/*!
   \file instrucoes_121-160.h
   \brief Protótipo das funções que implementam as instruções da Máquina Virtual
   Java.

   Esse arquivo contém os protótipos das funções que definem as instruções executadas
   pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \addtogroup instrucoes
 * @{
 */
#ifndef INSTRUCOES_121_160_H
#define INSTRUCOES_121_160_H

#include "instrucoes.h"
#include "estruturas_dados.h"
#include "leitor_constant_pool.h"

/*!
   \brief Desempilha dois long da pilha de operandos. O segundo int a ser desempilhado
   é shiftado s posições para a esquerda, sendo s os 6bits menos significativos
   do primeiro int desempilhado. Então, o resultado é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lshl(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. O segundo int a ser desempilhado
   é shiftado s posições para a direita, sendo s os 5bits menos significativos
   do primeiro int desempilhado. Então, o resultado é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ishr(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois long da pilha de operandos. O segundo int a ser desempilhado
   é shiftado s posições para a direita, sendo s os 6bits menos significativos
   do primeiro int desempilhado. Então, o resultado é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lshr(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. O segundo int a ser desempilhado
   é shiftado s posições para a direita, com extensão de zeros, sendo s os 5bits
   menos significativos do primeiro int desempilhado. Então, o resultado é empilhado
   na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void iushr(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois long da pilha de operandos. O segundo long a ser desempilhado
   é shiftado s posições para a direita, com extensão de zeros, sendo s os 6bits
   menos significativos do primeiro long desempilhado. Então, o resultado é empilhado
   na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lushr(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. O segundo int a ser desempilhado
   é somado bit a bit com primeiro int desempilhado. Então, o resultado é empilhado
   na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void iand(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois long da pilha de operandos. O segundo long a ser desempilhado
   é somado bit a bit com primeiro long desempilhado. Então, o resultado é empilhado
   na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void land(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. É aplicado o or bit a bit
   dos dois valores. Então, o resultado é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ior(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois long da pilha de operandos. É aplicado o or bit a bit
   dos dois valores. Então, o resultado é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lor(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. É aplicado o xor bit a bit
   dos dois valores. Então, o resultado é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ixor(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois long da pilha de operandos. É aplicado o xor bit a bit
   dos dois valores. Então, o resultado é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lxor(stack_frames *pilha_frames);

/*!
   \brief Caso wide_ seja 0, recupera os próximos dois bytes do code como index,
   caso contrário, recupera somente um byte. Após incrementar o PC, recupera o
   incremento, dois bytes caso wide_ seja 0 e um byte, caso contrário. Então,
   incrementa o int na posição index do array de variáveis locais em incremento.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void iinc(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e converte para long. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void i2l(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e converte para float. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void i2f(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e converte para double. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void i2d(stack_frames *pilha_frames);

/*!
   \brief Desempilha um long da pilha de operandos e converte para int. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void l2i(stack_frames *pilha_frames);

/*!
   \brief Desempilha um long da pilha de operandos e converte para float. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void l2f(stack_frames *pilha_frames);

/*!
   \brief Desempilha um long da pilha de operandos e converte para double. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void l2d(stack_frames *pilha_frames);

/*!
   \brief Desempilha um float da pilha de operandos e converte para int. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void f2i(stack_frames *pilha_frames);

/*!
   \brief Desempilha um float da pilha de operandos e converte para long. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void f2l(stack_frames *pilha_frames);

/*!
   \brief Desempilha um float da pilha de operandos e converte para double. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void f2d(stack_frames *pilha_frames);

/*!
   \brief Desempilha um double da pilha de operandos e converte para int. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void d2i(stack_frames *pilha_frames);

/*!
   \brief Desempilha um double da pilha de operandos e converte para long. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void d2l(stack_frames *pilha_frames);

/*!
   \brief Desempilha um double da pilha de operandos e converte para float. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void d2f(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e converte para byte. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void i2b(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e converte para char. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void i2c(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e converte para short. O resultado
   é empilhado na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void i2s(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois long da pilha de operandos. Caso o segundo valor desempilhado
   seja maior que o primeiro, empilha 1 na pilha de operandos. Caso os dois valores
   desepilhados sejam iguais, empilha 0 na pilha de operandos. Caso o segundo valor
   desempilhado seja menor que o primeiro, empilha -1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void lcmp(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois float da pilha de operandos. Caso o segundo valor desempilhado
   seja maior que o primeiro, empilha 1 na pilha de operandos. Caso os dois valores
   desepilhados sejam iguais, empilha 0 na pilha de operandos. Caso o segundo valor
   desempilhado seja menor que o primeiro, empilha -1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fcmpl(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois float da pilha de operandos. Caso o segundo valor desempilhado
   seja maior que o primeiro, empilha 1 na pilha de operandos. Caso os dois valores
   desepilhados sejam iguais, empilha 0 na pilha de operandos. Caso o segundo valor
   desempilhado seja menor que o primeiro, empilha -1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void fcmpg(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois double da pilha de operandos. Caso o segundo valor desempilhado
   seja maior que o primeiro, empilha 1 na pilha de operandos. Caso os dois valores
   desepilhados sejam iguais, empilha 0 na pilha de operandos. Caso o segundo valor
   desempilhado seja menor que o primeiro, empilha -1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dcmpl(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois double da pilha de operandos. Caso o segundo valor desempilhado
   seja maior que o primeiro, empilha 1 na pilha de operandos. Caso os dois valores
   desepilhados sejam iguais, empilha 0 na pilha de operandos. Caso o segundo valor
   desempilhado seja menor que o primeiro, empilha -1 na pilha de operandos.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void dcmpg(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e o compara com 0. Caso seja igual,
   o offset é calculado com os unsigneds branchbyte1 e branchbyte2 e a execução
   continua a partir do offset calculado. Caso contrário, a execução continua no
   endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ifeq(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e o compara com 0. Caso seja diferente,
   o offset é calculado com os unsigneds branchbyte1 e branchbyte2 e a execução
   continua a partir do offset calculado. Caso contrário, a execução continua no
   endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ifne(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e o compara com 0. Caso seja menor,
   o offset é calculado com os unsigneds branchbyte1 e branchbyte2 e a execução
   continua a partir do offset calculado. Caso contrário, a execução continua no
   endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void iflt(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e o compara com 0. Caso seja
   maior ou igual, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ifge(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e o compara com 0. Caso seja maior,
   o offset é calculado com os unsigneds branchbyte1 e branchbyte2 e a execução
   continua a partir do offset calculado. Caso contrário, a execução continua no
   endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ifgt(stack_frames *pilha_frames);

/*!
   \brief Desempilha um int da pilha de operandos e o compara com 0. Caso seja
   menor ou igual, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void ifle(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. Caso o segundo seja igual ao
   primeiro, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void if_icmpeq(stack_frames *pilha_frames);

/*!
   \brief Desempilha dois int da pilha de operandos. Caso o segundo seja diferente do
   primeiro, o offset é calculado com os unsigneds branchbyte1 e branchbyte2
   e a execução continua a partir do offset calculado. Caso contrário, a execução
   continua no endereço da instrução seguinte.

   \param pilha_frames ponteiro para a pilha de frames.

   \return Nenhum
*/
void if_icmpne(stack_frames *pilha_frames);

#endif /* INSTRUCOES_121_160_H */

/** @} */ // fim da definição de instrucoes
