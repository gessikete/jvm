/*!
   \file instrucoes.h
   \brief Protótipo das funções que manipulam as instruções da Máquina Virtual
   Java.

   Esse arquivo contém os protótipos das funções que manipulam as instruções
   executadas pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \defgroup instrucoes Manipulação de instruções
 *
 *  Módulo que contém toda a manipulação das instruções utilizadas para a execução
 *  da JVM.
 * @{
 */
#ifndef INSTRUCOES_H
#define INSTRUCOES_H

#include "types.h"
#include "instrucoes_0-40.h"
#include "instrucoes_41-80.h"
#include "instrucoes_81-120.h"
#include "instrucoes_121-160.h"
#include "instrucoes_161-201.h"
#include "estruturas_dados.h"

/*
 * Define o tipo do operando.
 */
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

/*!
   \brief Converte um float para um unsigned int 32bits.

   \param numero_float Float a ser convertido.

   \return Float no formato u4.
*/
u4 float_to_u4(float numero_float);

/*!
   \brief Converte um double para um unsigned int 64bits.

   \param numero_double Double a ser convertido.

   \return Double no formato u8.
*/
u8 double_to_u8(double numero_double);

/*!
   \brief Converte um long para um unsigned int 64bits.

   \param numero_long Long a ser convertido.

   \return Long no formato u8.
*/
u8 long_to_u8(long numero_long);

/*!
   \brief Converte um double para um float.

   \param numero_double Double a ser convertido.

   \return Double convertido para float.
*/
float double_to_float(double numero_double);

/*!
   \brief Converte um double para int.

   \param numero_double Double a ser convertido.

   \return Double convertido para int.
*/
int double_to_int(double numero_double);

/*!
   \brief Converte um unsigned int 32bits para um float.

   \param numero_u4 Unsigned int 32bits a ser convertido.

   \return u4 convertido para float.
*/
float u4_to_float(u4 numero_u4);

/*!
   \brief Converte dois unsigned int 32bits para um long.

   \param high Unsigned int 32bits de high order.
   \param low Unsigned int 32bits de low order.

   \return Dois unsigned int 32bits convertido para Long.
*/
long u8_to_long(u4 high, u4 low);

/*!
   \brief Converte dois unsigned int 32bits para um double.

   \param high Unsigned int 32bits de high order.
   \param low Unsigned int 32bits de low order.

   \return Dois unsigned int 32bits convertido para double.
*/
double u8_to_double(u4 low, u4 high);

/*!
   \brief Inicializa o vetor de instruções.

   \param Nenhum.

   \return Nenhum.
*/
void init_instrucoes();

 /*!
    \brief Preenche um vetor de t_instrucoes com o nome da instrução e o seu tipo
    de operando de acordo com o seu opcode.

    \param Nenhum

    \return Um vetor de structs do tipo t_instrucoes.
 */
t_instrucoes* vetorMnemonicos (void);

 /*!
    \brief Retorna o tamanho de um operando de acordo com o tipo do operando.
    Se o operando for do tipo LOOKUP_SWITCH ou TABLE_SWITCH, retorna 15.

    \param operando O tipo do operando.

    \return Tamanho do operando ou 15 (Se for LOOKUP_SWITCH ou TABLE_SWITCH).
 */
u1 acha_tamanho_operando(u1 operando);

 /*!
    \brief Concatena dois bytes de code.

    \param code[] Vetor com a parte de code de um método.
    \param index Índice onde está o primeiro byte a ser concatenado.

    \return Dois bytes de code[] concatenados.
 */
u2 operando_u2 (u1 code[], u4 index);

 /*!
    \brief Concatena quatro bytes de code.

    \param code[] Vetor com a parte de code de um método.
    \param index Índice onde está o primeiro byte a ser concatenado.

    \return Quatro bytes de code[] concatenados.
 */
u4 operando_u4 (u1 code[], u4 index);

 /*!
    \brief Relaciona um tipo primitivo de um array com um número inteiro.

    \param type_code O número inteiro a ser relacionado.

    \return String que representa um tipo primitivo.
 */
char *primitive_array_info(u1 type_code);

/*!
   \brief Descobre o tipo de um descritor.

   \param descritor String que descreve o descritor.

   \return Tag do descritor correspondente.
*/
u2 tipo_descritor(char *descritor);

//! Vetor de instruções.
/*! Declaração do vetor que contém os nomes da instruções, suas respectivas
funções e os tipos de seus operandos. */
extern t_instrucoes instrucoes[];

/*!
   \brief Descobre o tipo de um multiarray com base no class name.

   \param name_class Nome da classe do multiarray.
   \param dimensao Dimensao do array multidimensional.

   \return Ponteiro para uma lista de arrays.
*/
u1 tipo_multiarray(char *name_class, u1 dimensao);


/*!
   \brief Função recursiva que cria os subarrays de um multiarray.

   \param nivel Nível do subarray atual.
   \param tamanho Vetor que armazena o tamanho de cada subarray.
   \param subarray Vetor de ponteiros do tipo t_array; usado para criar os subarrays.
   \param tag Tipo do subarray no nível zero (int, float, etc).

   \return Nenhum.
*/
void for_array_multidimensional(u4 nivel, u4 tamanho[], t_array *subarray[], u1 tag);

#endif /* INSTRUCOES_H */

/** @} */ // fim da definição de instrucoes
