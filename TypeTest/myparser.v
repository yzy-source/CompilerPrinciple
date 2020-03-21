#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 49 of your 30 day trial period.
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
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 12/05/16
# Time: 17:45:18
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : MAIN LPRACE RPRACE comp_stmt
    2          | MAIN LPRACE VOID RPRACE comp_stmt
    3          | VOID MAIN LPRACE RPRACE comp_stmt
    4          | VOID MAIN LPRACE VOID RPRACE comp_stmt

    5  comp_stmt : LBRACE stmt_list RBRACE
    6            | LBRACE RBRACE

    7  stmt_list : stmt_list stmt
    8            | stmt

    9  stmt : var_dec
   10       | exp_stmt
   11       | if_stmt
   12       | while_stmt
   13       | for_stmt
   14       | input_stmt
   15       | output_stmt
   16       | comp_stmt

   17  var_dec : type_spec idlist SIMICOLON

   18  type_spec : INT
   19            | CHAR

   20  idlist : idlist COMMA id
   21         | idlist COMMA exp
   22         | id
   23         | exp

   24  id : ID

   25  if_stmt : IF LPRACE exp RPRACE stmt ELSE stmt
   26          | IF LPRACE exp RPRACE stmt

   27  for_stmt : FOR LPRACE exp_stmt exp_stmt exp RPRACE stmt
   28           | FOR LPRACE exp_stmt exp_stmt RPRACE stmt

   29  while_stmt : WHILE LPRACE exp RPRACE stmt

   30  input_stmt : CIN SHR exp input_child

   31  input_child : SHR exp input_child
   32              | SIMICOLON

   33  output_stmt : COUT SHL exp output_child

   34  output_child : SHL exp output_child
   35               | SIMICOLON

   36  exp_stmt : exp SIMICOLON
   37           | SIMICOLON

   38  exp : id ASSIGN exp
   39      | id ASSIGN SQUITO exp SQUITO
   40      | or_exp

   41  or_exp : or_exp OR and_exp
   42         | and_exp

   43  and_exp : and_exp AND shift_exp
   44          | shift_exp

   45  shift_exp : shift_exp SHL rel_exp
   46            | shift_exp SHR rel_exp
   47            | rel_exp

   48  rel_exp : rel_exp EQ simple_exp
   49          | rel_exp LT simple_exp
   50          | rel_exp GT simple_exp
   51          | rel_exp LE simple_exp
   52          | rel_exp GE simple_exp
   53          | rel_exp NEQ simple_exp
   54          | simple_exp

   55  simple_exp : simple_exp PLUS term
   56             | simple_exp MINUS term
   57             | MINUS simple_exp
   58             | simple_exp INC
   59             | simple_exp DEC
   60             | term

   61  term : term MUL factor
   62       | term DIV factor
   63       | term MOD factor
   64       | factor

   65  factor : LPRACE exp RPRACE
   66         | id
   67         | NUMBER
   68         | CONSTCHAR
   69         | NOT factor


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	VOID  shift 1
	MAIN  shift 2

	program  goto 3


state 1
	program : VOID . MAIN LPRACE RPRACE comp_stmt
	program : VOID . MAIN LPRACE VOID RPRACE comp_stmt

	MAIN  shift 4


state 2
	program : MAIN . LPRACE RPRACE comp_stmt
	program : MAIN . LPRACE VOID RPRACE comp_stmt

	LPRACE  shift 5


state 3
	$accept : program . $end  (0)

	$end  accept


state 4
	program : VOID MAIN . LPRACE RPRACE comp_stmt
	program : VOID MAIN . LPRACE VOID RPRACE comp_stmt

	LPRACE  shift 6


state 5
	program : MAIN LPRACE . RPRACE comp_stmt
	program : MAIN LPRACE . VOID RPRACE comp_stmt

	VOID  shift 7
	RPRACE  shift 8


state 6
	program : VOID MAIN LPRACE . RPRACE comp_stmt
	program : VOID MAIN LPRACE . VOID RPRACE comp_stmt

	VOID  shift 9
	RPRACE  shift 10


