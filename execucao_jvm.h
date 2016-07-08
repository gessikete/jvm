/*!
   \file execucao_jvm.h
   \brief Protótipo das funções para o módulo de execução da JVM.

   Esse arquivo contém os protótipos das funções que definem o execução da JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
/**
 * \defgroup execucao Execução e Inicialização da JVM
 *
 *  Módulo responsável pela inicialização e execução da JVM.
 * @{
 */
#ifndef EXEC_JVM_H
#define EXEC_JVM_H

#include "types.h"
#include "recuperar_constant_pool.h"
#include "estruturas_dados.h"
#include "instrucoes.h"
#include "recuperar_classe.h"

/*!
   \brief Inicializa a JVM.

   Inicializa a JVM recuperando os métodos clinit, init e main. Adiciona o método
   main como primeiro frame na pilha de frames e em seguida o clinit, caso exista.
   Então chama executar_jvm para executar as instruções.

   \param pt_classe Ponteiro para a estrutura com as informações sobre a classe.

   \return Nenhum.
*/
//void inicializar_jvm(class_file *pt_classe, int argc, char *argv[]);
void inicializar_jvm(class_file *pt_classe);

/*!
   \brief Executa a JVM.

   Inicializa o vetor de instruções e executa as instruções da pilha de frames
   até estar vazio.

   \param pilha_frames Ponteiro para a pilha de frames.

   \return Nenhum.
*/
void executar_jvm(stack_frames *pilha_frames);

#endif /* EXEC_JVM_H */

/** @} */ // fim da definição de execucao
