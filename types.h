#ifndef LIB_TYPES
#define LIB_TYPES

#include <stdio.h>
#include <stdint.h>
// Inclui stdboll para uso de tipos booleanos
#include <stdbool.h>

//arquivo de saida global ao projeto
 FILE *arquivo_saida;

 /*
  * Definindo as estruturas para manipulação de inteiros tamanhos 8bits, 16bits,
  * 32bits e 64bits da biblioteca stdint.h
  */

 /*
  * unsigned char
  */
 typedef uint8_t u1;

 /*
  * unsigned short
  */
 typedef uint16_t u2;

 /*
  * unsigned int
  */
 typedef uint32_t u4;

 /*
  * unsigned long long
  */
 typedef uint64_t u8;

 typedef uint8_t tipo_boolean;
 typedef int8_t tipo_byte;
 typedef uint16_t tipo_char;
 typedef int16_t tipo_short;
 typedef int32_t tipo_int;
 typedef long long tipo_long;
 typedef float tipo_float;
 typedef double tipo_double;

 /* Definições das estruturas necessárias para a execução da JVM */

 /* Definição das estruturas da constant pool */

 /** Representa uma classe ou interface
 	name_index: um constant_utf8_info representando um nome completo qualificado
 	da classe ou interface nesse arquivo.
 **/
 typedef struct {
 	u2 name_index;
 } constant_class_info;


 /** Representa um field.
 * class_index e name_and_type_index sao indices validos para constant_pool
 * 	class_index: eh um constant_utf8_info representando o nome completo da classe
 * ou interface que contem a declaracao desse field
 * 	name_and_type_index: indica o nome e o descritor desse field.
 **/
 typedef struct {
 	u2 class_index;
 	u2 name_and_type_index;
 } constant_fieldref_info;


 /** Representa valores de strings constantes, inclusive unicode.
 * 	length: indica o numero de bytes no array bytes
 * 	bytes: contem os bytes da string.
 **/
 typedef struct {
 	u2 length;
 	u1 *bytes;			//bytes[length]
 } constant_utf8_info;


 /** Representa um metodo.
 * class_index e name_and_type_index sao indices validos na constant_pool
 * 	class_index: um constant_utf8_info representando o nome completo da interface
 * que declarou esse metodo
 * 	name_and_type_index: indica o nome e o descritor do metodo.
 **/
 typedef struct {
 	u2 class_index;
 	u2 name_and_type_index;
 } constant_methodref_info;


 /** Representa objetos constantes do tipo String
  * 	string_index: indice para constant_pool. Eh um constant_utf8_info representando
  * a sequencia de caracteres com a qual o objeto string sera iniciado.
  **/
 typedef struct {
 	u2 string_index;
 } constant_string_info;


 /**
  * 	class_index: Indice valido para a constant_pool. Eh um constant_utf8_info
  * representando  nome completo da interface que contem a declaracao desse metodo
  * 	name_and_type_index: Indice valido para a constant_pool. Indica nome e descritor
  * do metodo.
  **/
 typedef struct {
 	u2 class_index;
 	u2 name_and_type_index;
 } constant_interface_methodref_info;


 /** Representa uma constante inteira de 4 bytes.
  *  bytes: representa o valor da constante int.
  **/
 typedef struct {
 	u4 bytes;
 } constant_integer_info;


 /** Representa uma constante de ponto flutuante de 4 bytes.
  * bytes: representa o valor da constante float no formato de precisao simples de ponto
  * flutuante padrao IEEE 754.
  **/
 typedef struct {
 	u4 bytes;
 } constant_float_info;

 /** Representa uma constante inteira de 8 bytes.
  * */
 typedef struct {
 	u8 bytes;
 } constant_long_info;


 /** Representa constante de ponto flutuante de 8 bytes, no formato de ponto flutuante
  * de dupla precisao IEEE 754.
  **/
 typedef struct {
 	u8 bytes;
 } constant_double_info;



 /** Representa um field ou metodo sem indicar classe ou interface a que pertence
 * name_index e descriptor_index sao indices validos para a constant_pool
 * 	name_index: um constant_utf8_info representando um nome simples de field, metodo
 * ou o nome do metodo especial <init>
 * 	descriptor_index: um constant_utf8_info representando um descritor valido de field
 * ou de metodo
 **/
 typedef struct {
 	u2 name_index;
 	u2 descriptor_index;
 } constant_name_and_type_info;


 //entrada em constant pool
 typedef struct {
 	u1 tag;
 	union union_info {
 		constant_class_info class_info;					//tag: 7
 		constant_fieldref_info fieldref_info;				//tag: 9
 		constant_utf8_info utf8_info;					//tag: 1
 		constant_methodref_info methodref_info;				//tag: 10
 		constant_string_info string_info;				//tag: 8
 		constant_interface_methodref_info interface_methodref_info;	//tag: 11
 		constant_integer_info integer_info;				//tag: 3
 		constant_float_info float_info;					//tag: 4
 		constant_long_info long_info;					//tag: 5
 		constant_double_info double_info;				//tag: 6
 		constant_name_and_type_info name_and_type_info;			//tag: 12
 	} info;
 } cp_info;

 /* Fim das definições das estruturas da constant pool */

 /* Definição das estruturas dos atributos */

 struct t_attribute_info;

 struct inner_classes_table;

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
 	u2 inner_class_info_index;
 	u2 outer_class_info_index;
 	u2 inner_name_index;
 	u2 inner_class_access_flags;			//classes [number_of_classes]
 } inner_classes_table;

 typedef struct {
 	u2 number_of_classes;

 	inner_classes_table *classes;
 } inner_classes_attribute;

 typedef struct t_attribute_info {
 	u2 attribute_name_index;
 	u4 attribute_length;
 	u1 attribute_tag; // útil para desalocar

 	union u_info {
 		constant_value_attribute constant_value_info;	// tag: ConstantValue
 		code_attribute code_info;			// tag: Code
 		exceptions_attribute exception_info;		// tag: Exceptions
 		inner_classes_attribute inner_classes_info;	// tag: InnerClasses
 		source_file_attribute source_file_info;		// tag: SourceFile
 	} info;

 } attribute_info;

 /* Fim da definição das estruturas dos atributos */

 /* Definição das estruturas de métodos */
 typedef struct {
 	u2 access_flags;
 	u2 name_index;
 	u2 descriptor_index;
 	u2 attributes_count;
 	attribute_info *attributes;			//attributes[attributes_count]
 } method_info;

 /* Fim da definição das estruturas de métodos */

 /* Definição das estruturas de campos */
 typedef struct {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info *attributes;  //attributes[attributes_count]
 } field_info;
 /* Fim da definição das estruturas de campos */

 /* Definição da estrutura do arquivo de classe */
 typedef struct {
     u4 magic;
     u2 minor_version;
     u2 major_version;
     u2 constant_pool_count;
     cp_info *constant_pool;
     u2 access_flags;
     u2 this_class;
     u2 super_class;
     u2 interfaces_count;
     u2 *interfaces;
     u2 fields_count;
     field_info *fields;
     u2 methods_count;
     method_info *methods;
     u2 attributes_count;
     attribute_info *attributes;
 } class_file;

 /* Definição de estruturas do Java */

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
     array *pt_array;
     u4 index;
     struct struct_lista_arrays *proximo;
 } elemento_lista_arrays;

 /* Estrutura que modela uma lista de objetos. */
 typedef struct struct_lista_objetos {
     objeto *pt_objeto;
     struct struct_lista_objetos *proximo;
 } elemento_lista_objetos;

 /* Fim da definição das estruturas do Java */



