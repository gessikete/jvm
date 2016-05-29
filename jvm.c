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
 *      - Ivan                          10/0088031
 *      - Laís                          00/0000000
 *
 *  Arquivo fonte principal "jvm.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */

#include <stdio.h>
#include "leitor_classe.h"
#include "exibidor_constant_pool.h"
#include "exibidor_atributos.h"

int main(int argc, char*argv[]){
	class_file *class;

	// verifica se o arquivo .class foi passado
	if(argc == 1){
		printf("Um arquivo .class é esperado como parâmetro.\n");
		return 0;
	}

	class = carregar_classe(argv[1]);
	if(class) {
		exibir_constant_pool(class->constant_pool,class->constant_pool_count);
		//exibir_code_attribute(class->attributes[0],class->constant_pool);
	  
	}
	
    return 0;
}
