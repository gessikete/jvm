#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <stdio.h>
#include "types.h"

/*
 * Abre arquivo para leitura
 *
 * Parâmetros:
 *       char *in_file: ponteiro para string contendo o nome do arquivo
 *
 * Retorno:
 *       FILE *: ponteiro para o arquivo aberto
 */
FILE *abrir_arquivo_leitura(char *nome_arquivo);

/*
 * Fecha arquivo aberto
 *
 * Parâmetros:
 *       FILE *pt_arquivo: ponteiro para o arquivo aberto
 *
 * Retorno:
 *       Nenhum
 */
void fechar_arquivo(FILE *pt_arquivo);


/*
 * Le 1 byte do arquivo .class
 *
 * Parâmetros:
 *       FILE *pt_arquivo: ponteiro para o arquivo aberto
 *
 * Retorno:
 *       Byte lido
 */
u1 ler_u1(FILE *pt_arquivo);


/*
 * Le 2 bytes do arquivo .class e os coloca em little endian order
 *
 * Parâmetros:
 *       FILE *pt_arquivo: ponteiro para o arquivo aberto
 *
 * Retorno:
 *       2 bytes do arquivo em little endian order
 */
u2 ler_u2(FILE *pt_arquivo);



/*
 * Le 4 bytes do arquivo .class e os coloca em little endian order
 *
 * Parâmetros:
 *       FILE *pt_arquivo: ponteiro para o arquivo aberto
 *
 * Retorno:
 *       4 bytes do arquivo em little endian order.
 */
u4 ler_u4(FILE *pt_arquivo);


/*
 * Le 8 bytes do arquivo .class e os coloca em little endian order
 *
 * Parâmetros:
 *       FILE *pt_arquivo: ponteiro para o arquivo aberto
 *
 * Retorno:
 *       8 bytes do arquivo em little endian order.
 */
u8 ler_u8(FILE *pt_arquivo);

#endif /* ARQUIVOS_H */
