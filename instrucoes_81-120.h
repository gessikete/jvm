/*!
   \file instrucoes_81-120.h
   \brief Protótipo das funções para o módulo de frames.

   Esse arquivo contém os protótipos das funções que definem as instruções executadas
   pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#ifndef INSTRUCOES_81_120_H
#define INSTRUCOES_81_120_H

#include "instrucoes.h"
#include "pilha_frames.h"
#include "leitor_constant_pool.h"
#include "math.h"

/*!
   \brief Instrução fastore. Desempilha float a ser salvo, o índice e o endereço
   do array onde o float será salvo. Adiciona o valor do float no índice do array e
   empilha o endereço do array float.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fastore(stack_frames *pilha_frames);

/*!
   \brief Instrução dastore. Desempilha double a ser salvo, o índice e o endereço
   do array onde o double será salvo. Adiciona o valor do double no índice do array e
   empilha o endereço do array double.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dastore(stack_frames *pilha_frames);

/*!
   \brief Instrução aastore. Desempilha endereço do subarray a ser salvo, o índice
   e o endereço do array onde o subarray será salvo. Adiciona o endereço do subarray
    no índice do array e empilha o endereço do array.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void aastore(stack_frames *pilha_frames);

/*!
   \brief Instrução bastore. Desempilha byte a ser salvo, o índice e o endereço
   do array onde o byte será salvo. Adiciona o valor do byte no índice do array e
   empilha o endereço do array byte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void bastore(stack_frames *pilha_frames);

/*!
   \brief Instrução castore. Desempilha char a ser salvo, o índice e o endereço
   do array onde o char será salvo. Adiciona o valor do char no índice do array e
   empilha o endereço do array char.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void castore(stack_frames *pilha_frames);

/*!
   \brief Instrução sastore. Desempilha short a ser salvo, o índice e o endereço
   do array onde o short será salvo. Adiciona o valor do short no índice do array e
   empilha o endereço do array short.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void sastore(stack_frames *pilha_frames);

/*!
   \brief Instrução pop. Desempilha um operando da pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void pop(stack_frames *pilha_frames);

/*!
   \brief Instrução pop. Desempilha dois operandos da pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void pop2(stack_frames *pilha_frames);
void dup(stack_frames *pilha_frames);
void dup_x1(stack_frames *pilha_frames);
void dup_x2(stack_frames *pilha_frames);
void dup2(stack_frames *pilha_frames);
void dup2_x1(stack_frames *pilha_frames);
void dup2_x2(stack_frames *pilha_frames);
void swap(stack_frames *pilha_frames);
void iadd(stack_frames *pilha_frames);
void ladd(stack_frames *pilha_frames);
void fadd(stack_frames *pilha_frames);
void dadd(stack_frames *pilha_frames);
void isub(stack_frames *pilha_frames);
void lsub(stack_frames *pilha_frames);
void fsub(stack_frames *pilha_frames);
void dsub(stack_frames *pilha_frames);
void imul(stack_frames *pilha_frames);
void lmul(stack_frames *pilha_frames);
void fmul(stack_frames *pilha_frames);
void dmul(stack_frames *pilha_frames);
void idiv(stack_frames *pilha_frames);
void ldiv_(stack_frames *pilha_frames);
void fdiv(stack_frames *pilha_frames);
void ddiv(stack_frames *pilha_frames);
void irem(stack_frames *pilha_frames);
void lrem(stack_frames *pilha_frames);
void frem(stack_frames *pilha_frames);
void drem_(stack_frames *pilha_frames);
void ineg(stack_frames *pilha_frames);
void lneg(stack_frames *pilha_frames);
void fneg(stack_frames *pilha_frames);
void dneg(stack_frames *pilha_frames);
void ishl(stack_frames *pilha_frames);

#endif /* INSTRUCOES_81_120_H */
