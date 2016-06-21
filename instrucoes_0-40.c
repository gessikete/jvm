#include "instrucoes_0-40.h"

void nop(stack_frames *pilha_frames) {
	return;
}


/*
    Instrução aconst_null: empilha null na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.: não incrementa o PC

*/
void aconst_null(stack_frames *pilha_frames) {

    u4 operando = (u4)NULL;

    // adiciona o operando a pilha
    push_operando(TAG_NULL, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução iconst_m1: empilha um int de valor -1 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.: não incrementa o PC

*/
void iconst_m1(stack_frames *pilha_frames) {

    //declarando o operando
    int32_t operando = -1;
    u4 operandoFormatado = 0;

    //faz um cast
    memcpy(&operandoFormatado, &operando, sizeof(u4));

    //salva valor na pilha de operandos
    push_operando(TAG_INTEGER, operandoFormatado, pilha_frames->first->operand_stack);

}


/*
    Instrução iconst_0: empilha um int de valor 0 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.: não incrementa o PC

*/
void iconst_0(stack_frames *pilha_frames) {

    //declara operando
    u4 operando = 0;

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução iconst_1: empilha um int de valor 1 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.: não incrementa o PC

*/
void iconst_1(stack_frames *pilha_frames) {

    //declara operando
    u4 operando = 1;

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução iconst_2: empilha um int de valor 2 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.: não incrementa o PC

*/
void iconst_2(stack_frames *pilha_frames) {

    //declara operando
    u4 operando = 2;

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução iconst_3: empilha um int de valor 3 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.: não incrementa o PC

*/
void iconst_3(stack_frames *pilha_frames) {

    //declara operando
    u4 operando = 3;

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução iconst_4: empilha um int de valor 4 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.: não incrementa o PC

*/
void iconst_4(stack_frames *pilha_frames) {

    //declara operando
    u4 operando = 4;

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução iconst_4: empilha um int de valor 4 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.: não incrementa o PC

*/
void iconst_5(stack_frames *pilha_frames) {

    //declara operando
    u4 operando = 5;

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução lconst_0: empilha um long de valor 0 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: não incrementa o PC
    Obs.2: guarda primeiro lower e depois higher

*/
void lconst_0(stack_frames *pilha_frames) {

    //declara operando
    u8 operando = 0;

    //pega o higher e o lower do operando
    u4 operando_hi = (u4) ((operando & 0xFFFFFFFF00000000) >> 32);
    u4 operando_lo = (u4) operando & 0x00000000FFFFFFFF;

    //empilha operando
    push_operando(TAG_LONG, operando_lo, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, operando_hi, pilha_frames->first->operand_stack);

}


/*
    Instrução lconst_1: empilha um long de valor 1 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: não incrementa o PC
    Obs.2: guarda primeiro lower e depois higher

*/
void lconst_1(stack_frames *pilha_frames) {

    //declara operando
    u8 operando = 1;

    //pega o higher e o lower do operando
    u4 operando_hi = (u4) ((operando & 0xFFFFFFFF00000000) >> 32);
    u4 operando_lo = (u4) operando & 0x00000000FFFFFFFF;

    //empilha operando
    push_operando(TAG_LONG, operando_lo, pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, operando_hi, pilha_frames->first->operand_stack);

}


/*
    Instrução fconst_0: empilha um float de valor 0 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: não incrementa o PC

*/
void fconst_0(stack_frames *pilha_frames) {

    //declara operando float e um de 32bits
    float valor = 0;
    u4 operando = 0;

    //conversao
    memcpy(&operando, &valor, sizeof(float));

    //empilha operando
    push_operando(TAG_FLOAT, operando, pilha_frames->first->operand_stack);
}


/*
    Instrução fconst_1: empilha um float de valor 1 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: não incrementa o PC

*/
void fconst_1(stack_frames *pilha_frames) {

    //declara operando float e um de 32bits
    float valor = 1;
    u4 operando = 0;

    //conversao
    memcpy(&operando, &valor, sizeof(float));

    //empilha operando
    push_operando(TAG_FLOAT, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução fconst_2: empilha um float de valor 2 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: não incrementa o PC

*/
void fconst_2(stack_frames *pilha_frames) {

    //declara operando float e um de 32bits
    float valor = 2;
    u4 operando = 0;

    //conversao
    memcpy(&operando, &valor, sizeof(float));

    //empilha operando
    push_operando(TAG_FLOAT, operando, pilha_frames->first->operand_stack);

}


/*
    Instrução dconst_0: empilha um double de valor 0 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: não incrementa o PC

*/
void dconst_0(stack_frames *pilha_frames) {

    //declara operando float e um de 32bits
    double valor = 0;
    u8 operando = 0;

    //pegando os 64 bits menos sigificativos do double
    memcpy(&operando + sizeof(u8) - 8, &valor, sizeof(double));

    //pega o higher e o lower do operando
    u4 operando_hi = (u4) ((operando & 0xFFFFFFFF00000000) >> 32);
    u4 operando_lo = (u4) operando & 0x00000000FFFFFFFF;

    //empilha operando
    push_operando(TAG_DOUBLE, operando_lo, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, operando_hi, pilha_frames->first->operand_stack);

}


/*
    Instrução dconst_1: empilha um double de valor 1 na pilha de operandos

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: não incrementa o PC

*/
void dconst_1(stack_frames *pilha_frames) {

    //declara operando float e um de 32bits
    double valor = 1;
    u8 operando = 0;

    //pegando os 64 bits menos sigificativos do double
    memcpy(&operando + sizeof(u8) - 8, &valor, sizeof(double));

    //pega o higher e o lower do operando
    u4 operando_hi = (u4) ((operando & 0xFFFFFFFF00000000) >> 32);
    u4 operando_lo = (u4) operando & 0x00000000FFFFFFFF;

    //empilha operando
    push_operando(TAG_DOUBLE, operando_lo, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, operando_hi, pilha_frames->first->operand_stack);

}


/*
    Instrução bipush: empilha um byte na pilha

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc

*/
void bipush(stack_frames *pilha_frames) {

    //incrementando pc
    pilha_frames->first->pc++;

    //pegando pc
    u4 pc = pilha_frames->first->pc;

    //pegando o byte
    u1 byte = pilha_frames->first->code_info->code[pc];

    u4 operando = (u4)byte;

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);
}


/*
    Instrução bipush: empilha um short na pilha

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: funciona se primeiro ele tirar da pilha o higher e depois o lower

*/
void sipush(stack_frames *pilha_frames) {

    //declarando operando
    u4 operando = 0;
    u4 pc;

    //incrementando pc
    pilha_frames->first->pc++;

    //pegando pc
    pc = pilha_frames->first->pc;

    //pegando o byte
    u1 byte1 = pilha_frames->first->code_info->code[pc];

    //incrementando pc mais uma vez
    pilha_frames->first->pc++;

    //pegando pc
    pc = pilha_frames->first->pc;

    //pegando o segundo byte
    u1 byte2 = pilha_frames->first->code_info->code[pc];

    //convertendo para 32bits
    operando = operando | (byte1 << 8);
    operando = operando | byte2;

    //empilha operando
    push_operando(TAG_INTEGER, operando, pilha_frames->first->operand_stack);
}


/*
    Instrução ldc: pega um index para o poll de constante. O index pode ser para um inteiro, float ou uma referência para uma string.
        Então ele empilha o oeprando que resgatar.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc

*/
void ldc(stack_frames *pilha_frames) {

    //declarando o index
    u1 index;
    u4 pc;
    cp_info operando;

    //incrementando pc
    pilha_frames->first->pc++;
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //pegando operando
    operando = pilha_frames->first->pt_constant_pool[index];

    //verificando a tag para saber que tipo de operando é
    switch(operando.tag)
    {
        case 3:
            //operando inteiro
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.integer_info.bytes, pilha_frames->first->operand_stack);
            break;

        case 4:
            //opernado float
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.float_info.bytes, pilha_frames->first->operand_stack);
            break;
        case 8:
            //operando string
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.string_info.string_index, pilha_frames->first->operand_stack);
            break;

        default:
            printf("ldc ERRO\n");
            break;
    }
}


/*
    Instrução ldc_w: pega dois bytes para index para o poll de constante. O index pode ser para um inteiro, float ou uma referência para uma string.
        Então ele empilha o oeprando que resgatar.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc

*/
void ldc_w(stack_frames *pilha_frames) {

    //delcarando operando
    u2 index;
    u4 pc;
    cp_info operando;

    //incrementando pc
    pilha_frames->first->pc++;
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //incrementando pc
    pilha_frames->first->pc++;
    pc = pilha_frames->first->pc;

    //pegando o index
    index = index << 8;
    index = index | pilha_frames->first->code_info->code[pc];

    //pegando operando
    operando = pilha_frames->first->pt_constant_pool[index];

    //verificando a tag para saber que tipo de operando é
    switch(operando.tag)
    {
        case 3:
            //operando inteiro
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.integer_info.bytes, pilha_frames->first->operand_stack);
            break;

        case 4:
            //opernado float
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.float_info.bytes, pilha_frames->first->operand_stack);
            break;
        case 8:
            //operando string
            //empilha operando
            push_operando(operando.tag, (u4)operando.info.string_info.string_index, pilha_frames->first->operand_stack);
            break;

        default:
            printf("ldc ERRO\n");
            break;
    }

}


/*
    Instrução ldc2_w: pega dois bytes para index para o poll de constante. O index pode ser para um long, double.
        Então ele empilha o oeprando que resgatar.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void ldc2_w(stack_frames *pilha_frames) {

    //delcarando operando
    u2 index;
    u4 pc;
    cp_info operando;
    u8 numero;
    u4 operando_hi;
    u4 operando_lo;

    //incrementando pc
    pilha_frames->first->pc++;
    pc = pilha_frames->first->pc;

    //pegando o index
    index = pilha_frames->first->code_info->code[pc];

    //incrementando pc
    pilha_frames->first->pc++;
    pc = pilha_frames->first->pc;

    //pegando o index
    index = index << 8;
    index = index | pilha_frames->first->code_info->code[pc];

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

            //empilha operando
            push_operando(operando.tag, operando_lo, pilha_frames->first->operand_stack);
            push_operando(operando.tag, operando_hi, pilha_frames->first->operand_stack);
            break;

        case 6:
            //opernado double
            //empilha operando
            numero = operando.info.double_info.bytes;

            //pega o higher e o lower do operando
            operando_hi = (u4) ((numero & 0xFFFFFFFF00000000) >> 32);
            operando_lo = (u4) numero & 0x00000000FFFFFFFF;

            //empilha operando
            push_operando(operando.tag, operando_lo, pilha_frames->first->operand_stack);
            push_operando(operando.tag, operando_hi, pilha_frames->first->operand_stack);
            break;

        default:
            printf("ldc2_w ERRO\n");
            break;
    }
}


/*
    Instrução iload: pega dois bytes para index para o poll de constante se tiver combinado com WIDE, se nao pega so um. O index pode ser para um long, double.
        Então ele empilha o oeprando que resgatar.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void iload(stack_frames *pilha_frames) {
    //precido do WIDE para fazer

}


/*
    Instrução lload: pega dois bytes para index para o poll de constante se tiver combinado com WIDE, se nao pega so um. O index pode ser para um long, double.
        Então ele empilha o oeprando que resgatar.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void lload(stack_frames *pilha_frames) {
    //preciso do wide

}


/*
    Instrução lload: recebe um índice do vetor de variaveis locais, que contem o operando que deve ser empilhado na pilha de parametros.
        se tiver Wide combina dois bytes para saber o index, se nao combina apenas um.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void fload(stack_frames *pilha_frames) {
    //precisa do wide

}


/*
    Instrução dload: recebe um índice do vetor de variaveis locais, que contem o operando que deve ser empilhado na pilha de parametros.
        se tiver Wide combina dois bytes para saber o index, se nao combina apenas um.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void dload(stack_frames *pilha_frames) {
    //precisa do wide

}


/*
    Instrução aload: recebe um índice do vetor de variaveis locais, que contem o operando que deve ser empilhado na pilha de parametros.
        se tiver Wide combina dois bytes para saber o index, se nao combina apenas um.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void aload(stack_frames *pilha_frames) {
    //wide

}


/*
    Instrução iload_0: empilha um inteiro de indice 0 na pilha de variaveis locais.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void iload_0(stack_frames *pilha_frames) {

    push_operando(TAG_INTEGER, pilha_frames->first->array_variaveis_locais[0], pilha_frames->first->operand_stack);

}


/*
    Instrução iload_1: empilha um inteiro de indice 0 na pilha de variaveis locais.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void iload_1(stack_frames *pilha_frames) {

    push_operando(TAG_INTEGER, pilha_frames->first->array_variaveis_locais[1], pilha_frames->first->operand_stack);

}


/*
    Instrução iload_1: empilha um inteiro de indice 2 na pilha de variaveis locais.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void iload_2(stack_frames *pilha_frames) {

    push_operando(TAG_INTEGER, pilha_frames->first->array_variaveis_locais[2], pilha_frames->first->operand_stack);
}


/*
    Instrução iload_3: empilha um inteiro de indice 2 na pilha de variaveis locais.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void iload_3(stack_frames *pilha_frames) {

    push_operando(TAG_INTEGER, pilha_frames->first->array_variaveis_locais[3], pilha_frames->first->operand_stack);

}


/*
    Instrução lload_0: pega o higher de um numero long no indice 0 e o lower no indice 1 e empilha na pilha de variavies locais.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void lload_0(stack_frames *pilha_frames) {

    push_operando(TAG_LONG, pilha_frames->first->array_variaveis_locais[1], pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, pilha_frames->first->array_variaveis_locais[0], pilha_frames->first->operand_stack);

}


/*
    Instrução lload_1: pega o higher de um numero long no indice 1 e o lower no indice 2 e empilha na pilha de variavies locais.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void lload_1(stack_frames *pilha_frames) {

    push_operando(TAG_LONG, pilha_frames->first->array_variaveis_locais[2], pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, pilha_frames->first->array_variaveis_locais[1], pilha_frames->first->operand_stack);

}


/*
    Instrução lload_2: pega o higher de um numero long no indice 2 e o lower no indice 3 e empilha na pilha de variavies locais.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void lload_2(stack_frames *pilha_frames) {

    push_operando(TAG_LONG, pilha_frames->first->array_variaveis_locais[3], pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, pilha_frames->first->array_variaveis_locais[2], pilha_frames->first->operand_stack);

}


/*
    Instrução lload_3: pega o higher de um numero long no indice 3 e o lower no indice 4 e empilha na pilha de variavies locais.

    Parametros:
        stack_frames *pilha_frames --> ponteiro para a pilha de frames

    Obs.1: incrementa o pc
    Obs.2: primeiro guardo o lower e depois o higher

*/
void lload_3(stack_frames *pilha_frames) {

    push_operando(TAG_LONG, pilha_frames->first->array_variaveis_locais[4], pilha_frames->first->operand_stack);
    push_operando(TAG_LONG, pilha_frames->first->array_variaveis_locais[3], pilha_frames->first->operand_stack);

}


/*
    Instrução fload_0: pega um float no array de variáveis locais com índice 0 e empilha na pilha de operandos

    Parametros:
        stack_frames *pilha_frames: ponteiro para a pilha de frames
*/
void fload_0(stack_frames *pilha_frames) {
    // Copia o valor do float na posição 0 do array de variáveis locais
    u4 value = pilha_frames->first->array_variaveis_locais[0];

    // Acidiona o operando a pilha
    push_operando(TAG_FLOAT, value, pilha_frames->first->operand_stack);
}


/*
    Instrução fload_1: pega um float no array de variáveis locais com índice 1 e empilha na pilha de operandos

    Parametros:
        stack_frames *pilha_frames: ponteiro para a pilha de frames
*/
void fload_1(stack_frames *pilha_frames) {
    // Copia o valor do float na posição 1 do array de variáveis locais
    u4 value = pilha_frames->first->array_variaveis_locais[1];

    // Acidiona o operando a pilha
    push_operando(TAG_FLOAT, value, pilha_frames->first->operand_stack);
}


/*
    Instrução fload_2: pega um float no array de variáveis locais com índice 2 e empilha na pilha de operandos

    Parametros:
        stack_frames *pilha_frames: ponteiro para a pilha de frames
*/
void fload_2(stack_frames *pilha_frames) {
    // Copia o valor do float na posição 2 do array de variáveis locais
    u4 value = pilha_frames->first->array_variaveis_locais[2];

    // Acidiona o operando a pilha
    push_operando(TAG_FLOAT, value, pilha_frames->first->operand_stack);
}


/*
    Instrução fload_3: pega um float no array de variáveis locais com índice 3 e empilha na pilha de operandos

    Parametros:
        stack_frames *pilha_frames: ponteiro para a pilha de frames
*/
void fload_3(stack_frames *pilha_frames) {
    // Copia o valor do float na posição 2 do array de variáveis locais
    u4 value = pilha_frames->first->array_variaveis_locais[3];

    // Acidiona o operando a pilha
    push_operando(TAG_FLOAT, value, pilha_frames->first->operand_stack);
}


/*
    Instrução dload_0: pega um double no array de variáveis locais com índice 0 e 1 e empilha na pilha de operandos

    Parametros:
        stack_frames *pilha_frames: ponteiro para a pilha de frames
*/
void dload_0(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um double do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[0];
    // recupera os low bytes de um double do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[1];

    // empilha big endian
    push_operando(TAG_DOUBLE, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, low_bytes, pilha_frames->first->operand_stack);
}


/*
    Instrução dload_1: pega um double no array de variáveis locais com índice 1 e 2 e empilha na pilha de operandos

    Parametros:
        stack_frames *pilha_frames: ponteiro para a pilha de frames
*/
void dload_1(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um double do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[1];
    // recupera os low bytes de um double do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[2];

    // empilha big endian
    push_operando(TAG_DOUBLE, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, low_bytes, pilha_frames->first->operand_stack);
}


/*
    Instrução dload_2: pega um double no array de variáveis locais com índice 2 e 3 e empilha na pilha de operandos

    Parametros:
        stack_frames *pilha_frames: ponteiro para a pilha de frames
*/
void dload_2(stack_frames *pilha_frames) {
    u4 high_bytes = 0, low_bytes = 0;

    // recupera os high bytes de um double do array de variáveis locais
    high_bytes = pilha_frames->first->array_variaveis_locais[2];
    // recupera os low bytes de um double do array de variáveis locais
    low_bytes = pilha_frames->first->array_variaveis_locais[3];

    // empilha big endian
    push_operando(TAG_DOUBLE, high_bytes, pilha_frames->first->operand_stack);
    push_operando(TAG_DOUBLE, low_bytes, pilha_frames->first->operand_stack);
}