state 7
	program : MAIN LPRACE VOID . RPRACE comp_stmt

	RPRACE  shift 11


state 8
	program : MAIN LPRACE RPRACE . comp_stmt

	LBRACE  shift 12

	comp_stmt  goto 13


state 9
	program : VOID MAIN LPRACE VOID . RPRACE comp_stmt

	RPRACE  shift 14


state 10
	program : VOID MAIN LPRACE RPRACE . comp_stmt

	LBRACE  shift 12

	comp_stmt  goto 15


state 11
	program : MAIN LPRACE VOID RPRACE . comp_stmt

	LBRACE  shift 12

	comp_stmt  goto 16


state 12
	comp_stmt : LBRACE . stmt_list RBRACE
	comp_stmt : LBRACE . RBRACE

	INT  shift 17
	CHAR  shift 18
	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	IF  shift 22
	FOR  shift 23
	WHILE  shift 24
	CIN  shift 25
	COUT  shift 26
	MINUS  shift 27
	NOT  shift 28
	LBRACE  shift 12
	RBRACE  shift 29
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	if_stmt  goto 39
	exp  goto 40
	type_spec  goto 41
	id  goto 42
	input_stmt  goto 43
	while_stmt  goto 44
	for_stmt  goto 45
	output_stmt  goto 46
	comp_stmt  goto 47
	stmt_list  goto 48
	stmt  goto 49
	var_dec  goto 50
	exp_stmt  goto 51


state 13
	program : MAIN LPRACE RPRACE comp_stmt .  (1)

	.  reduce 1


state 14
	program : VOID MAIN LPRACE VOID RPRACE . comp_stmt

	LBRACE  shift 12

	comp_stmt  goto 52


state 15
	program : VOID MAIN LPRACE RPRACE comp_stmt .  (3)

	.  reduce 3


state 16
	program : MAIN LPRACE VOID RPRACE comp_stmt .  (2)

	.  reduce 2


state 17
	type_spec : INT .  (18)

	.  reduce 18


state 18
	type_spec : CHAR .  (19)

	.  reduce 19


state 19
	id : ID .  (24)

	.  reduce 24


state 20
	factor : NUMBER .  (67)

	.  reduce 67


state 21
	factor : CONSTCHAR .  (68)

	.  reduce 68


state 22
	if_stmt : IF . LPRACE exp RPRACE stmt ELSE stmt
	if_stmt : IF . LPRACE exp RPRACE stmt

	LPRACE  shift 53


state 23
	for_stmt : FOR . LPRACE exp_stmt exp_stmt RPRACE stmt
	for_stmt : FOR . LPRACE exp_stmt exp_stmt exp RPRACE stmt

	LPRACE  shift 54


state 24
	while_stmt : WHILE . LPRACE exp RPRACE stmt

	LPRACE  shift 55


state 25
	input_stmt : CIN . SHR exp input_child

	SHR  shift 56


state 26
	output_stmt : COUT . SHL exp output_child

	SHL  shift 57


state 27
	simple_exp : MINUS . simple_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 58
	term  goto 36
	factor  goto 37
	id  goto 59


state 28
	factor : NOT . factor

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	NOT  shift 28
	LPRACE  shift 30

	factor  goto 60
	id  goto 59


state 29
	comp_stmt : LBRACE RBRACE .  (6)

	.  reduce 6


state 30
	factor : LPRACE . exp RPRACE

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 61
	id  goto 42


state 31
	exp_stmt : SIMICOLON .  (37)

	.  reduce 37


32: shift-reduce conflict (shift 62, reduce 44) on SHL
32: shift-reduce conflict (shift 63, reduce 44) on SHR
state 32
	shift_exp : shift_exp . SHL rel_exp
	and_exp : shift_exp .  (44)
	shift_exp : shift_exp . SHR rel_exp

	SHL  shift 62
	SHR  shift 63
	.  reduce 44


state 33
	rel_exp : simple_exp .  (54)
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . INC
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DEC

	PLUS  shift 64
	MINUS  shift 65
	INC  shift 66
	DEC  shift 67
	.  reduce 54