/* Definição das estruturas de frames e operandos */

typedef struct operand {
	u4 data;
	struct operand *next;
} t_operand;

/* Estrutura que modela a pilha de operandos */
typedef struct operand_stack {
	t_operand *first;
} t_operand_stack;

/* Estrutura que modela um frame */
typedef struct frame {
	method_info *pt_metodo;
	u4 pc;
	code_attribute *code_info;
	u4 array_variaveis_locais_count;
	u4 *array_variaveis_locais;
	t_operand_stack *operand_stack;
	cp_info *pt_constant_pool;
	elemento_lista_arrays *lista_arrays;
	elemento_lista_objetos *lista_objetos;
	u4 return_value;
	struct frame *next;
} t_frame;

/* Estrutura que modela a pilha de frames */
typedef struct {
    t_frame *first;
} stack_frames;

/* Fim da definição das estruturas de frames e operandos */



/* Definição das estruturas de instruções */

// variável global com o valor atual do wide
u1 wide_;

// ponteiro para as funções que implementam as instruções
typedef void (*t_funcao_instrucao)(stack_frames*);

//estrutura para guardar os nomes das funções e os tipos de operandos
typedef struct {
	char *nome;
	t_funcao_instrucao funcao_instrucao;
	u1 operando;
} t_instrucoes;

/* Fim da definição das estruturas de instruções */

/* Fim da definição de estruturas usadas pela JVM */


#endif /* LIB_TYPES */
