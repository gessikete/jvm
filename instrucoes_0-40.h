/*!
   \file instrucoes_0-40.h
   \brief Protótipo das funções para o módulo de frames.

   Esse arquivo contém os protótipos das funções que definem as instruções executadas
   pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#ifndef INSTRUCOES_0_40_H
#define INSTRUCOES_0_40_H

#include "instrucoes.h"
#include "pilha_frames.h"
#include "leitor_constant_pool.h"

void nop(stack_frames *pilha_frames);
void aconst_null(stack_frames *pilha_frames);
void iconst_m1(stack_frames *pilha_frames);
void iconst_0(stack_frames *pilha_frames);
void iconst_1(stack_frames *pilha_frames);
void iconst_2(stack_frames *pilha_frames);
void iconst_3(stack_frames *pilha_frames);
void iconst_4(stack_frames *pilha_frames);
void iconst_5(stack_frames *pilha_frames);
void lconst_0(stack_frames *pilha_frames);
void lconst_1(stack_frames *pilha_frames);
void fconst_0(stack_frames *pilha_frames);
void fconst_1(stack_frames *pilha_frames);
void fconst_2(stack_frames *pilha_frames);
void dconst_0(stack_frames *pilha_frames);
void dconst_1(stack_frames *pilha_frames);
void bipush(stack_frames *pilha_frames);
void sipush(stack_frames *pilha_frames);
void ldc(stack_frames *pilha_frames);
void ldc_w(stack_frames *pilha_frames);
void ldc2_w(stack_frames *pilha_frames);
void iload(stack_frames *pilha_frames);
void lload(stack_frames *pilha_frames);
void fload(stack_frames *pilha_frames);
void dload(stack_frames *pilha_frames);
void aload(stack_frames *pilha_frames);
void iload_0(stack_frames *pilha_frames);
void iload_1(stack_frames *pilha_frames);
void iload_2(stack_frames *pilha_frames);
void iload_3(stack_frames *pilha_frames);
void lload_0(stack_frames *pilha_frames);
void lload_1(stack_frames *pilha_frames);
void lload_2(stack_frames *pilha_frames);
void lload_3(stack_frames *pilha_frames);

/*!
   \brief Instrução fload_0. Recupera um float no array de variáveis locais com índice 0 e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fload_0(stack_frames *pilha_frames);

/*!
   \brief Instrução fload_1. Recupera um float no array de variáveis locais com índice 1 e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fload_1(stack_frames *pilha_frames);

/*!
   \brief Instrução fload_2. Recupera um float no array de variáveis locais com índice 2 e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fload_2(stack_frames *pilha_frames);

/*!
   \brief Instrução fload_3. Recupera um float no array de variáveis locais com índice 3 e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fload_3(stack_frames *pilha_frames);

/*!
   \brief Instrução dload_0. Recupera um double no array de variáveis locais com índice 0 e 1 com notação big endian
   e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dload_0(stack_frames *pilha_frames);

/*!
   \brief Instrução dload_1. Recupera um double no array de variáveis locais com índice 1 e 2 com notação big endian
   e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dload_1(stack_frames *pilha_frames);

/*!
   \brief Instrução dload_2. Recupera um double no array de variáveis locais com índice 2 e 3 com notação big endian
   e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dload_2(stack_frames *pilha_frames);

#endif /* INSTRUCOES_0_40_H */
