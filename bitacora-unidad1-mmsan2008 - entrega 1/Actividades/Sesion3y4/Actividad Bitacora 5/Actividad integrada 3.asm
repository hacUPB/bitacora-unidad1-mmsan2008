@SCREEN
D=A
@mov
M=D

(LOOP)

@mov
A=M
M=0


@KBD
D=M


@101
D=D-A
@left
D;JEQ


@KBD
D=M


@105
D=D-A
@right
D;JEQ

@DRAW
0;JMP

(left)

@POS
M=M-1
@DRAW
0;JMP

(right)

@mov
M=M+1

(DRAW)

@mov
A=M
M=-1

@LOOP
0;JMP

(mov)