state 34
	and_exp : and_exp . AND shift_exp
	or_exp : and_exp .  (42)

	AND  shift 68
	.  reduce 42


state 35
	exp : or_exp .  (40)
	or_exp : or_exp . OR and_exp

	OR  shift 69
	.  reduce 40


state 36
	simple_exp : term .  (60)
	term : term . MUL factor
	term : term . MOD factor
	term : term . DIV factor

	MUL  shift 70
	DIV  shift 71
	MOD  shift 72
	.  reduce 60


state 37
	term : factor .  (64)

	.  reduce 64


state 38
	rel_exp : rel_exp . NEQ simple_exp
	rel_exp : rel_exp . EQ simple_exp
	rel_exp : rel_exp . LT simple_exp
	rel_exp : rel_exp . LE simple_exp
	shift_exp : rel_exp .  (47)
	rel_exp : rel_exp . GT simple_exp
	rel_exp : rel_exp . GE simple_exp

	LT  shift 73
	LE  shift 74
	EQ  shift 75
	GT  shift 76
	GE  shift 77
	NEQ  shift 78
	.  reduce 47


state 39
	stmt : if_stmt .  (11)

	.  reduce 11


state 40
	exp_stmt : exp . SIMICOLON

	SIMICOLON  shift 79


state 41
	var_dec : type_spec . idlist SIMICOLON

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	idlist  goto 80
	exp  goto 81
	id  goto 82


state 42
	exp : id . ASSIGN exp
	exp : id . ASSIGN SQUITO exp SQUITO
	factor : id .  (66)

	ASSIGN  shift 83
	.  reduce 66


state 43
	stmt : input_stmt .  (14)

	.  reduce 14


state 44
	stmt : while_stmt .  (12)

	.  reduce 12


state 45
	stmt : for_stmt .  (13)

	.  reduce 13


state 46
	stmt : output_stmt .  (15)

	.  reduce 15


state 47
	stmt : comp_stmt .  (16)

	.  reduce 16


state 48
	comp_stmt : LBRACE stmt_list . RBRACE
	stmt_list : stmt_list . stmt

	INT  shift 17
	CHAR  shift 18
	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	IF  shift 22
	FOR  shift 23
	WHILE  shift 24
	CIN  shift 25
	COUT  shift 26
	MINUS  shift 27
	NOT  shift 28
	LBRACE  shift 12
	RBRACE  shift 84
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	if_stmt  goto 39
	exp  goto 40
	type_spec  goto 41
	id  goto 42
	input_stmt  goto 43
	while_stmt  goto 44
	for_stmt  goto 45
	output_stmt  goto 46
	comp_stmt  goto 47
	stmt  goto 85
	var_dec  goto 50
	exp_stmt  goto 51


state 49
	stmt_list : stmt .  (8)

	.  reduce 8


state 50
	stmt : var_dec .  (9)

	.  reduce 9


state 51
	stmt : exp_stmt .  (10)

	.  reduce 10


state 52
	program : VOID MAIN LPRACE VOID RPRACE comp_stmt .  (4)

	.  reduce 4


state 53
	if_stmt : IF LPRACE . exp RPRACE stmt ELSE stmt
	if_stmt : IF LPRACE . exp RPRACE stmt

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 86
	id  goto 42


state 54
	for_stmt : FOR LPRACE . exp_stmt exp_stmt RPRACE stmt
	for_stmt : FOR LPRACE . exp_stmt exp_stmt exp RPRACE stmt

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 40
	id  goto 42
	exp_stmt  goto 87


state 55
	while_stmt : WHILE LPRACE . exp RPRACE stmt

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 88
	id  goto 42


state 56
	input_stmt : CIN SHR . exp input_child

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 89
	id  goto 42


state 57
	output_stmt : COUT SHL . exp output_child

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 90
	id  goto 42


58: shift-reduce conflict (shift 66, reduce 57) on INC
58: shift-reduce conflict (shift 67, reduce 57) on DEC
state 58
	simple_exp : MINUS simple_exp .  (57)
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . INC
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DEC

	INC  shift 66
	DEC  shift 67
	.  reduce 57


