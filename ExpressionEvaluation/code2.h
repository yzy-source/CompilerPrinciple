/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 15 of your 30 day trial period.
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
* code2.h
* C++ header file generated from code2.y.
* 
* Date: 11/01/16
* Time: 19:33:58
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _CODE2_H
#define _CODE2_H

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
#line 26 ".\\code2.y"

	// place any extra class members here
	virtual int yygettoken();
	//double yyvalue;

#line 71 "code2.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 43 ".\\code2.y"

#ifndef YYSTYPE
#define YYSTYPE   double     //����ֵΪdouble���͵�
#define yylval (*reinterpret_cast<YYSTYPE*>(yylvalptr))
#endif


#line 86 "code2.h"
#define ADD 257
#define SUB 258
#define MUL 259
#define DIV 260
#define L_BRACKET 261
#define R_BRACKET 262
#define NUMBER 263
#define UMINUS 264
#endif
