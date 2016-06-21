#include "instrucoes_121-160.h"

void lshl(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Tamanho do shift
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);
	
	// Número que sofrerá shift
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);
	
	long operando1_long;
	long operando2_long;
	u8 resultado;
	
	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);
	
	// Realiza shift
	resultado = operando1_long<<operando2_long;
  
	// Armazena resultado do shift na pilha de operandos
	push_operando(resultado>>32,frame->operand_stack);
	push_operando(resultado,frame->operand_stack);
	
	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
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
	push_operando(resultado,frame->operand_stack);
	
	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}



void lshr(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Tamanho do shift
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);
	
	// Número que sofrerá shift
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);
	
	long operando1_long;
	long operando2_long;
	u8 resultado;
	
	// Transforma os operandos em longs
	operando1_long = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);
	
	// Realiza shift
	resultado = operando1_long>>operando2_long;
  
	// Armazena resultado do shift na pilha de operandos
	push_operando(resultado>>32,frame->operand_stack);
	push_operando(resultado,frame->operand_stack);
	
	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
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
	push_operando(resultado,frame->operand_stack);
	
	// Desaloca operandos que foram desempilhados
	free(operando1);
	free(operando2);
}



void lushr(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Tamanho do shift
	t_operand *operando2_low = pop_operando(frame->operand_stack);
	t_operand *operando2_high = pop_operando(frame->operand_stack);
	
	// Número que sofrerá shift
	t_operand *operando1_low = pop_operando(frame->operand_stack);
	t_operand *operando1_high = pop_operando(frame->operand_stack);
	
	unsigned long operando1_ulong;
	long operando2_long;
	u8 resultado;
	
	// Transforma os operandos em longs
	operando1_ulong = u8_to_long(operando1_low->data,operando1_high->data);
	operando2_long = u8_to_long(operando2_low->data,operando2_high->data);
	
	// Realiza shift
	resultado = operando1_ulong>>operando2_long;

	// Armazena resultado do shift na pilha de operandos
	push_operando(resultado>>32,frame->operand_stack);
	push_operando(resultado,frame->operand_stack);
	
	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
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
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado>>32,frame->operand_stack);
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado>>32,frame->operand_stack);
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado>>32,frame->operand_stack);
	push_operando(resultado,frame->operand_stack);
	
	// Desaloca operandos que foram desempilhados
	free(operando1_high);
	free(operando1_low);
	free(operando2_high);
	free(operando2_low);
}



void iinc(stack_frames *pilha_frames) {
	t_frame *frame = pilha_frames->first;
	
	// Recupera do code índice da variável a ser incrementada
	u1 indice_variavel = frame->code_info->code[pilha_frames->first->pc++];
	
	// Recupera do code o tamanho do incremento
	signed char incremento = frame->code_info->code[pilha_frames->first->pc++];
	
	// Realiza incremento
	frame->array_variaveis_locais[indice_variavel] += incremento;
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
	push_operando(resultado>>32,frame->operand_stack);
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado>>32,frame->operand_stack);
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado,frame->operand_stack);
	
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
	push_operando(resultado,frame->operand_stack);
	
	// Desaloca operandos que foram desempilhados
	free(operando_low);
	free(operando_high);
}


//ivan
//ivan
void l2d(stack_frames *pilha_frames) {
	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	u8 temp_long;
	u8 aux;
	u4 temp_low;
	u4 temp_high;
	tipo_long temp_long_var;
	tipo_double temp_double;

	//desempilha low
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	temp_long = (((u8)temp_high)<<32) & ((u8)temp_low);

	//tranformação long para double com typecast
	temp_long_var = (tipo_long)temp_long;
	temp_double = (tipo_double)temp_long_var;

	//empilha em big endian
	aux = (u8)temp_double;
	temp_high = (u4)(aux>>32 & 0x0000ffff);
	push_operando(temp_high,pilha_frames->first->operand_stack);
	temp_low = (u4)(aux & 0x0000ffff);
	push_operando(temp_low,pilha_frames->first->operand_stack);

	free(temp_operando);
}

void f2i(stack_frames *pilha_frames) {
	tipo_float temp_float;
	tipo_int temp_int;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_float = (tipo_float)temp_operando->data;
	//conversão via cast
	temp_int = (tipo_int)temp_float;
	push_operando((u4)temp_int,pilha_frames->first->operand_stack);
}


void f2l(stack_frames *pilha_frames) {
	tipo_float temp_float;
	tipo_long temp_long;
	u4 temp_32;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_float = (tipo_float)temp_operando->data;
	//conversão via cast
	temp_long = (tipo_long)temp_float;

	//empilha em big endian
	temp_32 = (u4)(temp_long >> 32);
	push_operando(temp_32,pilha_frames->first->operand_stack);
	temp_32 = (u4)temp_long;
	push_operando(temp_32,pilha_frames->first->operand_stack);
}