state 59
	factor : id .  (66)

	.  reduce 66


state 60
	factor : NOT factor .  (69)

	.  reduce 69


state 61
	factor : LPRACE exp . RPRACE

	RPRACE  shift 91


state 62
	shift_exp : shift_exp SHL . rel_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 33
	term  goto 36
	factor  goto 37
	rel_exp  goto 92
	id  goto 59


state 63
	shift_exp : shift_exp SHR . rel_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 33
	term  goto 36
	factor  goto 37
	rel_exp  goto 93
	id  goto 59


state 64
	simple_exp : simple_exp PLUS . term

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	NOT  shift 28
	LPRACE  shift 30

	term  goto 94
	factor  goto 37
	id  goto 59


state 65
	simple_exp : simple_exp MINUS . term

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	NOT  shift 28
	LPRACE  shift 30

	term  goto 95
	factor  goto 37
	id  goto 59


state 66
	simple_exp : simple_exp INC .  (58)

	.  reduce 58


state 67
	simple_exp : simple_exp DEC .  (59)

	.  reduce 59


state 68
	and_exp : and_exp AND . shift_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 96
	simple_exp  goto 33
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	id  goto 59


state 69
	or_exp : or_exp OR . and_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 97
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	id  goto 59


state 70
	term : term MUL . factor

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	NOT  shift 28
	LPRACE  shift 30

	factor  goto 98
	id  goto 59


state 71
	term : term DIV . factor

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	NOT  shift 28
	LPRACE  shift 30

	factor  goto 99
	id  goto 59


state 72
	term : term MOD . factor

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	NOT  shift 28
	LPRACE  shift 30

	factor  goto 100
	id  goto 59


state 73
	rel_exp : rel_exp LT . simple_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 101
	term  goto 36
	factor  goto 37
	id  goto 59


state 74
	rel_exp : rel_exp LE . simple_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 102
	term  goto 36
	factor  goto 37
	id  goto 59


state 75
	rel_exp : rel_exp EQ . simple_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 103
	term  goto 36
	factor  goto 37
	id  goto 59


state 76
	rel_exp : rel_exp GT . simple_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 104
	term  goto 36
	factor  goto 37
	id  goto 59


state 77
	rel_exp : rel_exp GE . simple_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 105
	term  goto 36
	factor  goto 37
	id  goto 59


state 78
	rel_exp : rel_exp NEQ . simple_exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	simple_exp  goto 106
	term  goto 36
	factor  goto 37
	id  goto 59


state 79
	exp_stmt : exp SIMICOLON .  (36)

	.  reduce 36


state 80
	var_dec : type_spec idlist . SIMICOLON
	idlist : idlist . COMMA id
	idlist : idlist . COMMA exp

	COMMA  shift 107
	SIMICOLON  shift 108


state 81
	idlist : exp .  (23)

	.  reduce 23


82: reduce-reduce conflict (reduce 22, reduce 66) on COMMA
82: reduce-reduce conflict (reduce 22, reduce 66) on SIMICOLON
state 82
	exp : id . ASSIGN exp
	exp : id . ASSIGN SQUITO exp SQUITO
	factor : id .  (66)
	idlist : id .  (22)

	ASSIGN  shift 83
	COMMA  reduce 22
	SIMICOLON  reduce 22
	.  reduce 66


state 83
	exp : id ASSIGN . exp
	exp : id ASSIGN . SQUITO exp SQUITO

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30
	SQUITO  shift 109

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 110
	id  goto 42


state 84
	comp_stmt : LBRACE stmt_list RBRACE .  (5)

	.  reduce 5


state 85
	stmt_list : stmt_list stmt .  (7)

	.  reduce 7


state 86
	if_stmt : IF LPRACE exp . RPRACE stmt ELSE stmt
	if_stmt : IF LPRACE exp . RPRACE stmt

	RPRACE  shift 111


