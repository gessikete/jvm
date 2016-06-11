#include "recuperar_constant_pool.h"
#include <string.h>

char *recupera_utf8(cp_info constant_pool[], u2 index) {
	constant_utf8_info utf8_info = constant_pool[index].info.utf8_info;
	u2 length = utf8_info.length+1;
	char *string = (char*)malloc(sizeof(char)*length);
	u2 i;

	//Copia os bytes para a string
	for(i=0; i<utf8_info.length; i++) {
		string[i] = utf8_info.bytes[i];
	}
	string[i] = '\0';

	return string;
}


char *recupera_class_name(cp_info *pt_const_pool, u2 class_index) {
	//recupera entrada da classe
	constant_class_info class = pt_const_pool[class_index].info.class_info;

	char *class_name = recupera_utf8(pt_const_pool,class.name_index);

	return class_name;
}

char *recupera_name_and_type(cp_info *pt_const_pool, u2 index) {
	//recupera entrada de name and type
	constant_name_and_type_info name_and_type_info = pt_const_pool[index].info.name_and_type_info;

	//recupera entrada do nome da classe
	constant_utf8_info name_utf8_info = pt_const_pool[name_and_type_info.name_index].info.utf8_info;

	//recupera entrada do descritor
	constant_utf8_info descriptor_utf8_info = pt_const_pool[name_and_type_info.descriptor_index].info.utf8_info;

	// recupera tamanho do nome da classe
	u2 name_length = name_utf8_info.length;

	//recupera tamanho do descritor
	u2 descriptor_length = descriptor_utf8_info.length+1;

	//recupera o nome
	char *name = recupera_utf8(pt_const_pool,name_and_type_info.name_index);

	//recupera o descritor
	char *descriptor = recupera_utf8(pt_const_pool,name_and_type_info.descriptor_index);

	//aloca espaço para a string final
	char *name_and_type = (char*)malloc(sizeof(char)*(name_length+descriptor_length+1));

	// copia nome para a string final
	memcpy(name_and_type,name,(sizeof(char)*(name_length+1)));


	// concatena o nome da classe e o descritor
	strcat(name_and_type,descriptor);

	// libera as strings temporárias criadas
	free(name);
	free(descriptor);

	//retorna nome+descritor
	return name_and_type;
}

u4 recupera_high_bytes(u8 bytes) {
	return (u4) (bytes>>32);
}

u4 recupera_low_bytes(u8 bytes) {
	return (u4) bytes;
}


int recupera_int(cp_info *pt_const_pool, u2 int_index){
	//recupera valor de int armazenado na constant pool
	constant_integer_info integer = pt_const_pool[int_index].info.integer_info;
	u4 bytes = integer.bytes;
	int i;

	//Transforma unsigned int para int
	memcpy(&i,&bytes,sizeof i);


	return i;
}

float recupera_float(cp_info *pt_const_pool, u2 float_index){
	//recupera valor de float na constant pool
	constant_float_info float_const = pt_const_pool[float_index].info.float_info;
	u4 bytes = float_const.bytes;
	float f;

	//copia os bytes para f, transformando-os em um float
	memcpy(&f,&bytes,sizeof f);

	return f;
}

double recupera_double(cp_info *pt_const_pool, u2 index) {
	//recupera valor de double na constant pool
	constant_double_info double_const = pt_const_pool[index].info.double_info;
	u8 bytes = double_const.bytes;
	double d;

	//transforma u8 em double
	memcpy(&d,&bytes,sizeof d);

	return d;
}

long recupera_long(cp_info *pt_const_pool, u2 long_index){
	//recupera valor long na constant pool
	constant_long_info long_const = pt_const_pool[long_index].info.long_info;
	u8 bytes = long_const.bytes;
	long l;

	//transforma u8 em long
	memcpy(&l,&bytes,sizeof l);

	return l;
}

char *recupera_name_and_type_name(cp_info *pt_const_pool, u2 index) {
	//recupera entrada de name and type
	constant_name_and_type_info name_and_type_info = pt_const_pool[index].info.name_and_type_info;
	char *name = recupera_utf8(pt_const_pool,name_and_type_info.name_index);

	return name;
}

char *recupera_elemento_como_string_constant_pool(cp_info *pt_const_pool, u2 index) {
	u2 tag = pt_const_pool[index].tag;
	char *string=NULL;

	//Cópia para receber os ponteiros das funções de recuperação que retornam strings
	//(necessária para realizar liberação de memória)
	char *copia=NULL;

	string = (char*) malloc(sizeof(char)*TAM_STRING);

	if((tag<9)||(tag==12)) {
		switch(tag) {
			case 1: string = recupera_utf8(pt_const_pool,index); break;
			case 3: sprintf(string,"%d",recupera_int(pt_const_pool,index)); break;
			case 4: sprintf(string,"%f",recupera_float(pt_const_pool,index)); break;
			case 5: sprintf(string,"%li",recupera_long(pt_const_pool,index)); break;
			case 6: sprintf(string,"%F",recupera_double(pt_const_pool,index)); break;
			case 7: {
				copia = recupera_class_name(pt_const_pool,index);
				strcpy(string,copia);
				free(copia);
				break;
			}
			case 8: string = recupera_utf8(pt_const_pool,pt_const_pool[index].info.string_info.string_index); break;
			default: sprintf(string," "); //TODO: descobrir se existe caso tag=12

		}
	} else {
		//casos: fieldref, methodref e interface_methodref
		char *name = recupera_name_and_type_name(pt_const_pool,pt_const_pool[index].info.methodref_info.name_and_type_index);
		copia = recupera_class_name(pt_const_pool,pt_const_pool[index].info.methodref_info.class_index);
		strcpy(string,copia);
		strcat(string,".");
		strcat(string,name);
		free(name);
		free(copia);
		copia=NULL;
	}

	return string;
}
