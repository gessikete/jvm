/*!
   \file instrucoes_0-40.h
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
#ifndef INSTRUCOES_0_40_H
#define INSTRUCOES_0_40_H

// #define DEBUG /** Descomentar caso deseje usar o modo debug */

#include "instrucoes.h"
#include "estruturas_dados.h"
#include "leitor_constant_pool.h"

/*!
   \brief Não faz nada.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void nop(stack_frames *pilha_frames);

/*!
   \brief Empilha null na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void aconst_null(stack_frames *pilha_frames);

/*!
   \brief Empilha um int de valor -1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iconst_m1(stack_frames *pilha_frames);

/*!
   \brief Empilha um int de valor 0 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iconst_0(stack_frames *pilha_frames);

/*!
   \brief Empilha um int de valor 1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iconst_1(stack_frames *pilha_frames);

/*!
   \brief Empilha um int de valor 2 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iconst_2(stack_frames *pilha_frames);

/*!
   \brief Empilha um int de valor 3 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iconst_3(stack_frames *pilha_frames);

/*!
   \brief Empilha um int de valor 4 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iconst_4(stack_frames *pilha_frames);

/*!
   \brief Empilha um int de valor 5 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iconst_5(stack_frames *pilha_frames);

/*!
   \brief Empilha um long de valor 0 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void lconst_0(stack_frames *pilha_frames);

/*!
   \brief Empilha um long de valor 1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void lconst_1(stack_frames *pilha_frames);

/*!
   \brief Empilha um float de valor 0 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void fconst_0(stack_frames *pilha_frames);

/*!
   \brief Empilha um float de valor 1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void fconst_1(stack_frames *pilha_frames);

/*!
   \brief Empilha um float de valor 2 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void fconst_2(stack_frames *pilha_frames);

/*!
   \brief Empilha um double de valor 0 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void dconst_0(stack_frames *pilha_frames);

/*!
   \brief Empilha um double de valor 1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void dconst_1(stack_frames *pilha_frames);

/*!
   \brief Empilha um byte signed para int na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void bipush(stack_frames *pilha_frames);

/*!
   \brief Empilha um short na pilha de operandos montado a partir de dois
   operandos de um byte cada do code.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void sipush(stack_frames *pilha_frames);

/*!
   \brief Recupera um index para a constant_pool. O index pode ser para um inteiro,
   float ou uma referência para uma string, referência simbólica para uma classe,
   tipo de método ou metodo handle. Então empilha o operando que resgatar.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void ldc(stack_frames *pilha_frames);

/*!
   \brief Recupera dois bytes para index para o poll de constante. O index pode ser
   para um inteiro, float ou uma referência para uma string, referência simbólica
   para uma classe, tipo de método ou metodo handle. Então ele empilha o operando
   que resgatar.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void ldc_w(stack_frames *pilha_frames);

/*!
   \brief Recupera dois bytes para index para o poll de constante. O index pode ser
   para um long, double. Então ele empilha o operando que resgatar.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void ldc2_w(stack_frames *pilha_frames);

/*!
   \brief Recebe um index para o vetor de variaveis locais, que contém o operando
   int que deve ser empilhado na pilha de operandos. Se wide_ for 0, combina
   dois bytes para saber o index, caso contrário, combina apenas um.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iload(stack_frames *pilha_frames);

/*!
   \brief Recebe um index do vetor de variaveis locais, index e index+1 contém o
   operando long que deve ser empilhado na pilha de operandos. Se wide_ for 0,
   combina dois bytes para saber o index, caso contrário, combina apenas um.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void lload(stack_frames *pilha_frames);

/*!
   \brief Recebe um index para o vetor de variaveis locais, que contém o operando
   float que deve ser empilhado na pilha de operandos. Se wide_ for 0, combina
   dois bytes para saber o index, caso contrário, combina apenas um.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void fload(stack_frames *pilha_frames);

/*!
   \brief Recebe um index do vetor de variaveis locais, index e index+1 contém o
   operando double que deve ser empilhado na pilha de operandos. Se wide_ for 0,
   combina dois bytes para saber o index, caso contrário, combina apenas um.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void dload(stack_frames *pilha_frames);

/*!
   \brief Recebe um index para o vetor de variaveis locais, que contém uma referencia
   que deve ser empilhada na pilha de operandos. Se wide_ for 0, combina dois bytes
   para saber o index, caso contrário, combina apenas um.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void aload(stack_frames *pilha_frames);

/*!
   \brief Empilha na pilha de operandos um int que está no index 0 do array de
   variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iload_0(stack_frames *pilha_frames);

/*!
   \brief Empilha na pilha de operandos um int que está no index 1 do array de
   variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iload_1(stack_frames *pilha_frames);

/*!
   \brief Empilha na pilha de operandos um int que está no index 2 do array de
   variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iload_2(stack_frames *pilha_frames);

/*!
   \brief Empilha na pilha de operandos um int que está no index 3 do array de
   variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void iload_3(stack_frames *pilha_frames);

/*!
   \brief Empilha na pilha de operandos um long que está nos index 0 e 1 do array
   de variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void lload_0(stack_frames *pilha_frames);

/*!
   \brief Empilha na pilha de operandos um long que está nos index 1 e 2 do array
   de variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void lload_1(stack_frames *pilha_frames);

/*!
   \brief Empilha na pilha de operandos um long que está nos index 2 e 3 do array
   de variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
void lload_2(stack_frames *pilha_frames);

/*!
   \brief Empilha na pilha de operandos um long que está nos index 3 e 4 do array
   de variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum.
*/
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

/** @} */ // fim da definição de instrucoes
