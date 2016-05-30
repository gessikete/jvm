#include "exibidor_classe.h"


void exibir_classe(class_file* cp){

	printf("Magic Number: %08x\n", cp->magic);
	printf("Minor Version: %d\n", cp->minor_version);
	printf("Major Version: %d\n", cp->major_version);
	printf("Constant Pool Count: %d\n", cp->constant_pool_count);

	exibir_constant_pool(cp->constant_pool, cp->constant_pool_count);

	printf("Access Flag: %04x\n", cp->access_flags);
	printf("This Class: %04x\n", cp->this_class);
	printf("Super Class: %04x\n", cp->super_class);


	printf("Interface Count: %d\n", cp->interfaces_count);

	/* Interfaces e classes são definidas pelo mesmo tipo de dados, então utiliza as mesmas funcoes. */
	//exibir_interfaces(cp->interfaces, cp->interfaces_count); //TODO

	printf("Fields Count: %d\n", cp->fields_count);

		/* FALTA - EXIBIDOR DE FIELDS */
	/* exibir_fields(cp->fields, cp->fields_count); */

	printf("Methods Count: %d\n", cp->methods_count);

		/* FALTA - EXIBIDOR DE METODOS */
	/* exibir_methods(cp->methods, cp->methods_count); */

	printf("Attributes Count: %d\n", cp->attributes_count);

		/* FALTA - EXIBIDOR DE ATTRIBUTES */
	/* exibir_attributes(cp->attributes, cp->attributes_count); */
}
