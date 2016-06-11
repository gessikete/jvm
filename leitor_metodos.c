<<<<<<< HEAD
#include "leitor_metodos.h"

method_info *carregar_methods(u2 methods_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo){
    method_info *method = NULL;
    int i = 0; // índice para laço for

    // Tenta alocar na memória espaço para o vetor de métodos
    method = (method_info *) malloc(sizeof(method_info) * methods_count);
    if(method == NULL){
        return false;
    }

    // Tenta ler todos os ítens da estrutura method_info para cada método
    for(i = 0; i < methods_count; i++){
        // Tenta ler a access_flag para esse método
        method[i].access_flags = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do nome desse método
        method[i].name_index = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do descritor desse método
        method[i].descriptor_index = ler_u2(pt_arquivo);

        // Tenta ler o número de atributos adicionais desse método
        method[i].attributes_count = ler_u2(pt_arquivo);

        // Tenta carregar o array de estruturas attribute_info desse método
        method[i].attributes = carregar_atributos(pt_arquivo, method[i].attributes_count, constant_pool, constant_pool_count);
        if(method[i].attributes == NULL){
            return false;
        }
    }

    return method;
}

void desalocar_metodos(method_info *methods, u2 methods_count){
    if(methods != NULL){
        u2 i = 0; // índice para o loop for
        // percorre o array de methods procurando por attributes para desalocar
        for(i = 0; i < methods_count; i++){
            desalocar_atributos((methods + i)->attributes, (methods + i)->attributes_count);
        }
        // desaloca o array de methods
        free(methods);
    }
}
=======
#include "leitor_metodos.h"

method_info *carregar_methods(u2 methods_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo){
    method_info *method = NULL;
    int i = 0; // índice para laço for

    // Tenta alocar na memória espaço para o vetor de métodos
    method = (method_info *) malloc(sizeof(method_info) * methods_count);
    if(method == NULL){
        return false;
    }

    // Tenta ler todos os ítens da estrutura method_info para cada método
    for(i = 0; i < methods_count; i++){
        // Tenta ler a access_flag para esse método
        method[i].access_flags = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do nome desse método
        method[i].name_index = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do descritor desse método
        method[i].descriptor_index = ler_u2(pt_arquivo);

        // Tenta ler o número de atributos adicionais desse método
        method[i].attributes_count = ler_u2(pt_arquivo);

        // Tenta carregar o array de estruturas attribute_info desse método
        method[i].attributes = carregar_atributos(pt_arquivo, method[i].attributes_count, constant_pool, constant_pool_count);
        if(method[i].attributes == NULL){
            return false;
        }
    }

    return method;
}

void desalocar_metodos(method_info *methods, u2 methods_count){
    if(methods != NULL){
        u2 i = 0; // índice para o loop for
        // percorre o array de methods procurando por attributes para desalocar
        for(i = 0; i < methods_count; i++){
            desalocar_atributos((methods + i)->attributes, (methods + i)->attributes_count);
        }
        // desaloca o array de methods
        free(methods);
    }
}
>>>>>>> 94b58d49e25992e30a5e81adaa8a8fa1717ed5c8
