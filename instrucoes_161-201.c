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
	t_frame *frame = pilha_frames->first;
	tipo_int comp_1, comp_2;

	
	t_operand *temp_operando2 = pop_operando(frame->operand_stack);
	
	if(temp_operando2->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		free(temp_operando2);
		return;
	}
	comp_2 = (int)temp_operando2->data;

	
	t_operand *temp_operando1 = pop_operando(frame->operand_stack);
	
	if(temp_operando2->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		free(temp_operando1);
		free(temp_operando2);
		return;
	}
	comp_1 = (int)temp_operando1->data;

	
	if(comp_1 < comp_2){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		frame->pc = frame->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operandos que foram desempilhados
	free(temp_operando1);
	free(temp_operando2);
}

void if_icmpge(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_1, comp_2;

	t_operand *temp_operando2 = pop_operando(frame->operand_stack);
	
	if(temp_operando2->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		free(temp_operando2);
		return;
	}
	comp_2 = (int)temp_operando2->data;

	
	t_operand *temp_operando1 = pop_operando(frame->operand_stack);
	
	if(temp_operando2->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		free(temp_operando1);
		free(temp_operando2);
		return;
	}
	comp_1 = (int)temp_operando1->data;
	

	if(comp_1 >= comp_2){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		frame->pc = frame->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operandos que foram desempilhados
	free(temp_operando1);
	free(temp_operando2);
}

void if_icmpgt(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_1, comp_2;

	t_operand *temp_operando2 = pop_operando(frame->operand_stack);
	
	if(temp_operando2->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		free(temp_operando2);
		return;
	}
	comp_2 = (int)temp_operando2->data;

	
	t_operand *temp_operando1 = pop_operando(frame->operand_stack);
	
	if(temp_operando2->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		free(temp_operando1);
		free(temp_operando2);
		return;
	}
	comp_1 = (int)temp_operando1->data;

	if(comp_1 > comp_2){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		frame->pc = frame->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operandos que foram desempilhados
	free(temp_operando1);
	free(temp_operando2);
}

void if_icmple(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_1, comp_2;

	t_operand *temp_operando2 = pop_operando(frame->operand_stack);
	
	if(temp_operando2->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		free(temp_operando2);
		return;
	}
	comp_2 = (int)temp_operando2->data;

	
	t_operand *temp_operando1 = pop_operando(frame->operand_stack);
	
	if(temp_operando2->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		free(temp_operando1);
		free(temp_operando2);
		return;
	}
	comp_1 = (int)temp_operando1->data;

	if(comp_1 <= comp_2){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		frame->pc = frame->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;
	
	// desaloca operando que foi desempilhado
	free(temp_operando1);
	free(temp_operando2);
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
	t_frame *frame = pilha_frames->first;
  
	int16_t offset_16bit = (int16_t)operando_u2(frame->code_info->code,frame->pc)-1;
	
	//adiciona offset ao valor de pc
	pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
}

void jsr(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
  
	int16_t offset_16bit = (int16_t)operando_u2(frame->code_info->code,frame->pc)-1;
	
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
	t_frame *frame = pilha_frames->first;
	u1 *code = frame->code_info->code;
  
	u4 index = frame->pc;
	u1 alinhamento = index % 4;
	int32_t i;
	int32_t offset_default;
	int32_t offset;
	int32_t indice_inferior;
	int32_t indice_superior;
	
	// Quantidade de bytes que procedem o opcode de table switch
	switch(alinhamento) {
		case 1: index+=3; break;
		case 2: index+=2; break;
		case 3: index+=1; break;
	}
	
	// Recupera o offset do default
	offset_default = operando_u4(code,index);

	// Atualiza o valor de index
	index+=4;

	// Recupera o índice inferior do switch
	indice_inferior = operando_u4(code,index);
	index+=4;

	// Recupera o índice superior do switch
	indice_superior = operando_u4(code,index);
	index+=4;
	
	
	t_operand *operando = pop_operando(frame->operand_stack);
	
	// Percorre o code até terminar o switch ou o case ser igual ao operando
	for(i=indice_inferior; i<=indice_superior; i++) {
		offset = (int32_t)operando_u4(code,index);
		if((operando->data)==i) {
			frame->pc += offset-1;
			break;
		} 
		index+=4;
	}
	if (i>indice_superior) frame->pc += offset_default-1;
	
	free(operando);
	
}

void lookupswitch(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	u1 *code = frame->code_info->code;
  
	u4 index = frame->pc;
	u1 alinhamento = index % 4;
	int32_t i;
	int32_t offset_default;
	int32_t offset;
	int32_t pair;
	int32_t npairs;

	// Quantidade de bytes que procedem o opcode de lookup switch
	switch(alinhamento) {
		case 1: index+=3; break;
		case 2: index+=2; break;
		case 3: index+=1; break;
	}
	
	offset_default = operando_u4(code,index);
	index+=4;

	npairs = operando_u4(code,index);
	index+=4;
	
	t_operand *operando = pop_operando(frame->operand_stack);
	
	for(i=0; i<npairs; i++) {
		pair = (int32_t)operando_u4(code,index);
		index+=4;
		offset = (int32_t)operando_u4(code,index);
		index+=4;

		if(operando->data==pair) {
			frame->pc += offset-1;
			break;
		}
	}
	if(i==npairs) frame->pc += offset_default-1;
	
	free(operando);
	
}

void ireturn(stack_frames *pilha_frames) {
	//desempilha value da operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	
	if (temp_operando->tag!=TAG_INTEGER) {
		printf("\nErro: Tipo invalido (esperado: int) \n");
		excecao = true;
		
		// desaloca operando que foi desempilhado
		free(temp_operando);
		return;
	}
	
	u4 value = temp_operando->data;

	pop_frame(pilha_frames);

	//adicionar tipo de value empilhado
	push_operando(temp_operando->tag, value,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void lreturn(stack_frames *pilha_frames) {
	
	t_operand *temp_operando_low = pop_operando(pilha_frames->first->operand_stack);
	t_operand *temp_operando_high = pop_operando(pilha_frames->first->operand_stack);
	
	
	if((temp_operando_low->tag!=TAG_LONG)||(temp_operando_high->tag!=TAG_LONG)) {
		printf("\nErro: Tipo invalido (esperado: long) \n");
		excecao = true;
		free(temp_operando_low);
		free(temp_operando_high);
		return;
	}
	
	u4 value_1 = temp_operando_low->data;
	u1 tag_1 = temp_operando_low->tag;
	
	u4 value_2 = temp_operando_high->data;
	u1 tag_2 = temp_operando_high->tag;

	pop_frame(pilha_frames);

	//adicionar tipo de value empilhado
	push_operando(tag_2, value_2,pilha_frames->first->operand_stack);
	//adicionar tipo de value empilhado
	push_operando(tag_1, value_1,pilha_frames->first->operand_stack);

	// desaloca operando que foram desempilhados
	free(temp_operando_low);
	free(temp_operando_high);
}

void freturn(stack_frames *pilha_frames) {
	//desempilha value da operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	
	if (temp_operando->tag!=TAG_FLOAT) {
		printf("\nErro: Tipo invalido (esperado: float) \n");
		excecao = true;
		
		// desaloca operando que foi desempilhado
		free(temp_operando);
		return;
	}
	
	u4 value = temp_operando->data;
	u1 tag = temp_operando->tag;

	pop_frame(pilha_frames);

	//adicionar tipo de value empilhado
	push_operando(tag, value,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void dreturn(stack_frames *pilha_frames) {
	//desempilha value da operand stack

	t_operand *temp_operando_low = pop_operando(pilha_frames->first->operand_stack);
	t_operand *temp_operando_high = pop_operando(pilha_frames->first->operand_stack);
	
	if((temp_operando_low->tag!=TAG_DOUBLE)||(temp_operando_high->tag!=TAG_DOUBLE)) {
		printf("\nErro: Tipo invalido (esperado: double) \n");
		excecao = true;
		free(temp_operando_low);
		free(temp_operando_high);
		return;
	}
	
	u4 value_1 = temp_operando_low->data;
	u1 tag_1 = temp_operando_low->tag;
	
	u4 value_2 = temp_operando_high->data;
	u1 tag_2 = temp_operando_high->tag;

	pop_frame(pilha_frames);

	//adicionar tipo de value empilhado
	push_operando(tag_2, value_2,pilha_frames->first->operand_stack);
	//adicionar tipo de value empilhado
	push_operando(tag_1, value_1,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando_low);
	free(temp_operando_high);
}

void areturn(stack_frames *pilha_frames) {
	//referência de objeto
	//desempilha value da operand stack
	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	
	u4 object_ref = temp_operando->data;
	u1 tag = temp_operando->tag;

	pop_frame(pilha_frames);

	//adicionar tipo de value empilhado
	push_operando(tag, object_ref, pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void return_(stack_frames *pilha_frames) {
	pop_frame(pilha_frames);
}


void getstatic(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Processo para recuperar nome da classe, nome do field e descritor.
	u2 field_index = operando_u2(frame->code_info->code,frame->pc);
	u2 class_index = frame->pt_constant_pool[field_index].info.fieldref_info.class_index;
	u2 name_and_type_index = frame->pt_constant_pool[field_index].info.fieldref_info.name_and_type_index;
	u2 field_name_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.name_index;
	u2 descriptor_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.descriptor_index;
	
	
	char *class_name = recupera_class_name(frame->pt_constant_pool,class_index);
	char *field_name = recupera_utf8(frame->pt_constant_pool,field_name_index);
	char *descriptor = recupera_utf8(frame->pt_constant_pool,descriptor_index);
	

	// Incrementa pc para a próxima instrução
	frame->pc += 2;

	// Verificando se classe a ser carregada não é de System.out
	if((!strcmp(class_name,"java/lang/System"))&&(!strcmp(field_name,"out"))) {
		free(class_name);
		free(field_name);
		free(descriptor);
		return;
	} 
			
	class_file *classe = busca_classe(class_name,lista_classes);
	t_field *field = NULL;
	
	if(classe!=frame->this_class) {
		field = busca_field_classe_estatica(classe,frame,class_name,field_name,descriptor);
	} else {
		field = busca_field(frame->lista_fields,
					     frame->this_class->fields_count,
					     frame->pt_constant_pool,
					     field_name,
					     descriptor);
	}
	if(field) {
		u4 value;
			
		switch(field->tag) {
			case TAG_UTF8: value = field->field_data; break; 
			case TAG_INTEGER: value = field->field_data; break;
			case TAG_FLOAT: value = field->field_data; break;
			case TAG_OBJECT_REF: value = (u4)field->field_data; break;
			case TAG_ARRAY_REF: value = (u4)field->field_data; break;
			case TAG_LONG: {
				value = field->field_data;
				u4 value_high = (field->field_data>>32);
				push_operando(field->tag,value_high,frame->operand_stack);
				
				break;
			}
			case TAG_DOUBLE: {
				value = field->field_data; 
				u4 value_high = (field->field_data>>32);
				push_operando(field->tag,value_high,frame->operand_stack);
				break;
			}
			default: {
				printf("\nErro (getstatic): tag desconhecida\n");
				excecao = true;
				return;
			}
		}
			
		push_operando(field->tag,value,frame->operand_stack);
		
	} 

	free(class_name);
	free(field_name);
	free(descriptor);
}

void putstatic(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	t_operand *operando = pop_operando(frame->operand_stack);
	
	u4 value = operando->data;
	
	// Processo para recuperar nome da classe, nome do field e descritor.
	u2 field_index = operando_u2(frame->code_info->code,frame->pc);
	u2 class_index = frame->pt_constant_pool[field_index].info.fieldref_info.class_index;
	
	
	u2 name_and_type_index = frame->pt_constant_pool[field_index].info.fieldref_info.name_and_type_index;
	
	u2 field_name_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.name_index;
	u2 descriptor_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.descriptor_index;
	
	
	char *class_name = recupera_class_name(frame->pt_constant_pool,class_index);
	char *field_name = recupera_utf8(frame->pt_constant_pool,field_name_index);
	char *descriptor = recupera_utf8(frame->pt_constant_pool,descriptor_index);
	
	frame->pc += 2;
	
	class_file *classe = busca_classe(class_name,lista_classes);

	t_field *field = NULL;
	
	
	if(classe!=frame->this_class) {
		field = busca_field_classe_estatica(classe,frame,class_name,field_name,descriptor);
	} else {
		field = busca_field(frame->lista_fields,
					     frame->this_class->fields_count,
					     frame->pt_constant_pool,
					     field_name,
					     descriptor);
	}
	
	if(field) {
		u2 tag = tipo_descritor(descriptor);
		field->tag = tag;
		switch(tag) {
			case TAG_UTF8: field->field_data = value; break; 
			case TAG_INTEGER: field->field_data = value; break;
			case TAG_FLOAT: field->field_data = value; break;
			case TAG_OBJECT_REF: field->field_data = value; break;
			case TAG_ARRAY_REF: field->field_data = value; break;
			case TAG_LONG: {
				t_operand *operando_high = pop_operando(frame->operand_stack);
				field->field_data = (value|((((u8)operando_high->data)<<32)));
				break;
			}
			case TAG_DOUBLE: {
				t_operand *operando_high = pop_operando(frame->operand_stack);
				field->field_data = (value|((((u8)operando_high->data)<<32))); 
				break;
			}
			default: {
				printf("\nErro (putstatic): tag desconhecida\n");
				excecao = true;
				return;
			}
		}
	}
	
	free(operando);
	free(class_name);
	free(field_name);
	free(descriptor);
}

void getfield(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Processo para recuperar nome da classe, nome do field e descritor.
	u2 field_index = operando_u2(frame->code_info->code,frame->pc);
	u2 name_and_type_index = frame->pt_constant_pool[field_index].info.fieldref_info.name_and_type_index;
	u2 field_name_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.name_index;
	u2 descriptor_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.descriptor_index;
	
	
	char *field_name = recupera_utf8(frame->pt_constant_pool,field_name_index);
	char *descriptor = recupera_utf8(frame->pt_constant_pool,descriptor_index);
	
	frame->pc+=2;
	
	// Pega operando que guarda o endereço do objeto
	t_operand *operando_objeto = pop_operando(frame->operand_stack);
	
	// Recupera-se o objeto usando o endereço
	t_objeto *objeto = (t_objeto*)operando_objeto->data;
	
	
	// Busca-se o field que se deseja recuperar
	t_field *field = busca_field(objeto->lista_fields,
				     objeto->tamanho_lista_fields,
				     objeto->pt_classe->constant_pool,
				     field_name,descriptor);
	
	u2 tag = tipo_descritor(descriptor);
	
	// Caso seja double, deve-se fazer dois empilhamentos.
	if ((tag==TAG_DOUBLE)||(tag==TAG_LONG)) {
		push_operando(tag,field->field_data>>32,frame->operand_stack);
	}
	
	push_operando(tag,field->field_data,frame->operand_stack);

	// Desaloca-se o operando que foi desempilhado
	free(operando_objeto);
}

void putfield(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Processo para recuperar nome da classe, nome do field e descritor.
	u2 field_index = operando_u2(frame->code_info->code,frame->pc);
	u2 name_and_type_index = frame->pt_constant_pool[field_index].info.fieldref_info.name_and_type_index;
	u2 field_name_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.name_index;
	u2 descriptor_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.descriptor_index;
	
	char *field_name = recupera_utf8(frame->pt_constant_pool,field_name_index);
	char *descriptor = recupera_utf8(frame->pt_constant_pool,descriptor_index);
	
	frame->pc+=2;
	
	
	// Recupera-se o valor que será colocado no field
	t_operand *operando_value = pop_operando(frame->operand_stack);
	u8 value = operando_value->data;
	
	u2 tag = tipo_descritor(descriptor);
	
	// Caso seja double ou long, deve-se desempilhar operando mais de uma vez
	if ((tag==TAG_DOUBLE)||(tag==TAG_LONG)) {
		t_operand *operando_value_high = pop_operando(frame->operand_stack);
		value |= (((u8)operando_value_high->data)<<32);
	}
	
	// Desempilha-se o endereço do objeto
	t_operand *operando_objeto = pop_operando(frame->operand_stack);

	// Recupera-se o objeto com o endereço desempilhado.
	t_objeto *objeto = (t_objeto*)operando_objeto->data;
	
	// Busca-se o field
	t_field *field = busca_field(objeto->lista_fields,
				     objeto->tamanho_lista_fields,
				     objeto->pt_classe->constant_pool,
				     field_name,descriptor);
	
	// Field recebe o valor desempilhado da operand stack
	field->field_data = value;
	
	// Desalocando operando desempilhados
	free(operando_value);
	free(operando_objeto);
}


void invokevirtual(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Recuperando índices para obter o nome da classe, método e descritor
	u2 methodref_index = operando_u2(frame->code_info->code,frame->pc);
	u2 class_index = frame->pt_constant_pool[methodref_index].info.methodref_info.class_index;
	u2 name_and_type_index = frame->pt_constant_pool[methodref_index].info.methodref_info.name_and_type_index;
	u2 method_name_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.name_index;
	u2 descriptor_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.descriptor_index;
	
	char *class_name = recupera_class_name(frame->pt_constant_pool,class_index);
	char *method_name = recupera_utf8(frame->pt_constant_pool,method_name_index);
	char *descriptor = recupera_utf8(frame->pt_constant_pool,descriptor_index);

	frame->pc+=2;
	
	// Descobre se o método é de imprimir na tela
	if(!strcmp(class_name,"java/io/PrintStream")) {
		if(frame->operand_stack->first) {
			// Recupera o primeiro operando da operand_stack
			t_operand *operando_1 = pop_operando(frame->operand_stack);

			// Elemento a ser impresso é um inteiro
			if(!strcmp(descriptor,"(I)V")) {
				printf("\n%d",operando_1->data);
			}

			// Elemento a ser impresso é um float
			else if (!strcmp(descriptor,"(F)V")) {
				printf("\n%f",u4_to_float(operando_1->data));
			}

			// Elemento a ser impresso é um long
			else if (!strcmp(descriptor,"(J)V")) {
				t_operand *operando_2 =  pop_operando(frame->operand_stack);
				printf("\n%li",u8_to_long(operando_1->data,operando_2->data));

				free(operando_2);
			}

			// Elemento a ser impresso é um double
			else if (!strcmp(descriptor,"(D)V")) {
				t_operand *operando_2 =  pop_operando(frame->operand_stack);
				printf("\n%f",u8_to_double(operando_1->data,operando_2->data));

				free(operando_2);
			}
			
			// Elemento a ser impresso é um boolean
			else if(!strcmp(descriptor,"(Z)V")) {
				if((operando_1->data)==true) printf("\ntrue");
				else printf("\nfalse");
			}

			// Elemento a ser impresso é um char
			else if (!strcmp(descriptor,"(C)V")) {
				printf("\n%c",operando_1->data);
			}

			// Elemento a ser impresso é uma string
			else if (!strcmp(descriptor,"(Ljava/lang/String;)V")) {
				printf("\n%s",recupera_elemento_como_string_constant_pool(frame->pt_constant_pool,operando_1->data));
			}

			free(class_name);
			free(method_name);
			free(descriptor);
			free(operando_1);
		} else {
			printf("\n");
		}
		return;
	}
	
	t_parameter_stack *pilha_parametros = carregar_parameter_stack(descriptor,frame->operand_stack);
	
	t_operand *operando = pop_operando(frame->operand_stack);
		
	t_objeto *objeto = (t_objeto*)operando->data;
	
	method_info *method = recupera_metodo(&(objeto->pt_classe),method_name,descriptor);
	
	if (pilha_parametros==NULL) pilha_parametros = alocar_parameter_stack(TAG_OBJECT_REF,(u4)objeto);
	else push_parametro(TAG_OBJECT_REF,(u4)objeto,pilha_parametros);
	
	push_frame(objeto->pt_classe,
		   objeto->classes_estaticas,
		   objeto->lista_fields,
		   pilha_parametros,method,
		   objeto->pt_classe->constant_pool,
		   pilha_frames);

	free(class_name);
	free(method_name);
	free(descriptor);
}

void invokespecial(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Recuperando índices para obter o nome da classe, método e descritor
	u2 methodref_index = operando_u2(frame->code_info->code,frame->pc);
	u2 class_index = frame->pt_constant_pool[methodref_index].info.methodref_info.class_index;
	u2 name_and_type_index = frame->pt_constant_pool[methodref_index].info.methodref_info.name_and_type_index;
	u2 method_name_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.name_index;
	u2 descriptor_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.descriptor_index;
	
	char *class_name = recupera_class_name(frame->pt_constant_pool,class_index);
	char *method_name = recupera_utf8(frame->pt_constant_pool,method_name_index);
	char *descritor = recupera_utf8(frame->pt_constant_pool,descriptor_index);
	
	frame->pc+=2;
	
	t_objeto *objeto = NULL;
	t_operand *operando = NULL;
	
	if(!strcmp(class_name,"java/lang/Object")) {
		return;
	}
	
	if(!strcmp(method_name,"<init>")) {
		//Declara elementos para um novo frame
		t_parameter_stack *pilha_parametros_init = carregar_parameter_stack(descritor,frame->operand_stack);
		
		operando = pop_operando(frame->operand_stack);
		
		objeto = (t_objeto*)operando->data;
		
		method_info *method_clinit = recupera_metodo(&(objeto->pt_classe),"<clinit>","()V");
		if(method_clinit!=NULL) {
			t_parameter_stack *pilha_parametros_clnit = alocar_parameter_stack(TAG_OBJECT_REF,(u4)(objeto->pt_classe));
		
			push_frame(objeto->pt_classe,objeto->classes_estaticas,objeto->lista_fields,
				    pilha_parametros_clnit,method_clinit,objeto->pt_classe->constant_pool,
				   pilha_frames);
		}
		
		if (pilha_parametros_init==NULL) pilha_parametros_init = alocar_parameter_stack(TAG_OBJECT_REF,(u4)objeto);
		else push_parametro(TAG_OBJECT_REF,(u4)objeto,pilha_parametros_init);
		
		method_info *method_init = recupera_metodo(&(objeto->pt_classe),method_name,descritor);

		push_frame(objeto->pt_classe,objeto->classes_estaticas,objeto->lista_fields,
				    pilha_parametros_init,method_init,objeto->pt_classe->constant_pool,
				   pilha_frames);
		
		return;
	}
	
	class_file *classe = busca_classe(class_name,lista_classes);
	
	//Caso em que invoca metodo private
	if(classe==frame->this_class) {
		t_parameter_stack *pilha_parametros = carregar_parameter_stack(descritor,frame->operand_stack);
	
		operando = pop_operando(frame->operand_stack);
		objeto = (t_objeto*)operando->data; 
		
		method_info *metodo = recupera_metodo(&(objeto->pt_classe),method_name,descritor);
		
		push_frame(objeto->pt_classe,objeto->classes_estaticas,objeto->lista_fields,
				    pilha_parametros,metodo,objeto->pt_classe->constant_pool,
				   pilha_frames);
		
	} else printf("\nTentativa de acesso ilegal a metodo private\n");
	
	free(operando);
}

void invokestatic(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Recuperando índices para obter o nome da classe, método e descritor
	u2 methodref_index = operando_u2(frame->code_info->code,frame->pc);
	u2 class_index = frame->pt_constant_pool[methodref_index].info.methodref_info.class_index;
	u2 name_and_type_index = frame->pt_constant_pool[methodref_index].info.methodref_info.name_and_type_index;
	u2 method_name_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.name_index;
	u2 descriptor_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.descriptor_index;
	
	char *class_name = recupera_class_name(frame->pt_constant_pool,class_index);
	char *method_name = recupera_utf8(frame->pt_constant_pool,method_name_index);
	char *descritor = recupera_utf8(frame->pt_constant_pool,descriptor_index);
	
	class_file *classe = busca_classe(class_name,lista_classes);
	 
	cp_info *constant_pool = classe->constant_pool;
	
	t_field *lista_fields = NULL;
	lista_classes_estaticas *classes_estaticas = NULL;
	

	
	// Verifica se a pilha de operandos está vazia ou se o primeiro elemento 
	//é uma referência a objeto.
	if((frame->operand_stack->first==NULL)||(frame->operand_stack->first->tag!=TAG_OBJECT_REF)) {
		if(frame->this_class!=classe) {
			classe_estatica *elemento_lista_classes_estaticas = 
				 busca_classe_estatica (classe,frame->classes_estaticas->first);
			
			if(!elemento_lista_classes_estaticas) {
				classes_estaticas = alocar_lista_classes_estaticas();
			}
			else {
				classes_estaticas = elemento_lista_classes_estaticas->classes_estaticas;
			}
			
		} else {
			//Caso seja a mesma classe, mantém os fields e classes estáticas para o próximo frame
			lista_fields = frame->lista_fields;
			classes_estaticas = frame->classes_estaticas;
		}
	} else {
		//TODO: caso seja um objeto
	}
	
	method_info *metodo = recupera_metodo(&classe,method_name,descritor);
	
	t_parameter_stack *pilha_parametros = carregar_parameter_stack(descritor,frame->operand_stack);
	
	push_frame(classe,classes_estaticas,lista_fields,pilha_parametros,metodo,constant_pool,pilha_frames);
	
	frame->pc += 2;
	
	free(class_name);
	free(method_name);
	free(descritor);

}

void invokeinterface(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Recuperando índices para obter o nome da classe, método e descritor
	u2 methodref_index = operando_u2(frame->code_info->code,frame->pc);
	u2 name_and_type_index = frame->pt_constant_pool[methodref_index].info.methodref_info.name_and_type_index;
	u2 method_name_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.name_index;
	u2 descriptor_index = frame->pt_constant_pool[name_and_type_index].info.name_and_type_info.descriptor_index;
	
	char *method_name = recupera_utf8(frame->pt_constant_pool,method_name_index);
	char *descritor = recupera_utf8(frame->pt_constant_pool,descriptor_index);
	
	frame->pc+=4;
	
	t_operand *operando = pop_operando(frame->operand_stack);
	
	t_objeto *objeto = (t_objeto*)operando->data;
	
	method_info *method = recupera_metodo(&(objeto->pt_classe),method_name,descritor);
	
	t_parameter_stack *pilha_parametros = carregar_parameter_stack(descritor,frame->operand_stack);
	
	if (pilha_parametros==NULL) {
	  pilha_parametros = alocar_parameter_stack(TAG_OBJECT_REF,(u4)objeto);
	}
	else push_parametro(TAG_OBJECT_REF,(u4)objeto,pilha_parametros);
	
	push_frame(objeto->pt_classe,
		   objeto->classes_estaticas,
		   objeto->lista_fields,
		   pilha_parametros,method,
		   objeto->pt_classe->constant_pool,
		   pilha_frames);
}

void unused(stack_frames *pilha_frames) {

}

void new_(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	u2 class_index = operando_u2(frame->code_info->code,frame->pc);
	
	char *class_name = recupera_class_name(frame->pt_constant_pool,class_index);
	
	class_file *classe = busca_classe(class_name,lista_classes);
	
	t_objeto *objeto = novo_objeto(classe);
	if(objeto->pt_classe==frame->this_class) {
		free(objeto->lista_fields);
		objeto->lista_fields = frame->lista_fields;
	}
	
	push_operando(TAG_OBJECT_REF, (u4)objeto, frame->operand_stack);

	frame->pc+=2;
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
	t_frame *frame = pilha_frames->first;
	
	u2 class_index = operando_u2(frame->code_info->code,frame->pc);
	
	char *class_name = recupera_class_name(frame->pt_constant_pool,class_index);
	
	u2 dimensao = 0;
	while(class_name[dimensao]=='[') dimensao++;
	
	frame->pc+=2;
	
	t_operand *operando = pop_operando(frame->operand_stack);
	u2 tamanho_array = operando->data;
		
	t_array *array = criar_array(ARRAY_ARRAY,tamanho_array,dimensao);
	
	push_operando(TAG_ARRAY_REF,(u4)array,frame->operand_stack);

	free(operando);
	
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

	// Os tamanhos de cada dimensão do array são salvos em um vetor.
	u4 tamanho[dimensao];

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
	t_frame *frame = pilha_frames->first;
  
	t_operand *operando = pop_operando(frame->operand_stack);
	
	if(operando->data==0) {
		int16_t offset_16bit = (int16_t)operando_u2(frame->code_info->code,frame->pc)-1;
		
		//adiciona offset ao valor de pc
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
	} else frame->pc+=2;
}

void ifnonnull(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
  
	t_operand *operando = pop_operando(frame->operand_stack);
	
	if(operando->data!=0) {
		int16_t offset_16bit = (int16_t)operando_u2(frame->code_info->code,frame->pc)-1;
		
		//adiciona offset ao valor de pc
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_16bit;
	} else frame->pc+=2;
}

void goto_w(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
  
	int32_t offset_32bit = (int32_t)operando_u4(frame->code_info->code,frame->pc)-1;
	
	//adiciona offset ao valor de pc
	pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_32bit;
}

void jsr_w(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
  
	int32_t offset_32bit = (int32_t)operando_u4(frame->code_info->code,frame->pc)-1;
	
	//adiciona offset ao valor de pc
	pilha_frames->first->pc = pilha_frames->first->pc + (tipo_int)offset_32bit;

}

void breakpoint(stack_frames *pilha_frames) {

}
