#include"mylexer.h"
#include"myparser.h"

using namespace std;
//enum PARENT;
//enum STMT_CHILD;
//enum EXP_CHILD;
//enum DEC_CHILD;
//enum TYPE;
////����
//
////���ʽ����
//union NodeAttr;
//struct TreeNode;
//
////���ű�����
//struct table ;
//class NodeTable;
//��䣬���ʽ������
const int MAXCHILD=4;
const int max_table=100;
enum PARENT
{
  STMT=0,                    
  EXPR,
  DECL
};
 //��䣺if,while,for ,�������
enum STMT_CHILD
{
  IF_STMT=0,                
  WHILE_STMT,
  FOR_STMT,
  COMP_STMT,
  INPUT_STMT,                //����������
  OUTPUT_STMT,
  VAR_DEC,
  EXP_STMT,
};
 //���ʽ�����ͣ����㣬������ID
enum EXP_CHILD
{
  TYPE_EXPR=0,
  OP_EXPR,
  NOT_EXPR,
  ARRAY_EXPR,  
  CONST_EXPR,
  ID_EXPR
};
 //������������������������
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
 int symbol_add;    //���ڷ��ű�λ��
 
 NodeAttr(void){op=0;} //������
 NodeAttr(int i){op=i;} //NUM
 NodeAttr(char c){valc=c;}//�ַ���
 
};
struct TreeNode
{
  struct TreeNode *child[MAXCHILD];  //���ӽڵ�
//struct TreeNode* child;
  struct TreeNode *sibling;          //�ֵܽڵ�
  int lineno;                        //������
  int nodekind;                      //����
  int nodekind_kind;                 //������
  NodeAttr attr;                     //����
  int type;                          //��������
  int seq;                           //�ڵ���
};
struct table 
{
 string name;    //��ʶ������    
 int token;      //��ʶ���������
 int type;      //��ʶ������
};

class NodeTable{
public:
	table symbol_table[max_table];
	TreeNode *node;
	int tablenumber;   //��¼���ű�ı�ʶ����Ŀ
   // int address;       //�洢ID,NUMBER �ڷ��ű��е�λ��
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

