/*!
   \file instrucoes_81-120.h
   \brief Protótipo das funções que implementam as instruções da Máquina Virtual
   Java.

   Esse arquivo contém os protótipos das funções que definem as instruções executadas
   pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \addtogroup instrucoes
 * @{
 */
#ifndef INSTRUCOES_81_120_H
#define INSTRUCOES_81_120_H

#include "instrucoes.h"
#include "estruturas_dados.h"
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

/*!
   \brief Instrução dup. NÃO IMPLEMENTADA.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dup(stack_frames *pilha_frames);

/*!
   \brief Instrução dup_x1. NÃO IMPLEMENTADA.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dup_x1(stack_frames *pilha_frames);

/*!
   \brief Instrução dup_x2. NÃO IMPLEMENTADA.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dup_x2(stack_frames *pilha_frames);

/*!
   \brief Instrução dup2. NÃO IMPLEMENTADA.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dup2(stack_frames *pilha_frames);

/*!
   \brief Instrução dup2_x1. NÃO IMPLEMENTADA.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dup2_x1(stack_frames *pilha_frames);

/*!
   \brief Instrução dup2_x2. NÃO IMPLEMENTADA.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dup2_x2(stack_frames *pilha_frames);

/*!
   \brief Instrução swap. NÃO IMPLEMENTADA.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void swap(stack_frames *pilha_frames);

/*!
   \brief Dois int são desempilhados da pilha de operandos e o resultado da soma
   dos dois int é empilhada na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void iadd(stack_frames *pilha_frames);

/*!
   \brief Dois long são desempilhados da pilha de operandos e o resultado da soma
   dos dois long é empilhada na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ladd(stack_frames *pilha_frames);

/*!
   \brief Dois float são desempilhados da pilha de operandos e o resultado da soma
   dos dois float é empilhada na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fadd(stack_frames *pilha_frames);

/*!
   \brief Dois double são desempilhados da pilha de operandos e o resultado da soma
   dos dois double é empilhada na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dadd(stack_frames *pilha_frames);

/*!
   \brief Dois int são desempilhados da pilha de operandos e o resultado da diferença
   entre o segundo int a ser desempilhado e o primeiro é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void isub(stack_frames *pilha_frames);

/*!
   \brief Dois long são desempilhados da pilha de operandos e o resultado da diferença
   entre o segundo long a ser desempilhado e o primeiro é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lsub(stack_frames *pilha_frames);

/*!
   \brief Dois float são desempilhados da pilha de operandos e o resultado da diferença
   entre o segundo float a ser desempilhado e o primeiro é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fsub(stack_frames *pilha_frames);

/*!
   \brief Dois double são desempilhados da pilha de operandos e o resultado da diferença
   entre o segundo double a ser desempilhado e o primeiro é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dsub(stack_frames *pilha_frames);

/*!
   \brief Dois int são desempilhados da pilha de operandos e o resultado do produto
   dos dois int é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void imul(stack_frames *pilha_frames);

/*!
   \brief Dois long são desempilhados da pilha de operandos e o resultado do produto
   dos dois long é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lmul(stack_frames *pilha_frames);

/*!
   \brief Dois float são desempilhados da pilha de operandos e o resultado do produto
   dos dois float é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fmul(stack_frames *pilha_frames);

/*!
   \brief Dois double são desempilhados da pilha de operandos e o resultado do produto
   dos dois double é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dmul(stack_frames *pilha_frames);

/*!
   \brief Dois int são desempilhados da pilha de operandos e o resultado da divisão
   entre o segundo int a ser desempilhado e o primeiro é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void idiv(stack_frames *pilha_frames);

/*!
   \brief Dois long são desempilhados da pilha de operandos e o resultado da divisão
   entre o segundo long a ser desempilhado e o primeiro é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ldiv_(stack_frames *pilha_frames);

/*!
   \brief Dois float são desempilhados da pilha de operandos e o resultado da divisão
   entre o segundo float a ser desempilhado e o primeiro é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fdiv(stack_frames *pilha_frames);

/*!
   \brief Dois double são desempilhados da pilha de operandos e o resultado da divisão
   entre o segundo double a ser desempilhado e o primeiro é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ddiv(stack_frames *pilha_frames);

/*!
   \brief Dois int são desempilhados da pilha de operandos e o resultado do módulo
   entre o segundo int a ser desempilhado e o primeiro é um int empilhado na pilha
   de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void irem(stack_frames *pilha_frames);

/*!
   \brief Dois long são desempilhados da pilha de operandos e o resultado do módulo
   entre o segundo long a ser desempilhado e o primeiro é um long empilhado na pilha
   de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lrem(stack_frames *pilha_frames);

/*!
   \brief Dois float são desempilhados da pilha de operandos e o resultado do módulo
   entre o segundo float a ser desempilhado e o primeiro é um float empilhado na pilha
   de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void frem(stack_frames *pilha_frames);

/*!
   \brief Dois double são desempilhados da pilha de operandos e o resultado do módulo
   entre o segundo double a ser desempilhado e o primeiro é um double empilhado na pilha
   de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void drem_(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e empilha o valor negado de volta
   na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ineg(stack_frames *pilha_frames);

/*!
   \brief Desempilha um long da pilha de operandos e empilha o valor negado de volta
   na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lneg(stack_frames *pilha_frames);

/*!
   \brief Desempilha um float da pilha de operandos e empilha o valor negado de volta
   na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fneg(stack_frames *pilha_frames);

/*!
   \brief Desempilha um double da pilha de operandos e empilha o valor negado de volta
   na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dneg(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. O segundo int a ser desempilhado
   é shiftado s posições para a esquerda, sendo s os 5bits menos significativos
   do primeiro int desempilhado. Então, o resultado é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ishl(stack_frames *pilha_frames);

#endif /* INSTRUCOES_81_120_H */

/** @} */ // fim da definição de instrucoes
