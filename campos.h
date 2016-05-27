#ifndef CAMPOS_H
#define CAMPOS_H

#include "types.h"
#include "atributos.h"
#include "constant_pool.h"

/* Definição das estruturas de campos */
typedef struct {
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info *attributes;  //attributes[attributes_count]
} field_info;
/* Fim da definição das estruturas de campos */

/* Definição dos métodos de campos */
/*
 * Carrega as estruturas referentes aos campos
 *
 * Parâmetros:
 *       u2 fields_count: número de fields dessa classe
 *		 u2 constant_pool_count: número de cosntants na constant_pool
 *		 cp_info *constant_pool: ponteiro para a constant_pool
 *       FILE *pt_arquivo: ponteiro para o arquivo binário da classe
 *
 * Retorno:
 *       field_info *: ponteiro para array contendo as estruturas dos campos
 */
field_info *carregar_fields(u2 fields_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo);
/* Fim da definição dos métodos de campos */
#endif
