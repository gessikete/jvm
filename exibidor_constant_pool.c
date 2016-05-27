#include "exibidor_constant_pool.h"

void inicializar_vetor_exibidor(void (*funcoes_constant[]) (cp_info)) {
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

void exibir_elemento_constant_pool(cp_info const_pool) {
	void (*funcoes_constant[13]) (cp_info);

	inicializar_vetor_exibidor(funcoes_constant);

	if(validar_tag(const_pool.tag)) {
		funcoes_constant[const_pool.tag](const_pool);
	}
}

void exibir_constant_pool(cp_info *const_pool, u2 constant_pool_count) {
	u2 i;

	for(i=0; i<constant_pool_count-1; i++) {
		printf("\n-----------------\n");
		printf("\nIndice: %d",i+1);
		exibir_elemento_constant_pool(const_pool[i]);
	}
	printf("\n\n\n");
}

void exibir_methodref_info(cp_info const_pool) {
	printf("\ntag: %d",const_pool.info.methodref_info.tag);
	printf("\nclass index: %d",const_pool.info.methodref_info.class_index);
	printf("\nname and type index: %d\n",const_pool.info.methodref_info.name_and_type_index);
}

void exibir_class_info(cp_info const_pool) {
	printf("\ntag: %d",const_pool.info.class_info.tag);
	printf("\nname index: %d\n",const_pool.info.class_info.name_index);
}


void exibir_fieldref_info(cp_info const_pool) {
	printf("\ntag: %d",const_pool.info.fieldref_info.tag);
	printf("\nclass index: %d",const_pool.info.fieldref_info.class_index);
	printf("\nname and type index: %d\n",const_pool.info.fieldref_info.name_and_type_index);
}


void exibir_utf8_info(cp_info const_pool) {
	int i;
	u2 length = const_pool.info.utf8_info.length;
	char string[length+1];

	printf("\ntag: %d",const_pool.info.utf8_info.tag);
	printf("\nlength: %d",length);

	printf("\nbytes: ");

	//Copia os bytes para a string
	for(i=0; i<const_pool.info.utf8_info.length; i++) {
		string[i]=const_pool.info.utf8_info.bytes[i];
	}
	string[i] = '\0';
	printf("%s\n",string);
}

void exibir_integer_info(cp_info const_pool) {
	int i;

	//Transforma unsigned int para int
	memcpy(&i,&const_pool.info.integer_info.bytes,sizeof i);

	printf("\ntag: %d",const_pool.info.integer_info.tag);
	printf("\nbytes: %d\n",i);
}

void exibir_name_and_type_info(cp_info const_pool) {
	printf("\ntag: %d",const_pool.info.name_and_type_info.tag);
	printf("\nname index: %d",const_pool.info.name_and_type_info.name_index);
	printf("\ndescriptor index: %d",const_pool.info.name_and_type_info.descriptor_index);

}

void exibir_float_info(cp_info const_pool) {
	float f;

	//copia os bytes para f, transformando-os em um float
	memcpy(&f,&const_pool.info.float_info.bytes,sizeof f);

	printf("\ntag: %d",const_pool.info.float_info.tag);
	printf("\nbytes: %f\n",f);

}

void exibir_string_info(cp_info const_pool) {

	printf("\ntag: %d",const_pool.info.string_info.tag);
	printf("\nstring index: %d",const_pool.info.string_info.string_index);

}

void exibir_long_info(cp_info const_pool) {
	long l;

	//transforma u8 em long
	memcpy(&l,&const_pool.info.long_info.bytes,sizeof l);

	printf("\ntag: %d",const_pool.info.long_info.tag);
	printf("\nbytes: %li",l);

}

void exibir_double_info(cp_info const_pool) {
	double d;

	//transforma u8 em double
	memcpy(&d,&const_pool.info.double_info.bytes,sizeof d);

	printf("\ntag: %d",const_pool.info.double_info.tag);
	printf("\nbytes: %f",d);
}

void exibir_interface_methodref_info(cp_info const_pool) {
	printf("\ntag: %d",const_pool.info.interface_methodref_info.tag);
	printf("\nclass index: %d",const_pool.info.interface_methodref_info.class_index);
	printf("\nname and type index: %d",const_pool.info.interface_methodref_info.name_and_type_index);
}
