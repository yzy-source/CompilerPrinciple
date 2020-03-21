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
# code2_2.v
# YACC verbose file generated from code2_2.y.
# 
# Date: 11/01/16
# Time: 21:53:18
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
    8       | SUB expr
    9       | NUMBER


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
	NUMBER  shift 4

	expr  goto 5


state 2
	lines : lines '\n' .  (2)

	.  reduce 2


state 3
	expr : SUB . expr

	SUB  shift 3
	NUMBER  shift 4

	expr  goto 6


state 4
	expr : NUMBER .  (9)

	.  reduce 9


state 5
	lines : lines expr . '\n'
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	'\n'  shift 7
	ADD  shift 8
	SUB  shift 9
	MUL  shift 10
	DIV  shift 11


state 6
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : SUB expr .  (8)

	.  reduce 8


state 7
	lines : lines expr '\n' .  (1)

	.  reduce 1


state 8
	expr : expr ADD . expr

	SUB  shift 3
	NUMBER  shift 4

	expr  goto 12


state 9
	expr : expr SUB . expr

	SUB  shift 3
	NUMBER  shift 4

	expr  goto 13


state 10
	expr : expr MUL . expr

	SUB  shift 3
	NUMBER  shift 4

	expr  goto 14


state 11
	expr : expr DIV . expr

	SUB  shift 3
	NUMBER  shift 4

	expr  goto 15


state 12
	expr : expr ADD expr .  (4)
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 10
	DIV  shift 11
	.  reduce 4


state 13
	expr : expr . ADD expr
	expr : expr SUB expr .  (5)
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 10
	DIV  shift 11
	.  reduce 5


state 14
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr MUL expr .  (6)
	expr : expr . MUL expr
	expr : expr . DIV expr

	.  reduce 6


state 15
	expr : expr . ADD expr
	expr : expr . SUB expr
	expr : expr . MUL expr
	expr : expr DIV expr .  (7)
	expr : expr . DIV expr

	.  reduce 7


##############################################################################
# Summary
##############################################################################

9 token(s), 3 nonterminal(s)
10 grammar rule(s), 16 state(s)


##############################################################################
# End of File
##############################################################################
