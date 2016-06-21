/* Módulo responsável pelas operações das estruturas da pilha de frames */
#ifndef PILHA_FRAMES_H
#define PILHA_FRAMES_H

#include <stdlib.h>
#include "types.h"
#include "macros.h"



elemento_lista_arrays* alocar_lista_arrays();
elemento_lista_objetos* alocar_lista_objetos();


t_operand_stack* alocar_operand_stack();
t_operand *alocar_operando(u4 data, t_operand *next);

t_frame *alocar_frame(method_info *pt_metodo, cp_info *pt_constant_pool, t_frame *next);
stack_frames *alocar_stack_frames();

t_operand *pop_operando(t_operand_stack *pilha_operandos);
void push_operando(u4 data, t_operand_stack *operand_stack);


void push_frame(method_info *pt_metodo, cp_info *pt_constant_pool, stack_frames *pilha_frames);
t_frame *pop_frame(stack_frames *pilha_frames);
#endif
