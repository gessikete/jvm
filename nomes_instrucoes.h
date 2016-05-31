#ifndef NOMES_INST_H
#define NOMES_INST_H


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "types.h"


#define NO_OP 0
#define CP2 1
#define CP1 2
#define LV1 3
#define INT1 4
#define INT2 5
#define LV1_INT1 6
#define OFFSET2 7
#define OFFSET4 8
#define CP2_INT1 9
#define FLAG1 10
#define INTERROG 11

/**
#define NO_OP "no_op"
#define CP2 "cp2"
#define CP1 "cp1"
#define LV1 "lv1"
#define INT1 "int1"
#define INT2 "int2"
#define LV1_INT1 "lv1_int1"
#define OFFSET2 "offset2"
#define OFFSET4 "offset4"
#define CP2_INT1 "cp2_int1"
#define FLAG1 "flag"
#define INTERROG "?"**/


//estrutura para guardar os opcodes e mnemonicos
typedef struct
{
	char *nome;
	u1 operando;
} t_instrucoes;


//funcao de preenchimento do vetor
t_instrucoes* vetorMnemonicos (void);


u1 acha_tamanho_operando(u1 operando);


#endif