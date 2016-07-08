/*!
   \file recuperar_classe.h
   \brief Protótipo das funções que recuperam classes referenciadas pelo
   arquivo classe informado.

   Este arquivo contém os protótipos das funções que recuperam classes referenciadas pelo
   arquivo classe informado. Essas referências são feitas através de métodos utilizados
   pelo arquivo .class principal.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

/**
 * \defgroup rec_classe Classes referenciadas
 *
 *  Módulo responsável pela manipulação e busca de elementos relacionado a classes
 *  referenciadas pelos métodos do arquivo .class passado por parâmetro.
 *
 * @{
 */

#ifndef REC_CLASSE_H
#define REC_CLASSE_H

#include <string.h>
#include "types.h"
#include "recuperar_constant_pool.h"
#include "leitor_classe.h"
#include "estruturas_dados.h"
#include "execucao_jvm.h"

/*!
   \brief

   \param descritor
   \param operand_stack

   \return Ponteiro para a pilha de parâmetros de um método.
*/
t_parameter_stack *carregar_parameter_stack(char *descritor, t_operand_stack *operand_stack);

/*!
   \brief

   \param classe
   \param frame
   \param class_name
   \param field_name
   \param descriptor

   \return Ponteiro para a estrutura de field.
*/
t_field *busca_field_classe_estatica(class_file *classe, t_frame *frame, char *class_name, char *field_name, char *descriptor);

/*!
   \brief

   \param pt_classe
   \param lista_classes

   \return Ponteiro para a classe estática encontrada.
*/
classe_estatica *busca_classe_estatica(class_file *pt_classe, classe_estatica *lista_classes);

/*!
   \brief

   \param lista_fields
   \param tamanho_lista_fields
   \param pt_constant_pool
   \param field_name
   \param descriptor

   \return Ponteiro para a classe estática encontrada.
*/
t_field *busca_field(t_field *lista_fields, u2 tamanho_lista_fields, cp_info *pt_constant_pool, char *field_name, char *descriptor);

/*!
   \brief

   \param nome_classe
   \param lista_classes

   \return Ponteiro para a classe buscada.
*/
class_file *busca_classe(char *nome_classe, elemento_tabela_classes *lista_classes);

/*!
   \brief Recupera um método em uma classe a partir do seu nome e descritor.

   \param classe Ponteiro para estutura de classe onde o método será procurado.
   \param method_name String com o nome do método procurado.
   \param method_descriptor descriptor do método procurado.

   \return Ponteiro para a estrutura do método buscado.
*/
method_info *recupera_metodo(class_file **classe, char *method_name, char *method_descriptor);

#endif /* REC_CLASSE_H */

/** @} */ // fim da definição de rec_classe
