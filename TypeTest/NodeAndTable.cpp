#include<iostream>
#include <string>
#include"NodeAndTable.h"
#include<fstream>
using namespace std;
 mylexer lexer;
//分析树节点定义

ofstream fout("output.txt");
NodeTable my;
//得到相应的符号在符号表中的位置
int NodeTable::getadd(string name)                                    
{
  for(int i=0;i<tablenumber;i++)
  {
    if(symbol_table[i].name==name)
      return i;
  }
  return -1;
}

//不在符号表中，向表中加入新表项
int NodeTable::insert(string name,int token,int type,int init,int def)        
{
  if(tablenumber>=max_table)
     return -1;
  symbol_table[tablenumber].name=name;
  symbol_table[tablenumber].token=token;
  symbol_table[tablenumber].type=type;
  symbol_table[tablenumber].init=init;
  symbol_table[tablenumber].def=def;
  tablenumber++;
  return (tablenumber-1);
}

//判断是否已经初始化
int NodeTable::ifinit(string name)
{
	int add=getadd(name);
	return symbol_table [add].init;
}

//返回符号表token值
int NodeTable::gettoken(string name)
{
 for(int i=0;i<tablenumber;i++)
 {
  if(symbol_table[i].name==name)
    return symbol_table[i].token;
 }
 return -1;
}

//返回符号表相应位置的name
string NodeTable::getname(int pos)
{
	string str=symbol_table[pos].name;
    return str;
}


//设置符号相应位置的ID 的type
int NodeTable::set_type(int pos,int type)
{
 if(pos<0||pos>=tablenumber)
   {
     cout<<"set type error"<<endl;
     return -1;
   }
   symbol_table[pos].type=type;
   return 0;
}


//返回符号表相应位置的ID 的type
int NodeTable::gettype(int pos)
{
  if(pos<0||pos>=tablenumber)
   {
     cout<<"get type error  "<<endl;
     return -1;
   }
   return symbol_table[pos].type;
}

//处理数字，返回数字的值
int NodeTable::getNumber(char *str)
{
       int value=0;
	   value=atoi(str);
	   return value;
}

//遍历符号表，查找未定义的ID 
void NodeTable ::lookuptable(void)
{
	for(int i=0;i<tablenumber;i++){
		if(my.symbol_table [i].def==0)
			fout<<"The ID "<<getname(i)<<" doesn't been defined "<<endl;
		if(my.symbol_table [i].init ==0)
			fout<<"The ID "<<getname (i)<<" doesn't been inited "<<endl;
	}
}

