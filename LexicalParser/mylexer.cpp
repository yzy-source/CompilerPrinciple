/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 19 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 11/05/16
* Time: 23:52:12
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

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


#line 66 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 43 ".\\mylexer.l"

	// place any extra initialisation code here

#line 90 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 48 ".\\mylexer.l"

	// place any extra cleanup code here

#line 102 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 70 ".\\mylexer.l"
/*no action and no return */
#line 174 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 72 ".\\mylexer.l"
cout<<"INT\t"<<"int\t"<<endl;
#line 181 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 73 ".\\mylexer.l"
cout<<"CHAR\t"<<"char\t"<<endl;
#line 188 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 74 ".\\mylexer.l"
cout<<"VOID\t"<<"void\t"<<endl;
#line 195 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 75 ".\\mylexer.l"
cout<<"MAIN\t"<<"main\t"<<endl;
#line 202 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 76 ".\\mylexer.l"
cout<<"CLASS\t"<<"class\t"<<endl;
#line 209 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 79 ".\\mylexer.l"
cout<<"IF\t"<<"if\t"<<endl;
#line 216 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 80 ".\\mylexer.l"
cout<<"ELSE\t"<<"else\t"<<endl;
#line 223 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 81 ".\\mylexer.l"
cout<<"FOR\t"<<"for\t"<<endl;
#line 230 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 82 ".\\mylexer.l"
cout<<"DO\t"<<"do\t"<<endl;
#line 237 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 83 ".\\mylexer.l"
cout<<"WHILE\t"<<"while\t"<<endl;
#line 244 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 84 ".\\mylexer.l"
cout<<"BREAK\t"<<"break\t"<<endl;
#line 251 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 85 ".\\mylexer.l"
cout<<"CONTINUE\t"<<"continue\t"<<endl;
#line 258 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 86 ".\\mylexer.l"
cout<<"RETURN\t"<<"return\t"<<endl;
#line 265 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 87 ".\\mylexer.l"
cout<<"ASSIGN\t"<<"=\t"<<endl;
#line 272 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 90 ".\\mylexer.l"
cout<<"ID\t";yylval=installID();cout<<symbol_table[yylval]<<"\t"<<yylval<<endl;
#line 279 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 91 ".\\mylexer.l"
cout<<"NUMBER\t";yylval=installNumber();cout<<yylval<<"\t"<<yylval<<endl;
#line 286 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 94 ".\\mylexer.l"
cout<<"LT\t"<<"<\t"<<endl;
#line 293 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 95 ".\\mylexer.l"
cout<<"LE\t"<<"<=\t"<<endl;
#line 300 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 96 ".\\mylexer.l"
cout<<"EQ\t"<<"==\t"<<endl;
#line 307 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 97 ".\\mylexer.l"
cout<<"NE\t"<<"<>\t"<<endl;
#line 314 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 98 ".\\mylexer.l"
cout<<"GT\t"<<">\t"<<endl;
#line 321 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 99 ".\\mylexer.l"
cout<<"GE\t"<<">=\t"<<endl;
#line 328 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 100 ".\\mylexer.l"
cout<<"NZ\t"<<"!=\t"<<endl;
#line 335 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 103 ".\\mylexer.l"
cout<<"PLUS\t"<<"+\t"<<endl;
#line 342 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 104 ".\\mylexer.l"
cout<<"MINUS\t"<<"-\t"<<endl;
#line 349 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 105 ".\\mylexer.l"
cout<<"MUL\t"<<"*\t"<<endl;
#line 356 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 106 ".\\mylexer.l"
cout<<"DIV\t"<<"/\t"<<endl;
#line 363 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 107 ".\\mylexer.l"
cout<<"MOD\t"<<"%\t"<<endl;
#line 370 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 108 ".\\mylexer.l"
cout<<"INC\t"<<"++\t"<<endl;
#line 377 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 109 ".\\mylexer.l"
cout<<"DEC\t"<<"--\t"<<endl;
#line 384 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 110 ".\\mylexer.l"
cout<<"IAND\t"<<"&\t"<<endl;
#line 391 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 111 ".\\mylexer.l"
cout<<"IOR\t"<<"|\t"<<endl;
#line 398 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 112 ".\\mylexer.l"
cout<<"XOR\t"<<"^\t"<<endl;
#line 405 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 113 ".\\mylexer.l"
cout<<"NOT\t"<<"~\t"<<endl;
#line 412 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 114 ".\\mylexer.l"
cout<<"SHL\t"<<"<<\t"<<endl;
#line 419 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 115 ".\\mylexer.l"
cout<<"SHR\t"<<">>\t"<<endl;
#line 426 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 116 ".\\mylexer.l"
cout<<"AND\t"<<"&&\t"<<endl;
#line 433 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 117 ".\\mylexer.l"
cout<<"OR\t"<<"||\t"<<endl;
#line 440 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 118 ".\\mylexer.l"
cout<<"OPPSITE\t"<<"!\t"<<endl;
#line 447 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 121 ".\\mylexer.l"
cout<<"LBRACE\t"<<"{\t"<<endl;
#line 454 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 122 ".\\mylexer.l"
cout<<"RBRACE\t"<<"}\t"<<endl;
#line 461 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 123 ".\\mylexer.l"
cout<<"LPAREN\t"<<"(\t"<<endl;
#line 468 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 124 ".\\mylexer.l"
cout<<"RPAREN\t"<<")\t"<<endl;
#line 475 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 125 ".\\mylexer.l"
cout<<"LSBRACKET\t"<<"[\t"<<endl;
#line 482 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 126 ".\\mylexer.l"
cout<<"RSBRACKET\t"<<"]\t"<<endl;
#line 489 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 127 ".\\mylexer.l"
cout<<"COMMA\t"<<",\t"<<endl;
#line 496 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 128 ".\\mylexer.l"
cout<<"SIMICOLON\t"<<";\t"<<endl;
#line 503 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 129 ".\\mylexer.l"
COUT<<"COLON\t"<<":\t"<<endl;
#line 510 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 130 ".\\mylexer.l"
cout<<"SQUITO\t"<<"'\t"<<endl;
#line 517 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 131 ".\\mylexer.l"
cout<<"NOTE\t"<<"//\t"<<endl;
#line 524 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 132 ".\\mylexer.l"
cout<<"LNOTE\t"<<"/*\t"<<endl;
#line 531 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 133 ".\\mylexer.l"
cout<<"RNOTE\t"<<"*/\t"<<endl;
#line 538 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 204;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 3, 3 },
		{ 3, 3 },
		{ 54, 25 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 44, 14 },
		{ 69, 47 },
		{ 43, 13 },
		{ 69, 47 },
		{ 61, 30 },
		{ 45, 14 },
		{ 52, 20 },
		{ 53, 20 },
		{ 3, 1 },
		{ 4, 1 },
		{ 3, 3 },
		{ 47, 68 },
		{ 62, 30 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 58, 27 },
		{ 14, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 46, 15 },
		{ 59, 28 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 55, 26 },
		{ 48, 18 },
		{ 49, 18 },
		{ 50, 18 },
		{ 56, 26 },
		{ 60, 29 },
		{ 22, 1 },
		{ 57, 26 },
		{ 23, 1 },
		{ 24, 1 },
		{ 39, 4 },
		{ 63, 31 },
		{ 64, 32 },
		{ 25, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 65, 33 },
		{ 66, 34 },
		{ 30, 1 },
		{ 67, 36 },
		{ 0, 46 },
		{ 40, 6 },
		{ 31, 1 },
		{ 71, 54 },
		{ 72, 55 },
		{ 73, 56 },
		{ 74, 57 },
		{ 32, 1 },
		{ 75, 59 },
		{ 76, 60 },
		{ 77, 62 },
		{ 33, 1 },
		{ 34, 1 },
		{ 78, 63 },
		{ 79, 64 },
		{ 80, 65 },
		{ 35, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 81, 66 },
		{ 41, 10 },
		{ 51, 19 },
		{ 82, 71 },
		{ 83, 72 },
		{ 84, 73 },
		{ 85, 74 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 86, 75 },
		{ 87, 78 },
		{ 88, 79 },
		{ 89, 80 },
		{ 21, 99 },
		{ 90, 81 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 21, 99 },
		{ 91, 82 },
		{ 92, 84 },
		{ 93, 85 },
		{ 94, 88 },
		{ 95, 90 },
		{ 96, 93 },
		{ 97, 94 },
		{ 98, 96 },
		{ 99, 98 },
		{ 42, 11 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 99, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 1 },
		{ 0, 26, 40 },
		{ 0, 0, 29 },
		{ 0, 62, 32 },
		{ 0, 0, 50 },
		{ 0, 0, 43 },
		{ 0, 0, 44 },
		{ 0, 83, 27 },
		{ 0, 160, 25 },
		{ 0, 0, 47 },
		{ 0, -27, 26 },
		{ 0, -26, 28 },
		{ 68, 9, 17 },
		{ 0, 0, 49 },
		{ 0, 0, 48 },
		{ 0, 18, 18 },
		{ 0, 70, 15 },
		{ 0, -39, 22 },
		{ 99, 0, 16 },
		{ 0, 0, 45 },
		{ 0, 0, 46 },
		{ 0, 0, 34 },
		{ 99, -109, 16 },
		{ 99, -27, 16 },
		{ 99, -73, 16 },
		{ 99, -52, 16 },
		{ 99, -29, 16 },
		{ 99, -82, 16 },
		{ 99, -9, 16 },
		{ 99, -12, 16 },
		{ 99, -16, 16 },
		{ 99, -8, 16 },
		{ 0, 0, 41 },
		{ 0, -26, 33 },
		{ 0, 0, 42 },
		{ 0, 0, 35 },
		{ 0, 0, 24 },
		{ 0, 0, 38 },
		{ 0, 0, 53 },
		{ 0, 0, 30 },
		{ 0, 0, 31 },
		{ 0, 0, 52 },
		{ 0, 0, 51 },
		{ 68, 30, 0 },
		{ 70, -26, 0 },
		{ 0, 0, 36 },
		{ 0, 0, 19 },
		{ 0, 0, 21 },
		{ 0, 0, 20 },
		{ 0, 0, 23 },
		{ 0, 0, 37 },
		{ 99, 1, 16 },
		{ 99, 6, 16 },
		{ 99, 7, 16 },
		{ 99, -5, 16 },
		{ 99, 0, 10 },
		{ 99, -8, 16 },
		{ 99, -6, 16 },
		{ 99, 0, 7 },
		{ 99, -7, 16 },
		{ 99, 7, 16 },
		{ 99, -3, 16 },
		{ 99, 9, 16 },
		{ 99, 24, 16 },
		{ 0, 0, 39 },
		{ 0, -42, 17 },
		{ 70, 0, 0 },
		{ 0, 19, 17 },
		{ 99, 35, 16 },
		{ 99, 19, 16 },
		{ 99, 19, 16 },
		{ 99, 19, 16 },
		{ 99, 61, 16 },
		{ 99, 0, 9 },
		{ 99, 0, 2 },
		{ 99, 53, 16 },
		{ 99, 47, 16 },
		{ 99, 65, 16 },
		{ 99, 59, 16 },
		{ 99, 87, 16 },
		{ 99, 0, 3 },
		{ 99, 80, 16 },
		{ 99, 91, 16 },
		{ 99, 0, 8 },
		{ 99, 0, 5 },
		{ 99, 83, 16 },
		{ 99, 0, 4 },
		{ 99, 97, 16 },
		{ 99, 0, 12 },
		{ 99, 0, 6 },
		{ 99, 89, 16 },
		{ 99, 90, 16 },
		{ 99, 0, 11 },
		{ 99, 84, 16 },
		{ 99, 0, 14 },
		{ 99, 101, 16 },
		{ 0, 71, 13 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 136 ".\\mylexer.l"


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


