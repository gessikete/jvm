#include "leitor_atributos.h"
#include "recuperar_constant_pool.h"
#include <string.h>
#include <stdlib.h>

void criar_constant_value_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count) {
	// Define qual o tipo de attribute, necessário para desalocar
	attributes[index].attribute_tag = CONST_VALUE_NUM;

	//salvando numero do index  na struct
	attributes[index].info.constant_value_info.constant_value_index = ler_u2(pt_arquivo);
}

void criar_code_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count) {
	u4 i;

	// Variavel local para salvar as informações
	code_attribute code_info;

	//Leitura das informações no arquivo
	u2 max_stack = ler_u2(pt_arquivo);
	u2 max_locals = ler_u2(pt_arquivo);
	u4 code_length = ler_u4(pt_arquivo);

	//Alocação de memória para o código
	u1 *code = (u1*) malloc(sizeof(u1)*code_length);					//code[code_lenght]

	//Leitura byte a byte do código
	for(i=0; i<code_length; i++) {
		code[i] = ler_u1(pt_arquivo);
	}

	//Leitura do tamanho da exception_table
	u2 exception_table_length = ler_u2(pt_arquivo);

	//Declaração de ponteiro para a exception_table
	t_exception_table *exception_table = NULL;

	//Se a exception table tiver ao menos um elemento, salvar as informações
	if(exception_table_length>0) {
		//Alocação da exception table
		exception_table = (t_exception_table*) malloc(sizeof(t_exception_table)*exception_table_length);

		//Leitura de cada uma das entradas da exception_table
		for(i=0; i<exception_table_length; i++) {
			//Leitura das informações de cada um dos elemento da exception table
			exception_table[i].start_pc = ler_u2(pt_arquivo);
			exception_table[i].end_pc = ler_u2(pt_arquivo);
			exception_table[i].handler_pc = ler_u2(pt_arquivo);
			exception_table[i].catch_type = ler_u2(pt_arquivo);
		}

	}

	//Leitura da quantidade de atributos
	u2 attributes_count = ler_u2(pt_arquivo);

	//Declaração de um ponteiro para os atributos
	attribute_info *atributos = NULL;		//attributes[attributes_count]

	//Se houver mais de um atributo, alocar espaço para eles e chamar a função para salvá-los
	if(attributes_count>0) {
		atributos = (attribute_info*) malloc (sizeof(attribute_info)*attributes_count);
		atributos = carregar_atributos(pt_arquivo,attributes_count,constant_pool,constant_pool_count);

	}

	//Salva as informações lidas na variável code_info
	code_info.max_stack = max_stack;
	code_info.max_locals = max_locals;
	code_info.code_length = code_length;
	code_info.code = code;
	code_info.exception_table_length = exception_table_length;
	code_info.exception_table = exception_table;
	code_info.attributes = atributos;

	//Entrada corrente da lista de atributos recebe code_info
	attributes[index].info.code_info = code_info;
	// Define qual o tipo de attribute, necessário para desalocar
	attributes[index].attribute_tag = CODE_NUM;
}

void criar_exceptions_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count) {
	u2 i;
	exceptions_attribute exceptions_info;

	//Leitura do tamanho da exception_table
	exceptions_info.number_of_exceptions = ler_u2(pt_arquivo);

	//Declaração de ponteiro para a exception_table
	u2 *exception_table_index = NULL;

	//Se a exception table tiver ao menos um elemento, salvar as informações
	if(exceptions_info.number_of_exceptions > 0) {
		//Alocação da exception table
		exception_table_index = (u2*) malloc(sizeof(u2)*exceptions_info.number_of_exceptions);

		//Leitura de cada uma das entradas da exception_table
		for(i=0; i < exceptions_info.number_of_exceptions; i++) {
			//Leitura das informações de cada um dos elemento da exception table
			exception_table_index[i] = ler_u2(pt_arquivo);
		}
		exceptions_info.exceptions_index_table = exception_table_index;
	}
	attributes[index].info.exception_info = exceptions_info;
	// Define qual o tipo de attribute, necessário para desalocar
	attributes[index].attribute_tag = EXCEPTION_NUM;
}


void criar_innner_classes_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count) {
	u2 i;
	inner_classes_attribute inner_classes_info;

	// leitura do número de classes
	inner_classes_info.number_of_classes = ler_u2(pt_arquivo);

	inner_classes_table *classes = NULL;

	if(inner_classes_info.number_of_classes > 0){
		//alocação de espaço para as classes
		classes = (inner_classes_table*)malloc(sizeof(inner_classes_table)*inner_classes_info.number_of_classes);
		//Leitura de cada uma das entradas de inner_classes
		for(i=0; i < inner_classes_info.number_of_classes; i++) {
			//Leitura das informações de cada um dos elemento da inner class table
			classes[i].inner_class_info_index = ler_u2(pt_arquivo);
			classes[i].outer_class_info_index = ler_u2(pt_arquivo);
			classes[i].inner_name_index = ler_u2(pt_arquivo);
			classes[i].inner_class_access_flags = ler_u2(pt_arquivo);
		}
		inner_classes_info.classes = classes;
	}
	//adiciona o atributo de inner class ao atributo
	attributes[index].info.inner_classes_info = inner_classes_info;
	// Define qual o tipo de attribute, necessário para desalocar
	attributes[index].attribute_tag = INNER_CLASSES_NUM;
}

