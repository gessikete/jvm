#include "exibidor_campos.h"
#include "exibidor_atributos.h"

void exibir_fields(field_info *fields, u2 fields_count){
	int i;
	u2 flag = fields->access_flags;

	for(i=0; i < fields_count; i++){
	//Access flag para o campo
		printf("\tFields - Access Flag: %02x [",flag);
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
			printf("]\n");
		}
	//index de constant_pool válido, contendo um constant_u8_info
	printf("\tFields - Name Index: %02x\n", fields->name_index);
	//index de descrição para o campo
	printf("\tFields - Descriptor Index: %02x\n", fields->descriptor_index);
	//número de atributos do campo com mesmo fields->access_flag
	printf("\tFields - Attributes Count: %02x\n", fields->attributes_count);

		//for(j = 0; j < attributes_count; j++){

				//EXIBIDOR DE ATTRIBUTES
//}
	}
}

