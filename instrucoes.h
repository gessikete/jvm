#ifndef INSTRUCOES_H
#define INSTRUCOES_H



#include "types.h"


#include "instrucoes_0-40.h"
#include "instrucoes_41-80.h"
#include "instrucoes_81-120.h"
#include "instrucoes_121-160.h"
#include "instrucoes_161-201.h"
#include "pilha_frames.h"


#define NO_OP 0
#define CP2 1
#define CP1 2
#define LV1 3
#define INT1 4
#define INT2 5
#define LV1_INT1 6
#define OFFSET2 7
#define OFFSET4 8
#define CP2_INT1 9
#define FLAG1 10
#define TABLE_SWITCH 11
#define LOOKUP_SWITCH 12
#define CP2_INT0 13

u4 float_to_u4(float numero_float);
u8 double_to_u8(double numero_double);
u8 long_to_u8(long numero_double);

float u4_to_float(u4 numero_u4);
long u8_to_long(u4 high, u4 low);
double u8_to_double(u4 low, u4 high);

void init_instrucoes();

/*
 * Preenche um vetor de t_instrucoes com o nome da instrução e o seu tipo de
 * operando de acordo com o seu opcode
 *
 * Parâmetros:
 *       Nenhum
 *
 * Retorno:
 *       Um vetor de structs do tipo t_instrucoes
 */
t_instrucoes* vetorMnemonicos (void);


/*
 * Retorna o tamanho de um operando de acordo com o tipo do operando. Se o operando
 * for do tipo LOOKUP_SWITCH ou TABLE_SWITCH, retorna 15.
 *
 * Parâmetros:
 *       u1 operando: o tipo do operando
 *
 * Retorno:
 *       Tamanho do operando ou 15 (Se for LOOKUP_SWITCH ou TABLE_SWITCH).
 */
u1 acha_tamanho_operando(u1 operando);


/*
 * Concatena dois bytes de code.
 *
 * Parâmetros:
 *      u1 code[]: vetor com a parte de code de um método
 * 	u4 index: índice onde está o primeiro byte a ser concatenado
 *
 * Retorno:
 *      Dois bytes de code[] concatenados.
 */
u2 operando_u2 (u1 code[], u4 index);

/*
 * Concatena quatro bytes de code.
 *
 * Parâmetros:
 *      u1 code[]: vetor com a parte de code de um método
 * 	u4 index: índice onde está o primeiro byte a ser concatenado
 *
 * Retorno:
 *     	Quatro bytes de code[] concatenados.
 */
u4 operando_u4 (u1 code[], u4 index);


/*
 * Relaciona um tipo primitivo de um array com um número inteiro
 *
 * Parâmetros:
 *      u1 type_code: o número inteiro a ser relacionado
 *
 * Retorno:
 *     	String que representa um tipo primitivo
 */
char *primitive_array_info(u1 type_code);


// Declaração do vetor que contém os nomes da instruções, suas respectivas funções e os tipos de seus operandos
extern t_instrucoes instrucoes[];

#endif
