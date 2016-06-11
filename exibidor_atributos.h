#ifndef EXIBIDOR_ATRIBUTOS_H
#define EXIBIDOR_ATRIBUTOS_H

#include "leitor_constant_pool.h"
#include "leitor_atributos.h"
#include "recuperar_constant_pool.h"
#include "instrucoes.h"

//Define tamanho máximo de uma string que mostra o operando de uma instrução
#define TAM_OPERANDO 250

extern t_instrucoes instr[];

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

/*
 * Exibe o número de exceções da classe e os indíces da tabela de exceção do constant_pool
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *	 cp_info constant_pool: a constant pool
 *
 * Retorno:
 *       Nada
 */

void exibir_exception_attribute_table(attribute_info atributo, cp_info constant_pool[]);

/*
 * Exibe todas as informações do atributo exceção
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *	 cp_info constant_pool: a constant pool
 *
 * Retorno:
 *       Nada
 */


void exibir_exception_attribute(attribute_info atributo, cp_info constant_pool[]);


/*
 * Exibe a quantidade de classes dentro da classe
 * Exibe todos os parâmetros de uma classe interna, de todas as classes internas
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *	 cp_info constant_pool: a constant pool
 *
 * Retorno:
 *       Nada
 */
void exibir_inner_classes_attribute_table(attribute_info atributo, cp_info constant_pool[]);

/*
 * Exibe todas as informações do atributo inner_class
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *	 cp_info constant_pool: a constant pool
 *
 * Retorno:
 *       Nada
 */
void exibir_inner_classes_attribute(attribute_info atributo, cp_info constant_pool[]);


/*
 * Exibe o index correspondente ao source_file na constant pool
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *
 * Retorno:
 *       Nada
 */
void exibir_source_file(attribute_info atributo,  cp_info constant_pool[]);

/*
 * Exibe todas as informações do atributo souce_file
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *	 cp_info constant_pool: a constant pool
 *
 * Retorno:
 *       Nada
 */
void exibir_source_file_attribute(attribute_info atributo, cp_info constant_pool[]);

/*
 * Exibe todas as informações do atributo constant_value
 *
 * Parâmetros:
 *       attribute_info atributo: o atributo a ser mostrado
 *
 * Retorno:
 *       Nada
 */
void exibir_constant_attribute(attribute_info atributo,  cp_info constant_pool[]);


void exibe_table_switch(u1 code[], u4 *ref_index);
void exibe_lookup_switch(u1 code[], u4 *ref_index);
char *recupera_operando(cp_info constant_pool[], u1 tipo_operando, u4 tamanho_operando, u1 code[], u4 *ref_index);

#endif
