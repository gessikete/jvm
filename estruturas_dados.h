/*!
   \file estruturas_dados.h
   \brief Protótipo das funções para o módulo de estruturas de dados.

   Esse arquivo contém os protótipos para a manipulação de estruturas de dados usadas na execucao
   da JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

/**
 * \defgroup dados Dados
 *
 *  Módulo responsável pela manipulação de pilhas e listas necessárias para o
 *  funcionamento da JVM. Pilhas de frames, operandos, parâmentros, além de suas
 *  estruturas internas, como arrays, objetos, etc.
 *
 * @{
 */

#ifndef ESTRUT_DADOS_H
#define ESTRUT_DADOS_H

#include <stdlib.h>
#include "types.h"
#include "macros.h"
#include "recuperar_constant_pool.h"
#include "leitor_classe.h"


/*!
   \brief Cria uma lista de classes estaticas.

   \param Nenhum.

   \return Ponteiro para lista_classes_estaticas
*/
lista_classes_estaticas *alocar_lista_classes_estaticas();

/*!
   \brief Cria nova classe estatica

   \param pt_classe ponteiro para classe
   \param next  proximo elemento da lista

   \return Ponteiro para uma classe_estatica
*/
classe_estatica *nova_classe_estatica(class_file *pt_classe, classe_estatica  *next);

/*!
   \brief Cria novo elemento na tabela de classes

   \param pt_classe ponteiro para classe
   \param next  proximo elemento da lista

   \return Ponteiro para um elemento_tabela_classes
*/
elemento_tabela_classes *nova_classe(class_file *pt_classe, elemento_tabela_classes *next);


/*!
   \brief Cria um novo objeto

   \param pt_classe ponteiro para classe

   \return Ponteiro para um objeto
*/
t_objeto *novo_objeto(class_file *pt_classe);

/*!
   \brief Cria um novo array

   \param tag tag que identifica o tipo do array
   \param tamanho  tamanho do array
   \param dimensoes dimensao do array

   \return Ponteiro para um array
*/
t_array* criar_array(u1 tag, u2 tamanho, u1 dimensoes);

/*!
   \brief Aloca espaço na memória para uma pilha de operandos.

   \param Nenhum.

   \return Ponteiro para a pilha de operandos.
*/
t_operand_stack* alocar_operand_stack();

/*!
   \brief Aloca um operando para a pilha de operandos.

   \param tag Unsigned int de 8bits com o tipo do operando.
   \param data Unsigned int de 32bits com o operando.

   \return Ponteiro para o operando.
*/
t_operand *alocar_operando(u1 tag, u4 data, t_operand *next);


/*!
   \brief Aloca espaço na memória para uma pilha de parâmetros.

   \param Nenhum.

   \return Ponteiro para a pilha de parâmetros.
*/
t_parameter_stack* alocar_parameter_stack(u1 tag, u4 data);

/*!
   \brief Aloca um parâmetro para a pilha de parametros.

   \param tag Unsigned int de 8bits com o tipo do parametro.
   \param data Unsigned int de 32bits com o parâmetro.

   \return Ponteiro para o parâmetro.
*/
t_parameter *alocar_parametro(u1 tag, u4 data, t_parameter *next);


/*!
   \brief Aloca uma lista de fields

   \param classe ponteiro para a classe que contem os fields

   \return Ponteiro para a lista de fields
*/
t_field *alocar_lista_fields(class_file *classe);

/*!
   \brief Aloca um novo frame na pilha de frames.
    \param this_class ponteiro para a classe onde esta o metodo do frame
   \param lista_fields lista de fields da classe
   \param pilha_parametros pilha dos parametros do metodo
   \param pilha_frames Ponteiro stack_frames para a pilha de frames.
   \param pt_metodo Ponteiro para um method_info struct.
   \param pt_constant_pool Ponteiro para a constant pool.
   \param next Ponteiro para o frame anterior na pilha.

   \return Ponteiro para o frame alocado no topo da pilha.
*/
t_frame *alocar_frame(class_file *this_class, lista_classes_estaticas *classes_estaticas, t_field *lista_fields, t_parameter_stack *pilha_parametros, method_info *pt_metodo, cp_info *pt_constant_pool, t_frame *next);

