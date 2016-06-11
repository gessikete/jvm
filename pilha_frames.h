/* Módulo responsável pelas operações das estruturas da pilha de frames */
#ifndef PILHA_FRAMES_H
#define PILHA_FRAMES_H

#include "leitor_classe.h"
#include "leitor_metodos.h"
#include "resolve.h"


typedef struct operand {
	u4 data;
	struct operand *next;
} t_operand;

/* Estrutura que modela a pilha de operandos */
typedef struct operand_stack {
	t_operand *first;
} t_operand_stack;

/* Estrutura que modela um frame */
typedef struct frame {
	method_info *pt_metodo;
	u4 pc;
	code_attribute *code_info;
	u4 array_variaveis_locais_count;
	u4 *array_variaveis_locais;
	t_operand_stack *operand_stack;
	cp_info *pt_constant_pool;
	elemento_lista_arrays *lista_arrays;
	elemento_lista_objetos *lista_objetos;
	u4 return_value;
	struct frame *next;
} t_frame;

/* Estrutura que modela a pilha de frames */
typedef struct {
    t_frame *first;
} stack_frames;


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
