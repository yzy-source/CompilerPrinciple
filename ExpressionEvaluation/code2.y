%{
/****************************************************************************
code2.y
ParserWizard generated YACC file.

Date: 2016��10��28��
1.�����еĴʷ��������ܾ�����yygettoken������ʵ�֣�Ϊ+��-��*��\��(��)ÿ��������������ֱ���һ�����������yygettoken��ʵ�ִ��룬��ʶ����Щ���ʣ�����������𷵻ظ��ʷ���������

2.ʵ�ֹ��ܸ�ǿ�Ĵʷ��������򣬿�ʶ�𲢺��Կո��Ʊ�����س��ȿհ׷�����ʶ���λʮ����������


****************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <iostream>
using namespace std;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here
	virtual int yygettoken();
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
%include{
#ifndef YYSTYPE
#define YYSTYPE   double     //����ֵΪdouble���͵�
#define yylval (*reinterpret_cast<YYSTYPE*>(yylvalptr))
#endif

}

%token ADD
%token SUB
%token MUL
%token DIV
%token L_BRACKET
%token R_BRACKET
%token NUMBER

%left ADD SUB
%left MUL DIV
%right UMINUS


%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)
lines	:	lines expr '\n'	{ cout<<$2<<endl; }                //ʶ��س�
		|	lines '\n'
		|
		;
expr	:	expr ADD expr	{ $$ = $1 + $3 ; }
		|	expr SUB expr	{ $$ = $1 - $3; }
		|	expr MUL expr	{ $$ = $1 * $3; }
		|	expr DIV expr	{ $$ = $1 / $3; }
		|	L_BRACKET expr R_BRACKET	{ $$ = $2; }
		|	SUB expr %prec UMINUS	{ $$ = -$2; }             //��Ŀ����UMINUS���нϸߵ����ȼ�
		|	NUMBER  {$$=$1;}                             //yylval����ֵ
		;





%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int YYPARSERNAME::yygettoken()
{
	// place your token retrieving code here
	char c;
	c=cin.get();
	while(c==' '||c=='\t')                 //ʶ��ո��Ʊ��������
	   c=cin.get();
	switch(c)
	{
	  case '+':
	      return ADD;
	  case '-':
	      return SUB;
	  case '*':
	      return MUL;
	  case '/':
	      return DIV;
	  case'(':
	      return L_BRACKET;
	  case ')':
	      return R_BRACKET;
	  default:
	      if(isdigit(c))
	      { 
	          yylval=c-'0';
	          c=cin.get();
	          while(true)
	          {
	            while(c==' '||c=='\t')
	              c=cin.get();
	             if(isdigit(c))
	             yylval=yylval*10+(c-'0');
	            else
	             break;
	            c=cin.get();
	          }
	          cin.unget();                  //����Ĳ������ֵ��ַ�����
	          return NUMBER;
	      }
	      
	      else 
	      {
	          return c;
	      }
	}
}

int main(void)
{

	int n = 1;
	myparser parser;
	if (parser.yycreate()) {
		n = parser.yyparse();
	}
	return n;
}

