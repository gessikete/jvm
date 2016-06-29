/* Esse módulo foi criado para tratar as operações de troca de referências simbólist_class
 * para a constant pool para referências diretas */

#ifndef CLASSE_H
#define CLASSE_H

#include <string.h>
#include "types.h"


/*
 * Verifica se a classe já está carregada na tabela de classes
 *
 * Parâmetros:
 *		char *nome_classe: Nome da classe a ser verificada
 *		elemento_tabela_classes *tabela_classes: ponteiro para a tabela de classes carregadas
 *
 * Retorno:
 *		true - a classe já está carregadas
 *		false - a classe não está carregada
 */
bool verificar_classe_carregada(char *nome_classe, elemento_tabela_classes *tabela_classes);

/*
 * Insere uma classe na tabela de classes, deve verificar se elemento já está carregado
 *
 * Parâmetros:
 *		elemento_tabela_classes **tabela_classes: ponteiro para ponteiro de classes carregadas
 *		class_file *pt_classe: ponteiro para a classe a ser inserida na tabela
 *
 * Retorno:
 *		Nenhum
 */
void inserir_elemento_tabela_classes(elemento_tabela_classes **tabela_classes, class_file *pt_classe);


#endif /* CLASSE_H */
