/*!
   \file leitor_constant_pool.h
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
 * \addtogroup leitor
 * @{
 */

#ifndef LEITOR_CONSTANT_POOL_H
#define LEITOR_CONSTANT_POOL_H

#include <stdlib.h>
#include "types.h"
#include "arquivos.h"
#include "validation.h"

#define TAG_LARGE 254 /** Tag das entradas da constant pool que são precedidas
                          por um double ou um long.*/

#define TAG_0 255 /** Tag da primeira entrada da constant pool (que não é utilizada
                      para facilitar o acesso elementos da const pool*/

 /*!
    \brief Inicializa um vetor de ponteiros para as funcoes de preenchimento dos
    elementos da constant_pool.

    \param funcoes_constant Vetor de ponteiros para as funcoes.

    \return Nenhum.
 */
void inicializar_vetor_funcoes(void (*funcoes_constant[]) (FILE*,cp_info[],u2,u1));

 /*!
    \brief Preenche o constant pool com todos os seus dados.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param cp_info Ponteiro para o array onde esta a constant pool.
    \param tamanho Tamanho da constant_pool.

    \return Nenhum.
 */
void criar_constant_pool(FILE *pt_arquivo, cp_info const_pool[], u2 tamanho);

 /*!
    \brief Preenche a estrutura class_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_class_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche a estrutura fieldref_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_fieldref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche a estrutura utf8_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_utf8_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche a estrutura methodref_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);


 /*!
    \brief Preenche a estrutura string_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_string_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);


 /*!
    \brief Preenche a estrutura interface_methodref_info com os dados fornecidos
    pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_interface_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche a estrutura integer_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_integer_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche a estrutura float_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_float_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche a estrutura long_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_long_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche a estrutura double_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_double_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche a estrutura name_and_type_info com os dados fornecidos pelo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.
    \param const_pool[] Um elemento da constant pool.
    \param index Índice atual de cp_info.

    \return Nenhum.
 */
void criar_name_and_type_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);

 /*!
    \brief Preenche entrada do constant pool com uma tag inválida.

    \param cp_info Ponteiro para o array onde esta a constant pool.
    \param index Índice atual de cp_info.
    \param tag Tag invalida.

    \return Nenhum.
 */
void tag_invalida(cp_info const_pool[], u2 index, u2 tag);

 /*!
    \brief Verifica se tag é um long ou um double.

    \param tag Tag a ser avaliada.

    \return Nenhum.
 */
bool large_numeric(u2 tag);

 /*!
    \brief Preenche a constant pool.

    \param constant_pool_count Tamanho da constant pool.
    \param pt_arquivo Ponteiro para o arquivo .class.

    \return Ponteiro para a constant pool.
 */
cp_info *carregar_constant_pool(u2 constant_pool_count, FILE *pt_arquivo);

 /*!
    \brief Desaloca o espaço alocado para a estrutura constant pool.

    \param constant_pool Ponteiro para a estrutura constant_pool.
    \param constant_pool_count Tamanho da constant pool.

    \return Nenhum.
 */
void desalocar_constant_pool(cp_info *constant_pool, u2 constant_pool_count);

#endif /* LEITOR_CONSTANT_POOL_H */

/** @} */ // fim da definição de leitor
