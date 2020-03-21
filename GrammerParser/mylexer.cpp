/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 42 of your 30 day trial period.
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
* Date: 11/28/16
* Time: 20:11:46
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

#line 58 "mylexer.cpp"
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
#line 35 ".\\mylexer.l"

	// place any extra initialisation code here

#line 82 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 40 ".\\mylexer.l"

	// place any extra cleanup code here

#line 94 "mylexer.cpp"
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
#line 60 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
	

#line 166 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 68 ".\\mylexer.l"

#line 173 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 69 ".\\mylexer.l"
/*no action and no return */
#line 180 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 70 ".\\mylexer.l"
my.lineno++;
#line 187 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 107 ".\\mylexer.l"
return INT;
#line 194 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 108 ".\\mylexer.l"
return CHAR;
#line 201 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 109 ".\\mylexer.l"
return VOID;
#line 208 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 110 ".\\mylexer.l"
return MAIN;
#line 215 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 114 ".\\mylexer.l"
return IF;
#line 222 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 115 ".\\mylexer.l"
return ELSE;
#line 229 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 116 ".\\mylexer.l"
return FOR;
#line 236 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 117 ".\\mylexer.l"
return WHILE;
#line 243 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 120 ".\\mylexer.l"
return ASSIGN;
#line 250 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 121 ".\\mylexer.l"
return CIN;
#line 257 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 122 ".\\mylexer.l"
return COUT;
#line 264 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 127 ".\\mylexer.l"
return LT;
#line 271 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 128 ".\\mylexer.l"
return LE;
#line 278 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 129 ".\\mylexer.l"
return EQ;
#line 285 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 130 ".\\mylexer.l"
return GT;
#line 292 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 131 ".\\mylexer.l"
return GE;
#line 299 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 132 ".\\mylexer.l"
return NEQ;
#line 306 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 135 ".\\mylexer.l"
return PLUS;
#line 313 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 136 ".\\mylexer.l"
return MINUS;
#line 320 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 137 ".\\mylexer.l"
return MUL;
#line 327 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 138 ".\\mylexer.l"
return DIV;
#line 334 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 139 ".\\mylexer.l"
return MOD;
#line 341 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 140 ".\\mylexer.l"
return INC;
#line 348 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 141 ".\\mylexer.l"
return DEC;
#line 355 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 143 ".\\mylexer.l"
return INAD;
#line 362 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 144 ".\\mylexer.l"
return IOR;
#line 369 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 145 ".\\mylexer.l"
return XOR;
#line 376 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 146 ".\\mylexer.l"
return NOT;
#line 383 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 147 ".\\mylexer.l"
return SHL;
#line 390 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 148 ".\\mylexer.l"
return SHR;
#line 397 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 150 ".\\mylexer.l"
return AND;
#line 404 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 151 ".\\mylexer.l"
return OR;
#line 411 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 152 ".\\mylexer.l"
return OPPOSITE;
#line 418 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 155 ".\\mylexer.l"
return LBRACE;
#line 425 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 156 ".\\mylexer.l"
return RBRACE;
#line 432 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 157 ".\\mylexer.l"
return LPRACE;
#line 439 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 158 ".\\mylexer.l"
return RPRACE;
#line 446 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 159 ".\\mylexer.l"
return LSBRACE;
#line 453 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 160 ".\\mylexer.l"
return RSBRACE;
#line 460 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 161 ".\\mylexer.l"
return COMMA;
#line 467 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 162 ".\\mylexer.l"
return SIMICOLON;
#line 474 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 163 ".\\mylexer.l"
return COLON;
#line 481 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 164 ".\\mylexer.l"
return SQUITO;
#line 488 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 170 ".\\mylexer.l"
 yylval=&node;
              yylval->attr.valc=yytext[0];      //const Char
              return CONSTCHAR;
              
#line 498 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 174 ".\\mylexer.l"
 
              string str(yytext);
              address=my.getadd(str);          //判断是否在符号表中
              if(address==-1)
               address=my.insert(str,ID);      //不在插入
              else 
                 node.type=my.gettype(address);  //获得type
              yylval=&node;
              yylval->attr.symbol_add=address;  //在符号表中的位置存入属性
              
              return ID;               
             
#line 516 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 186 ".\\mylexer.l"

              yylval=&node;
              yylval->attr.val=my.getNumber(yytext); //数字的值存入属性
               return NUMBER;
             
             
