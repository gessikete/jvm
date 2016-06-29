/*!
   \file types.h
   \brief Estruturas utilizadas pela JVM

   Este arquivo contém as definições das estruturas e tipos utilizados pela JVM.
   Estão agrupados de acordo com sua utilização.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#ifndef LIB_TYPES
#define LIB_TYPES

#include <stdio.h>
#include <stdint.h>
// Inclui stdboll para uso de tipos booleanos
#include <stdbool.h>

/**
 * \defgroup int_class Inteiros para leitura do class file
 * Definindo as estruturas para manipulação de inteiros tamanhos 8bits, 16bits,
 * 32bits e 64bits da biblioteca stdint.h
 * @{
 */

//! unsigned char
/*! Define o tipo u1 como um uint8_t */
typedef uint8_t u1;

//! unsigned short
/*! Define o tipo u2 como um uint16_t */
typedef uint16_t u2;

//! unsigned int
/*! Define o tipo u2 como um uint16_t */
typedef uint32_t u4;

//! unsigned long long
/*! Define o tipo u2 como um uint16_t */
typedef uint64_t u8;

/** @} */ // fim da definição de int_class


/**
 * \defgroup tipos_var Tipos de variáveis Java
 * Estruturas para manipulação dos tipos das variáveis do Java.
 * @{
 */

//! Boolean
/*! Define o tipo boolean */
typedef uint8_t tipo_boolean;

//! Byte
/*! Define o tipo byte */
typedef int8_t tipo_byte;

//! Char
/*! Define o tipo char */
typedef uint16_t tipo_char;

//! Short
/*! Define o tipo short */
typedef int16_t tipo_short;

//! Int
/*! Define o tipo int */
typedef int32_t tipo_int;

//! Long
/*! Define o tipo long */
typedef long long tipo_long;

//! Float
/*! Define o tipo float */
typedef float tipo_float;

//! Double
/*! Define o tipo double */
typedef double tipo_double;

/** @} */ // fim da definição de tipos_var

/**
 * \defgroup global_var Variáveis Globais
    Variáveis usadas globalmente por todo o programa.
 * @{
 */

//! Arquivo de saída
/*!
    Arquivo de saída global ao projeto. Utilizado para gravação da exibição
    do class file.
*/
FILE *arquivo_saida;

//! Flag de sinalização do wide
/*!
    Variável global com o valor atual do wide. Quando setada pra 1 a instrução
    seguinte deverá ser modificada, caso contrário, seu valor é 0.
*/
u1 wide_;

/** @} */ // fim da definição de global_var


/**
 * \defgroup const_pool Constant Pool
    Definições das estruturas da constant pool.
 * @{
 */

/*! Representa uma classe ou interface. */
typedef struct {
    u2 name_index; /*!< um constant_utf8_info representando um nome completo qualificado da classe ou interface nesse arquivo. */
} constant_class_info;

 /*!
    Representa um field. class_index e name_and_type_index são indices validos para constant_pool
*/
 typedef struct {
 	u2 class_index; /*!< É um constant_utf8_info representando o nome completo da classe ou interface que contem a declaracao desse field */
 	u2 name_and_type_index; /*!< Indica o nome e o descritor desse field. */
 } constant_fieldref_info;

 /*"! Representa valores de strings constantes, inclusive unicode. "*/
 typedef struct {
 	u2 length; /*!< Indica o numero de bytes no array bytes */
 	u1 *bytes; /*!< Contém os bytes da string. bytes[length] */
 } constant_utf8_info;

 /*!
    Representa um metodo.
    class_index e name_and_type_index sao indices validos na constant_pool
*/
 typedef struct {
 	u2 class_index; /*!< Um constant_utf8_info representando o nome completo da interface que declarou esse método. */
 	u2 name_and_type_index; /*!< Indica o nome e o descritor do metodo. */
 } constant_methodref_info;

  /*! Representa objetos constantes do tipo String. */
 typedef struct {
 	u2 string_index; /*!< Índice para constant_pool. É um constant_utf8_info representando a sequência de caracteres com a qual o objeto string sera iniciado. */
 } constant_string_info;

/*! Representa a interface com a declaração desse método. */
typedef struct {
 	u2 class_index; /*!< Índice válido para a constant_pool. É um constant_utf8_info representando nome completo da interface que contém a declaração desse método. */
 	u2 name_and_type_index; /*!< Índice válido para a constant_pool. Indica nome e descritor do método. */
} constant_interface_methodref_info;

