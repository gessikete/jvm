#include "constant_pool.h"

void inicializar_vetor_funcoes(void (*funcoes_constant[]) (FILE*,cp_info[],u2)) {
	funcoes_constant[0] = NULL;
	funcoes_constant[1] = criar_utf8_info;
	funcoes_constant[2] = NULL;
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

void criar_class_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	constant_class_info class_info;
	u1 tag=0x07;
	u2 name_index = ler_u2(pt_arquivo);

	class_info.tag = tag;
	class_info.name_index = name_index;

	const_pool[index].tag = tag;
	const_pool[index].info.class_info = class_info;
}


void criar_fieldref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	constant_fieldref_info fieldref_info;
	u1 tag=0x09;
	u2 class_index=ler_u2(pt_arquivo);
	u2 name_and_type_index=ler_u2(pt_arquivo);

	fieldref_info.tag = tag;
	fieldref_info.class_index = class_index;
	fieldref_info.name_and_type_index = name_and_type_index;

	const_pool[index].tag = tag;
	const_pool[index].info.fieldref_info = fieldref_info;

}


void criar_utf8_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	constant_utf8_info utf8_info;
	u1 tag=0x01;
	int i;
	u2 length=ler_u2(pt_arquivo);

	utf8_info.tag = tag;
	utf8_info.length = length;
	utf8_info.bytes = (u1*)malloc(sizeof(u1)*length);
	for(i=0; i<length; i++) {
		utf8_info.bytes[i] = ler_u1(pt_arquivo);
	}

	const_pool[index].tag = tag;
	const_pool[index].info.utf8_info = utf8_info;
}


void criar_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	u1 tag=0x0A;
	u2 class_index = ler_u2(pt_arquivo);
	u2 name_and_type_index = ler_u2(pt_arquivo);
	constant_methodref_info methodref_info;

	methodref_info.tag = tag;
	methodref_info.class_index = class_index;
	methodref_info.name_and_type_index = name_and_type_index;

	const_pool[index].tag = tag;
	const_pool[index].info.methodref_info = methodref_info;
}


void criar_string_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	u1 tag = 0x08;
	u2 string_index = ler_u2(pt_arquivo);
	constant_string_info string_info;

	string_info.tag = tag;
	string_info.string_index = string_index;

	const_pool[index].tag = tag;
	const_pool[index].info.string_info = string_info;

}


void criar_interface_methodref_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	u1 tag = 0x0B;
	constant_interface_methodref_info interface_methodref_info;
	u2 class_index = ler_u2(pt_arquivo);
	u2 name_and_type_index = ler_u2(pt_arquivo);

	interface_methodref_info.tag = tag;
	interface_methodref_info.class_index = class_index;
	interface_methodref_info.name_and_type_index = name_and_type_index;

	const_pool[index].tag = tag;
	const_pool[index].info.interface_methodref_info = interface_methodref_info;
}


void criar_integer_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	u1 tag = 0x03;
	u4 bytes = ler_u4(pt_arquivo);
	constant_integer_info integer_info;

	integer_info.tag = tag;
	integer_info.bytes = bytes;


	const_pool[index].tag = tag;
	const_pool[index].info.integer_info = integer_info;
}


void criar_float_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	u1 tag = 0x04;
	u4 bytes = ler_u4(pt_arquivo);
	constant_float_info float_info;

	float_info.tag = tag;
	float_info.bytes = bytes;

	const_pool[index].tag = tag;
	const_pool[index].info.float_info = float_info;

}


void criar_long_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	u1 tag = 0x05;
	constant_long_info long_info;
	u8 bytes = ler_u8(pt_arquivo);


	long_info.tag = tag;
	long_info.bytes = bytes;

	const_pool[index].tag = tag;
	const_pool[index].info.long_info = long_info;

}


void criar_double_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	u1 tag = 0x06;
	constant_double_info double_info;
	u8 bytes = ler_u8(pt_arquivo);

	double_info.tag = tag;
	double_info.bytes = bytes;

	const_pool[index].tag = tag;
	const_pool[index].info.double_info = double_info;

}


void criar_name_and_type_info(FILE *pt_arquivo, cp_info const_pool[], u2 index) {
	u1 tag = 0x0C;
	constant_name_and_type_info name_and_type_info;
	u2 name_index = ler_u2(pt_arquivo);
	u2 descriptor_index = ler_u2(pt_arquivo);

	name_and_type_info.tag = tag;
	name_and_type_info.name_index = name_index;
	name_and_type_info.descriptor_index = descriptor_index;

	const_pool[index].tag = tag;
	const_pool[index].info.name_and_type_info = name_and_type_info;

}

void tag_invalida(cp_info const_pool[], u2 index, u2 tag) {
	const_pool[index].tag = tag;
}

void criar_constant_pool(FILE *pt_arquivo, cp_info const_pool[], u2 tamanho) {
	u2 i;
	u1 tag;
	void (*funcoes_constant[13]) (FILE*,cp_info[],u2);

	//Preenche vetor de funcoes
	inicializar_vetor_funcoes(funcoes_constant);

	//Le e escreve todos os elementos da constant pool no vetor const_pool
	for(i=0; i<tamanho; i++) {
		//Le a tag
		tag = ler_u1(pt_arquivo);

		if(validar_tag(tag)) {
			//Executa funcao associada a tag. A funcao ira preencher a entrada.
			funcoes_constant[tag](pt_arquivo,const_pool,i);
		} else tag_invalida(const_pool,i,tag);
	}
}

cp_info *carregar_constant_pool(u2 constant_pool_count, FILE *pt_arquivo) {
	  cp_info *const_pool = (cp_info*)malloc(sizeof(cp_info)*constant_pool_count);

	  criar_constant_pool(pt_arquivo,const_pool,constant_pool_count-1);

	  return const_pool;
}
