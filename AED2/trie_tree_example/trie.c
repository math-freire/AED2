#include <stdlib.h>

#include "trie.h"

ASCIITrie *ATE_Buscar_R(ASCIITrie *T, unsigned char *chave, int n, int p){

    if(T == NULL)
        return NULL;

    if(p == n)
        return T;

// o caracter atual da busca equivale a profundidade p (posicao na palavra)
    return ATE_Buscar_R(T -> filhos[chave[p]], chave, n, p+1);
}

ASCIITrie *ATE_Buscar(ASCIITrie *T, unsigned char *chave){
    // Se a palavra tem 5 letras e seguimos 5 links existentes daquela palavra, 
    // entao achamos a palavra
    return ATE_Buscar_R(T, chave, strlen(chave), 0);
}