/* Esse módulo foi criado para tratar as operações de troca de referências simbólist_class
 * para a constant pool para referências diretas */

#ifndef CLASSE_H
#define CLASSE_H

#include "leitor_classe.h"

/* Estrutura que modela um tipo de variavel em java. */
typedef struct {

    /* tag informa se o campo eh de qual tipo especificado na union, conforme as macros definidas em "espeficicacoes.h". */
    uint8_t tag;

    /* union mapeia o campo em um dos tipos definidos abaixo, conforme o valor de tag. */
    union {
        tipo_boolean campo_boolean;
        tipo_byte campo_byte;
        tipo_short campo_short;
        tipo_int campo_int;
        tipo_long campo_long;
        tipo_float campo_float;
        tipo_double campo_double;
    } info;
} tipo_java;

/* Estrutura que modela um runtime field. */
typedef struct {
    tipo_java dados_field;
    field_info *pt_field;
    class_file *pt_classe;
} runtime_field;

/* Estrutura que modela um objeto java. */
typedef struct struct_objeto {
    class_file *pt_classe;
    u2 tamanho_lista_runtime_fields;
    runtime_field *lista_runtime_fields;
    u2 tamanho_lista_arrays;
    struct struct_array *lista_arrays;
} objeto;

/* Estrutura que modela um array em java. */
typedef struct struct_array {

    uint8_t tag;
    uint32_t tamanho;
    uint8_t dimensoes;

    union {
        tipo_boolean *array_boolean;
        tipo_byte *array_byte;
        tipo_char *array_char;
        tipo_short *array_short;
        tipo_int *array_int;
        tipo_long *array_long;
        tipo_float *array_float;
        tipo_double *array_double;
        struct struct_objeto *array_objeto;
        struct struct_array *array_array;
    } info;
} array;


/* Estrutura que modela uma tabela de classe */
typedef struct list_class{
	class_file *pt_classe;
	struct list_class *next;
}elemento_tabela_classes;

/* Estrutura que modela uma lista de arrays. */
typedef struct struct_lista_arrays {
    array *ptArray;
    struct struct_lista_arrays *proximo;
} elemento_lista_arrays;

/* Estrutura que modela uma lista de objetos. */
typedef struct struct_lista_objetos {
    objeto *ptObjeto;
    struct struct_lista_objetos *proximo;
} elemento_lista_objetos;

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
