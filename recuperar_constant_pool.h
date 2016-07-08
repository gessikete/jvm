/*!
   \file recuperar_constant_pool.h
   \brief Protótipo das funções que manipulam a leitura da constant pool.

   Este arquivo contém os protótipos das funções que manipulam a leitura da
   constant pool.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

/**
 * \defgroup rec_const_pool Recupera constant pool
 *
 *  Módulo responsável pela recuperação de informações da constant pool.
 *
 * @{
 */

#ifndef REC_CONST_POOL_H
#define REC_CONST_POOL_H

#include "leitor_constant_pool.h"

#define TAM_STRING 250 /** Tamanho máximo de uma string*/

/*!
   \brief Lê o campo bytes de um utf8_info e os salva em uma string.

   \param constant_pool[] Ponteiro para a constat pool.
   \param utf8_index Índice do campo utf8.

   \return String da entrada utf8.
*/
char *recupera_utf8(cp_info constant_pool[], u2 utf8_index);

 /*!
    \brief Recupera o nome de uma classe de acordo com o seu indice no constant pool.

    \param pt_const_pool Ponteiro para a constant pool.
    \param class_index Índice da classe.

    \return Ponteiro para o nome da classe.
 */
char *recupera_class_name(cp_info *pt_const_pool, u2 class_index);

 /*!
    \brief Recupera o nome e o tipo de uma estrutura do tipo name_and_type_info
    de acordo com o seu indice.

    \param pt_const_pool Ponteiro para a constant pool.
    \param index Índice da estrutura.

    \return Ponteiro para o nome e descritor concatenados.
 */
char *recupera_name_and_type(cp_info *pt_const_pool, u2 index);

 /*!
    \brief Recupera os bits mais significativos de um unsigned de 64 bits.

    \param bytes Unsigned de 64 bits.

    \return Um unsigned de 32 bits.
 */
u4 recupera_high_bytes(u8 bytes);

/*!
   \brief Recupera os bits menos significativos de um unsigned de 64 bits.

   \param bytes Unsigned de 64 bits.

   \return Um unsigned de 32 bits.
*/
u4 recupera_low_bytes(u8 bytes);

 /*!
    \brief Recupera um valor int na constant pool.

    \param pt_const_pool Ponteiro para a constant pool.
    \param int_index Índice do int.

    \return Int recuperado.
 */
int recupera_int(cp_info *pt_const_pool, u2 int_index);

/*!
   \brief Recupera um valor float na constant pool.

   \param pt_const_pool Ponteiro para a constant pool.
   \param float_index Índice do float.

   \return float recuperado.
*/
float recupera_float(cp_info *pt_const_pool, u2 float_index);

 /*!
    \brief Recupera um valor long na constant pool.

    \param pt_const_pool Ponteiro para a constant pool.
    \param long_index Índice do long.

    \return long recuperado.
 */
long recupera_long(cp_info *pt_const_pool, u2 long_index);

/*!
   \brief Recupera um valor double na constant pool.

   \param pt_const_pool Ponteiro para a constant pool.
   \param index Índice do double.

   \return long recuperado.
*/
double recupera_double(cp_info *pt_const_pool, u2 index);

 /*!
    \brief Recupera a string em utf8_info de acordo com o seu indice no constant pool.

    \param pt_const_pool Ponteiro para a constant pool.
    \param string_index Índice da string.

    \return Um ponteiro para a string em utf8_info.
 */
char *recupera_string(cp_info *pt_const_pool, u2 string_index);

/*!
   \brief Recupera um elemento de acordo com o seu indice no constant pool e o
   retorna como string.

   \param pt_const_pool Ponteiro para a constant pool.
   \param index Índice do elemento.

   \return Um ponteiro para a string que representa o elemento.
*/
char *recupera_elemento_como_string_constant_pool(cp_info *pt_const_pool, u2 index);

#endif /* REC_CONST_POOL_H */

/** @} */ // fim da definição de rec_const_pool
