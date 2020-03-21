#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 19 of your 30 day trial period.
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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 11/05/16
# Time: 23:52:12
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ \t\n]+

    2  int

    3  char

    4  void

    5  main

    6  class

    7  if

    8  else

    9  for

   10  do

   11  while

   12  break

   13  continue

   14  return

   15  "="

   16  ([A-Za-z]|[_])([A-Za-z]|[0-9]|[_])*

   17  [0-9]+(\.[0-9]+)?(E[+-]?[0-9]+)?

   18  "<"

   19  "<="

   20  "=="

   21  "<>"

   22  ">"

   23  ">="

   24  "!="

   25  "+"

   26  "-"

   27  "*"

   28  "/"

   29  "%"

   30  "++"

   31  "--"

   32  "&"

   33  "|"

   34  "^"

   35  "~"

   36  "<<"

   37  ">>"

   38  "&&"

   39  "||"

   40  "!"

   41  "{"

   42  "}"

   43  "("

   44  ")"

   45  "["

   46  "]"

   47  ","

   48  ";"

   49  ":"

   50  "'"

   51  "//"

   52  "/*"

   53  "*/"


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09 - 0x0a (2)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x25               goto 5
	0x26               goto 6
	0x27               goto 7
	0x28               goto 8
	0x29               goto 9
	0x2a               goto 10
	0x2b               goto 11
	0x2c               goto 12
	0x2d               goto 13
	0x2f               goto 14
	0x30 - 0x39 (10)   goto 15
	0x3a               goto 16
	0x3b               goto 17
	0x3c               goto 18
	0x3d               goto 19
	0x3e               goto 20
	0x41 - 0x5a (26)   goto 21
	0x5b               goto 22
	0x5d               goto 23
	0x5e               goto 24
	0x5f               goto 21
	0x61               goto 21
	0x62               goto 25
	0x63               goto 26
	0x64               goto 27
	0x65               goto 28
	0x66               goto 29
	0x67 - 0x68 (2)    goto 21
	0x69               goto 30
	0x6a - 0x6c (3)    goto 21
	0x6d               goto 31
	0x6e - 0x71 (4)    goto 21
	0x72               goto 32
	0x73 - 0x75 (3)    goto 21
	0x76               goto 33
	0x77               goto 34
	0x78 - 0x7a (3)    goto 21
	0x7b               goto 35
	0x7c               goto 36
	0x7d               goto 37
	0x7e               goto 38


state 2
	^INITIAL

	0x09 - 0x0a (2)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x25               goto 5
	0x26               goto 6
	0x27               goto 7
	0x28               goto 8
	0x29               goto 9
	0x2a               goto 10
	0x2b               goto 11
	0x2c               goto 12
	0x2d               goto 13
	0x2f               goto 14
	0x30 - 0x39 (10)   goto 15
	0x3a               goto 16
	0x3b               goto 17
	0x3c               goto 18
	0x3d               goto 19
	0x3e               goto 20
	0x41 - 0x5a (26)   goto 21
	0x5b               goto 22
	0x5d               goto 23
	0x5e               goto 24
	0x5f               goto 21
	0x61               goto 21
	0x62               goto 25
	0x63               goto 26
	0x64               goto 27
	0x65               goto 28
	0x66               goto 29
	0x67 - 0x68 (2)    goto 21
	0x69               goto 30
	0x6a - 0x6c (3)    goto 21
	0x6d               goto 31
	0x6e - 0x71 (4)    goto 21
	0x72               goto 32
	0x73 - 0x75 (3)    goto 21
	0x76               goto 33
	0x77               goto 34
	0x78 - 0x7a (3)    goto 21
	0x7b               goto 35
	0x7c               goto 36
	0x7d               goto 37
	0x7e               goto 38


state 3
	0x09 - 0x0a (2)    goto 3
	0x20               goto 3

	match 1


state 4
	0x3d               goto 39

	match 40


state 5
	match 29


state 6
	0x26               goto 40

	match 32


state 7
	match 50


state 8
	match 43


state 9
	match 44


state 10
	0x2f               goto 41

	match 27


state 11
	0x2b               goto 42

	match 25


state 12
	match 47


state 13
	0x2d               goto 43

	match 26


state 14
	0x2a               goto 44
	0x2f               goto 45

	match 28


state 15
	0x2e               goto 46
	0x30 - 0x39 (10)   goto 15
	0x45               goto 47

	match 17


state 16
	match 49


state 17
	match 48


state 18
	0x3c               goto 48
	0x3d               goto 49
	0x3e               goto 50

	match 18


state 19
	0x3d               goto 51

	match 15


state 20
	0x3d               goto 52
	0x3e               goto 53

	match 22


state 21
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 16


state 22
	match 45


state 23
	match 46


state 24
	match 34


state 25
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 54
	0x73 - 0x7a (8)    goto 21

	match 16


