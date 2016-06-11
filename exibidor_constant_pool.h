#ifndef EXIBIDOR_CONST_POOL_H
#define EXIBIDOR_CONST_POOL_H

#include "leitor_constant_pool.h"
#include "recuperar_constant_pool.h"
#include <string.h>
/*
 * Exibe todos os elementos da constant pool
 *
 * Parâmetros:
 * 	cp_info *const_pool: ponteiro para a constant pool;
 * 	u2 constant_pool_count: tamanho da constant pool.
 *
 * Retorno:
 *       Nada
 */
void exibir_constant_pool(cp_info *const_pool, u2 constant_pool_count);


/*
 * Exibe um unico elemento da constant pool, redirecionando para a funcao que exibe
 * o elemento de acordo com a sua tag.
 *
 * Parâmetros:
 * 	cp_info const_pool: Um elemento da constant pool.
 *
 * Retorno:
 *       Nada
 */
void exibir_elemento_constant_pool(cp_info *pt_const_pool, u2 index);


/*
 * Todas as funcoes a seguir exibem todos os campos de um elemento da constant pool.
 *
 * Parâmetros:
 * 	cp_info const_pool: Um elemento da constant pool.
 *
 * Retorno:
 *       Nada
 */
void exibir_methodref_info(cp_info *pt_const_pool, u2 index);
void exibir_class_info(cp_info *pt_const_pool, u2 index);
void exibir_fieldref_info(cp_info *pt_const_pool, u2 index);
void exibir_utf8_info(cp_info *pt_const_pool, u2 index);
void exibir_integer_info(cp_info *pt_const_pool, u2 index);
void exibir_name_and_type_info(cp_info *pt_const_pool, u2 index);
void exibir_float_info(cp_info *pt_const_pool, u2 index);
void exibir_string_info(cp_info *pt_const_pool, u2 index);
void exibir_long_info(cp_info *pt_const_pool, u2 index);
void exibir_double_info(cp_info *pt_const_pool, u2 index);
void exibir_interface_methodref_info(cp_info *pt_const_pool, u2 index);


/*
 * Simplesmente informa que é uma entrada que sucede um double ou um long.
 *
 * Parâmetros:
 * 	Index: indice na constant pool
 *
 * Retorno:
 *       Nada
 */
void exibir_large_numeric(u2 index);


#endif /* EXIBIDOR_CONST_POOL_H */
