#ifndef EXIBIDOR_ATRIBUTOS_H
#define EXIBIDOR_ATRIBUTOS_H

#include "leitor_constant_pool.h"
#include "leitor_atributos.h"


/*
 * Exibe as informações genéricas do atributo code (índice do nome e o seu tamanho)
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *
 * Retorno:
 *       Nada
 */
void exibir_generic_info(attribute_info atributo);


/*
 * Exibe max_stack, max_locals e code_length do código
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 * 
 * Retorno:
 *       Nada
 */
void exibir_code_attribute_misc(attribute_info atributo);


/*
 * Exibe o código em si.
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *	 cp_info constant_pool: a constant pool
 *
 * Retorno:
 *       Nada
 */
void exibir_code_attribute_bytecode(attribute_info atributo, cp_info constant_pool[]);


/*
 * Exibe a tabela de exceções.
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *	 cp_info constant_pool: a constant pool
 *
 * Retorno:
 *       Nada
 */
void exibir_code_attribute_exception_table(attribute_info atributo, cp_info constant_pool[]);


/*
 * Exibe todas as informações do atributo code
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *	 cp_info constant_pool: a constant pool
 *
 * Retorno:
 *       Nada
 */
void exibir_code_attribute(attribute_info atributo, cp_info constant_pool[]);


#endif