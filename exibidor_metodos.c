/*!
   \file exibidor_metodos.c
   \brief Implementação das funções de manipulação da exibição de métodos.

   Esse arquivo contém a implementação das funções que manipulam a exibição de
   métodos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "exibidor_metodos.h"

void exibir_methods(method_info *methods, u2 methods_count, cp_info *const_pool){
	u2 i, j;

	for(i = 0; i < methods_count; i++) {
		u2 name_index = methods[i].name_index;
		u2 descriptor_index = methods[i].descriptor_index;
		u2 flag = methods[i].access_flags;

		char *method_name = recupera_utf8(const_pool, name_index);
		char *descriptor_name = recupera_utf8(const_pool, descriptor_index);

		fprintf(arquivo_saida, "\n[%d] %s", i, method_name);
		fprintf(arquivo_saida, "\nName: cp_info #%d <%s>", name_index, method_name);
		fprintf(arquivo_saida, "\nDescriptor: cp_info #%d <%s>", descriptor_index, descriptor_name);
		fprintf(arquivo_saida, "\nAccess flags: ");
		exibir_access_flag_method(flag);
		fprintf(arquivo_saida, "\nAttribute Count for methods: %d ", methods[i].attributes_count);
		for(j = 0; j < methods[i].attributes_count; j++){
			exibir_code_attribute(methods[i].attributes[j], const_pool);
		}

		free(method_name);
		free(descriptor_name);
	}
	fprintf(arquivo_saida, "\n\n\n");
}
