/*!
   \file exibidor_constant_pool.c
   \brief Implementação das funções de manipulação da exibição da constant_pool.

   Esse arquivo contém a implementação das funções que manipulam a exibição da
   constant_pool.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "exibidor_constant_pool.h"

void inicializar_vetor_exibidor(void (*funcoes_constant[]) (cp_info*,u2)) {
	funcoes_constant[1] = exibir_utf8_info;
	funcoes_constant[3] = exibir_integer_info;
	funcoes_constant[4] = exibir_float_info;
	funcoes_constant[5] = exibir_long_info;
	funcoes_constant[6] = exibir_double_info;
	funcoes_constant[7] = exibir_class_info;
	funcoes_constant[8] = exibir_string_info;
	funcoes_constant[9] = exibir_fieldref_info;
	funcoes_constant[10] = exibir_methodref_info;
	funcoes_constant[11] = exibir_interface_methodref_info;
	funcoes_constant[12] = exibir_name_and_type_info;
}

void exibir_elemento_constant_pool(cp_info *pt_const_pool, u2 index) {
	void (*funcoes_constant[13]) (cp_info*,u2);
	cp_info const_pool = pt_const_pool[index];

	inicializar_vetor_exibidor(funcoes_constant);

	if(validar_tag(const_pool.tag)) {
		funcoes_constant[const_pool.tag](pt_const_pool,index);
	} else if(const_pool.tag==TAG_LARGE) exibir_large_numeric(index);
}

void exibir_constant_pool(cp_info *const_pool, u2 constant_pool_count) {
	u2 i;

	for(i=1; i<constant_pool_count; i++) {
		//fprintf(arquivo_saida, "\n-----------------\n");
		exibir_elemento_constant_pool(const_pool,i);
		//fprintf(arquivo_saida, "\n");
	}
	fprintf(arquivo_saida, "\n\n\n");
}

void exibir_large_numeric(u2 index) {
	fprintf(arquivo_saida, "\n[%d] (Large Numeric Continued)",index);
}

void exibir_methodref_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 class_index = const_pool.info.methodref_info.class_index;
	u2 name_and_type_index = const_pool.info.methodref_info.name_and_type_index;
	char *name_and_type = recupera_name_and_type(pt_const_pool,name_and_type_index);
	char *class_name = recupera_class_name(pt_const_pool,class_index);

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Methodref_info",index);
	fprintf(arquivo_saida, "\n\tClass Name: cp_info #%d <%s>",class_index,class_name);
	fprintf(arquivo_saida, "\n\tName and Type: cp_info #%d <%s>",name_and_type_index,name_and_type);

	free(name_and_type);
	free(class_name);
}

void exibir_class_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 name_index = const_pool.info.class_info.name_index;
	char *class_name = recupera_class_name(pt_const_pool,index);

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Class_info",index);
	fprintf(arquivo_saida, "\n\tClass Name: cp_info #%d <%s>",name_index,class_name);

	free(class_name);
}


void exibir_fieldref_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 class_index = const_pool.info.fieldref_info.class_index;
	u2 name_and_type_index = const_pool.info.fieldref_info.name_and_type_index;
	char *name_and_type = recupera_name_and_type(pt_const_pool,name_and_type_index);
	char *class_name = recupera_class_name(pt_const_pool,class_index);

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Fieldref_info",index);
	fprintf(arquivo_saida, "\n\tClass Name: cp_info #%d <%s>",class_index,class_name);
	fprintf(arquivo_saida, "\n\tName and Type: cp_info #%d <%s>",name_and_type_index,name_and_type);

	free(class_name);
	free(name_and_type);
}

void exibir_utf8_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 length = const_pool.info.utf8_info.length;
	char *string = recupera_utf8(pt_const_pool,index);

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Utf8_info",index);
	fprintf(arquivo_saida, "\n\tLength: %d",length);
	fprintf(arquivo_saida, "\n\tString: %s",string);

	free(string);
}

void exibir_integer_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u4 bytes = const_pool.info.integer_info.bytes;

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Integer_info",index);
	fprintf(arquivo_saida, "\n\tBytes: 0x%.8x",bytes);
	fprintf(arquivo_saida, "\n\tInteger: %d",recupera_int(pt_const_pool,index));
}

void exibir_name_and_type_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 name_index = const_pool.info.name_and_type_info.name_index;
	u2 descriptor_index = const_pool.info.name_and_type_info.descriptor_index;
	char *name = recupera_utf8(pt_const_pool,name_index);
	char *descriptor = recupera_utf8(pt_const_pool,descriptor_index);

	fprintf(arquivo_saida, "\n[%d] CONSTANT_NameAndType_info",index);
	fprintf(arquivo_saida, "\n\tName: cp_info #%d <%s>",name_index,name);
	fprintf(arquivo_saida, "\n\tDescriptor: cp_info #%d <%s>",descriptor_index,descriptor);

	free(name);
	free(descriptor);
}

void exibir_float_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u4 bytes = const_pool.info.float_info.bytes;

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Float_info",index);
	fprintf(arquivo_saida, "\n\tBytes: 0x%.8x",bytes);
	fprintf(arquivo_saida, "\n\tFloat: %f",recupera_float(pt_const_pool,index));

}

void exibir_string_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 string_index = const_pool.info.string_info.string_index;
	char *string = recupera_utf8(pt_const_pool,string_index);

	fprintf(arquivo_saida, "\n[%d] CONSTANT_String_info",index);
	fprintf(arquivo_saida, "\n\tString: cp_info #%d <%s>",string_index,string);

	free(string);
}

void exibir_long_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u8 bytes = const_pool.info.long_info.bytes;

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Long_info",index);
	fprintf(arquivo_saida, "\n\tHigh Bytes: 0x%.8x",recupera_high_bytes(bytes));
	fprintf(arquivo_saida, "\n\tLow Bytes: 0x%.8x",recupera_low_bytes(bytes));
	fprintf(arquivo_saida, "\n\tLong: %li",recupera_long(pt_const_pool,index));

}

void exibir_double_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u8 bytes = const_pool.info.double_info.bytes;

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Double_info",index);
	fprintf(arquivo_saida, "\n\tHigh Bytes: 0x%.8x",recupera_high_bytes(bytes));
	fprintf(arquivo_saida, "\n\tLow Bytes: 0x%.8x",recupera_low_bytes(bytes));
	fprintf(arquivo_saida, "\n\tDouble: %f",recupera_double(pt_const_pool,index));
}

void exibir_interface_methodref_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 class_index = const_pool.info.interface_methodref_info.class_index;
	u2 name_and_type_index = const_pool.info.interface_methodref_info.name_and_type_index;
	char *class_name = recupera_class_name(pt_const_pool,class_index);
	char *name_and_type = recupera_name_and_type(pt_const_pool,name_and_type_index);

	fprintf(arquivo_saida, "\n[%d] CONSTANT_Interface_Methodref_info",index);
	fprintf(arquivo_saida, "\n\tClass Name: cp_info #%d <%s>",class_index,class_name);
	fprintf(arquivo_saida, "\n\tName and Type: cp_info #%d <%s>",name_and_type_index,name_and_type);

	free(class_name);
	free(name_and_type);
}
