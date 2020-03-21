%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2016年11月17日
****************************************************************************/

#include <string>

#include "myparser.h"
#include "NodeAndTable.h"
#include <iostream>
using namespace std;

int address=0;   //存储ID在符号表中的位置
extern NodeTable my;    //NodeTable对象
TreeNode node;    //临时定义一个TreeNode 
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
	//int getID()
	
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
delim       [ \t]
ws          {delim}+
newline      \n
letter      [A-Za-z]
digit       [0-9]
id          ({letter}|[_])({letter}|{digit}|[_])*
number      {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
constchar   '.'
annotation  ("/*"([^*"]*|".*"|\*+[^/])*\**"*/")|("//".*\n)

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
	
%}

// place your Lex rules here

{annotation} {}
{ws}         {/*no action and no return */}
{newline}    {my.lineno++;}
//"/*"         { 
//               char c;
//               ANNO:
//               c=cin.get();
//               while(c!='*'&&c!='"')
//                 c=cin.get();
//               if(c=='"')
//               {
//                 do{
//                     c=cin.get();
//                     if(c=='\n')
//                       my.lineno++;
//                     
//                    }while(c!='"');
//                }
//                if(c=='*'){
//                do{
//                   c=cin.get();
//                   if(c=='/')
//                      break;
//                   if(c=='\n')
//                      my.lineno++;
//                    if(c!='*')
//                      goto ANNO;
//                }while(c=='*');
//                }
//              }
//"//"         {
//              //单行注释
//               char c;
//              do{ 
//                  c=cin.get();                   
//                 }while(c!='\n');
//                 my.lineno++;
//             }
//type
int         {return INT;}
char        {return CHAR;}
void        {return VOID;}
main        {return MAIN;}


//paragraph
if          {return IF;} 
else        {return ELSE;}
for         {return FOR;}
while       {return WHILE;}


"="         {return ASSIGN;}
"cin"       {return CIN;}
"cout"      {return COUT;}



//relation
"<"         {return LT;}
"<="        {return LE;}
"=="        {return EQ;}
">"         {return GT;}
">="        {return GE;}
"!="        {return NEQ;}

//logical
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return MUL;}
"/"         {return DIV;}
"%"         {return MOD;}
"++"        {return INC;}
"--"        {return DEC;}

"&"         {return INAD;}
"|"         {return IOR;}
"^"         {return XOR;}
"~"         {return NOT;}
"<<"        {return SHL;}
">>"        {return SHR;}

"&&"        {return AND;}
"||"        {return OR;}
"!"         {return OPPOSITE;}

//segmal
"{"         {return LBRACE;}
"}"         {return RBRACE;}
"("         {return LPRACE;}
")"         {return RPRACE;}
"["         {return LSBRACE;}
"]"         {return RSBRACE;}
","         {return COMMA;}
";"         {return SIMICOLON;}
":"         {return COLON;}
"'"         {return SQUITO;}
//"//"        {return NOTE;}
//"/*"        {return LNOTE;}
//"*/"        {return RNOTE;}


{constchar} { yylval=&node;
              yylval->attr.valc=yytext[1];      //const Char
              return CONSTCHAR;
              }
{id}        { 
              string str(yytext);
              address=my.getadd(str);          //判断是否在符号表中
              if(address==-1)
               address=my.insert(str,ID);      //不在插入
              else 
                 node.type=my.gettype(address);  //获得type
              yylval=&node;
              yylval->attr.symbol_add=address;  //在符号表中的位置存入属性
              
              return ID;               
             }
{number}     {
              yylval=&node;
              yylval->attr.val=my.getNumber(yytext); //数字的值存入属性
               return NUMBER;
             
             }  

%%

