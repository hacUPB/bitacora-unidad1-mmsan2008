@15
D=A
@var
M=D

@10
D=A
@i
M=D

@i
D=M
@var
D=D-M

@20
D;JGT 
@30
0;JMP                   


@1000
D=A
@i
M=D

(LOOP)
@i
D=M
@COUNT
D;JEQ
@i
M=M-1
@LOOP
0;JMP
(COUNT)
