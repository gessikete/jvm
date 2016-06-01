#include "nomes_instrucoes.h"
#include <string.h>


// int main(int argc, char const *argv[])
// {
// 	t_instrucoes *vetorTeste;

// 	vetorTeste = vetorMnemonicos();

// 	printf("%s\n", vetorTeste[0xB2].nome);
// 	return 0;
// }


u1 acha_tamanho_operando(u1 operando) {
	switch(operando) {
		case NO_OP: return 0; //ok
		case CP2: return 2;   //ok
		case CP1: return 1;
		case LV1: return 1;
		case INT1: return 1;
		case INT2: return 2;
		case LV1_INT1: return 2;
		case OFFSET2: return 2;
		case OFFSET4: return 4;
		case CP2_INT1: return 3;
		case FLAG1: return 1;
		default: return 0;
		//TODO: case INTERROG:
	  
	}
}

t_instrucoes* vetorMnemonicos (void)
{
	t_instrucoes *vetorRetorno = (t_instrucoes*)malloc(sizeof(t_instrucoes)*0xCB);

	//declarando o vetor com os mnemonicos
	t_instrucoes instrucoes[] = 
	{
		[0x00] = {"nop", NO_OP},
		[0xB2] = {"getstatic", CP2},
		[0xB3] = {"putstatic", CP2},
		[0xB4] = {"getfield", CP2},
		[0xB5] = {"putfield", CP2},

		[0x15] = {"iload", LV1},
		[0x16] = {"lload ", LV1},
		[0x17] = {"fload", LV1},
		[0x18] = {"dload", LV1},
		[0x19] = {"aload", LV1},

		[0x36] = {"istore", LV1},
		[0x37] = {"lstore", LV1},
		[0x38] = {"fstore", LV1},
		[0x39] = {"dstore", LV1},
		[0x3A] = {"astore", LV1},

		[0xC4] = {"wide", NO_OP},

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

		[0x2E] = {"iaload", NO_OP},
		[0x2F] = {"laload", NO_OP},

		[0x30] = {"faload", NO_OP},
		[0x31] = {"daload", NO_OP},
		[0x32] = {"aaload", NO_OP},

		[0x33] = {"baload", NO_OP},
		[0x34] = {"caload", NO_OP},
		[0x35] = {"saload", NO_OP},

		[0x4F] = {"iastore", NO_OP},
		[0x50] = {"lastore", NO_OP},
		[0x51] = {"fastore", NO_OP},
		[0x52] = {"dastore", NO_OP},
		[0x53] = {"aastore", NO_OP},

		[0x54] = {"bastore", NO_OP},
		[0x55] = {"castore", NO_OP},
		[0x56] = {"sastore", NO_OP},

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

		[0x57] = {"pop", NO_OP},
		[0x58] = {"pop2", NO_OP},

		[0x59] = {"dup", NO_OP},
		[0x5A] = {"dup_x1", NO_OP},
		[0x5B] = {"dup_x2", NO_OP},
		[0x5C] = {"dup2", NO_OP},
		[0x5D] = {"dup2_x1", NO_OP},
		[0x5E] = {"dup2_x2", NO_OP},

		[0x5F] = {"swap", NO_OP},

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

		[0xA7] = {"goto", OFFSET2},
		[0xC8] = {"goto_w", OFFSET4},

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

		[0x94] = {"lcmp", NO_OP},

		[0x95] = {"fcmpl", NO_OP},
		[0x96] = {"fcmpg", NO_OP},
		[0x97] = {"dcmpl", NO_OP},
		[0x98] = {"dcmpg", NO_OP},

		[0xC6] = {"ifnull", OFFSET2},
		[0xC7] = {"ifnonnull", OFFSET2},

		[0xA5] = {"if_acmpeq", OFFSET2},
		[0xA6] = {"if_acmpne", OFFSET2},

		[0xAA] = {"tableswitch", INTERROG},
		[0xAB] = {"lookupswitch", INTERROG},

		[0xB6] = {"invokevirtual", CP2},
		[0xB7] = {"invokespecial", CP2},
		[0xB8] = {"invokestatic", CP2},
		[0xB9] = {"invokeinterface", CP2_INT1},

		[0xAC] = {"ireturn", NO_OP},
		[0xAD] = {"lreturn", NO_OP},
		[0xAE] = {"freturn", NO_OP},
		[0xAF] = {"dreturn", NO_OP},
		[0xB0] = {"areturn", NO_OP},

		[0xB1] = {"return", NO_OP},

		[0xBB] = {"new", CP2},
		[0xC0] = {"checkcast", CP2},
		[0xC1] = {"instanceof", CP2},

		[0xBC] = {"newarray", FLAG1},
		[0xBD] = {"anewarray", CP2},

		[0xC5] = {"multianewarray", CP2_INT1},
		[0xBE] = {"arraylength", NO_OP},
		[0xA8] = {"jsr", OFFSET2},
		[0xC9] = {"jsr_w", OFFSET4},
		[0xA9] = {"ret", LV1},

		[0xBF] = {"athrow", NO_OP},
		[0xC2] = {"monitorenter", NO_OP},
		[0xC3] = {"monitorexit", NO_OP},
		[0xCA] = {"breakpoint", NO_OP},
		[0xBA] = {"xxxunusedxxx", NO_OP}
	};

	memcpy(vetorRetorno,instrucoes,sizeof instrucoes);

	return vetorRetorno;
}