void f2d(stack_frames *pilha_frames) {
	tipo_float temp_float;
	tipo_double temp_double;
	u8 aux;
	u4 temp_high, temp_low;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_float = (tipo_float)temp_operando->data;
	//conversão via cast
	temp_double = (tipo_double)temp_float;

	//empilha em big endian
	aux = (u8)temp_double;
	temp_high = (u4)(aux>>32 & 0x0000ffff);
	push_operando(temp_high,pilha_frames->first->operand_stack);
	temp_low = (u4)(aux & 0x0000ffff);
	push_operando(temp_low,pilha_frames->first->operand_stack);
}


void d2i(stack_frames *pilha_frames) { //problema com o tamanho do data!!
	u8 temp_double;
	u4 temp_low, temp_high;
	tipo_double temp_double_var;
	tipo_int temp_int;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha low
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian
	temp_double = (((u8)temp_high)<<32) & ((u8)temp_low);
	//conversão via cast
	temp_double_var = (tipo_double)temp_double;
	temp_int = (tipo_int)temp_double_var;

	push_operando((u4)temp_int,pilha_frames->first->operand_stack);
}



void d2l(stack_frames *pilha_frames) { //problema com o tamanho do data!!
	u8 temp_double,aux;
	u4 temp_low;
	u4 temp_high;
	tipo_long temp_long;
	tipo_double temp_double_var;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha low
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian
	temp_double = (((u8)temp_high)<<32) & ((u8)temp_low);

	//tranformação long para double com typecast
	temp_double_var = (tipo_double)temp_double;
	temp_long = (tipo_long)temp_double_var;

	//empilha em big endian
	aux = (u8)temp_long;
	temp_high = (u4)(aux>>32 & 0x0000ffff);
	push_operando(temp_high,pilha_frames->first->operand_stack);
	temp_low = (u4)(aux & 0x0000ffff);
	push_operando(temp_low,pilha_frames->first->operand_stack);
}



void d2f(stack_frames *pilha_frames) { //problema com o tamanho do data!!
	u8 temp_double;
	u4 temp_low, temp_high;
	tipo_double temp_double_var;
	tipo_float temp_float;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha low
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian
	temp_double = (((u8)temp_high)<<32) & ((u8)temp_low);

	//conversão via cast
	temp_double_var = (tipo_double)temp_double;
	temp_float = (tipo_float)temp_double_var;

	push_operando((u4)temp_float,pilha_frames->first->operand_stack);
}



void i2b(stack_frames *pilha_frames) {
	u4 temp_byte;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_byte = (u4)temp_operando->data;

	if(temp_byte >> 31 == 0){
		temp_byte = 0x000f & (temp_byte >> 24);
	}
	else{
		temp_byte = 0xffff & (temp_byte >> 24);
	}
	push_operando(temp_byte,pilha_frames->first->operand_stack);
}



void i2c(stack_frames *pilha_frames) {
	u4 temp;
	u4 temp_char;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp = (u4)temp_operando->data;

	temp_char = 0x000f & (temp >> 24);
	push_operando(temp_char,pilha_frames->first->operand_stack);
}



void i2s(stack_frames *pilha_frames) {
	u4 temp;
	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp = (u4)temp_operando->data;
	if(temp >> 31 == 0){
		temp = 0x00ff & (temp >> 16);
	}
	else{
		temp = 0xffff & (temp >> 16);
	}
	push_operando(temp,pilha_frames->first->operand_stack);
}


void lcmp(stack_frames *pilha_frames) {
	u8 temp_long1;
	u8 temp_long2;
	u4 temp_low;
	u4 temp_high;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha low long2
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high long 2
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian long 2
	temp_long2 = (((u8)temp_high)<<32) & ((u8)temp_low);

	//desempilha low long 1
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high long 1
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian long 1
	temp_long1 = (((u8)temp_high)<<32) & ((u8)temp_low);

	u8 *p_long1 = &temp_long1;
	u8 *p_long2 = &temp_long2;
	u4 n;

	n = memcmp(p_long1,p_long2,sizeof(u8));

	push_operando(n,pilha_frames->first->operand_stack);
}




