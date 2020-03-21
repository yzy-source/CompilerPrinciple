%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.
main(){int a=2+3;a=6;}
Date: 2016年11月20日
****************************************************************************/

#include "mylexer.h"
#include <fstream>
#include <hash_map>
#include <string>
#include <stack>
int total = 0;
int total_func = 0;
int Count = 0;
extern int lineno;
const int MAXEXP = 4;
enum ID_Type{CHAR_t,INT_t,BOOL_t,VOID_t,FUNC_t};
enum State{Valid,Not_Def,Type_Err,Not_Init,Dup_Def};
enum NodeType{stmt,expr,decl,null};
enum Stmt{ifstmt,whilestmt,forstmt,groupstmt,elsestmt,iostmt,retstmt};
enum Expr{calcul,type,ID,num,efunc};
enum Decl{constdecl,iddecl,vardecl,fundecl};
enum printform{gt,lt,ge,le,eq,ne,add,sub,mul,di,mod,assign,inc,de,land,lor,lxor,And,Or,Not,lshift,rshift,uminus};
//当前语句类型
int nowStmtType = -1;
//当前声明类型
ID_Type nowType = VOID_t;
//中间变量数组，值为变量名
hash_map<int, string> glbtemp;
//即将使用的中间变量下标
int itemp = 0;
//符号表mark------->在栈中相对ebp的offset
hash_map<int, int> main_map;
//初始栈offset
int stack_pos = 0;
//局部变量个数
int num_var = 0;
//局部变量个数栈
stack<int> num_var_stack;
//Label个数
int num_label = 0;
//Label栈
stack<int> label_stack;
//下一段代码label
int next_label = 0;
struct ID_Table
{
	char name[20];
	ID_Type type;
	int val;
	char ch;
	State state;
	int line;
}Table[100];

struct FUNC_ID_Table
{
	char name[20];
	ID_Type type;
	//args[i]----->第i个参数的类型
	int args[10];
	//参数个数
	int num_args;
	//重载次数
	int num_override;
	State state;
	int line;
}FUNC_Table[100];

struct Node{
	Node *Children[MAXEXP];
	Node *Sibling;
	NodeType Type;
	ID_Type sort;
	int order;
	int pos;
	int val;
	char ch;
	//assembly output
	string code;
	//函数名
	char name[20];
	//temp下标
	int it;
	State sign;
};
struct Node* root;
//出栈所有局部变量
string popAll();
int func_find_name(char *target);
int func_check(int index);
int func_find(char *target, int num_args_a, int args_a[]);
State insert_func(char *target, int &position);
void traverseTree(Node* root);
void Display(Node* curr);
Node* newNode(NodeType t,int o,int v);
int find(char *target);
State insert(char *target,int& position);
void setvalue(int pos, char c, int v, ID_Type t);
extern int yyval;
extern char text[20];
string newline = "\n";
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE Node*
#endif
}

// place any declarations here
%token RETURN
%token NUM CONSTCHAR
%token ADD SUB MUL DIV MOD LAND LXOR LOR INC DEC NOT LE GE GT LT EQ NE EQU AND OR LSHIFT RSHIFT UMINUS
%token LP RP LB RB ID
%token IF FOR WHILE ELSE
%token INT CHAR
%token SEMICOLON COMMA
%token OUTPUT INPUT

%right EQU

%left OR
%left AND
%left LOR
%left LXOR
%left LAND
%left EQ NE
%left LT GT LE GE
%left LSHIFT RSHIFT
%left ADD SUB
%left MUL DIV MOD
%right INC DEC NOT
%right UMINUS

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

//开始符号
start : func_defs
		{
			$$ = $1;
			root = $$;
			string tete = root->code;
			root->code = ".486" + newline + ".model flat, stdcall"
				+ newline + "option casemap :none" + newline + "include \\masm32\\include\\msvcrt.inc" + newline
				+ "includelib \\masm32\\lib\\msvcrt.lib" + newline + ".data" + newline
				+ "szFmtIn  db '%d',0" + newline + "szFmtOut db ' %d ',0" + newline;
			for(int i = 0; i < itemp; ++i)
				root->code += (glbtemp[i] + "\tdd ?" + newline);
			root->code += (".code" + newline + tete);
			//traverseTree(root);
			//cout<<root->code;
			ofstream outInFile("test.asm");
			outInFile << root->code;
			cout<<"Succeed!"<<endl;
		}
		;
/***************************************************************************/
/*-------------------------------------------------------------------------*/
/*************************************函数**************************************/
func_defs : func_def func_defs
		{
			$$ = $1;
			$1->Sibling = $2;
			$$->code += $2->code;

		}
		| func_def
		{
			$$ = $1;
		}
		;

mmm :
		{
			total = 0;num_var = 0;nowStmtType = fundecl;stack_pos = 0;
		}
		;

