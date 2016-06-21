#include "execucao_jvm.h"

void inicializar_jvm(class_file *pt_classe) {
	method_info *methods;
	cp_info *constant_pool;
	char *init_method;
	char *main_method;
	u2 indice_init;
	u2 indice_main;
	u2 methods_count;
	t_frame *frame = NULL;
	stack_frames *pilha_frames = NULL;

	if(pt_classe->methods_count>1) {
		methods = pt_classe->methods;

		constant_pool = pt_classe->constant_pool;

		// Strings recebem os nomes dos primeiros métodos para verificar se são init e main
		indice_init = methods[0].name_index;
		init_method = recupera_utf8(constant_pool,indice_init);

		methods_count = pt_classe->methods_count;

		// Busca método main entre os métodos da classe
		while(methods_count>1) {
			indice_main = methods[methods_count-1].name_index;
			main_method = recupera_utf8(constant_pool,indice_main);

			methods_count--;
			if(!strcmp(main_method,"main")) break;
		}

		// Checa os primeiros métodos
		if((!strcmp(init_method,"<init>")||(!strcmp(init_method,"<clinit>")))&&(!strcmp(main_method,"main"))) {

			// Aloca a pilha (que inicialmente estará vazia)
			pilha_frames = alocar_stack_frames();

			// Aloca o primeiro frame (do método <init>)
			frame = alocar_frame(&(methods[0]),constant_pool,NULL);

			// Primeiro elemento da pilha recebe ponteiro para o frame de init
			pilha_frames->first = frame;

			// Push do método main
			push_frame(&(methods[methods_count]),constant_pool,pilha_frames);
	
			executar_jvm(pilha_frames);

		} else printf("\nClasse informada nao pode ser inicializada (nao possui metodo <init> e/ou <main>)");
	} else printf("\nClasse informada nao pode ser inicializada (nao possui main)");

	free(init_method);
	free(main_method);
}

void executar_jvm(stack_frames *pilha_frames) {
	init_instrucoes();
  
	
	push_operando(3,pilha_frames->first->operand_stack);
	instrucoes[pilha_frames->first->code_info->code[pilha_frames->first->pc++]].funcao_instrucao(pilha_frames);

	pilha_frames->first->pc+=4;
	printf("\n%x\n",pilha_frames->first->code_info->code[pilha_frames->first->pc]);
	instrucoes[pilha_frames->first->code_info->code[pilha_frames->first->pc++]].funcao_instrucao(pilha_frames);
}
