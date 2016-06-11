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
void fload_0(stack_frames *pilha_frames);
void fload_1(stack_frames *pilha_frames);
void fload_2(stack_frames *pilha_frames);
void fload_3(stack_frames *pilha_frames);
void dload_0(stack_frames *pilha_frames);
void dload_1(stack_frames *pilha_frames);
void dload_2(stack_frames *pilha_frames);

#endif