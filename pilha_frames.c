/*!
   \file pilha_frames.c
   \brief Pilha de frames.

   Módulo responsável pelas operações das estruturas da pilha de frames e pilha
   de operandos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "pilha_frames.h"

t_array* criar_array(u1 tag, u2 tamanho, u1 dimensoes) {
	t_array *array = (t_array*)malloc(sizeof(t_array));
	
	array->tag = tag;
	array->tamanho = tamanho;
	array->dimensoes = dimensoes;
	
	switch(tag) {
		case BOOLEAN_ARRAY: array->info.array_boolean = (tipo_boolean*)calloc(tamanho,sizeof(tipo_boolean)); break;
		case BYTE_ARRAY: array->info.array_byte = (tipo_byte*)calloc(tamanho,sizeof(tipo_byte)); break;
		case CHAR_ARRAY: array->info.array_char = (tipo_char*)calloc(tamanho,sizeof(tipo_char)); break;
		case SHORT_ARRAY: array->info.array_short = (tipo_short*)calloc(tamanho,sizeof(tipo_short)); break;
		case INT_ARRAY: array->info.array_int = (tipo_int*)calloc(tamanho,sizeof(tipo_int)); break;
		case LONG_ARRAY: array->info.array_long = (tipo_long*)calloc(tamanho,sizeof(tipo_long)); break;
		case FLOAT_ARRAY: array->info.array_float = (tipo_float*)calloc(tamanho,sizeof(tipo_float)); break;
		case DOUBLE_ARRAY: array->info.array_double = (tipo_double*)calloc(tamanho,sizeof(tipo_double)); break;
		case OBJETO_ARRAY: array->info.array_objeto = (objeto*)calloc(tamanho,sizeof(objeto)); break;
		case ARRAY_ARRAY: array->info.array_array = (t_array*)calloc(tamanho,sizeof(t_array)); break;
		default: printf("\nErro: Tipo de array nao existe\n");
	}

	return array;
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
			frame->nome_metodo = recupera_utf8(pt_constant_pool,pt_metodo->name_index);


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

			// Lista começa vazia
			frame->lista_objetos = NULL;


			frame->next = next;
		}

	} else printf("Nao foi possivel criar frame (metodo vazio)");

	return frame;
}

void desalocar_array(t_array *pt_array){
	if(pt_array != NULL){
		// desaloca o array relativo a tag do tipo de array Java
		switch (pt_array->tag) {
			case BOOLEAN_ARRAY: if(pt_array->info.array_boolean != NULL) free(pt_array->info.array_boolean); break;
			case BYTE_ARRAY: if(pt_array->info.array_byte != NULL) if(pt_array->info.array_byte != NULL) free(pt_array->info.array_byte); break;
			case CHAR_ARRAY: if(pt_array->info.array_char != NULL) free(pt_array->info.array_char); break;
			case SHORT_ARRAY: if(pt_array->info.array_short != NULL) free(pt_array->info.array_short); break;
			case INT_ARRAY: if(pt_array->info.array_int != NULL) free(pt_array->info.array_int); break;
			case LONG_ARRAY: if(pt_array->info.array_long != NULL) free(pt_array->info.array_long); break;
			case FLOAT_ARRAY: if(pt_array->info.array_float != NULL) free(pt_array->info.array_float); break;
			case DOUBLE_ARRAY: if(pt_array->info.array_double != NULL) free(pt_array->info.array_double); break;
			case OBJETO_ARRAY: if(pt_array->info.array_objeto != NULL) desalocar_objeto(pt_array->info.array_objeto); break;
			case ARRAY_ARRAY: if(pt_array->info.array_array != NULL) desalocar_array(pt_array->info.array_array); break;
		
		}
		// desaloca o array em si
		free(pt_array);
	}
}

void desalocar_lista_objetos(elemento_lista_objetos *lista_objetos){
	if(lista_objetos != NULL){
		if (lista_objetos->proximo != NULL) {
			// desaloca o próximo objeto da lista
			desalocar_lista_objetos(lista_objetos->proximo);
			if(lista_objetos->pt_objeto != NULL){
				// desaloca o objeto
				desalocar_objeto(lista_objetos->pt_objeto);
			}
		}
		// desaloca a lista de objetos em si
		free(lista_objetos);
	}
}

void desalocar_objeto(objeto *pt_objeto){
	if(pt_objeto != NULL){
		// Desaloca class file
		if(pt_objeto->pt_classe != NULL) desalocar_classe(pt_objeto->pt_classe);

		// desaloca runtime field
		if(pt_objeto->lista_runtime_fields != NULL) desalocar_runtime_fields(pt_objeto->lista_runtime_fields);

		// desaloca lista  de arrays
		if(pt_objeto->lista_arrays != NULL) desalocar_array(pt_objeto->lista_arrays);

		// desaloca o objeto em si
		free(pt_objeto);
	}
}

void desalocar_runtime_fields(runtime_field *pt_runtime_fields){
	if(pt_runtime_fields != NULL){
		// desaloca field
		if(pt_runtime_fields->pt_field != NULL) desalocar_campos(pt_runtime_fields->pt_field, 1);

		// desaloca class FILE
		if(pt_runtime_fields->pt_classe != NULL) desalocar_classe(pt_runtime_fields->pt_classe);

		// desaloca o runtime field em si
		free(pt_runtime_fields);
	}
}

void desalocar_operand_stack(t_operand_stack *pt_operand_stack){
	if(pt_operand_stack != NULL){
		// desaloca o primeiro elemento da pilha de operandos
		if (pt_operand_stack->first != NULL) {
			desalocar_operando(pt_operand_stack->first);
		}
		// desaloca a pilha de operandos em si
		free(pt_operand_stack);
	}
}

void desalocar_operando(t_operand *pt_operando){
	if(pt_operando != NULL){
		// desaloca recursivamente toda a lista
		if(pt_operando->next != NULL) desalocar_operando(pt_operando->next);
		// desaloca o operando em si
		free(pt_operando);
	}
}

void desalocar_stack_frames(stack_frames *pt_stack_frames){
	if(pt_stack_frames != NULL){
		// desaloca o primeiro frame
		if(pt_stack_frames->first != NULL) desalocar_frame(pt_stack_frames->first);
		// desaloca a pilha propriamente dita
		free(pt_stack_frames);
	}
}

void desalocar_frame(t_frame *pt_frame){
	if(pt_frame != NULL){
		// desaloca o nome do método
		if(pt_frame->nome_metodo != NULL) free(pt_frame->nome_metodo);

		// muda a referência do ponteiro do método para null
		if(pt_frame->pt_metodo != NULL) pt_frame->pt_metodo = NULL;

		// muda a referência do ponteiro de code_info para null
		if(pt_frame->code_info != NULL) pt_frame->code_info = NULL;

		// desaloca array de variáveis locais
		if(pt_frame->array_variaveis_locais != NULL) free(pt_frame->array_variaveis_locais);

		// desaloca operand stack_frames
		if(pt_frame->operand_stack != NULL) desalocar_operand_stack(pt_frame->operand_stack);

		// muda a referência do ponteiro de constant pool para null
		if(pt_frame->pt_constant_pool != NULL) pt_frame->pt_constant_pool = NULL;

		// desaloca lista de objetos
		if(pt_frame->lista_objetos != NULL) desalocar_lista_objetos(pt_frame->lista_objetos);

		if(pt_frame->next != NULL) desalocar_frame(pt_frame->next);
		// desaloca o frame em si
		free(pt_frame);
	}
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
