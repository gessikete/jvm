#ifndef LEITOR_CAMPOS_H
#define LEITOR_CAMPOS_H

#include "types.h"
#include "leitor_atributos.h"
#include "leitor_constant_pool.h"

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

/*
 * Desaloca o espaço alocado para a estrutura de campos
 *
 * Parâmetros:
 *		field_info *fields: ponteiro para array contendo as estruturas dos campos
 *		u2 fields_count: número de fields dessa classe
 *
 * Retorno:
 *		Nenhum
 */
void desalocar_campos(field_info *fields, u2 fields_count);

/* Fim da definição dos métodos de campos */
#endif /* LEITOR_CAMPOS_H */
