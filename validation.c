#include "validation.h"
#include <stdio.h>

bool validar_magic(u4 magic){
	if(magic == 0xCAFEBABE){
		return true;
	}
	fprintf(arquivo_saida, "Magic Number Invalido.\n");
	return false;
}

bool validar_version(u2 minor, u2 major){
	if((major > 46 || major < 45) || (major == 46 && minor > 0)){
		fprintf(arquivo_saida, "Arquivo Com Versão Invalida.\n");
		return false;
	}
	return true;
}

bool validar_tag(u2 tag) {
	if((tag>=1) && (tag!=2) && (tag<=12)) {
	return true;
	}
	fprintf(arquivo_saida, "Arquivo com a tag invalida.\n");
	return false;
}
