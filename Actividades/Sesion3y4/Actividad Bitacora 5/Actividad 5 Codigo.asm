
//inicializa suma y guarda en la variable @sum
@0
D=A
@sum
M=D
//inicializa contador y guarda en la variable @contador
@1
D=A
@contador
M=D

//el ciclo salta aca cada ves que yo le de la instruccion, llama la variable contador , copia el valor de contador en D,
//voy a @5 y si es meyor que 6 termina el ciclo si no continua 
(CICLO)
@contador
D=M
@5
D=D-A
@FIN
D;JGT

//incrementa 
@contador
M=M+1