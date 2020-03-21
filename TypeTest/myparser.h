/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 49 of your 30 day trial period.
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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/05/16
* Time: 17:45:18
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 27 ".\\myparser.y"

	// place any extra class members here

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 42 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif

#line 82 "myparser.h"
#define INT 257
#define CHAR 258
#define VOID 259
#define MAIN 260
#define ID 261
#define NUMBER 262
#define CONSTCHAR 263
#define IF 264
#define ELSE 265
#define FOR 266
#define WHILE 267
#define CIN 268
#define COUT 269
#define ASSIGN 270
#define LT 271
#define LE 272
#define EQ 273
#define GT 274
#define GE 275
#define NEQ 276
#define PLUS 277
#define MINUS 278
#define MUL 279
#define DIV 280
#define MOD 281
#define INC 282
#define DEC 283
#define INAD 284
#define IOR 285
#define XOR 286
#define NOT 287
#define SHL 288
#define SHR 289
#define AND 290
#define OR 291
#define OPPOSITE 292
#define LBRACE 293
#define RBRACE 294
#define LPRACE 295
#define RPRACE 296
#define LSBRACE 297
#define RSBRACE 298
#define COMMA 299
#define SIMICOLON 300
#define COLON 301
#define SQUITO 302
#define NOTE 303
#define LNOTE 304
#define RNOTE 305
#define UMINUS 306
#endif
