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
 *      - Alisson Carvalho              00/0000000
 *      - Ana Carolina                  11/0107578
 *      - Géssica Neves Sodré da Silva  11/0146115
 *      - Ivan                          00/0000000
 *      - Laís                          00/0000000
 *
 *  Arquivo fonte principal "main.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */

#include <stdio.h>
#include "class_reader.h"
#include "exibidor_constant_pool.h"

int main(int argc, char*argv[]){
	class_file *class;

	// verifica se o arquivo .class foi passado
	if(argc <= 1){
		printf("Um arquivo .class é esperado como parâmetro.\n");
		return 0;
	}

	class = carregar_classe(argv[1]);
	if(class) {
		exibir_constant_pool(class->constant_pool,class->constant_pool_count);
	}
	
	

    return 0;
}