func_def : mmm type_empty id LP RP block_only
		{
			if(func_check($3->val) == 1)
			{
				$$ = newNode(decl, fundecl, -1);
				$$->sort = $2->sort;
				$$->Children[0] = $2;
				$$->Children[1] = $3;
				$$->Children[2] = $6;
				$2->Sibling = $3;
				$3->Sibling = $6;
				if($2->sort == VOID_t){
					Node* cu = $6;
					while(cu != NULL)
					{
						if(cu->order == retstmt)
							cout<<"warn: reutrn value will be dropped!" + newline;
						cu = cu->Sibling;
					}
				}
				if(string(FUNC_Table[$3->val].name) == "main")
				{
					$$->code = string(FUNC_Table[$3->val].name) + to_string(FUNC_Table[$3->val].num_override) + ":" + newline
					 		+ "push ebp" + newline + "mov ebp, esp" + newline
					  	+ $6->code + /*popAll() + newline
							+ "ret" + */newline
						 	+ "end " + string(FUNC_Table[$3->val].name) + to_string(FUNC_Table[$3->val].num_override) + newline;
				}
				else
				{
					$$->code = string(FUNC_Table[$3->val].name) + to_string(FUNC_Table[$3->val].num_override) + "\tproc" + newline
					 		+ "push ebp" + newline + "mov ebp, esp" + newline
					  	+ $6->code + /*popAll() + newline
							+ "pop ebp" + newline + "ret" +*/ newline
						 	+ string(FUNC_Table[$3->val].name) + to_string(FUNC_Table[$3->val].num_override) + "\tendp" + newline + newline;
				}
			}
			else
			{
				$$ = newNode(null, -1, -1);
			}

		}
		| mmm type_empty id LP def_params RP
		{
			Node* ptr = $5;
			int pos = -8;
			while(ptr != NULL)
			{
				main_map[ptr->Children[1]->val] = pos;
				pos -= 4;
				FUNC_Table[$3->val].args[FUNC_Table[$3->val].num_args] = ptr->Children[0]->val;

				FUNC_Table[$3->val].num_args++;
				ptr = ptr->Sibling;
			}
			num_var = 0;
			stack_pos = 0;
		} block_only
				{
					if(func_check($3->val) == 1)
					{
						$$ = newNode(decl, fundecl, -1);
						$$->sort = $2->sort;
						$$->Children[0] = $2;
						$$->Children[1] = $3;
						$$->Children[2] = $5;
						$$->Children[3] = $8;
						$2->Sibling = $3;
						$3->Sibling = $5;
						$5->Sibling = $8;
						if($2->sort == VOID_t){
							Node* cu = $8;
							while(cu != NULL)
							{
								if(cu->order == retstmt)
									cout<<"warn: reutrn value will be dropped!" + newline;
								cu = cu->Sibling;
							}
						}
						$$->code = string(FUNC_Table[$3->val].name) + to_string(FUNC_Table[$3->val].num_override)
								+ "\tproc" + newline + "push ebp" + newline + "mov ebp, esp" + newline
								+ $5->code + $8->code + /*popAll() + newline + "pop ebp" + newline
								+ "ret" +*/ newline
								+ string(FUNC_Table[$3->val].name) + to_string(FUNC_Table[$3->val].num_override)
								+ "\tendp" + newline + newline;
					}
					else
					{
						$$ = newNode(null, -1, -1);
					}
				}
		;
/*------------------------------------函数参数-------------------------------------*/
def_params : def_param
		{
			$$ = $1;
		}
		| def_param COMMA def_params
		{
			$$ = $1;
			$1->Sibling = $3;
		}
		;

def_param : type decl_param
		{
			$$ = newNode(decl, fundecl, -1);
			$$->Children[0] = $1;
			$$->Children[1] = $2;
			$1->Sibling = $2;
			$2->sort = $1->sort;
		}
		;
/*************************************语句块**************************************/
//块必须被大括号包起来的情况，如函数体。
block_only : LB stmts RB
		{
			$$ = newNode(stmt, groupstmt, -1);
			$$->Children[0] = $2;
			$$->code = $2->code;
		}
		| LB RB SEMICOLON
		{

			$$ = newNode(null, -1, -1);
		}
		| LB RB
		{
			$$ = newNode(null, -1, -1);
		}
		;
//只有一条语句大括号可以省略时的情况
block : block_only
		{
			$$ = $1;
		}
		| stmt
		{
			$$ = $1;
		}
		;
/*------------------------------------语句-------------------------------------*/
stmts : block stmts
		{
			$$ = $1;
			$1->Sibling = $2;
			$$->code += $2->code;
		}
		| block
		{
			$$ = $1;
		}
		;

stmt : for_stmt
		{
			$$ = $1;
		}
		| while_stmt
		{
			$$ = $1;
		}
		| if_stmt
		{
			$$ = $1;
		}
		| simple_stmt SEMICOLON
		{
			$$ = $1;
		}
		;
/*---------------------------简单语句（后有封号）------------------------------*/
simple_stmt : decl_stmt
		{
			$$ = $1;
		}
		| assign_stmt
		{
			$$ = $1;
		}
		| simple_expr
		{
			$$ = $1;
		}
		| output_stmt
		{

		}
		| input_stmt
		{

		}
		|	return_stmt
		{
			$$ = $1;
		}
		|
		{

		}
		;
/*------------------------for,while,if,赋值,声明语句---------------------------*/
return_stmt : RETURN simple_expr_empty
		{
			$$ = newNode(stmt, retstmt, -1);
			$$->Children[0] = $2;
			string tep = "mov ebx, " + glbtemp[$2->it];
			if($2->it == -1)
				tep = "";
			$$->code = $2->code + popAll() + newline + "pop ebp" + newline
			 					+ tep/*"mov ebx, " + glbtemp[$2->it]*/ + newline + "ret";
			cout<<"-----------"<<$2->it<<endl;
		}
		;

