#include "exibidor_campos.h"
#include "exibidor_atributos.h"

void exibir_fields(field_info *fields, u2 fields_count){
	int i, j;

	for(i=0; i < fields_count; i++){
	//Access flag para o campo
	switch(fields->access_flags){
		case(PUBLIC):
			printf("\tFields - Access Flags: Public\n");
			break;
		case(PRIVATE):
			printf("\tFields - Access Flags: Private\n");
			break;
		case(PROTECTED):
			printf("\tFields - Access Flags: Protected\n");
			break;
		case(STATIC):
			printf("\tFields - Access Flags: Static\n");
			break;
		case(FINAL):
			printf("\tFields - Access Flags: Final\n");
			break;
		case(VOLATILE):
			printf("\tFields - Access Flags: Volatile\n");
			break;
		case(TRANSCIENT):
			printf("\tFields - Access Flags: Transcient\n");
			break;
		case(ENUM):
			printf("\tFields - Access Flags: Enum\n");
			break;
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
