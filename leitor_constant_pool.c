/*!
   \file leitor_constant_pool.c
   \brief Implementação das funções que manipulam a leitura da constant pool.

   Este arquivo contém as implementações das funções que manipulam a leitura da
   constant pool.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "leitor_constant_pool.h"

void inicializar_vetor_funcoes(void (*funcoes_constant[]) (FILE*,cp_info[],u2,u1)) {
	funcoes_constant[1] = criar_utf8_info;
	funcoes_constant[3] = criar_integer_info;
	funcoes_constant[4] = criar_float_info;
	funcoes_constant[5] = criar_long_info;
	funcoes_constant[6] = criar_double_info;
	funcoes_constant[7] = criar_class_info;
	funcoes_constant[8] = criar_string_info;
	funcoes_constant[9] = criar_fieldref_info;
	funcoes_constant[10] = criar_methodref_info;
	funcoes_constant[11] = criar_interface_methodref_info;
	funcoes_constant[12] = criar_name_and_type_info;
}

void criar_class_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	constant_class_info class_info;
	u2 name_index = ler_u2(pt_arquivo);

	class_info.name_index = name_index;

	const_pool[index].tag = tag;
	const_pool[index].info.class_info = class_info;
}


void criar_fieldref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	constant_fieldref_info fieldref_info;
	u2 class_index=ler_u2(pt_arquivo);
	u2 name_and_type_index=ler_u2(pt_arquivo);

	fieldref_info.class_index = class_index;
	fieldref_info.name_and_type_index = name_and_type_index;

	const_pool[index].tag = tag;
	const_pool[index].info.fieldref_info = fieldref_info;

}


void criar_utf8_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	constant_utf8_info utf8_info;
	int i;
	u2 length=ler_u2(pt_arquivo);

	utf8_info.length = length;
	utf8_info.bytes = (u1*)malloc(sizeof(u1)*length);
	for(i=0; i<length; i++) {
		utf8_info.bytes[i] = ler_u1(pt_arquivo);
	}

	const_pool[index].tag = tag;
	const_pool[index].info.utf8_info = utf8_info;
}


void criar_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	u2 class_index = ler_u2(pt_arquivo);
	u2 name_and_type_index = ler_u2(pt_arquivo);
	constant_methodref_info methodref_info;

	methodref_info.class_index = class_index;
	methodref_info.name_and_type_index = name_and_type_index;

	const_pool[index].tag = tag;
	const_pool[index].info.methodref_info = methodref_info;
}


void criar_string_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	u2 string_index = ler_u2(pt_arquivo);
	constant_string_info string_info;

	string_info.string_index = string_index;

	const_pool[index].tag = tag;
	const_pool[index].info.string_info = string_info;

}


void criar_interface_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	constant_interface_methodref_info interface_methodref_info;
	u2 class_index = ler_u2(pt_arquivo);
	u2 name_and_type_index = ler_u2(pt_arquivo);

	interface_methodref_info.class_index = class_index;
	interface_methodref_info.name_and_type_index = name_and_type_index;

	const_pool[index].tag = tag;
	const_pool[index].info.interface_methodref_info = interface_methodref_info;
}


void criar_integer_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	u4 bytes = ler_u4(pt_arquivo);
	constant_integer_info integer_info;

	integer_info.bytes = bytes;

	const_pool[index].tag = tag;
	const_pool[index].info.integer_info = integer_info;
}


void criar_float_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	u4 bytes = ler_u4(pt_arquivo);
	constant_float_info float_info;

	float_info.bytes = bytes;

	const_pool[index].tag = tag;
	const_pool[index].info.float_info = float_info;

}


void criar_long_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	constant_long_info long_info;
	u8 bytes = ler_u8(pt_arquivo);

	long_info.bytes = bytes;

	const_pool[index].tag = tag;
	const_pool[index].info.long_info = long_info;
}


void criar_double_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	constant_double_info double_info;
	u8 bytes = ler_u8(pt_arquivo);

	double_info.bytes = bytes;

	const_pool[index].tag = tag;
	const_pool[index].info.double_info = double_info;

}


void criar_name_and_type_info(FILE *pt_arquivo, cp_info const_pool[], u2 index, u1 tag) {
	constant_name_and_type_info name_and_type_info;
	u2 name_index = ler_u2(pt_arquivo);
	u2 descriptor_index = ler_u2(pt_arquivo);

	name_and_type_info.name_index = name_index;
	name_and_type_info.descriptor_index = descriptor_index;

	const_pool[index].tag = tag;
	const_pool[index].info.name_and_type_info = name_and_type_info;

}

void tag_invalida(cp_info const_pool[], u2 index, u2 tag) {
	const_pool[index].tag = tag;
}

bool large_numeric(u2 tag) {
	if((tag==0x06) || (tag==0x05)) return true;
	return false;
}

void criar_constant_pool(FILE *pt_arquivo, cp_info const_pool[], u2 tamanho) {
	u2 i;
	u1 tag;
	void (*funcoes_constant[13]) (FILE*,cp_info[],u2,u1);

	//Preenche vetor de funcoes
	inicializar_vetor_funcoes(funcoes_constant);


	//A primeira entrada de const_pool não é utilizada para facilitar na recuperação
	//de índices
	const_pool[0].tag = TAG_0;

	//Lê e escreve todos os elementos da constant pool no vetor const_pool
	for(i=1; i<tamanho; i++) {
		//Lê a tag
		tag = ler_u1(pt_arquivo);

		if(validar_tag(tag)) {
			//Executa funcao associada a tag. A funcao ira preencher a entrada.
			funcoes_constant[tag](pt_arquivo,const_pool,i,tag);

			//Verifica se tag é um double ou long
			if(large_numeric(tag)) {
			  const_pool[++i].tag = TAG_LARGE;
			}
		} else tag_invalida(const_pool,i,tag);
	}
}

cp_info *carregar_constant_pool(u2 constant_pool_count, FILE *pt_arquivo) {
	  cp_info *const_pool = (cp_info*)malloc(sizeof(cp_info)*constant_pool_count);
	  if (const_pool==NULL) return NULL;

	  criar_constant_pool(pt_arquivo,const_pool,constant_pool_count);

	  return const_pool;
}

void desalocar_constant_pool(cp_info *constant_pool, u2 constant_pool_count){
	if(constant_pool != NULL){
		u2 i = 0; // índice para o for
		// Percorre toda constant pool em busca de estruturas internas alocadas
		for(i = 0; i < constant_pool_count; i++){
			// Caso seja uma string, libera a string
			if((constant_pool + i)->tag == TAG_UTF8){
				free((constant_pool + i)->info.utf8_info.bytes);
			}
		}

		// Libera a constant pool
		free(constant_pool);
	}
}
