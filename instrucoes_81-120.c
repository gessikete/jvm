/*!
   \file instrucoes_81-120.c
   \brief Instruções da Máquina Virtual Java.

   Módulo responsável por parte das instruções que definem as operações a serem
   executadas pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#include "instrucoes_81-120.h"

void fastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

	// Recupera o float a ser salvo
	t_operand *operando_value = pop_operando(frame->operand_stack);

	// Recupera o índice onde o float será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o float será salvo
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\nNull Pointer Exception\n");
		return;
	}

	if(index >= array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Salva float na posicao index
	array->array_data[index] = operando_value->data;

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_value);
	free(operando_endereco);
}

void dastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	u8 value;
	t_array *array = NULL;

	// Recupera o double a ser salvo
	t_operand *operando_low = pop_operando(frame->operand_stack);
	t_operand *operando_high = pop_operando(frame->operand_stack);

	value = (((u8)operando_high->data)<<32)|(operando_low->data);

	// Recupera o índice onde o double será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o double será salvo
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\nNull Pointer Exception\n");
		return;
	}

	if(index >= array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Salva o double na posição index do array de double
	array->array_data[index] = value;

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_low);
	free(operando_high);
	free(operando_endereco);
}

void aastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index, value;
	t_array *array = NULL;

	// Recupera a referencia a ser salva
	t_operand *operando_value = pop_operando(frame->operand_stack);
	value = operando_value->data;

	// Recupera o índice onde está a referencia
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço da referência
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\nNull Pointer Exception\n");
		return;
	}

	if(index >= array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Salva o endereço na posição index do array de bytes
	array->array_data[index] = value;

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_value);
	free(operando_endereco);
}

void bastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index, value;
	t_array *array = NULL;

	// Recupera o byte a ser salvo
	t_operand *operando_value = pop_operando(frame->operand_stack);
	value = operando_value->data;

	// Recupera o índice onde o byte será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o byte será salvo
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\nNull Pointer Exception\n");
		return;
	}

	if(index >= array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Salva o byte na posição index do array de bytes
	array->array_data[index] = value;

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_value);
	free(operando_endereco);
}

void castore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index, value;
	t_array *array = NULL;

	// Recupera o char a ser salvo
	t_operand *operando_value = pop_operando(frame->operand_stack);
	value = operando_value->data;

	// Recupera o índice onde o char será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o char será salvo
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\nNull Pointer Exception\n");
		return;
	}

	if(index >= array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Salva o char na posição index do array de chars
	array->array_data[index] = value;

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_value);
	free(operando_endereco);
}

void sastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index, value;
	t_array *array = NULL;

	// Recupera o short a ser salvo
	t_operand *operando_value = pop_operando(frame->operand_stack);
	value = operando_value->data;

	// Recupera o índice onde o short será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o short será salvo
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\nNull Pointer Exception\n");
		return;
	}

	if(index >= array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Salva o short na posição index do array
	array->array_data[index] = value;

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_value);
	free(operando_endereco);
}

void pop(stack_frames *pilha_frames) {
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	free(temp_operando);
}

void pop2(stack_frames *pilha_frames) {
	t_operand *first = pop_operando(pilha_frames->first->operand_stack);
	t_operand *second = pop_operando(pilha_frames->first->operand_stack);

	free(first);
	free(second);
}

void dup(stack_frames *pilha_frames) {
	t_operand *first = pilha_frames->first->operand_stack->first;
  
	push_operando(first->tag,first->data,pilha_frames->first->operand_stack);
}

void dup_x1(stack_frames *pilha_frames) {

}

void dup_x2(stack_frames *pilha_frames) {

}

void dup2(stack_frames *pilha_frames) {
	t_operand *first = pilha_frames->first->operand_stack->first;
	t_operand *second = first->next;
  
	push_operando(second->tag,second->data,pilha_frames->first->operand_stack);
	push_operando(first->tag,first->data,pilha_frames->first->operand_stack);
}

void dup2_x1(stack_frames *pilha_frames) {

}

void dup2_x2(stack_frames *pilha_frames) {

}

void swap(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
  
	
	t_operand *temp = frame->operand_stack->first;
	frame->operand_stack->first = frame->operand_stack->first->next;
	frame->operand_stack->first->next = temp;
}

void iadd(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de soma
	resultado = operando1_int+operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void ladd(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	long operando2_long;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);

	// Realiza operação soma
	resultado = operando1_long+operando2_long;

	// Armazena resultado da soma na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void fadd(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	float operando1_float;
	float operando2_float;
	float resultado_float;
	u4 resultado;

	// Transforma os operandos em floats
	operando1_float = u4_to_float(operando1->data);
	operando2_float = u4_to_float(operando2->data);

	// Realiza operação de soma
	resultado_float = operando1_float + operando2_float;

	// Transforma resultado da soma em u4
	resultado = float_to_u4(resultado_float);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_FLOAT, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void dadd(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	double operando1_double;
	double operando2_double;
	double resultado_double;
	u8 resultado;

	// Transforma os operandos em doubles
	operando1_double = u8_to_double(operando1_low->data,operando1_high->data);
	operando2_double = u8_to_double(operando2_low->data,operando2_high->data);

	// Realiza soma
	resultado_double = operando1_double+operando2_double;

	// Transforma resultado da soma, um double, em um u8
	resultado = double_to_u8(resultado_double);

	// Armazena resultado da soma na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32, frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado, frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void isub(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de subtração
	resultado = operando1_int-operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void lsub(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	long operando2_long;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);

	// Realiza operação de subtração
	resultado = operando1_long-operando2_long;

	// Armazena resultado da subtração na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void fsub(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	float operando1_float;
	float operando2_float;
	float resultado_float;
	u4 resultado;

	// Transforma os operandos em floats
	operando1_float = u4_to_float(operando1->data);
	operando2_float = u4_to_float(operando2->data);

	// Realiza operação de subtração
	resultado_float = operando1_float-operando2_float;

	// Transforma resultado da subtração em u4
	resultado = float_to_u4(resultado_float);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_FLOAT, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void dsub(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	double operando1_double;
	double operando2_double;
	double resultado_double;
	u8 resultado;

	// Transforma os operandos em doubles
	operando1_double = u8_to_double(operando1_low->data,operando1_high->data);
	operando2_double = u8_to_double(operando2_low->data,operando2_high->data);

	// Realiza subtração
	resultado_double = operando1_double-operando2_double;

	// Transforma resultado da subtração em u8
	resultado = double_to_u8(resultado_double);

	// Armazena resultado da subtração na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32, frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado, frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void imul(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de multiplicação
	resultado = operando1_int*operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void lmul(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	long operando2_long;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);

	// Realiza operação multiplicação
	resultado = operando1_long*operando2_long;

	// Armazena resultado da multiplicação na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void fmul(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	float operando1_float;
	float operando2_float;
	float resultado_float;
	u4 resultado;

	// Transforma os operandos em floats
	operando1_float = u4_to_float(operando1->data);
	operando2_float = u4_to_float(operando2->data);

	// Realiza operação de multiplicação
	resultado_float = operando1_float*operando2_float;

	// Transforma resultado da multiplicação em u4
	resultado = float_to_u4(resultado_float);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_FLOAT, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void dmul(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	double operando1_double;
	double operando2_double;
	double resultado_double;
	u8 resultado;

	// Transforma os operandos em doubles
	operando1_double = u8_to_double(operando1_low->data,operando1_high->data);
	operando2_double = u8_to_double(operando2_low->data,operando2_high->data);

	// Realiza multiplicação
	resultado_double = operando1_double*operando2_double;

	// Transforma resultado em u8
	resultado = double_to_u8(resultado_double);

	// Armazena resultado da multiplicação na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32, frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado, frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void idiv(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de divisão
	resultado = operando1_int/operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);

}

void ldiv_(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera divisor
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera número a ser dividido
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	long operando2_long;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);


	// Realiza divisão
	resultado = operando1_long/operando2_long;

	// Armazena resultado da divisão na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void fdiv(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera divisor
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera número a ser dividido
	t_operand *operando1 = pop_operando(frame->operand_stack);

	float operando1_float;
	float operando2_float;
	float resultado_float;
	u4 resultado;

	// Transforma os operandos em floats
	operando1_float = u4_to_float(operando1->data);
	operando2_float = u4_to_float(operando2->data);

	// Realiza divisão
	resultado_float = operando1_float/operando2_float;

	// Transforma resultado da divisão, um float, em um u4
	resultado = float_to_u4(resultado_float);

	// Armazena resultado da divisão na pilha de operandos
	push_operando(TAG_FLOAT, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void ddiv(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera divisor
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera número a ser dividido
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	double operando1_double;
	double operando2_double;
	double resultado_double;
	u8 resultado;

	// Transforma os operandos em doubles
	operando1_double = u8_to_double(operando1_low->data,operando1_high->data);
	operando2_double = u8_to_double(operando2_low->data,operando2_high->data);

	// Realiza divisão
	resultado_double = operando1_double/operando2_double;

	// Transforma resultado da divisão, um double, em um u8
	resultado = double_to_u8(resultado_double);

	// Armazena resultado da divisão na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32,frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void irem(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	int resultado_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza módulo
	resultado_int = operando1_int%operando2_int;

	// Transforma resultado do módulo, um int, em um u4
	resultado = (u4)(resultado_int);

	// Armazena o módulo na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void lrem(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	long operando2_long;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);

	// Realiza operação de módulo
	resultado = operando1_long%operando2_long;

	// Armazena resultado do módulo na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void frem(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	float operando1_float;
	float operando2_float;
	float resultado_float;
	u4 resultado;

	// Transforma os operandos em floats
	operando1_float = u4_to_float(operando1->data);
	operando2_float = u4_to_float(operando2->data);

	// Realiza operação de módulo
	resultado_float = fmod(operando1_float,operando2_float);

	// Transforma resultado do módulo, um float, em um u4
	resultado = float_to_u4(resultado_float);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_FLOAT, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void drem_(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera primeiro operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera segundo operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	double operando1_double;
	double operando2_double;
	double resultado_double;
	u8 resultado;

	// Transforma os operandos em doubles
	operando1_double = u8_to_double(operando1_low->data,operando1_high->data);
	operando2_double = u8_to_double(operando2_low->data,operando2_high->data);

	// Realiza módulo
	resultado_double = fmod(operando1_double,operando2_double);

	// Transforma resultado do módulo, um double, em um u8
	resultado = double_to_u8(resultado_double);

	// Armazena resultado do módulo na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32, frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado, frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void ineg(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);

	int operando_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando_int = (int32_t)operando->data;

	// Obtém número negativo
	resultado = -operando_int;

	// Armazena o número negativo
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando);
}

void lneg(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando_low = pop_operando(frame->operand_stack);
	t_operand *operando_high = pop_operando(frame->operand_stack);

	long operando_long;
	u8 resultado;

	// Concatena high e low
	operando_long = u8_to_long(operando_low->data,operando_high->data);

	// Obtém número negativo
	resultado = -operando_long;

	// Armazena o número negativo na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_high);
	free(operando_low);
}

void fneg(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);

	float operando_float;
	float resultado_float;
	u4 resultado;

	// Transforma os operando em float
	operando_float = u4_to_float(operando->data);

	// Obtém número negativo
	resultado_float = -operando_float;

	// Transforma resultado, um float, em um u4
	resultado = float_to_u4(resultado_float);

	// Armazena o número negativo na pilha de operandos
	push_operando(TAG_FLOAT, resultado,frame->operand_stack);

	// Desaloca operando que foi desempilhado
	free(operando);
}

void dneg(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando_low = pop_operando(frame->operand_stack);
	t_operand *operando_high = pop_operando(frame->operand_stack);

	double operando_double;
	double resultado_double;
	u8 resultado;

	// Concatena high e low
	operando_double= u8_to_double(operando_low->data,operando_high->data);

	// Obtém número negativo
	resultado_double = -operando_double;

	// Transforma resultado, um double, em um u8
	resultado = double_to_u8(resultado_double);

	// Armazena o número negativo na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32,frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_high);
	free(operando_low);
}

void ishl(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Tamanho do shift
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Número a ser shiftado
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de shift
	resultado = operando1_int<<operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}
