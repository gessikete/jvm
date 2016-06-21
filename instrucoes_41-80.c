#include "instrucoes_41-80.h"

/*
    Instrução dload_3: pega um double no array de variáveis locais com índice 3 e 4 e empilha na pilha de operandos

    Parametros:
        stack_frames *pilha_frames: ponteiro para a pilha de frames
*/
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
    array *array_ref = NULL;
    u4 element_index = 0, array_index = 0;
    t_operand *temp_operando = NULL;

    // recupera o índex do elemento
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
	element_index = temp_operando->data;

    // recupera o índex o array
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
    array_index = temp_operando->data;

    array_ref = recupera_array_index(pilha_frames->first->lista_arrays, array_index);

    if (array_ref == NULL) {
        printf("\n\nNullPointerException (iaload)\n");
        return;
    }

    push_operando(TAG_INTEGER, array_ref->info.array_int[element_index], pilha_frames->first->operand_stack);

    free(temp_operando);
}



void laload(stack_frames *pilha_frames) {
    array *array_ref = NULL;
    u4 element_index = 0, array_index = 0;
    u8 *value_long = 0;
    t_operand *temp_operando = NULL;

    // recupera o índex do elemento
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
	element_index = temp_operando->data;

    // recupera o índex o array
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
    array_index = temp_operando->data;

    array_ref = recupera_array_index(pilha_frames->first->lista_arrays, array_index);

    if (array_ref == NULL) {
        printf("\n\nNullPointerException (laload)\n");
        return;
    }

    value_long = malloc(sizeof(u8));
    memcpy(value_long, &(array_ref->info.array_long[element_index]), sizeof(u8));
    push_operando(TAG_LONG, *value_long >> 32, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, *value_long & 0xffffffff, pilha_frames->first->operand_stack);

    free(temp_operando);
}



void faload(stack_frames *pilha_frames) {
    array *array_ref = NULL;
    u4 element_index = 0, array_index = 0;
    u4 *value_float = 0;
    t_operand *temp_operando = NULL;

    // recupera o índex do elemento
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
	element_index = temp_operando->data;

    // recupera o índex o array
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
    array_index = temp_operando->data;

    array_ref = recupera_array_index(pilha_frames->first->lista_arrays, array_index);

    if (array_ref == NULL) {
        printf("\n\nNullPointerException (faload)\n");
        return;
    }

    value_float = malloc(sizeof(u4));
    memcpy(value_float, &(array_ref->info.array_float[element_index]), sizeof(u4));
    push_operando(TAG_FLOAT, *value_float, pilha_frames->first->operand_stack);

    free(temp_operando);
}



void daload(stack_frames *pilha_frames) {
    array *array_ref = NULL;
    u4 element_index = 0, array_index = 0;
    u8 *value_double = 0;
    t_operand *temp_operando = NULL;

    // recupera o índex do elemento
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
	element_index = temp_operando->data;

    // recupera o índex o array
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
    array_index = temp_operando->data;

    array_ref = recupera_array_index(pilha_frames->first->lista_arrays, array_index);

    if (array_ref == NULL) {
        printf("\n\nNullPointerException (daload)\n");
        return;
    }

    value_double = malloc(sizeof(u8));
    memcpy(value_double, &(array_ref->info.array_double[element_index]), sizeof(u8));
    push_operando(TAG_DOUBLE, *value_double >> 32, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, *value_double & 0xffffffff, pilha_frames->first->operand_stack);

    free(temp_operando);
}



void aaload(stack_frames *pilha_frames) {
    array *array_ref = NULL;
    u4 element_index = 0, array_index = 0;
    t_operand *temp_operando = NULL;

    // recupera o índex do elemento
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
	element_index = temp_operando->data;

    // recupera o índex o array
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
    array_index = temp_operando->data;

    array_ref = recupera_array_index(pilha_frames->first->lista_arrays, array_index);

	if (array_ref == NULL) {
		printf("\n\nNullPointerException (aaload)\n");
		return;
	}

    // TODO
	// push_operando(array_ref->info.array_array[element_index], pilha_frames->first->operand_stack);
    printf("OPS! push não implementado. Sorry.\n");

    free(temp_operando);
}