output_stmt : OUTPUT LP simple_expr_empty RP
		{

			$$ = newNode(stmt, iostmt, -1);
			$$->Children[0] = $3;
			$$->code = $3->code + "invoke crt_printf, addr szFmtOut, " + glbtemp[$3->it] + newline;
		}
		;

input_stmt : INPUT LP id RP
		{
			$$ = newNode(stmt, iostmt, -1);

			$$->Children[0] = $3;
			$$->code = "invoke crt_scanf, addr szFmtIn, addr [ebp - "
								+ to_string(main_map[$3->val]) + "]" + newline;
		}
		;
for_stmt : {label_stack.push(num_label++);}
		FOR LP simple_stmt SEMICOLON simple_expr_empty SEMICOLON simple_stmt RP block
		{
			$$ = newNode(stmt, forstmt, -1);
			$$->Children[0]=$4;
			$$->Children[1]=$6;
			$$->Children[2]=$8;
			$$->Children[3]=$10;
			$4->Sibling=$6;
			$6->Sibling=$8;
			$8->Sibling=$10;
			$$->code = $4->code + "@" + to_string(num_label) + ":" + newline + $6->code
								+ "cmp " + glbtemp[$6->it] + ",0" + newline
								+ "je @" + to_string(label_stack.top()) + newline
								+ $10->code + $8->code + "jmp @" + to_string(num_label) + newline
								+ "@" + to_string(label_stack.top()) + ":" + newline;
			++num_label;
			label_stack.pop();
		}
		;

while_stmt : {label_stack.push(num_label++);}
		WHILE LP simple_expr RP block
		{
			$$ = newNode(stmt, whilestmt, -1);
			$$->Children[0]=$4;
			$$->Children[1]=$6;
			$4->Sibling=$6;
			$$->code = "@" + to_string(num_label) + ":" + newline + $4->code
								+ "cmp " + glbtemp[$4->it] + ",0" + newline
								+ "je @" + to_string(label_stack.top()) + newline
								+ $6->code + "jmp @" + to_string(num_label) + newline
								+ "@" + to_string(label_stack.top()) + ":" + newline;
			++num_label;
			label_stack.pop();
		}
		;

if_stmt : {label_stack.push(num_label++);}
		IF LP simple_expr RP block else_stmt
		{
			$$ = newNode(stmt, ifstmt, -1);
			$$->Children[0]=$4;
			$$->Children[1]=$6;
			$$->Children[2]=$7;
			$4->Sibling=$6;
			$6->Sibling=$7;
			cout<<"itemp---->"<<num_label<<endl;
			$$->code = $4->code + newline + "cmp " + glbtemp[$4->it] + ", 0" + newline
								+ "je @" + to_string(num_label) + newline + $6->code + newline
								+ "jmp @" + to_string(label_stack.top()) + newline
								+ "@" + to_string(num_label) + ":" + newline + $7->code + newline
								+ "@" + to_string(label_stack.top()) + ":" + newline;
			++num_label;
			label_stack.pop();
		}
		;

else_stmt : ELSE block
		{
			$$ = newNode(stmt, ifstmt, -1);
			$$->Children[0]=$2;
			$$->code = $2->code;
		}
		|
		{
			$$ = newNode(null, -1, -1);
		}
		;

assign_stmt : id EQU simple_expr
		{
			$$ = newNode(expr, calcul, assign);
			$$->Children[0]=$1;
			$$->Children[1]=$3;
			$1->Sibling=$3;


			//如果是声明语句，在栈中分配空间
			if(nowStmtType == vardecl)
			{
				stack_pos += 4;
				main_map[$1->val] = stack_pos;
				$$->code = $3->code + "push " + glbtemp[$3->it] + newline;
				num_var ++;
			}
			else
			{
				$$->code = $3->code + "mov eax, " + glbtemp[$3->it] + newline
				 						+ "mov [ebp - (" + to_string(main_map[$1->val]) + ")], eax" + newline;
			}

			//cout<<Table[$1->val].state<<endl;
			if(Table[$1->val].state == Not_Def)
				$$->sign = Not_Def;
			else if(Table[$1->val].state == Dup_Def)
				$$->sign = Dup_Def;
			else
			{
				if($1->sort == $3->sort)
				{
					if($3->sort == INT_t)
					{
						setvalue($1->val, NULL, $3->val, INT_t);
						$1->sort = INT_t;
					}
					else if($3->sort == CHAR_t)
					{
						setvalue($1->val, $3->ch, NULL, CHAR_t);
						$1->sort = CHAR_t;
					}
				}
				else
				{
					$$->sign = Type_Err;
					if($1->sort == INT_t)
						$3->sort = INT_t;
					else if($3->sort == INT_t)
						$1->sort = INT_t;
					else if($1->sort == VOID_t)
						$$->sign = Not_Init;
				}
			}
			$$->sort = $1->sort;
		}
		;

