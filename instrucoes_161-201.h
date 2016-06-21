#ifndef INSTRUCOES_181_201_H
#define INSTRUCOES_181_201_H

#include "instrucoes.h"
#include "pilha_frames.h"
#include "recuperar_constant_pool.h"

void if_icmplt(stack_frames *pilha_frames);
void if_icmpge(stack_frames *pilha_frames);
void if_icmpgt(stack_frames *pilha_frames);
void if_icmple(stack_frames *pilha_frames);
void if_acmpeq(stack_frames *pilha_frames);
void if_acmpne(stack_frames *pilha_frames);
void goto_(stack_frames *pilha_frames);
void jsr(stack_frames *pilha_frames);
void ret(stack_frames *pilha_frames);
void tableswitch(stack_frames *pilha_frames);
void lookupswitch(stack_frames *pilha_frames);
void ireturn(stack_frames *pilha_frames);
void lreturn(stack_frames *pilha_frames);
void freturn(stack_frames *pilha_frames);
void dreturn(stack_frames *pilha_frames);
void areturn(stack_frames *pilha_frames);
void return_(stack_frames *pilha_frames);
void getstatic(stack_frames *pilha_frames);
void putstatic(stack_frames *pilha_frames);
void getfield(stack_frames *pilha_frames);
void putfield(stack_frames *pilha_frames);
void invokevirtual(stack_frames *pilha_frames);
void invokespecial(stack_frames *pilha_frames);
void invokestatic(stack_frames *pilha_frames);
void invokeinterface(stack_frames *pilha_frames);
void unused(stack_frames *pilha_frames);
void new_(stack_frames *pilha_frames);
void newarray(stack_frames *pilha_frames);
void anewarray(stack_frames *pilha_frames);
void arraylength(stack_frames *pilha_frames);
void athrow(stack_frames *pilha_frames);
void checkcast(stack_frames *pilha_frames);
void instanceof(stack_frames *pilha_frames);
void monitorenter(stack_frames *pilha_frames);
void monitorexit(stack_frames *pilha_frames);
void wide(stack_frames *pilha_frames);
void multianewarray(stack_frames *pilha_frames);
void ifnull(stack_frames *pilha_frames);
void ifnonnull(stack_frames *pilha_frames);
void goto_w(stack_frames *pilha_frames);
void jsr_w(stack_frames *pilha_frames);
void breakpoint(stack_frames *pilha_frames);

#endif