state 26
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x67 (7)    goto 21
	0x68               goto 55
	0x69 - 0x6b (3)    goto 21
	0x6c               goto 56
	0x6d - 0x6e (2)    goto 21
	0x6f               goto 57
	0x70 - 0x7a (11)   goto 21

	match 16


state 27
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 58
	0x70 - 0x7a (11)   goto 21

	match 16


state 28
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 59
	0x6d - 0x7a (14)   goto 21

	match 16


state 29
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 60
	0x70 - 0x7a (11)   goto 21

	match 16


state 30
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x65 (5)    goto 21
	0x66               goto 61
	0x67 - 0x6d (7)    goto 21
	0x6e               goto 62
	0x6f - 0x7a (12)   goto 21

	match 16


state 31
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 63
	0x62 - 0x7a (25)   goto 21

	match 16


state 32
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 64
	0x66 - 0x7a (21)   goto 21

	match 16


state 33
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 65
	0x70 - 0x7a (11)   goto 21

	match 16


state 34
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x67 (7)    goto 21
	0x68               goto 66
	0x69 - 0x7a (18)   goto 21

	match 16


state 35
	match 41


state 36
	0x7c               goto 67

	match 33


state 37
	match 42


state 38
	match 35


state 39
	match 24


state 40
	match 38


state 41
	match 53


state 42
	match 30


state 43
	match 31


state 44
	match 52


state 45
	match 51


state 46
	0x30 - 0x39 (10)   goto 68


state 47
	0x2b               goto 69
	0x2d               goto 69
	0x30 - 0x39 (10)   goto 70


state 48
	match 36


state 49
	match 19


state 50
	match 21


state 51
	match 20


state 52
	match 23


state 53
	match 37


state 54
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 71
	0x66 - 0x7a (21)   goto 21

	match 16


state 55
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 72
	0x62 - 0x7a (25)   goto 21

	match 16


state 56
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 73
	0x62 - 0x7a (25)   goto 21

	match 16


state 57
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 74
	0x6f - 0x7a (12)   goto 21

	match 16


state 58
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 10


state 59
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 75
	0x74 - 0x7a (7)    goto 21

	match 16


state 60
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 76
	0x73 - 0x7a (8)    goto 21

	match 16


state 61
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 7


state 62
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 77
	0x75 - 0x7a (6)    goto 21

	match 16


state 63
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 78
	0x6a - 0x7a (17)   goto 21

	match 16


state 64
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 79
	0x75 - 0x7a (6)    goto 21

	match 16


state 65
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 80
	0x6a - 0x7a (17)   goto 21

	match 16


state 66
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 81
	0x6a - 0x7a (17)   goto 21

	match 16


state 67
	match 39


state 68
	0x30 - 0x39 (10)   goto 68
	0x45               goto 47

	match 17


state 69
	0x30 - 0x39 (10)   goto 70


state 70
	0x30 - 0x39 (10)   goto 70

	match 17


state 71
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 82
	0x62 - 0x7a (25)   goto 21

	match 16


state 72
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 83
	0x73 - 0x7a (8)    goto 21

	match 16


state 73
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 84
	0x74 - 0x7a (7)    goto 21

	match 16


state 74
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 85
	0x75 - 0x7a (6)    goto 21

	match 16


state 75
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 86
	0x66 - 0x7a (21)   goto 21

	match 16


state 76
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 9


state 77
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 2


state 78
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 87
	0x6f - 0x7a (12)   goto 21

	match 16


state 79
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x74 (20)   goto 21
	0x75               goto 88
	0x76 - 0x7a (5)    goto 21

	match 16


state 80
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x63 (3)    goto 21
	0x64               goto 89
	0x65 - 0x7a (22)   goto 21

	match 16


state 81
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 90
	0x6d - 0x7a (14)   goto 21

	match 16


state 82
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6a (10)   goto 21
	0x6b               goto 91
	0x6c - 0x7a (15)   goto 21

	match 16


state 83
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 3


state 84
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 92
	0x74 - 0x7a (7)    goto 21

	match 16


state 85
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 93
	0x6a - 0x7a (17)   goto 21

	match 16


state 86
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 8


state 87
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 5


state 88
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 94
	0x73 - 0x7a (8)    goto 21

	match 16


state 89
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 4


state 90
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 95
	0x66 - 0x7a (21)   goto 21

	match 16


state 91
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 12


state 92
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 6


state 93
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 96
	0x6f - 0x7a (12)   goto 21

	match 16


state 94
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 97
	0x6f - 0x7a (12)   goto 21

	match 16


state 95
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 11


state 96
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x74 (20)   goto 21
	0x75               goto 98
	0x76 - 0x7a (5)    goto 21

	match 16


state 97
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 14


state 98
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 99
	0x66 - 0x7a (21)   goto 21

	match 16


state 99
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 13


#############################################################################
# Summary
#############################################################################

1 start state(s)
53 expression(s), 99 state(s)


#############################################################################
# End of File
#############################################################################
