#include "instrucoes.h"
#include <string.h>

t_instrucoes instrucoes[0xCB];

u4 float_to_u4(float numero_float) {
	u4 numero_u4;
	
	memcpy(&numero_u4,&numero_float,sizeof(numero_u4));
  
	return numero_u4;
}

u8 double_to_u8(double numero_double) {
	u8 numero_u8;
	
	memcpy(&numero_u8,&numero_double,sizeof(numero_u8));
  
	return numero_u8;
}

u8 long_to_u8(long numero_double) {
	u8 numero_u8;
	
	memcpy(&numero_u8,&numero_double,sizeof(numero_u8));
  
	return numero_u8;
}

float u4_to_float(u4 numero_u4) {
	int32_t numero_s4;
	float numero_float;
	
	memcpy(&numero_s4,&numero_u4,sizeof(numero_s4));
	memcpy(&numero_float,&numero_s4,sizeof(numero_float));
	
	
	return numero_float;
}

long u8_to_long(u4 low, u4 high) {
	int64_t numero_s8;
	u8 numero_u8 = (((u8)high<<32)|low);
	long numero_long;
	
	memcpy(&numero_s8,&numero_u8,sizeof(numero_s8));
	memcpy(&numero_long,&numero_s8,sizeof(numero_long));
	
	
	return numero_long;
}

double u8_to_double(u4 low, u4 high) {
	int64_t numero_s8;
	u8 numero_u8 = (((u8)high<<32)|low);
	double numero_double;
	
	memcpy(&numero_s8,&numero_u8,sizeof(numero_s8));
	memcpy(&numero_double,&numero_s8,sizeof(numero_double));
	
	
	return numero_double;
}


