/*!
   \file leitor_campos.h
   \brief Protótipo das funções que manipulam a leitura dos campos.

   Este arquivo contém os protótipos das funções que manipulam a leitura dos
   campos.

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

#ifndef LEITOR_CAMPOS_H
#define LEITOR_CAMPOS_H

#include "types.h"
#include "leitor_atributos.h"
#include "leitor_constant_pool.h"

 /*!
    \brief Carrega as estruturas referentes aos campos

    \param fields_count Número de fields dessa classe.
    \param constant_pool_count Número de cosntants na constant_pool.
    \param constant_pool Ponteiro para a constant_pool.
    \param pt_arquivo Ponteiro para o arquivo binário da classe.

    \return Ponteiro para array contendo as estruturas dos campos.
 */
field_info *carregar_fields(u2 fields_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo);

 /*!
    \brief Desaloca o espaço alocado para a estrutura de campos.

    \param fields Ponteiro para array contendo as estruturas dos campos.
    \param fields_count Número de fields dessa classe.

    \return Nenhum.
 */
void desalocar_campos(field_info *fields, u2 fields_count);

#endif /* LEITOR_CAMPOS_H */

/** @} */ // fim da definição de leitor
