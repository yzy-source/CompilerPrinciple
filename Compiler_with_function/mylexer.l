%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2016Äê11ÔÂ20ÈÕ
****************************************************************************/

#include "myparser.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int yyval;
int lineno = 0;
char text[20];
extern struct Node;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
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

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here

//reserved words
"if"								{return IF;}
"else"								{return ELSE;}
"while"								{return WHILE;}
"for"								{return FOR;}
"int"								{return INT;}
"char"								{return CHAR;}
"output"							{return OUTPUT;}
"input"								{return INPUT;}
"return"							{return RETURN;}
//"bool"								{return BOOL;}

//number
[123456789]+[0123456789]*
|[0]								{yyval = atoi(yytext);return NUM;}

//ConstChar
'.'									{text[0] = yytext[1];return CONSTCHAR;}

//ID
[[:alpha:]_][[:alpha:]0-9_]*		{strcpy_s(text,strlen(yytext)+1,yytext);return ID;}

//special symbols
"+"									{return ADD;}
"-"									{return SUB;}
"*"									{return MUL;}
"/"									{return DIV;}
"//"								{ 
										char c;
										while (true)
											if((c=yyinput()) == NULL || c == '\n') break;
									}
"/*"								{ 
										char c;
										bool isdone = false;
										do {
											while ((c = yyinput()) != '*')
												if (c == NULL) break;
											while ((c = yyinput()) == '*');
												if (c == '/') isdone = true;
										} while (!isdone);
									}
"%"									{return MOD;}
"="									{return EQU;}
"&"									{return LAND;}
"^"									{return LXOR;}
"|"									{return LOR;}
";"									{return SEMICOLON;}
"++"								{return INC;}
"--"								{return DEC;}
"("									{return LP;}
")"									{return RP;}
"{"									{return LB;}
"}"									{return RB;}
"~"									{return NOT;}
">"									{return GT;}
"<"									{return LT;}
"=="								{return EQ;}
">="								{return GE;}
"<="								{return LE;}
"!="								{return NE;}
","									{return COMMA;}
"<<"								{return LSHIFT;}
">>"								{return RSHIFT;}
"&&"								{return AND;}
"||"								{return OR;}

//blank symbols
[ \t]*								{}
[\n]								{lineno++;}
//others
//.									{return ERROR;}

%%

/////////////////////////////////////////////////////////////////////////////
// programs section