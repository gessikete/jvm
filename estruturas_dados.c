/*!
   \file estruturas_dados.c
   \brief Pilha de frames.

   Módulo responsável pelas operações das estruturas da pilha de frames e pilha
   de operandos.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "estruturas_dados.h"

lista_classes_estaticas *alocar_lista_classes_estaticas() {
	lista_classes_estaticas *classes_estaticas = (lista_classes_estaticas*)calloc(1,sizeof(lista_classes_estaticas));
	
	if(classes_estaticas) {
		classes_estaticas->first = NULL;
		classes_estaticas->last = NULL;
	} else {
		printf("\nNao foi possivel alocar espaco para uma lista de classes estaticas\n");
		excecao = true;
	}
	
	return classes_estaticas;
}

classe_estatica *nova_classe_estatica(class_file *pt_classe, classe_estatica  *next) {
	classe_estatica *nova_classe_estatica;
	
	
	nova_classe_estatica = (classe_estatica*)malloc(sizeof(classe_estatica));
	
	if(nova_classe_estatica) {
		nova_classe_estatica->pt_classe = pt_classe;
		
		nova_classe_estatica->next = next;
		nova_classe_estatica->last = nova_classe_estatica;
		
		nova_classe_estatica->lista_fields = alocar_lista_fields(pt_classe);
		nova_classe_estatica->tamanho_lista_fields = pt_classe->fields_count;
	} else {
		printf("\nNao foi possivel alocar espaco para uma classe estatica\n");
		excecao = true;
	}
	
	return nova_classe_estatica;
}

elemento_tabela_classes *nova_classe(class_file *pt_classe, elemento_tabela_classes *next) {
	elemento_tabela_classes *novo_elemento_tabela_classes;
	
	
	novo_elemento_tabela_classes = (elemento_tabela_classes*)malloc(sizeof(elemento_tabela_classes));
	if(novo_elemento_tabela_classes) {
		novo_elemento_tabela_classes->pt_classe = pt_classe;
		novo_elemento_tabela_classes->next = next;
		novo_elemento_tabela_classes->last = novo_elemento_tabela_classes;
	} else {
		printf("\nNao foi possivel alocar espaco para um novo class_file\n");
		excecao = true;
	}
	return novo_elemento_tabela_classes;
}

t_objeto *novo_objeto(class_file *pt_classe) {
	t_objeto *objeto = (t_objeto*)malloc(sizeof(t_objeto));
  
	if(objeto) {
		objeto->pt_classe = pt_classe;
		objeto->tamanho_lista_fields = pt_classe->fields_count;
		objeto->lista_fields = alocar_lista_fields(pt_classe);;
	  
	} else {
		printf("\nNao foi possivel alocar espaco para um novo objeto\n");
		excecao = true;
	}
	
	return objeto;
}

t_array* criar_array(u1 tag, u2 tamanho, u1 dimensoes) {
	t_array *array = (t_array*)malloc(sizeof(t_array));
	
	if(array) {
		array->tag = tag;
		array->tamanho = tamanho;
		array->dimensoes = dimensoes;
		
		array->array_data = (u8*)calloc(tamanho,sizeof(u8));
	} else {
		printf("\nNao foi possivel alocar espaco para um novo array\n");
		excecao = true;
	}

	return array;
}

t_operand_stack* alocar_operand_stack() {
	t_operand_stack* operand_stack;

	operand_stack = (t_operand_stack*) malloc(sizeof(t_operand_stack));
	if(!operand_stack) {
		printf("\nNao foi possivel alocar a pilha de operandos\n");
		excecao = true;
	}
	else operand_stack->first = NULL;

	return operand_stack;
}

t_operand *alocar_operando(u1 tag, u4 data, t_operand *next) {
	t_operand *operando;

	operando = (t_operand*) malloc(sizeof(t_operand));

	if(operando) {
		operando->tag = tag;
		operando->data = data;
		operando->next = next;
	} else {
		printf("\nNao foi possivel alocar espaco para operando\n");
		excecao = true;
	}


	return operando;
}

t_parameter_stack* alocar_parameter_stack(u1 tag, u4 data) {
	t_parameter_stack* parameter_stack;

	parameter_stack = (t_parameter_stack*) malloc(sizeof(t_parameter_stack));
	if(!parameter_stack) {
		printf("\nNao foi possivel alocar a pilha de parametros\n");
		excecao = true;
	}
	else parameter_stack->first = alocar_parametro(tag,data,NULL);

	return parameter_stack;
}

t_parameter *alocar_parametro(u1 tag, u4 data, t_parameter *next) {
	t_parameter *parametro;

	parametro = (t_parameter*) malloc(sizeof(t_parameter));

	if(parametro) {
		parametro->tag = tag;
		parametro->data = data;
		parametro->next = next;
	} else {
		printf("\nNao foi possivel alocar espaco para parametro\n");
		excecao = true;
	}


	return parametro;
}

stack_frames *alocar_stack_frames(class_file *this_class, lista_classes_estaticas *classes_estaticas, t_field *lista_fields, t_parameter_stack *pilha_parametros, method_info *pt_metodo, cp_info *pt_constant_pool) {
	stack_frames *pilha_frames = (stack_frames*) malloc(sizeof(stack_frames));

	if(!pilha_frames) {
		printf("\nNao foi possivel alocar a pilha de frames\n");
		excecao = true;
	}
	else pilha_frames->first = alocar_frame(this_class,classes_estaticas,lista_fields,pilha_parametros,pt_metodo,pt_constant_pool,NULL);

	return pilha_frames;
}

t_field *alocar_lista_fields(class_file *classe) {
	// Descobre tamanho da lista de fields
	u2 tamanho_lista = classe->fields_count;
			
	// Aloca lista de fields
	t_field *lista_fields = (t_field*)calloc(tamanho_lista,sizeof(t_field)*tamanho_lista);
	
	if(lista_fields) {
		// Pega ponteiros dos fields da classe
		for(int i=0; i<tamanho_lista; i++) {
			lista_fields[i].pt_field = &(classe->fields[i]); 
		}
	} else {
		printf("\nNao foi possivel alocar espaco para uma lista de fields\n");
		excecao = true;
	}
	
	return lista_fields;
}

t_frame *alocar_frame(class_file *this_class, lista_classes_estaticas *classes_estaticas, t_field *lista_fields, t_parameter_stack *pilha_parametros, method_info *pt_metodo, cp_info *pt_constant_pool, t_frame *next) {
	t_frame *frame = NULL;
	code_attribute *code_info;
	u2 i;

	// Verifica se método não está vazio
	if(pt_metodo) {

		// Tenta alocar um novo frame
		frame = (t_frame*) malloc(sizeof(t_frame));

		if(frame) {
			frame->this_class = this_class;
			
			frame->lista_fields = lista_fields;
			
			attribute_info *atributos = pt_metodo->attributes;

			// busca atributo code
			for(i=0; i<pt_metodo->attributes_count; i++) {
				if(atributos[i].attribute_tag==CODE_NUM) {
					code_info = &(atributos[i].info.code_info);
					break;
				}
			}

			frame->code_info = code_info;

			frame->pt_metodo = pt_metodo;
			frame->pc = 0;
			frame->array_variaveis_locais_count = code_info->max_locals;
			
			frame->array_variaveis_locais = (u4*) malloc(sizeof(u4)*(code_info->max_locals));

			i = 0;
			// Salva parâmetros no array de variáveis locais
			if(pilha_parametros) {
				while(pilha_parametros->first) {
					t_parameter *parametro = pop_parametro(pilha_parametros);
					frame->array_variaveis_locais[i] = parametro->data;
					
					free(parametro);
					i++;
				}
			}
			
			frame->operand_stack = alocar_operand_stack();

			frame->pt_constant_pool = pt_constant_pool ;
			
			frame->classes_estaticas = classes_estaticas;

			frame->next = next;
		}

	} else {
		printf("Nao foi possivel criar frame (metodo vazio)");
		excecao = true;
	}

	return frame;
}

void desalocar_array(t_array *pt_array){
	if(pt_array != NULL){
		// desaloca o array relativo a tag do tipo de array Java
		free(pt_array->array_data);
		// desaloca o array em si
		free(pt_array);
	}
}

void desalocar_objeto(t_objeto *pt_objeto){
	if(pt_objeto != NULL){
		// desaloca field
		if(pt_objeto->lista_fields != NULL) desalocar_fields(pt_objeto->lista_fields);

		// desaloca o objeto em si
		free(pt_objeto);
	}
}

void desalocar_fields(t_field *pt_fields){
	if(pt_fields != NULL){
		// desaloca field
		if(pt_fields->pt_field != NULL) desalocar_campos(pt_fields->pt_field, 1);
		
		// desaloca o field em si
		free(pt_fields);
	}
}

void desalocar_operand_stack(t_operand_stack *pt_operand_stack){
	if(pt_operand_stack != NULL){
		// desaloca o primeiro elemento da pilha de operandos
		if (pt_operand_stack->first != NULL) {
			desalocar_operando(pt_operand_stack->first);
		}
		// desaloca a pilha de operandos em si
		free(pt_operand_stack);
	}
}

void desalocar_operando(t_operand *pt_operando){
	if(pt_operando != NULL){
		// desaloca recursivamente toda a lista
		if(pt_operando->next != NULL) desalocar_operando(pt_operando->next);
		// desaloca o operando em si
		free(pt_operando);
	}
}

void desalocar_stack_frames(stack_frames *pt_stack_frames){
	if(pt_stack_frames != NULL){
		// desaloca o primeiro frame
		if(pt_stack_frames->first != NULL) desalocar_frame(pt_stack_frames->first);
		// desaloca a pilha propriamente dita
		free(pt_stack_frames);
	}
}

void desalocar_frame(t_frame *pt_frame){
	if(pt_frame != NULL){
		// muda a referência do ponteiro do método para null
		if(pt_frame->pt_metodo != NULL) pt_frame->pt_metodo = NULL;

		// muda a referência do ponteiro de code_info para null
		if(pt_frame->code_info != NULL) pt_frame->code_info = NULL;

		// desaloca array de variáveis locais
		if(pt_frame->array_variaveis_locais != NULL) free(pt_frame->array_variaveis_locais);

		// desaloca operand stack_frames
		if(pt_frame->operand_stack != NULL) desalocar_operand_stack(pt_frame->operand_stack);

		// muda a referência do ponteiro de constant pool para null
		if(pt_frame->pt_constant_pool != NULL) pt_frame->pt_constant_pool = NULL;

		if(pt_frame->next != NULL) desalocar_frame(pt_frame->next);
		// desaloca o frame em si
		free(pt_frame);
	}
}

t_operand *pop_operando(t_operand_stack *pilha_operandos) {
	t_operand *operando = pilha_operandos->first;
	pilha_operandos->first = operando->next;

	return operando;
}

void push_operando(u1 tag, u4 data, t_operand_stack *operand_stack) {
	operand_stack->first = alocar_operando(tag, data, operand_stack->first);
}


t_parameter *pop_parametro(t_parameter_stack *pilha_parametros) {
	t_parameter *parametro = pilha_parametros->first;
	pilha_parametros->first = parametro->next;

	return parametro;
}


void push_parametro(u1 tag, u4 data, t_parameter_stack *parameter_stack) {
	parameter_stack->first = alocar_parametro(tag, data, parameter_stack->first);
}

void push_frame(class_file *this_class, lista_classes_estaticas *classes_estaticas, t_field *lista_fields, t_parameter_stack *pilha_parametros, method_info *pt_metodo, cp_info *pt_constant_pool, stack_frames *pilha_frames) {
	pilha_frames->first = alocar_frame(this_class,classes_estaticas,lista_fields,pilha_parametros,pt_metodo,pt_constant_pool,pilha_frames->first);
}

t_frame *pop_frame(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	pilha_frames->first = frame->next;

	return frame;
}
