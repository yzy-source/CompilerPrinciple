#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 15 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# code2_3.v
# YACC verbose file generated from code2_3.y.
# 
# Date: 11/01/16
# Time: 21:54:52
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : lines $end

    1  lines : lines expr '\n'
    2        | lines '\n'
    3        |

    4  expr : expr ADD expr
    5       | expr SUB expr
    6       | expr MUL expr
    7       | expr DIV expr
    8       | L_BRACKET expr R_BRACKET
    9       | SUB expr
   10       | NUMBER


##############################################################################
# States
##############################################################################

state 0
	$accept : . lines $end
	lines : .  (3)

	.  reduce 3

	lines  goto 1


state 1
	$accept : lines . $end  (0)
	lines : lines . expr '\n'
	lines : lines . '\n'

	$end  accept
	'\n'  shift 2
	SUB  shift 3
	L_BRACKET  shift 4
	NUMBER  shift 5

	expr  goto 6


state 2
	lines : lines '\n' .  (2)

	.  reduce 2


state 3
	expr : SUB . expr

	SUB  shift 3
	L_BRACKET  shift 4
	NUMBER  shift 5

	expr  goto 7


state 4
	expr : L_BRACKET . expr R_BRACKET

	SUB  shift 3
	L_BRACKET  shift 4
	NUMBER  shift 5

	expr  goto 8


state 5
	expr : NUMBER .  (10)

	.  reduce 10


state 6
	lines : lines expr . '\n'
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	'\n'  shift 9
	ADD  shift 10
	SUB  shift 11
	MUL  shift 12
	DIV  shift 13


state 7
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : SUB expr .  (9)

	.  reduce 9


state 8
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : L_BRACKET expr . R_BRACKET

	ADD  shift 10
	SUB  shift 11
	MUL  shift 12
	DIV  shift 13
	R_BRACKET  shift 14


state 9
	lines : lines expr '\n' .  (1)

	.  reduce 1


state 10
	expr : expr ADD . expr

	SUB  shift 3
	L_BRACKET  shift 4
	NUMBER  shift 5

	expr  goto 15


state 11
	expr : expr SUB . expr

	SUB  shift 3
	L_BRACKET  shift 4
	NUMBER  shift 5

	expr  goto 16


state 12
	expr : expr MUL . expr

	SUB  shift 3
	L_BRACKET  shift 4
	NUMBER  shift 5

	expr  goto 17


state 13
	expr : expr DIV . expr

	SUB  shift 3
	L_BRACKET  shift 4
	NUMBER  shift 5

	expr  goto 18


state 14
	expr : L_BRACKET expr R_BRACKET .  (8)

	.  reduce 8


state 15
	expr : expr ADD expr .  (4)
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 12
	DIV  shift 13
	.  reduce 4


state 16
	expr : expr . ADD expr
	expr : expr SUB expr .  (5)
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 12
	DIV  shift 13
	.  reduce 5


state 17
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr MUL expr .  (6)
	expr : expr . MUL expr
	expr : expr . DIV expr

	.  reduce 6


state 18
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr DIV expr .  (7)
	expr : expr . DIV expr

	.  reduce 7


##############################################################################
# Summary
##############################################################################

11 token(s), 3 nonterminal(s)
11 grammar rule(s), 19 state(s)


##############################################################################
# End of File
##############################################################################
