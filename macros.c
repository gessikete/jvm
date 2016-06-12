#include "macros.h"

void exibir_access_flag_string(u2 flag){
	fprintf(arquivo_saida, "0x%04x [", flag);
	while(flag != 0){
		if(flag >= ACC_ENUM){
			flag -= ACC_ENUM;
			fprintf(arquivo_saida, " enum");
		}else if( flag >= ACC_ANNOTATION){
			flag -= ACC_ANNOTATION;
			fprintf(arquivo_saida, " annotation");
		}else if(flag >= ACC_SYNTHETIC) {
			flag -= ACC_SYNTHETIC;
			fprintf(arquivo_saida, " synthetic");
		}else if (flag >= ACC_ABSTRACT) {
			flag -= ACC_ABSTRACT;
			fprintf(arquivo_saida, " abstract");
		}else if (flag >= ACC_INTERFACE) {
			flag -= ACC_INTERFACE;
			fprintf(arquivo_saida, " interface");
		}else if (flag >= ACC_SUPER) {
			flag -= ACC_SUPER;
			fprintf(arquivo_saida, " super");
		}else if (flag >= ACC_FINAL) {
			flag -= ACC_FINAL;
			fprintf(arquivo_saida, " final");
		} else{
			flag -= ACC_PUBLIC;
			fprintf(arquivo_saida, " public");
		}
	}
	fprintf(arquivo_saida, " ]");
}
