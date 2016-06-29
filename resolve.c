#include "resolve.h"

method_info *recupera_metodo(class_file **classe, char *method_name, char *method_descriptor) {
	int32_t i;

	for(i = 0; i < (*classe)->methods_count; i++) {
		if((strcmp((char *)(*classe)->constant_pool[(*classe)->methods[i].name_index].info.utf8_info.bytes, method_name) == 0) &&
			(strcmp((char *)(*classe)->constant_pool[(*classe)->methods[i].descriptor_index].info.utf8_info.bytes, method_descriptor)) == 0) {
			return &(*classe)->methods[i];
		}
	}

	// TODO retorno caso o método esteja na superClass

	return NULL;
}