/*!
   \brief Aloca a pilha de frames.

   \param this_class ponteiro para propria classe
   \param lista_classes_estaticas lista de classes estaticas
   \param lista_fields lista de fields
   \param pilha_parametros pilha de parametros do metodo
   \param pt_metodo  ponteiro para o metodo
   \param pt_constant_pool ponteiro para a constant pool

   \return Ponteiro para a pilha de frames.
*/
stack_frames *alocar_stack_frames(class_file *this_class, lista_classes_estaticas *classes_estaticas, t_field *lista_fields, t_parameter_stack *pilha_parametros, method_info *pt_metodo, cp_info *pt_constant_pool);


/*!
   \brief Desaloca um array da memória.

   \param pt_array Ponteiro para uma estrutura array.

   \return Nenhum.
*/
void desalocar_array(t_array *pt_array);

/*!
   \brief Desaloca um objeto da memória.

   \param pt_objeto Ponteiro para uma estrutura objeto.

   \return Nenhum.
*/
void desalocar_objeto(t_objeto *pt_objeto);

/*!
   \brief Desaloca um field.

   \param pt_fields Ponteiro para uma estrutura t_field.

   \return Nenhum.
*/
void desalocar_fields(t_field *pt_fields);

/*!
   \brief Desaloca uma pilha de operandos da memória.

   \param pt_operand_stack Ponteiro para uma estrutura t_operand_stack.

   \return Nenhum.
*/
void desalocar_operand_stack(t_operand_stack *pt_operand_stack);

/*!
   \brief Desaloca um operando da memória.

   \param pt_operando Ponteiro para uma estrutura t_operand.

   \return Nenhum.
*/
void desalocar_operando(t_operand *pt_operando);

/*!
   \brief Desaloca uma pilha de frames da memória.

   \param pt_stack_frames Ponteiro para uma estrutura stack_frames.

   \return Nenhum.
*/
void desalocar_stack_frames(stack_frames *pt_stack_frames);

/*!
   \brief Desaloca um frame da memória.

   \param pt_frame Ponteiro para uma estrutura t_frame.

   \return Nenhum.
*/
void desalocar_frame(t_frame *pt_frame);

/*!
   \brief Desempilha o operando no topo da pilha de operandos.

   \param pilha_operandos Ponteiro t_operand_stack para a pilha de operandos.

   \return Ponteiro para a estrutura t_operand com o operando do topo da pilha.
*/
t_operand *pop_operando(t_operand_stack *pilha_operandos);

/*!
   \brief Empilha um operando na pilha de operandos.

   \param tag Unsigned int de 8bits com o tipo do operando.
   \param data Unsigned int de 32bits com o operando.
   \param operand_stack Ponteiro t_operand_stack para a pilha de operandos.

   \return Nenhum.
*/
void push_operando(u1 tag, u4 data, t_operand_stack *operand_stack);


/*!
   \brief Desempilha o parametro no topo da pilha de parametros.

   \param pilha_parametros Ponteiro t_parameter_stack para a pilha de parametros.

   \return Ponteiro para a estrutura t_parameter com o operando do topo da pilha.
*/
t_parameter *pop_parametro(t_parameter_stack *pilha_parametros);

/*!
   \brief Empilha um parametro na pilha de parametros.

   \param tag Unsigned int de 8bits com o tipo do parametro.
   \param data Unsigned int de 32bits com o parametro.
   \param parameter_stack Ponteiro t_parameter_stack para a pilha de parametros.

   \return Nenhum.
*/
void push_parametro(u1 tag, u4 data, t_parameter_stack *parameter_stack);

/*!
   \brief Empilha um frame na pilha de frames.

   \param this_class ponteiro para a classe onde esta o metodo do frame
   \param lista_fields lista de fields da classe
   \param pilha_parametros pilha dos parametros do metodo
   \param pt_metodo Ponteiro method_info para a estrutura do método relativo ao frame.
   \param pt_constant_pool Ponteiro cp_info para a constant pool.
   \param pilha_frames Ponteiro stack_frames para a pilha de frames.

   \return Nenhum.
*/
void push_frame(class_file *this_class, lista_classes_estaticas *classes_estaticas, t_field *lista_fields, t_parameter_stack *pilha_parametros, method_info *pt_metodo, cp_info *pt_constant_pool, stack_frames *pilha_frames);

/*!
   \brief Desempilha o frame no topo da pilha de frames.

   \param pilha_frames Ponteiro stack_frames para a pilha de frames.

   \return Ponteiro para a estrutura t_frame com o frame do topo da pilha.
*/
t_frame *pop_frame(stack_frames *pilha_frames);

#endif /* ESTRUT_DADOS_H */

/** @} */ // fim da definição de pilha
