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

	#ifdef DEBUG
        printf("Instrução dload_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", u8_to_double(low_bytes, high_bytes));
    #endif

    // empilha big endian
    push_operando(TAG_DOUBLE, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, low_bytes, pilha_frames->first->operand_stack);
}

void aload_0(stack_frames *pilha_frames) {
    // recupera o valor na posição 0 do array de variávies locais
    u4 value = pilha_frames->first->array_variaveis_locais[0];

	#ifdef DEBUG
        printf("Instrução aload_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
		printf("Empilhado: %x\n", value);
    #endif

    // empilha o valor na pilha de operandos
    push_operando(TAG_OBJECT_REF, value, pilha_frames->first->operand_stack);
}

void aload_1(stack_frames *pilha_frames) {
    // recupera o valor na posição 0 do array de variávies locais
    u4 value = pilha_frames->first->array_variaveis_locais[1];

	#ifdef DEBUG
        printf("Instrução aload_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
		printf("Empilhado: %x\n", value);
    #endif

    // empilha o valor na pilha de operandos
    push_operando(TAG_OBJECT_REF, value, pilha_frames->first->operand_stack);
}

void aload_2(stack_frames *pilha_frames) {
    // recupera o valor na posição 0 do array de variávies locais
    u4 value = pilha_frames->first->array_variaveis_locais[2];

	#ifdef DEBUG
        printf("Instrução aload_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
		printf("Empilhado: %x\n", value);
    #endif

    // empilha o valor na pilha de operandos
    push_operando(TAG_OBJECT_REF, value, pilha_frames->first->operand_stack);
}

void aload_3(stack_frames *pilha_frames) {
    // recupera o valor na posição 0 do array de variávies locais
    u4 value = pilha_frames->first->array_variaveis_locais[3];

	#ifdef DEBUG
        printf("Instrução aload_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
		printf("Empilhado: %x\n", value);
    #endif

    // empilha o valor na pilha de operandos
    push_operando(TAG_OBJECT_REF, value, pilha_frames->first->operand_stack);
}

void iaload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução iaload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o índice do int dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado index: %x\n", index);
        printf("Desempilhado endereço: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (iaload)\n");
        excecao = true;
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){ // verifica se houve uma exceção
    	// Empilha valor na pilha de operandos
    	push_operando(TAG_INTEGER, array->array_data[index], pilha_frames->first->operand_stack);

        #ifdef DEBUG
            printf("Empilhado int: %d\n", (int32_t)array->array_data[index]);
        #endif
    }

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void laload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução laload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o índice do long dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado index: %x\n", index);
        printf("Desempilhado endereço: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (laload)\n");
        excecao = true;
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){
    	// Empilha valor na pilha de operandos
        // High bit
    	push_operando(TAG_LONG, array->array_data[index]>>32, pilha_frames->first->operand_stack);
        // Low bit
    	push_operando(TAG_LONG, array->array_data[index], pilha_frames->first->operand_stack);

        #ifdef DEBUG
            printf("Empilhado long: %lli\n", array->array_data[index]);
        #endif
    }

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void faload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução faload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o índice do float dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado index: %x\n", index);
        printf("Desempilhado endereço: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (faload)\n");
        excecao = true;
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){
    	// Empilha valor na pilha de operandos
    	push_operando(TAG_FLOAT, array->array_data[index], pilha_frames->first->operand_stack);

        #ifdef DEBUG
            printf("Empilhado float: %f\n", u4_to_float(array->array_data[index]));
        #endif
    }

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void daload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução daload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o índice do double dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado index: %x\n", index);
        printf("Desempilhado endereço: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (daload)\n");
		excecao = true;
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
		excecao = true;
		return;
	}

    if(!excecao){
    	// Empilha valor na pilha de operandos
    	push_operando(TAG_DOUBLE, array->array_data[index]>>32, pilha_frames->first->operand_stack);
    	push_operando(TAG_DOUBLE, array->array_data[index], pilha_frames->first->operand_stack);

        #ifdef DEBUG
            printf("Empilhado double: %f\n", u8_to_double(array->array_data[index],array->array_data[index]>>32));
        #endif
    }

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void aaload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução aaload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o índice do subarray dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado index: %x\n", index);
        printf("Desempilhado endereço: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (aaload)\n");
        excecao = true;
		return;
	}

	if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){
    	// Empilha endereco do subarray na pilha de operandos
    	push_operando(TAG_ARRAY_REF, array->array_data[index], pilha_frames->first->operand_stack);

        #ifdef DEBUG
            printf("Empilhado endereço do array: 0x%llx\n", array->array_data[index]);
        #endif
    }


	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void baload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução baload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o índice do byte dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado index: %x\n", index);
        printf("Desempilhado endereço: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (baload)\n");
        excecao = true;
		return;
	}

    if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){
    	// Empilha valor na pilha de operandos
    	push_operando(TAG_INTEGER, array->array_data[index], pilha_frames->first->operand_stack);

        #ifdef DEBUG
            printf("Empilhado endereço do array: 0x%llx\n", array->array_data[index]);
        #endif
    }

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void caload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução caload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o índice do char dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado index: %x\n", index);
        printf("Desempilhado endereço: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (caload)\n");
        excecao = true;
		return;
	}

    if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){
        push_operando(TAG_INTEGER, array->array_data[index], pilha_frames->first->operand_stack);

        #ifdef DEBUG
            printf("Empilhado endereço do array: 0x%llx\n", array->array_data[index]);
        #endif
    }


	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void saload(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução saload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o índice do short dentro do array
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado index: %x\n", index);
        printf("Desempilhado endereço: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\n\nNullPointerException (saload)\n");
        excecao = true;
		return;
	}

    if(index>=array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){
        push_operando(TAG_INTEGER, array->array_data[index], pilha_frames->first->operand_stack);

        #ifdef DEBUG
            printf("Empilhado endereço do array: 0x%llx\n", array->array_data[index]);
        #endif
    }


	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_endereco);
}

