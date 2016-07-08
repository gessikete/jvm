/*!
   \file exibidor_constant_pool.h
   \brief Protótipo das funções de manipulação da exibição da constant_pool.

   Esse arquivo contém a protótipo das funções que manipulam a exibição da
   constant_pool.

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
#ifndef EXIBIDOR_CONST_POOL_H
#define EXIBIDOR_CONST_POOL_H

#include "recuperar_constant_pool.h"

 /*!
    \brief Exibe todos os elementos da constant pool.

    \param const_pool Ponteiro para a constant pool.
    \param constant_pool_count Tamanho da constant pool.

    \return Nenhum.
 */
void exibir_constant_pool(cp_info *const_pool, u2 constant_pool_count);

 /*!
    \brief Exibe um unico elemento da constant pool, redirecionando para a função
    que exibe o elemento de acordo com a sua tag.

    \param pt_const_pool Um elemento da constant pool.
    \param index Index para um elemento na constant_pool.

    \return Nenhum.
 */
void exibir_elemento_constant_pool(cp_info *pt_const_pool, u2 index);

 /*!
    \brief Exibe um methodref_info da constant pool no índice informado.

    \param pt_const_pool Um elemento da constant pool.
    \param index Index para um elemento na constant_pool.

    \return Nenhum.
 */
void exibir_methodref_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um class_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_class_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um fieldref_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_fieldref_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um utf8_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_utf8_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um integer_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_integer_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um name_and_type_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_name_and_type_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um float_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_float_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um string_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_string_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um long_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_long_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um double_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_double_info(cp_info *pt_const_pool, u2 index);

/*!
   \brief Exibe um interface_methodref_info da constant pool no índice informado.

   \param pt_const_pool Um elemento da constant pool.
   \param index Index para um elemento na constant_pool.

   \return Nenhum.
*/
void exibir_interface_methodref_info(cp_info *pt_const_pool, u2 index);

 /*!
    \brief Simplesmente informa que é uma entrada que sucede um double ou um long.

    \param index Index para um elemento na constant_pool.

    \return Nenhum.
 */
void exibir_large_numeric(u2 index);


#endif /* EXIBIDOR_CONST_POOL_H */

/** @} */ // fim da definição de exibidor
