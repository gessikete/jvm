#include "exibidor_metodos.h"

void exibir_metodos(method_info *methods, u2 methods_count, cp_info *const_pool){
	u2 i, j;

	for(i = 0; i < methods_count; i++) {
		u2 name_index = methods->name_index;
		u2 descriptor_index = methods->descriptor_index;
		u2 flag = methods->access_flags;

		char *method_name = recupera_string(const_pool, name_index);

		printf("\n-----------------\n");
		printf("\n[%d] %s", i, method_name);
		printf("\nName: cp_info #%d <%s>", name_index, method_name);
		printf("\nDescriptor: cp_info #%d <%s>", descriptor_index, recupera_string(const_pool, descriptor_index));
		printf("\nAccess flags: %06x [", flag);
		while(flag != 0){
			if(flag >= SYNTHETIC){
				flag -= SYNTHETIC;
				printf(" synthetic");
			}else if( flag >= ABSTRACT){
				flag -= ABSTRACT;
				printf(" abstract");
			}else if(flag >= NATIVE) {
				flag -= NATIVE;
				printf(" native");
			}else if (flag >= VARARGS) {
				flag -= VARARGS;
				printf(" varargs");
			}else if (flag >= BRIDGE) {
				flag -= BRIDGE;
				printf(" bridge");
			}else if (flag >= SYNCHRONIZED) {
				flag -= SYNCHRONIZED;
				printf(" synchronized");
			}else if (flag >= FINAL) {
				flag -= FINAL;
				printf(" final");
			} else if (flag >= STATIC){
				flag -= STATIC;
				printf(" static");
			} else if (flag >= PROTECTED){
				flag -= PROTECTED;
				printf(" protected");
			} else if (flag >= PRIVATE){
				flag -= PRIVATE;
				printf(" private");
			} else {
				flag -= PUBLIC;
				printf(" public");
			}
		}
		printf("]\n\n");
		for(j = 0; j < methods->attributes_count; j++){
			exibir_code_attribute(methods->attributes[j], const_pool);
		}
	}
	printf("\n\n\n");
}
