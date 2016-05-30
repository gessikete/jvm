#ifndef EXIBIDOR_CAMPOS_H
#define EXIBIDOR_CAMPOS_H

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
#include "recuperar_constant_pool.h"
#include "validation.h"


/* Parte 1 */

/*  Mostra Na Tela todos os fields
	Recebe o Ponteiro de fields e
	a quantidade de fields
 */
#define PUBLIC 0x0001
#define PRIVATE 0x0002
#define PROTECTED 0x0004
#define STATIC 0x0008
#define FINAL 0x0010
#define VOLATILE 0x0040
#define TRANSCIENT 0x0080
#define ENUM 0x4000

void exibir_fields(field_info *fields, u2 fields_count, cp_info *const_pool);

#endif
