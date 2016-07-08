/*!
   \file arquivos.h
   \brief Protótipo das funções para o módulo de manipulação de arquivos.

   Esse arquivo contém os protótipos das funções que definem as manipulações de
   arquivos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \defgroup arquivos Manipulação de Arquivos
 *
 *  Módulo responsável pela manipulação do arquivo .class passado por parâmetro
 *  e leitura dos seus dados.
 *
 * @{
 */
#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <stdio.h>
#include "types.h"

 /*!
    \brief Abre arquivo para leitura.

    \param nome_arquivo Ponteiro para string contendo o nome do arquivo.

    \return Ponteiro para o arquivo aberto.
 */
FILE *abrir_arquivo_leitura(char *nome_arquivo);

 /*!
    \brief Fecha arquivo aberto.

    \param pt_arquivo Poonteiro para o arquivo aberto.

    \return Nenhum.
 */
void fechar_arquivo(FILE *pt_arquivo);

 /*!
    \brief Lê um byte do arquivo .class.

    \param pt_arquivo Ponteiro para o arquivo aberto.

    \return Byte lido.
 */
u1 ler_u1(FILE *pt_arquivo);

 /*!
    \brief Lê 2 bytes do arquivo .class e os coloca em little endian order.

    \param pt_arquivo Ponteiro para o arquivo aberto.

    \return 2 bytes do arquivo em little endian order.
 */
u2 ler_u2(FILE *pt_arquivo);

 /*!
    \brief Lê 4 bytes do arquivo .class e os coloca em little endian order.

    \param pt_arquivo Ponteiro para o arquivo aberto.

    \return 4 bytes do arquivo em little endian order.
 */
u4 ler_u4(FILE *pt_arquivo);

 /*!
    \brief Lê 8 bytes do arquivo .class e os coloca em little endian order.

    \param pt_arquivo Ponteiro para o arquivo aberto.

    \return 8 bytes do arquivo em little endian order.
 */
u8 ler_u8(FILE *pt_arquivo);

#endif /* ARQUIVOS_H */

/** @} */ // fim da definição de arquivos
