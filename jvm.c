/*
 *  Universidade de Brasília
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2016
 *
 *  Projeto JVM
 *
 *  Grupo 3:
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
	class_file *class;

	// verifica se o arquivo .class foi passado
	if(argc == 2){
		printf("Um arquivo .class é esperado como parâmetro.\n");
		return 0;
	}

	class = carregar_classe(argv[2]);

	if (!strcmp(argv[1], "-l"))
	{
		printf("\nLeitura concluída com sucesso!\n");
	}
	else if (!strcmp(argv[1], "-e"))
	{
		if(class) {

			//abrindo arquivo para gravar a saida
			arquivo_saida = fopen("saida.txt", "w");

			//gravando no arquivo
			exibir_classe(class);
			// desalocar_classe(class);

			printf("\nGravação : 100%%\n");

			fclose(arquivo_saida);

			printf("\nLeitura e gravação concluída com sucesso. Para visualizar o arquivo abra a pasta e localize o arquivo saida.txt!\n\n");
		}
	}
    return 0;
}
