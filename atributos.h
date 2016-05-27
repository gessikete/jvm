#ifndef ATRIBUTOS_H
#define ATRIBUTOS_H

#include "types.h"
#include "constant_pool.h"

/* Definição das estruturas dos atributos */
typedef struct {
	u2 attribute_name_index;
	u4 attribute_lenght;
	u1 *info;					//info[attribute_lenght]
} attribute_info;

typedef struct {
	u2 attribute_name_index;
	u4 attribute_lenght;
	u2 max_stack;
	u2 max_locals;
	u4 code_lenght;
	u1 *code;					//code[code_lenght]
	u2 exception_table_length;
	union {
		u2 start_pc;
		u2 end_pc;
		u2 handler_pc;
		u2 catch_type;
	} *exception_table;				//exception_table[exception_table_length]
	u2 attributes_count;
	attribute_info *attributes;		//attributes[attributes_count]
} code_attribute;

typedef struct {
	u2 attribute_name_index;
	u4 attribute_lenght;
	u2 number_of_exceptions;
	u2 *exceptions_index_table;
} exceptions_attribute;

typedef struct {
	u2 attribute_name_index;
	u4 attribute_lenght;
	u2 number_of_classes;
	union {
		u2 innner_class_info_index;
		u2 outer_class_info_index;
		u2 inner_name_index;
		u2 inner_class_access_flags;
	} *classes;					//classes [number_of_classes]
} innner_classes_attribute;

/* Fim da definição das estruturas dos atributos */

/* Declaração dos métodos dos atributos */
attribute_info *carregar_atributos(u2 attributes_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo);

/* Fim da declaração dos métodos dos atributos */

#endif /* ATRIBUTOS_H */
