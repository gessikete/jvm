/*!
   \file validation.h
   \brief Protótipo das funções que validam o .class.

   Este arquivo contém os protótipos das funções que validam o arquivo .class
   passado como parâmetro de acordo com o .class gerado através do comando
   <javac {arquivo.java} -source 1.2 -target 1.2>

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

/**
 * \defgroup validation Validação
 *
 *  Módulo responsável validação do formato .class.
 *
 * @{
 */

#ifndef VALIDATION_H
#define VALIDATION_H

#include "types.h"
#include "macros.h"
#include "recuperar_constant_pool.h"
#include "string.h"

 /*!
    \brief Valida o número mágico.

    \param magic Valor do magic number.

    \return Falso, no caso de magic number inválido. True, no caso de magic number válido.
 */
bool validar_magic(u4 magic);

 /*!
    \brief Verifica se nome do arquivo é igual ao nome do atributo sourcefile

    \param constant_pool ponteiro para a constant_pool
    \param attributes_count quantidade de atributos
    \param attributes  ponteiro para os atributos
    \param nome_arquivo nome do arquivo

    \return Falso, no caso nomes sejam diferentes 
 */
bool validar_nome(cp_info *constant_pool, u2 attributes_count, attribute_info *attributes, char *nome_arquivo);

 /*!
    \brief Valida as versões minor e major.

    Valida as versões minor e major. Para k ≥ 2, JDK release 1.k suporta formatos
    de arquivos class entre 45.0 e 44+k.0, incluindo as extremidades.

    \param minor Minor version number.
    \param u2 major Major version number.

    \return Falso, no caso de versão inválida. True, no caso de versão válida.
 */
bool validar_version(u2 minor, u2 major);

 /*!
    \brief Verifica se a tag lida é válida.

    \param tag Tag a ser verificada.

    \return Falso, caso tag seja inválida, ou true, caso seja válida.
 */
bool validar_tag(u2 tag);

 /*!
    \brief Verifica se as access flags lidas são válida.

    \param flags Tag a ser verificada.

    \return Falso, caso alguma access flag seja inválida, ou true, caso todas sejam válidas.
 */
bool validar_access_flag(u2 flags);

#endif /* VALIDATION_H */

/** @} */ // fim da definição de validation
