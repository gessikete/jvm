#include "exibidor_classe.h"


void exibir_classe(class_file* cp){

	/* Exibir na Tela */
	fprintf(arquivo_saida, "Magic Number: %08x\n", cp->magic);
	fprintf(arquivo_saida, "Minor Version: %d\n", cp->minor_version);
	fprintf(arquivo_saida, "Major Version: %d\n", cp->major_version);
	fprintf(arquivo_saida, "Constant Pool Count: %d\n", cp->constant_pool_count);
	//Constant Pool
	exibir_constant_pool(cp->constant_pool, cp->constant_pool_count);

	fprintf(arquivo_saida, "Access Flag: %04x\n", cp->access_flags);
	fprintf(arquivo_saida, "This Class: %04x\n", cp->this_class);
	fprintf(arquivo_saida, "Super Class: %04x\n", cp->super_class);

	//Interface
	fprintf(arquivo_saida, "Interface Count: %d\n", cp->interfaces_count);

	exibir_interfaces(cp->interfaces, cp->interfaces_count, cp->constant_pool);

	//Fields
	fprintf(arquivo_saida, "Fields Count: %d\n", cp->fields_count);

	exibir_fields(cp->fields, cp->fields_count, cp->constant_pool);

	//Methods
	fprintf(arquivo_saida, "Methods Count: %d\n", cp->methods_count);

	exibir_methods(cp->methods, cp->methods_count, cp->constant_pool);

	//Attributes
	fprintf(arquivo_saida, "Attributes Count: %d\n", cp->attributes_count);

	u2 i = 0;
	while(i < cp->attributes_count){
		char *nome_atributo = recupera_string(cp->constant_pool,cp->attributes[i].attribute_name_index);

		if(nome_atributo) {
			//comparar a string recuperada com os nomes de atributos e retornar a função que trata do atributo encontrado
			if(strcmp(nome_atributo,CONST_VALUE)==0) exibir_constant_attribute(cp->attributes[i],cp->constant_pool);
			if(strcmp(nome_atributo,CODE)==0) exibir_code_attribute(cp->attributes[i],cp->constant_pool);
			if(strcmp(nome_atributo,EXCEPTION)==0) exibir_exception_attribute(cp->attributes[i],cp->constant_pool);
			if(strcmp(nome_atributo,INNER_CLASSES)==0) exibir_inner_classes_attribute(cp->attributes[i],cp->constant_pool);
			if(strcmp(nome_atributo,SOURCE_FILE)==0) exibir_source_file_attribute(cp->attributes[i],cp->constant_pool);
		}
		i++;
	}

	/* Exibir no Arquivo */

	fprintf(arquivo_saida, "Magic Number: %08x\n", cp->magic);
	fprintf(arquivo_saida, "Minor Version: %d\n", cp->minor_version);
	fprintf(arquivo_saida, "Major Version: %d\n", cp->major_version);
	fprintf(arquivo_saida, "Constant Pool Count: %d\n", cp->constant_pool_count);

	/* FALTA - EXIBIDOR DE CONSTANT POOL - PRINTAR NO ARQUIVO*/

	fprintf(arquivo_saida, "Access Flag: %04x\n", cp->access_flags);
	fprintf(arquivo_saida, "This Class: %04x\n", cp->this_class);
	fprintf(arquivo_saida, "Super Class: %04x\n", cp->super_class);

	fprintf(arquivo_saida, "Interface Count: %d\n", cp->interfaces_count);

	/* FALTA - EXIBIDOR DE INTERFACE - PRINTAR NO ARQUIVO*/

	fprintf(arquivo_saida, "Fields Count: %d\n", cp->fields_count);

	/* FALTA - EXIBIDOR DE FIELDS - PRINTAR NO ARQUIVO*/

	fprintf(arquivo_saida, "Methods Count: %d\n", cp->methods_count);

	/* FALTA - EXIBIDOR DE METODOS - PRINTAR NO ARQUIVO*/

	fprintf(arquivo_saida, "Attributes Count: %d\n", cp->attributes_count);
}

void exibir_interfaces(u2 *interfaces, u2 interfaces_count, cp_info *const_pool){
	u2 i;

	for(i = 0; i < interfaces_count; i++) {
		fprintf(arquivo_saida, "\n-----------------\n");
		fprintf(arquivo_saida, "\nInterface %d: cp_info #%d <%s>", i, *(interfaces + i), recupera_class_name(const_pool, *(interfaces + i)));
	}
	fprintf(arquivo_saida, "\n\n\n");
}
