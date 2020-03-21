%{
/****************************************************************************
code2_2.y
ParserWizard generated YACC file.

Date: 2016��10��29��

�޸�Yacc���򣬲����б��ʽ�ļ��㣬����ʵ����׺���ʽ����׺���ʽ��ת����

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
#define YYSTYPE   double
#define yylval (*reinterpret_cast<YYSTYPE*>(yylvalptr))
#endif

}

%token ADD
%token SUB
%token MUL
%token DIV
//%token L_BRACKET
//%token R_BRACKET
%token NUMBER

%left ADD SUB
%left MUL DIV
%right UMINUS


%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

lines	:	lines expr '\n'	{ cout<<endl; }                //ʶ��س�
		|	lines '\n'
		|
		;
expr	:	expr ADD expr	{ cout<<"+ ";}
		|	expr SUB expr	{ cout<<"- ";}
		|	expr MUL expr	{ cout<<"* ";}
		|	expr DIV expr	{ cout<<"/ ";}
	//	|	'(' expr ')'	{ $$=$2;}
		|	SUB expr %prec UMINUS	{ cout<< "-" ;}             //��Ŀ����UMINUS���нϸߵ����ȼ�
		|	NUMBER           {cout<<$1<<" ";}               		          
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

