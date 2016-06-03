#include "exibidor_atributos.h"

void exibir_generic_info(attribute_info atributo) {
	//passa as informações do atributo para novas variáveis
	u2 attribute_name_index = atributo.attribute_name_index;
	u4 attribute_length = atributo.attribute_length;

	//exibe as informações genéricas
	fprintf(arquivo_saida, "\n\tGeneric Info: ");
	fprintf(arquivo_saida, "\n\tAttribute Name Index: cp_info #%d",attribute_name_index);
	fprintf(arquivo_saida, "\n\tAttribute Length: %d",attribute_length);

}

void exibir_constant_value_index(attribute_info atributo) {
	//passa as informações do atributo para novas variáveis
	u2 attribute_constant_value_index = atributo.info.constant_value_info.constant_value_index;

	//exibe as informações do constant value
	fprintf(arquivo_saida, "\n\tConstant Value Index: %d",attribute_constant_value_index);

}

void exibir_code_attribute_misc(attribute_info atributo) {
	//passa o atributo o para uma nova variável
	code_attribute code_info = atributo.info.code_info;

	//passa as informações do atributo para novas variáveis
	u2 max_stack = code_info.max_stack;
	u2 max_locals = code_info.max_locals;
	u4 code_length = code_info.code_length;

	fprintf(arquivo_saida, "\n\t# Misc");
	//exibe as informaões recuperadas
	fprintf(arquivo_saida, "\n\tMaximum Stack Depth: %d",max_stack);
	fprintf(arquivo_saida, "\n\tMaximum Local Variables: %d",max_locals);
	fprintf(arquivo_saida, "\n\tCode Length: %d\n",code_length);

}

u2 operando_u2 (u1 code[], u4 index){
	return ((code[index]<<8)|code[index+1]);
}

u4 operando_u4 (u1 code[], u4 index) {
	u2 code_u2 = ((code[index]<<8)|code[index+1]);
	return ((code_u2<<24)|(code[index+2]<<8)|(code[index+3]));
}

char *recupera_operando(cp_info constant_pool[], u1 tipo_operando, u1 tamanho_operando, u1 code[], u4 index) {
	char *operando=NULL;
	char *elemento_constant_pool;

	operando = (char*)malloc(sizeof(char)*TAM_OPERANDO);
	
	if(tamanho_operando==1) {
		u1 code_u1 = code[index];
		switch(tipo_operando) {
			case CP1: {
				elemento_constant_pool = recupera_elemento_como_string_constant_pool(constant_pool,code_u1);
				sprintf(operando,"#%d <%s>",code_u1,elemento_constant_pool); 
				
				free(elemento_constant_pool);
				break;
			}
			case LV1: sprintf(operando,"%d",code_u1); break;
			case INT1: sprintf(operando,"%d",(signed char)code_u1); break;
			
			//TODO case FLAG1: return 1; break;
		}
	} else if(tamanho_operando==2) {
		u2 code_u2 = operando_u2(code,index);
		switch(tipo_operando) {
			case CP2: {
				elemento_constant_pool = recupera_elemento_como_string_constant_pool(constant_pool,code_u2);
				sprintf(operando,"#%d <%s>",code_u2,elemento_constant_pool); 
				
				free(elemento_constant_pool);
				break;
			}
			case INT2: sprintf(operando,"%d",(int)code_u2); break;
			
			//TODO case LV1_INT1: return 2; break;
			
			case OFFSET2: sprintf(operando,"%d",(int)code_u2); break;
		}
	} else if(tamanho_operando==4) {
		switch(tipo_operando) {
			case OFFSET4: {
				u4 code_u4 = operando_u4(code,index);
				sprintf(operando,"%d",(int)code_u4);
				break;
			}
			case CP2_INT0: {
				int count = code[index+2];
				u2 code_u2 = operando_u2(code,index);
				elemento_constant_pool = recupera_elemento_como_string_constant_pool(constant_pool,code_u2);
				sprintf(operando,"#%d <%s> count %d",code_u2,elemento_constant_pool,count); 
				
				free(elemento_constant_pool);
				break;
			}
			//TODO: CP2_INT1
			
			default: sprintf(operando," ");
		}
	} else {
		//TODO switchtable e lookuptable
	}

	return operando;
}

void exibir_code_attribute_bytecode(attribute_info atributo, cp_info constant_pool[]) {
	//recupera vetor de instrucoes
	t_instrucoes *instrucoes = vetorMnemonicos();
	code_attribute code_info = atributo.info.code_info;
	u4 code_length = code_info.code_length;
	u1 *code = code_info.code;
	u1 tamanho_operando;
	char *operando;
	u4 i;

	fprintf(arquivo_saida, "\n\t# Bytecode: ");
	for(i=0; i<code_length; i++) {
		fprintf(arquivo_saida, "\n\t\t%d %s",i,instrucoes[code[i]].nome);
		
		//recupera tamanho do operando
		tamanho_operando = acha_tamanho_operando(instrucoes[code[i]].operando);
		
		if (tamanho_operando>0) {

			//recupera operando de acordo com o seu tipo
			operando = recupera_operando(constant_pool,instrucoes[code[i]].operando,tamanho_operando,code,i+1);
			fprintf(arquivo_saida, ": %s",operando);
			free(operando);
		}
		i += tamanho_operando;
	}

	free(instrucoes);
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

	fprintf(arquivo_saida, "\n\t# Exception Table Length: %d",exception_table_length);

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
		fprintf(arquivo_saida, "\n\tNr.: %d   ",i);
		fprintf(arquivo_saida, "start pc: %d  ",start_pc);
		fprintf(arquivo_saida, "end pc: %d  ",end_pc);
		fprintf(arquivo_saida, "handler pc: %d  ",handler_pc);
		fprintf(arquivo_saida, "catch type: cp_info #%d  ",catch_type);
		fprintf(arquivo_saida, "verbose: %s",recupera_class_name(constant_pool,catch_type));

	}
}

