#include "class_reader.h"

class_file *carregar_classe(char *nome_arquivo){
	FILE *pt_arquivo = NULL;
	class_file *pt_classe = NULL;

	// Tenta abrir o arquivo passado para leitura
	// caso não consiga, retorna falso e termina a execução
	pt_arquivo = abrir_arquivo_leitura(nome_arquivo);
	if(pt_arquivo == NULL){
		return NULL;
	}

	// Tenta alocar espaço na memória para a estrutura da classe
	// caso não consiga, retorna falso e termina a execução
	pt_classe = (class_file *) malloc(sizeof(class_file)); // TODO DESALOCAR
	if(pt_classe == NULL){
		return NULL;
	}

	// Tentar ler magic number do arquivo, caso não exista, retorna falso
	// e termina a execução
	pt_classe->magic = ler_u4(pt_arquivo);
	if(!validar_magic(pt_classe->magic)){
		return NULL;
	}

	// Tenta ler minor e major version, caso estejam corretos continua a leitura
	// da classe, caso contrário retorna falso
	pt_classe->minor_version = ler_u2(pt_arquivo);
	pt_classe->major_version = ler_u2(pt_arquivo);
	if(!validar_version(pt_classe->minor_version, pt_classe->major_version)){
		return NULL;
	}

	// Tentar ler o número de entradas da cosntant pool
	pt_classe->constant_pool_count = ler_u2(pt_arquivo);

	// Tenta ler as constantes da constant pool
	pt_classe->constant_pool = carregar_constant_pool(pt_classe->constant_pool_count, pt_arquivo);

	// TODO é realmente necessário fazer algum tipo de leitura diferente para access flag?
	// Tenta ler o valor de access flag
	pt_classe->access_flags = ler_u2(pt_arquivo);

	// Tenta ler o valor de this class, index para estrutura na constant pool
	// que representa a classe ou interface
	pt_classe->this_class = ler_u2(pt_arquivo);

	// Tenta ler o valor de super_class. Caso seja diferente de zero, é um index
	// para estrutura na constant_pool que representa a superclasse direta de this_class
	pt_classe->super_class = ler_u2(pt_arquivo);

	// Tenta ler o valor de interfaces_count. Representa o número de superinterfaces
	// diretas dessa classe ou interface type
	pt_classe->interfaces_count = ler_u2(pt_arquivo);

	// Tenta ler o array interfaces. Cada elemento representa uma interface que é
	// superinterface direta dessa classe ou interface type
	pt_classe->interfaces = ler_interfaces(pt_classe->interfaces_count, pt_arquivo);

	// Tenta ler o número de campos para essa classe
	pt_classe->fields_count = ler_u2(pt_arquivo);

	// Tenta carregar o array de fields. Cada elemento representa uma estrutura
	// contendo informações do field
	pt_classe->fields = carregar_fields(pt_classe->fields_count, pt_classe->constant_pool_count,
						pt_classe->constant_pool, pt_arquivo);

	// Tenta ler o número de métodos para essa classe
	pt_classe->methods_count = ler_u2(pt_arquivo);

	// Tenta carregar o array de métodos. Cada elemento representa uma estrutura
	// contendo informações do método
	pt_classe->methods = carregar_methods(pt_classe->methods_count, pt_classe->constant_pool_count,
						 pt_classe->constant_pool, pt_arquivo);

	// Tentar ler o número de atributos para essa classe
	pt_classe->attributes_count = ler_u2(pt_arquivo);

	// Tenta carregar o array de atributos. Cada elemento representa uma estrutura
	// coontendo informações do atributo
	pt_classe->attributes = carregar_atributos(pt_classe->attributes_count, pt_classe->constant_pool_count,
							pt_classe->constant_pool, pt_arquivo);

    // Tenta fechar o arquivo depois que a classe foi completamene carregada
	fechar_arquivo(pt_arquivo);
	return pt_classe;
}

u2 *ler_interfaces(u2 interfaces_count, FILE *pt_arquivo){
	u2 *pt_interfaces = NULL;
	int i = 0; // flag auxiliar do for

	// Tenta alocar o array de índices das interfaces na memória
	pt_interfaces = (u2 *) malloc(sizeof(u2)*interfaces_count);
	if(pt_interfaces == NULL) return false; // retorna false caso não haja espaço

	for(i = 0; i < interfaces_count; i++){
		*(pt_interfaces + i) = ler_u2(pt_arquivo);
	}

	return pt_interfaces;
}
