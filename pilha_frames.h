/*!
   \file pilha_frames.h
   \brief Protótipo das funções para o módulo de frames.

   Esse arquivo contém os protótipos para a manipulação das pilhas de frames e
   operandos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#ifndef PILHA_FRAMES_H
#define PILHA_FRAMES_H

#include <stdlib.h>
#include "types.h"
#include "macros.h"
#include "recuperar_constant_pool.h"
#include "leitor_classe.h"


/*!
   \brief Cria um novo array

   \param tag tag que identifica o tipo do array
   \param tamanho  tamanho do array
   \param dimensoes dimensao do array

   \return Ponteiro para um array
*/
t_array* criar_array(u1 tag, u2 tamanho, u1 dimensoes);

/*!
   \brief Aloca uma lista de objetos.

   \param Nenhum.

   \return Ponteiro para uma lista de objetos.
*/
elemento_lista_objetos* alocar_lista_objetos();

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
   \brief Aloca um novo frame na pilha de frames.

   \param pt_metodo Ponteiro para um method_info struct.
   \param pt_constant_pool Ponteiro para a constant pool.
   \param next Ponteiro para o frame anterior na pilha.

   \return Ponteiro para o frame alocado no topo da pilha.
*/
t_frame *alocar_frame(method_info *pt_metodo, cp_info *pt_constant_pool, t_frame *next);

/*!
   \brief Aloca a pilha de frames.

   \param Nenhum.

   \return Ponteiro para a pilha de frames.
*/
stack_frames *alocar_stack_frames();

/*!
   \brief Desaloca a lista de objetos da memória.

   \param lista_objetos Ponteiro para uma lista elemento_lista_objetos.

   \return Nenhum.
*/
void desalocar_lista_objetos(elemento_lista_objetos *lista_objetos);

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
void desalocar_objeto(objeto *pt_objeto);

/*!
   \brief Desaloca um frame corrente da memória.

   \param pt_runtime_fields Ponteiro para uma estrutura runtime_field.

   \return Nenhum.
*/
void desalocar_runtime_fields(runtime_field *pt_runtime_fields);

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
   \brief Empilha um frame na pilha de frames.

   \param pt_metodo Ponteiro method_info para a estrutura do método relativo ao frame.
   \param pt_constant_pool Ponteiro cp_info para a constant pool.
   \param pilha_frames Ponteiro stack_frames para a pilha de frames.

   \return Nenhum.
*/
void push_frame(method_info *pt_metodo, cp_info *pt_constant_pool, stack_frames *pilha_frames);

/*!
   \brief Desempilha o frame no topo da pilha de frames.

   \param pilha_frames Ponteiro stack_frames para a pilha de frames.

   \return Ponteiro para a estrutura t_frame com o frame do topo da pilha.
*/
t_frame *pop_frame(stack_frames *pilha_frames);

#endif /* PILHA_FRAMES_H */
