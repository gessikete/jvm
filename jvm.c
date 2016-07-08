/*!
   \file jvm.c
   \brief Arquivo fonte principal.

   Arquivo principal que contém a função main. Essa função é responsável por
   parcear os parâmetros passados por linha de comando e executar a leitura e
   exibição do arquivo class ou somente a leitura.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

/**
 * \defgroup jvm Main
 *
 *  Arquivo principal que contém o parseamento dos parâmetros passados para a
 *	execução da JVM e a função principal main.
 *
 * @{
 */

#include <stdio.h>
#include "types.h"
#include "leitor_classe.h"
#include "exibidor_classe.h"
#include "execucao_jvm.h"

// #define DEBUG /** Descomentar caso deseje usar o modo debug */

int main(int argc, char*argv[]){
	class_file *pt_classe;

	// verifica se o for informada a quantidade necessária de argumentos
	if(argc != 4){
		printf("\nATENÇÃO\n");
		printf("Para executar esse programa siga as seguintes instruções:\n");
		printf("Para executar esse programa utilizando o terminal a partir da raiz do projeto execute:\n");
		printf("$ ./jvm.exe { -e | -l } {path} {arquivo}\n\n");
		printf("De forma que:\n");
		printf("{ -e | -l }\n");
		printf(" -e caso queira carregar o arquivo .class e escrever a saída no arquivo saida.txt\n");
		printf(" -l caso queira somente carregar o arquivo .class");
		printf("\n\nExemplo: ./jvm.exe -l path/ Arquivo\n\n");
	} else{
		path = argv[2];
		char *nome_classe = argv[3];

		// Carrega as informações do arquivo .class para a memória
		pt_classe = carregar_classe(nome_classe);

		if ((!strcmp(argv[1], "-l"))&&(pt_classe)){
			//printf("\nLeitura concluída com sucesso!\n");
			//inicializar_jvm(pt_classe,argc,argv);
            inicializar_jvm(pt_classe);

		} else if (!strcmp(argv[1], "-e")){
			if(pt_classe) {

				// Abrindo arquivo para gravar a saida
				arquivo_saida = fopen("saida.txt", "w");

				// Gravo o a saída das informações da classe no arquivo
				exibir_classe(pt_classe);

				// Desaloca a classe
				desalocar_classe(pt_classe);

				// Fechando arquivo após gravação
				fclose(arquivo_saida);

				printf("\nLeitura e gravação concluída com sucesso.\n");
				printf("\nPara visualizar o arquivo abra a pasta e localize o arquivo saida.txt!\n\n");
			}
		}
	}
    return 0;
}

/** @} */ // fim da definição de jvm