void init_instrucoes() {
	t_instrucoes vetor_instrucoes[] =
	{
		[0x00] = {"nop", nop, NO_OP},
		[0x01] = {"aconst_null", aconst_null, NO_OP},
		[0x02] = {"iconst_m1", iconst_m1, NO_OP},
		[0x03] = {"iconst_0", iconst_0, NO_OP},
		[0x04] = {"iconst_1", iconst_1, NO_OP},
		[0x05] = {"iconst_2", iconst_2, NO_OP},
		[0x06] = {"iconst_3", iconst_3, NO_OP},
		[0x07] = {"iconst_4", iconst_4, NO_OP},
		[0x08] = {"iconst_5", iconst_5, NO_OP},
		[0x09] = {"lconst_0", lconst_0, NO_OP},
		[0x0A] = {"lconst_1", lconst_1, NO_OP},
		[0x0B] = {"fconst_0", fconst_0, NO_OP},
		[0x0C] = {"fconst_1", fconst_1, NO_OP},
		[0x0D] = {"fconst_2", fconst_2, NO_OP},
		[0x0E] = {"dconst_0", dconst_0, NO_OP},
		[0x0F] = {"dconst_1", dconst_1, NO_OP},
		[0x10] = {"bipush", bipush, INT1},
		[0x11] = {"sipush", sipush, INT2},
		[0x12] = {"ldc", ldc, CP1},
		[0x13] = {"ldc_w", ldc_w, CP2},
		[0x14] = {"ldc2_w", ldc2_w, CP2},
		[0x15] = {"iload", iload, LV1},
		[0x16] = {"lload", lload, LV1},
		[0x17] = {"fload", fload, LV1},
		[0x18] = {"dload", dload, LV1},
		[0x19] = {"aload", aload, LV1},
		[0x1A] = {"iload_0", iload_0, NO_OP},
		[0x1B] = {"iload_1", iload_1, NO_OP},
		[0x1C] = {"iload_2", iload_2, NO_OP},
		[0x1D] = {"iload_3", iload_3, NO_OP},
		[0x1E] = {"lload_0", lload_0, NO_OP},
		[0x1F] = {"lload_1", lload_1, NO_OP},
		[0x20] = {"lload_2", lload_2, NO_OP},
		[0x21] = {"lload_3", lload_3, NO_OP},
		[0x22] = {"fload_0", fload_0, NO_OP},
		[0x23] = {"fload_1", fload_1, NO_OP},
		[0x24] = {"fload_2", fload_2, NO_OP},
		[0x25] = {"fload_3", fload_3, NO_OP},
		[0x26] = {"dload_0", dload_0, NO_OP},
		[0x27] = {"dload_1", dload_1, NO_OP},
		[0x28] = {"dload_2", dload_2, NO_OP},
		[0x29] = {"dload_3", dload_3, NO_OP},
		[0x2A] = {"aload_0", aload_0, NO_OP},
		[0x2B] = {"aload_1", aload_1, NO_OP},
		[0x2C] = {"aload_2", aload_2, NO_OP},
		[0x2D] = {"aload_3", aload_3, NO_OP},
		[0x2E] = {"iaload", iaload, NO_OP},
		[0x2F] = {"laload", laload, NO_OP},
		[0x30] = {"faload", faload, NO_OP},
		[0x31] = {"daload", daload, NO_OP},
		[0x32] = {"aaload", aaload, NO_OP},
		[0x33] = {"baload", baload, NO_OP},
		[0x34] = {"caload", caload, NO_OP},
		[0x35] = {"saload", saload, NO_OP},
		[0x36] = {"istore", istore, LV1},
		[0x37] = {"lstore", lstore, LV1},
		[0x38] = {"fstore", fstore, LV1},
		[0x39] = {"dstore", dstore, LV1},
		[0x3A] = {"astore", astore, LV1},
		[0x3B] = {"istore_0", istore_0, NO_OP},
		[0x3C] = {"istore_1", istore_1, NO_OP},
		[0x3D] = {"istore_2", istore_2, NO_OP},
		[0x3E] = {"istore_3", istore_3, NO_OP},
		[0x3F] = {"lstore_0", lstore_0, NO_OP},
		[0x40] = {"lstore_1", lstore_1, NO_OP},
		[0x41] = {"lstore_2", lstore_2, NO_OP},
		[0x42] = {"lstore_3", lstore_3, NO_OP},
		[0x43] = {"fstore_0", fstore_0, NO_OP},
		[0x44] = {"fstore_1", fstore_1, NO_OP},
		[0x45] = {"fstore_2", fstore_2, NO_OP},
		[0x46] = {"fstore_3", fstore_3, NO_OP},
		[0x47] = {"dstore_0", dstore_0, NO_OP},
		[0x48] = {"dstore_1", dstore_1, NO_OP},
		[0x49] = {"dstore_2", dstore_2, NO_OP},
		[0x4A] = {"dstore_3", dstore_3, NO_OP},
		[0x4B] = {"astore_0", astore_0, NO_OP},
		[0x4C] = {"astore_1", astore_1, NO_OP},
		[0x4D] = {"astore_2", astore_2, NO_OP},
		[0x4E] = {"astore_3", astore_3, NO_OP},
		[0x4F] = {"iastore", iastore, NO_OP},
		[0x50] = {"lastore", lastore, NO_OP},
		[0x51] = {"fastore", fastore, NO_OP},
		[0x52] = {"dastore", dastore, NO_OP},
		[0x53] = {"aastore", aastore, NO_OP},
		[0x54] = {"bastore", bastore, NO_OP},
		[0x55] = {"castore", castore, NO_OP},
		[0x56] = {"sastore", sastore, NO_OP},
		[0x57] = {"pop", pop, NO_OP},
		[0x58] = {"pop2", pop2, NO_OP},
		[0x59] = {"dup", dup, NO_OP},
		[0x5A] = {"dup_x1", dup_x1, NO_OP},
		[0x5B] = {"dup_x2", dup_x2, NO_OP},
		[0x5C] = {"dup2", dup2, NO_OP},
		[0x5D] = {"dup2_x1", dup2_x1, NO_OP},
		[0x5E] = {"dup2_x2", dup2_x2, NO_OP},
		[0x5F] = {"swap", swap, NO_OP},
		[0x60] = {"iadd", iadd, NO_OP},
		[0x61] = {"ladd", ladd, NO_OP},
		[0x62] = {"fadd", fadd, NO_OP},
		[0x63] = {"dadd", dadd, NO_OP},
		[0x64] = {"isub", isub, NO_OP},
		[0x65] = {"lsub", lsub, NO_OP},
		[0x66] = {"fsub", fsub, NO_OP},
		[0x67] = {"dsub", dsub, NO_OP},
		[0x68] = {"imul", imul, NO_OP},
		[0x69] = {"lmul", lmul, NO_OP},
		[0x6A] = {"fmul", fmul, NO_OP},
		[0x6B] = {"dmul", dmul, NO_OP},
		[0x6C] = {"idiv", idiv, NO_OP},
		[0x6D] = {"ldiv", ldiv_, NO_OP},
		[0x6E] = {"fdiv", fdiv, NO_OP},
		[0x6F] = {"ddiv", ddiv, NO_OP},
		[0x70] = {"irem", irem, NO_OP},
		[0x71] = {"lrem", lrem, NO_OP},
		[0x72] = {"frem", frem, NO_OP},
		[0x73] = {"drem", drem, NO_OP},
		[0x74] = {"ineg", ineg, NO_OP},
		[0x75] = {"lneg", lneg, NO_OP},
		[0x76] = {"fneg", fneg, NO_OP},
		[0x77] = {"dneg", dneg, NO_OP},
		[0x78] = {"ishl", ishl, NO_OP},
		[0x79] = {"lshl", lshl, NO_OP},
		[0x7A] = {"ishr", ishr, NO_OP},
		[0x7B] = {"lshr", lshr, NO_OP},
		[0x7C] = {"iushr", iushr, NO_OP},
		[0x7D] = {"lushr", lushr, NO_OP},
		[0x7E] = {"iand", iand, NO_OP},
		[0x7F] = {"land", land, NO_OP},
		[0x80] = {"ior", ior, NO_OP},
		[0x81] = {"lor", lor, NO_OP},
		[0x82] = {"ixor", ixor, NO_OP},
		[0x83] = {"lxor", lxor, NO_OP},
		[0x84] = {"iinc", iinc, LV1_INT1},
		[0x85] = {"i2l", i2l, NO_OP},
		[0x86] = {"i2f", i2f, NO_OP},
		[0x87] = {"i2d", i2d, NO_OP},
		[0x88] = {"l2i", l2i, NO_OP},
		[0x89] = {"l2f", l2f, NO_OP},
		[0x8A] = {"l2d", l2d, NO_OP},
		[0x8B] = {"f2i", f2i, NO_OP},
		[0x8C] = {"f2l", f2l, NO_OP},
		[0x8D] = {"f2d", f2d, NO_OP},
		[0x8E] = {"d2i", d2i, NO_OP},
		[0x8F] = {"d2l", d2l, NO_OP},
		[0x90] = {"d2f", d2f, NO_OP},
		[0x91] = {"i2b", i2b, NO_OP},
		[0x92] = {"i2c", i2c, NO_OP},
		[0x93] = {"i2s", i2s, NO_OP},
		[0x94] = {"lcmp", lcmp, NO_OP},
		[0x95] = {"fcmpl", fcmpl, NO_OP},
		[0x96] = {"fcmpg", fcmpg, NO_OP},
		[0x97] = {"dcmpl", dcmpl, NO_OP},
		[0x98] = {"dcmpg", dcmpg, NO_OP},
		[0x99] = {"ifeq", ifeq, OFFSET2},
		[0x9A] = {"ifne", ifne, OFFSET2},
		[0x9B] = {"iflt", iflt, OFFSET2},
		[0x9C] = {"ifge", ifge, NO_OP},
		[0x9D] = {"ifgt", ifgt, NO_OP},
		[0x9E] = {"ifle", ifle, NO_OP},
		[0x9F] = {"if_icmpeq", if_icmpeq, OFFSET2},
		[0xA0] = {"if_icmpne", if_icmpne, OFFSET2},
		[0xA1] = {"if_icmplt", if_icmplt, OFFSET2},
		[0xA2] = {"if_icmpge", if_icmpge, OFFSET2},
		[0xA3] = {"if_icmpgt", if_icmpgt, OFFSET2},
		[0xA4] = {"if_icmple", if_icmple, OFFSET2},
		[0xA5] = {"if_acmpeq", if_acmpeq, OFFSET2},
		[0xA6] = {"if_acmpne", if_acmpne, OFFSET2},
		[0xA7] = {"goto", goto_, OFFSET2},
		[0xA8] = {"jsr", jsr, OFFSET2},
		[0xA9] = {"ret", ret, LV1},
		[0xAA] = {"tableswitch", tableswitch, TABLE_SWITCH},
		[0xAB] = {"lookupswitch", lookupswitch, LOOKUP_SWITCH},
		[0xAC] = {"ireturn", ireturn, NO_OP},
		[0xAD] = {"lreturn", lreturn, NO_OP},
		[0xAE] = {"freturn", freturn, NO_OP},
		[0xAF] = {"dreturn", dreturn, NO_OP},
		[0xB0] = {"areturn", areturn, NO_OP},
		[0xB1] = {"return", return_, NO_OP},
		[0xB2] = {"getstatic", getstatic, CP2},
		[0xB3] = {"putstatic", putstatic, CP2},
		[0xB4] = {"getfield", getfield, CP2},
		[0xB5] = {"putfield", putfield, CP2},
		[0xB6] = {"invokevirtual", invokevirtual, CP2},
		[0xB7] = {"invokespecial", invokespecial, CP2},
		[0xB8] = {"invokestatic", invokestatic, CP2},
		[0xB9] = {"invokeinterface", invokeinterface, CP2_INT0},
		[0xBA] = {"unused", unused, NO_OP},
		[0xBB] = {"new", new_, CP2},
		[0xBC] = {"newarray", newarray, FLAG1},
		[0xBD] = {"anewarray", anewarray, CP2},
		[0xBE] = {"arraylength", arraylength, NO_OP},
		[0xBF] = {"athrow", athrow, NO_OP},
		[0xC0] = {"checkcast", checkcast, CP2},
		[0xC1] = {"instanceof", instanceof, CP2},
		[0xC2] = {"monitorenter", monitorenter, NO_OP},
		[0xC3] = {"monitorexit", monitorexit, NO_OP},
		[0xC4] = {"wide", wide, NO_OP},
		[0xC5] = {"multianewarray", multianewarray, CP2_INT1},
		[0xC6] = {"ifnull", ifnull, OFFSET2},
		[0xC7] = {"ifnonnull", ifnonnull, OFFSET2},
		[0xC8] = {"goto_w", goto_w, OFFSET4},
		[0xC9] = {"jsr_w", jsr_w, OFFSET4},
		[0xCA] = {"breakpoint", breakpoint, NO_OP}
	};

	memcpy(instrucoes,vetor_instrucoes,sizeof (instrucoes));
}


