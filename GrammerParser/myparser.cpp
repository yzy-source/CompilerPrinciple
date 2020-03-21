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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 11/28/16
* Time: 20:11:46
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2016年11月22日
****************************************************************************/


#include "mylexer.h"
#include "NodeAndTable.h"
#include <string>
#include <iostream>
using namespace std;

extern NodeTable my;


#line 57 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 32 ".\\myparser.y"

	// place any extra initialisation code here

#line 81 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 37 ".\\myparser.y"

	// place any extra cleanup code here

#line 95 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 82 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(4 - 4);
             
#line 207 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 86 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(5 - 5);
             
#line 222 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 90 ".\\myparser.y"

              (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(5 - 5);
             
#line 237 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 94 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(6 - 6); 
             
#line 252 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 100 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr) = my.createnode(STMT, COMP_STMT, 0, Notype, yyattribute(2 - 3),NULL,NULL,NULL);
             
#line 267 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 104 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=NULL;
             
#line 282 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 109 ".\\myparser.y"

              YYSTYPE t=yyattribute(1 - 2);
               if(t!=NULL)
               {
                while(t->sibling!=NULL)
                   t=t->sibling;
                t->sibling=yyattribute(2 - 2);
                (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
                 } 
                else
                 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);              
             
#line 306 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 122 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 321 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 127 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 336 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 131 ".\\myparser.y"

              (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 351 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 135 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 366 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 139 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 381 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 143 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 396 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 147 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 411 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 151 ".\\myparser.y"

              (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 426 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 155 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
             
#line 441 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 161 ".\\myparser.y"

              //同时声明的ID 赋给同样的类型
              TreeNode *p;
              (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(DECL,VAR_DECL,0,Notype,yyattribute(1 - 3),yyattribute(2 - 3),NULL,NULL);
               for(p=yyattribute(2 - 3);p!=NULL&&p->type==ID;p=p->sibling)
               { 
                 p->type=yyattribute(1 - 3)->type;
                 my.set_type(p->attr.symbol_add,p->type);
                 
               }
                
             
#line 465 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 175 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = my.createnode(EXPR, TYPE_EXPR, 0, Integer,NULL,NULL,NULL,NULL);
              
#line 480 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 179 ".\\myparser.y"

              (*(YYSTYPE YYFAR*)yyvalptr) = my.createnode(EXPR, TYPE_EXPR, 0, Char,NULL,NULL,NULL,NULL);
              
#line 495 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 185 ".\\myparser.y"
 
               //将兄弟结点串起来
                 YYSTYPE t=yyattribute(1 - 3);
                 if(t!=NULL)
                 {
                   while(t->sibling!=NULL)
                     t=t->sibling;
                   t->sibling=yyattribute(3 - 3);
                  (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3);
                 }
                 else 
                  (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(3 - 3);
                 
               
#line 521 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 200 ".\\myparser.y"

                 YYSTYPE t=yyattribute(1 - 3);
                 if(t!=NULL)
                 {
                  while(t->sibling!=NULL)
                     t=t->sibling;
                   t->sibling=yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3);
                  }
                  else 
                  (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(3 - 3);
               
#line 545 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 213 ".\\myparser.y"

                 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
               
#line 560 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 217 ".\\myparser.y"

                 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
               
#line 575 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 223 ".\\myparser.y"

                 (*(YYSTYPE YYFAR*)yyvalptr) =my.createnode(EXPR, ID_EXPR, yyattribute(1 - 1)->attr.symbol_add, yyattribute(1 - 1)->type,NULL,NULL,NULL,NULL);
                
#line 590 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 228 ".\\myparser.y"

                  (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,IF_STMT,0,Notype,yyattribute(3 - 7),yyattribute(5 - 7),yyattribute(7 - 7),NULL);
                
#line 605 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 232 ".\\myparser.y"

                  (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,IF_STMT,0,Notype,yyattribute(3 - 5),yyattribute(5 - 5),NULL,NULL);
                
#line 620 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 237 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,FOR_STMT,0,Notype,yyattribute(3 - 7),yyattribute(4 - 7),yyattribute(5 - 7),yyattribute(7 - 7));
                 
#line 635 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 241 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,FOR_STMT,0,Notype,yyattribute(3 - 6),yyattribute(4 - 6),yyattribute(6 - 6),NULL);
                 
#line 650 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 246 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,WHILE_STMT,0,Notype,yyattribute(3 - 5),yyattribute(5 - 5),NULL,NULL);
                 
#line 665 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 251 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,INPUT_STMT,0,Notype,yyattribute(3 - 4),yyattribute(4 - 4),NULL,NULL);
                 
#line 680 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 256 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,INPUT_STMT,0,Notype,yyattribute(3 - 3),yyattribute(4 - 3),NULL,NULL);
                 
#line 695 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 260 ".\\myparser.y"

                  (*(YYSTYPE YYFAR*)yyvalptr)=NULL;
                 
#line 710 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 265 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,OUTPUT_STMT,0,Notype,yyattribute(3 - 4),yyattribute(4 - 4),NULL,NULL);
                  
#line 725 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 270 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,OUTPUT_STMT,0,Notype,yyattribute(3 - 3),yyattribute(4 - 3),NULL,NULL);
                  
#line 740 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 274 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=NULL;
                  
#line 755 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 279 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(STMT,EXP_STMT,0,Notype,yyattribute(1 - 2),NULL,NULL,NULL);
                  
#line 770 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 283 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=NULL;
                  
#line 785 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 288 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,ASSIGN,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 800 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 292 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,ASSIGN,Notype,yyattribute(1 - 5),yyattribute(4 - 5),NULL,NULL);
                  
#line 815 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 296 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                  
#line 830 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 302 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,OR,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL); 
                  
#line 845 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 306 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                  
#line 860 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 311 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,AND,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL); 
                  
#line 875 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 315 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                  
#line 890 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 320 ".\\myparser.y"

                     (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,SHL,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL); 
                   
#line 905 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 324 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,SHR,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL); 
                   
#line 920 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 328 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                   
#line 935 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 333 ".\\myparser.y"

                    
                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,EQ,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 951 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 338 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,LT,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 966 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 342 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,GT,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 981 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 346 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,LE,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 996 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 350 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,GE,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 1011 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 354 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,NEQ,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 1026 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 358 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1); 
                  
#line 1041 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 363 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,PLUS,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 1056 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 367 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,MINUS,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 1071 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 371 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,MINUS,Notype,yyattribute(2 - 2),NULL,NULL,NULL);
                  
#line 1086 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 375 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,INC,Notype,yyattribute(1 - 2),NULL,NULL,NULL);
                  
#line 1101 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 379 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,DEC,Notype,yyattribute(1 - 2),NULL,NULL,NULL);
                  
#line 1116 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 383 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                  
#line 1131 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 388 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,MUL,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 1146 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 392 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,DIV,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 1161 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 396 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,OP_EXPR,MOD,Notype,yyattribute(1 - 3),yyattribute(3 - 3),NULL,NULL);
                  
#line 1176 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 400 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                  
#line 1191 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 405 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
                 
#line 1206 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 409 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                 
#line 1221 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 413 ".\\myparser.y"

				  (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,CONST_EXPR,yyattribute(1 - 1)->attr.val,Integer,NULL,NULL,NULL,NULL);
                 
#line 1236 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 417 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR,CONST_EXPR,yyattribute(1 - 1)->attr.valc,Char,NULL,NULL,NULL,NULL);
                 
#line 1251 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 421 ".\\myparser.y"

                   (*(YYSTYPE YYFAR*)yyvalptr)=my.createnode(EXPR, NOT_EXPR, NOT, Notype, yyattribute(2 - 2),NULL,NULL,NULL);
                 
#line 1266 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "INT", 257 },
		{ "CHAR", 258 },
		{ "VOID", 259 },
		{ "MAIN", 260 },
		{ "ID", 261 },
		{ "NUMBER", 262 },
		{ "CONSTCHAR", 263 },
		{ "IF", 264 },
		{ "ELSE", 265 },
		{ "FOR", 266 },
		{ "WHILE", 267 },
		{ "CIN", 268 },
		{ "COUT", 269 },
		{ "ASSIGN", 270 },
		{ "LT", 271 },
		{ "LE", 272 },
		{ "EQ", 273 },
		{ "GT", 274 },
		{ "GE", 275 },
		{ "NEQ", 276 },
		{ "PLUS", 277 },
		{ "MINUS", 278 },
		{ "MUL", 279 },
		{ "DIV", 280 },
		{ "MOD", 281 },
		{ "INC", 282 },
		{ "DEC", 283 },
		{ "NOT", 287 },
		{ "SHL", 288 },
		{ "SHR", 289 },
		{ "AND", 290 },
		{ "OR", 291 },
		{ "LBRACE", 293 },
		{ "RBRACE", 294 },
		{ "LPRACE", 295 },
		{ "RPRACE", 296 },
		{ "COMMA", 299 },
		{ "SIMICOLON", 300 },
		{ "SQUITO", 302 },
		{ "UMINUS", 306 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: MAIN LPRACE RPRACE comp_stmt",
		"program: MAIN LPRACE VOID RPRACE comp_stmt",
		"program: VOID MAIN LPRACE RPRACE comp_stmt",
		"program: VOID MAIN LPRACE VOID RPRACE comp_stmt",
		"comp_stmt: LBRACE stmt_list RBRACE",
		"comp_stmt: LBRACE RBRACE",
		"stmt_list: stmt_list stmt",
		"stmt_list: stmt",
		"stmt: var_dec",
		"stmt: exp_stmt",
		"stmt: if_stmt",
		"stmt: while_stmt",
		"stmt: for_stmt",
		"stmt: input_stmt",
		"stmt: output_stmt",
		"stmt: comp_stmt",
		"var_dec: type_spec idlist SIMICOLON",
		"type_spec: INT",
		"type_spec: CHAR",
		"idlist: idlist COMMA id",
		"idlist: idlist COMMA exp",
		"idlist: id",
		"idlist: exp",
		"id: ID",
		"if_stmt: IF LPRACE exp RPRACE stmt ELSE stmt",
		"if_stmt: IF LPRACE exp RPRACE stmt",
		"for_stmt: FOR LPRACE exp_stmt exp_stmt exp RPRACE stmt",
		"for_stmt: FOR LPRACE exp_stmt exp_stmt RPRACE stmt",
		"while_stmt: WHILE LPRACE exp RPRACE stmt",
		"input_stmt: CIN SHR exp input_child",
		"input_child: SHR exp input_child",
		"input_child: SIMICOLON",
		"output_stmt: COUT SHL exp output_child",
		"output_child: SHL exp output_child",
		"output_child: SIMICOLON",
		"exp_stmt: exp SIMICOLON",
		"exp_stmt: SIMICOLON",
		"exp: id ASSIGN exp",
		"exp: id ASSIGN SQUITO exp SQUITO",
		"exp: or_exp",
		"or_exp: or_exp OR and_exp",
		"or_exp: and_exp",
		"and_exp: and_exp AND shift_exp",
		"and_exp: shift_exp",
		"shift_exp: shift_exp SHL rel_exp",
		"shift_exp: shift_exp SHR rel_exp",
		"shift_exp: rel_exp",
		"rel_exp: rel_exp EQ simple_exp",
		"rel_exp: rel_exp LT simple_exp",
		"rel_exp: rel_exp GT simple_exp",
		"rel_exp: rel_exp LE simple_exp",
		"rel_exp: rel_exp GE simple_exp",
		"rel_exp: rel_exp NEQ simple_exp",
		"rel_exp: simple_exp",
		"simple_exp: simple_exp PLUS term",
		"simple_exp: simple_exp MINUS term",
		"simple_exp: MINUS simple_exp",
		"simple_exp: simple_exp INC",
		"simple_exp: simple_exp DEC",
		"simple_exp: term",
		"term: term MUL factor",
		"term: term DIV factor",
		"term: term MOD factor",
		"term: factor",
		"factor: LPRACE exp RPRACE",
		"factor: id",
		"factor: NUMBER",
		"factor: CONSTCHAR",
		"factor: NOT factor"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 1, 5, 1 },
		{ 1, 5, 2 },
		{ 1, 6, 3 },
		{ 2, 3, 4 },
		{ 2, 2, 5 },
		{ 3, 2, 6 },
		{ 3, 1, 7 },
		{ 4, 1, 8 },
		{ 4, 1, 9 },
		{ 4, 1, 10 },
		{ 4, 1, 11 },
		{ 4, 1, 12 },
		{ 4, 1, 13 },
		{ 4, 1, 14 },
		{ 4, 1, 15 },
		{ 5, 3, 16 },
		{ 6, 1, 17 },
		{ 6, 1, 18 },
		{ 7, 3, 19 },
		{ 7, 3, 20 },
		{ 7, 1, 21 },
		{ 7, 1, 22 },
		{ 8, 1, 23 },
		{ 9, 7, 24 },
		{ 9, 5, 25 },
		{ 10, 7, 26 },
		{ 10, 6, 27 },
		{ 11, 5, 28 },
		{ 12, 4, 29 },
		{ 13, 3, 30 },
		{ 13, 1, 31 },
		{ 14, 4, 32 },
		{ 15, 3, 33 },
		{ 15, 1, 34 },
		{ 16, 2, 35 },
		{ 16, 1, 36 },
		{ 17, 3, 37 },
		{ 17, 5, 38 },
		{ 17, 1, 39 },
		{ 18, 3, 40 },
		{ 18, 1, 41 },
		{ 19, 3, 42 },
		{ 19, 1, 43 },
		{ 20, 3, 44 },
		{ 20, 3, 45 },
		{ 20, 1, 46 },
		{ 21, 3, 47 },
		{ 21, 3, 48 },
		{ 21, 3, 49 },
		{ 21, 3, 50 },
		{ 21, 3, 51 },
		{ 21, 3, 52 },
		{ 21, 1, 53 },
		{ 22, 3, 54 },
		{ 22, 3, 55 },
		{ 22, 2, 56 },
		{ 22, 2, 57 },
		{ 22, 2, 58 },
		{ 22, 1, 59 },
		{ 23, 3, 60 },
		{ 23, 3, 61 },
		{ 23, 3, 62 },
		{ 23, 1, 63 },
		{ 24, 3, 64 },
		{ 24, 1, 65 },
		{ 24, 1, 66 },
		{ 24, 1, 67 },
		{ 24, 2, 68 }
	};
	yyreduction = reduction;

	yytokenaction_size = 122;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 132, YYAT_SHIFT, 17 },
		{ 132, YYAT_SHIFT, 18 },
		{ 6, YYAT_SHIFT, 9 },
		{ 117, YYAT_SHIFT, 19 },
		{ 117, YYAT_SHIFT, 20 },
		{ 117, YYAT_SHIFT, 21 },
		{ 5, YYAT_SHIFT, 7 },
		{ 132, YYAT_SHIFT, 22 },
		{ 125, YYAT_SHIFT, 132 },
		{ 132, YYAT_SHIFT, 23 },
		{ 132, YYAT_SHIFT, 24 },
		{ 132, YYAT_SHIFT, 25 },
		{ 132, YYAT_SHIFT, 26 },
		{ 99, YYAT_SHIFT, 72 },
		{ 99, YYAT_SHIFT, 73 },
		{ 120, YYAT_SHIFT, 84 },
		{ 128, YYAT_SHIFT, 117 },
		{ 82, YYAT_SHIFT, 84 },
		{ 99, YYAT_SHIFT, 74 },
		{ 99, YYAT_SHIFT, 75 },
		{ 117, YYAT_SHIFT, 27 },
		{ 93, YYAT_SHIFT, 66 },
		{ 93, YYAT_SHIFT, 67 },
		{ 93, YYAT_SHIFT, 68 },
		{ 93, YYAT_SHIFT, 69 },
		{ 93, YYAT_SHIFT, 70 },
		{ 93, YYAT_SHIFT, 71 },
		{ 127, YYAT_SHIFT, 114 },
		{ 128, YYAT_SHIFT, 118 },
		{ 117, YYAT_SHIFT, 28 },
		{ 92, YYAT_SHIFT, 66 },
		{ 92, YYAT_SHIFT, 67 },
		{ 92, YYAT_SHIFT, 68 },
		{ 92, YYAT_SHIFT, 69 },
		{ 92, YYAT_SHIFT, 70 },
		{ 92, YYAT_SHIFT, 71 },
		{ 132, YYAT_SHIFT, 12 },
		{ 117, YYAT_SHIFT, 30 },
		{ 127, YYAT_SHIFT, 115 },
		{ 6, YYAT_SHIFT, 10 },
		{ 101, YYAT_SHIFT, 76 },
		{ 101, YYAT_SHIFT, 77 },
		{ 101, YYAT_SHIFT, 78 },
		{ 5, YYAT_SHIFT, 8 },
		{ 120, YYAT_REDUCE, 20 },
		{ 120, YYAT_REDUCE, 20 },
		{ 82, YYAT_REDUCE, 22 },
		{ 82, YYAT_REDUCE, 22 },
		{ 39, YYAT_SHIFT, 66 },
		{ 39, YYAT_SHIFT, 67 },
		{ 39, YYAT_SHIFT, 68 },
		{ 39, YYAT_SHIFT, 69 },
		{ 39, YYAT_SHIFT, 70 },
		{ 39, YYAT_SHIFT, 71 },
		{ 98, YYAT_SHIFT, 72 },
		{ 98, YYAT_SHIFT, 73 },
		{ 97, YYAT_SHIFT, 72 },
		{ 97, YYAT_SHIFT, 73 },
		{ 123, YYAT_SHIFT, 130 },
		{ 98, YYAT_SHIFT, 74 },
		{ 98, YYAT_SHIFT, 75 },
		{ 97, YYAT_SHIFT, 74 },
		{ 97, YYAT_SHIFT, 75 },
		{ 96, YYAT_SHIFT, 72 },
		{ 96, YYAT_SHIFT, 73 },
		{ 95, YYAT_SHIFT, 72 },
		{ 95, YYAT_SHIFT, 73 },
		{ 122, YYAT_SHIFT, 129 },
		{ 96, YYAT_SHIFT, 74 },
		{ 96, YYAT_SHIFT, 75 },
		{ 95, YYAT_SHIFT, 74 },
		{ 95, YYAT_SHIFT, 75 },
		{ 94, YYAT_SHIFT, 72 },
		{ 94, YYAT_SHIFT, 73 },
		{ 40, YYAT_SHIFT, 72 },
		{ 40, YYAT_SHIFT, 73 },
		{ 112, YYAT_SHIFT, 124 },
		{ 94, YYAT_SHIFT, 74 },
		{ 94, YYAT_SHIFT, 75 },
		{ 40, YYAT_SHIFT, 74 },
		{ 40, YYAT_SHIFT, 75 },
		{ 100, YYAT_SHIFT, 76 },
		{ 100, YYAT_SHIFT, 77 },
		{ 100, YYAT_SHIFT, 78 },
		{ 41, YYAT_SHIFT, 76 },
		{ 41, YYAT_SHIFT, 77 },
		{ 41, YYAT_SHIFT, 78 },
		{ 105, YYAT_SHIFT, 64 },
		{ 105, YYAT_SHIFT, 65 },
		{ 81, YYAT_SHIFT, 107 },
		{ 81, YYAT_SHIFT, 108 },
		{ 58, YYAT_SHIFT, 74 },
		{ 58, YYAT_SHIFT, 75 },
		{ 38, YYAT_SHIFT, 64 },
		{ 38, YYAT_SHIFT, 65 },
		{ 0, YYAT_SHIFT, 1 },
		{ 0, YYAT_SHIFT, 2 },
		{ 106, YYAT_SHIFT, 79 },
		{ 88, YYAT_SHIFT, 113 },
		{ 87, YYAT_SHIFT, 31 },
		{ 86, YYAT_SHIFT, 111 },
		{ 84, YYAT_SHIFT, 109 },
		{ 78, YYAT_ERROR, 0 },
		{ 61, YYAT_SHIFT, 91 },
		{ 49, YYAT_SHIFT, 85 },
		{ 45, YYAT_SHIFT, 84 },
		{ 43, YYAT_SHIFT, 80 },
		{ 42, YYAT_SHIFT, 79 },
		{ 33, YYAT_SHIFT, 62 },
		{ 26, YYAT_SHIFT, 57 },
		{ 25, YYAT_SHIFT, 56 },
		{ 24, YYAT_SHIFT, 55 },
		{ 23, YYAT_SHIFT, 54 },
		{ 22, YYAT_SHIFT, 53 },
		{ 14, YYAT_SHIFT, 12 },
		{ 12, YYAT_SHIFT, 29 },
		{ 9, YYAT_SHIFT, 14 },
		{ 7, YYAT_SHIFT, 11 },
		{ 4, YYAT_SHIFT, 6 },
		{ 3, YYAT_ACCEPT, 0 },
		{ 2, YYAT_SHIFT, 5 },
		{ 1, YYAT_SHIFT, 4 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -164, 1, YYAT_ERROR, 0 },
		{ -139, 1, YYAT_ERROR, 0 },
		{ -175, 1, YYAT_ERROR, 0 },
		{ 119, 1, YYAT_ERROR, 0 },
		{ -177, 1, YYAT_ERROR, 0 },
		{ -253, 1, YYAT_ERROR, 0 },
		{ -257, 1, YYAT_ERROR, 0 },
		{ -179, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 14 },
		{ -180, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 14 },
		{ 0, 0, YYAT_DEFAULT, 14 },
		{ -179, 1, YYAT_DEFAULT, 132 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -179, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ -183, 1, YYAT_ERROR, 0 },
		{ -184, 1, YYAT_ERROR, 0 },
		{ -179, 1, YYAT_ERROR, 0 },
		{ -179, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 78 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -186, 1, YYAT_DEFAULT, 132 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ -195, 1, YYAT_REDUCE, 44 },
		{ -223, 1, YYAT_REDUCE, 47 },
		{ -203, 1, YYAT_REDUCE, 54 },
		{ -195, 1, YYAT_REDUCE, 60 },
		{ -183, 1, YYAT_REDUCE, 42 },
		{ -185, 1, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ -165, 1, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ -196, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 87 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ -191, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ -193, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 78 },
		{ 0, 0, YYAT_DEFAULT, 78 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 78 },
		{ 0, 0, YYAT_DEFAULT, 78 },
		{ -176, 1, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ -210, 1, YYAT_ERROR, 0 },
		{ -253, 1, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ -201, 1, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ -196, 1, YYAT_ERROR, 0 },
		{ -201, 1, YYAT_DEFAULT, 117 },
		{ -198, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 127 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ -241, 1, YYAT_REDUCE, 45 },
		{ -250, 1, YYAT_REDUCE, 46 },
		{ -205, 1, YYAT_REDUCE, 49 },
		{ -212, 1, YYAT_REDUCE, 51 },
		{ -214, 1, YYAT_REDUCE, 48 },
		{ -221, 1, YYAT_REDUCE, 50 },
		{ -223, 1, YYAT_REDUCE, 52 },
		{ -264, 1, YYAT_REDUCE, 53 },
		{ -198, 1, YYAT_REDUCE, 55 },
		{ -239, 1, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ -201, 1, YYAT_REDUCE, 43 },
		{ -193, 1, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_DEFAULT, 132 },
		{ -220, 1, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_DEFAULT, 132 },
		{ 0, 0, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ -258, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ -255, 1, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ -235, 1, YYAT_ERROR, 0 },
		{ -207, 1, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_DEFAULT, 132 },
		{ -288, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -262, 1, YYAT_ERROR, 0 },
		{ -272, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_DEFAULT, 132 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -257, 1, YYAT_DEFAULT, 87 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 27 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 75;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 132, 36 },
		{ 130, 135 },
		{ 132, 136 },
		{ 132, 34 },
		{ 132, 44 },
		{ 78, 59 },
		{ 117, 45 },
		{ 132, 46 },
		{ 132, 50 },
		{ 132, 48 },
		{ 132, 47 },
		{ 128, 134 },
		{ 132, 51 },
		{ 80, 59 },
		{ 132, 35 },
		{ 117, 128 },
		{ 117, 43 },
		{ 117, 42 },
		{ 117, 38 },
		{ 117, 39 },
		{ 117, 40 },
		{ 78, 104 },
		{ 80, -1 },
		{ 80, -1 },
		{ 80, 106 },
		{ 44, 81 },
		{ 44, 82 },
		{ 107, 120 },
		{ 87, 112 },
		{ 87, 49 },
		{ 79, -1 },
		{ 79, 105 },
		{ 73, 101 },
		{ 73, 37 },
		{ 127, 133 },
		{ 44, 83 },
		{ 107, 121 },
		{ 71, 99 },
		{ 71, 41 },
		{ 65, -1 },
		{ 65, 93 },
		{ 12, 33 },
		{ 12, 32 },
		{ 124, 131 },
		{ 114, 127 },
		{ 113, 126 },
		{ 112, 125 },
		{ 111, 123 },
		{ 109, 122 },
		{ 90, 119 },
		{ 89, 116 },
		{ 84, 110 },
		{ 77, 103 },
		{ 76, 102 },
		{ 72, 100 },
		{ 70, 98 },
		{ 69, 97 },
		{ 68, 96 },
		{ 67, 95 },
		{ 66, 94 },
		{ 64, 92 },
		{ 57, 90 },
		{ 56, 89 },
		{ 55, 88 },
		{ 54, 87 },
		{ 53, 86 },
		{ 33, 63 },
		{ 30, 61 },
		{ 28, 60 },
		{ 27, 58 },
		{ 14, 52 },
		{ 11, 16 },
		{ 10, 15 },
		{ 8, 13 },
		{ 0, 3 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 73, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 71, -1 },
		{ 0, -1 },
		{ 70, -1 },
		{ 69, -1 },
		{ 38, 132 },
		{ 0, -1 },
		{ 68, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 47, 71 },
		{ 44, 78 },
		{ 0, -1 },
		{ 50, 117 },
		{ 0, -1 },
		{ 0, -1 },
		{ 62, 132 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 18, 117 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 48, 117 },
		{ 48, 87 },
		{ 46, 117 },
		{ 45, 117 },
		{ 44, 117 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 65 },
		{ 19, 79 },
		{ 37, 71 },
		{ 36, 71 },
		{ 35, 71 },
		{ 34, 71 },
		{ 33, 71 },
		{ 15, 73 },
		{ 31, 73 },
		{ 9, 78 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 78 },
		{ 28, 78 },
		{ -3, -1 },
		{ 11, 80 },
		{ 5, 117 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 34, 117 },
		{ 0, -1 },
		{ 0, -1 },
		{ 12, 117 },
		{ 0, -1 },
		{ 37, -1 },
		{ 34, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 19, 117 },
		{ 0, -1 },
		{ 31, 117 },
		{ 0, -1 },
		{ 43, 132 },
		{ 29, 117 },
		{ 41, 132 },
		{ 27, 117 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 71 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 132 },
		{ 0, -1 },
		{ 0, -1 },
		{ 21, -1 },
		{ -4, -1 },
		{ 0, -1 },
		{ -3, 132 },
		{ 0, -1 },
		{ -2, 87 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 426 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	return n;
}


