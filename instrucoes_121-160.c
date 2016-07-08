/*!
   \file instrucoes_121-160.c
   \brief Instruções da Máquina Virtual Java.

   Módulo responsável por parte das instruções que definem as operações a serem
   executadas pela JVM.

   \author Alisson Carvalho                 12/0072521
   \author Ana Carolina Lopes               11/0107578
   \author Géssica Neves Sodré da Silva     11/0146115
   \author Ivan Sena                        10/0088031
   \author Laís Mendes Gonçalves            11/0033647
*/

#include "instrucoes_121-160.h"

void lshl(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Tamanho do shift
	t_operand *operando2 = pop_operando(frame->operand_stack);


	// Número que sofrerá shift
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	int operando2_int;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_int = (int32_t) (operando2->data);

	// Realiza shift
	resultado = operando1_long<<operando2_int;

	// Armazena resultado do shift na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2);
}

void ishr(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Tamanho do shift
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Número a ser shiftado
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de shift
	resultado = operando1_int>>operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void lshr(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Tamanho do shift
	t_operand *operando2 = pop_operando(frame->operand_stack);


	// Número que sofrerá shift
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	int operando2_int;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_int = (int32_t) (operando2->data);

	// Realiza shift
	resultado = operando1_long>>operando2_int;

	// Armazena resultado do shift na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2);
}

void iushr(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Tamanho do shift
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Número a ser shiftado
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando2_int;
	u4 resultado;

	// Transforma o operando do tamanho do shift em int
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de shift no inteiro unsigned
	resultado = (operando1->data)>>operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void lushr(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Tamanho do shift
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Número que sofrerá shift
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	unsigned long operando1_ulong;
	long operando2_int;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_ulong = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_int = (int32_t) (operando2->data);

	// Realiza shift
	resultado = operando1_ulong>>operando2_int;

	// Armazena resultado do shift na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2);
}

void iand(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de and
	resultado = operando1_int&operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void land(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	long operando2_long;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);

	// Realiza operação and
	resultado = operando1_long&operando2_long;

	// Armazena resultado do and na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void ior(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação or
	resultado = operando1_int|operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void lor(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	long operando2_long;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);

	// Realiza operação or
	resultado = operando1_long|operando2_long;

	// Armazena resultado do or na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void ixor(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2 = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1 = pop_operando(frame->operand_stack);

	int operando1_int;
	int operando2_int;
	u4 resultado;

	// Transforma os operandos em ints
	operando1_int = (int32_t)operando1->data;
	operando2_int = (int32_t)operando2->data;

	// Realiza operação de xor
	resultado = operando1_int^operando2_int;

	// Armazena o resultado na pilha de operandos
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}

void lxor(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera segundo operando
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);

	// Recupera primeiro operando
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);

	long operando1_long;
	long operando2_long;
	u8 resultado;

	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);

	// Realiza operação xor
	resultado = operando1_long^operando2_long;

	// Armazena resultado do xor na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}

void iinc(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	int16_t incremento;
	u2 indice_variavel;

	if(!wide_) {
		 //Se wide não estiver setado, tanto o índice quanto o incremento terão 1byte

		//Recupera o índice
		indice_variavel = frame->code_info->code[pilha_frames->first->pc++];

		//Recupera o incremento
		incremento = (signed char) frame->code_info->code[pilha_frames->first->pc++];
	} else {
		//Se wide estiver setado, tanto o índice quanto o incremento terão 2bytes
		indice_variavel = operando_u2(frame->code_info->code,pilha_frames->first->pc++);
		incremento = (int16_t) operando_u2(frame->code_info->code,++pilha_frames->first->pc);
		pilha_frames->first->pc+=2;
		wide_ = 0;
	}
	// Realiza incremento
	frame->array_variaveis_locais[indice_variavel] += incremento;
	//printf("\n%d; %d",incremento,indice_variavel);
}

