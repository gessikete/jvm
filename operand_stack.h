/* Módulo responsável pelas operações das estruturas da pilha de operandos */
#ifndef STACK_FRAME_H
#define STACK_FRAME_H

#include "types.h"

/* Estrutura que modela a pilha de operandos */
typedef struct struct_operand_stack {
	u4 data;
	struct operand_stack *next;
}operand_stack;

#endif
