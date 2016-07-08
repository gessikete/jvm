/*!
   \file leitor_metodos.h
   \brief Protótipo das funções que manipulam a leitura dos métodos.

   Este arquivo contém os protótipos das funções que manipulam a leitura dos
   métodos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

/**
 * \addtogroup leitor
 * @{
 */

#ifndef LEITOR_METODOS_H
#define LEITOR_METODOS_H

#include "types.h"
#include "arquivos.h"
#include "leitor_atributos.h"
#include "leitor_constant_pool.h"

 /*!
    \brief Carrega as estruturas referentes aos métodos.

    \param methods_count Número de methods dessa classe.
    \param constant_pool_count Número de cosntants na constant_pool.
    \param constant_pool Ponteiro para a constant_pool.
    \param pt_arquivo Ponteiro para o arquivo binário da classe.

    \return Ponteiro para array contendo as estruturas dos métodos.
 */
method_info *carregar_methods(u2 methods_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo);

 /*!
    \brief Desaloca o espaço alocado para o array de methods.

    \param methods: ponteiro para o array contendo as estruturas dos métodos.
    \param methods_count Número de methods dessa classe.

    \return Nenhum.
 */
void desalocar_metodos(method_info *methods, u2 methods_count);

#endif /* LEITOR_METODOS_H */

/** @} */ // fim da definição de leitor
