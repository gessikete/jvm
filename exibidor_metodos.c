#include "exibidor_metodos.h"

void exibir_metodos(method_info *methods, u2 methods_count){

	int i;
	u2 flag = methods->access_flags;

	printf("Metodos - Access Flags: %02x\n",methods->access_flags);
	printf("Metodos - Name Index: %02x\n",methods->name_index);
	printf("Metodos - Description Index: %02x\n",methods->descriptor_index);
	printf("Metodos - Attributes Count: %02x\n",methods->attributes_count);

	for(i = 0; i < methods_count; i++){
		printf("\tFields - Access Flag: %02x [",flag);
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
			printf("]\n");
	}
}