u2 operando_u2 (u1 code[], u4 index) {
	return ((code[index]<<8)|code[index+1]);
}

u4 operando_u4 (u1 code[], u4 index) {
	return (code[index]<<24)|(code[index+1]<<16)|(code[index+2]<<8)|code[index+3];
}

u1 acha_tamanho_operando(u1 operando) {
	switch(operando) {
		case NO_OP: return 0;
		case CP2: return 2;
		case CP1: return 1;
		case LV1: return 1;
		case INT1: return 1;
		case INT2: return 2;
		case LV1_INT1: return 2;
		case OFFSET2: return 2;
		case OFFSET4: return 4;
		case CP2_INT1: return 3;
		case FLAG1: return 1;
		case CP2_INT0: return 4;
		default: return 15;
	}
}

char *primitive_array_info(u1 type_code) {
	char *type = (char*)malloc(sizeof(char)*7);

	switch (type_code) {
		case 4: strcpy(type,"boolean"); break;
		case 5: strcpy(type,"char"); break;
		case 6: strcpy(type,"float"); break;
		case 7:strcpy(type,"double"); break;
		case 8:strcpy(type,"byte"); break;
		case 9:strcpy(type,"short"); break;
		case 10:strcpy(type,"int"); break;
		case 11:strcpy(type,"long"); break;
	}


	return type;
}

