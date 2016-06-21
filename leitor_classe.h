#ifndef LEITOR_CLASSE_H
#define LEITOR_CLASSE_H

#include "types.h"
#include "arquivos.h"
#include "leitor_atributos.h"
#include "leitor_metodos.h"
#include "leitor_campos.h"
#include "validation.h"

#define STR_SIZE 100

/*
 * Organiza a leitura de todos os elementos da classe
 *
 * Parâmetros:
 *       char *nome_arquivo: ponteiro para string contendo o nome do arquivo .class
 *
 * Retorno:
 *       class_file *: ponteiro para a strutura contendo as informações da classe
 */
class_file *carregar_classe(char *nome_arquivo);

/*
 * Lê os valores referentes aos índices para a constant_pool das interfaces
 *
 * Parâmetros:
 *       u2 interfaces_count: número de interfaces dessa classe
 *       FILE *pt_arquivo: ponteiro para o arquivo binário da classe
 *
 * Retorno:
 *       u2 *: ponteiro para array com índices das interfaces
 */
u2 *ler_interfaces(u2 interfaces_count, FILE *pt_arquivo);

/*
 * Desaloca o espaço alocado para o array de interfaces
 *
 * Parâmetros:
 *      u2 *pt_interfaces: ponteiro para o array de interfaces
 * Retorno:
 *      Nenhum
 */
void desalocar_interfaces(u2 *pt_interfaces);

/*
 * Desaloca o espaço alocado para a estrutura da classe
 *
 * Parâmetros:
 *      class_file *pt_classe: ponteiro para a estrutura contento as informações da classe
 *
 * Retorno:
 *      Nenhum
 */
void desalocar_classe(class_file *pt_classe);

#endif /* LEITOR_CLASSE_H */
