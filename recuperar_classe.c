/*!
   \file recuperar_classe.c
   \brief Implementação das funções que recuperam classes referenciadas pelo
   arquivo classe informado.

   Este arquivo contém as implementações das funções que recuperam classes referenciadas pelo
   arquivo classe informado. Essas referências são feitas através de métodos utilizados
   pelo arquivo .class principal.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "recuperar_classe.h"

t_parameter_stack *carregar_parameter_stack(char *descritor, t_operand_stack *operand_stack) {
	t_parameter_stack *pilha_parametros = NULL;

	int i=1;
	//Coloca valores na lista de parametros de acordo com o descritor
	while(descritor[i]!=')') {
		//TODO: VERIFICAR SE TAG DO OPERANDO É IGUAL A TAG DO PARÂMETRO
		if((descritor[i]=='D')||(descritor[i]=='J')) {
			t_operand *operando_low = pop_operando(operand_stack);
			t_operand *operando_high = pop_operando(operand_stack);

			if(!pilha_parametros) {
				pilha_parametros = alocar_parameter_stack(operando_low->tag,operando_low->data);
				push_parametro(operando_high->tag,operando_high->data,pilha_parametros);
			} else {
				push_parametro(operando_low->tag,operando_low->data,pilha_parametros);
				push_parametro(operando_high->tag,operando_high->data,pilha_parametros);
			}
			free(operando_low);
			free(operando_high);
		} else {
			t_operand *operando = pop_operando(operand_stack);

			if(!pilha_parametros) {
				pilha_parametros = alocar_parameter_stack(operando->tag,operando->data);
			} else push_parametro(operando->tag,operando->data,pilha_parametros);

			free(operando);
			while(descritor[i]=='[') i++;
			if(descritor[i]=='L') {
				while(descritor[i]!=';') i++;
			}
		}

		i++;
	}

	return pilha_parametros;
}

t_field *busca_field_classe_estatica(class_file *classe, t_frame *frame, char *class_name, char *field_name, char *descriptor) {
	t_field *field = NULL;
	_Bool flag_clinit = false;

	classe_estatica *elemento_lista_classes_estaticas = NULL;

	// Cria lista de classes estáticas se ela não existir
	if(!frame->classes_estaticas->first) {
		elemento_lista_classes_estaticas = nova_classe_estatica(classe,NULL);
		frame->classes_estaticas->first = elemento_lista_classes_estaticas;
		frame->classes_estaticas->last = elemento_lista_classes_estaticas;

		// Seta flag_clinit (significa que variáveis estáticas precisam ser inicializadas)
		flag_clinit = true;
	} else {
		elemento_lista_classes_estaticas = busca_classe_estatica(classe,frame->classes_estaticas->first);

		// Se lista não estiver vazia, mas a classe não estiver lá, o último elemento da lista recebe a classe
		if(!elemento_lista_classes_estaticas) {
			frame->classes_estaticas->last->next = nova_classe_estatica(classe,frame->classes_estaticas->last->next);
			elemento_lista_classes_estaticas = frame->classes_estaticas->last->next;
			flag_clinit = true;
		}
	}

	if(flag_clinit) {
		method_info *clinit_method = recupera_metodo(&classe,"<clinit>","()V");
		if(clinit_method) {
			t_parameter_stack *pilha_parametros_init = alocar_parameter_stack(TAG_OBJECT_REF,(u4)classe);
			lista_classes_estaticas *classes_estaticas = alocar_lista_classes_estaticas();

			stack_frames *pilha_frames_temp =
				alocar_stack_frames(classe,
				classes_estaticas,
				elemento_lista_classes_estaticas->lista_fields,
				pilha_parametros_init,
				clinit_method,classe->constant_pool);

			executar_jvm(pilha_frames_temp);
		} else {
			//TODO: inicializar campos
		}
	}

	field = busca_field(elemento_lista_classes_estaticas->lista_fields,
			    elemento_lista_classes_estaticas->tamanho_lista_fields,
			    classe->constant_pool,
			    field_name,
			    descriptor);

	return field;
}

classe_estatica *busca_classe_estatica(class_file *pt_classe, classe_estatica *lista_classes) {
	classe_estatica *classe = lista_classes;

	while(classe) {
	  if (pt_classe==classe->pt_classe) {
		 return classe;
		}
		classe = classe->next;
	}

	return NULL;
}

t_field *busca_field(t_field *lista_fields, u2 tamanho_lista_fields, cp_info *pt_constant_pool, char *field_name, char *descriptor) {
	for(int i=0; i<tamanho_lista_fields; i++) {
		field_info *pt_field = lista_fields[i].pt_field;
		u2 field_name_index = pt_field->name_index;
		u2 descriptor_index = pt_field->descriptor_index;


		char *field_name_i = recupera_utf8(pt_constant_pool,field_name_index);
		char *descriptor_i = recupera_utf8(pt_constant_pool,descriptor_index);


		if(((!strcmp(field_name_i,field_name))&&
		  ((!strcmp(descriptor_i,descriptor))))) {
			free(field_name_i);
			free(descriptor_i);

			return &(lista_fields[i]);
		}

		free(field_name_i);
		free(descriptor_i);
	}

	printf("\nErro: field nao encontrado\n");
	excecao = true;
	return NULL;

}

class_file *busca_classe(char *nome_classe, elemento_tabela_classes *lista_classes) {
	elemento_tabela_classes *elemento_classe = NULL;


	elemento_classe = lista_classes;
	while(elemento_classe) {
		class_file *classe = elemento_classe->pt_classe;
		char *this_class_name = recupera_class_name(classe->constant_pool,classe->this_class);


		if(!strcmp(this_class_name,nome_classe)) {
			free(this_class_name);
			return classe;
		}

		free(this_class_name);
		elemento_classe = elemento_classe->next;
	}


	// Se chegou aqui, classe não está carregada. Então uma nova classe é
	// criada e colocada na lista de classes.
	class_file *classe = carregar_classe(nome_classe);
	lista_classes->last->next = nova_classe(classe,lista_classes->last->next);

	return classe;
}



method_info *recupera_metodo(class_file **classe, char *method_name, char *method_descriptor) {
	int32_t i;

	for(i = 0; i < (*classe)->methods_count; i++) {
		u2 name_index = (*classe)->methods[i].name_index;
		u2 descriptor_index = (*classe)->methods[i].descriptor_index;

		char *name = recupera_utf8((*classe)->constant_pool,name_index);
		char *descriptor = recupera_utf8((*classe)->constant_pool,descriptor_index);

		if((strcmp(name, method_name) == 0) &&
			(strcmp(descriptor, method_descriptor)) == 0) {
			free(name);
			free(descriptor);
			return &(*classe)->methods[i];
		}
		free(name);
		free(descriptor);
	}
	// TODO retorno caso o método esteja na superClass

	return NULL;
}
