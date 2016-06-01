#include "recuperar_constant_pool.h"
#include <string.h>

void recupera_utf8(char string[], u2 length, constant_utf8_info utf8_info) {
	u2 i;
  
	//Copia os bytes para a string
	for(i=0; i<utf8_info.length; i++) {
		string[i] = utf8_info.bytes[i];
	}
	string[i] = '\0';
}


char *recupera_class_name(cp_info *pt_const_pool, u2 class_index) {
	//recupera entrada da classe
	constant_class_info class = pt_const_pool[class_index].info.class_info;
	
	//recupera entrada do nome da classe
	constant_utf8_info utf8_info = pt_const_pool[class.name_index].info.utf8_info;
	
	//recupera tamanho do nome
	u2 length = utf8_info.length+1;
	char *class_name = (char*)malloc(sizeof(char)*(length));
	
	//recupera nome
	recupera_utf8(class_name,length,utf8_info);
	
	return class_name;
}

char *recupera_name_and_type_name(cp_info *pt_const_pool, u2 index) {
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
	
	// aloca tamanho para nome+descritor
	char *name_and_type = (char*)malloc(sizeof(char)*(name_length+descriptor_length+1));
	char *descriptor = (char*)malloc(sizeof(char)*(descriptor_length));
	
	// recupera o nome da classe
	recupera_utf8(name_and_type,name_length,name_utf8_info);
	recupera_utf8(descriptor,descriptor_length,descriptor_utf8_info);
	
	// concatena o nome da classe e o descritor
	strcat(name_and_type,descriptor);
	
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

char *recupera_string(cp_info *pt_const_pool, u2 string_index) {
	if(pt_const_pool[string_index].tag==0x01) {
		//recupera entrada da string
		constant_utf8_info utf8_info = pt_const_pool[string_index].info.utf8_info;
	
		//recupera tamanho do nome
		u2 length = utf8_info.length+1;
		char *string = (char*)malloc(sizeof(char)*(length));
	
		//recupera nome
		recupera_utf8(string,length,utf8_info);
	
		return string;
	  
	} else printf("\nErro! Indice nao corresponde a uma string");
	return NULL;
}

char *recupera_elemento_como_string_constant_pool(cp_info *pt_const_pool, u2 index) {
	u2 tag = pt_const_pool[index].tag;
	char *string=NULL;
	
	string = (char*) malloc(sizeof(char)*TAM_STRING);
	
	switch(tag) {
		case 1: string = recupera_string(pt_const_pool,index); break;
		case 3: sprintf(string,"%d",recupera_int(pt_const_pool,index)); break;
		case 4: sprintf(string,"%f",recupera_float(pt_const_pool,index)); break;
		case 5: sprintf(string,"%li",recupera_long(pt_const_pool,index)); break;
		case 6: sprintf(string,"%F",recupera_double(pt_const_pool,index)); break;
		//case 7: class_info
		case 8: string = recupera_string(pt_const_pool,pt_const_pool[index].info.string_info.string_index); break;
		//case 9: fieldref
		//case 10: methodref
		//case 11: interface_methodref_info
		//case 12: name_and_type 
	}
  
	return string;
}