void istore(stack_frames *pilha_frames) {
    u4 index = 0;
    t_operand *temp_operando = NULL;

    #ifdef DEBUG
        printf("Instrução istore: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

    if (wide_) {
        pilha_frames->first->pc++;
        index = index << 8;
        index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        wide_ = 0;
    }

    temp_operando = pop_operando(pilha_frames->first->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado int: %d\n", temp_operando->data);
    #endif

    pilha_frames->first->array_variaveis_locais[index] = temp_operando->data;

    free(temp_operando);
}

void lstore(stack_frames *pilha_frames) {
    u4 index = 0, low_bytes = 0, high_bytes = 0;

    #ifdef DEBUG
        printf("Instrução lstore: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

    if (wide_) {
        index = index << 8;
        index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        pilha_frames->first->pc++;
        wide_ = 0;
    }

    // desempilha o low byte da pilha de operandos
    t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = operando_low->data;

    // desempilha o high byte da pilha de operandos
    t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = operando_high->data;

    #ifdef DEBUG
        printf("Desempilhado long: %lu\n", u8_to_long(low_bytes, high_bytes));
    #endif

    pilha_frames->first->array_variaveis_locais[index] = high_bytes;
    pilha_frames->first->array_variaveis_locais[index + 1] = low_bytes;

    free(operando_low);
    free(operando_high);
}

void fstore(stack_frames *pilha_frames) {
    u4 index = 0;
    t_operand *temp_operando = NULL;

    #ifdef DEBUG
        printf("Instrução fstore: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

    if (wide_) {
        index = index << 8;
        index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        pilha_frames->first->pc++;
        wide_ = 0;
    }

    temp_operando = pop_operando(pilha_frames->first->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado float: %f\n", u4_to_float(temp_operando->data));
    #endif

    pilha_frames->first->array_variaveis_locais[index] = temp_operando->data;

    free(temp_operando);
}

void dstore(stack_frames *pilha_frames) {
    u4 index = 0, low_bytes = 0, high_bytes = 0;

    #ifdef DEBUG
        printf("Instrução dstore: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

	if (wide_) {
		index = index << 8;
		index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        pilha_frames->first->pc++;
		wide_ = 0;
	}

    // desempilha o low byte da pilha de operandos
    t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = operando_low->data;

    // desempilha o high byte da pilha de operandos
    t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = operando_high->data;

    #ifdef DEBUG
        printf("Desempilhado double: %f\n", u8_to_double(low_bytes, high_bytes));
    #endif

	pilha_frames->first->array_variaveis_locais[index] = high_bytes;
    pilha_frames->first->array_variaveis_locais[index + 1] = low_bytes;

    free(operando_low);
    free(operando_high);
}

void astore(stack_frames *pilha_frames) {
    u4 index = 0;
    t_operand *temp_operando = NULL;

    #ifdef DEBUG
        printf("Instrução astore: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	index = pilha_frames->first->code_info->code[pilha_frames->first->pc];
    pilha_frames->first->pc++;

	if (wide_) {
		index = index << 8;
		index |= pilha_frames->first->code_info->code[pilha_frames->first->pc];
        pilha_frames->first->pc++;
		wide_ = 0;
	}

    temp_operando = pop_operando(pilha_frames->first->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado endereço do array: %x\n", temp_operando->data);
    #endif

	pilha_frames->first->array_variaveis_locais[index] = temp_operando->data;

    free(temp_operando);
}

void istore_0(stack_frames *pilha_frames) {
    u4 value = 0;
    t_operand *temp_operando = NULL;

    #ifdef DEBUG
        printf("Instrução istore_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    // recupera um int da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    value = temp_operando->data;

    #ifdef DEBUG
        printf("Desempilhado operando: %d\n", value);
    #endif

    // guarda no array de variáveis locais um int na posição 0
    pilha_frames->first->array_variaveis_locais[0] = value;

    free(temp_operando);
}

void istore_1(stack_frames *pilha_frames) {
    u4 value = 0;
    t_operand *temp_operando = NULL;

    #ifdef DEBUG
        printf("Instrução istore_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    // recupera um int da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    value = temp_operando->data;

    #ifdef DEBUG
        printf("Desempilhado int: %d\n", value);
    #endif

    // guarda no array de variáveis locais um int na posição 1
    pilha_frames->first->array_variaveis_locais[1] = value;

    free(temp_operando);
}

void istore_2(stack_frames *pilha_frames) {
    u4 value = 0;
    t_operand *temp_operando = NULL;

    #ifdef DEBUG
        printf("Instrução istore_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    // recupera um int da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    value = temp_operando->data;

    #ifdef DEBUG
        printf("Desempilhado int: %d\n", value);
    #endif

    // guarda no array de variáveis locais um int na posição 2
    pilha_frames->first->array_variaveis_locais[2] = value;

    free(temp_operando);
}

void istore_3(stack_frames *pilha_frames) {
    u4 value = 0;
    t_operand *temp_operando = NULL;

    #ifdef DEBUG
        printf("Instrução istore_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    // recupera um int da pilha de operandos
    temp_operando = pop_operando(pilha_frames->first->operand_stack);
    value = temp_operando->data;

    #ifdef DEBUG
        printf("Desempilhado int: %d\n", value);
    #endif

    // guarda no array de variáveis locais um int na posição 3
    pilha_frames->first->array_variaveis_locais[3] = value;

    free(temp_operando);
}

void lstore_0(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    #ifdef DEBUG
        printf("Instrução lstore_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    // recupera os low bytes de um double da pilha de operandos
    t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = operando_low->data;

    // recupera os high bytes de um double da pilha de operandos
    t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = operando_high->data;

    #ifdef DEBUG
        printf("Desempilhado long: %li\n", u8_to_long(low_bytes, high_bytes));
    #endif

    // guarda no array de variáveis locais um long, big endian
    pilha_frames->first->array_variaveis_locais[0] = high_bytes;
    pilha_frames->first->array_variaveis_locais[1] = low_bytes;

    free(operando_low);
    free(operando_high);
}

void lstore_1(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    #ifdef DEBUG
        printf("Instrução lstore_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    // recupera os low bytes de um double da pilha de operandos
    t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = operando_low->data;

    // recupera os high bytes de um double da pilha de operandos
    t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = operando_high->data;

    #ifdef DEBUG
        printf("Desempilhado long: %lu\n", u8_to_long(low_bytes, high_bytes));
    #endif

    // guarda no array de variáveis locais um long, big endian
    pilha_frames->first->array_variaveis_locais[1] = high_bytes;
    pilha_frames->first->array_variaveis_locais[2] = low_bytes;

    free(operando_low);
    free(operando_high);
}

void lstore_2(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    #ifdef DEBUG
        printf("Instrução lstore_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    // recupera os low bytes de um double da pilha de operandos
    t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = operando_low->data;

    // recupera os high bytes de um double da pilha de operandos
    t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = operando_high->data;

    #ifdef DEBUG
        printf("Desempilhado long: %lu\n", u8_to_long(low_bytes, high_bytes));
    #endif

    // guarda no array de variáveis locais um long, big endian
    pilha_frames->first->array_variaveis_locais[2] = high_bytes;
    pilha_frames->first->array_variaveis_locais[3] = low_bytes;

    free(operando_low);
    free(operando_high);
}

void lstore_3(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    #ifdef DEBUG
        printf("Instrução lstore_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    // recupera os low bytes de um double da pilha de operandos
    t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
    low_bytes = operando_low->data;

    // recupera os high bytes de um double da pilha de operandos
    t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
    high_bytes = operando_high->data;

    #ifdef DEBUG
        printf("Desempilhado long: %lu\n", u8_to_long(low_bytes, high_bytes));
    #endif

    // guarda no array de variáveis locais um long, big endian
    pilha_frames->first->array_variaveis_locais[3] = high_bytes;
    pilha_frames->first->array_variaveis_locais[4] = low_bytes;

    free(operando_low);
    free(operando_high);
}

void fstore_0(stack_frames *pilha_frames) {
  u4 value = 0;
  t_operand *temp_operando = NULL;

  #ifdef DEBUG
      printf("Instrução fstore_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  value = temp_operando->data;

  #ifdef DEBUG
      printf("Desempilhado float: %f\n", u4_to_float(value));
  #endif

  pilha_frames->first->array_variaveis_locais[0] = value;

  free(temp_operando);
}

void fstore_1(stack_frames *pilha_frames) {
  u4 value = 0;
  t_operand *temp_operando = NULL;

  #ifdef DEBUG
      printf("Instrução fstore_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  value = temp_operando->data;

  #ifdef DEBUG
      printf("Desempilhado float: %f\n", u4_to_float(value));
  #endif

  pilha_frames->first->array_variaveis_locais[1] = value;

  free(temp_operando);

}

void fstore_2(stack_frames *pilha_frames) {
  u4 value = 0;
  t_operand *temp_operando = NULL;

  #ifdef DEBUG
      printf("Instrução fstore_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  value = temp_operando->data;

  #ifdef DEBUG
      printf("Desempilhado float: %f\n", u4_to_float(value));
  #endif

  pilha_frames->first->array_variaveis_locais[2] = value;

  free(temp_operando);

}

void fstore_3(stack_frames *pilha_frames) {
  u4 value = 0;
  t_operand *temp_operando = NULL;

  #ifdef DEBUG
      printf("Instrução fstore_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  value = temp_operando->data;

  #ifdef DEBUG
      printf("Desempilhado float: %f\n", u4_to_float(value));
  #endif

  pilha_frames->first->array_variaveis_locais[3] = value;

  free(temp_operando);

}

void dstore_0(stack_frames *pilha_frames) {
  u4 high_bytes = 0, low_bytes = 0;

  #ifdef DEBUG
      printf("Instrução dstore_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  // recupera os low bytes de um double da pilha de operandos
  t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
  low_bytes = operando_low->data;

  // recupera os high bytes de um double da pilha de operandos
  t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
  high_bytes = operando_high->data;

  #ifdef DEBUG
      printf("Desempilhado double: %f\n", u8_to_double(low_bytes, high_bytes));
  #endif

  pilha_frames->first->array_variaveis_locais[0] = high_bytes;
  pilha_frames->first->array_variaveis_locais[1] = low_bytes;

  free(operando_low);
  free(operando_high);

}

void dstore_1(stack_frames *pilha_frames) {
  u4 high_bytes = 0, low_bytes = 0;

  #ifdef DEBUG
      printf("Instrução dstore_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  // recupera os low bytes de um double da pilha de operandos
  t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
  low_bytes = operando_low->data;

  // recupera os high bytes de um double da pilha de operandos
  t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
  high_bytes = operando_high->data;

  #ifdef DEBUG
      printf("Desempilhado double: %f\n", u8_to_double(low_bytes, high_bytes));
  #endif

  pilha_frames->first->array_variaveis_locais[1] = high_bytes;
  pilha_frames->first->array_variaveis_locais[2] = low_bytes;

  free(operando_low);
  free(operando_high);
}

void dstore_2(stack_frames *pilha_frames) {
  u4 high_bytes = 0, low_bytes = 0;

  #ifdef DEBUG
      printf("Instrução dstore_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  // recupera os low bytes de um double da pilha de operandos
  t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
  low_bytes = operando_low->data;

  // recupera os high bytes de um double da pilha de operandos
  t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
  high_bytes = operando_high->data;

  #ifdef DEBUG
      printf("Desempilhado double: %f\n", u8_to_double(low_bytes, high_bytes));
  #endif

  pilha_frames->first->array_variaveis_locais[2] = high_bytes;
  pilha_frames->first->array_variaveis_locais[3] = low_bytes;

  free(operando_low);
  free(operando_high);
}

void dstore_3(stack_frames *pilha_frames) {
  u4 high_bytes = 0, low_bytes = 0;

  #ifdef DEBUG
      printf("Instrução dstore_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  // recupera os low bytes de um double da pilha de operandos
  t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
  low_bytes = operando_low->data;

  // recupera os high bytes de um double da pilha de operandos
  t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
  high_bytes = operando_high->data;

  #ifdef DEBUG
      printf("Desempilhado double: %f\n", u8_to_double(low_bytes, high_bytes));
  #endif

  pilha_frames->first->array_variaveis_locais[3] = high_bytes;
  pilha_frames->first->array_variaveis_locais[4] = low_bytes;

  free(operando_low);
  free(operando_high);
}

void astore_0(stack_frames *pilha_frames) {
  u4 data;
  t_operand *temp_operando = NULL;

  #ifdef DEBUG
      printf("Instrução astore_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  data = temp_operando->data;

  #ifdef DEBUG
      printf("Desempilhado endereço do array: %x\n", data);
  #endif

  pilha_frames->first->array_variaveis_locais[0] = data;

  free(temp_operando);

}

void astore_1(stack_frames *pilha_frames) {
  u4 data;
  t_operand *temp_operando = NULL;

  #ifdef DEBUG
      printf("Instrução astore_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  data = temp_operando->data;

  #ifdef DEBUG
      printf("Desempilhado endereço do array: %x\n", data);
  #endif

  pilha_frames->first->array_variaveis_locais[1] = data;

  free(temp_operando);
}

void astore_2(stack_frames *pilha_frames) {
  u4 data;
  t_operand *temp_operando = NULL;

  #ifdef DEBUG
      printf("Instrução astore_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  data = temp_operando->data;

  #ifdef DEBUG
      printf("Desempilhado endereço do array: %x\n", data);
  #endif

  pilha_frames->first->array_variaveis_locais[2] = data;

  free(temp_operando);
}

void astore_3(stack_frames *pilha_frames) {
  u4 data;
  t_operand *temp_operando = NULL;

  #ifdef DEBUG
      printf("Instrução astore_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
  #endif

  temp_operando = pop_operando(pilha_frames->first->operand_stack);
  data = temp_operando->data;

  #ifdef DEBUG
      printf("Desempilhado endereço do array: %x\n", data);
  #endif

  pilha_frames->first->array_variaveis_locais[3] = data;

  free(temp_operando);

}

void iastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index, value;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução iastore: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o int a ser salvo
	t_operand *operando_value = pop_operando(frame->operand_stack);
	value = operando_value->data;

	// Recupera o índice onde o int será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o int será salvo
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado int: %d\n", value);
        printf("Desempilhado index: %d\n", index);
        printf("Desempilhado endereço do array: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\nNull Pointer Exception\n");
        excecao = true;
		return;
	}

	if(index >= array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){
        // Salva o int na posição index do array de int
        array->array_data[index] = value;

        #ifdef DEBUG
            printf("Empilhado endereço do array: 0x%d\n", operando_endereco->data);
        #endif
    }

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_value);
	free(operando_endereco);
}

void lastore(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u4 index;
	t_array *array = NULL;

    #ifdef DEBUG
        printf("Instrução lastore: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

	// Recupera o long a ser salvo
	t_operand *operando_low = pop_operando(frame->operand_stack);
	t_operand *operando_high = pop_operando(frame->operand_stack);

	// Recupera o índice onde o long será salvo
	t_operand *operando_index = pop_operando(frame->operand_stack);
	index = operando_index->data;

	// Recupera o endereço do array onde o long será salvo
	t_operand *operando_endereco = pop_operando(frame->operand_stack);

    #ifdef DEBUG
        printf("Desempilhado long: %li\n", u8_to_long(operando_low->data,operando_high->data));
        printf("Desempilhado index: %d\n", index);
        printf("Desempilhado endereço do array: %x\n", operando_endereco->data);
    #endif

	array = (t_array*)(operando_endereco->data);

	if (array == NULL) {
		printf("\nNull Pointer Exception\n");
        excecao = true;
		return;
	}

	if(index >= array->tamanho) {
		printf("\n\nArrayIndexOutOfBoundsException: %d\n",index);
        excecao = true;
		return;
	}

    if(!excecao){
    	// Salva o char na posição index do array de chars
    	array->array_data[index] = (((u8)operando_high->data)<<32)|(operando_low->data);

        #ifdef DEBUG
            printf("Empilhado endereço do array: 0x%x\n", operando_endereco->data);
        #endif
    }

	// Desaloca operandos que foram desempilhados
	free(operando_index);
	free(operando_low);
	free(operando_high);
	free(operando_endereco);
}
