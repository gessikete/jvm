#ifndef MACROS_H
#define MACROS_H

#include "types.h"

/* Definição das macros de access flags */
#define ACC_PUBLIC 0x0001       // Declared public; may be accessed from outside its package.
#define ACC_FINAL 0x0010        // Declared final; no subclasses allowed.
#define ACC_SUPER 0x0020        // Treat superclass methods specially when invoked by the invokespecial instruction.
#define ACC_INTERFACE 0x0200    // Is an interface, not a class.
#define ACC_ABSTRACT 0x0400     // Declared abstract; must not be instantiated.
#define ACC_SYNTHETIC 0x1000    // Declared synthetic; not present in the source code.
#define ACC_ANNOTATION 0x2000   // Declared as an annotation type.
#define ACC_ENUM 0x4000         // Declared as an enum type.
/* Fim das definições das macros de access flags */

/* Declaração dos métodos */
/*
 * Exibe uma access flag no formato "0x000 [ value ]"
 *
 * Parâmetros:
 *       u2 flag: máscara da flag
 *
 * Retorno:
 *       Nenhum
 */
void exibir_access_flag_string(u2 flag);

#endif /* MACROS_H */
