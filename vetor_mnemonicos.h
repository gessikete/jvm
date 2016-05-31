#ifndef MNEMONICOS_H
#define MNEMONICOS_H


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


#define NO_OP " "
#define CP2 "cp2"
#define CP1 "cp1"
#define LV1 "lv1"
#define INT1 "int1"
#define INT2 "int2"
#define Lv1Int1 "lv1 int1"
#define OFFSET2 "offset2"
#define OFFSET4 "offset4"
#define Cp2Int1 "cp2+int1"
#define FLAG1 "flag1"




//estrutura para guardar os opcodes e mnemonicos
typedef struct
{
	char *nome;
	char *operando;
} t_instrucoes;


//funcao de preenchimento do vetor
t_instrucoes* vetorMnemonicos (void);


#endif