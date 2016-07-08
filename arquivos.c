/*!
   \file arquivos.c
   \brief Implementação das funções de manipulação de arquivos.

   Esse arquivo contém a implementação das funções que definem as manipulações de
   arquivos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "arquivos.h"

/* Manipulação de arquivo de leitura */
FILE *abrir_arquivo_leitura(char *nome_arquivo){
    FILE *pt_arquivo = NULL;

    // tenta abrir o arquivo passado como binário para leitura
    pt_arquivo = fopen(nome_arquivo, "rb");

    // caso o arquivo tenha sido aberto corretamente, retorna o ponteiro
    // caso contrário retorna null
    if (pt_arquivo != NULL) {
        return pt_arquivo;
    }else{
        printf("Problema na abertura do Arquivo.\n");
        return NULL;
    }
}

/* Fim da manipulação de arquivos */
void fechar_arquivo(FILE *pt_arquivo){
    fclose(pt_arquivo);
}


/* Manipulação de tipos int */
u1 ler_u1(FILE *pt_arquivo){
    u1 retorno_u1 = 0;

    // lê um 1 byte do arquivo'
    fread(&retorno_u1, sizeof(uint8_t), 1, pt_arquivo);

    return retorno_u1;
}

u2 ler_u2(FILE *pt_arquivo){
    u2 retorno_u2 = 0;
    u1 primeiro_byte = 0, segundo_byte = 0;

    // lê o primeiro byte - mais significativo
    primeiro_byte = ler_u1(pt_arquivo);

    // lê o segundo byte - menos significativo
    segundo_byte = ler_u1(pt_arquivo);

    // muda de big endian para little endian
    retorno_u2 = retorno_u2 | (((u2) primeiro_byte) << 8);
    retorno_u2 = retorno_u2 | (((u2) segundo_byte));

    return retorno_u2;
}

u4 ler_u4(FILE *pt_arquivo){
    u4 retorno_u4 = 0;
    u2 primeiros_2_bytes = 0, segundos_2_bytes = 0;

    // lê os dois primeiros bytes em little endian order
    primeiros_2_bytes = ler_u2(pt_arquivo);

    // lê os dois segundos bytes em little endian order
    segundos_2_bytes = ler_u2(pt_arquivo);

    // mudar de big endian order para little endian
    retorno_u4 = retorno_u4 | (((u4) primeiros_2_bytes) << 16);
    retorno_u4 = retorno_u4 | (((u4) segundos_2_bytes));

    return retorno_u4;
}


u8 ler_u8(FILE *pt_arquivo){
    u8 retorno_u8 = 0;
    u4 primeiros_4_bytes = 0, segundos_4_bytes = 0;

    // lê os quatro primeiros bytes em little endian order
    primeiros_4_bytes = ler_u4(pt_arquivo);

    // lê os quatro segundos bytes em little endian order
    segundos_4_bytes = ler_u4(pt_arquivo);

    // mudar de big endian order para little endian
    retorno_u8 = retorno_u8 | (((u8) primeiros_4_bytes) << 32);
    retorno_u8 = retorno_u8 | (((u8) segundos_4_bytes));

    return retorno_u8;
}
