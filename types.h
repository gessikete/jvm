/*
 *  Universidade de Brasília
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2016
 *
 *  Projeto JVM
 *
 *  Arquivo de cabeçalho "main.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#ifndef LIB_TYPES
#define LIB_TYPES

#include <stdio.h>
#include <stdint.h>
// Inclui stdboll para uso de tipos booleanos
#include <stdbool.h>

//arquivo de saida global ao projeto
 FILE *arquivo_saida;

/*
 * Definindo as estruturas para manipulação de inteiros tamanhos 8bits, 16bits,
 * 32bits e 64bits da biblioteca stdint.h
 */

/*
 * unsigned char
 */
typedef uint8_t u1;

/*
 * unsigned short
 */
typedef uint16_t u2;

/*
 * unsigned int
 */
typedef uint32_t u4;

/*
 * unsigned long long
 */
typedef uint64_t u8;

typedef uint8_t tipo_boolean;
typedef int8_t tipo_byte;
typedef uint16_t tipo_char;
typedef int16_t tipo_short;
typedef int32_t tipo_int;
typedef long long tipo_long;
typedef float tipo_float;
typedef double tipo_double;


#endif /* LIB_TYPES */