decl_stmt : type {nowStmtType = vardecl;} decl_params
		{

			$$ = newNode(decl, vardecl, -1);
			$$->Children[0] = $1;
			$$->Children[1] = $3;
			$1->Sibling=$3;
			Node * temp = $3;

			$$->code = $3->code;

			for(;temp!=NULL;temp=temp->Sibling)
			{
			cout<<temp->Type<<"\t"<<temp->order<<endl;
				if(temp->Type == expr)
				{
					if($1->sort != temp->sort)
						$$->sign = Type_Err;
				}
				else
				{
					temp->sort = $1->sort;
					Table[temp->val].type = $1->sort;
				}
			}

			$$->sort = $1->sort;
			nowStmtType = $1->sort;

		}
		;

type_empty : type
		{
			$$ = $1;
		}
		|
		{
			$$ = newNode(expr, type, VOID_t);
			nowType = VOID_t;
		}
		;

type	:	INT
		{
				$$ = newNode(expr, type, INT_t);
				$$->sort=INT_t;
				nowType = INT_t;
		}
		|	CHAR
		{
				$$ = newNode(expr, type, CHAR_t);
				$$->sort=CHAR_t;
				nowType = CHAR_t;
		}
		;

decl_params : decl_param
		{
			$$ = $1;
		}
		| decl_param COMMA decl_params
		{
			$$ = $1;
			$1->Sibling = $3;
			$1->code += $3->code;
		}
		;

decl_param : id
		{
			$$ = $1;
			stack_pos += 4;
			main_map[$1->val] = stack_pos;
			$$->code = "push eax" + newline;
			num_var ++;
		}
		| assign_stmt
		{
			$$ = $1;
		}
		;
/*-------------------------------简单表达式--------------------------------*/
simple_expr : expr_arithmetic
		{
			$$ = $1;
		}
		| func_expr
		{
			$$ = $1;
		}
		;

