#include"mylexer.h"
#include"myparser.h"

using namespace std;
//enum PARENT;
//enum STMT_CHILD;
//enum EXP_CHILD;
//enum DEC_CHILD;
//enum TYPE;
////类型
//
////表达式类型
//union NodeAttr;
//struct TreeNode;
//
////符号表类型
//struct table ;
//class NodeTable;
//语句，表达式，声明
const int MAXCHILD=4;
const int max_table=100;
enum PARENT
{
  STMT=0,                    
  EXPR,
  DECL
};
 //语句：if,while,for ,复合语句
enum STMT_CHILD
{
  IF_STMT=0,                
  WHILE_STMT,
  FOR_STMT,
  COMP_STMT,
  INPUT_STMT,                //输入输出语句
  OUTPUT_STMT,
  VAR_DEC,
  EXP_STMT,
};
 //表达式：类型，运算，常量，ID
enum EXP_CHILD
{
  TYPE_EXPR=0,
  OP_EXPR,
  NOT_EXPR,
  ARRAY_EXPR,  
  CONST_EXPR,
  ID_EXPR
};
 //声明：变量声明，数组声明
enum DEC_CHILD
{
  VAR_DECL=0,              
  ARRAY_DECL
}; 
enum TYPE
{
 Notype=0,
 Integer,
 Char,
 Boolean
};
//enum
//{
//	OPASSIGN=0,
//	OPOR,
//	OPAND,
//	OPSHL,
//	OPSHR,
//	OPEQ,
//	OPLT,
//	OPGT,
//	OPLE,
//	OPGE,
//	OPNEQ,
//	OPPLUS,
//	OPMINUS,
//	OPINC,
//	OPDEC,
//	OPMUL,
//	OPDIV,
//	OPMOD,
//};
union NodeAttr
{
 int op;
 int val;
 char valc;
 int symbol_add;    //所在符号表位置
 
 NodeAttr(void){op=0;} //操作符
 NodeAttr(int i){op=i;} //NUM
 NodeAttr(char c){valc=c;}//字符型
 
};
struct TreeNode
{
  struct TreeNode *child[MAXCHILD];  //孩子节点
//struct TreeNode* child;
  struct TreeNode *sibling;          //兄弟节点
  int lineno;                        //所在行
  int nodekind;                      //类型
  int nodekind_kind;                 //子类型
  NodeAttr attr;                     //属性
  int type;                          //变量类型
  int seq;                           //节点编号
};
struct table 
{
 string name;    //标识符名字    
 int token;      //标识符单词类别
 int type;      //标识符类型
};

class NodeTable{
public:
	table symbol_table[max_table];
	TreeNode *node;
	int tablenumber;   //记录符号表的标识符数目
   // int address;       //存储ID,NUMBER 在符号表中的位置
    int lineno;
    int nodenumber;

    int getNumber(char*);
    int getadd(string name);
    int insert(string name,int token); 
    int gettoken(string name);
    string& getname(int pos);
    int set_type(int pos,int type);
    int gettype(int pos);
	void shownode(struct TreeNode *p);
   	TreeNode * createnode(int nodekind,int nodekind_kind,NodeAttr attr,int type,struct TreeNode *child0,struct TreeNode *child1,struct TreeNode *child2,struct TreeNode *child3);
	void Display(TreeNode *p);
	//TreeNode* NodeTable::createnode(int nodekind,int nodekind_kind,NodeAttr attr,int type,struct TreeNode *child);
};

