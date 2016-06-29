/*!
   \file instrucoes_41-80.h
   \brief Protótipo das funções para o módulo de frames.

   Esse arquivo contém os protótipos das funções que definem as instruções executadas
   pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#ifndef INSTRUCOES_41_80_H
#define INSTRUCOES_41_80_H

#include "instrucoes.h"
#include "pilha_frames.h"
#include "leitor_constant_pool.h"
#include "resolve.h"

/*!
   \brief Instrução dload_3. Recupera um double no array de variáveis locais com
   índice 3 e 4 com notação big endian e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dload_3(stack_frames *pilha_frames);

/*!
   \brief Instrução aload_0. Recupera um objectref do tipo reference no array de
   variáveis locais com índice 0 e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void aload_0(stack_frames *pilha_frames);

/*!
   \brief Instrução aload_1. Recupera um objectref do tipo reference no array de
   variáveis locais com índice 1 e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void aload_1(stack_frames *pilha_frames);

/*!
   \brief Instrução aload_2. Recupera um objectref do tipo reference no array de
   variáveis locais com índice 2 e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void aload_2(stack_frames *pilha_frames);

/*!
   \brief Instrução aload_3. Recupera um objectref do tipo reference no array de
   variáveis locais com índice 3 e empilha na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void aload_3(stack_frames *pilha_frames);

/*!
   \brief Instrução iaload. Recupera o índex do valor e o endereço do array de
   int e empilha o valor int do array na posição índex na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void iaload(stack_frames *pilha_frames);

/*!
   \brief Instrução laload. Recupera o índex do valor e o endereço do array de
   long e empilha o valor long do array na posição índex na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void laload(stack_frames *pilha_frames);

/*!
   \brief Instrução faload. Recupera o índex do valor e o endereço do array de
   float e empilha o valor float do array na posição índex na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void faload(stack_frames *pilha_frames);

/*!
   \brief Instrução daload. Recupera o índex do valor e o endereço do array de
   double e empilha o valor double do array na posição índex na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void daload(stack_frames *pilha_frames);

/*!
   \brief Instrução aaload. Recupera o índex do subarray e o endereço do array de
   array e empilha o valor do endereço do subarray da posição índex na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void aaload(stack_frames *pilha_frames);

/*!
   \brief Instrução baload. Recupera o índex do valor e o endereço do array de
   byte e empilha o valor byte do array da posição índex na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void baload(stack_frames *pilha_frames);

/*!
   \brief Instrução saload. Recupera o índex do valor e o endereço do array de
   char e empilha o valor char do array da posição índex na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void caload(stack_frames *pilha_frames);

/*!
   \brief Instrução saload. Recupera o índex do valor e o endereço do array de
   short e empilha o valor short do array da posição índex na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void saload(stack_frames *pilha_frames);

/*!
   \brief Instrução istore. Recupera o índex usando a posição atual do PC no code
   do frame atual, caso a flag wide_ esteja setada recupera um 2bytes, desempilha
   um int da pilha de operandos e o adiciona ao array de variáveis locais no índex
   recuperado do code.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void istore(stack_frames *pilha_frames);

/*!
   \brief Instrução lstore. Recupera o índex usando a posição atual do PC no code
   do frame atual, caso a flag wide_ esteja setada recupera um 2bytes, desempilha
   um long da pilha de operandos e o adiciona ao array de variáveis locais no índex
   recuperado do code.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lstore(stack_frames *pilha_frames);

/*!
   \brief Instrução fstore. Recupera o índex usando a posição atual do PC no code
   do frame atual, caso a flag wide_ esteja setada recupera um 2bytes, desempilha
   um flot da pilha de operandos e o adiciona ao array de variáveis locais no índex
   recuperado do code.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fstore(stack_frames *pilha_frames);

/*!
   \brief Instrução dstore. Recupera o índex usando a posição atual do PC no code
   do frame atual, caso a flag wide_ esteja setada recupera um 2bytes, desempilha
   um double da pilha de operandos e o adiciona ao array de variáveis locais no índex
   recuperado do code.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dstore(stack_frames *pilha_frames);

/*!
   \brief Instrução astore. Recupera o índex usando a posição atual do PC no code
   do frame atual, caso a flag wide_ esteja setada recupera um 2bytes, desempilha
   um objectref da pilha de operandos e o adiciona ao array de variáveis locais
   no índex recuperado do code.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void astore(stack_frames *pilha_frames);

/*!
   \brief Instrução istore_0. Desempilha um int da pilha de operandos e o adiciona
   ao array de variáveis locais na posição 0.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void istore_0(stack_frames *pilha_frames);

/*!
   \brief Instrução istore_1. Desempilha um int da pilha de operandos e o adiciona
   ao array de variáveis locais na posição 1.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void istore_1(stack_frames *pilha_frames);

/*!
   \brief Instrução istore_2. Desempilha um int da pilha de operandos e o adiciona
   ao array de variáveis locais na posição 2.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void istore_2(stack_frames *pilha_frames);

/*!
   \brief Instrução istore_3. Desempilha um int da pilha de operandos e o adiciona
   ao array de variáveis locais na posição 3.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void istore_3(stack_frames *pilha_frames);

/*!
   \brief Instrução lstore_0. Desempilha um long da pilha de operandos em notação
   big endian e o adiciona ao array de variáveis locais na posição 0 e 1.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lstore_0(stack_frames *pilha_frames);

/*!
   \brief Instrução lstore_1. Desempilha um long da pilha de operandos em notação
   big endian e o adiciona ao array de variáveis locais na posição 1 e 2.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lstore_1(stack_frames *pilha_frames);

/*!
   \brief Instrução lstore_2. Desempilha um long da pilha de operandos em notação
   big endian e o adiciona ao array de variáveis locais na posição 2 e 3.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lstore_2(stack_frames *pilha_frames);

/*!
   \brief Instrução lstore_3. Desempilha um long da pilha de operandos em notação
   big endian e o adiciona ao array de variáveis locais na posição 3 e 4.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lstore_3(stack_frames *pilha_frames);

/*!
   \brief Instrução fstore_0. Desempilha um float da pilha de operandos e o adiciona
   ao array de variáveis locais na posição 0.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fstore_0(stack_frames *pilha_frames);

/*!
   \brief Instrução fstore_1. Desempilha um float da pilha de operandos e o adiciona
   ao array de variáveis locais na posição 1.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fstore_1(stack_frames *pilha_frames);

/*!
   \brief Instrução fstore_2. Desempilha um float da pilha de operandos e o adiciona
   ao array de variáveis locais na posição 2.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fstore_2(stack_frames *pilha_frames);

/*!
   \brief Instrução fstore_3. Desempilha um float da pilha de operandos e o adiciona
   ao array de variáveis locais na posição 3.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fstore_3(stack_frames *pilha_frames);

/*!
   \brief Instrução dstore_0. Desempilha um double da pilha de operandos em notação
   big endian e o adiciona ao array de variáveis locais na posição 0 e 1.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dstore_0(stack_frames *pilha_frames);

/*!
   \brief Instrução dstore_1. Desempilha um double da pilha de operandos em notação
   big endian e o adiciona ao array de variáveis locais na posição 1 e 2.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dstore_1(stack_frames *pilha_frames);

/*!
   \brief Instrução dstore_2. Desempilha um double da pilha de operandos em notação
   big endian e o adiciona ao array de variáveis locais na posição 2 e 3.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dstore_2(stack_frames *pilha_frames);

/*!
   \brief Instrução dstore_3. Desempilha um double da pilha de operandos em notação
   big endian e o adiciona ao array de variáveis locais na posição 3 e 4.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dstore_3(stack_frames *pilha_frames);

/*!
   \brief Instrução astore_0. Desempilha um objectref da pilha de operandos e o
   adiciona ao array de variáveis locais na posição 0.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void astore_0(stack_frames *pilha_frames);

/*!
   \brief Instrução astore_1. Desempilha um objectref da pilha de operandos e o
   adiciona ao array de variáveis locais na posição 1.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void astore_1(stack_frames *pilha_frames);

/*!
   \brief Instrução astore_2. Desempilha um objectref da pilha de operandos e o
   adiciona ao array de variáveis locais na posição 2.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void astore_2(stack_frames *pilha_frames);

/*!
   \brief Instrução astore_3. Desempilha um objectref da pilha de operandos e o
   adiciona ao array de variáveis locais na posição 3.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void astore_3(stack_frames *pilha_frames);

/*!
   \brief Instrução iastore. Desempilha int a ser salvo, o índice e o endereço
   do array onde o int será salvo. Adiciona o valor do int no índice do array e
   empilha o endereço do array int.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void iastore(stack_frames *pilha_frames);

/*!
   \brief Instrução lastore. Desempilha long a ser salvo, o índice e o endereço
   do array onde o long será salvo. Adiciona o valor do long no índice do array e
   empilha o endereço do array long.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lastore(stack_frames *pilha_frames);

#endif /* INSTRUCOES_41_80_H */
