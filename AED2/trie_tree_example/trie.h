#pragma once

typedef enum ASCIITrie_ESTADO{
    // Teremos o valor no noh final, isso eh necessario para saber se eh um noh
    // valido ou um noh intermediario do caminho
    // ((raiz)) -> r -> a -> t -> o -> (((noh que guarda a string rato)))
    ATE_LIVRE,
    ATE_OCUPADO
} ASCIITrie_ESTADO;

//Nao precisa ser toda a tabela ASCII, eh mais conveniente usar somente o tamanho
// do alfabeto (caracteres) a ser utilizado
typedef struct ASCIITrie{
    int val;
    ASCIITrie_ESTADO estado;
    struct ASCIITrie* filhos[256]; // 256 ponteiros para a ASCIITrie
} ASCIITrie;

ASCIITrie *ATE_BUSCAR(ASCIITrie *T, unsigned char *chave);
