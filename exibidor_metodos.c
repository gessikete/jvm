#include "exibidor_metodos.h"

void exibir_methods(method_info *methods, u2 methods_count, cp_info *const_pool){
	u2 i, j;

	for(i = 0; i < methods_count; i++) {
		u2 name_index = methods[i].name_index;
		u2 descriptor_index = methods[i].descriptor_index;
		u2 flag = methods[i].access_flags;

		char *method_name = recupera_utf8(const_pool, name_index);
		char *descriptor_name = recupera_utf8(const_pool, descriptor_index);

		fprintf(arquivo_saida, "\n-----------------\n");
		fprintf(arquivo_saida, "\n[%d] %s", i, method_name);
		fprintf(arquivo_saida, "\nName: cp_info #%d <%s>", name_index, method_name);
		fprintf(arquivo_saida, "\nDescriptor: cp_info #%d <%s>", descriptor_index, descriptor_name);
		fprintf(arquivo_saida, "\nAccess flags: 0x%04x [", flag);
		while(flag != 0){
			if(flag >= SYNTHETIC){
				flag -= SYNTHETIC;
				fprintf(arquivo_saida, " synthetic");
			}else if( flag >= ABSTRACT){
				flag -= ABSTRACT;
				fprintf(arquivo_saida, " abstract");
			}else if(flag >= NATIVE) {
				flag -= NATIVE;
				fprintf(arquivo_saida, " native");
			}else if (flag >= VARARGS) {
				flag -= VARARGS;
				fprintf(arquivo_saida, " varargs");
			}else if (flag >= BRIDGE) {
				flag -= BRIDGE;
				fprintf(arquivo_saida, " bridge");
			}else if (flag >= SYNCHRONIZED) {
				flag -= SYNCHRONIZED;
				fprintf(arquivo_saida, " synchronized");
			}else if (flag >= FINAL) {
				flag -= FINAL;
				fprintf(arquivo_saida, " final");
			} else if (flag >= STATIC){
				flag -= STATIC;
				fprintf(arquivo_saida, " static");
			} else if (flag >= PROTECTED){
				flag -= PROTECTED;
				fprintf(arquivo_saida, " protected");
			} else if (flag >= PRIVATE){
				flag -= PRIVATE;
				fprintf(arquivo_saida, " private");
			} else {
				flag -= PUBLIC;
				fprintf(arquivo_saida, " public");
			}
		}
		fprintf(arquivo_saida, "]\n\n");
		fprintf(arquivo_saida, "\nAttribute Count for methods: %d ", methods[i].attributes_count);
		for(j = 0; j < methods[i].attributes_count; j++){
			exibir_code_attribute(methods[i].attributes[j], const_pool);
		}

		free(method_name);
		free(descriptor_name);
	}
	fprintf(arquivo_saida, "\n\n\n");
}