/*! Representa uma constante inteira de 4 bytes. */
typedef struct {
 	u4 bytes; /*!< Representa o valor da constante int. */
} constant_integer_info;

 /*! Representa uma constante de ponto flutuante de 4 bytes. */
 typedef struct {
 	u4 bytes; /*!< Representa o valor da constante float no formato de precisao simples de ponto flutuante padrão IEEE 754. */
 } constant_float_info;

 /*! Representa uma constante inteira de 8 bytes. */
 typedef struct {
 	u8 bytes; /*!< Representa o valor da constante long. */
 } constant_long_info;

 /*! Representa constante de ponto flutuante de 8 bytes, no formato de ponto flutuante de dupla precisao IEEE 754.*/
 typedef struct {
 	u8 bytes; /*!< Representa o valor da constante double. */
 } constant_double_info;

 /*! Representa um field ou metodo sem indicar classe ou interface a que pertence. */
 typedef struct {
 	u2 name_index; /*!< Um constant_utf8_info representando um nome simples de field, método ou o nome do metodo especial <init>. */
 	u2 descriptor_index; /*!< Um constant_utf8_info representando um descritor válido de field. */
 } constant_name_and_type_info;


 /*! Representa uma entrada em constant pool. */
 typedef struct {

 	u1 tag; /*!< Um unsigned int de 8bits representando o tipo da entrada. */

 	union union_info {
 		constant_class_info class_info; /*!< tag: 7 CONSTANT_Class */
 		constant_fieldref_info fieldref_info; /*!< tag: 9 CONSTANT_Fieldref */
 		constant_utf8_info utf8_info; /*!< tag: 1 CONSTANT_Utf8 */
 		constant_methodref_info methodref_info; /*!< tag: 10 CONSTANT_Methodref */
 		constant_string_info string_info; /*!< tag: 8 CONSTANT_String */
 		constant_interface_methodref_info interface_methodref_info; /*!< tag: 11 CONSTANT_InterfaceMethodref */
 		constant_integer_info integer_info; /*!< tag: 3 CONSTANT_Integer */
 		constant_float_info float_info; /*!< tag: 4 CONSTANT_Float */
 		constant_long_info long_info; /*!< tag: 5 CONSTANT_Long */
 		constant_double_info double_info; /*!< tag: 6 CONSTANT_Double */
 		constant_name_and_type_info name_and_type_info; /*!< tag: 12 CONSTANT_NameAndType */
 	} info; /*!< Mapeia cada uma das possíveis entradas na constant pool de acordo com a tag. */

 } cp_info;

/** @} */ // Fim das definições de const_pool

 /**
  * \defgroup def_atributos Atributos
     Definições das estruturas dos atributos.
  * @{
  */

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

 /** @} */ // Fim das definições de def_atributos

 /**
  * \defgroup def_metodos Métodos
     Definições das estruturas de métodos.
  * @{
  */
 typedef struct {
 	u2 access_flags;
 	u2 name_index;
 	u2 descriptor_index;
 	u2 attributes_count;
 	attribute_info *attributes;			//attributes[attributes_count]
 } method_info;

 /** @} */ // Fim das definições de def_metodos

 /**
  * \defgroup def_campos Campos
     Definições das estruturas de campos.
  * @{
  */
 typedef struct {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info *attributes;  //attributes[attributes_count]
 } field_info;
 /** @} */ // Fim das definições de def_campos

 /*! Definição da estrutura do arquivo de classe. */
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

 /**
  * \defgroup def_java Java
     Definição de estruturas do Java.
  * @{
  */

 /*! Estrutura que modela um tipo de variável em java. */
 typedef struct {

     uint8_t tag; /*!< Representa o tipo especificado na union, conforme as macros definidas em macros.h. */

     union {
         tipo_boolean campo_boolean;
         tipo_byte campo_byte;
         tipo_short campo_short;
         tipo_int campo_int;
         tipo_long campo_long;
         tipo_float campo_float;
         tipo_double campo_double;
     } info; /*!< Mapeia o campo em um dos tipos definidos acima, conforme o valor de tag. */
 } tipo_java;

 /*! Estrutura que modela um runtime field. */
 typedef struct {
     tipo_java dados_field;
     field_info *pt_field;
     class_file *pt_classe;
 } runtime_field;

 /*! Estrutura que modela um objeto java. */
 typedef struct struct_objeto {
     class_file *pt_classe;
     u2 tamanho_lista_runtime_fields;
     runtime_field *lista_runtime_fields;
     u2 tamanho_lista_arrays;
     struct struct_array *lista_arrays;
 } objeto;

 /*! Estrutura que modela um array em java. */
 typedef struct struct_array {

     u1 tag;
     u4 tamanho;
     u1 dimensoes;

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

 } t_array;


 /*! Estrutura que modela uma tabela de classe. */
 typedef struct list_class{
  	class_file *pt_classe;
  	struct list_class *next;
 }elemento_tabela_classes;


 /*! Estrutura que modela uma lista de objetos. */
 typedef struct struct_lista_objetos {
     objeto *pt_objeto;
     struct struct_lista_objetos *proximo;
 } elemento_lista_objetos;

 /** @} */ // Fim das definições de def_java

 /**
  * \defgroup def_pilha Frames e Operandos
     Definição das estruturas de frames e operandos.
  * @{
  */

/*! Estrutura que modela um operando. */
typedef struct operand {
    u1 tag;
    u4 data;
	struct operand *next;
} t_operand;

/*! Estrutura que modela a pilha de operandos. */
typedef struct operand_stack {
	t_operand *first;
} t_operand_stack;

/*! Estrutura que modela um frame. */
typedef struct frame {
	char *nome_metodo;
	method_info *pt_metodo;
	u4 pc;
	code_attribute *code_info;
	u4 array_variaveis_locais_count;
	u4 *array_variaveis_locais;
	t_operand_stack *operand_stack;
	u2 constant_pool_count;
	cp_info *pt_constant_pool;
	elemento_lista_objetos *lista_objetos;
	u4 return_value;
	struct frame *next;
} t_frame;

/*! Estrutura que modela a pilha de frames. */
typedef struct {
    t_frame *first;
} stack_frames;

/** @} */ // Fim das definições de def_pilha

/**
 * \defgroup def_instrucoes Instruções
    Definição das estruturas de instruções.
 * @{
 */

/*! ponteiro para as funções que implementam as instruções. */
typedef void (*t_funcao_instrucao)(stack_frames*);

/*! Estrutura para guardar os nomes das funções e os tipos de operandos. */
typedef struct {
	char *nome;
	t_funcao_instrucao funcao_instrucao;
	u1 operando;
} t_instrucoes;

/** @} */ // Fim das definições de def_intrucoes


#endif /* LIB_TYPES */
