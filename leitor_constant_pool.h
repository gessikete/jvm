#ifndef LEITOR_CONSTANT_POOL_H
#define LEITOR_CONSTANT_POOL_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arquivos.h"
#include "validation.h"


//Tag das entradas da constant pool que são precedidas por um double ou um long.
#define TAG_LARGE 254

//Tag da primeira entrada da constant pool (que não é utilizada para facilitar o acesso
//elementos da const pool.
#define TAG_0 255

#define TAG_UTF8 1


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


/*
 * Inicializa um vetor de ponteiros para as funcoes de preenchimento dos elementos da
 * constant_pool.
 *
 * Parâmetros:
 *	funcoes_constant: vetor de ponteiros para as funcoes.
 * Retorno:
 *       Nada.
 */
void inicializar_vetor_funcoes(void (*funcoes_constant[]) (FILE*,cp_info[],u2,u1));


/*
 * Preenche o constant pool com todos os seus dados.
 *
 * Parâmetros:
 *	FILE *pt_arquivo: ponteiro para o arquivo aberto;
 *	cp_info: Ponteiro para o array onde esta a constant pool;
 *	tamanho: tamanho da constant_pool
 * Retorno:
 *       Nada.
 */
void criar_constant_pool(FILE *pt_arquivo, cp_info const_pool[], u2 tamanho);


/*
 * As funcoes a seguir preenchem as suas respectivas estruturas de acordo com
 * os dados fornecidos pelo .class
 *
 * Parâmetros:
 *	FILE *pt_arquivo: ponteiro para o arquivo aberto;
 *	const_pool[]: um elemento da constant pool;
 *	index: indice atual de cp_info
 * Retorno:
 *       Nada.
 */
void criar_class_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_fieldref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_utf8_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_string_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_interface_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_integer_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_float_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_long_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_double_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);
void criar_name_and_type_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag);


/*
 * Preenche entrada do constant pool com uma tag invalida
 *
 * Parâmetros:
 *	cp_info: Ponteiro para o array onde esta a constant pool;
 *	index: indice atual de cp_info
 * 	tag: tag invalida
 * Retorno:
 *       Nada.
 */
void tag_invalida(cp_info const_pool[], u2 index, u2 tag);


/*
 * Verifica se tag é um long ou um double.
 *
 * Parâmetros:
 * 	tag: tag a ser avaliada.
 * Retorno:
 *       Nada.
 */
bool large_numeric(u2 tag);

/*
 * Preenche a constant pool
 *
 * Parâmetros:
 *	u2 constant_pool_count: tamanho da constant pool
 *	FILE *pt_arquivo: ponteiro para o arquivo .class
 * Retorno:
 *       Ponteiro para a constant pool.
 */
cp_info *carregar_constant_pool(u2 constant_pool_count, FILE *pt_arquivo);

/*
 * Desaloca o espaço alocado para a estrutura constant pool
 *
 * Parâmetros:
 *		cp_info *constant_pool: ponteiro para a estrutura constant_pool
 *		u2 constant_pool_count: tamanho da constant pool
 * Retorno:
 *		Nenhum
 */
void desalocar_constant_pool(cp_info *constant_pool, u2 constant_pool_count);

#endif /* LEITOR_CONSTANT_POOL_H */
