/*!
   \file leitor_classe.h
   \brief Protótipo das funções que manipulam a leitura das classes.

   Este arquivo contém os protótipos das funções que manipulam a leitura das
   classes.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \defgroup leitor Leitura
 *
 *  Leitura da classe com seus métodos, atributos, campos e constant pool.
 *
 * @{
 */
#ifndef LEITOR_CLASSE_H
#define LEITOR_CLASSE_H

#include "types.h"
#include "arquivos.h"
#include "leitor_atributos.h"
#include "leitor_metodos.h"
#include "leitor_campos.h"
#include "validation.h"

#define STR_SIZE 100

 /*!
    \brief Organiza a leitura de todos os elementos da classe.

    \param nome_arquivo Ponteiro para string contendo o nome do arquivo sem a extensão .class.

    \return Ponteiro para a strutura contendo as informações da classe.
 */
class_file *carregar_classe(char *nome_arquivo);

 /*!
    \brief Lê os valores referentes aos índices para a constant_pool das interfaces.

    \param interfaces_count Número de interfaces dessa classe.
    \param pt_arquivo Ponteiro para o arquivo binário da classe.

    \return ponteiro para array com índices das interfaces.
 */
u2 *ler_interfaces(u2 interfaces_count, FILE *pt_arquivo);

 /*!
    \brief Desaloca o espaço alocado para o array de interfaces.

    \param pt_interfaces Ponteiro para o array de interfaces.

    \return Nenhum.
 */
void desalocar_interfaces(u2 *pt_interfaces);

 /*!
    \brief Desaloca o espaço alocado para a estrutura da classe.

    \param pt_classe Ponteiro para a estrutura contento as informações da classe.

    \return Nenhum.
 */
void desalocar_classe(class_file *pt_classe);

#endif /* LEITOR_CLASSE_H */

/** @} */ // fim da definição de leitor
