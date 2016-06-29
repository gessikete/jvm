/*!
   \file instrucoes_121-160.h
   \brief Protótipo das funções para o módulo de frames.

   Esse arquivo contém os protótipos das funções que definem as instruções executadas
   pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#ifndef INSTRUCOES_121_160_H
#define INSTRUCOES_121_160_H

#include "instrucoes.h"
#include "pilha_frames.h"
#include "leitor_constant_pool.h"

void lshl(stack_frames *pilha_frames);
void ishr(stack_frames *pilha_frames);
void lshr(stack_frames *pilha_frames);
void iushr(stack_frames *pilha_frames);
void lushr(stack_frames *pilha_frames);
void iand(stack_frames *pilha_frames);
void land(stack_frames *pilha_frames);
void ior(stack_frames *pilha_frames);
void lor(stack_frames *pilha_frames);
void ixor(stack_frames *pilha_frames);
void lxor(stack_frames *pilha_frames);
void iinc(stack_frames *pilha_frames);
void i2l(stack_frames *pilha_frames);
void i2f(stack_frames *pilha_frames);
void i2d(stack_frames *pilha_frames);
void l2i(stack_frames *pilha_frames);
void l2f(stack_frames *pilha_frames);
void l2d(stack_frames *pilha_frames);
void f2i(stack_frames *pilha_frames);
void f2l(stack_frames *pilha_frames);
void f2d(stack_frames *pilha_frames);
void d2i(stack_frames *pilha_frames);
void d2l(stack_frames *pilha_frames);
void d2f(stack_frames *pilha_frames);
void i2b(stack_frames *pilha_frames);
void i2c(stack_frames *pilha_frames);
void i2s(stack_frames *pilha_frames);
void lcmp(stack_frames *pilha_frames);
void fcmpl(stack_frames *pilha_frames);
void fcmpg(stack_frames *pilha_frames);
void dcmpl(stack_frames *pilha_frames);
void dcmpg(stack_frames *pilha_frames);
void ifeq(stack_frames *pilha_frames);
void ifne(stack_frames *pilha_frames);
void iflt(stack_frames *pilha_frames);
void ifge(stack_frames *pilha_frames);
void ifgt(stack_frames *pilha_frames);
void ifle(stack_frames *pilha_frames);
void if_icmpeq(stack_frames *pilha_frames);
void if_icmpne(stack_frames *pilha_frames);

#endif /* INSTRUCOES_121_160_H */
