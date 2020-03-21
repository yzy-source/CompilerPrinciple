%{
/****************************************************************************
code2.y
ParserWizard generated YACC file.

Date: 2016年10月28日
1.将所有的词法分析功能均放在yygettoken函数内实现，为+、-、*、\、(、)每个运算符及整数分别定义一个单词类别，在yygettoken内实现代码，能识别这些单词，并将单词类别返回给词法分析程序。

2.实现功能更强的词法分析程序，可识别并忽略空格、制表符、回车等空白符，能识别多位十进制整数。


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
#define YYSTYPE   double     //属性值为double类型的
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
lines	:	lines expr '\n'	{ cout<<$2<<endl; }                //识别回车
		|	lines '\n'
		|
		;
expr	:	expr ADD expr	{ $$ = $1 + $3 ; }
		|	expr SUB expr	{ $$ = $1 - $3; }
		|	expr MUL expr	{ $$ = $1 * $3; }
		|	expr DIV expr	{ $$ = $1 / $3; }
		|	L_BRACKET expr R_BRACKET	{ $$ = $2; }
		|	SUB expr %prec UMINUS	{ $$ = -$2; }             //单目运算UMINUS具有较高的优先级
		|	NUMBER  {$$=$1;}                             //yylval属性值
		;





%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int YYPARSERNAME::yygettoken()
{
	// place your token retrieving code here
	char c;
	c=cin.get();
	while(c==' '||c=='\t')                 //识别空格，制表符并跳过
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
	          cin.unget();                  //多读的不是数字的字符回流
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