#line 528 "mylexer.cpp"
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
		{ 4, 1 },
		{ 3, 3 },
		{ 42, 78 },
		{ 37, 5 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 78, 63 },
		{ 85, 78 },
		{ 42, 15 },
		{ 58, 30 },
		{ 56, 29 },
		{ 65, 63 },
		{ 59, 31 },
		{ 43, 15 },
		{ 3, 1 },
		{ 5, 1 },
		{ 3, 3 },
		{ 45, 66 },
		{ 57, 29 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 60, 32 },
		{ 15, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 0, 85 },
		{ 61, 34 },
		{ 51, 26 },
		{ 52, 26 },
		{ 67, 45 },
		{ 62, 39 },
		{ 67, 45 },
		{ 65, 43 },
		{ 63, 85 },
		{ 53, 26 },
		{ 0, 44 },
		{ 44, 16 },
		{ 64, 85 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 49, 21 },
		{ 50, 21 },
		{ 46, 19 },
		{ 47, 19 },
		{ 38, 7 },
		{ 23, 1 },
		{ 69, 51 },
		{ 24, 1 },
		{ 25, 1 },
		{ 70, 52 },
		{ 71, 53 },
		{ 72, 54 },
		{ 73, 55 },
		{ 26, 1 },
		{ 74, 57 },
		{ 27, 1 },
		{ 28, 1 },
		{ 75, 58 },
		{ 76, 59 },
		{ 29, 1 },
		{ 77, 60 },
		{ 0, 8 },
		{ 78, 64 },
		{ 30, 1 },
		{ 48, 20 },
		{ 40, 12 },
		{ 79, 69 },
		{ 80, 71 },
		{ 81, 72 },
		{ 82, 75 },
		{ 83, 76 },
		{ 84, 77 },
		{ 31, 1 },
		{ 32, 1 },
		{ 41, 14 },
		{ 86, 84 },
		{ 54, 27 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 55, 28 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 86 },
		{ 0, 0 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 22, 86 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 86, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 2 },
		{ 0, 0, 3 },
		{ 0, -56, 36 },
		{ 0, 0, 25 },
		{ 0, 44, 28 },
		{ -39, 89, 46 },
		{ 0, 0, 39 },
		{ 0, 0, 40 },
		{ 0, 0, 23 },
		{ 0, 60, 21 },
		{ 0, 0, 43 },
		{ 0, 67, 22 },
		{ 0, -24, 24 },
		{ 66, 20, 49 },
		{ 0, 0, 45 },
		{ 0, 0, 44 },
		{ 0, 20, 15 },
		{ 0, 41, 12 },
		{ 0, 17, 18 },
		{ 86, 0, 48 },
		{ 0, 0, 41 },
		{ 0, 0, 42 },
		{ 0, 0, 30 },
		{ 86, -47, 48 },
		{ 86, 6, 48 },
		{ 86, 18, 48 },
		{ 86, -82, 48 },
		{ 86, -78, 48 },
		{ 86, -89, 48 },
		{ 86, -66, 48 },
		{ 0, 0, 37 },
		{ 0, -68, 29 },
		{ 0, 0, 38 },
		{ 0, 0, 31 },
		{ 0, 0, 20 },
		{ 0, 0, 34 },
		{ 0, 21, 0 },
		{ 0, 0, 26 },
		{ 0, 0, 27 },
		{ 85, 0, 0 },
		{ -43, 52, 0 },
		{ 66, -4, 0 },
		{ 68, 16, 0 },
		{ 0, 0, 32 },
		{ 0, 0, 16 },
		{ 0, 0, 17 },
		{ 0, 0, 19 },
		{ 0, 0, 33 },
		{ 86, -13, 48 },
		{ 86, -23, 48 },
		{ 86, -29, 48 },
		{ 86, -26, 48 },
		{ 86, -24, 48 },
		{ 86, 0, 8 },
		{ 86, -24, 48 },
		{ 86, -10, 48 },
		{ 86, -9, 48 },
		{ 86, -7, 48 },
		{ 0, 0, 35 },
		{ 0, 0, 47 },
		{ -42, -26, 0 },
		{ 85, 58, 0 },
		{ 0, 0, 1 },
		{ 0, -42, 49 },
		{ 68, 0, 0 },
		{ 0, 146, 49 },
		{ 86, -10, 48 },
		{ 86, 0, 13 },
		{ 86, -11, 48 },
		{ 86, 5, 48 },
		{ 86, 0, 10 },
		{ 86, 0, 4 },
		{ 86, -3, 48 },
		{ 86, 8, 48 },
		{ 86, 1, 48 },
		{ 64, -30, 0 },
		{ 86, 0, 5 },
		{ 86, 0, 14 },
		{ 86, 0, 9 },
		{ 86, 0, 7 },
		{ 86, 0, 6 },
		{ 86, 12, 48 },
		{ -42, 21, 1 },
		{ 0, 71, 11 }
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
		0
	};
	yybackup = backup;
}
#line 193 ".\\mylexer.l"



