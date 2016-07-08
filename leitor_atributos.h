/*!
   \file leitor_atributos.h
   \brief Protótipo das funções que manipulam a leitura dos atributos.

   Este arquivo contém os protótipos das funções que manipulam a leitura dos
   atributos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \addtogroup leitor Leitura
 * @{
 */
#ifndef LEITOR_ATRIBUTOS_H
#define LEITOR_ATRIBUTOS_H

#include <string.h>
#include "types.h"
#include "macros.h"
#include "recuperar_constant_pool.h"

//! Ponteiro para funções
/*! Define um ponteiro para as funções de criação de atributos. */
typedef void (*funcoes_criar) (FILE*,attribute_info[],u2,cp_info[],u2);

/*!
   \brief Compara o nome do atributo com o atributo na constant pool e retorna a
   função de criação adequada para o tipo de atributo em questão.

   \param constant_pool[] A constant pool.
   \param name_index Índice do nome do atributo na constant pool.

   \return A função de criação de atributos correspondente ao nome do atributo.
*/
funcoes_criar escolher_funcao(cp_info constant_pool[], u2 name_index);

 /*!
    \brief Preenche uma estrutura do tipo attribute_info.

    \param pt_arquivo Ponteiro para o .class.
    \param constant_pool[] Constant pool.
    \param constant_pool_count Quantidade de elementos na constant pool.
    \param atributos[] Vetor de atributos.
    \param index Índice corrente no vetor de atributos.

    \return Nenhum.
 */
void criar_attribute(FILE *pt_arquivo, cp_info constant_pool[], u2 constant_pool_count, attribute_info atributos[], u2 index);

 /*!
    \brief Salva as informações dos atributos em uma lista do tipo attribute_info.

    \param pt_arquivo Ponteiro para o .class.
    \param attributes_count Quantidade de atributos a serem escritos.
    \param constant_pool[] Constant pool.
    \param constant_pool_count Tamanho da constant pool.

    \return Ponteiro para a lista de atributos.
 */
attribute_info *carregar_atributos(FILE *pt_arquivo, u2 attributes_count, cp_info constant_pool[], u2 constant_pool_count);

/*!
   \brief Preenche a estrutura de constant value com as informações lidas do arquivo.

   \param pt_arquivo Ponteiro para o arquivo.
   \param attributes[] Vetor de atributos.
   \param index Índice da entrada corrente no vetor de atributos.
   \param constant_pool[] Constant pool.
   \param constant_pool_count Tamanho da constant pool.

   \return Nenhum
*/
void criar_constant_value_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);

/*!
   \brief Preenche a estrutura de code com as informações lidas do arquivo.

   \param pt_arquivo Ponteiro para o arquivo.
   \param attributes[] Vetor de atributos.
   \param index Índice da entrada corrente no vetor de atributos.
   \param constant_pool[] Constant pool.
   \param constant_pool_count Tamanho da constant pool.

   \return Nenhum
*/
void criar_code_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);

/*!
   \brief Preenche a estrutura de exceptions com as informações lidas do arquivo.

   \param pt_arquivo Ponteiro para o arquivo.
   \param attributes[] Vetor de atributos.
   \param index Índice da entrada corrente no vetor de atributos.
   \param constant_pool[] Constant pool.
   \param constant_pool_count Tamanho da constant pool.

   \return Nenhum
*/
void criar_exceptions_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);

/*!
   \brief Preenche a estrutura de inner classes com as informações lidas do arquivo.

   \param pt_arquivo Ponteiro para o arquivo.
   \param attributes[] Vetor de atributos.
   \param index Índice da entrada corrente no vetor de atributos.
   \param constant_pool[] Constant pool.
   \param constant_pool_count Tamanho da constant pool.

   \return Nenhum
*/
void criar_innner_classes_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);

/*!
   \brief Preenche a estrutura de source file com as informações lidas do arquivo.

   \param pt_arquivo Ponteiro para o arquivo.
   \param attributes[] Vetor de atributos.
   \param index Índice da entrada corrente no vetor de atributos.
   \param constant_pool[] Constant pool.
   \param constant_pool_count Tamanho da constant pool.

   \return Nenhum
*/
void criar_source_file_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);

/*!
   \brief Preenche a estrutura de atributo inválido com as informações lidas do arquivo.

   \param pt_arquivo Ponteiro para o arquivo.
   \param attributes[] Vetor de atributos.
   \param index Índice da entrada corrente no vetor de atributos.
   \param constant_pool[] Constant pool.
   \param constant_pool_count Tamanho da constant pool.

   \return Nenhum
*/
void atributo_invalido(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);

 /*!
    \brief Desaloca o espaço alocado para o array de attributes.

    \param attributes Ponteiro para o array de attributes
    \param attributes_count Número de attributos para a estrutura em questão.

    \return Nenhum.
 */
void desalocar_atributos(attribute_info *attributes, u2 attributes_count);

 /*!
    \brief Desaloca uma estrutura de code attibute.

    \param code_info Ponteiro para o array de code info.

    \return Nenhum.
 */
void desalocar_code_attribute(code_attribute *code_info);

 /*!
    \brief Desaloca uma estrutura de exceptions attribute.

    \param exception_info Ponteiro para o array de excepton info.

    \return Nenhum.
 */
void desalocar_exceptions_attribute(exceptions_attribute *exception_info);

 /*!
    \brief Desaloca uma estrutura de inner classes attribute.

    \param inner_classes_info Ponteiro para o array de inner classes info.

    \return Nenhum.
 */
void desalocar_innner_classes_attribute(inner_classes_attribute *inner_classes_info);

#endif /* LEITOR_ATRIBUTOS_H */

/** @} */ // fim da definição de leitor
