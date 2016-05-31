#include "exibidor_campos.h"
#include "exibidor_atributos.h"

void exibir_fields(field_info *pt_fields, u2 fields_count, cp_info *const_pool){
	u2 i;
	field_info *fields = pt_fields;

	for(i = 0; i < fields_count; i++) {
		
	  
		u2 name_index = fields[i].name_index;
		u2 descriptor_index = fields[i].descriptor_index;
		u2 flag = fields[i].access_flags;

		char *field_name = recupera_string(const_pool, name_index);

		printf("\n-----------------\n");
		printf("\n[%d] %s", i, field_name);
		printf("\nName: cp_info #%d <%s>", name_index, field_name);
		printf("\nDescriptor: cp_info #%d <%s>", descriptor_index, recupera_string(const_pool, descriptor_index));
		printf("\nAccess flags: %06x [", flag);
		while(flag != 0){
			if(flag >= ENUM){
				flag -= ENUM;
				printf(" enum");
			}else if( flag >= TRANSCIENT){
				flag -= TRANSCIENT;
				printf(" transient");
			}else if(flag >= VOLATILE) {
				flag -= VOLATILE;
				printf(" volatile");
			}else if (flag >= FINAL) {
				flag -= FINAL;
				printf(" final");
			}else if (flag >= STATIC) {
				flag -= STATIC;
				printf(" static");
			}else if (flag >= PROTECTED) {
				flag -= PROTECTED;
				printf(" protected");
			}else if (flag >= PRIVATE) {
				flag -= PRIVATE;
				printf(" private");
			} else{
				flag -= PUBLIC;
				printf(" public");
			}
		}
		printf("]\n");
	}
	printf("\n\n\n");
}
