/*!
   \file instrucoes_41-80.c
   \brief Instruções da Máquina Virtual Java.

   Módulo responsável por parte das instruções que definem as operações a serem
   executadas pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#include "instrucoes_41-80.h"

void dload_3(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um double do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[3];
    // recupera os low bytes de um double do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[4];

    // empilha big endian
    push_operando(TAG_DOUBLE, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, low_bytes, pilha_frames->first->operand_stack);
}

void aload_0(stack_frames *pilha_frames) {
    // recupera o valor na posição 0 do array de variávies locais
    u4 value = pilha_frames->first->array_variaveis_locais[0];

    // empilha o valor na pilha de operandos
    push_operando(TAG_OBJECT_REF, value, pilha_frames->first->operand_stack);
}

void aload_1(stack_frames *pilha_frames) {
    // recupera o valor na posição 0 do array de variávies locais
    u4 value = pilha_frames->first->array_variaveis_locais[1];

    // empilha o valor na pilha de operandos
    push_operando(TAG_OBJECT_REF, value, pilha_frames->first->operand_stack);
}

void aload_2(stack_frames *pilha_frames) {
    // recupera o valor na posição 0 do array de variávies locais
    u4 value = pilha_frames->first->array_variaveis_locais[2];

    // empilha o valor na pilha de operandos
    push_operando(TAG_OBJECT_REF, value, pilha_frames->first->operand_stack);
}

void aload_3(stack_frames *pilha_frames) {
    // recupera o valor na posição 0 do array de variávies locais
    u4 value = pilha_frames->first->array_variaveis_locais[3];

    // empilha o valor na pilha de operandos
    push_operando(TAG_OBJECT_REF, value, pilha_frames->first->operand_stack);
}

void iaload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

	// Recupera o índice do int dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (iaload)\n");
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Empilha valor na pilha de operandos
	push_operando(TAG_INTEGER, array->info.array_int[index], pilha_frames->first->operand_stack);


	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void laload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

	// Recupera o índice do long dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (laload)\n");
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Empilha valor na pilha de operandos
	push_operando(TAG_LONG, array->info.array_long[index]>>32, pilha_frames->first->operand_stack);
	push_operando(TAG_LONG, array->info.array_long[index], pilha_frames->first->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void faload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	float value;
	t_array *array = NULL;

	// Recupera o índice do float dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (faload)\n");
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Recupera o valor como um float
	value = array->info.array_float[index];

	// Empilha valor na pilha de operandos
	push_operando(TAG_FLOAT, float_to_u4(value), pilha_frames->first->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void daload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	double value;
	t_array *array = NULL;

	// Recupera o índice do double dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (daload)\n");
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	// Recupera o valor como um double
	value = array->info.array_double[index];

	// Empilha valor na pilha de operandos
	push_operando(TAG_DOUBLE, (double_to_u8(value))>>32, pilha_frames->first->operand_stack);
	push_operando(TAG_DOUBLE, (double_to_u8(value)), pilha_frames->first->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void aaload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

	// Recupera o índice do subarray dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (aaload)\n");
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		return;
	}

	u4 endereco = (u4)(&array->info.array_array[index]);

	// Empilha endereco do subarray na pilha de operandos
	push_operando(TAG_ARRAY_REF, endereco, pilha_frames->first->operand_stack);


	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void baload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

	// Recupera o índice do byte dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (baload)\n");
		return;
	}

	// Empilha valor na pilha de operandos
	push_operando(TAG_INTEGER, array->info.array_byte[index], pilha_frames->first->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void caload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

	// Recupera o índice do char dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (caload)\n");
		return;
	}

	push_operando(TAG_INTEGER, array->info.array_char[index], pilha_frames->first->operand_stack);


	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void saload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

	// Recupera o índice do short dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (saload)\n");
		return;
	}

	push_operando(TAG_INTEGER, array->info.array_short[index], pilha_frames->first->operand_stack);


	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void istore(stack_frames *pilha_frames) {
    u4 index = 0;
    t_operand *temp_operando = NULL;

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

    if (wide_) {
        pilha_frames->first->pc++;
        index = index << 8;
        index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        wide_ = 0;
    }

    temp_operando = pop_operando(pilha_frames->first->operand_stack);

    pilha_frames->first->array_variaveis_locais[index] = temp_operando->data;

    free(temp_operando);
}

void lstore(stack_frames *pilha_frames) {
    u4 index = 0, low_bytes = 0, high_bytes = 0;
    t_operand *temp_operando = NULL;

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

    if (wide_) {
        index = index << 8;
        index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        pilha_frames->first->pc++;
        wide_ = 0;
    }

    // desempilha o low byte da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = temp_operando->data;

    // desempilha o high byte da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = temp_operando->data;

    pilha_frames->first->array_variaveis_locais[index] = high_bytes;
    pilha_frames->first->array_variaveis_locais[index + 1] = low_bytes;

    free(temp_operando);
}

void fstore(stack_frames *pilha_frames) {
    u4 index = 0;
    t_operand *temp_operando = NULL;

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

    if (wide_) {
        index = index << 8;
        index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        pilha_frames->first->pc++;
        wide_ = 0;
    }

    temp_operando = pop_operando(pilha_frames->first->operand_stack);

    pilha_frames->first->array_variaveis_locais[index] = temp_operando->data;

    free(temp_operando);
}

void dstore(stack_frames *pilha_frames) {
    u4 index = 0, low_bytes = 0, high_bytes = 0;
    t_operand *temp_operando = NULL;

	index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

	if (wide_) {
		index = index << 8;
		index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        pilha_frames->first->pc++;
		wide_ = 0;
	}

    // desempilha o low byte da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = temp_operando->data;

    // desempilha o high byte da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = temp_operando->data;

	pilha_frames->first->array_variaveis_locais[index] = high_bytes;
    pilha_frames->first->array_variaveis_locais[index + 1] = low_bytes;

    free(temp_operando);
}

void astore(stack_frames *pilha_frames) {
    u4 index = 0;
    t_operand *temp_operando = NULL;

	index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

	if (wide_) {
		index = index << 8;
		index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        pilha_frames->first->pc++;
		wide_ = 0;
	}

    temp_operando = pop_operando(pilha_frames->first->operand_stack);

	pilha_frames->first->array_variaveis_locais[index] = temp_operando->data;

    free(temp_operando);
}

void istore_0(stack_frames *pilha_frames) {
    u4 value = 0;
    t_operand *temp_operando = NULL;

    // recupera um int da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    value = temp_operando->data;

    // guarda no array de variáveis locais um int na posição 0
    pilha_frames->first->array_variaveis_locais[0] = value;

    free(temp_operando);
}

void istore_1(stack_frames *pilha_frames) {
    u4 value = 0;
    t_operand *temp_operando = NULL;

    // recupera um int da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    value = temp_operando->data;

    // guarda no array de variáveis locais um int na posição 1
    pilha_frames->first->array_variaveis_locais[1] = value;

    free(temp_operando);
}

void istore_2(stack_frames *pilha_frames) {
    u4 value = 0;
    t_operand *temp_operando = NULL;

    // recupera um int da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    value = temp_operando->data;

    // guarda no array de variáveis locais um int na posição 2
    pilha_frames->first->array_variaveis_locais[2] = value;

    free(temp_operando);
}

void istore_3(stack_frames *pilha_frames) {
    u4 value = 0;
    t_operand *temp_operando = NULL;

    // recupera um int da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    value = temp_operando->data;

    // guarda no array de variáveis locais um int na posição 3
    pilha_frames->first->array_variaveis_locais[3] = value;

    free(temp_operando);
}

void lstore_0(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;
    t_operand *temp_operando = NULL;

    // recupera os low bytes de um double da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = temp_operando->data;

    // recupera os high bytes de um double da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = temp_operando->data;

    // guarda no array de variáveis locais um long, big endian
    pilha_frames->first->array_variaveis_locais[0] = high_bytes;
    pilha_frames->first->array_variaveis_locais[1] = low_bytes;

    free(temp_operando);
}

void lstore_1(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;
    t_operand *temp_operando = NULL;

    // recupera os low bytes de um double da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = temp_operando->data;

    // recupera os high bytes de um double da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = temp_operando->data;

    // guarda no array de variáveis locais um long, big endian
    pilha_frames->first->array_variaveis_locais[1] = high_bytes;
    pilha_frames->first->array_variaveis_locais[2] = low_bytes;

    free(temp_operando);
}

void lstore_2(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;
    t_operand *temp_operando = NULL;

    // recupera os low bytes de um double da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = temp_operando->data;

    // recupera os high bytes de um double da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = temp_operando->data;

    // guarda no array de variáveis locais um long, big endian
    pilha_frames->first->array_variaveis_locais[2] = high_bytes;
    pilha_frames->first->array_variaveis_locais[3] = low_bytes;

    free(temp_operando);
}

void lstore_3(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;
    t_operand *temp_operando = NULL;

    // recupera os low bytes de um double da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = temp_operando->data;

    // recupera os high bytes de um double da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = temp_operando->data;

    // guarda no array de variáveis locais um long, big endian
    pilha_frames->first->array_variaveis_locais[3] = high_bytes;
    pilha_frames->first->array_variaveis_locais[4] = low_bytes;

    free(temp_operando);
}

void fstore_0(stack_frames *pilha_frames) {
  u4 value = 0;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  value = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[0] = value;

  free(temp_operando);
}

void fstore_1(stack_frames *pilha_frames) {
  u4 value = 0;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  value = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[1] = value;

  free(temp_operando);

}

void fstore_2(stack_frames *pilha_frames) {
  u4 value = 0;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  value = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[2] = value;

  free(temp_operando);

}

void fstore_3(stack_frames *pilha_frames) {
  u4 value = 0;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  value = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[3] = value;

  free(temp_operando);

}

void dstore_0(stack_frames *pilha_frames) {
  u4 high_bytes = 0, low_bytes = 0;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  low_bytes = temp_operando->data;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  high_bytes = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[0] = high_bytes;
  pilha_frames->first->array_variaveis_locais[1] = low_bytes;

  free(temp_operando);

}

void dstore_1(stack_frames *pilha_frames) {
  u4 high_bytes = 0, low_bytes = 0;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  low_bytes = temp_operando->data;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  high_bytes = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[1] = high_bytes;
  pilha_frames->first->array_variaveis_locais[2] = low_bytes;

  free(temp_operando);
}

void dstore_2(stack_frames *pilha_frames) {
  u4 high_bytes = 0, low_bytes = 0;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  low_bytes = temp_operando->data;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  high_bytes = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[2] = high_bytes;
  pilha_frames->first->array_variaveis_locais[3] = low_bytes;

  free(temp_operando);
}

void dstore_3(stack_frames *pilha_frames) {
  u4 high_bytes = 0, low_bytes = 0;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  low_bytes = temp_operando->data;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  high_bytes = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[3] = high_bytes;
  pilha_frames->first->array_variaveis_locais[4] = low_bytes;

  free(temp_operando);
}

void astore_0(stack_frames *pilha_frames) {
  u4 data;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  data = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[0] = data;

  free(temp_operando);

}

void astore_1(stack_frames *pilha_frames) {
  u4 data;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  data = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[1] = data;

  free(temp_operando);
}

void astore_2(stack_frames *pilha_frames) {
  u4 data;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  data = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[2] = data;

  free(temp_operando);
}

void astore_3(stack_frames *pilha_frames) {
  u4 data;
  t_operand *temp_operando = NULL;

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  data = temp_operando->data;

  pilha_frames->first->array_variaveis_locais[3] = data;

  free(temp_operando);

}

void iastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index, value;
	t_array *array = NULL;

	// Recupera o int a ser salvo
	t_operand *operando_value = pop_operando(frame->operand_stack);
	value = operando_value->data;

	// Recupera o índice onde o int será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o int será salvo
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
	// Salva o int na posição index do array de int
	array->info.array_int[index] = value;


	// Empilha endereço do array novamente para a próxima instrução
	push_operando(TAG_ARRAY_REF,operando_endereco->data,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_value);
	free(operando_endereco);
}

void lastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	long value;
	t_array *array = NULL;

	// Recupera o long a ser salvo
	t_operand *operando_low = pop_operando(frame->operand_stack);
	t_operand *operando_high = pop_operando(frame->operand_stack);

	value = u8_to_long(operando_low->data,operando_high->data);

	// Recupera o índice onde o long será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o long será salvo
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
	array->info.array_long[index] = value;


	// Empilha endereço do array novamente para a próxima instrução
	push_operando(TAG_ARRAY_REF,operando_endereco->data,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_low);
	free(operando_high);
	free(operando_endereco);
}
