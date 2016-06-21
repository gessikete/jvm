#ifndef INSTRUCOES_81_120_H
#define INSTRUCOES_81_120_H

#include "instrucoes.h"
#include "pilha_frames.h"
#include "leitor_constant_pool.h"
#include "math.h"

void fastore(stack_frames *pilha_frames);
void dastore(stack_frames *pilha_frames);
void aastore(stack_frames *pilha_frames);
void bastore(stack_frames *pilha_frames);
void castore(stack_frames *pilha_frames);
void sastore(stack_frames *pilha_frames);
void pop(stack_frames *pilha_frames);
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

#endif