void i2l(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);
	long operando_long;
	u8 resultado;

	// Realiza conversão por meio de casting
	operando_long = (signed)operando->data;

	// Transforma long em um u8
	resultado = long_to_u8(operando_long);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_LONG, resultado>>32,frame->operand_stack);
	push_operando(TAG_LONG, resultado,frame->operand_stack);

	// Desaloca operando que foi desempilhado
	free(operando);
}

void i2f(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);
	float operando_float;
	u4 resultado;

	// Realiza conversão por meio de casting
	operando_float = (signed)operando->data;

	// Transforma float em um u4
	resultado = float_to_u4(operando_float);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_FLOAT, resultado,frame->operand_stack);

	// Desaloca operando que foi desempilhado
	free(operando);
}

void i2d(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);
	double operando_double;
	u8 resultado;

	// Realiza conversão por meio de casting
	operando_double = (signed)operando->data;

	// Transforma double em um u4
	resultado = double_to_u8(operando_double);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32,frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado,frame->operand_stack);

	// Desaloca operando que foi desempilhado
	free(operando);
}

void l2i(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operandos
	t_operand *operando_low = pop_operando(frame->operand_stack);
	t_operand *operando_high = pop_operando(frame->operand_stack);

	// Concatena high e low em um long
	long operando = u8_to_long(operando_low->data,operando_high->data);

	// Realiza conversão por meior de casting
	int resultado = (int) operando;

	// Armazena resultado na operand stack
	push_operando(TAG_INTEGER, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_low);
	free(operando_high);
}

void l2f(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operandos
	t_operand *operando_low = pop_operando(frame->operand_stack);
	t_operand *operando_high = pop_operando(frame->operand_stack);

	// Concatena high e low em um long
	long operando = u8_to_long(operando_low->data,operando_high->data);

	// Realiza conversão por meior de casting
	float resultado_float = (float) operando;

	u4 resultado = float_to_u4(resultado_float);

	// Armazena resultado na operand stack
	push_operando(TAG_FLOAT, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_low);
	free(operando_high);
}

void l2d(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operandos
	t_operand *operando_low = pop_operando(frame->operand_stack);
	t_operand *operando_high = pop_operando(frame->operand_stack);

	// Concatena high e low em um long
	long operando_long = u8_to_long(operando_low->data,operando_high->data);

	// Realiza conversão por meio de casting
	double operando_double = (double) operando_long;

	// Armazena resultado
	u8 resultado = double_to_u8(operando_double);

	// Armazena resultado na operand stack
	push_operando(TAG_DOUBLE, resultado>>32,frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado,frame->operand_stack);

	// Desaloca operandos que foram desempilhados
	free(operando_low);
	free(operando_high);
}

void f2i(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);
	float operando_float;
	int operando_int;
	u8 resultado;

	// Realiza conversão de u4 para float
	operando_float = u4_to_float(operando->data);

	// Realiza conversão para int por meio de casting
	operando_int = (int) operando_float;

	resultado = operando_int;

	// Armazena resultado na pilha de operandos
	push_operando(TAG_DOUBLE, resultado,frame->operand_stack);

	// Desaloca operando que foi desempilhado
	free(operando);
}

void f2l(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);
	float operando_float;
	long operando_long;
	u8 resultado;

	// Realiza conversão de u4 para float
	operando_float = u4_to_float(operando->data);

	// Realiza conversão para int por meio de casting
	operando_long = (long) operando_float;

	resultado = operando_long;

	// Armazena resultado na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32,frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado,frame->operand_stack);

	// Desaloca operando que foi desempilhado
	free(operando);
}

void f2d(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;

	// Recupera operando
	t_operand *operando = pop_operando(frame->operand_stack);
	double operando_double;
	float operando_float;
	u8 resultado;


	operando_float = u4_to_float(operando->data);
	operando_double = (double)operando_float;

	// Transforma double em um u4
	resultado = double_to_u8(operando_double);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_DOUBLE, resultado>>32,frame->operand_stack);
	push_operando(TAG_DOUBLE, resultado,frame->operand_stack);

	// Desaloca operando que foi desempilhado
	free(operando);
}