void fcmpl(stack_frames *pilha_frames) {
	tipo_float temp_float1,temp_float2;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha primeiro operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_float2 = (tipo_float)temp_operando->data;

	//desempilha o segundo operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_float1 = (tipo_float)temp_operando->data;

	//:::::::::::::::::::::::::::::::::::::::::falta fazer a comparação de not a number::::::::::::::::::::::::::::::::://
	// se algum operando for NAN, empilha -1

	u4 n;
	tipo_float *p_float1 = &temp_float1;
	tipo_float *p_float2 = &temp_float2;

	n = memcmp(p_float1,p_float2,sizeof(u4));

	push_operando(n,pilha_frames->first->operand_stack);
}



void fcmpg(stack_frames *pilha_frames) {
	tipo_float temp_float1,temp_float2;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha primeiro operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_float2 = (tipo_float)temp_operando->data;

	//desempilha o segundo operando
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_float1 = (tipo_float)temp_operando->data;

	//:::::::::::::::::::::::::::::::::::::::::falta fazer a comparação de not a number::::::::::::::::::::::::::::::::://
	// se algum operando for NAN, empilha 1

	u4 n;
	tipo_float *p_float1 = &temp_float1;
	tipo_float *p_float2 = &temp_float2;

	n = memcmp(p_float1,p_float2,sizeof(u4));

	push_operando(n,pilha_frames->first->operand_stack);

}



void dcmpl(stack_frames *pilha_frames) {
	u8 temp_double1;
	u8 temp_double2;
	u4 temp_low;
	u4 temp_high;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha low long2
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high long 2
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian long 2
	temp_double2 = (((u8)temp_high)<<32) & ((u8)temp_low);

	//desempilha low long 1
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high long 1
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian long 1
	temp_double1 = (((u8)temp_high)<<32) & ((u8)temp_low);

	tipo_double double1, double2;

	double2 = (tipo_double)temp_double2;
	double1 = (tipo_double)temp_double1;

	//:::::::::::::::::::::::::::::::::::::::::falta fazer a comparação de not a number::::::::::::::::::::::::::::::::://
	// se algum operando for NAN, empilha -1

	tipo_double *p_double1 = &double1;
	tipo_double *p_double2 = &double2;
	u4 n;

	n = memcmp(p_double1,p_double2,sizeof(u8));

	push_operando(n,pilha_frames->first->operand_stack);
}



void dcmpg(stack_frames *pilha_frames) {
	u8 temp_double1;
	u8 temp_double2;
	u4 temp_low;
	u4 temp_high;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	//desempilha low long2
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high long 2
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian long 2
	temp_double2 = (((u8)temp_high)<<32) & ((u8)temp_low);

	//desempilha low long 1
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_low = temp_operando->data;

	//desempila high long 1
	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	temp_high = temp_operando->data;

	//organiza em big endian long 1
	temp_double1 = (((u8)temp_high)<<32) & ((u8)temp_low);

	tipo_double double1, double2;

	double2 = (tipo_double)temp_double2;
	double1 = (tipo_double)temp_double1;

	//:::::::::::::::::::::::::::::::::::::::::falta fazer a comparação de not a number::::::::::::::::::::::::::::::::://
	// se algum operando for NAN, empilha 1

	tipo_double *p_double1 = &double1;
	tipo_double *p_double2 = &double2;
	u4 n;

	n = memcmp(p_double1,p_double2,sizeof(u8));

	push_operando(n,pilha_frames->first->operand_stack);
}



void ifeq(stack_frames *pilha_frames) {
	tipo_int comp_z;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z == 0){
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

}



void ifne(stack_frames *pilha_frames) {
	tipo_int comp_z;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z != 0){
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
}



void iflt(stack_frames *pilha_frames) {
	tipo_int comp_z;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z < 0){
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
}



void ifge(stack_frames *pilha_frames) {
	tipo_int comp_z;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z >= 0){
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
}



void ifgt(stack_frames *pilha_frames) {
	tipo_int comp_z;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z > 0){
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
}



void ifle(stack_frames *pilha_frames) {
	tipo_int comp_z;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);

	comp_z = (int)temp_operando->data;

	if(comp_z <= 0){
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
}



void if_icmpeq(stack_frames *pilha_frames) {
	tipo_int comp_1, comp_2;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_1 = (int)temp_operando->data;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_2 = (int)temp_operando->data;

	if(comp_1 == comp_2){
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

}



void if_icmpne(stack_frames *pilha_frames) {
	tipo_int comp_1, comp_2;

	t_operand *temp_operando = NULL;
	temp_operando = (t_operand*) malloc(sizeof(t_operand));

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_1 = (int)temp_operando->data;

	temp_operando = pop_operando(pilha_frames->first->operand_stack);
	comp_2 = (int)temp_operando->data;

	if(comp_1 != comp_2){
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
}