//分析树定义————
//void NodeTable::shownode(struct TreeNode * p)
//{  
//   fout.setf(ios_base::left);//左对齐
//   fout.width(3);
//   fout<<p->seq<<"\t";   //节点编号
//  switch(p->nodekind)     //根据nodekind判断是哪个大类型，根据nodekind_kind 判断是哪个子类型
//  {
//    case STMT:
//    {
//      string names[8]={"if_stmt","while_stmt","for_stmt","comp_stmt","input_stmt","output_stmt","var_dec","exp_stmt"};
//	  fout.width(40);
//      fout<<names[p->nodekind_kind];
//      break;
//    }
//    case EXPR:
//    {
//      string names[6]={"Type specifier  ","Expr  ","Not Epr ","Array  ","Const decl  ","ID decl  "};
//      string types[4]={"Notype","interger","char","boolean"};
//      string opname[]={"=","<","<=","==",">",">=","!=","+","-","*","/","%","++","--","&","|","^","!","<<",">>","&&","||"};
//	  
//	  fout.width(20);
//      fout<<names[p->nodekind_kind];
//	  fout.width(10);
//      fout<<types[p->type];
//	  fout.width(10);
//      switch(p->nodekind_kind)
//      {
//        case TYPE_EXPR:
//             fout<<"   ";
//             break;
//        case NOT_EXPR:
//			fout<<"op:  !";
//			break;
//        case OP_EXPR:
//             { //根据token的值与ASSIGN的差找到opname数组对应的位置；
//               fout<<"op:  "<<opname[p->attr.op-ASSIGN];
//               break;
//             }
//        case CONST_EXPR:
//             {
//             if(p->type==Integer)
//                fout<<"Integer:"<<p->attr.val;
//             else 
//               fout<<"Char:"<<p->attr.valc;
//             break;
//             }
//        case ID_EXPR:
//             {
//              fout<<"ID   "<<getname(p->attr.symbol_add);
//              break;
//             }
//      }
//      break;
//     }
//    case DECL:
//    {
//     string names[2]={"var declaration","Array declaratioin"};
//      fout.width(40);
//	  fout<<names[p->nodekind_kind];
//     break;
//    }
//  }
//  
//  fout<<"    Children:";
//  for(int i=0;i<MAXCHILD;i++)
//  {
//    if(p->child[i]==NULL)
//      continue;
//    else
//    {
//     fout<<p->child[i]->seq<<" ";
//    }
// 
//  if (i+1)//输出“兄弟”号
//	{
//		for (TreeNode *child = p->child[i]->sibling; child; child = child->sibling)
//			fout << child->seq << " ";
//	}
//  }
//  fout<<endl;
//}
void TreeNode::shownode()
{  
   fout.setf(ios_base::left);//左对齐
   fout.width(3);
   fout<<seq<<"\t";   //节点编号
  switch(nodekind)     //根据nodekind判断是哪个大类型，根据nodekind_kind 判断是哪个子类型
  {
    case STMT:
    {
      string names[8]={"if_stmt","while_stmt","for_stmt","comp_stmt","input_stmt","output_stmt","var_dec","exp_stmt"};
	  fout.width(40);
      fout<<names[nodekind_kind];
      break;
    }
    case EXPR:
    {
      string names[6]={"Type specifier  ","Expr  ","Not Epr ","Array  ","Const decl  ","ID decl  "};
      string types[4]={"Notype","interger","char","boolean"};
      string opname[]={"=","<","<=","==",">",">=","!=","+","-","*","/","%","++","--","&","|","^","!","<<",">>","&&","||"};
	  
	  fout.width(20);
      fout<<names[nodekind_kind];
	  fout.width(10);
      fout<<types[type];
	  fout.width(10);
      switch(nodekind_kind)
      {
        case TYPE_EXPR:
             fout<<"   ";
             break;
        case NOT_EXPR:
			fout<<"op:  !";
			break;
        case OP_EXPR:
             { //根据token的值与ASSIGN的差找到opname数组对应的位置；
               fout<<"op:  "<<opname[attr.op-ASSIGN];
               break;
             }
        case CONST_EXPR:
             {
             if(type==Integer)
                fout<<"Integer:"<<attr.val;
             else 
               fout<<"Char:"<<attr.valc;
             break;
             }
        case ID_EXPR:
             {
              fout<<"ID   "<<my.getname(attr.symbol_add);
              break;
             }
      }
      break;
     }
    case DECL:
    {
     string names[2]={"var declaration","Array declaratioin"};
      fout.width(40);
	  fout<<names[nodekind_kind];
     break;
    }
  }
  
  fout<<"    Children:";
  for(int i=0;i<MAXCHILD;i++)
  {
    if(child[i]==NULL)
      continue;
    else
    {
     fout<<child[i]->seq<<" ";
    }
 
  if (i+1)//输出“兄弟”号
	{
		for (TreeNode *temp =child[i]->sibling; temp; temp = temp->sibling)
			fout << temp->seq << " ";
	}
  }
  fout<<endl;
}
//进行类型检查
void NodeTable::type_check(TreeNode *p)
{
	switch(p->nodekind ){
		case STMT:{//检查语句
				switch(p->nodekind_kind ){
				case IF_STMT :{ //if语句判断可以是Integer/char/bool 转化成Bool
						if(p->child[0]->type!=Boolean && p->child[0]->type!=Integer && p->child [0]->type !=Char) //if语句判断不是bool/char/int 输出错误，否则函数返回
							   fout<<"The if_stmt judge is not boolean at line "<<p->lineno <<endl;
						p->child[0]->type =Boolean ;
						return;
					}	
				case WHILE_STMT :{
						if(p->child [0]->type!=Boolean && p->child[0]->type!=Integer && p->child [0]->type !=Char ) //while语句判断不是bool/char/int 输出错误，否则函数返回
							  fout<<"The while_stmt judge is not boolean at line "<<p->lineno <<endl;
						p->child[0]->type =Boolean ;
							  return;
					}
				case FOR_STMT :
					{               //for的判断语句先判断是不是int/char/bool 转化成bool
						if(p->child[1]!=NULL)
						{
							if(p->child [1]->type!=Boolean && p->child[1]->type!=Integer && p->child [1]->type !=Char ) //for语句判断不是bool/char/int 输出错误，否则函数返回
							  fout<<"The for_stmt judge is not boolean at line "<<p->lineno <<endl;
						p->child[1]->type =Boolean ;
						}
						return;
					}
				default:
					return;
				}
				return;
			}
		case EXPR: { //检查表达式
				switch(p->nodekind_kind ){
				case OP_EXPR :{   
					if(p->attr .op ==ASSIGN ){    //初始化标志设置
							 int add=p->child[0]->attr .symbol_add ;
							 if(symbol_table [add].def ==1)     //已经被定义
							 {
								 if(symbol_table [add].type!=p->child[1]->type)   //赋值语句左右两边类型不同
									 fout<<"The left and right sides of ASSIGN exp are of different types at line  "<<p->lineno <<endl;}
							     else
								  symbol_table [add].type =p->child [1]->type ;  //等号右边类型赋给左边
							      my.symbol_table[add].init=1;
							     return;
						}
					else{
						for(int i=0;i<2&&p->child[i]!=NULL;i++)
						{
							if(p->child[i]->nodekind_kind==ID_EXPR )
							{
								p->child[i]->type =symbol_table [p->child [i]->attr .symbol_add ].type ;
								if(symbol_table [p->child[i]->attr .symbol_add ].init !=1)
									fout<<"The ID "<<getname(p->child [i]->attr .symbol_add)<<" hasn't been inited before calculate!"<<endl;
							}
						}

						if(p->attr.op ==AND||p->attr.op==OR||p->attr .op ==OPPOSITE ) { //逻辑表达式两边运算类型bool/integer/char
							if((p->child[0]->type!=Boolean&&p->child[0]->type!=Integer && p->child[0]->type!=Char)||
								(p->child [1]->type!=Boolean && p->child [1]->type!=Integer  && p->child [1]->type!=Char) ){
								fout<<"The logical expr(&&/||!) is not boolean/Char/Integer at line "<<p->lineno<<endl;
							}
							if(p->child[0]->type !=p->child [1]->type )
								fout<<"Left and right are of different types,and have a type conversion at line"<<p->lineno <<endl;
						    p->type=p->child[0]->type;
							return;
						}
						if(p->attr.op ==PLUS||(p->attr.op>=MUL&&p->attr.op<=MOD))    //加 乘 除 模运算左右是integer或char
						{
							if((p->child[0]->type!=Integer  && p->child[0]->type!=Char)||(p->child [1]->type!=Integer  && p->child[1]->type!=Char))
								fout<<"The arithmetic operation expr('+'/'*'/'/'/'%') is not Interger/Char at line "<<p->lineno<<endl;
							if(p->child[0]->type !=p->child [1]->type )
								fout<<"Left and right are of different types,and have a type conversion at line"<<p->lineno <<endl;
							p->type=p->child[0]->type;
							return;
						}
						if(p->attr .op ==MINUS)     //减 判断是两个运算符还是一个运算符
						{
							if(p->child[1]!=NULL){   //两个运算符
							   if((p->child[0]->type!=Integer  && p->child[0]->type!=Char)||(p->child [1]->type!=Integer  && p->child[1]->type!=Char) )
								  fout<<"The arithmetic operation expr('-') is not Interger/Char at line "<<p->lineno<<endl;
							   if(p->child[0]->type !=p->child [1]->type )
								  fout<<"Left and right are of different types,and have a type conversion at line"<<p->lineno <<endl;
							}
							else               //一个运算符
							{
								if(p->child[0]->type!=Integer&&p->child [0]->type!=Char)
									 fout<<"The arithmetic operation expr('-') is not Interger/Char at line "<<p->lineno<<endl;
								if(p->child[0]->type !=p->child [1]->type )
									fout<<"Left and right are of different types,and have a type conversion at line"<<p->lineno <<endl;
							}
							p->type=p->child[0]->type;
							return;
						}
						if(p->attr .op ==INC||p->attr .op ==DEC )
						{
							if(p->child[0]->type!=Integer&&p->child [0]->type!=Char)
								 fout<<"The arithmetic operation expr('++'/'--') is not Interger/Char at line "<<p->lineno<<endl;
							if(p->child[0]->type !=p->child [1]->type )
								fout<<"Left and right are of different types,and have a type conversion at line"<<p->lineno <<endl;
							p->type=p->child[0]->type;
							return;
						}
						if(p->attr .op >=INAD && p->attr .op <=SHR)
						{
							if((p->child[0]->type!=Integer  && p->child[0]->type!=Char)||(p->child [1]->type!=Integer  && p->child[1]->type!=Char))
								fout<<"The bitwise operator expr('&'/'|'/'^'/'~'/'<<'/'>>') is not Interger/Char at line "<<p->lineno<<endl;
							if(p->child[0]->type !=p->child [1]->type )
								fout<<"Left and right are of different types,and have a type conversion at line"<<p->lineno <<endl;
							p->type=p->child[0]->type;
							return;
						}
						if(p->attr.op>=LT&&p->attr.op<=NEQ)    //关系运算运算左右是integer或char
						{
							if((p->child[0]->type!=Integer  && p->child[0]->type!=Char)||(p->child [1]->type!=Integer  && p->child[1]->type!=Char))
								fout<<"The arithmetic operation expr('<'/'<='/'>'/'>='/'=='/'!=') is not Interger/Char at line "<<p->lineno<<endl;
							if(p->child[0]->type !=p->child [1]->type )
								fout<<"Left and right are of different types,and have a type conversion at line"<<p->lineno <<endl;
							p->type=p->child[0]->type;
							return;
						}	
					  return;
				}
				case NOT_EXPR :{
					if(p->child[0]->type!=Boolean && p->child[0]->type!=Integer && p->child [0]->type !=Char)
					    fout<<"The Not_EXPR is not boolean/Integer/char at seq "<<p->seq  <<endl ;
						p->type=p->child[0]->type;
					return;
				  }
				default:       //对于ID_EXPR /CONST_EXPR中 CHAR,NUMBER 类型的expr不需要进行类型检查
					return;   
					}
				}
}
		case DECL:   //声明检查重定义
			{
				switch(p->nodekind_kind ){
				case VAR_DECL :{
					TreeNode *temp;
					for(temp=p->child[1];temp!=NULL;temp=temp->sibling)
					{
						if(temp->nodekind_kind ==ID_EXPR )
						{
							if(symbol_table [temp->attr.symbol_add ].def==1)
								{fout<<"The ID "<<getname (temp->attr.symbol_add )<<" has been difined at seq "<<temp->seq<<endl;}
							else
								{
									symbol_table [temp ->attr .symbol_add ].def =1;
									symbol_table[temp->attr .symbol_add ].type =p->child[0]->type;
							}

						}
						if(temp->nodekind_kind ==OP_EXPR &&temp->attr .op ==ASSIGN )
						{
							if(symbol_table [temp->child[0]->attr.symbol_add ].def==1)
								{fout<<"The ID "<<getname (temp->child[0]->attr.symbol_add )<<" has been difined at seq "<<temp->child[0]->seq<<endl;}
							else
								symbol_table [temp ->child[0]->attr .symbol_add ].def =1;
							if(symbol_table [temp ->child [0]->attr .symbol_add ].type !=p->child [0]->type )
								fout<<"The define is of different types! at seq "<<temp ->seq <<endl;
							else
								temp->child[0]->type =p->child[0]->type;
						}
					}
						return;
					}
				default:
					return;
				}
				return;
			}
	}	
}




TreeNode* NodeTable::createnode(int nodekind,int nodekind_kind,NodeAttr attr,int type,struct TreeNode *child0,struct TreeNode *child1,struct TreeNode *child2,struct TreeNode *child3)
{
  struct TreeNode *node=new TreeNode;

  if(node==NULL)
    fout<<"out of memory at line "<<lineno<<endl;
   else
   {
     node->nodekind=nodekind;
     node->nodekind_kind=nodekind_kind;
     node->attr=attr;
     node->type=type;
     node->child[0]=child0;
     node->child[1]=child1;
     node->child[2]=child2;
     node->child[3]=child3;
     node->sibling=NULL;
     node->lineno=lineno++;
     node->seq=nodenumber++;
     //shownode(node);
	 //type_check(node);
   }
   return node;
}
void NodeTable::display( TreeNode *a){
	int i=0;
	if(a!=NULL){
		for(;a->child[i]!=NULL;i++){
			display(a->child[i]);
		}
	}
	type_check(a);
	a->shownode();
	if(a->sibling!=NULL)
		display(a->sibling);

}  