simple_expr_empty : simple_expr
		{
			$$ = $1;
		}
		|
		{
			$$ = newNode(null, -1, -1);
			$$->it = -1;
		}
		;

		expr_arithmetic	:	expr_arithmetic ADD expr_arithmetic
				{
					$$ = newNode(expr,calcul,add);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
										+ "mov ebx, " + glbtemp[$3->it] + newline
										+ "add eax, ebx" + newline
										+ "mov " + glbtemp[$1->it] + ", eax" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
					{
						$$->sign = Type_Err;
						if($1->sort == INT_t)
						{
							$3->sort = INT_t;
							$$->sort = $1->sort;
							cout<<$3->sort<<"3"<<endl;
						}
						else if($3->sort == INT_t)
						{
							$1->sort = INT_t;
							$$->sort = $3->sort;
						}
					}
					else
						$$->sort = $1->sort;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
				}
				|	expr_arithmetic SUB expr_arithmetic
				{
					$$ = newNode(expr,calcul,sub);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "sub eax, ebx" + newline
							+ "mov " + glbtemp[$1->it] + ", eax" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	expr_arithmetic MUL expr_arithmetic
				{
					$$ = newNode(expr,calcul,mul);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "mul ebx" + newline
							+ "mov " + glbtemp[$1->it] + ", edx" + newline
							+ "mov " + glbtemp[$3->it] + ", eax" + newline;
					$$->it = $3->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	expr_arithmetic DIV expr_arithmetic
				{
					$$ = newNode(expr,calcul,di);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov edx, 0" + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "div ebx" + newline
							+ "mov " + glbtemp[$1->it] + ", eax" + newline
							+ "mov " + glbtemp[$3->it] + ", edx" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	expr_arithmetic MOD expr_arithmetic
				{
					$$ = newNode(expr,calcul,mod);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov edx, 0" + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "div ebx" + newline
							+ "mov " + glbtemp[$1->it] + ", edx" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	expr_arithmetic AND expr_arithmetic
				{
					$$ = newNode(expr,calcul,And);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "mov "+ glbtemp[$1->it] + ", 0" + newline
							+ "cmp eax, 0" + newline
							+ "jne @" + to_string(num_label) + newline
							+ "jmp @" + to_string(num_label+1) + newline
							+ "@" + to_string(num_label) + ": cmp ebx, 0" + newline
							+ "jne @" + to_string(num_label + 2) + newline
							+ "jmp @" + to_string(num_label+1) + newline
							+ "@" + to_string(num_label + 2) + ": mov " + glbtemp[$1->it] + ", 1" + newline
							+ "@" + to_string(num_label + 1) + ":" + newline;
					$$->it = $1->it;
					num_label +=3;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	expr_arithmetic OR expr_arithmetic
				{
					$$ = newNode(expr,calcul,Or);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "mov "+ glbtemp[$1->it] + ", 0" + newline
							+ "cmp eax, 0" + newline
							+ "jne @" + to_string(num_label) + newline
							+ "cmp ebx, 0" + newline
							+ "jne @" + to_string(num_label) + newline
							+ "jmp @" + to_string(num_label + 1) + newline
							+ "@" + to_string(num_label) + ": mov " + glbtemp[$1->it] + ", 1" + newline
							+ "@" + to_string(num_label + 1) + ":" + newline;
					$$->it = $1->it;
					num_label +=2;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				| expr_arithmetic LSHIFT expr_arithmetic
				{
					$$ = newNode(expr,calcul,lshift);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ecx, " + glbtemp[$3->it] + newline
							+ "sal eax, cl" + newline
							+ "mov " + glbtemp[$1->it] + ", eax" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|   expr_arithmetic RSHIFT expr_arithmetic
				{
					$$ = newNode(expr,calcul,rshift);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ecx, " + glbtemp[$3->it] + newline
							+ "sar eax, cl" + newline
							+ "mov " + glbtemp[$1->it] + ", eax" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|   expr_arithmetic LAND expr_arithmetic
				{
					$$ = newNode(expr,calcul,land);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "and eax, " + glbtemp[$3->it] + newline
							+ "mov " + glbtemp[$1->it] + ", eax" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|   expr_arithmetic LOR expr_arithmetic
				{
					$$ = newNode(expr,calcul,lor);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "or eax, " + glbtemp[$3->it] + newline
							+ "mov " + glbtemp[$1->it] + ", eax" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|   expr_arithmetic LXOR expr_arithmetic
				{
					$$ = newNode(expr,calcul,lxor);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "xor eax, " + glbtemp[$3->it] + newline
							+ "mov " + glbtemp[$1->it] + ", eax" + newline;
					$$->it = $1->it;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	expr_arithmetic LT expr_arithmetic
				{
					$$ = newNode(expr,calcul,lt);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov "+ glbtemp[$1->it] + ", 0" + newline
							+ "cmp eax, " + glbtemp[$3->it] + newline
							+ "jl @" + to_string(num_label++) + newline
							+ "jmp @" + to_string(num_label) + newline
							+ "@" + to_string(num_label - 1) + ": mov " + glbtemp[$1->it] + ", 1" + newline
												+ "@" + to_string(num_label) + ":"+newline;
					$$->it = $1->it;
					num_label ++;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	expr_arithmetic GT expr_arithmetic
				{
					$$ = newNode(expr,calcul,gt);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "mov "+ glbtemp[$1->it] + ", 0" + newline
							+ "cmp eax, ebx" + newline
							+ "jg @" + to_string(num_label++) + newline
							+ "jmp @" + to_string(num_label) + newline
							+ "@" + to_string(num_label - 1) + ": mov " + glbtemp[$1->it] + ", 1" + newline
							+ "@" + to_string(num_label) + ":"+newline;
					$$->it = $1->it;
					num_label ++;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|   expr_arithmetic LE expr_arithmetic
				{
					$$ = newNode(expr,calcul,le);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "mov "+ glbtemp[$1->it] + ", 0" + newline
							+ "cmp eax, ebx" + newline
							+ "jng @" + to_string(num_label++) + newline
							+ "jmp @" + to_string(num_label) + newline
							+ "@" + to_string(num_label - 1) + ": mov " + glbtemp[$1->it] + ", 1" + newline
							+ "@" + to_string(num_label) + ":"+newline;
					$$->it = $1->it;
					num_label ++;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|   expr_arithmetic GE expr_arithmetic
				{
					$$ = newNode(expr,calcul,ge);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "mov "+ glbtemp[$1->it] + ", 0" + newline
							+ "cmp eax, ebx" + newline
							+ "jnl @" + to_string(num_label++) + newline
							+ "jmp @" + to_string(num_label) + newline
							+ "@" + to_string(num_label - 1) + ": mov " + glbtemp[$1->it] + ", 1" + newline
							+ "@" + to_string(num_label) + ":"+newline;
					$$->it = $1->it;
					num_label ++;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	expr_arithmetic EQ expr_arithmetic
				{
					$$ = newNode(expr,calcul,eq);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "mov "+ glbtemp[$1->it] + ", 0" + newline
							+ "cmp eax, ebx" + newline
							+ "je @" + to_string(num_label++) + newline
							+ "jmp @" + to_string(num_label) + newline
							+ "@" + to_string(num_label - 1) + ": mov " + glbtemp[$1->it] + ", 1" + newline
							+ "@" + to_string(num_label) + ":"+newline;
					$$->it = $1->it;
					num_label ++;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|   expr_arithmetic NE expr_arithmetic
				{
					$$ = newNode(expr,calcul,ne);
					$$->Children[0]=$1;
					$$->Children[1]=$3;
					$1->Sibling=$3;

					$$->code = $1->code + $3->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "mov ebx, " + glbtemp[$3->it] + newline
							+ "mov "+ glbtemp[$1->it] + ", 0" + newline
							+ "cmp eax, ebx" + newline
							+ "jne @" + to_string(num_label++) + newline
							+ "jmp @" + to_string(num_label) + newline
							+ "@" + to_string(num_label - 1) + ": mov " + glbtemp[$1->it] + ", 1" + newline
							+ "@" + to_string(num_label) + ":"+newline;
					$$->it = $1->it;
					num_label ++;

					if($1->sort != $3->sort)
						$$->sign = Type_Err;
					if($1->order == iddecl)
					{
						if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
							$$->sign = Not_Init;
					}
					if($3->order == iddecl)
					{
						if(Table[$3->val].val == -1 && Table[$3->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $1->sort;
				}
				|	SUB expr_arithmetic %prec UMINUS
				{
					$$ = newNode(expr,calcul,uminus);
					$$->Children[0]=$2;

					$$->code = $2->code + "mov ebx, " + glbtemp[$2->it] + newline
							+ "mov eax, 0" + newline
							+ "sub eax, ebx" + newline
							+ "mov " + glbtemp[$2->it] + ", eax" + newline;
					$$->it = $2->it;

					if($2->order == iddecl)
					{
					    if(Table[$2->val].val == -1 && Table[$2->val].ch == '=')
							$$->sign = Not_Init;
					}
					$$->sort = $2->sort;
				}
				|   INC expr_arithmetic
				{
					$$ = newNode(expr,calcul,inc);
					$$->Children[0]=$2;
					$$->code = $2->code + "mov eax, " + glbtemp[$2->it] + newline
							+ "inc eax" + newline
							+ "mov " + glbtemp[$2->it] + ", eax" + newline
							+ "mov [ebp - " + to_string(main_map[$2->val]) + "], eax" + newline;
					$$->it = $2->it;

					if($2->order != iddecl)
						$$->sign = Type_Err;
					else if(Table[$2->val].val == -1 && Table[$2->val].ch == '=')
						$$->sign = Not_Init;
					$$->sort = $2->sort;
				}
				|   DEC expr_arithmetic
				{
					$$ = newNode(expr,calcul,de);
					$$->Children[0]=$2;

					$$->code = $2->code + "mov eax, " + glbtemp[$2->it] + newline
							+ "dec eax" + newline
							+ "mov " + glbtemp[$2->it] + ", eax" + newline
							+ "mov [ebp - " + to_string(main_map[$2->val]) + "], eax" + newline;
					$$->it = $2->it;

					if($2->order != iddecl)
						$$->sign = Type_Err;
					else if(Table[$2->val].val == -1 && Table[$2->val].ch == '=')
						$$->sign = Not_Init;
					$$->sort = $2->sort;
				}
				|   expr_arithmetic INC
				{
					$$ = newNode(expr,calcul,inc);
					$$->Children[0]=$1;
					$$->code = $1->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "inc eax" + newline
							+ "mov [ebp - " + to_string(main_map[$1->val]) + "], eax" + newline;
					$$->it = $1->it;

					if($1->order != iddecl)
						$$->sign = Type_Err;
					else if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
						$$->sign = Not_Init;
					$$->sort = $1->sort;
				}
				|   expr_arithmetic DEC
				{
					$$ = newNode(expr,calcul,de);
					$$->Children[0]=$1;

					$$->code = $1->code + "mov eax, " + glbtemp[$1->it] + newline
							+ "dec eax" + newline
							+ "mov " + glbtemp[$1->it] + ", eax" + newline
							+ "mov [ebp - " + to_string(main_map[$1->val]) + "], eax" + newline;
					$$->it = $1->it;

					if($1->order != iddecl)
						$$->sign = Type_Err;
					else if(Table[$1->val].val == -1 && Table[$1->val].ch == '=')
						$$->sign = Not_Init;
					$$->sort = $1->sort;
				}
				|   NOT expr_arithmetic
				{
					$$ = newNode(expr,calcul,Not);
					$$->Children[0]=$2;

					$$->code = $2->code + "mov eax, " + glbtemp[$2->it] + newline
							+ "not eax" + newline
							+ "mov " + glbtemp[$2->it] + ", eax" + newline;
					$$->it = $2->it;

					if($2->order != iddecl)
						$$->sign = Type_Err;
					else if(Table[$2->val].val == -1 && Table[$2->val].ch == '=')
						$$->sign = Not_Init;
					$$->sort = $2->sort;
				}
				|	LP expr_arithmetic RP
				{
					$$ = $2;
				}
				|	number
				{
					$$ = $1;
					glbtemp[itemp] = "tdb" + to_string(itemp);
					$$->code = "mov " + glbtemp[itemp] + ", " + to_string($1->val) + newline;
					$$->it = itemp;
					itemp++;
					//itemp %= 2;
				}
				|   id
				{
					$$ = $1;
					glbtemp[itemp] = "tdb" + to_string(itemp);
					$$->code = "mov eax, [ebp - " + to_string(main_map[$1->val]) + "]" + newline + "mov " + glbtemp[itemp] + ", " + "eax" + newline;
					//$$->code = "mov " + glbtemp[itemp] + ", " + "[ebp - " + to_string(main_map[$1->val]) + "]" + newline;
					$$->it = itemp;
					itemp++;
					//itemp %= 2;
				}
				|	constchar
				{
					$$ = $1;
					glbtemp[itemp] = "tdb" + to_string(itemp);
					$$->code = "mov " + glbtemp[itemp] + ", " + to_string((int)$1->ch) + newline;
					$$->it = itemp;
					itemp++;
					//itemp %= 2;
				}
				| func_expr
				{
					$$ = $1;
				}
				;

id : ID
		{
			if(nowStmtType == fundecl)
			{
				int mark;
				State sign = insert_func(text,mark);
				$$ = newNode(decl,iddecl,mark);
				$$->sign=sign;
				strcpy_s($$->name,strlen(text) + 1,text);
				if(sign == Not_Def)
				{
					FUNC_Table[mark].line=lineno;

						FUNC_Table[mark].type = nowType;
						FUNC_Table[mark].state = Valid;

				}
				$$->sort = FUNC_Table[mark].type;
				nowStmtType = vardecl;
			}
			else if(func_find_name(text))
			{
				//如果是函数id
				$$ = newNode(decl, fundecl, -1);
				strcpy_s($$->name,strlen(text) + 1,text);
			}
			else
			{
				int mark;
				State sign = insert(text,mark);
				$$ = newNode(decl,iddecl,mark);
				$$->sign=sign;
				if(sign == Not_Def)
				{
					Table[mark].line=lineno;
					if(nowStmtType == vardecl)
					{
						Table[mark].type = nowType;
						Table[mark].state = Valid;
					}
				}
				$$->sort = Table[mark].type;

				//cout<<string(text)<<" "<<nowType<<"..";
			}

		}
		;
number	:	NUM
		{
			$$ = newNode(decl,constdecl,yyval);
			$$->sort=INT_t;
		}
		;
constchar : CONSTCHAR
		{
			$$ = newNode(decl,constdecl,-1);
			$$->ch = text[0];
			$$->sort=CHAR_t;
		}
		;
/*-----------------------------函数调用---------------------------------*/
func_expr : id LP func_params RP
		{
			$$ = newNode(expr, efunc, -1);
			$$->Children[0] = $1;
			$$->Children[1] = $3;
			//匹配相应函数
			int args_a[10];
			int num_args_a = 0;
			Node* ptr = $3;
			while(ptr != NULL)
			{
				args_a[num_args_a] = ptr->sort;
				num_args_a++;
				ptr = ptr->Sibling;
			}
			$1->val = func_find($1->name, num_args_a, args_a);

			if($1->val == -1)
				cout<<"func not found"<<endl;

			$$->code = $3->code + "call " + string(FUNC_Table[$1->val].name)
									+ to_string(FUNC_Table[$1->val].num_override) + newline;
			Node* te = $3;
			while(te != NULL)
			{
				$$->code += ("pop eax" + newline);
				te = te->Sibling;
			}
			$$->code += ("mov " + glbtemp[$3->it] + ", ebx" + newline);
			$$->it = $3->it;
		}
		| id LP RP
		{
			$$ = newNode(expr, efunc, -1);
			//匹配相应函数
			int args_a[10];
			int num_args_a = 0;
			$1->val = func_find($1->name, num_args_a, args_a);
			if($1->val == -1)
				cout<<"func not found"<<endl;
			$$->Children[0] = $1;
			glbtemp[itemp] = "tdb" + to_string(itemp);
			$$->code = "call " + string(FUNC_Table[$1->val].name)
								+ to_string(FUNC_Table[$1->val].num_override) + newline
								+ ("mov " + glbtemp[itemp] + ", ebx" + newline);
			$$->it = itemp;
			itemp++;
		}
		;

func_params : simple_expr
		{
			$$ = $1;
			$1->code += ("push " + glbtemp[$1->it] + newline);
		}
		| simple_expr COMMA func_params
		{
			$$ = $1;
			$1->Sibling = $3;
			$1->code = $3->code + $1->code + "push " + glbtemp[$1->it] + newline;
		}
		;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int find(char *target)
{
	int curr = 0;
	while(curr <= total)
	{
		if(strcmp(Table[curr].name,target) == 0)
			return curr;
		curr ++;
	}
	return -1;
}
State insert(char *target,int& position)
{
	position = find(target);
	if(position == -1)
	{
		strcpy_s(Table[total].name,strlen(target) + 1,target);
		Table[total].val = -1;
		Table[total].ch = '=';
		position = total;
		total++;
		Table[position].state = Not_Def;
		return Not_Def;
	}
	else
	{
		if(Table[position].state == Valid)
		{
			Table[position].state = Dup_Def;
			return Dup_Def;
		}
		return Table[position].state;
	}
}
int func_check(int index)
{
	int curr = 0;
	while(curr <= total_func)
	{
		//如果函数名相同，并且参数个数相同，并且参数类型相同，说明函数相同
		//cout<<"fuck 1"<<endl;
		if(strcmp(FUNC_Table[curr].name, FUNC_Table[index].name) == 0 && curr != index)
		{
			//如果同名说明是重载
			//cout<<"fuck 2"<<endl;
			FUNC_Table[index].num_override++;
			if(FUNC_Table[index].num_args == FUNC_Table[curr].num_args)
			{
				int i;
				for(i = 0; i < FUNC_Table[index].num_args; ++i)
					if(FUNC_Table[index].args[i] != FUNC_Table[index].args[i])
						break;
				//函数相同，删除。
				if(i >= FUNC_Table[index].num_args)
				{
					cout<<"func redefine"<<endl;
					total_func--;
					return 0;
				}
			}
		}
		curr ++;
	}
	return 1;
}
int func_find(char *target, int num_args_a, int args_a[])
{
	int curr = 0;

	while(curr <= total_func)
	{
		//如果函数名相同，并且参数个数相同，并且参数类型相同，说明函数相同
		//cout<<"---->>>"<<num_args_a<<endl;
		if(strcmp(FUNC_Table[curr].name, target) == 0)
			if(num_args_a == FUNC_Table[curr].num_args)
			{
				int i;
				for(i = 0; i < num_args_a; ++i)
					if(args_a[i] != FUNC_Table[curr].args[i])
						break;
				if(i >= num_args_a)
					return curr;
			}
		curr ++;
	}
	return -1;
}
int func_find_name(char *target)
{
	int curr = 0;
	while(curr <= total_func)
	{
		//如果函数名相同，并且参数个数相同，并且参数类型相同，说明函数相同
		if(strcmp(FUNC_Table[curr].name, target) == 0)
			return 1;
		curr ++;
	}
	return 0;
}
State insert_func(char *target, int &position)
{
	//position = find_func(target);
	strcpy_s(FUNC_Table[total_func].name,strlen(target) + 1,target);
	FUNC_Table[total_func].num_args = 0;
	FUNC_Table[total_func].num_override = 0;
	position = total_func;
	total_func++;
	FUNC_Table[position].state = Not_Def;
	return Not_Def;
}

void setvalue(int pos, char c, int v, ID_Type t)
{
	Table[pos].type = t;
	if(t == CHAR_t)
		Table[pos].ch = c;
	else if(t == INT_t)
		Table[pos].val = v;
}

string popAll()
{
	string ret;
	for(; num_var >= 1; --num_var)
		ret += "pop eax" + newline;
	return ret;
}

Node* newNode(NodeType t,int o,int v)
{
	Node *curr = new Node;
	curr->Children[0] = NULL;
	curr->Children[1] = NULL;
	curr->Children[2] = NULL;
	curr->Children[3] = NULL;
	curr->Sibling = NULL;
	curr->Type = t;
	curr->order = o;
	curr->val = v;
	return curr;
}
void traverseTree(Node* root)
{
	Node *temp = root->Sibling;
	if(root->Children[0] != NULL)
	{
		traverseTree(root->Children[0]);
	}
	if(root->Type != null)
	{
		root->pos = Count++;
	}
	Display(root);
	if(temp!=NULL)
		traverseTree(temp);

}
void Display(Node* curr)
{
	if(curr->Type != null)
	{
		cout<<curr->pos<<":";
	}
	else
		return;
	Node* temp=curr->Children[0];
	char printType[4][10]={"CHAR","INT","BOOL","VOID"};
	if(curr->Type == stmt)
	{
		char printstmt[4][15]={"ifstmt","whilestmt","forstmt","compoundstmt"};
		cout<<printstmt[curr->order]<<"\t\t\t\t";
		cout<<"Children:";
		while(temp!=NULL)
		{
			if(temp->Type != null)
			{
				cout<<temp->pos<<" ";
			}
			temp = temp->Sibling;
		}
		cout<<endl;
	}
	else if(curr->Type == decl)
	{
		switch(curr->order)
		{
			case vardecl:
				cout<<"Var Declaration,\t\t\t";
				break;
			case constdecl:
				if(curr->sort==INT_t)
					cout<<"Const Declaration,\t"<<"value:"<<curr->val<<" \t";
				else if(curr->sort==CHAR_t)
					cout<<"Const Declaration,\t"<<"value:"<<curr->ch<<" \t";
				else
					cout<<"Const Declaration,\t"<<"value:"<<curr->val<<" \t";
				break;
			case iddecl:
				cout<<"ID Declaration,\t"<<"symbol:"<<Table[curr->val].name<<" \t";
				break;
			case fundecl:
				cout<<"Function Declaration,\t\t\t";//<<"symbol:"<<Table[curr->val].name<<" \t";
		}
		cout<<"Children:";
		while(temp!=NULL)
		{
			if(temp->Type != null)
			{
				cout<<temp->pos<<" ";
			}
			temp = temp->Sibling;
		}
		if(curr->order != fundecl)
			cout<<"\tType:"<<printType[curr->sort];
		if(curr->sign == Type_Err) cout<<"\tTypeErr";
		if(curr->sign == Not_Init) cout<<"\tNotInit";
		cout<<endl;
	}
	else if(curr->Type == expr)
	{
		char printop[23][3]={">","<",">=","<=","==","!=","+","-","*","/","%","=","++","--","&","|","^","&&","||","~","<<",">>","-"};
		switch(curr->order)
		{
			case calcul:
				cout<<"Expr, \t\t"<<"op:"<<printop[curr->val]<<" \t\t";
				break;
			case type:
				if(curr->val == INT_t)
					cout<<"Type Specifier\t"<<"Integer\t\t";
				else if(curr->val == CHAR_t)
					cout<<"Type Specifier\t"<<"Char\t\t";
				else cout<<"Type Specifier\t"<<"VOID\t\t";
				break;
		}
		cout<<"Children:";
		for(int i=0;i<MAXEXP;i++)
		{
			if(curr->Children[i]!=NULL)
			{
				if(curr->Children[i]->Type != null)
				{
					cout<<curr->Children[i]->pos<<" ";
				}
			}
		}
		cout<<"\tType:"<<printType[curr->sort];
		if(curr->sign == Type_Err) cout<<"\tTypeErr";
		if(curr->sign == Not_Init) cout<<"\tNotInit";
		if(curr->sign == Not_Def) cout<<"\tNotDef";
		if(curr->sign == Dup_Def) cout<<"\tDupDef";
		cout<<endl;
	}
}
int main(int argc,char *argv[])
{
	int n = 1;
	mylexer lexer;
	lexer.yyin = new ifstream("test.cpp");
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	return n;
}
