#include "leitor_metodos.h"

method_info *carregar_methods(u2 methods_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo){
    method_info *pt_method = NULL;
    int i = 0; // índice para laço for

    // Tenta alocar na memória espaço para o vetor de métodos
    pt_method = (method_info *) malloc(sizeof(method_info) * methods_count); // TODO DESALOCAR DA MEMÓRIA NO FINAL DE TODA A EXECUÇÃO
    if(pt_method == NULL){
        return false;
    }

    // Tenta ler todos os ítens da estrutura method_info para cada método
    for(i = 0; i < methods_count; i++){
        // Tenta ler a access_flag para esse método
        pt_method->access_flags = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do nome desse método
        pt_method->name_index = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do descritor desse método
        pt_method->descriptor_index = ler_u2(pt_arquivo);

        // Tenta ler o número de atributos adicionais desse método
        pt_method->attributes_count = ler_u2(pt_arquivo);

        // Tenta carregar o array de estruturas attribute_info desse método
        pt_method->attributes = carregar_atributos(pt_arquivo, pt_method->attributes_count, constant_pool, constant_pool_count);
        if(pt_method->attributes == NULL){
            return false;
        }
    }

    return pt_method;
}
