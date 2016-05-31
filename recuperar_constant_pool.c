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


u4 recupera_int(cp_info *pt_const_pool, u2 int_index){
	//recupera valor de int armazenado na constant pool
	constant_integer_info integer = pt_const_pool[int_index].info.integer_info;

	return (u4) integer.bytes;
}

u4 recupera_float(cp_info *pt_const_pool, u2 float_index){
	//recupera valor de float na constant pool
	constant_float_info float_const = pt_const_pool[float_index].info.float_info;

	return (u4) float_const.bytes;
}

u8 recupera_long(cp_info *pt_const_pool, u2 long_index){
	//recupera valor long na constant pool
	constant_long_info long_const = pt_const_pool[long_index].info.long_info;

	return (u8)long_const.bytes;
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
	  
	}
	return NULL;
}