void exibir_exception_attribute_table(attribute_info atributo, cp_info constant_pool[]) {
	exceptions_attribute exception_info = atributo.info.exception_info;
	u2 number_of_exceptions = exception_info.number_of_exceptions;
	u2 *exception_table_index;
	u2 i;


	fprintf(arquivo_saida, "\n\t\tNumber of Exceptions: %d",number_of_exceptions);

	exception_table_index = exception_info.exceptions_index_table;

	//imprime os indíces de exception_table[]
	for(i=0; i<number_of_exceptions; i++) {
		//exibe as informações recuperadas
		fprintf(arquivo_saida, "\n\t\tException Table Index[%d] = %d ",i,exception_table_index[i]);
	}

}

void exibir_inner_classes_attribute_table(attribute_info atributo, cp_info constant_pool[]) {
	inner_classes_attribute inner_classes_info = atributo.info.inner_classes_info;
	u2 number_of_inner_classes = inner_classes_info.number_of_classes;
	inner_classes_table *classes;
	u2 i;


	fprintf(arquivo_saida, "\n\tNumber of Inner Classes: %d",number_of_inner_classes);

	classes = inner_classes_info.classes;

	fprintf(arquivo_saida, "\t\tClasses:\n");

	//imprime os indeices de exception_table[]
	for(i=0; i<number_of_inner_classes; i++) {
		//exibe as informações recuperadas
		fprintf(arquivo_saida, "\t\tClass %d\n", i);
		// fprintf(arquivo_saida, "\nInner_Class[%d].inner_class_info_index = %d ",i,classes[i].inner_class_info_index);
		// fprintf(arquivo_saida, "\nInner_Class[%d].outer_class_info_index = %d ",i,classes[i].outer_class_info_index);
		// fprintf(arquivo_saida, "\nInner_Class[%d].inner_name_index = %s ",i,recupera_string(constant_pool,classes[i].inner_name_index));
		// fprintf(arquivo_saida, "\nInner_Class[%d].inner_class_access_flag = %d ",i,classes[i].inner_class_access_flags);

		fprintf(arquivo_saida, "\n\t\tinner_class_info_index: %d ",classes[i].inner_class_info_index);
		fprintf(arquivo_saida, "\n\t\touter_class_info_index: %d ",classes[i].outer_class_info_index);
		fprintf(arquivo_saida, "\n\t\tinner_name_index: %s ",recupera_utf8(constant_pool,classes[i].inner_name_index));
		fprintf(arquivo_saida, "\n\t\tinner_class_access_flags: %d ",classes[i].inner_class_access_flags);
	}
}

void exibir_source_file(attribute_info atributo, cp_info constant_pool[]){
	char *source_file = recupera_utf8(constant_pool,atributo.attribute_name_index+1);
  
	fprintf(arquivo_saida, "\n\tSource File: %s",source_file);
	
	free(source_file);
}

void exibir_code_attribute(attribute_info atributo, cp_info constant_pool[]) {
	fprintf(arquivo_saida, "\n\n\t -> Code Attribute: ");
	exibir_generic_info(atributo);
	fprintf(arquivo_saida, "\n");
	exibir_code_attribute_bytecode(atributo,constant_pool);
	fprintf(arquivo_saida, "\n");
	exibir_code_attribute_exception_table(atributo,constant_pool);
	fprintf(arquivo_saida, "\n");
	exibir_code_attribute_misc(atributo);
	fprintf(arquivo_saida, "\n");
}
void exibir_exception_attribute(attribute_info atributo, cp_info constant_pool[]) {
	fprintf(arquivo_saida, "\n\t -> Exception Attribute: ");
	exibir_generic_info(atributo);
	exibir_exception_attribute_table(atributo,constant_pool);
}

void exibir_inner_classes_attribute(attribute_info atributo, cp_info constant_pool[]){
	fprintf(arquivo_saida, "\n\t -> Inner Class Attribute: ");
	exibir_generic_info(atributo);
	exibir_inner_classes_attribute_table(atributo,constant_pool);
}

void exibir_source_file_attribute(attribute_info atributo, cp_info constant_pool[]){
	fprintf(arquivo_saida, "\n\t -> Source File Attribute: ");
	exibir_generic_info(atributo);
	exibir_source_file(atributo,constant_pool);
}

void exibir_constant_attribute(attribute_info atributo,  cp_info constant_pool[]){
	fprintf(arquivo_saida, "\n\t -> Constant Attribute: ");
	exibir_generic_info(atributo);
	exibir_constant_value_index(atributo);
}
