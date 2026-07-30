
//“Crea un programa que use un ciclo para sumar los números del 1 al 5 y guarde el resultado en la dirección de memoria 12.”//

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
D=M
@sum
M=D+M

@contador
M=M+1

@CICLO
0;JMP

(FIN)

@sum
D=M
@12
M=D
