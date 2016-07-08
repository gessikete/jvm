/*!
   \file instrucoes_161-201.h
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
#ifndef INSTRUCOES_181_201_H
#define INSTRUCOES_181_201_H

#include "instrucoes.h"
#include "estruturas_dados.h"
#include "recuperar_constant_pool.h"

/*!
   \brief Desempilha dois int da pilha de operandos. Caso o segundo seja menor que o
   primeiro, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void if_icmplt(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. Caso o segundo seja maior ou igual ao
   primeiro, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void if_icmpge(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. Caso o segundo seja maior que o
   primeiro, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void if_icmpgt(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. Caso o segundo seja menor ou igual ao
   primeiro, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void if_icmple(stack_frames *pilha_frames);

/*!
   \brief Desempilha duas referencias da pilha de operandos. Caso o segundo igual ao
   primeiro, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void if_acmpeq(stack_frames *pilha_frames);

/*!
   \brief Desempilha duas referencias da pilha de operandos. Caso o segundo diferente do
   primeiro, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void if_acmpne(stack_frames *pilha_frames);

/*!
   \brief O offset é calculado com os unsigneds operandos branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado dentro do mesmo método do goto_.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void goto_(stack_frames *pilha_frames);

/*!
   \brief O endereço da instrução que segue a instrução jsr é empilhada na pilha
   de operandos com tipo returnAddress. O offset é calculado com os unsigneds
   operandos branchbyte1 e branchbyte2 e a execução continua a partir do offset
   calculado.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void jsr(stack_frames *pilha_frames);

/*!
   \brief Recupera o index na próxima posição do PC e atualiza o PC com o valor
   da posição index do array de variáveis locais.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ret(stack_frames *pilha_frames);

/*!
   \brief Recupera o index apontado pelo PC, acessa a jump table e executa o pulo
   de acordo como index.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void tableswitch(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lookupswitch(stack_frames *pilha_frames);

/*!
   \brief Desempilha um valor dos tipos boolean, byte, short, char ou int da pilha
   de operandos do frame atual. Desempilha o frame atual e empilha valor na pilha
   de operandos do frame do método invoker.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ireturn(stack_frames *pilha_frames);

/*!
   \brief Desempilha um valor do tipo long da pilha de operandos do frame atual.
   Desempilha o frame atual e empilha valor na pilha de operandos do frame do
   método invoker.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lreturn(stack_frames *pilha_frames);

/*!
   \brief Desempilha um valor do tipo float da pilha de operandos do frame atual.
   Desempilha o frame atual e empilha valor na pilha de operandos do frame do
   método invoker.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void freturn(stack_frames *pilha_frames);

/*!
   \brief Desempilha um valor do tipo double da pilha de operandos do frame atual.
   Desempilha o frame atual e empilha valor na pilha de operandos do frame do
   método invoker.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dreturn(stack_frames *pilha_frames);

/*!
   \brief Desempilha um valor do tipo reference da pilha de operandos do frame atual.
   Desempilha o frame atual e empilha valor na pilha de operandos do frame do
   método invoker.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void areturn(stack_frames *pilha_frames);

/*!
   \brief Desempilha o frame atual.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void return_(stack_frames *pilha_frames);

/*!
   \brief Os dois bytes apontados pelo PC são usados para construir um index para
   a constant_pool. O item encontrado na posição do index deve ser uma referencia
   para um field, que é então resolvida. Então, a classe que declarou o field é
   carregada, caso ainda não esteja carregada.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void getstatic(stack_frames *pilha_frames);

/*!
   \brief Os dois bytes apontados pelo PC são usados para construir um index para
   a constant_pool. O item encontrado na posição do index deve ser uma referencia
   para um field, que é então resolvida. Então, a classe que declarou o field é
   carregada, caso ainda não esteja carregada.
   O valor é desempilhado da pilha de operandos e o field da classe carregada é
   setado para o valor desempilhado.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void putstatic(stack_frames *pilha_frames);

/*!
   \brief Um object_ref do tipo reference é desempilhado da pilha de operandos.
   Os dois bytes apontados pelo PC são usados para construir um index para
   a constant_pool. O item encontrado na posição do index deve ser uma referencia
   para um field, que é então resolvida. Então, o valor referenciado no field em
   object_ref é buscado e empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void getfield(stack_frames *pilha_frames);

/*!
   \brief Os dois bytes apontados pelo PC são usados para construir um index para
   a constant_pool. O item encontrado na posição do index deve ser uma referencia
   para um field, que é então resolvida. Então, o valor é desempilhado da pilha
   de operandos e o field referenciado por object_ref é setado para o valor desempilhado.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void putfield(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void invokevirtual(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void invokespecial(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void invokestatic(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void invokeinterface(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void unused(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void new_(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void newarray(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void anewarray(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void arraylength(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void athrow(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void checkcast(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void instanceof(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void monitorenter(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void monitorexit(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void wide(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void multianewarray(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ifnull(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ifnonnull(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void goto_w(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void jsr_w(stack_frames *pilha_frames);

/*!
   \brief

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void breakpoint(stack_frames *pilha_frames);

#endif /* INSTRUCOES_161-201_H */

/** @} */ // fim da definição de instrucoes
