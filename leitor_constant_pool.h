#ifndef LEITOR_CONSTANT_POOL_H
#define LEITOR_CONSTANT_POOL_H

#include <stdlib.h>
#include "types.h"
#include "arquivos.h"
#include "validation.h"


//Tag das entradas da constant pool que são precedidas por um double ou um long.
#define TAG_LARGE 254

//Tag da primeira entrada da constant pool (que não é utilizada para facilitar o acesso
//elementos da const pool.
#define TAG_0 255

#define TAG_UTF8 1

/*
 * Inicializa um vetor de ponteiros para as funcoes de preenchimento dos elementos da
 * constant_pool.
 *
 * Parâmetros:
 *	funcoes_constant: vetor de ponteiros para as funcoes.
 * Retorno:
 *       Nada.
 */
void inicializar_vetor_funcoes(void (*funcoes_constant[]) (FILE*,cp_info[],u2,u1));


/*
 * Preenche o constant pool com todos os seus dados.
 *
 * Parâmetros:
 *	FILE *pt_arquivo: ponteiro para o arquivo aberto;
 *	cp_info: Ponteiro para o array onde esta a constant pool;
 *	tamanho: tamanho da constant_pool
 * Retorno:
 *       Nada.
 */
void criar_constant_pool(FILE *pt_arquivo, cp_info const_pool[], u2 tamanho);


/*
 * As funcoes a seguir preenchem as suas respectivas estruturas de acordo com
 * os dados fornecidos pelo .class
 *
 * Parâmetros:
 *	FILE *pt_arquivo: ponteiro para o arquivo aberto;
 *	const_pool[]: um elemento da constant pool;
 *	index: indice atual de cp_info
 * Retorno:
 *       Nada.
 */
void criar_class_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_fieldref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_utf8_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_string_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_interface_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_integer_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_float_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_long_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_double_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_name_and_type_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);


/*
 * Preenche entrada do constant pool com uma tag invalida
 *
 * Parâmetros:
 *	cp_info: Ponteiro para o array onde esta a constant pool;
 *	index: indice atual de cp_info
 * 	tag: tag invalida
 * Retorno:
 *       Nada.
 */
void tag_invalida(cp_info const_pool[], u2 index, u2 tag);


/*
 * Verifica se tag é um long ou um double.
 *
 * Parâmetros:
 * 	tag: tag a ser avaliada.
 * Retorno:
 *       Nada.
 */
bool large_numeric(u2 tag);

/*
 * Preenche a constant pool
 *
 * Parâmetros:
 *	u2 constant_pool_count: tamanho da constant pool
 *	FILE *pt_arquivo: ponteiro para o arquivo .class
 * Retorno:
 *       Ponteiro para a constant pool.
 */
cp_info *carregar_constant_pool(u2 constant_pool_count, FILE *pt_arquivo);

/*
 * Desaloca o espaço alocado para a estrutura constant pool
 *
 * Parâmetros:
 *		cp_info *constant_pool: ponteiro para a estrutura constant_pool
 *		u2 constant_pool_count: tamanho da constant pool
 * Retorno:
 *		Nenhum
 */
void desalocar_constant_pool(cp_info *constant_pool, u2 constant_pool_count);

#endif /* LEITOR_CONSTANT_POOL_H */
