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
	if(argc == 1){
		printf("Um arquivo .class é esperado como parâmetro.\n");
		return 0;
	}

	class = carregar_classe(argv[1]);
	if(class) {
		exibir_classe(class);
		// desalocar_classe(class);
	}

    return 0;
}
