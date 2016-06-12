#include "exibidor_campos.h"

void exibir_fields(field_info *pt_fields, u2 fields_count, cp_info *const_pool){
	u2 i;
	field_info *fields = pt_fields;

	for(i = 0; i < fields_count; i++) {


		u2 name_index = fields[i].name_index;
		u2 descriptor_index = fields[i].descriptor_index;
		u2 flag = fields[i].access_flags;

		char *field_name = recupera_utf8(const_pool, name_index);
		char *descriptor = recupera_utf8(const_pool, descriptor_index);

		fprintf(arquivo_saida, "\n[%d] %s", i, field_name);
		fprintf(arquivo_saida, "\nName: cp_info #%d <%s>", name_index, field_name);
		fprintf(arquivo_saida, "\nDescriptor: cp_info #%d <%s>", descriptor_index, descriptor);
		fprintf(arquivo_saida, "\nAccess flags: 0x%04x [", flag);
		while(flag != 0){
			if(flag >= ENUM){
				flag -= ENUM;
				fprintf(arquivo_saida, " enum");
			}else if( flag >= TRANSCIENT){
				flag -= TRANSCIENT;
				fprintf(arquivo_saida, " transient");
			}else if(flag >= VOLATILE) {
				flag -= VOLATILE;
				fprintf(arquivo_saida, " volatile");
			}else if (flag >= FINAL) {
				flag -= FINAL;
				fprintf(arquivo_saida, " final");
			}else if (flag >= STATIC) {
				flag -= STATIC;
				fprintf(arquivo_saida, " static");
			}else if (flag >= PROTECTED) {
				flag -= PROTECTED;
				fprintf(arquivo_saida, " protected");
			}else if (flag >= PRIVATE) {
				flag -= PRIVATE;
				fprintf(arquivo_saida, " private");
			} else{
				flag -= PUBLIC;
				fprintf(arquivo_saida, " public");
			}
		}
		fprintf(arquivo_saida, "]");
		free(descriptor);
		free(field_name);
	}
	fprintf(arquivo_saida, "\n\n\n");
}
