/*!
   \file exibidor_atributos.h
   \brief Protótipo das funções de manipulação da exibição de atributos.

   Esse arquivo contém o protótipo das funções que manipulam a exibição de
   atributos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \addtogroup exibidor
 * @{
 */
#ifndef EXIBIDOR_ATRIBUTOS_H
#define EXIBIDOR_ATRIBUTOS_H

#include "types.h"
#include "macros.h"
#include "instrucoes.h"

/** Define tamanho máximo de uma string que mostra o operando de uma instrução */
#define TAM_OPERANDO 250

/*!< Variável externa que define o vetor de instruções. */
extern t_instrucoes instr[];

 /*!
    \brief Exibe as informações genéricas do atributo code (índice do nome e o
    seu tamanho).

    \param atributo O atributo a ser mostrado.

    \return Nenhum.
 */
void exibir_generic_info(attribute_info atributo);

 /*!
    \brief Exibe max_stack, max_locals e code_length do código.

    \param atributo O atributo a ser mostrado.

    \return Nenhum.
 */
void exibir_code_attribute_misc(attribute_info atributo);

 /*!
    \brief Exibe o código em si.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_code_attribute_bytecode(attribute_info atributo, cp_info constant_pool[]);

 /*!
    \brief Exibe a tabela de exceções.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_code_attribute_exception_table(attribute_info atributo, cp_info constant_pool[]);

 /*!
    \brief Exibe todas as informações do atributo code.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_code_attribute(attribute_info atributo, cp_info constant_pool[]);

 /*!
    \brief Exibe o número de exceções da classe e os indíces da tabela de exceção
    do constant_pool.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_exception_attribute_table(attribute_info atributo, cp_info constant_pool[]);

 /*!
    \brief Exibe todas as informações do atributo exceção.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_exception_attribute(attribute_info atributo, cp_info constant_pool[]);

 /*!
    \brief Exibe a quantidade de classes dentro da classe e todos os parâmetros
    de uma classe interna, de todas as classes internas.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_inner_classes_attribute_table(attribute_info atributo, cp_info constant_pool[]);

 /*!
    \brief Exibe todas as informações do atributo inner_class.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_inner_classes_attribute(attribute_info atributo, cp_info constant_pool[]);

 /*!
    \brief Exibe o index correspondente ao source_file na constant pool.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_source_file(attribute_info atributo,  cp_info constant_pool[]);

 /*!
    \brief Exibe todas as informações do atributo souce_file.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_source_file_attribute(attribute_info atributo, cp_info constant_pool[]);

 /*!
    \brief Exibe todas as informações do atributo constant_value.

    \param atributo O atributo a ser mostrado.
    \param constant_pool A constant pool.

    \return Nenhum.
 */
void exibir_constant_attribute(attribute_info atributo,  cp_info constant_pool[]);

/*!
   \brief Exibe todas as informações do atributo table_switch.

   \param code Code do método.
   \param ref_index Referência para o índex.

   \return Nenhum.
*/
void exibe_table_switch(u1 code[], u4 *ref_index);

/*!
   \brief Exibe todas as informações do atributo lookup_switch.

   \param code Code do método.
   \param ref_index Referência para o índex.

   \return Nenhum.
*/
void exibe_lookup_switch(u1 code[], u4 *ref_index);

/*!
   \brief Recupera um operando da constant_pool.

   \param constant_pool A constant pool.
   \param tipo_operando Tipo do operando a ser recuperado.
   \param tamanho_operando Tamanho do operando a ser recuperado.
   \param code Code do método.
   \param ref_index Referência para o índex.

   \return Ponteiro para a string do operando resgatado da constant_pool.
*/
char *recupera_operando(cp_info constant_pool[], u1 tipo_operando, u4 tamanho_operando, u1 code[], u4 *ref_index);

#endif /* EXIBIDOR_ATRIBUTOS_H */

/** @} */ // fim da definição de exibidor
