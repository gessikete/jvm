#include "exibidor_atributos.h"
#include "leitor_atributos.h"
#include "recuperar_constant_pool.h"


void exibir_generic_info(attribute_info atributo) {
	//passa as informações do atributo para novas variáveis
	u2 attribute_name_index = atributo.attribute_name_index;
	u4 attribute_length = atributo.attribute_length;
  
	//exibe as informações genéricas
	printf("\nGeneric Info: ");
	printf("\nAttribute Name Index: cp_info #%d",attribute_name_index);
	printf("\nAttribute Length: %d",attribute_length);
 
}

void exibir_code_attribute_misc(attribute_info atributo) {
	//passa o atributo o para uma nova variável
	code_attribute code_info = atributo.info.code_info;
	
	//passa as informações do atributo para novas variáveis
	u2 max_stack = code_info.max_stack;
	u2 max_locals = code_info.max_locals;
	u4 code_length = code_info.code_length;
	
	//exibe as informaões recuperadas
	printf("\nMaximum Stack Depth: %d",max_stack);
	printf("\nMaximum Local Variables: %d",max_locals);
	printf("\nCode Length: %d\n",code_length);
 
}

void exibir_code_attribute_bytecode(attribute_info atributo, cp_info constant_pool[]) {
	code_attribute code_info = atributo.info.code_info;
	u4 code_length = code_info.code_length;
	u4 i;
	
	printf("\nHexa: ");
	//exibe cada um dos bytes do código em hexa
	for(i=0; i<code_length; i++) {
		printf("%.2x ",code_info.code[i]);
	}
	
	//TODO: Transformar hexa em codigo
}

void exibir_code_attribute_exception_table(attribute_info atributo, cp_info constant_pool[]) {
	code_attribute code_info = atributo.info.code_info;
	u2 exception_table_length = code_info.exception_table_length;
	t_exception_table exception_table;
	u2 start_pc;
	u2 end_pc;
	u2 handler_pc;
	u2 catch_type;
	u2 i;
  
	printf("\nException Table Length: %d",exception_table_length);
	printf("\n-----------------------\n");
	
	//percorre as entradas de exception_table[]
	for(i=0; i<exception_table_length; i++) {
		//salva a entrada corrente em uma nova variável
		exception_table = code_info.exception_table[i];
		
		//salva as informações de da entrada corrente de exception_table
		start_pc = exception_table.start_pc;
		end_pc = exception_table.end_pc;
		handler_pc = exception_table.handler_pc;
		catch_type = exception_table.catch_type;
		
		//exibe as informações recuperadas
		printf("\nNr.: %d   ",i);
		printf("start pc: %d  ",start_pc);
		printf("end pc: %d  ",end_pc);
		printf("handler pc: %d  ",handler_pc);
		printf("catch type: cp_info #%d  ",catch_type);
		printf("verbose: %s",recupera_class_name(constant_pool,catch_type));
		
	}
	printf("\n------------------------\n");
	
}

void exibir_code_attribute(attribute_info atributo, cp_info constant_pool[]) {
	exibir_generic_info(atributo);
	exibir_code_attribute_bytecode(atributo,constant_pool);
	exibir_code_attribute_exception_table(atributo,constant_pool);
	exibir_code_attribute_misc(atributo);
}