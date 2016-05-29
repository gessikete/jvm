#ifndef REC_CONST_POOL_H
#define REC_CONST_POOL_H


#include "leitor_constant_pool.h"
/*
 * Lê o campo bytes de um utf8_info e os salva em uma string.
 *
 * Parâmetros:
 *	char string[]: String a ser escrita
 *	u2 length: Tamanho da string
 *	constant_utf8_info utf8_info: Bytes a serem escritos na string
 *
 * Retorno:
 *       Nada
 */
void recupera_utf8(char string[], u2 length, constant_utf8_info utf8_info);



/*
 * Recupera o nome de uma classe de acordo com o seu indice no constant pool.
 *
 * Parâmetros:
 *	cp_info *pt_const_pool: ponteiro para a constant pool
 *	u2 class_index: indice da classe 
 *
 * Retorno:
 *       Nome da classe
 */
char *recupera_class_name(cp_info *pt_const_pool, u2 class_index);


/*
 * Recupera o nome e o tipo de uma estrutura do tipo name_and_type_info de acordo com o
 * seu indice.
 *
 * Parâmetros:
 *	cp_info *pt_const_pool: ponteiro para a constant pool
 *	u2 index: indice da estrutura
 *
 * Retorno:
 *       Nome e descritor.
 */
char *recupera_name_and_type_name(cp_info *pt_const_pool, u2 index);


/*
 * As funcoes a seguir recuperam os bits mais significativos e menos significativos de
 * um unsigned de 64 bits, respectivamente.
 *
 * Parâmetros:
 *	u8 bytes: unsigned de 64 bits
 *
 * Retorno:
 *      Um unsigned de 32 bits.
 */
u4 recupera_high_bytes(u8 bytes);
u4 recupera_low_bytes(u8 bytes);


/*
 * Recupera a string em utf8_info de acordo com o seu indice no constant pool.
 *
 * Parâmetros:
 *	cp_info *pt_const_pool: ponteiro para a constant pool
 *	u2 string_index: indice da string
 *
 * Retorno:
 *      Um ponteiro para a string em utf8_info.
 */
char *recupera_string(cp_info *pt_const_pool, u2 string_index);



#endif