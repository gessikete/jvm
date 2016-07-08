/*!
   \file execucao_jvm.c
   \brief Implementação das funções de execução da JVM.

   Esse arquivo contém a implementação das funções que definem o execução da JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/
#include "execucao_jvm.h"

elemento_tabela_classes *lista_classes;

//void inicializar_jvm(class_file *pt_classe, int argc, char *argv[]) {
void inicializar_jvm(class_file *pt_classe) {
	stack_frames *pilha_frames;
	cp_info *constant_pool = pt_classe->constant_pool;
	method_info *init_method;
	method_info *main_method;
	method_info *clinit_method;
	_Bool flag_args = false;
	t_parameter_stack *pilha_parametros_main = NULL;
	t_parameter_stack *pilha_parametros_init = NULL;

	// Busca <clinit>
	clinit_method = recupera_metodo(&pt_classe,"<clinit>","()V");

	// Busca <init>
	init_method = recupera_metodo(&pt_classe,"<init>","()V");

	if(!init_method) {
		printf("\nErro! Metodo <init> nao encontrado\n");
		return;
	}

	// Busca main
	main_method = recupera_metodo(&pt_classe,"main","()V");

	// Verifica se encontrou método main sem argumentos.
	if(!main_method) {

		// Senão, procura main com argumentos.
		main_method = recupera_metodo(&pt_classe,"main","([Ljava/lang/String;)V");

		// Se não encontrar, exibe mensagem de erro.
		if(!main_method) {
			printf("\nErro! Metodo main nao encontrado\n");
			return;
		}
		// Se encontrar, seta a flag de argumentos para true.
		else flag_args = true;
	}
	
	// Aloca lista de campos
	t_field *lista_fields = alocar_lista_fields(pt_classe);
	
	// Aloca lista de classes estaticas 
	lista_classes_estaticas *classes_estaticas = alocar_lista_classes_estaticas();

	// Aloca pilha de parâmetros para init (que na prática será um ponteiro para a classe)
	pilha_parametros_init = alocar_parameter_stack(TAG_OBJECT_REF,(u4)pt_classe);

	if (flag_args) {
		// Aloca pilha de parâmetros para a main (args[])
		//pilha_parametros_main = alocar_parameter_stack();
		//TODO: quando main recebe args[] (pilha_parametros_main recebe args[])
	}

	// Aloca a pilha de frames com a main como primeiro elemento
	pilha_frames = alocar_stack_frames(pt_classe,classes_estaticas,lista_fields,pilha_parametros_main,main_method,constant_pool);

	if (clinit_method) {
		// Push de clinit (caso exista)
		push_frame(pt_classe,classes_estaticas,lista_fields,pilha_parametros_init,clinit_method,constant_pool,pilha_frames);
	}

	// Inicializa lista de classes carregadas
	lista_classes = nova_classe(pt_classe, NULL);

	executar_jvm(pilha_frames);
}

void executar_jvm(stack_frames *pilha_frames) {
	// Inicializa vetor de instruções
	init_instrucoes();

	// Inicializa a flag de exceção com false
	excecao = false;

	// Executa até a pilha de frames se esvaziar
	while (pilha_frames->first) {
		//printf("\n%s",instrucoes[pilha_frames->first->code_info->code[pilha_frames->first->pc]].nome);
		if(!excecao)
			instrucoes[pilha_frames->first->code_info->code[pilha_frames->first->pc++]].funcao_instrucao(pilha_frames);
		else
			break;
	}
	printf("\n");
}
