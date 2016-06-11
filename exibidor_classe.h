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
#include "exibidor_campos.h"
#include "exibidor_metodos.h"
#include "exibidor_atributos.h"
#include "recuperar_constant_pool.h"
#include "validation.h"
#include "macros.h"


/* Parte 1 */
/* Recebe a estrutura lida de class file e exibe na tela os binários*/
void exibir_classe(class_file* cf);

/*
 * Exibe as interfaces da classe
 *
 * Parâmetros:
 *      u2 *interfaces: ponteiro para o array de índices das interfaces
 *      u2 interfaces_count: número de interfaces dessa classe
 *      cp_info *const_pool: ponteiro para a constant pool
 * Retorno:
 *      Nenhum
 */
void exibir_interfaces(u2 *interfaces, u2 interfaces_count, cp_info *const_pool);

/*
 * Exibe em human-readable string o valor associado a access_flag
 *
 * Parâmetros:
 *      u2 access_flag: hexadecimal que representa a classe
 *
 * Retorno:
 *      Nenhum*/
void exibir_access_flag(u2 access_flag);

/*
 * Exibe informações gerais sobre this class e super class
 *
 * Parâmetros:
 *      char *tipo: tipo de classe a ser exibida, texto a ser EXIBIDOR
 *      u2 class_index: íncide da classe para a constant Pool
 *      cp_info *const_pool: ponteiro para a constant POOL
 *
 * Retorno:
 *      Nenhum
 */
void exibir_tipo_classe(char *tipo, u2 classe_index, cp_info *const_pool);

#endif
