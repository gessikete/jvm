#include "exibidor_constant_pool.h"
#include "recuperar_constant_pool.h"
#include <string.h>

void inicializar_vetor_exibidor(void (*funcoes_constant[]) (cp_info*,u2)) {
	funcoes_constant[0] = NULL;
	funcoes_constant[1] = exibir_utf8_info;
	funcoes_constant[2] = NULL;
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
		printf("\n-----------------\n");
		exibir_elemento_constant_pool(const_pool,i);
	}
	printf("\n\n\n");
}

void exibir_large_numeric(u2 index) {
	printf("\n[%d] (Large Numeric Continued)\n",index);
}

void exibir_methodref_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u2 class_index = const_pool.info.methodref_info.class_index;
	u2 name_and_type_index = const_pool.info.methodref_info.name_and_type_index;
	
	printf("\n[%d] CONSTANT_Methodref_info",index);
	printf("\nTag: %d",tag);
	printf("\nClass Name: cp_info #%d <%s>",class_index,recupera_class_name(pt_const_pool,class_index));
	printf("\nName and Type: cp_info #%d <%s>\n",name_and_type_index,recupera_name_and_type_name(pt_const_pool,name_and_type_index));
}

void exibir_class_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u2 name_index = const_pool.info.class_info.name_index;
  
	printf("\n[%d] CONSTANT_Class_info",index);
	printf("\nTag: %d",tag);
	printf("\nClass Name: cp_info #%d <%s>\n",name_index,recupera_class_name(pt_const_pool,index));
}


void exibir_fieldref_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u2 class_index = const_pool.info.fieldref_info.class_index;
	u2 name_and_type_index = const_pool.info.fieldref_info.name_and_type_index;
  
	printf("\n[%d] CONSTANT_Fieldref_info",index);
	printf("\nTag: %d",tag);
	printf("\nClass Name: cp_info #%d <%s>",class_index,recupera_class_name(pt_const_pool,class_index));
	printf("\nName and Type: cp_info #%d <%s>\n",name_and_type_index,recupera_name_and_type_name(pt_const_pool,name_and_type_index));
}

void exibir_utf8_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 length = const_pool.info.utf8_info.length;
	u2 tag = const_pool.tag;
	char string[length+1];

	printf("\n[%d] CONSTANT_Utf8_info",index);
	printf("\nTag: %d",tag);
	printf("\nLength: %d",length);

	printf("\nString: ");

	//Transforma os bytes em string
	recupera_utf8(string,length,const_pool.info.utf8_info);
	printf("%s\n",string);
}

void exibir_integer_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u4 bytes = const_pool.info.integer_info.bytes;
	int i;

	//Transforma unsigned int para int
	memcpy(&i,&bytes,sizeof i);

	printf("\n[%d] CONSTANT_Integer_info",index);
	printf("\nTag: %d",tag);
	printf("\nBytes: 0x%.8x",bytes);
	printf("\nInteger: %d",i);
}

void exibir_name_and_type_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u2 name_index = const_pool.info.name_and_type_info.name_index;
	u2 descriptor_index = const_pool.info.name_and_type_info.descriptor_index;
  
	printf("\n[%d] CONSTANT_NameAndType_info",index);
	printf("\nTag: %d",tag);
	printf("\nName: cp_info #%d <%s>",name_index,recupera_string(pt_const_pool,name_index));
	printf("\nDescriptor: cp_info #%d <%s>",descriptor_index,recupera_string(pt_const_pool,descriptor_index));

}

void exibir_float_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u4 bytes = const_pool.info.float_info.bytes;
	float f;

	
	//copia os bytes para f, transformando-os em um float
	memcpy(&f,&bytes,sizeof f);

	printf("\n[%d] CONSTANT_Float_info",index);
	printf("\nTag: %d",tag);
	printf("\nBytes: 0x%.8x",bytes);
	printf("\nFloat: %f",f);

}

void exibir_string_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u2 string_index = const_pool.info.string_info.string_index;

	printf("\n[%d] CONSTANT_String_info",index);
	printf("\nTag: %d",tag);
	printf("\nString: cp_info #%d <%s>",string_index,recupera_string(pt_const_pool,string_index));

}

void exibir_long_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u8 bytes = const_pool.info.long_info.bytes;
	u2 tag = const_pool.tag;
	long l;

	//transforma u8 em long
	memcpy(&l,&bytes,sizeof l);

	printf("\n[%d] CONSTANT_Long_info",index);
	printf("\nTag: %d",tag);
	printf("\nHigh Bytes: 0x%.8x",recupera_high_bytes(bytes));
	printf("\nLow Bytes: 0x%.8x",recupera_low_bytes(bytes));
	printf("\nLong: %li",l);

}

void exibir_double_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u8 bytes = const_pool.info.double_info.bytes;
	double d;

	//transforma u8 em double
	memcpy(&d,&bytes,sizeof d);

	printf("\n[%d] CONSTANT_Double_info",index);
	printf("\nTag: %d",tag);
	printf("\nHigh Bytes: 0x%.8x",recupera_high_bytes(bytes));
	printf("\nLow Bytes: 0x%.8x",recupera_low_bytes(bytes));
	printf("\nDouble: %f",d);
}

void exibir_interface_methodref_info(cp_info *pt_const_pool, u2 index) {
	cp_info const_pool = pt_const_pool[index];
	u2 tag = const_pool.tag;
	u2 class_index = const_pool.info.interface_methodref_info.class_index;
	u2 name_and_type_index = const_pool.info.interface_methodref_info.name_and_type_index;
  
	printf("\n[%d] CONSTANT_Interface_Methodref_info",index);
	printf("\nTag: %d",tag);
	printf("\nClass Name: cp_info #%d <%s>",class_index,recupera_class_name(pt_const_pool,class_index));
	printf("\nName and Type: cp_info #%d <%s>\n",name_and_type_index,recupera_name_and_type_name(pt_const_pool,name_and_type_index));
}