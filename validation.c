/*!
   \file validation.c
   \brief Implementação das funções que validam o .class.

   Este arquivo contém as implementações das funções que validam o arquivo .class
   passado como parâmetro de acordo com o .class gerado através do comando
   <javac {arquivo.java} -source 1.2 -target 1.2>

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "validation.h"

bool validar_nome(cp_info *constant_pool, u2 attributes_count, attribute_info *attributes, char *nome_arquivo) {
        attribute_info *atributo = attributes;
        int i;
        
        for(i=0; i<attributes_count; i++) {
                if(atributo[i].attribute_tag==SOURCE_FILE_NUM) break;
        }
        source_file_attribute source_file = atributo[i].info.source_file_info;
        u2 source_file_index = source_file.source_file_index;
        char *nome_source = recupera_utf8(constant_pool, source_file_index);
        char nome_java[strlen(nome_arquivo)+5];
        
        strcpy(nome_java,nome_arquivo);
        strcat(nome_java,".java");
 
        if(!strcmp(nome_source,nome_java)) return true;
        return false;
        
}

bool validar_magic(u4 magic){
	if(magic == 0xCAFEBABE){
		return true;
	}
	fprintf(arquivo_saida, "Magic number inválido.\n");
	printf("Magic number inválido.\n");
	return false;
}

bool validar_version(u2 minor, u2 major){
	if((major > 46 || major < 45) || (major == 46 && minor > 0)){
		fprintf(arquivo_saida, "Arquivo com versão invalida.\n");
		printf("Arquivo com versão invalida.\n");
		return false;
	}
	return true;
}

bool validar_tag(u2 tag) {
	if((tag>=1) && (tag!=2) && (tag<=12)) {
		return true;
	}
	if(tag!=254) {
		fprintf(arquivo_saida, "Arquivo com a tag inválida.\n");
		printf("Arquivo com a tag inválida.\n");
		return false;
	}
	return false;
}

bool validar_access_flag(u2 flags){
	// Verifica se é uma interface
    if((flags & ACC_INTERFACE) == ACC_INTERFACE){
    	// Se interface, verfica se é abstrata
		if(((flags & ACC_ABSTRACT) != ACC_ABSTRACT)){
			fprintf(arquivo_saida, "Access flags inválidas. Interface não abstrata.\n");
            printf("Access flags inválidas. Interface não abstrata.\n");
			return false;
        }else if(((flags & ACC_FINAL) == ACC_FINAL) || ((flags & ACC_SUPER) == ACC_SUPER)){ // se for interface e abstrata, verifica se não é final ou super
			fprintf(arquivo_saida, "Access flags inválidas. Interface abstrata com flag final ou super.\n");
            printf("Access flags inválidas. Interface abstrata com flag final ou super.\n");
			return false;
		}
		return true;
    }else{
		// Caso não seja interface, verifica se não é final e abstrata
        if (((flags & ACC_FINAL) == ACC_FINAL) && ((flags & ACC_ABSTRACT) == ACC_ABSTRACT)) {
			fprintf(arquivo_saida, "Access flags inválidas. Classe com flags final e abstract.\n");
            printf("Access flags inválidas. Classe com flags final e abstract.\n");
			return false;
        }
    }
	return true;
}