void criar_source_file_attribute(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count) {
	// preenche o attribute_tag com o valor de SOURCE_FILE_NUM
	attributes[index].attribute_tag = SOURCE_FILE_NUM;

	attributes[index].info.source_file_info.source_file_index = ler_u2(pt_arquivo);

}

void atributo_invalido(FILE *pt_arquivo, attribute_info attributes[], u2 index, cp_info constant_pool[],  u2 constant_pool_count) {
	u2 i = 0; // índice do loop for

	// preenche o attribute_tag com o valor de atributo inválido
	attributes[index].attribute_tag = INVALIDO_NUM;

	// percorre o arquivo ignorando os bytes do atributo
	for(i = 0; i < attributes[index].attribute_length; i++){
		ler_u1(pt_arquivo);
	}
}


funcoes_criar escolher_funcao(cp_info constant_pool[], u2 name_index) {
	char *nome_atributo = recupera_string(constant_pool,name_index);

	//Se conseguir recuperar a string
	if(nome_atributo) {
		//comparar a string recuperada com os nomes de atributos e retornar a função que trata do atributo encontrado
		if(strcmp(nome_atributo,CONST_VALUE)==0) return criar_constant_value_attribute;
		if(strcmp(nome_atributo,CODE)==0) return criar_code_attribute;
		if(strcmp(nome_atributo,EXCEPTION)==0) return criar_exceptions_attribute;
		if(strcmp(nome_atributo,INNER_CLASSES)==0) return criar_innner_classes_attribute;
		if(strcmp(nome_atributo,SOURCE_FILE)==0) return criar_source_file_attribute;
		//if(strcmp(nome_atributo,LINE_NUM_TABLE)==0) return criar_line_number_table_attribute;
	}
	//caso atributo seja inválido, chamar a função que não faz nada (trata atributo desconhecido em silêncio)
	return atributo_invalido;
}

void criar_attribute(FILE *pt_arquivo, cp_info constant_pool[], u2 constant_pool_count, attribute_info atributos[], u2 index) {
	//funcao de criacao de atributos
	funcoes_criar funcao_criar;

	// Tenta ler o índice para a constant_pool attribute_name_index
	u2 name_index = ler_u2(pt_arquivo);
	// Tenta ler o tamanho das informações seguintes em bytes
	u4 attribute_length = ler_u4(pt_arquivo);


	atributos[index].attribute_name_index = name_index;
	atributos[index].attribute_length = attribute_length;

	// Verifica se o nome do índice é uma entrada válida na constant pool
	if(name_index<=constant_pool_count) {
		// Encontra a função adequada para salvar as informações do atributo.
		funcao_criar = escolher_funcao(constant_pool,name_index);

		// Chama a função para salvar as informações.
		funcao_criar(pt_arquivo,atributos,index,constant_pool,constant_pool_count);
	}
}


attribute_info *carregar_atributos(FILE *pt_arquivo, u2 attributes_count, cp_info constant_pool[], u2 constant_pool_count){
    attribute_info *pt_atributos = NULL;
    int i = 0; // índice para o laço for

    // Tenta alocar na memória o array de estruturas attribute_info
    pt_atributos = (attribute_info *) malloc(sizeof(attribute_info) * attributes_count);
    if(pt_atributos == NULL){
        return NULL;
    }

    // Lê uma estrutura attribute_info para cada um dos dados
    for(i = 0; i < attributes_count; i++){
		criar_attribute(pt_arquivo,constant_pool,constant_pool_count,pt_atributos,i);
    }

    return pt_atributos;
}

void desalocar_atributos(attribute_info *attributes, u2 attributes_count){
	if(attributes != NULL){
		u2 i = 0; // índice para o loop for

		// percorre o array de attributes procurando por estruturas internas para desalocar
		for(i = 0; i < attributes_count; i++){
			// Verfica qual é o tipo de atributo para desalocar
			if((attributes + i)->attribute_tag == CODE_NUM){
				desalocar_code_attribute(attributes + i);
			}else if((attributes + i)->attribute_tag == EXCEPTION_NUM){
				desalocar_exceptions_attribute(attributes + i);
			}else if((attributes + i)->attribute_tag == INNER_CLASSES_NUM){
				desalocar_innner_classes_attribute(attributes + i);
			}
		}
		// desaloca o array de attributes
		free(attributes);
	}
}

void desalocar_code_attribute(attribute_info *attributes){
	free(attributes->info.code_info.code);
	free(attributes->info.code_info.exception_table);
	desalocar_atributos(attributes->info.code_info.attributes, attributes->info.code_info.attributes_count);
}

void desalocar_exceptions_attribute(attribute_info *attributes){
	free(attributes->info.exception_info.exceptions_index_table);
}

void desalocar_innner_classes_attribute(attribute_info *attributes){
	free(attributes->info.inner_classes_info.classes);
}