/**
t_instrucoes* vetorMnemonicos (void)
{
	t_instrucoes *vetorRetorno = (t_instrucoes*)malloc(sizeof(t_instrucoes)*0xCB);

	//declarando o vetor com os mnemonicos
	t_instrucoes instrucoes[] =
	{
		[0x00] = {"nop", NO_OP},
		[0x01] = {"aconst_null ", NO_OP},
		[0x02] = {"iconst_m1 ", NO_OP},
		[0x03] = {"iconst_0", NO_OP},
		[0x04] = {"iconst_1", NO_OP},
		[0x05] = {"iconst_2", NO_OP},
		[0x06] = {"iconst_3", NO_OP},
		[0x07] = {"iconst_4", NO_OP},
		[0x08] = {"iconst_5", NO_OP},
		[0x09] = {"lconst_0", NO_OP},
		[0x0A] = {"lconst_1", NO_OP},
		[0x0B] = {"fconst_0", NO_OP},
		[0x0C] = {"fconst_1", NO_OP},
		[0x0D] = {"fconst_2", NO_OP},
		[0x0E] = {"dconst_0", NO_OP},
		[0x0F] = {"dconst_1", NO_OP},


		[0x10] = {"bipush", INT1},
		[0x11] = {"sipush", INT2},
		[0x12] = {"ldc", CP1},
		[0x13] = {"ldc_w", CP2},
		[0x14] = {"ldc2_w", CP2},
		[0x15] = {"iload", LV1},
		[0x16] = {"lload ", LV1},
		[0x17] = {"fload", LV1},
		[0x18] = {"dload", LV1},
		[0x19] = {"aload", LV1},
		[0x1A] = {"iload_0", NO_OP},
		[0x1B] = {"iload_1", NO_OP},
		[0x1C] = {"iload_2", NO_OP},
		[0x1D] = {"iload_3", NO_OP},
		[0x1E] = {"lload_0", NO_OP},
		[0x1F] = {"lload_1", NO_OP},


		[0x20] = {"lload_2", NO_OP},
		[0x21] = {"lload_3", NO_OP},
		[0x22] = {"fload_0", NO_OP},
		[0x23] = {"fload_1", NO_OP},
		[0x24] = {"fload_2", NO_OP},
		[0x25] = {"fload_3", NO_OP},
		[0x26] = {"dload_0", NO_OP},
		[0x27] = {"dload_1", NO_OP},
		[0x28] = {"dload_2", NO_OP},
		[0x29] = {"dload_3", NO_OP},
		[0x2A] = {"aload_0", NO_OP},
		[0x2B] = {"aload_1", NO_OP},
		[0x2C] = {"aload_2", NO_OP},
		[0x2D] = {"aload_3", NO_OP},
		[0x2E] = {"iaload", NO_OP},
		[0x2F] = {"laload", NO_OP},


		[0x30] = {"faload", NO_OP},
		[0x31] = {"daload", NO_OP},
		[0x32] = {"aaload", NO_OP},
		[0x33] = {"baload", NO_OP},
		[0x34] = {"caload", NO_OP},
		[0x35] = {"saload", NO_OP},
		[0x36] = {"istore", LV1},
		[0x37] = {"lstore", LV1},
		[0x38] = {"fstore", LV1},
		[0x39] = {"dstore", LV1},
		[0x3A] = {"astore", LV1},
		[0x3B] = {"istore_0", NO_OP},
		[0x3C] = {"istore_1", NO_OP},
		[0x3D] = {"istore_2", NO_OP},
		[0x3E] = {"istore_3", NO_OP},
		[0x3F] = {"lstore_0", NO_OP},


		[0x40] = {"lstore_1", NO_OP},
		[0x41] = {"lstore_2", NO_OP},
		[0x42] = {"lstore_3", NO_OP},
		[0x43] = {"fstore_0", NO_OP},
		[0x44] = {"fstore_1", NO_OP},
		[0x45] = {"fstore_2", NO_OP},
		[0x46] = {"fstore_3", NO_OP},
		[0x47] = {"dstore_0", NO_OP},
		[0x48] = {"dstore_1", NO_OP},
		[0x49] = {"dstore_2", NO_OP},
		[0x4A] = {"dstore_3", NO_OP},
		[0x4B] = {"astore_0", NO_OP},
		[0x4C] = {"astore_1", NO_OP},
		[0x4D] = {"astore_2", NO_OP},
		[0x4E] = {"astore_3", NO_OP},
		[0x4F] = {"iastore", NO_OP},


		[0x50] = {"lastore", NO_OP},
		[0x51] = {"fastore", NO_OP},
		[0x52] = {"dastore", NO_OP},
		[0x53] = {"aastore", NO_OP},
		[0x54] = {"bastore", NO_OP},
		[0x55] = {"castore", NO_OP},
		[0x56] = {"sastore", NO_OP},
		[0x57] = {"pop", NO_OP},
		[0x58] = {"pop2", NO_OP},
		[0x59] = {"dup", NO_OP},
		[0x5A] = {"dup_x1", NO_OP},
		[0x5B] = {"dup_x2", NO_OP},
		[0x5C] = {"dup2", NO_OP},
		[0x5D] = {"dup2_x1", NO_OP},
		[0x5E] = {"dup2_x2", NO_OP},
		[0x5F] = {"swap", NO_OP},


		[0x60] = {"iadd", NO_OP},
		[0x61] = {"ladd", NO_OP},
		[0x62] = {"fadd", NO_OP},
		[0x63] = {"dadd", NO_OP},
		[0x64] = {"isub", NO_OP},
		[0x65] = {"lsub", NO_OP},
		[0x66] = {"fsub", NO_OP},
		[0x67] = {"dsub", NO_OP},
		[0x68] = {"imul", NO_OP},
		[0x69] = {"lmul", NO_OP},
		[0x6A] = {"fmul", NO_OP},
		[0x6B] = {"dmul", NO_OP},
		[0x6C] = {"idiv", NO_OP},
		[0x6D] = {"ldiv", NO_OP},
		[0x6E] = {"fdiv", NO_OP},
		[0x6F] = {"ddiv", NO_OP},


		[0x70] = {"irem", NO_OP},
		[0x71] = {"lrem", NO_OP},
		[0x72] = {"frem", NO_OP},
		[0x73] = {"drem", NO_OP},
		[0x74] = {"ineg", NO_OP},
		[0x75] = {"lneg", NO_OP},
		[0x76] = {"fneg", NO_OP},
		[0x77] = {"dneg", NO_OP},
		[0x78] = {"ishl", NO_OP},
		[0x79] = {"lshl", NO_OP},
		[0x7A] = {"ishr", NO_OP},
		[0x7B] = {"lshr", NO_OP},
		[0x7C] = {"iushr", NO_OP},
		[0x7D] = {"lushr", NO_OP},
		[0x7E] = {"iand", NO_OP},
		[0x7F] = {"land", NO_OP},


		[0x80] = {"ior", NO_OP},
		[0x81] = {"lor", NO_OP},
		[0x82] = {"ixor", NO_OP},
		[0x83] = {"lxor", NO_OP},
		[0x84] = {"iinc", LV1_INT1},
		[0x85] = {"i2l", NO_OP},
		[0x86] = {"i2f", NO_OP},
		[0x87] = {"i2d", NO_OP},
		[0x88] = {"l2i", NO_OP},
		[0x89] = {"l2f", NO_OP},
		[0x8A] = {"l2d", NO_OP},
		[0x8B] = {"f2i", NO_OP},
		[0x8C] = {"f2l", NO_OP},
		[0x8D] = {"f2d", NO_OP},
		[0x8E] = {"d2i", NO_OP},
		[0x8F] = {"d2l", NO_OP},


		[0x90] = {"d2f", NO_OP},
		[0x91] = {"i2b", NO_OP},
		[0x92] = {"i2c", NO_OP},
		[0x93] = {"i2s", NO_OP},
		[0x94] = {"lcmp", NO_OP},
		[0x95] = {"fcmpl", NO_OP},
		[0x96] = {"fcmpg", NO_OP},
		[0x97] = {"dcmpl", NO_OP},
		[0x98] = {"dcmpg", NO_OP},
		[0x99] = {"ifeq", OFFSET2},
		[0x9A] = {"ifne", OFFSET2},
		[0x9B] = {"iflt", OFFSET2},
		[0x9C] = {"ifge", NO_OP},
		[0x9D] = {"ifgt", NO_OP},
		[0x9E] = {"ifle", NO_OP},
		[0x9F] = {"if_icmpeq", OFFSET2},


		[0xA0] = {"if_icmpne", OFFSET2},
		[0xA1] = {"if_icmplt", OFFSET2},
		[0xA2] = {"if_icmpge", OFFSET2},
		[0xA3] = {"if_icmpgt", OFFSET2},
		[0xA4] = {"if_icmple", OFFSET2},
		[0xA5] = {"if_acmpeq", OFFSET2},
		[0xA6] = {"if_acmpne", OFFSET2},
		[0xA7] = {"goto", OFFSET2},
		[0xA8] = {"jsr", OFFSET2},
		[0xA9] = {"ret", LV1},
		[0xAA] = {"tableswitch", TABLE_SWITCH},
		[0xAB] = {"lookupswitch", LOOKUP_SWITCH},
		[0xAC] = {"ireturn", NO_OP},
		[0xAD] = {"lreturn", NO_OP},
		[0xAE] = {"freturn", NO_OP},
		[0xAF] = {"dreturn", NO_OP},


		[0xB0] = {"areturn", NO_OP},
		[0xB1] = {"return", NO_OP},
		[0xB2] = {"getstatic", CP2},
		[0xB3] = {"putstatic", CP2},
		[0xB4] = {"getfield", CP2},
		[0xB5] = {"putfield", CP2},
		[0xB6] = {"invokevirtual", CP2},
		[0xB7] = {"invokespecial", CP2},
		[0xB8] = {"invokestatic", CP2},
		[0xB9] = {"invokeinterface", CP2_INT0},
		// [0xBA] = unused
		[0xBB] = {"new", CP2},
		[0xBC] = {"newarray", FLAG1},
		[0xBD] = {"anewarray", CP2},
		[0xBE] = {"arraylength", NO_OP},
		[0xBF] = {"athrow", NO_OP},


		[0xC0] = {"checkcast", CP2},
		[0xC1] = {"instanceof", CP2},
		[0xC2] = {"monitorenter", NO_OP},
		[0xC3] = {"monitorexit", NO_OP},
		[0xC4] = {"wide", NO_OP},
		[0xC5] = {"multianewarray", CP2_INT1},
		[0xC6] = {"ifnull", OFFSET2},
		[0xC7] = {"ifnonnull", OFFSET2},
		[0xC8] = {"goto_w", OFFSET4},
		[0xC9] = {"jsr_w", OFFSET4},
		[0xCA] = {"breakpoint", NO_OP}
	};

	memcpy(vetorRetorno,instrucoes,sizeof instrucoes);

	return vetorRetorno;
}**/
