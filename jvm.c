/*
 *  Universidade de Brasília
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2016
 *
 *  Projeto JVM
 *
 *  Grupo:
 *      - Alisson Carvalho              12/0072521
 *      - Ana Carolina Lopes            11/0107578
 *      - Géssica Neves Sodré da Silva  11/0146115
 *      - Ivan Sena                     10/0088031
 *		- Laís Mendes Gonçalves			11/0033647
 *
 *  Arquivo fonte principal "jvm.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */

#include <stdio.h>
#include "leitor_classe.h"
#include "exibidor_classe.h"


int main(int argc, char*argv[]){
	class_file *pt_classe;

	// verifica se o for informada a quantidade necessária de argumentos
	if(argc != 3){
		printf("\nATENÇÃO\n");
		printf("Para executar esse programa siga as seguintes instruções:\n");
		printf("Para executar esse programa utilizando o terminal a partir da raiz do projeto execute:\n");
		printf("$ ./jvm.exe { -e | -l } {arquivo.class}\n\n");
		printf("De forma que:\n");
		printf("{ -e | -l }\n");
		printf(" -e caso queira carregar o arquivo .class e escrever a saída no arquivo saida.txt\n");
		printf(" -l caso queira somente carregar o arquivo .class");
	}else{
		char *nome_classe = argv[2];

		// Carrega as informações do arquivo .class para a memória
		pt_classe = carregar_classe(nome_classe);

		if (!strcmp(argv[1], "-l")){
			printf("\nLeitura concluída com sucesso!\n");
		}else if (!strcmp(argv[1], "-e")){
			if(pt_classe) {

				// Abrindo arquivo para gravar a saida
				arquivo_saida = fopen("saida.txt", "w");

				// Gravo o a saída das informações da classe no arquivo
				exibir_classe(pt_classe);

				// Desaloca a classe
				desalocar_classe(pt_classe);

				printf("\nGravação : 100%%\n");

				// Fechando arquivo após gravação
				fclose(arquivo_saida);

				printf("\nLeitura e gravação concluída com sucesso.\n");
				printf("\nPara visualizar o arquivo abra a pasta e localize o arquivo saida.txt!\n\n");
			}
		}
	}
    return 0;
}
