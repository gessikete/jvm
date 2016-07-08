/*!
   \file macros.c
   \brief Implementação das funções que manipulam as macros utilizadas pela JVM.

   Este arquivo contém as implementações das funções necessárias para manipulação.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "macros.h"

void exibir_access_flag_class(u2 flag){
	fprintf(arquivo_saida, "0x%04x [", flag);
	while(flag != 0){
		if(flag >= ACC_ABSTRACT){
			flag -= ACC_ABSTRACT;
			fprintf(arquivo_saida, " abstract");
		}else if( flag >= ACC_INTERFACE){
			flag -= ACC_INTERFACE;
			fprintf(arquivo_saida, " interface");
		}else if(flag >= ACC_SUPER) {
			flag -= ACC_SUPER;
			fprintf(arquivo_saida, " super");
		}else if (flag >= ACC_FINAL) {
			flag -= ACC_FINAL;
			fprintf(arquivo_saida, " final");
		}else if (flag >= ACC_PUBLIC) {
			flag -= ACC_PUBLIC;
			fprintf(arquivo_saida, " public");
		}
	}
	fprintf(arquivo_saida, " ]");
}

void exibir_access_flag_field(u2 flag){
	fprintf(arquivo_saida, "\n0x%04x [", flag);
	while(flag != 0){
		if(flag >= ACC_TRANSIENT){
			flag -= ACC_TRANSIENT;
			fprintf(arquivo_saida, " transient");
		}else if( flag >= ACC_VOLATILE){
			flag -= ACC_VOLATILE;
			fprintf(arquivo_saida, " volatile");
		}else if(flag >= ACC_FINAL) {
			flag -= ACC_FINAL;
			fprintf(arquivo_saida, " final");
		}else if (flag >= ACC_STATIC) {
			flag -= ACC_STATIC;
			fprintf(arquivo_saida, " static");
		}else if (flag >= ACC_PROTECTED) {
			flag -= ACC_PROTECTED;
			fprintf(arquivo_saida, " protected");
		}else if (flag >= ACC_PRIVATE) {
			flag -= ACC_PRIVATE;
			fprintf(arquivo_saida, " private");
		}else if (flag >= ACC_PUBLIC) {
			flag -= ACC_PUBLIC;
			fprintf(arquivo_saida, " public");
		}
	}
	fprintf(arquivo_saida, " ]");
}

void exibir_access_flag_method(u2 flag){
	fprintf(arquivo_saida, "\n0x%04x [", flag);
	while(flag != 0){
		if(flag >= ACC_STRICT){
			flag -= ACC_STRICT;
			fprintf(arquivo_saida, " strictfp");
		}else if( flag >= ACC_ABSTRACT){
			flag -= ACC_ABSTRACT;
			fprintf(arquivo_saida, " abstract");
		}else if(flag >= ACC_NATIVE) {
			flag -= ACC_NATIVE;
			fprintf(arquivo_saida, " native");
		}else if (flag >= ACC_SYNCHRONIZED) {
			flag -= ACC_SYNCHRONIZED;
			fprintf(arquivo_saida, " synchronized");
		}else if (flag >= ACC_FINAL) {
			flag -= ACC_FINAL;
			fprintf(arquivo_saida, " final");
		}else if (flag >= ACC_STATIC) {
			flag -= ACC_STATIC;
			fprintf(arquivo_saida, " static");
		}else if (flag >= ACC_PROTECTED) {
			flag -= ACC_PROTECTED;
			fprintf(arquivo_saida, " protected");
		} else if (flag >= ACC_PRIVATE){
			flag -= ACC_PRIVATE;
			fprintf(arquivo_saida, " private");
		} else if (flag >= ACC_PUBLIC){
			flag -= ACC_PUBLIC;
			fprintf(arquivo_saida, " public");
		}
	}
	fprintf(arquivo_saida, " ]");
}

void exibir_access_flag_inner_class(u2 flag){
	fprintf(arquivo_saida, "\n0x%04x [", flag);
	while(flag != 0){
		if(flag >= ACC_ABSTRACT){
			flag -= ACC_ABSTRACT;
			fprintf(arquivo_saida, " abstract");
		}else if( flag >= ACC_INTERFACE){
			flag -= ACC_INTERFACE;
			fprintf(arquivo_saida, " interface");
		}else if(flag >= ACC_FINAL) {
			flag -= ACC_FINAL;
			fprintf(arquivo_saida, " final");
		}else if (flag >= ACC_STATIC) {
			flag -= ACC_STATIC;
			fprintf(arquivo_saida, " static");
		}else if (flag >= ACC_PROTECTED) {
			flag -= ACC_PROTECTED;
			fprintf(arquivo_saida, " protected");
		}else if (flag >= ACC_PRIVATE) {
			flag -= ACC_PRIVATE;
			fprintf(arquivo_saida, " private");
		}else if (flag >= ACC_PUBLIC) {
			flag -= ACC_PUBLIC;
			fprintf(arquivo_saida, " public");
		}
	}
	fprintf(arquivo_saida, " ]");
}
