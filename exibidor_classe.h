/*!
   \file exibidor_classe.h
   \brief Protótipo das funções de manipulação da exibição de campos.

   Esse arquivo contém o protótipo das funções que manipulam a exibição da classe.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \defgroup exibidor Exibição
 *
 *  Exibição de classe com seus métodos, atributos, campos e constant pool.
 *
 * @{
 */
#ifndef EXIBIDOR_CLASSE_H
#define EXIBIDOR_CLASSE_H

#include "exibidor_constant_pool.h"
#include "exibidor_campos.h"
#include "exibidor_metodos.h"
#include "exibidor_atributos.h"

 /*!
    \brief Recebe a estrutura lida de class file e exibe na tela os binários.

    \param cf Ponteiro para a estrutura do .class.

    \return Nenhum.
 */
void exibir_classe(class_file* cf);

 /*!
    \brief Exibe as interfaces da classe.

    \param interfaces Ponteiro para o array de índices das interfaces.
    \param interfaces_count Número de interfaces dessa classe.
    \param const_pool Ponteiro para a constant pool.

    \return Nenhum.
 */
void exibir_interfaces(u2 *interfaces, u2 interfaces_count, cp_info *const_pool);

 /*!
    \brief Exibe informações gerais sobre this class e super class.

    \param tipo Tipo de classe a ser exibida, texto a ser EXIBIDOR.
    \param class_index Íncide da classe para a constant Pool.
    \param const_pool Ponteiro para a constant POOL.

    \return Nenhum.
 */
void exibir_tipo_classe(char *tipo, u2 classe_index, cp_info *const_pool);

#endif /* EXIBIDOR_CLASSE_H */

/** @} */ // fim da definição de exibidor
