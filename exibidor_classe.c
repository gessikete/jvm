#include "exibidor_classe.h"


void exibir_classe(class_file* cp){

	/* Exibir na Tela */
	// Informações gerais sobre a classe
	fprintf(arquivo_saida, "Magic Number: %08x\n", cp->magic);
	fprintf(arquivo_saida, "Minor version: %d\n", cp->minor_version);
	fprintf(arquivo_saida, "Major version: %d\n", cp->major_version);
	fprintf(arquivo_saida, "Constant pool count: %d\n", cp->constant_pool_count);
	exibir_access_flag(cp->access_flags);
	exibir_tipo_classe("This class", cp->this_class, cp->constant_pool);
	exibir_tipo_classe("Super class", cp->super_class, cp->constant_pool);
	fprintf(arquivo_saida, "\nInterface count: %d\n", cp->interfaces_count);
	fprintf(arquivo_saida, "Fields count: %d\n", cp->fields_count);
	fprintf(arquivo_saida, "Methods Count: %d\n", cp->methods_count);
	fprintf(arquivo_saida, "Attributes Count: %d\n", cp->attributes_count);

	//Constant Pool
	if(cp->constant_pool_count > 0){
		fprintf(arquivo_saida, "\n\n##Constant Pool##\n");
		exibir_constant_pool(cp->constant_pool, cp->constant_pool_count);
	}

	//Interface
	if(cp->interfaces_count > 0){
		fprintf(arquivo_saida, "##Interfaces##\n");
		fprintf(arquivo_saida, "Interface Count: %d\n", cp->interfaces_count);
		exibir_interfaces(cp->interfaces, cp->interfaces_count, cp->constant_pool);
	}

	//Fields
	if(cp->fields_count > 0){
		fprintf(arquivo_saida, "##Fields##\n");
		fprintf(arquivo_saida, "Fields Count: %d\n", cp->fields_count);
		exibir_fields(cp->fields, cp->fields_count, cp->constant_pool);
	}

	//Methods
	if(cp->methods_count > 0){
		fprintf(arquivo_saida, "##Methods##\n");
		fprintf(arquivo_saida, "Methods Count: %d\n", cp->methods_count);
		exibir_methods(cp->methods, cp->methods_count, cp->constant_pool);
	}

	//Attributes
	if(cp->attributes_count > 0){
		fprintf(arquivo_saida, "##Attributes##\n");
		fprintf(arquivo_saida, "Attributes Count: %d\n", cp->attributes_count);

		u2 i = 0;
		while(i < cp->attributes_count){
			char *nome_atributo = recupera_utf8(cp->constant_pool,cp->attributes[i].attribute_name_index);

			if(nome_atributo) {
				//comparar a string recuperada com os nomes de atributos e retornar a função que trata do atributo encontrado
				if(strcmp(nome_atributo,CONST_VALUE)==0) exibir_constant_attribute(cp->attributes[i],cp->constant_pool);
				if(strcmp(nome_atributo,CODE)==0) exibir_code_attribute(cp->attributes[i],cp->constant_pool);
				if(strcmp(nome_atributo,EXCEPTION)==0) exibir_exception_attribute(cp->attributes[i],cp->constant_pool);
				if(strcmp(nome_atributo,INNER_CLASSES)==0) exibir_inner_classes_attribute(cp->attributes[i],cp->constant_pool);
				if(strcmp(nome_atributo,SOURCE_FILE)==0) exibir_source_file_attribute(cp->attributes[i],cp->constant_pool);
			}
			i++;
			free(nome_atributo);
		}
	}
}

void exibir_interfaces(u2 *interfaces, u2 interfaces_count, cp_info *const_pool){
	u2 i;

	for(i = 0; i < interfaces_count; i++) {
		char *class_name = recupera_class_name(const_pool, *(interfaces + i));
		fprintf(arquivo_saida, "\n-----------------\n");
		fprintf(arquivo_saida, "\nInterface %d: cp_info #%d <%s>", i, *(interfaces + i),class_name);

		free(class_name);
	}
	fprintf(arquivo_saida, "\n\n\n");
}

void exibir_access_flag(u2 flag){
	fprintf(arquivo_saida, "Access flags: 0x%04x [", flag);
	while(flag != 0){
		if(flag >= ENUM){
			flag -= ENUM;
			fprintf(arquivo_saida, " enum");
		}else if( flag >= ACC_ANNOTATION){
			flag -= ACC_ANNOTATION;
			fprintf(arquivo_saida, " annotation");
		}else if(flag >= ACC_SYNTHETIC) {
			flag -= ACC_SYNTHETIC;
			fprintf(arquivo_saida, " synthetic");
		}else if (flag >= ACC_ABSTRACT) {
			flag -= ACC_ABSTRACT;
			fprintf(arquivo_saida, " abstract");
		}else if (flag >= ACC_INTERFACE) {
			flag -= ACC_INTERFACE;
			fprintf(arquivo_saida, " interface");
		}else if (flag >= ACC_SUPER) {
			flag -= ACC_SUPER;
			fprintf(arquivo_saida, " super");
		}else if (flag >= ACC_FINAL) {
			flag -= ACC_FINAL;
			fprintf(arquivo_saida, " final");
		} else{
			flag -= ACC_PUBLIC;
			fprintf(arquivo_saida, " public");
		}
	}
	fprintf(arquivo_saida, "]");
}

void exibir_tipo_classe(char *tipo, u2 classe_index, cp_info *const_pool){
	char *class_name = recupera_class_name(const_pool, classe_index);

	fprintf(arquivo_saida, "\n%s: cp_info #%d <%s>", tipo, classe_index,class_name);

	free(class_name);
}
