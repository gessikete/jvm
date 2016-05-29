#include "leitor_campos.h"

field_info *carregar_fields(u2 fields_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo){
    field_info *pt_fields = NULL;
    u2 count_index = 0;

    /* Tenta alocar memoria para o vetor fields. */
    pt_fields = (field_info *) malloc(sizeof(field_info) * fields_count); 
    if(pt_fields == NULL){
        return false;
    }

    // Tenta ler todos os ítens da estrutura method_info para cada método
    for(count_index = 0; count_index < fields_count; count_index++){
        // Tenta ler a access_flag para o campo(varável) da classe
        pt_fields->access_flags = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do nome desse campo
        pt_fields->name_index = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do descritor desse campo
        pt_fields->descriptor_index = ler_u2(pt_arquivo);

        // Tenta ler o número de atributos adicionais desse campo
        pt_fields->attributes_count = ler_u2(pt_arquivo);

        // Tenta carregar o array de estruturas attribute_info desse campo
        pt_fields->attributes = carregar_atributos(pt_arquivo, pt_fields->attributes_count, constant_pool, constant_pool_count);
        if(pt_fields->attributes == NULL){
            return false;
        }
    }

    return pt_fields;
}

