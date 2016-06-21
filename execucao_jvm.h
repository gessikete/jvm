#ifndef EXEC_JVM_H
#define EXEC_JVM_H

#include "types.h"
#include "recuperar_constant_pool.h"
#include "pilha_frames.h"
#include "instrucoes.h"

void inicializar_jvm(class_file *pt_classe);
void executar_jvm(stack_frames *pilha_frames);

#endif
