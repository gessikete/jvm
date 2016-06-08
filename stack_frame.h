/* Módulo responsável pelas operações das estruturas da pilha de frames */
#ifndef STACK_FRAME_H
#define STACK_FRAME_H

#include "leitor_classe.h"
#include "leitor_metodos.h"
#include "operand_stack.h"
#include "resolve.h"

/* Estrutura que modela um frame */
typedef struct{
	method_info *pt_metodo;
	u4 pc;
	u4 array_variaveis_locais_count;
	u4 *array_variaveis_locais;
	struct operand_stack *operand_stack;
	cp_info *pt_constant_pool;
    elemento_lista_arrays *list_arrays;
    elemento_lista_objetos *list_objects;
    uint32_t return_address;
}frame;

/* Estrutura que modela a pilha de frames */
typedef struct struct_stack_frames {
    frame *dados;
    struct struct_stack_frames *next;
}stack_frames;



#endif
