#ifndef LEITOR_ATRIBUTOS_H
#define LEITOR_ATRIBUTOS_H

#include <string.h>
#include "types.h"
#include "macros.h"
#include "recuperar_constant_pool.h"

// Define um ponteiro para as funções de criação de atributos
typedef void (*funcoes_criar) (FILE*,attribute_info[],u2,cp_info[],u2);


/* Declaração dos métodos dos atributos */

/*
 * Compara o nome do atributo com o atributo na constant pool e
 * retorna a função de criação adequada para o tipo de atributo em questão.
 *
 * Parâmetros:
 *	cp_info constant_pool[]: a constant pool
 *	u2 name_index: índice do nome do atributo na constant pool
 *
 * Retorno:
 *       A função de criação de atributos correspondente ao nome do atributo.
 */

funcoes_criar escolher_funcao(cp_info constant_pool[], u2 name_index);


/*
 * Preenche uma estrutura do tipo attribute_info.
 *
 * Parâmetros:
 *	FILE *pt_arquivo: ponteiro para o .class
 *	cp_info constant_pool[]: constant pool
 *	u2 constant_pool_count: quantidade de elementos na constant pool
 *	attribute_info atributos[]: vetor de atributos
 *	u2 index: índice corrente no vetor de atributos
 *
 * Retorno:
 *       Nada
 */
void criar_attribute(FILE *pt_arquivo, cp_info constant_pool[], u2 constant_pool_count, attribute_info atributos[], u2 index);


/*
 * Salva as informações dos atributos em uma lista do tipo attribute_info
 *
 * Parâmetros:
 *	FILE *pt_arquivo: Ponteiro para o .class
 *	u2 attributes_count: Quantidade de atributos a serem escritos
 *	cp_info constant_pool[]: Constant pool
 *	u2 constant_pool_count: Tamanho da constant pool
 *
 * Retorno:
 *       Ponteiro para a lista de atributos.
 */
attribute_info *carregar_atributos(FILE *pt_arquivo, u2 attributes_count, cp_info constant_pool[], u2 constant_pool_count);


/*
 * As funções a seguir preenchem as suas respectivas estruturas de acordo com
 * as informações lidas do arquivo.
 *
 * Parâmetros:
 *	FILE *pt_arquivo: ponteiro para o arquivo
 *	attribute_info attributes[]: vetor de atributos
 *	u2 index: índice da entrada corrente no vetor de atributos
 *	cp_info constant_pool[]: constant pool
 *	u2 constant_pool_count: tamanho da constant pool
 *
 * Retorno:
 *       Nada
 */
void criar_constant_value_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_code_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_exceptions_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_innner_classes_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_source_file_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void atributo_invalido(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);

/*
 * Desaloca o espaço alocado para o array de attributes
 *
 * Parâmetros:
 *		attribute_info *attributes: ponteiro para o array de attributes
 *		u2 attributes_count: número de attributos para a estrutura em questão
 *
 * Retorno:
 *		Nenhum
 */
void desalocar_atributos(attribute_info *attributes, u2 attributes_count);

/*
 * As funções a seguir desalocam suas respectivas estruturas de acordo com a tag
 * do atributo
 *
 * Parâmetros:
 *		attribute_info *attributes: ponteiro para o array de attributos
 *
 * Retorno:
 *       Nenhum
 */
void desalocar_code_attribute(attribute_info *attributes);
void desalocar_exceptions_attribute(attribute_info *attributes);
void desalocar_innner_classes_attribute(attribute_info *attributes);
/* Fim da declaração dos métodos dos atributos */

#endif /* LEITOR_ATRIBUTOS_H */
