#ifndef LEITOR_ATRIBUTOS_H
#define LEITOR_ATRIBUTOS_H

#include "types.h"
#include "leitor_constant_pool.h"

/* Definição das estruturas dos atributos */

struct t_attribute_info;

typedef struct {
	u2 source_file_index;
} source_file_attribute;

typedef struct {
	u2 constant_value_index;
} constant_value_attribute;


typedef struct {
		u2 start_pc;
		u2 end_pc;
		u2 handler_pc;
		u2 catch_type;
} t_exception_table;


typedef struct {
	u2 max_stack;
	u2 max_locals;
	u4 code_length;
	u1 *code;					//code[code_lenght]
	u2 exception_table_length;
	t_exception_table *exception_table;				//exception_table[exception_table_length]
	u2 attributes_count;
	struct t_attribute_info *attributes;		//attributes[attributes_count]
} code_attribute;

typedef struct {
	u2 number_of_exceptions;
	u2 *exceptions_index_table;
} exceptions_attribute;

typedef struct {
	u2 number_of_classes;
	
	struct {
		u2 innner_class_info_index;
		u2 outer_class_info_index;
		u2 inner_name_index;
		u2 inner_class_access_flags;			//classes [number_of_classes]
	} *classes;
} innner_classes_attribute;

typedef struct {
	u2 line_number_table_length;
	
	struct {
		u2 start_pc;
		u2 line_number;
	} *line_number_table;					//line_number_table[line_number_table_length]
} line_number_table_attribute;

typedef struct t_attribute_info {
	u2 attribute_name_index;
	u4 attribute_length;

	union u_info {
		constant_value_attribute constant_value_info;	// tag: ConstantValue
		code_attribute code_info;			// tag: Code
		exceptions_attribute exception_info;		// tag: Exceptions
		innner_classes_attribute inner_classes_info;	// tag: InnerClasses
		source_file_attribute source_file_info;		// tag: SourceFile
		line_number_table_attribute line_number_table;	// tag: LineNumberTable
	} info;

} attribute_info;

#define CONST_VALUE "ConstantValue"
#define CODE "Code"
#define EXCEPTION "Exceptions"
#define INNER_CLASSES "InnerClasses"
#define SOURCE_FILE "SourceFile"
#define LINE_NUM_TABLE "LineNumberTable"

/* Fim da definição das estruturas dos atributos */

// Define um ponteiro para as funções de criação de atributos
typedef void (*funcoes_criar) (FILE*,attribute_info[],u2,cp_info[],u2);


/* Declaração dos métodos dos atributos */

/*
 * Compara o nome do atributo com o atributo na constant pool e
 * retorna a função de criação adequada para o tipo de atributo em questão.
 *
 * Parâmetros:
 *	cp_info constant_pool[]: a constant pool
 *	u2 name_index: índice do nome do atributo na constant pool
 *
 * Retorno:
 *       A função de criação de atributos correspondente ao nome do atributo.
 */

funcoes_criar escolher_funcao(cp_info constant_pool[], u2 name_index);


/*
 * Preenche uma estrutura do tipo attribute_info.
 * 
 * Parâmetros:
 *	FILE *pt_arquivo: ponteiro para o .class
 *	cp_info constant_pool[]: constant pool
 *	u2 constant_pool_count: quantidade de elementos na constant pool
 *	attribute_info atributos[]: vetor de atributos
 *	u2 index: índice corrente no vetor de atributos
 * 
 * Retorno:
 *       Nada
 */
void criar_attribute(FILE *pt_arquivo, cp_info constant_pool[], u2 constant_pool_count, attribute_info atributos[], u2 index);


/*
 * Salva as informações dos atributos em uma lista do tipo attribute_info
 *
 * Parâmetros:
 *	FILE *pt_arquivo: Ponteiro para o .class
 *	u2 attributes_count: Quantidade de atributos a serem escritos
 *	cp_info constant_pool[]: Constant pool
 *	u2 constant_pool_count: Tamanho da constant pool
 *
 * Retorno:
 *       Ponteiro para a lista de atributos.
 */
attribute_info *carregar_atributos(FILE *pt_arquivo, u2 attributes_count, cp_info constant_pool[], u2 constant_pool_count);


/*
 * As funções a seguir preenchem as suas respectivas estruturas de acordo com 
 * as informações lidas do arquivo.
 * 
 * Parâmetros:
 *	FILE *pt_arquivo: ponteiro para o arquivo
 *	attribute_info attributes[]: vetor de atributos
 *	u2 index: índice da entrada corrente no vetor de atributos
 *	cp_info constant_pool[]: constant pool
 *	u2 constant_pool_count: tamanho da constant pool
 * 
 * Retorno:
 *       Nada
 */
void criar_constant_value_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_code_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_exceptions_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_innner_classes_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_source_file_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void criar_line_number_table_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);
void atributo_invalido(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count);

/* Fim da declaração dos métodos dos atributos */

#endif /* LEITOR_ATRIBUTOS_H */
