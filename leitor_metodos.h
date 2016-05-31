#ifndef LEITOR_METODOS_H
#define LEITOR_METODOS_H

#include "types.h"
#include "arquivos.h"
#include "leitor_atributos.h"
#include "leitor_constant_pool.h"
#include "vetor_mnemonicos.h"

/* Definição das estruturas de métodos */
typedef struct {
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info *attributes;			//attributes[attributes_count]
} method_info;

/* Fim da definição das estruturas de métodos */

/* Declaração dos métodos */
/*
 * Carrega as estruturas referentes aos métodos
 *
 * Parâmetros:
 *       u2 methods_count: número de methods dessa classe
 *		 u2 constant_pool_count: número de cosntants na constant_pool
 *		 cp_info *constant_pool: ponteiro para a constant_pool
 *       FILE *pt_arquivo: ponteiro para o arquivo binário da classe
 *
 * Retorno:
 *       method_info *: ponteiro para array contendo as estruturas dos métodos
 */
method_info *carregar_methods(u2 methods_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo);

/*
 * Desaloca o espaço alocado para o array de methods
 *
 * Parâmetros:
 *		method_info *methods: ponteiro para o array contendo as estruturas dos métodos
 *		u2 methods_count: número de methods dessa classe
 * Retorno:
 *		Nenhum
 */
void desalocar_metodos(method_info *methods, u2 methods_count);
/* Fim da declaração dos métodos */

#endif /* LEITOR_METODOS_H */
