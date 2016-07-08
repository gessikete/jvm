/*!
   \file exibidor_campos.c
   \brief Implementação das funções de manipulação da exibição de campos.

   Esse arquivo contém a implementação das funções que manipulam a exibição de
   campos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
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
		fprintf(arquivo_saida, "\nAccess flags: ");
		exibir_access_flag_field(flag);
		free(descriptor);
		free(field_name);
	}
	fprintf(arquivo_saida, "\n\n\n");
}
