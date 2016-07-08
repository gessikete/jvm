/*!
   \file instrucoes_0-40.c
   \brief Instruções da Máquina Virtual Java.

   Módulo responsável por parte das instruções que definem as operações a serem
   executadas pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#include "instrucoes_0-40.h"

void nop(stack_frames *pilha_frames) {
    #ifdef DEBUG
        printf("Instrução nop: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif
	return;
}

void aconst_null(stack_frames *pilha_frames) {
    u4 operando = 0;

    #ifdef DEBUG
        printf("Instrução aconst_null: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", operando);
    #endif
    // adiciona o operando a pilha
    push_operando(TAG_NULL, operando, pilha_frames->first->operand_stack);
}

void iconst_m1(stack_frames *pilha_frames) {
    //declarando o operando
    int32_t operando = -1;
 
    #ifdef DEBUG
        printf("Instrução iconst_m1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", operando);
    #endif

    //salva valor na pilha de operandos
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}

void iconst_0(stack_frames *pilha_frames) {
    //declara operando
    u4 operando = 0;

    #ifdef DEBUG
        printf("Instrução iconst_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", operando);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}

void iconst_1(stack_frames *pilha_frames) {
    //declara operando
    u4 operando = 1;

    #ifdef DEBUG
        printf("Instrução iconst_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", operando);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}

void iconst_2(stack_frames *pilha_frames) {
    //declara operando
    u4 operando = 2;

    #ifdef DEBUG
        printf("Instrução iconst_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", operando);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}

void iconst_3(stack_frames *pilha_frames) {
    //declara operando
    u4 operando = 3;

    #ifdef DEBUG
        printf("Instrução iconst_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", operando);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}

void iconst_4(stack_frames *pilha_frames) {
    //declara operando
    u4 operando = 4;

    #ifdef DEBUG
        printf("Instrução iconst_4: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", operando);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}

void iconst_5(stack_frames *pilha_frames) {
    //declara operando
    u4 operando = 5;

    #ifdef DEBUG
        printf("Instrução iconst_5: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", operando);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}

void lconst_0(stack_frames *pilha_frames) {
    //declara operando
    u4 operando = 0;

    #ifdef DEBUG
        printf("Instrução lconst_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %ld\n", u8_to_long(operando, operando));
    #endif

    //empilha operando
    push_operando(TAG_LONG, operando, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, operando, pilha_frames->first->operand_stack);

}

void lconst_1(stack_frames *pilha_frames) {
    //declara operando
    u8 operando = 1;

    #ifdef DEBUG
        printf("Instrução lconst_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %li\n", u8_to_long(operando,operando>>32));
    #endif

    //empilha operando
    push_operando(TAG_LONG, operando>>32, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, operando, pilha_frames->first->operand_stack);

}

void fconst_0(stack_frames *pilha_frames) {
    //declara operando float e um de 32bits
    float valor = 0;
    u4 operando = float_to_u4(valor);

    #ifdef DEBUG
        printf("Instrução fconst_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", valor);
    #endif

    //empilha operando
    push_operando(TAG_FLOAT, operando, pilha_frames->first->operand_stack);
}

void fconst_1(stack_frames *pilha_frames) {
    //declara operando float e um de 32bits
    float valor = 1;
    u4 operando = float_to_u4(valor);

    #ifdef DEBUG
        printf("Instrução fconst_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", valor);
    #endif

    //empilha operando
    push_operando(TAG_FLOAT, operando, pilha_frames->first->operand_stack);

}

void fconst_2(stack_frames *pilha_frames) {
    float valor = 2;
    u4 operando = float_to_u4(valor);

    #ifdef DEBUG
        printf("Instrução fconst_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", valor);
    #endif

    //empilha operando
    push_operando(TAG_FLOAT, operando, pilha_frames->first->operand_stack);

}

void dconst_0(stack_frames *pilha_frames) {
    //declara operando float e um de 32bits
    double valor = 0;
    u8 operando = double_to_u8(valor);

    #ifdef DEBUG
        printf("Instrução dconst_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", valor);
    #endif

    //empilha operando
    push_operando(TAG_DOUBLE, operando>>32, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, operando, pilha_frames->first->operand_stack);

}

void dconst_1(stack_frames *pilha_frames) {
    //declara operando float e um de 32bits
    double valor = 1;
    u8 operando = double_to_u8(valor);

    #ifdef DEBUG
        printf("Instrução dconst_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", valor);
    #endif

    //empilha operando
    push_operando(TAG_DOUBLE, operando>>32, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, operando, pilha_frames->first->operand_stack);

}

void bipush(stack_frames *pilha_frames) {
    //pegando pc
    u4 pc = pilha_frames->first->pc;

    //pegando o operando
    u4 operando = (int8_t)pilha_frames->first->code_info->code[pc];

    #ifdef DEBUG
        printf("Instrução bipush: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

    //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc++;
}

void sipush(stack_frames *pilha_frames) {
    //declarando operando
    u4 operando = 0;
    u4 pc;

    //pegando pc
    pc = pilha_frames->first->pc;

    //pegando o operando
    operando = (int16_t)operando_u2(pilha_frames->first->code_info->code,pc);

    #ifdef DEBUG
        printf("Instrução sipush: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

    //incrementando pc
    pilha_frames->first->pc+=2;
}

void ldc(stack_frames *pilha_frames) {

    //declarando o index
    u1 index;
    u4 pc;
    cp_info operando;

    #ifdef DEBUG
        printf("Instrução ldc: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //pegando pc
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    #ifdef DEBUG
        printf("Index: %d\n", index);
    #endif

    //pegando operando
    operando = pilha_frames->first->pt_constant_pool[index];


    //verificando a tag para saber que tipo de operando é
    switch(operando.tag)
    {
        case 3:
            //operando inteiro
            #ifdef DEBUG
                printf("Empilhado: 0x%x\n", operando.info.integer_info.bytes);
            #endif
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.integer_info.bytes, pilha_frames->first->operand_stack);
            break;

        case 4:
            //opernado float
            #ifdef DEBUG
                printf("Empilhado: 0x%x\n", operando.info.float_info.bytes);
            #endif
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.float_info.bytes, pilha_frames->first->operand_stack);
            break;
        case 8:
            //operando string
            #ifdef DEBUG
                printf("Empilhado: 0x%x\n", operando.info.string_info.string_index);
            #endif
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.string_info.string_index, pilha_frames->first->operand_stack);
            break;

        default:
            printf("ldc ERRO\n");
            break;
    }

    //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc++;
}

void ldc_w(stack_frames *pilha_frames) {

    //delcarando operando
    u2 index;
    u4 pc;
    cp_info operando;

    #ifdef DEBUG
        printf("Instrução ldc_w: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //pegando o pc
    pc = pilha_frames->first->pc;

    index = operando_u2(pilha_frames->first->code_info->code,pc);

    #ifdef DEBUG
        printf("Index: %d\n", index);
    #endif

    //pegando operando
    operando = pilha_frames->first->pt_constant_pool[index];

    //verificando a tag para saber que tipo de operando é
    switch(operando.tag)
    {
        case 3:
            //operando inteiro
            #ifdef DEBUG
                printf("Empilhado: 0x%x\n", operando.info.integer_info.bytes);
            #endif
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.integer_info.bytes, pilha_frames->first->operand_stack);
            break;

        case 4:
            //opernado float
            #ifdef DEBUG
                printf("Empilhado: 0x%x\n", operando.info.float_info.bytes);
            #endif
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.float_info.bytes, pilha_frames->first->operand_stack);
            break;
        case 8:
            //operando string
            #ifdef DEBUG
                printf("Empilhado: 0x%x\n", operando.info.string_info.string_index);
            #endif
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.string_info.string_index, pilha_frames->first->operand_stack);
            break;

        default:
            printf("ldc ERRO\n");
            break;
    }

   //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc+=2;

}

void ldc2_w(stack_frames *pilha_frames) {
    //delcarando operando
    u2 index;
    u4 pc;
    cp_info operando;
    u8 numero;
    u4 operando_hi;
    u4 operando_lo;

    #ifdef DEBUG
        printf("Instrução ldc2_w: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //pegando o pc
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //incrementando pc
    pilha_frames->first->pc++;
    pc = pilha_frames->first->pc;

    //pegando o index
    index = index << 8;
    index = index | pilha_frames->first->code_info->code[pc];

    #ifdef DEBUG
        printf("Index: %d\n", index);
    #endif

    //pegando operando
    operando = pilha_frames->first->pt_constant_pool[index];

    //verificando a tag para saber que tipo de operando é
    switch(operando.tag)
    {
        case 5:
            //operando long
            //empilha operando
            numero = operando.info.long_info.bytes;

            //pega o higher e o lower do operando
            operando_hi = (u4) ((numero & 0xFFFFFFFF00000000) >> 32);
            operando_lo = (u4) numero & 0x00000000FFFFFFFF;

            #ifdef DEBUG
                printf("Empilhado: %lu\n", u8_to_long(operando_lo, operando_hi));
            #endif

            //empilha operando
            push_operando(operando.tag, operando_hi, pilha_frames->first->operand_stack);
            push_operando(operando.tag, operando_lo, pilha_frames->first->operand_stack);
            break;

        case 6:
            //opernado double
            //empilha operando
            numero = operando.info.double_info.bytes;

            //pega o higher e o lower do operando
            operando_hi = (u4) ((numero & 0xFFFFFFFF00000000) >> 32);
            operando_lo = (u4) numero & 0x00000000FFFFFFFF;

            #ifdef DEBUG
                printf("Empilhado: %f\n", u8_to_double(operando_lo, operando_hi));
            #endif

            //empilha operando
            push_operando(operando.tag, operando_hi, pilha_frames->first->operand_stack);
            push_operando(operando.tag, operando_lo, pilha_frames->first->operand_stack);
            break;

        default:
            printf("ldc2_w ERRO\n");
            break;
    }

    //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc++;
}

void iload(stack_frames *pilha_frames) {

    //declarando variáveis
    u2 index;
    u4 pc;
    u4 operando;

    #ifdef DEBUG
        printf("Instrução iload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //pegando o pc
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //se tiver sido setado a flag wide_ ele pega o segundo byte e forma um index
    if (wide_)
    {
        pilha_frames->first->pc++;

        //pegando o pc
        pc = pilha_frames->first->pc;

        //juntando os dois bytes para formar o index
        index = index << 8;
        index = index | pilha_frames->first->code_info->code[pc];

        //mudando o valor da flag wide_
        wide_ = 0;
    }

    #ifdef DEBUG
        printf("Index: %d\n", index);
    #endif

    //pegando o operando
    operando = pilha_frames->first->array_variaveis_locais[index];

    #ifdef DEBUG
        printf("Empilhado: %d\n", operando);
    #endif

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

    //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc++;

}

void lload(stack_frames *pilha_frames) {

    //declarando variáveis
    u2 index;
    u4 pc;
    u4 operando_lo, operando_hi;

    #ifdef DEBUG
        printf("Instrução lload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //pegando o pc
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //se tiver sido setado a flag wide_ ele pega o segundo byte e forma um index
    if (wide_)
    {
        pilha_frames->first->pc++;

        //pegando o pc
        pc = pilha_frames->first->pc;

        //juntando os dois bytes para formar o index
        index = index << 8;
        index = index | pilha_frames->first->code_info->code[pc];

        //mudando o valor da flag wide_
        wide_ = 0;
    }

    #ifdef DEBUG
        printf("Index: %d\n", index);
    #endif

    //pegando o operando
    operando_hi = pilha_frames->first->array_variaveis_locais[index];
    operando_lo = pilha_frames->first->array_variaveis_locais[index+1];

    #ifdef DEBUG
        printf("Empilhado: %li\n", u8_to_long(operando_lo, operando_hi));
    #endif

    //empilha operando
    push_operando(TAG_LONG, operando_hi, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, operando_lo, pilha_frames->first->operand_stack);

    //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc++;

}

void fload(stack_frames *pilha_frames) {

    //declarando variáveis
    u2 index;
    u4 pc;
    u4 operando;

    #ifdef DEBUG
        printf("Instrução fload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //pegando o pc
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //se tiver sido setado a flag wide_ ele pega o segundo byte e forma um index
    if (wide_)
    {
        pilha_frames->first->pc++;

        //pegando o pc
        pc = pilha_frames->first->pc;

        //juntando os dois bytes para formar o index
        index = index << 8;
        index = index | pilha_frames->first->code_info->code[pc];

        //mudando o valor da flag wide_
        wide_ = 0;
    }

    #ifdef DEBUG
        printf("Index: %d\n", index);
    #endif

    //pegando o operando
    operando = pilha_frames->first->array_variaveis_locais[index];

    #ifdef DEBUG
        printf("Empilhado: %f\n", u4_to_float(operando));
    #endif

    //empilha operando
    push_operando(TAG_FLOAT, operando, pilha_frames->first->operand_stack);

    //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc++;

}

void dload(stack_frames *pilha_frames) {

    //declarando variáveis
    u2 index;
    u4 pc;
    u4 operando_hi, operando_lo;

    #ifdef DEBUG
        printf("Instrução dload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //pegando o pc
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //se tiver sido setado a flag wide_ ele pega o segundo byte e forma um index
    if (wide_)
    {
        pilha_frames->first->pc++;

        //pegando o pc
        pc = pilha_frames->first->pc;

        //juntando os dois bytes para formar o index
        index = index << 8;
        index = index | pilha_frames->first->code_info->code[pc];

        //mudando o valor da flag wide_
        wide_ = 0;
    }

    #ifdef DEBUG
        printf("Index: %d\n", index);
    #endif

    //pegando o operando
    operando_hi = pilha_frames->first->array_variaveis_locais[index];
    operando_lo = pilha_frames->first->array_variaveis_locais[index+1];

    #ifdef DEBUG
        printf("Empilhado: %f\n", u8_to_double(operando_lo, operando_hi));
    #endif

    //empilha operando
    push_operando(TAG_DOUBLE, operando_hi, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, operando_lo, pilha_frames->first->operand_stack);

    //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc++;

}

void aload(stack_frames *pilha_frames) {

    //declarando variáveis
    u2 index;
    u4 pc;
    u4 operando;

    #ifdef DEBUG
        printf("Instrução aload: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
    #endif

    //pegando o pc
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //se tiver sido setado a flag wide_ ele pega o segundo byte e forma um index
    if (wide_)
    {
        pilha_frames->first->pc++;

        //pegando o pc
        pc = pilha_frames->first->pc;

        //juntando os dois bytes para formar o index
        index = index << 8;
        index = index | pilha_frames->first->code_info->code[pc];

        //mudando o valor da flag wide_
        wide_ = 0;
    }

    #ifdef DEBUG
        printf("Index: %d\n", index);
    #endif

    //pegando o operando
    operando = pilha_frames->first->array_variaveis_locais[index];

    #ifdef DEBUG
        printf("Empilhado: %x\n", operando);
    #endif

    //empilha operando
    push_operando(TAG_ARRAY_REF, operando, pilha_frames->first->operand_stack);

    //incrementando pc mais uma vez para pegar o opcode
    pilha_frames->first->pc++;
}

void iload_0(stack_frames *pilha_frames) {

    #ifdef DEBUG
        printf("Instrução iload_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", pilha_frames->first->array_variaveis_locais[0]);
    #endif

    push_operando(TAG_INTEGER, pilha_frames->first->array_variaveis_locais[0], pilha_frames->first->operand_stack);

}

void iload_1(stack_frames *pilha_frames) {

    #ifdef DEBUG
        printf("Instrução iload_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", pilha_frames->first->array_variaveis_locais[1]);
    #endif

    push_operando(TAG_INTEGER, pilha_frames->first->array_variaveis_locais[1], pilha_frames->first->operand_stack);

}

void iload_2(stack_frames *pilha_frames) {

    #ifdef DEBUG
        printf("Instrução iload_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", pilha_frames->first->array_variaveis_locais[2]);
    #endif

    push_operando(TAG_INTEGER, pilha_frames->first->array_variaveis_locais[2], pilha_frames->first->operand_stack);
}

void iload_3(stack_frames *pilha_frames) {

    #ifdef DEBUG
        printf("Instrução iload_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %d\n", pilha_frames->first->array_variaveis_locais[3]);
    #endif

    push_operando(TAG_INTEGER, pilha_frames->first->array_variaveis_locais[3], pilha_frames->first->operand_stack);
}

void lload_0(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um long do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[0];
    // recupera os low bytes de um long do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[1];

    #ifdef DEBUG
        printf("Instrução lload_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %lu\n", u8_to_long(low_bytes, high_bytes));
    #endif

    // empilha big endian
    push_operando(TAG_LONG, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, low_bytes, pilha_frames->first->operand_stack);
}

void lload_1(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um long do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[1];
    // recupera os low bytes de um long do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[2];

    #ifdef DEBUG
        printf("Instrução lload_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %lu\n", u8_to_long(low_bytes, high_bytes));
    #endif

    // empilha big endian
    push_operando(TAG_LONG, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, low_bytes, pilha_frames->first->operand_stack);
}

void lload_2(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um long do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[2];
    // recupera os low bytes de um long do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[3];

    #ifdef DEBUG
        printf("Instrução lload_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %lu\n", u8_to_long(low_bytes, high_bytes));
    #endif

    // empilha big endian
    push_operando(TAG_LONG, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, low_bytes, pilha_frames->first->operand_stack);
}

void lload_3(stack_frames *pilha_frames) {

    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um long do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[3];
    // recupera os low bytes de um long do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[4];

    #ifdef DEBUG
        printf("Instrução lload_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %lu\n", u8_to_long(low_bytes, high_bytes));
    #endif

    // empilha big endian
    push_operando(TAG_LONG, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, low_bytes, pilha_frames->first->operand_stack);
}

void fload_0(stack_frames *pilha_frames) {
    // Copia o valor do float na posição 0 do array de variáveis locais
    u4 value = pilha_frames->first->array_variaveis_locais[0];

    #ifdef DEBUG
        printf("Instrução fload_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", u4_to_float(value));
    #endif

    // Acidiona o operando a pilha
    push_operando(TAG_FLOAT, value, pilha_frames->first->operand_stack);
}

void fload_1(stack_frames *pilha_frames) {
    // Copia o valor do float na posição 1 do array de variáveis locais
    u4 value = pilha_frames->first->array_variaveis_locais[1];

    #ifdef DEBUG
        printf("Instrução fload_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", u4_to_float(value));
    #endif

    // Acidiona o operando a pilha
    push_operando(TAG_FLOAT, value, pilha_frames->first->operand_stack);
}

void fload_2(stack_frames *pilha_frames) {
    // Copia o valor do float na posição 2 do array de variáveis locais
    u4 value = pilha_frames->first->array_variaveis_locais[2];

    #ifdef DEBUG
        printf("Instrução fload_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", u4_to_float(value));
    #endif

    // Acidiona o operando a pilha
    push_operando(TAG_FLOAT, value, pilha_frames->first->operand_stack);
}

void fload_3(stack_frames *pilha_frames) {
    // Copia o valor do float na posição 2 do array de variáveis locais
    u4 value = pilha_frames->first->array_variaveis_locais[3];

    #ifdef DEBUG
        printf("Instrução fload_3: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", u4_to_float(value));
    #endif

    // Acidiona o operando a pilha
    push_operando(TAG_FLOAT, value, pilha_frames->first->operand_stack);
}

void dload_0(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um double do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[0];
    // recupera os low bytes de um double do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[1];

    #ifdef DEBUG
        printf("Instrução dload_0: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", u8_to_double(low_bytes, high_bytes));
    #endif

    // empilha big endian
    push_operando(TAG_DOUBLE, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, low_bytes, pilha_frames->first->operand_stack);
}

void dload_1(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um double do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[1];
    // recupera os low bytes de um double do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[2];

    #ifdef DEBUG
        printf("Instrução dload_1: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", u8_to_double(low_bytes, high_bytes));
    #endif

    // empilha big endian
    push_operando(TAG_DOUBLE, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, low_bytes, pilha_frames->first->operand_stack);
}

void dload_2(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um double do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[2];
    // recupera os low bytes de um double do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[3];

    #ifdef DEBUG
        printf("Instrução dload_2: 0x%x\n", (u1)pilha_frames->first->code_info->code[pilha_frames->first->pc]);
        printf("Empilhado: %f\n", u8_to_double(low_bytes, high_bytes));
    #endif

    // empilha big endian
    push_operando(TAG_DOUBLE, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, low_bytes, pilha_frames->first->operand_stack);
}
