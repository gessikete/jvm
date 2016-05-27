#ifndef CLASS_READER_H
#define CLASS_READER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <inttypes.h>
#include "types.h"
#include "arquivos.h"
#include "atributos.h"
#include "metodos.h"
#include "campos.h"
#include "constant_pool.h"
#include "validation.h"

#define STR_SIZE 100

/* Definição da estrutura do arquivo de classe */
typedef struct {
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    cp_info *constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2 *interfaces;
    u2 fields_count;
    field_info *fields;
    u2 methods_count;
    method_info *methods;
    u2 attributes_count;
    attribute_info *attributes;
} class_file;

/*
 * Organiza a leitura de todos os elementos da classe
 *
 * Parâmetros:
 *       char *nome_arquivo: ponteiro para string contendo o nome do arquivo .class
 *
 * Retorno:
 *       class_file *: ponteiro para a strutura contendo as informações da classe
 */
class_file *carregar_classe(char *nome_arquivo);

/*
 * Carrega os elementos da constant_pool
 *
 * Parâmetros:
 *       u2 constant_pool_count: número de elementos + 1 da constant_pool
 *       FILE *pt_arquivo: ponteiro para o arquivo binário da classe
 *
 * Retorno:
 *       cp_info *: ponteiro para a estrutura com a constant_pool preenchida
 */
cp_info *carregar_constant_pool(u2 constant_pool_count, FILE *pt_arquivo);

/*
 * Lê os valores referentes aos índices para a constant_pool das interfaces
 *
 * Parâmetros:
 *       u2 interfaces_count: número de interfaces dessa classe
 *       FILE *pt_arquivo: ponteiro para o arquivo binário da classe
 *
 * Retorno:
 *       u2 *: ponteiro para array com índices das interfaces
 */
u2 *ler_interfaces(u2 interfaces_count, FILE *pt_arquivo);


#endif /* CLASS_READER_H */
