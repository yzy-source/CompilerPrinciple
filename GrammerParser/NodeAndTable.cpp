#include<iostream>
#include <string>
#include"NodeAndTable.h"
#include<fstream>
using namespace std;

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
int NodeTable::insert(string name,int token)        
{
  if(tablenumber>=max_table)
     return -1;
  symbol_table[tablenumber].name=name;
  symbol_table[tablenumber].token=token;
  symbol_table[tablenumber].type=0;
  tablenumber++;
  return (tablenumber-1);
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
string& NodeTable::getname(int pos)
{
  return symbol_table[pos].name;
}


//设置符号相应位置的ID 的type
int NodeTable::set_type(int pos,int type)
{
 if(pos<0||pos>=tablenumber)
   {
     cout<<"error"<<endl;
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
     cout<<"error"<<endl;
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

//分析树定义————
void NodeTable::shownode(struct TreeNode * p)
{  
   fout.setf(ios_base::left);//左对齐
   fout.width(3);
   fout<<p->seq<<"\t";   //节点编号
  switch(p->nodekind)     //根据nodekind判断是哪个大类型，根据nodekind_kind 判断是哪个子类型
  {
    case STMT:
    {
      string names[8]={"if_stmt","while_stmt","for_stmt","comp_stmt","input_stmt","output_stmt","var_dec","exp_stmt"};
	  fout.width(40);
      fout<<names[p->nodekind_kind];
      break;
    }
    case EXPR:
    {
      string names[6]={"Type specifier  ","Expr  ","Not Epr ","Array  ","Const decl  ","ID decl  "};
      string types[4]={"Notype","interger","char","boolean"};
      string opname[]={"=","<","<=","==",">",">=","!=","+","-","*","/","%","++","--","&","|","^","!","<<",">>","&&","||","!"};
	  
	  fout.width(20);
      fout<<names[p->nodekind_kind];
	  fout.width(10);
      fout<<types[p->type];
	  fout.width(10);
      switch(p->nodekind_kind)
      {
        case TYPE_EXPR:
             fout<<"   ";
             break;
        case NOT_EXPR:
			fout<<"op:  !";
			break;
        case OP_EXPR:
             { //根据token的值与ASSIGN的差找到opname数组对应的位置；
               fout<<"op:  "<<opname[p->attr.op-ASSIGN];
               break;
             }
        case CONST_EXPR:
             {
             if(p->type==Integer)
                fout<<"Integer:"<<p->attr.val;
             else 
               fout<<"Char:"<<p->attr.valc;
             break;
             }
        case ID_EXPR:
             {
              fout<<"ID   "<<getname(p->attr.symbol_add);
              break;
             }
      }
      break;
     }
    case DECL:
    {
     string names[2]={"var declaration","Array declaratioin"};
      fout.width(40);
	  fout<<names[p->nodekind_kind];
     break;
    }
  }
  
  fout<<"    Children:";
  for(int i=0;i<MAXCHILD;i++)
  {
    if(p->child[i]==NULL)
      continue;
    else
    {
     fout<<p->child[i]->seq<<" ";
    }
 
  if (i+1)//输出“兄弟”号
	{
		for (TreeNode *child = p->child[i]->sibling; child; child = child->sibling)
			fout << child->seq << " ";
	}
  }
  fout<<endl;
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
     node->lineno=lineno;
     node->seq=nodenumber++;
     shownode(node);
   }
   return node;
}