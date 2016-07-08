/*!
   \file exibidor_metodos.h
   \brief Protótipo das funções de manipulação da exibição de métodos.

   Esse arquivo contém o protótipo das funções que manipulam a exibição de
   métodos.

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
#ifndef EXIBIDOR_METODOS_H
#define EXIBIDOR_METODOS_H

#include "types.h"
#include "macros.h"
#include "exibidor_atributos.h"

/*!
   \brief Exibe os métodos de uma classe.

   \param methods Métodos a serem exibidos.
   \param methods_count Número de métodos a serem exibidos.
   \param constant_pool A constant pool.

   \return Nenhum
*/
void exibir_methods(method_info *methods, u2 methods_count, cp_info *const_pool);

#endif /* EXIBIDOR_METODOS_H */

/** @} */ // fim da definição de exibidor