void baload(stack_frames *pilha_frames) {
    array *array_ref = NULL;
    u4 element_index = 0, array_index = 0;
    signed signed_value = 0;
    t_operand *temp_operando = NULL;

    // recupera o índex do elemento
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
	element_index = temp_operando->data;

    // recupera o índex o array
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
    array_index = temp_operando->data;

    array_ref = recupera_array_index(pilha_frames->first->lista_arrays, array_index);

	if (array_ref == NULL) {
		printf("\n\nNullPointerException (baload)\n");
		return;
	}

    signed_value = (signed) array_ref->info.array_byte[element_index];
	push_operando(TAG_INTEGER, signed_value, pilha_frames->first->operand_stack);

    free(temp_operando);
}



void caload(stack_frames *pilha_frames) {
    array *array_ref = NULL;
    u4 element_index = 0, array_index = 0;
    t_operand *temp_operando = NULL;

    // recupera o índex do elemento
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
	element_index = temp_operando->data;

    // recupera o índex o array
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
    array_index = temp_operando->data;

    array_ref = recupera_array_index(pilha_frames->first->lista_arrays, array_index);

	if (array_ref == NULL) {
		printf("\n\nNullPointerException (caload)\n");
		return;
	}

	push_operando(TAG_INTEGER, array_ref->info.array_char[element_index], pilha_frames->first->operand_stack);

    free(temp_operando);
}



void saload(stack_frames *pilha_frames) {
    array *array_ref = NULL;
    u4 element_index = 0, array_index = 0;
    t_operand *temp_operando = NULL;

    // recupera o índex do elemento
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
	element_index = temp_operando->data;

    // recupera o índex o array
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
    array_index = temp_operando->data;

    array_ref = recupera_array_index(pilha_frames->first->lista_arrays, array_index);

	if (array_ref == NULL) {
		printf("\n\nNullPointerException (saload)\n");
		return;
	}

	push_operando(TAG_INTEGER, array_ref->info.array_short[element_index], pilha_frames->first->operand_stack);

    free(temp_operando);
}



void istore(stack_frames *pilha_frames) {
    u4 index = 0;
    t_operand *temp_operando = NULL;

    pilha_frames->first->pc++;

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];

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

    pilha_frames->first->pc++;

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];

    if (wide_) {
        pilha_frames->first->pc++;
        index = index << 8;
        index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
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

    pilha_frames->first->pc++;

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];

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



void dstore(stack_frames *pilha_frames) {
    u4 index = 0, low_bytes = 0, high_bytes = 0;
    t_operand *temp_operando = NULL;

	pilha_frames->first->pc++;

	index = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	if (wide_) {
		pilha_frames->first->pc++;
		index = index << 8;
		index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
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

	pilha_frames->first->pc++;

	index = pilha_frames->first->code_info->code[pilha_frames->first->pc];

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

}



void fstore_1(stack_frames *pilha_frames) {

}



void fstore_2(stack_frames *pilha_frames) {

}



void fstore_3(stack_frames *pilha_frames) {

}



void dstore_0(stack_frames *pilha_frames) {

}



void dstore_1(stack_frames *pilha_frames) {

}



void dstore_2(stack_frames *pilha_frames) {

}



void dstore_3(stack_frames *pilha_frames) {

}



void astore_0(stack_frames *pilha_frames) {

}



void astore_1(stack_frames *pilha_frames) {

}



void astore_2(stack_frames *pilha_frames) {

}



void astore_3(stack_frames *pilha_frames) {

}



void iastore(stack_frames *pilha_frames) {

}



void lastore(stack_frames *pilha_frames) {

}