state 87
	for_stmt : FOR LPRACE exp_stmt . exp_stmt RPRACE stmt
	for_stmt : FOR LPRACE exp_stmt . exp_stmt exp RPRACE stmt

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 40
	id  goto 42
	exp_stmt  goto 112


state 88
	while_stmt : WHILE LPRACE exp . RPRACE stmt

	RPRACE  shift 113


state 89
	input_stmt : CIN SHR exp . input_child

	SHR  shift 114
	SIMICOLON  shift 115

	input_child  goto 116


state 90
	output_stmt : COUT SHL exp . output_child

	SHL  shift 117
	SIMICOLON  shift 118

	output_child  goto 119


state 91
	factor : LPRACE exp RPRACE .  (65)

	.  reduce 65


state 92
	shift_exp : shift_exp SHL rel_exp .  (45)
	rel_exp : rel_exp . NEQ simple_exp
	rel_exp : rel_exp . EQ simple_exp
	rel_exp : rel_exp . LT simple_exp
	rel_exp : rel_exp . LE simple_exp
	rel_exp : rel_exp . GT simple_exp
	rel_exp : rel_exp . GE simple_exp

	LT  shift 73
	LE  shift 74
	EQ  shift 75
	GT  shift 76
	GE  shift 77
	NEQ  shift 78
	.  reduce 45


state 93
	rel_exp : rel_exp . NEQ simple_exp
	rel_exp : rel_exp . EQ simple_exp
	rel_exp : rel_exp . LT simple_exp
	rel_exp : rel_exp . LE simple_exp
	rel_exp : rel_exp . GT simple_exp
	rel_exp : rel_exp . GE simple_exp
	shift_exp : shift_exp SHR rel_exp .  (46)

	LT  shift 73
	LE  shift 74
	EQ  shift 75
	GT  shift 76
	GE  shift 77
	NEQ  shift 78
	.  reduce 46


state 94
	simple_exp : simple_exp PLUS term .  (55)
	term : term . MUL factor
	term : term . MOD factor
	term : term . DIV factor

	MUL  shift 70
	DIV  shift 71
	MOD  shift 72
	.  reduce 55


state 95
	simple_exp : simple_exp MINUS term .  (56)
	term : term . MUL factor
	term : term . MOD factor
	term : term . DIV factor

	MUL  shift 70
	DIV  shift 71
	MOD  shift 72
	.  reduce 56


state 96
	shift_exp : shift_exp . SHL rel_exp
	and_exp : and_exp AND shift_exp .  (43)
	shift_exp : shift_exp . SHR rel_exp

	SHL  shift 62
	SHR  shift 63
	.  reduce 43


state 97
	and_exp : and_exp . AND shift_exp
	or_exp : or_exp OR and_exp .  (41)

	AND  shift 68
	.  reduce 41


state 98
	term : term MUL factor .  (61)

	.  reduce 61


state 99
	term : term DIV factor .  (62)

	.  reduce 62


state 100
	term : term MOD factor .  (63)

	.  reduce 63


state 101
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . INC
	rel_exp : rel_exp LT simple_exp .  (49)
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DEC

	PLUS  shift 64
	MINUS  shift 65
	INC  shift 66
	DEC  shift 67
	.  reduce 49


state 102
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . INC
	rel_exp : rel_exp LE simple_exp .  (51)
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DEC

	PLUS  shift 64
	MINUS  shift 65
	INC  shift 66
	DEC  shift 67
	.  reduce 51


state 103
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . INC
	rel_exp : rel_exp EQ simple_exp .  (48)
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DEC

	PLUS  shift 64
	MINUS  shift 65
	INC  shift 66
	DEC  shift 67
	.  reduce 48


state 104
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . INC
	rel_exp : rel_exp GT simple_exp .  (50)
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DEC

	PLUS  shift 64
	MINUS  shift 65
	INC  shift 66
	DEC  shift 67
	.  reduce 50


state 105
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . INC
	rel_exp : rel_exp GE simple_exp .  (52)
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DEC

	PLUS  shift 64
	MINUS  shift 65
	INC  shift 66
	DEC  shift 67
	.  reduce 52


