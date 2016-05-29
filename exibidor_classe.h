#ifndef EXIBIDOR_CLASSE_H
#define EXIBIDOR_CLASSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <inttypes.h>
#include "types.h"
#include "arquivos.h"
#include "leitor_atributos.h"
#include "leitor_classe.h"
#include "leitor_metodos.h"
#include "leitor_campos.h"
#include "leitor_constant_pool.h"
#include "exibidor_constant_pool.h"
#include "validation.h"



/* Parte 1 */
/* Recebe a estrutura lida de class file e exibe na tela os binários*/
void exibe_classe(class_file* cf);


#endif
