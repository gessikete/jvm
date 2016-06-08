#ifndef STACKFRAME_H
#define STACKFRAME_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <inttypes.h>
#include "types.h"
#include "arquivos.h"
#include "leitor_atributos.h"
#include "leitor_classe.h"
#include "leitor_metodos.h"
#include "leitor_campos.h"
#include "leitor_constant_pool.h"
#include "exibidor_constant_pool.h"
#include "exibidor_campos.h"
#include "exibidor_metodos.h"
#include "exibidor_atributos.h"
#include "recuperar_constant_pool.h"
#include "validation.h"
#include "macros.h"


/* ESTRUTURA DO FRAME */
typedef struct{
	method_info *pt_metodo;
	u4 pc;
	u4 array_variaveis_locais_count;
	u4 *array_variaveis_locais;
	struct operand_stack *operand_stack;
	cp_info *pt_constant_pool;
}frame;

/* STACK DE FRAMES */
typedef struct struct_stack_frames {
    frame *dados;
    struct struct_stack_frames *next;
}stack_frames;

/* STACK DE OPERANDOS */
typedef struct operand_stack {
	u4 data;
	struct operand_stack *next;
}operand_stack;

#endif