state 106
	rel_exp : rel_exp NEQ simple_exp .  (53)
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . INC
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . DEC

	PLUS  shift 64
	MINUS  shift 65
	INC  shift 66
	DEC  shift 67
	.  reduce 53


state 107
	idlist : idlist COMMA . id
	idlist : idlist COMMA . exp

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 120
	id  goto 121


state 108
	var_dec : type_spec idlist SIMICOLON .  (17)

	.  reduce 17


state 109
	exp : id ASSIGN SQUITO . exp SQUITO

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 122
	id  goto 42


state 110
	exp : id ASSIGN exp .  (38)

	.  reduce 38


state 111
	if_stmt : IF LPRACE exp RPRACE . stmt ELSE stmt
	if_stmt : IF LPRACE exp RPRACE . stmt

	INT  shift 17
	CHAR  shift 18
	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	IF  shift 22
	FOR  shift 23
	WHILE  shift 24
	CIN  shift 25
	COUT  shift 26
	MINUS  shift 27
	NOT  shift 28
	LBRACE  shift 12
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	if_stmt  goto 39
	exp  goto 40
	type_spec  goto 41
	id  goto 42
	input_stmt  goto 43
	while_stmt  goto 44
	for_stmt  goto 45
	output_stmt  goto 46
	comp_stmt  goto 47
	stmt  goto 123
	var_dec  goto 50
	exp_stmt  goto 51


state 112
	for_stmt : FOR LPRACE exp_stmt exp_stmt . RPRACE stmt
	for_stmt : FOR LPRACE exp_stmt exp_stmt . exp RPRACE stmt

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30
	RPRACE  shift 124

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 125
	id  goto 42


state 113
	while_stmt : WHILE LPRACE exp RPRACE . stmt

	INT  shift 17
	CHAR  shift 18
	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	IF  shift 22
	FOR  shift 23
	WHILE  shift 24
	CIN  shift 25
	COUT  shift 26
	MINUS  shift 27
	NOT  shift 28
	LBRACE  shift 12
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	if_stmt  goto 39
	exp  goto 40
	type_spec  goto 41
	id  goto 42
	input_stmt  goto 43
	while_stmt  goto 44
	for_stmt  goto 45
	output_stmt  goto 46
	comp_stmt  goto 47
	stmt  goto 126
	var_dec  goto 50
	exp_stmt  goto 51


state 114
	input_child : SHR . exp input_child

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 127
	id  goto 42


state 115
	input_child : SIMICOLON .  (32)

	.  reduce 32


state 116
	input_stmt : CIN SHR exp input_child .  (30)

	.  reduce 30


state 117
	output_child : SHL . exp output_child

	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	MINUS  shift 27
	NOT  shift 28
	LPRACE  shift 30

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	exp  goto 128
	id  goto 42


state 118
	output_child : SIMICOLON .  (35)

	.  reduce 35


state 119
	output_stmt : COUT SHL exp output_child .  (33)

	.  reduce 33


state 120
	idlist : idlist COMMA exp .  (21)

	.  reduce 21


121: reduce-reduce conflict (reduce 20, reduce 66) on COMMA
121: reduce-reduce conflict (reduce 20, reduce 66) on SIMICOLON
state 121
	exp : id . ASSIGN exp
	exp : id . ASSIGN SQUITO exp SQUITO
	factor : id .  (66)
	idlist : idlist COMMA id .  (20)

	ASSIGN  shift 83
	COMMA  reduce 20
	SIMICOLON  reduce 20
	.  reduce 66


state 122
	exp : id ASSIGN SQUITO exp . SQUITO

	SQUITO  shift 129


123: shift-reduce conflict (shift 130, reduce 26) on ELSE
state 123
	if_stmt : IF LPRACE exp RPRACE stmt . ELSE stmt
	if_stmt : IF LPRACE exp RPRACE stmt .  (26)

	ELSE  shift 130
	.  reduce 26


