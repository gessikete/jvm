<<<<<<< HEAD
#include "leitor_campos.h"

field_info *carregar_fields(u2 fields_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo){
    field_info *fields = NULL;
    u2 count_index = 0;

    /* Tenta alocar memoria para o vetor fields. */
    fields = (field_info *) malloc(sizeof(field_info) * fields_count);
    if(fields == NULL){
        return false;
    }

    // Tenta ler todos os ítens da estrutura method_info para cada método
    for(count_index = 0; count_index < fields_count; count_index++){
        // Tenta ler a access_flag para o campo(varável) da classe
        fields[count_index].access_flags = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do nome desse campo
        fields[count_index].name_index = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do descritor desse campo
        fields[count_index].descriptor_index = ler_u2(pt_arquivo);

        // Tenta ler o número de atributos adicionais desse campo
        fields[count_index].attributes_count = ler_u2(pt_arquivo);

        // Tenta carregar o array de estruturas attribute_info desse campo
        fields[count_index].attributes = carregar_atributos(pt_arquivo, fields[count_index].attributes_count, constant_pool, constant_pool_count);
        if(fields[count_index].attributes == NULL){
            return false;
        }
    }

    return fields;
}

void desalocar_campos(field_info *fields, u2 fields_count){
    if(fields != NULL){
        u2 i = 0; // índice para o loop for
        // Percorre o array de fields em procura de attributes para desalocar
        for(i = 0; i < fields_count; i++){
            desalocar_atributos((fields + i)->attributes, (fields + i)->attributes_count);
        }

        // Desaloca o array de fields
        free(fields);
    }
}
=======
#include "leitor_campos.h"

field_info *carregar_fields(u2 fields_count, u2 constant_pool_count, cp_info *constant_pool, FILE *pt_arquivo){
    field_info *fields = NULL;
    u2 count_index = 0;

    /* Tenta alocar memoria para o vetor fields. */
    fields = (field_info *) malloc(sizeof(field_info) * fields_count);
    if(fields == NULL){
        return false;
    }

    // Tenta ler todos os ítens da estrutura method_info para cada método
    for(count_index = 0; count_index < fields_count; count_index++){
        // Tenta ler a access_flag para o campo(varável) da classe
        fields[count_index].access_flags = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do nome desse campo
        fields[count_index].name_index = ler_u2(pt_arquivo);

        // Tenta ler o índice para a constant_pool do descritor desse campo
        fields[count_index].descriptor_index = ler_u2(pt_arquivo);

        // Tenta ler o número de atributos adicionais desse campo
        fields[count_index].attributes_count = ler_u2(pt_arquivo);

        // Tenta carregar o array de estruturas attribute_info desse campo
        fields[count_index].attributes = carregar_atributos(pt_arquivo, fields[count_index].attributes_count, constant_pool, constant_pool_count);
        if(fields[count_index].attributes == NULL){
            return false;
        }
    }

    return fields;
}

void desalocar_campos(field_info *fields, u2 fields_count){
    if(fields != NULL){
        u2 i = 0; // índice para o loop for
        // Percorre o array de fields em procura de attributes para desalocar
        for(i = 0; i < fields_count; i++){
            desalocar_atributos((fields + i)->attributes, (fields + i)->attributes_count);
        }

        // Desaloca o array de fields
        free(fields);
    }
}
>>>>>>> 94b58d49e25992e30a5e81adaa8a8fa1717ed5c8
