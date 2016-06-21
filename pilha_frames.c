#include "pilha_frames.h"

elemento_lista_arrays* alocar_lista_arrays() {
	elemento_lista_arrays* lista_arrays;

	lista_arrays = (elemento_lista_arrays*) malloc(sizeof(elemento_lista_arrays));

	return lista_arrays;

}

elemento_lista_objetos* alocar_lista_objetos() {
	elemento_lista_objetos* lista_objetos;

	lista_objetos = (elemento_lista_objetos*) malloc(sizeof(elemento_lista_objetos));

	return lista_objetos;
}

t_operand_stack* alocar_operand_stack() {
	t_operand_stack* operand_stack;

	operand_stack = (t_operand_stack*) malloc(sizeof(t_operand_stack));
	if(!operand_stack) printf("\nNao foi possivel alocar a pilha de operandos\n");
	else operand_stack->first = NULL;

	return operand_stack;
}

t_operand *alocar_operando(u1 tag, u4 data, t_operand *next) {
	t_operand *operando;

	operando = (t_operand*) malloc(sizeof(t_operand));

	if(operando) {
		operando->tag = tag;
		operando->data = data;
		operando->next = next;
	} else printf("\nNao foi possivel alocar espaco para operando\n");


	return operando;
}

stack_frames *alocar_stack_frames() {
	stack_frames *pilha_frames = (stack_frames*) malloc(sizeof(stack_frames));

	if(!pilha_frames) printf("\nNao foi possivel alocar a pilha de frames\n");
	else pilha_frames->first = NULL;

	return pilha_frames;
}

t_frame *alocar_frame(method_info *pt_metodo, cp_info *pt_constant_pool, t_frame *next) {
	t_frame *frame = NULL;
	code_attribute *code_info;
	u2 i;

	// Verifica se método não está vazio
	if(pt_metodo) {

		// Tenta alocar um novo frame
		frame = (t_frame*) malloc(sizeof(t_frame));

		if(frame) {
			attribute_info *atributos = pt_metodo->attributes;

			// busca atributo code
			for(i=0; i<pt_metodo->attributes_count; i++) {
				if(atributos[i].attribute_tag==CODE_NUM) {
					code_info = &(atributos[i].info.code_info);
					break;
				}
			}

			frame->code_info = code_info;

			frame->pt_metodo = pt_metodo;
			frame->pc = 0;
			frame->array_variaveis_locais_count = code_info->max_locals;
			frame->array_variaveis_locais = (u4*) malloc(sizeof(u4)*(code_info->max_locals));

			frame->operand_stack = alocar_operand_stack();

			frame->pt_constant_pool = pt_constant_pool ;

			// Listas começam vazias
			frame->lista_arrays = NULL;
			frame->lista_objetos = NULL;


			frame->next = next;
		}

	} else printf("Nao foi possivel criar frame (metodo vazio)");

	return frame;
}

t_operand *pop_operando(t_operand_stack *pilha_operandos) {
	t_operand *operando = pilha_operandos->first;
	pilha_operandos->first = operando->next;

	return operando;
}

void push_operando(u1 tag, u4 data, t_operand_stack *operand_stack) {
	operand_stack->first = alocar_operando(tag, data, operand_stack->first);
}

void push_frame(method_info *pt_metodo, cp_info *pt_constant_pool, stack_frames *pilha_frames) {
	pilha_frames->first = alocar_frame(pt_metodo,pt_constant_pool,pilha_frames->first);
}

t_frame *pop_frame(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	pilha_frames->first = frame->next;

	return frame;
}
