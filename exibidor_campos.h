/*!
   \file exibidor_campos.h
   \brief Protótipo das funções de manipulação da exibição de campos.

   Esse arquivo contém o protótipo das funções que manipulam a exibição de
   campos.

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
#ifndef EXIBIDOR_CAMPOS_H
#define EXIBIDOR_CAMPOS_H

#include "recuperar_constant_pool.h"

/*!
   \brief Exibe os campos de uma classe.

   \param fields Fields a serem exibidos.
   \param fields_count Número de fields a serem exibidos.
   \param constant_pool A constant pool.

   \return Nenhum
*/
void exibir_fields(field_info *fields, u2 fields_count, cp_info *const_pool);

#endif /* EXIBIDOR_CAMPOS_H */

/** @} */ // fim da definição de exibidor