state 124
	for_stmt : FOR LPRACE exp_stmt exp_stmt RPRACE . stmt

	INT  shift 17
	CHAR  shift 18
	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	IF  shift 22
	FOR  shift 23
	WHILE  shift 24
	CIN  shift 25
	COUT  shift 26
	MINUS  shift 27
	NOT  shift 28
	LBRACE  shift 12
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	if_stmt  goto 39
	exp  goto 40
	type_spec  goto 41
	id  goto 42
	input_stmt  goto 43
	while_stmt  goto 44
	for_stmt  goto 45
	output_stmt  goto 46
	comp_stmt  goto 47
	stmt  goto 131
	var_dec  goto 50
	exp_stmt  goto 51


state 125
	for_stmt : FOR LPRACE exp_stmt exp_stmt exp . RPRACE stmt

	RPRACE  shift 132


state 126
	while_stmt : WHILE LPRACE exp RPRACE stmt .  (29)

	.  reduce 29


state 127
	input_child : SHR exp . input_child

	SHR  shift 114
	SIMICOLON  shift 115

	input_child  goto 133


state 128
	output_child : SHL exp . output_child

	SHL  shift 117
	SIMICOLON  shift 118

	output_child  goto 134


state 129
	exp : id ASSIGN SQUITO exp SQUITO .  (39)

	.  reduce 39


state 130
	if_stmt : IF LPRACE exp RPRACE stmt ELSE . stmt

	INT  shift 17
	CHAR  shift 18
	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	IF  shift 22
	FOR  shift 23
	WHILE  shift 24
	CIN  shift 25
	COUT  shift 26
	MINUS  shift 27
	NOT  shift 28
	LBRACE  shift 12
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	if_stmt  goto 39
	exp  goto 40
	type_spec  goto 41
	id  goto 42
	input_stmt  goto 43
	while_stmt  goto 44
	for_stmt  goto 45
	output_stmt  goto 46
	comp_stmt  goto 47
	stmt  goto 135
	var_dec  goto 50
	exp_stmt  goto 51


state 131
	for_stmt : FOR LPRACE exp_stmt exp_stmt RPRACE stmt .  (28)

	.  reduce 28


state 132
	for_stmt : FOR LPRACE exp_stmt exp_stmt exp RPRACE . stmt

	INT  shift 17
	CHAR  shift 18
	ID  shift 19
	NUMBER  shift 20
	CONSTCHAR  shift 21
	IF  shift 22
	FOR  shift 23
	WHILE  shift 24
	CIN  shift 25
	COUT  shift 26
	MINUS  shift 27
	NOT  shift 28
	LBRACE  shift 12
	LPRACE  shift 30
	SIMICOLON  shift 31

	shift_exp  goto 32
	simple_exp  goto 33
	and_exp  goto 34
	or_exp  goto 35
	term  goto 36
	factor  goto 37
	rel_exp  goto 38
	if_stmt  goto 39
	exp  goto 40
	type_spec  goto 41
	id  goto 42
	input_stmt  goto 43
	while_stmt  goto 44
	for_stmt  goto 45
	output_stmt  goto 46
	comp_stmt  goto 47
	stmt  goto 136
	var_dec  goto 50
	exp_stmt  goto 51


state 133
	input_child : SHR exp input_child .  (31)

	.  reduce 31


state 134
	output_child : SHL exp output_child .  (34)

	.  reduce 34


state 135
	if_stmt : IF LPRACE exp RPRACE stmt ELSE stmt .  (25)

	.  reduce 25


state 136
	for_stmt : FOR LPRACE exp_stmt exp_stmt exp RPRACE stmt .  (27)

	.  reduce 27


##############################################################################
# Summary
##############################################################################

State 32 contains 2 shift-reduce conflict(s)
State 58 contains 2 shift-reduce conflict(s)
State 82 contains 2 reduce-reduce conflict(s)
State 121 contains 2 reduce-reduce conflict(s)
State 123 contains 1 shift-reduce conflict(s)


42 token(s), 25 nonterminal(s)
70 grammar rule(s), 137 state(s)


##############################################################################
# End of File
##############################################################################
