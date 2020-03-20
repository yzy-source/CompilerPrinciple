%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

列出你的C编译器支持的语言特性所涉及的单词，设计正规定义
利用Lex工具实现词法分析器，识别所有单词，能将源程序转化为单词流


可以输入简单的C源程序，输出单词流每个单词的词素内容、单词类别和属性
（常数的属性可以是数值，标识符可以是指向符号表的指针）。
Date: 2016年11月5日
****************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

int number=0;     //记录符号表中已经有的标识符数目
char symbol_table[100][30];  //符号表，记录标识符
int yylval;

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
	int installID();
	int installNumber();
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


delim       [ \t\n]
ws          {delim}+
letter      [A-Za-z]
digit       [0-9]
id          ({letter}|[_])({letter}|{digit}|[_])*
number      {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
annotation  ("/*"([^*"]*|".*"|\*+[^/])*\**"*/")|("//".*\n)
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here


{ws}        {/*no action and no return */}
//type
int         {cout<<"INT\t"<<"int\t"<<endl;}
char        {cout<<"CHAR\t"<<"char\t"<<endl;}
void        {cout<<"VOID\t"<<"void\t"<<endl;}
main        {cout<<"MAIN\t"<<"main\t"<<endl;}
class       {cout<<"CLASS\t"<<"class\t"<<endl;}

//paragraph
if          {cout<<"IF\t"<<"if\t"<<endl;}
else        {cout<<"ELSE\t"<<"else\t"<<endl;}
for         {cout<<"FOR\t"<<"for\t"<<endl;}
do          {cout<<"DO\t"<<"do\t"<<endl;}
while       {cout<<"WHILE\t"<<"while\t"<<endl;}
break       {cout<<"BREAK\t"<<"break\t"<<endl;}
continue    {cout<<"CONTINUE\t"<<"continue\t"<<endl;}
return      {cout<<"RETURN\t"<<"return\t"<<endl;}
"="         {cout<<"ASSIGN\t"<<"=\t"<<endl;}

//var
{id}        {cout<<"ID\t";yylval=installID();cout<<symbol_table[yylval]<<"\t"<<yylval<<endl;}
{number}    {cout<<"NUMBER\t";yylval=installNumber();cout<<yylval<<"\t"<<yylval<<endl;}

//relation
"<"         {cout<<"LT\t"<<"<\t"<<endl;}
"<="        {cout<<"LE\t"<<"<=\t"<<endl;}
"=="        {cout<<"EQ\t"<<"==\t"<<endl;}
"<>"        {cout<<"NE\t"<<"<>\t"<<endl;}
">"         {cout<<"GT\t"<<">\t"<<endl;}
">="        {cout<<"GE\t"<<">=\t"<<endl;}
"!="        {cout<<"NZ\t"<<"!=\t"<<endl;}

//logical
"+"         {cout<<"PLUS\t"<<"+\t"<<endl;}
"-"         {cout<<"MINUS\t"<<"-\t"<<endl;}
"*"         {cout<<"MUL\t"<<"*\t"<<endl;}
"/"         {cout<<"DIV\t"<<"/\t"<<endl;}
"%"         {cout<<"MOD\t"<<"%\t"<<endl;}
"++"        {cout<<"INC\t"<<"++\t"<<endl;}
"--"        {cout<<"DEC\t"<<"--\t"<<endl;}
"&"         {cout<<"IAND\t"<<"&\t"<<endl;}
"|"         {cout<<"IOR\t"<<"|\t"<<endl;}
"^"         {cout<<"XOR\t"<<"^\t"<<endl;}
"~"         {cout<<"NOT\t"<<"~\t"<<endl;}
"<<"        {cout<<"SHL\t"<<"<<\t"<<endl;}
">>"        {cout<<"SHR\t"<<">>\t"<<endl;}
"&&"        {cout<<"AND\t"<<"&&\t"<<endl;}
"||"        {cout<<"OR\t"<<"||\t"<<endl;}
"!"         {cout<<"OPPSITE\t"<<"!\t"<<endl;}

//segmal
"{"         {cout<<"LBRACE\t"<<"{\t"<<endl;}
"}"         {cout<<"RBRACE\t"<<"}\t"<<endl;}
"("         {cout<<"LPAREN\t"<<"(\t"<<endl;}
")"         {cout<<"RPAREN\t"<<")\t"<<endl;}
"["         {cout<<"LSBRACKET\t"<<"[\t"<<endl;}
"]"         {cout<<"RSBRACKET\t"<<"]\t"<<endl;}
","         {cout<<"COMMA\t"<<",\t"<<endl;}
";"         {cout<<"SIMICOLON\t"<<";\t"<<endl;}
":"         {COUT<<"COLON\t"<<":\t"<<endl;}
"'"         {cout<<"SQUITO\t"<<"'\t"<<endl;}
"//"        {cout<<"NOTE\t"<<"//\t"<<endl;}
"/*"        {cout<<"LNOTE\t"<<"/*\t"<<endl;}
"*/"        {cout<<"RNOTE\t"<<"*/\t"<<endl;}


%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int mylexer::installID()
{      
       bool judge=false;
       int index=0;
       for(;index<number;index++)
       {
          if(strcmp(symbol_table[index],yytext)==0)
           {  
              judge=true;
              break;
            }
       }
       if(judge)
         return index;
       else
       { 
         strcpy_s(symbol_table[number],strlen(yytext)+1,yytext);
         number++;
         return (number-1);
       }
         
}

int mylexer::installNumber()
{
       int value=0;
       for(int i=0;i<yyleng;i++)
       {
          value=value*10+(yytext[i]-'0'); 

       }
       return value;
       
    
      
}
int main(void)
{
	int n = 1;
	mylexer lexer;
	
	cout<<"单词\t"<<"词素\t"<<"属性\t"<<endl;
	
	
	if (lexer.yycreate()) 
	{
	    //lexer.yyin=new ifstream("mylex.cpp");
	    
		n = lexer.yylex();
	}
	
	return n;
}

