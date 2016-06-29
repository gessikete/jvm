/*!
   \file instrucoes_161-201.c
   \brief Instruções da Máquina Virtual Java.

   Módulo responsável por parte das instruções que definem as operações a serem
   executadas pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#include "instrucoes_161-201.h"

void if_icmplt(stack_frames *pilha_frames) {
	tipo_int comp_1, comp_2;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_1 = (int)temp_operando->data;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_2 = (int)temp_operando->data;

	if(comp_1 < comp_2){
		u4 offset_2;
		u4 offset_1;

		pilha_frames->first->pc++;
		offset_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		offset_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

		tipo_short offset_16bit = 0;
		//gera o offset para  pc
		offset_16bit = (tipo_short)((offset_1 << 8) | offset_2);
		//adiciona offset ao valor de pc
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
	}

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void if_icmpge(stack_frames *pilha_frames) {
	tipo_int comp_1, comp_2;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_1 = (int)temp_operando->data;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_2 = (int)temp_operando->data;

	if(comp_1 >= comp_2){
		u4 offset_2;
		u4 offset_1;

		pilha_frames->first->pc++;
		offset_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		offset_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

		tipo_short offset_16bit = 0;
		//gera o offset para  pc
		offset_16bit = (tipo_short)((offset_1 << 8) | offset_2);
		//adiciona offset ao valor de pc
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
	}

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void if_icmpgt(stack_frames *pilha_frames) {
	tipo_int comp_1, comp_2;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_1 = (int)temp_operando->data;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_2 = (int)temp_operando->data;

	if(comp_1 > comp_2){
		u4 offset_2;
		u4 offset_1;

		pilha_frames->first->pc++;
		offset_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		offset_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

		tipo_short offset_16bit = 0;
		//gera o offset para  pc
		offset_16bit = (tipo_short)((offset_1 << 8) | offset_2);
		//adiciona offset ao valor de pc
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
	}

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void if_icmple(stack_frames *pilha_frames) {
	tipo_int comp_1, comp_2;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_1 = (int)temp_operando->data;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_2 = (int)temp_operando->data;

	if(comp_1 <= comp_2){
		u4 offset_2;
		u4 offset_1;

		pilha_frames->first->pc++;
		offset_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		offset_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

		tipo_short offset_16bit = 0;
		//gera o offset para  pc
		offset_16bit = (tipo_short)((offset_1 << 8) | offset_2);
		//adiciona offset ao valor de pc
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
	}

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void if_acmpeq(stack_frames *pilha_frames) {
	t_operand *comp_1 = NULL;
	t_operand *comp_2 = NULL;

	comp_1 = pop_operando(pilha_frames->first->operand_stack);
	comp_2 = pop_operando(pilha_frames->first->operand_stack);

	if(comp_1->data == comp_2->data){
		u4 offset_2;
		u4 offset_1;

		pilha_frames->first->pc++;
		offset_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		offset_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

		tipo_short offset_16bit = 0;
		//gera o offset para  pc
		offset_16bit = (tipo_short)((offset_1 << 8) | offset_2);
		//adiciona offset ao valor de pc
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
	}

	// desaloca operandos que foram desempilhados
	free(comp_1);
	free(comp_2);
}

void if_acmpne(stack_frames *pilha_frames) {
	t_operand *comp_1 = NULL;
	t_operand *comp_2 = NULL;

	comp_1 = pop_operando(pilha_frames->first->operand_stack);
	comp_2 = pop_operando(pilha_frames->first->operand_stack);

	if(comp_1->data != comp_2->data){
		u4 offset_2;
		u4 offset_1;

		pilha_frames->first->pc++;
		offset_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		offset_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

		tipo_short offset_16bit = 0;
		//gera o offset para  pc
		offset_16bit = (tipo_short)((offset_1 << 8) | offset_2);
		//adiciona offset ao valor de pc
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
	}

	// desaloca operandos que foram desempilhados
	free(comp_1);
	free(comp_2);
}

void goto_(stack_frames *pilha_frames) {
	u4 offset_2;
	u4 offset_1;

	pilha_frames->first->pc++;
	offset_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	offset_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	tipo_short offset_16bit = 0;
	//gera o offset para  pc
	offset_16bit = (tipo_short)((offset_1 << 8) | offset_2);
	//adiciona offset ao valor de pc
	pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
}

void jsr(stack_frames *pilha_frames) {
	//code_attribute *next_code_info;

	//empilha endereço de retorno da próxima instrução
	//next_code_info = pilha_frames->first->next->code_info;
	//TODO: tirar warning
	//push_operando(pilha_frames->first->next->pt_constant_pool->tag, (u4)next_code_info, pilha_frames->first->operand_stack); // TODO falta empilhar o tipo do operando como referencia

	u4 offset_2;
	u4 offset_1;

	pilha_frames->first->pc++;
	offset_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	offset_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	tipo_short offset_16bit = 0;
	//gera o offset para  pc
	offset_16bit = (tipo_short)((offset_1 << 8) | offset_2);
	//adiciona offset ao valor de pc
	pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
}

void ret(stack_frames *pilha_frames) {
	u4 index;

	pilha_frames->first->pc++;
	index = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	pilha_frames->first->pc = pilha_frames->first->array_variaveis_locais[index];
}

void tableswitch(stack_frames *pilha_frames) {
	u1 default_1, default_2, default_3, default_4;
	u1 low_1, low_2, low_3, low_4;
	u1 high_1, high_2, high_3, high_4;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	tipo_int index = (tipo_int)temp_operando->data;

	//setting default_t
	//passing the byte padding for correct address

	do{
		pilha_frames->first->pc++;
		if(pilha_frames->first->pc % 4 == 0){
			default_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		}
	}while(pilha_frames->first->pc % 4 != 0);

	pilha_frames->first->pc++;
	default_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	default_3 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	default_4 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	tipo_int default_t = 	(tipo_int)(((u4)default_1 << 24) | ((u4)default_2 << 16) | ((u4)default_3 << 8) | (u4)default_4);

	//setting low_t
	pilha_frames->first->pc++;
	low_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	low_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	low_3 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	low_4 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	tipo_int low_t = 	(tipo_int)(((u4)low_1 << 24) | ((u4)low_2 << 16) | ((u4)low_3 << 8) | (u4)low_4);

	//setting hight_t
	pilha_frames->first->pc++;
	high_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	high_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	high_3 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	high_4 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	tipo_int high_t = (tipo_int)(((u4)high_1 << 24) | ((u4)high_2 << 16) | ((u4)high_3 << 8) | (u4)high_4);

	//comparison for jump in the table os jump offsets
	if((index < low_t) || (index > high_t)){
		pilha_frames->first->pc = pilha_frames->first->pc + default_t;
	}
	else{
		pilha_frames->first->pc = pilha_frames->first->pc + pilha_frames->first->code_info->code[index - low_t];
	}
	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void lookupswitch(stack_frames *pilha_frames) {
	u1 default_1, default_2, default_3, default_4;
	u1 nvalue_1, nvalue_2, nvalue_3, nvalue_4;
	int aux = 0;

	//setting default_t
	//passing the byte padding for correct address

	do{
		pilha_frames->first->pc++;
		if(pilha_frames->first->pc % 4 == 0){
			default_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		}
	}while(pilha_frames->first->pc % 4 != 0);

	pilha_frames->first->pc++;
	default_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	default_3 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	default_4 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	tipo_int default_t = 	(tipo_int)(((u4)default_1 << 24) | ((u4)default_2 << 16) | ((u4)default_3 << 8) | (u4)default_4);

	//setting nvalue_t
	pilha_frames->first->pc++;
	nvalue_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	nvalue_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	nvalue_3 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
	pilha_frames->first->pc++;
	nvalue_4 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

	tipo_int nvalue_t = (tipo_int)(((u4)nvalue_1 << 24) | ((u4)nvalue_2 << 16) | ((u4)nvalue_3 << 8) | (u4)nvalue_4);

	//desempilha key value na operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	tipo_int key = (tipo_int)temp_operando->data;

	while(aux <= nvalue_t){
		u1 match_1, match_2, match_3, match_4;

		pilha_frames->first->pc++;
		match_1 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		match_2 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		match_3 = pilha_frames->first->code_info->code[pilha_frames->first->pc];
		pilha_frames->first->pc++;
		match_4 = pilha_frames->first->code_info->code[pilha_frames->first->pc];

		tipo_int match_t = (tipo_int)(((u4)match_1 << 24) | ((u4)match_2 << 16) | ((u4)match_3 << 8) | (u4)match_4);

		if( key != match_t){
			aux++;
		}
		else{
			pilha_frames->first->pc = pilha_frames->first->pc + pilha_frames->first->code_info->code[pilha_frames->first->pc];
		}
	}
	if(aux > nvalue_t){
		pilha_frames->first->pc = pilha_frames->first->pc + default_t;
	}

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void ireturn(stack_frames *pilha_frames) {
	//desempilha value da operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	u4 value = temp_operando->data;

	t_frame *temp_frame = NULL;
	temp_frame = pop_frame(pilha_frames);
	free(temp_frame);

	//adicionar tipo de value empilhado
	push_operando(temp_operando->tag, value,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void lreturn(stack_frames *pilha_frames) {
	//desempilha value da operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	u4 value_1 = temp_operando->data;
	u1 tag_1 = temp_operando->tag;
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	u4 value_2 = temp_operando->data;
	u1 tag_2 = temp_operando->tag;

	t_frame *temp_frame = NULL;
	temp_frame = pop_frame(pilha_frames);
	free(temp_frame);

	//adicionar tipo de value empilhado
	push_operando(tag_2, value_2,pilha_frames->first->operand_stack);
	//adicionar tipo de value empilhado
	push_operando(tag_1, value_1,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void freturn(stack_frames *pilha_frames) {
	//desempilha value da operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	u4 value = temp_operando->data;
	u1 tag = temp_operando->tag;

	t_frame *temp_frame = NULL;
	temp_frame = pop_frame(pilha_frames);
	free(temp_frame);

	//adicionar tipo de value empilhado
	push_operando(tag, value,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void dreturn(stack_frames *pilha_frames) {
	//desempilha value da operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	u4 value_1 = temp_operando->data;
	u1 tag_1 = temp_operando->tag;
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	u4 value_2 = temp_operando->data;
	u1 tag_2 = temp_operando->tag;

	t_frame *temp_frame = NULL;
	temp_frame = pop_frame(pilha_frames);
	free(temp_frame);

	//adicionar tipo de value empilhado
	push_operando(tag_2, value_2,pilha_frames->first->operand_stack);
	//adicionar tipo de value empilhado
	push_operando(tag_1, value_1,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void areturn(stack_frames *pilha_frames) {
	//referência de objeto
	//desempilha value da operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	u4 object_ref = temp_operando->data;
	u1 tag = temp_operando->tag;

	t_frame *temp_frame = NULL;
	temp_frame = pop_frame(pilha_frames);
	free(temp_frame);

	//adicionar tipo de value empilhado
	push_operando(tag, object_ref, pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void return_(stack_frames *pilha_frames) {
	t_frame *temp_frame = NULL;
	temp_frame = pop_frame(pilha_frames);
	free(temp_frame);
}

// TODO OBS: ESSA INSTRUÇÃO NÃO ESTÁ TODA IMPLEMENTADA!
void getstatic(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u2 indice_constant_pool = operando_u2(frame->code_info->code,frame->pc);
	char *name_field;

	// Incrementa pc para a próxima instrução
	frame->pc += 2;

	name_field = recupera_elemento_como_string_constant_pool(frame->pt_constant_pool,indice_constant_pool);

	// Verificando se classe a ser carregada não é de System.out
	if(!strcmp(name_field,"java/lang/System.out")) {
		free(name_field);
		return;
	}

	free(name_field);
}

void putstatic(stack_frames *pilha_frames) {

}

void getfield(stack_frames *pilha_frames) {

}

void putfield(stack_frames *pilha_frames) {

}

// TODO OBS: ESSA INSTRUÇÃO NÃO ESTÁ TODA IMPLEMENTADA! SÓ FOI FEITA A PARTE DO PRINT
void invokevirtual(stack_frames *pilha_frames) {
	// Ponteiro para frame para facilitar acesso
	t_frame *frame = pilha_frames->first;

	// Indice do método na constant pool
	u2 indice_metodo = operando_u2(frame->code_info->code,frame->pc);

	// Acessa constant pool por meio de indice_metodo e encontra o índice de name_and_type_info
	u2 indice_nome_tipo = frame->pt_constant_pool[indice_metodo].info.methodref_info.name_and_type_index;

	// Descobre o índice para a string do descritor do método
	u2 indice_descritor = frame->pt_constant_pool[indice_nome_tipo].info.name_and_type_info.descriptor_index;
	char *nome_metodo;
	char *descritor_metodo;


	// Incrementa pc para a próxima instrução
	frame->pc += 2;

	// Recupera nome do método para checar se é o print
	nome_metodo = recupera_elemento_como_string_constant_pool(frame->pt_constant_pool,indice_metodo);

	// Recupera descritor para (caso seja o System.out.print) saber o tipo do
	// elemento que será impresso
	descritor_metodo = recupera_utf8(frame->pt_constant_pool,indice_descritor);

	// Descobre se o método é de imprimir na tela
	if((!strcmp(nome_metodo,"java/io/PrintStream.println"))||(!strcmp(nome_metodo,"java/io/PrintStream.print"))) {
		// Recupera o primeiro operando da operand_stack
		t_operand *operando_1 = pop_operando(frame->operand_stack);

		// Elemento a ser impresso é um inteiro
		if(!strcmp(descritor_metodo,"(I)V")) {
			printf("\n%d",operando_1->data);
		}

		// Elemento a ser impresso é um float
		else if (!strcmp(descritor_metodo,"(F)V")) {
			printf("\n%f",u4_to_float(operando_1->data));
		}

		// Elemento a ser impresso é um long
		else if (!strcmp(descritor_metodo,"(J)V")) {
			t_operand *operando_2 =  pop_operando(frame->operand_stack);
			printf("\n%li",u8_to_long(operando_1->data,operando_2->data));

			free(operando_2);
		}

		// Elemento a ser impresso é um double
		else if (!strcmp(descritor_metodo,"(D)V")) {
			t_operand *operando_2 =  pop_operando(frame->operand_stack);
			printf("\n%f",u8_to_double(operando_1->data,operando_2->data));

			free(operando_2);
		}

		// Elemento a ser impresso é um char
		else if (!strcmp(descritor_metodo,"(C)V")) {
			printf("\n%c",operando_1->data);
		}

		// Elemento a ser impresso é uma string
		else if (!strcmp(descritor_metodo,"(Ljava/lang/String;)V")) {
			printf("\n%s",recupera_elemento_como_string_constant_pool(frame->pt_constant_pool,operando_1->data));
		}

		free(nome_metodo);
		free(descritor_metodo);
		free(operando_1);
		return;
	}

	free(nome_metodo);
	free(descritor_metodo);
}

void invokespecial(stack_frames *pilha_frames) {

}

void invokestatic(stack_frames *pilha_frames) {

}

void invokeinterface(stack_frames *pilha_frames) {

}

void unused(stack_frames *pilha_frames) {

}

void new_(stack_frames *pilha_frames) {

}

void newarray(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u8 endereco;

	// Essa instrução cria arrays de dimensão 1
	u1 dimensao = 1;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);

	// Tamanho do array está na pilha de operandos
	u4 tamanho_array = operando->data;

	// Tag que indica o tipo do array está no code
	u1 tag = frame->code_info->code[frame->pc];


	t_array *array = criar_array(tag,tamanho_array,dimensao);


	// Incremento do pc
	frame->pc++;

	endereco = (u4)(array);

	// Empilha endereço do array
	push_operando(TAG_ARRAY_REF,endereco,frame->operand_stack);

	free(operando);
}

void anewarray(stack_frames *pilha_frames) {

}

void arraylength(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando do endereço do array
	t_operand *operando = pop_operando(frame->operand_stack);

	// Carrega array
	t_array *array = (t_array*)(operando->data);

	u4 length = array->tamanho;

	push_operando(TAG_INTEGER,length,frame->operand_stack);
}

void athrow(stack_frames *pilha_frames) {

}

void checkcast(stack_frames *pilha_frames) {

}

void instanceof(stack_frames *pilha_frames) {

}

void monitorenter(stack_frames *pilha_frames) {

}

void monitorexit(stack_frames *pilha_frames) {

}

void wide(stack_frames *pilha_frames) {
	wide_ = 1;
}

void multianewarray(stack_frames *pilha_frames) {
	u1 tag;
	t_frame *frame = pilha_frames->first;
	u2 class_index = operando_u2(frame->code_info->code,frame->pc);


	u1 dimensao = frame->code_info->code[frame->pc+2];
	frame->pc+=3;

	// nome da classe (necessária para descobrir o tipo do multiarray)
	char *class_name = recupera_class_name(frame->pt_constant_pool,class_index);

	// tag do último subarray (dimensão 1)
	tag = tipo_multiarray(class_name,dimensao);

	u4 tamanho[dimensao];

	// Os tamanhos de cada dimensão do array são salvos em um vetor.
	for(u1 i=0; i<dimensao; i++) {
		// Retira-se cada tamanho dos operandos salvos na operand_stack
		t_operand *operando = pop_operando(frame->operand_stack);
		tamanho[i] = operando->data;

		// Desaloca operando desempilhado
		free(operando);
	}

	// Lista de ponteiros do tamanho da maior dimensão do multiarray que
	// será usada para criar os diversos subarrays do multiarray;
	t_array *subarray[dimensao];

	// array será o ponteiro para o multiarray
	t_array *array = criar_array(ARRAY_ARRAY,tamanho[dimensao-1],dimensao);
	subarray[dimensao-1] = array;

	// Cria cada subarray do multiarray
	for_array_multidimensional(dimensao-1,tamanho,subarray,tag);

	// Empilha endereço do array
	push_operando(TAG_ARRAY_REF,(u4)array,frame->operand_stack);
}

void ifnull(stack_frames *pilha_frames) {

}

void ifnonnull(stack_frames *pilha_frames) {

}

void goto_w(stack_frames *pilha_frames) {

}

void jsr_w(stack_frames *pilha_frames) {

}

void breakpoint(stack_frames *pilha_frames) {

}
