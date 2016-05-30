#ifndef EXIBIDOR_METODOS_H
#define EXIBIDOR_METODOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <inttypes.h>
#include "types.h"
#include "arquivos.h"
#include "leitor_atributos.h"
#include "leitor_metodos.h"
#include "leitor_campos.h"
#include "leitor_constant_pool.h"
#include "exibidor_atributos.h"
#include "validation.h"
#include "recuperar_constant_pool.h"


/* Parte 1 */

/*  Mostra Na Tela todos os metodos
	Recebe o Ponteiro de metodos e
	a quantidade de metodod
 */
#define PUBLIC 0x0001
#define PRIVATE 0x0002
#define PROTECTED 0x0004
#define STATIC 0x0008
#define FINAL 0x0010
#define SYNCHRONIZED 0x0020
#define BRIDGE 0x0040
#define VARARGS 0x0080
#define NATIVE 0x0100
#define ABSTRACT 0x0400
#define STRICT 0x0800
#define SYNTHETIC 0x1000

void exibir_metodos(method_info *methods, u2 methods_count, cp_info *const_pool);

#endif