void d2i(stack_frames *pilha_frames) {
	u4 temp_low, temp_high;
	tipo_double temp_double;
	tipo_int temp_int;

	//desempilha low
	t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
	temp_low = operando_low->data;

	//detecção de erros
	if(operando_low->tag != TAG_DOUBLE){
		printf("Invalid operand type on double to int conversion");
		//insira função de erro aqui
	}

	//desempila high
	t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
	temp_high = operando_high->data;

	//organiza em big endian
	temp_double = u8_to_double(temp_low,temp_high);

	//conversão
	temp_int = double_to_int(temp_double);

	// empilha na pilha de operandos double convertido para inteiro
	push_operando(TAG_INTEGER, (u4)temp_int,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(operando_low);
	free(operando_high);
}

void d2l(stack_frames *pilha_frames) {
	u8 aux;
	u4 temp_low;
	u4 temp_high;
	tipo_long temp_long;
	tipo_double temp_double;

	//desempilha low
	t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
	temp_low = operando_low->data;

	//detecção de erros
	if(operando_low->tag != TAG_DOUBLE){
		printf("Invalid operand type on double to long conversion");
		//insira função de erro aqui
	}

	//desempila high
	t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
	temp_high = operando_high->data;

	//organiza em big endian
	temp_double = u8_to_double(temp_low,temp_high);

	//tranformação long para double com typecast
	temp_long = (tipo_long)temp_double;

	//empilha em big endian
	aux = long_to_u8(temp_long);

	// Armazena resultado na pilha de operandos
	push_operando(TAG_LONG, aux>>32,pilha_frames->first->operand_stack);
	push_operando(TAG_LONG, aux,pilha_frames->first->operand_stack);

	// desaloca o operando que foi desempilhado
	free(operando_low);
	free(operando_high);
}

void d2f(stack_frames *pilha_frames) {
	u4 temp_low, temp_high;
	tipo_double temp_double;
	tipo_float temp_float;

	//desempilha low
	t_operand *operando_low = pop_operando(pilha_frames->first->operand_stack);
	temp_low = operando_low->data;

	//detecção de erros
	if(operando_low->tag != TAG_DOUBLE){
		printf("Invalid operand type on double to float conversion");
		//insira função de erro aqui
	}

	//desempila high
	t_operand *operando_high = pop_operando(pilha_frames->first->operand_stack);
	temp_high = operando_high->data;

	//organiza em big endian
	temp_double = u8_to_double(temp_low,temp_high);

	temp_float = double_to_float(temp_double);

	//push
	push_operando(TAG_FLOAT, float_to_u4(temp_float),pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(operando_low);
	free(operando_high);
}

void i2b(stack_frames *pilha_frames) {
	u4 temp_byte;

	t_operand *temp_operando = NULL;

	//desempilha operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_byte = (int8_t)temp_operando->data;

	push_operando(TAG_INTEGER, temp_byte,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void i2c(stack_frames *pilha_frames) {
	char temp_char;

	t_operand *temp_operando = NULL;

	//desempilha operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_char = (char)temp_operando->data;

	push_operando(TAG_INTEGER, temp_char,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void i2s(stack_frames *pilha_frames) {
	u4 temp;
	t_operand *temp_operando = NULL;

	//desempilha operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp = (short)temp_operando->data;

	push_operando(TAG_INTEGER, temp,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void lcmp(stack_frames *pilha_frames) {
	long temp_long1;
	long temp_long2;
	u4 temp_low;
	u4 temp_high;

	t_operand *temp_operando1_low = NULL;
	t_operand *temp_operando1_high = NULL;
	t_operand *temp_operando2_low = NULL;
	t_operand *temp_operando2_high = NULL;

	//desempilha low long2
	temp_operando2_low = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando2_low->data;

	//desempila high long 2
	temp_operando2_high = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando2_high->data;


	temp_long2 = u8_to_long(temp_low,temp_high);

	//desempilha low long 1
	temp_operando1_low = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando1_low->data;

	//desempila high long 1
	temp_operando1_high = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando1_high->data;

	temp_long1 = u8_to_long(temp_low,temp_high);

	int n;
	if(temp_long1>temp_long2) n = 1;
	else if(temp_long1==temp_long2) n = 0;
	else n = -1;

	push_operando(TAG_INTEGER, n, pilha_frames->first->operand_stack);

	// desaloca operandos que foram desempilhados
	free(temp_operando1_high);
	free(temp_operando2_high);
	free(temp_operando1_low);
	free(temp_operando2_low);
}

void fcmpl(stack_frames *pilha_frames) {
	tipo_float temp_float1, temp_float2;

	//desempilha primeiro operando
	t_operand *operando_1 = pop_operando(pilha_frames->first->operand_stack);
	temp_float2 = u4_to_float(operando_1->data);

	//desempilha o segundo operando
	t_operand *operando_2 = pop_operando(pilha_frames->first->operand_stack);
	temp_float1 = u4_to_float(operando_2->data);

	// TODO falta fazer a comparação de not a number
	// se algum operando for NAN, empilha -1

	u4 n;
	if(temp_float1>temp_float2) n = 1;
	else if(temp_float1 == temp_float2) n = 0;
	else n = -1;

	push_operando(TAG_INTEGER, n, pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(operando_1);
	free(operando_2);
}

void fcmpg(stack_frames *pilha_frames) {
	tipo_float temp_float1,temp_float2;

	//desempilha primeiro operando
	t_operand *operando_1 = pop_operando(pilha_frames->first->operand_stack);
	temp_float2 = u4_to_float(operando_1->data);

	//desempilha o segundo operando
	t_operand *operando_2 = pop_operando(pilha_frames->first->operand_stack);
	temp_float1 = u4_to_float(operando_2->data);

	// TODO falta fazer a comparação de not a number
	// se algum operando for NAN, empilha 1

	u4 n;
	if(temp_float1>temp_float2) n = 1;
	else if(temp_float1 == temp_float2) n = 0;
	else n = -1;

	push_operando(TAG_INTEGER, n,pilha_frames->first->operand_stack);

	// desaloca operando que foi desempilhado
	free(operando_1);
	free(operando_2);
}

void dcmpl(stack_frames *pilha_frames) {
	tipo_double temp_double1;
	tipo_double temp_double2;
	u4 temp_low;
	u4 temp_high;

	t_operand *temp_operando_high2 = NULL;
	t_operand *temp_operando_high1 = NULL;
	t_operand *temp_operando_low2 = NULL;
	t_operand *temp_operando_low1 = NULL;

	//desempilha low long2
	temp_operando_low2 = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando_low2->data;

	//detecção de erros
	if(temp_operando_low2->tag != TAG_DOUBLE){
		printf("Invalid operand type on double to float conversion");
		//insira função de erro aqui
	}

	//desempila high long 2
	temp_operando_high2 = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando_high2->data;

	//organiza em big endian long 2
	temp_double2 = u8_to_double(temp_low,temp_high);

	//desempilha low long 1
	temp_operando_low1 = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando_low1->data;

	//detecção de erros
	if(temp_operando_low1->tag != TAG_DOUBLE){
		printf("Invalid operand type on double to float conversion");
		//insira função de erro aqui
	}

	//desempila high long 1
	temp_operando_high1 = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando_high1->data;

	//organiza em big endian long 1
	temp_double1 = u8_to_double(temp_low,temp_high);

	if( temp_double1 > temp_double2){	push_operando(TAG_INTEGER, (u4)1, pilha_frames->first->operand_stack);	}
	else if( temp_double1 == temp_double2){ push_operando(TAG_INTEGER, (u4)0, pilha_frames->first->operand_stack);	}
	else if( temp_double1 < temp_double2){ push_operando(TAG_INTEGER, (u4)-1, pilha_frames->first->operand_stack);	}
	else{ push_operando(TAG_INTEGER, (u4)-1, pilha_frames->first->operand_stack);}

	// desaloca operando que foi desempilhado
	free(temp_operando_low1);
	free(temp_operando_high1);
	free(temp_operando_low2);
	free(temp_operando_high2);
}

void dcmpg(stack_frames *pilha_frames) {
	tipo_double temp_double1;
	tipo_double temp_double2;
	u4 temp_low;
	u4 temp_high;


	t_operand *temp_operando_high2 = NULL;
	t_operand *temp_operando_high1 = NULL;
	t_operand *temp_operando_low2 = NULL;
	t_operand *temp_operando_low1 = NULL;


	//desempilha low long2
	temp_operando_low2 = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando_low2->data;

	//detecção de erros
	if(temp_operando_low2->tag != TAG_DOUBLE){
		printf("Invalid operand type on double to float conversion");
		//insira função de erro aqui
	}

	//desempila high long 2
	temp_operando_high2 = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando_high2->data;

	//organiza em big endian long 2
	temp_double2 = u8_to_double(temp_low,temp_high);

	//desempilha low long 1
	temp_operando_low1 = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando_low1->data;

	//detecção de erros
	if(temp_operando_low1->tag != TAG_DOUBLE){
		printf("Invalid operand type on double to float conversion");
		//insira função de erro aqui
	}

	//desempila high long 1
	temp_operando_high1 = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando_high1->data;

	//organiza em big endian long 1
	temp_double1 = u8_to_double(temp_low,temp_high);

	if( temp_double1 > temp_double2){	push_operando(TAG_INTEGER, (u4)1, pilha_frames->first->operand_stack);	}
	else if( temp_double1 == temp_double2){ push_operando(TAG_INTEGER, (u4)0, pilha_frames->first->operand_stack);	}
	else if( temp_double1 < temp_double2){ push_operando(TAG_INTEGER, (u4)-1, pilha_frames->first->operand_stack);	}
	else{ push_operando(TAG_INTEGER, (u4)1, pilha_frames->first->operand_stack);}

	// desaloca operando que foi desempilhado
	free(temp_operando_low1);
	free(temp_operando_high1);
	free(temp_operando_low2);
	free(temp_operando_high2);
}

void ifeq(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_z;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z == 0){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void ifne(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_z;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;


	if(comp_z != 0){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void iflt(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_z;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z < 0){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void ifge(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_z;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z >= 0){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void ifgt(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_z;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z > 0){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void ifle(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_z;

	t_operand *temp_operando = NULL;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z <= 0){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		pilha_frames->first->pc = pilha_frames->first->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operando que foi desempilhado
	free(temp_operando);
}

void if_icmpeq(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_1, comp_2;

	t_operand *temp_operando1 = NULL;
	t_operand *temp_operando2 = NULL;

	temp_operando1 = pop_operando(frame->operand_stack);
	comp_1 = (int)temp_operando1->data;

	temp_operando2 = pop_operando(frame->operand_stack);
	comp_2 = (int)temp_operando2->data;

	if(comp_1 == comp_2){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		frame->pc = frame->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operando que foi desempilhado
	free(temp_operando1);
	free(temp_operando2);
}

void if_icmpne(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	tipo_int comp_1, comp_2;

	t_operand *temp_operando1 = NULL;
	t_operand *temp_operando2 = NULL;

	temp_operando1 = pop_operando(frame->operand_stack);
	comp_1 = (int)temp_operando1->data;

	temp_operando2 = pop_operando(frame->operand_stack);
	comp_2 = (int)temp_operando2->data;

	if(comp_1 != comp_2){
		tipo_short offset_16bit = operando_u2(frame->code_info->code,frame->pc);
		frame->pc = frame->pc + (tipo_short)offset_16bit-1;
	} else frame->pc += 2;

	// desaloca operando que foi desempilhado
	free(temp_operando1);
	free(temp_operando2);
}
