#include "trie.h"

no *criarNo(void) {
    no *novo = (no*)malloc(sizeof(no));

    if (novo != NULL){
        novo -> tipo = 'I';

        for(int i=0; i<TAMANHO_ALFABETO; i++)
            novo -> filho[i] = NULL;
    }
    return novo;
}

void apagarArvore(no *raiz) {
    // IMPLEMENTAR !!!
    // Dica 1: Desaloque todos os nos filhos e depois desaloca o no atual.
    // Dica 2: Usar recursao facilita!
}

void adicionarPalavra(char *palavra, no *raiz) {

    int nivel = 0, indice;
    no *cursor = raiz;
    
    for(nivel; nivel < strlen(palavra); nivel++){
        indice = CHAR_TO_INDEX(palavra[nivel]);
        if(cursor -> filho[indice] == NULL) //caso nao tenha essa letra na arvore
            cursor -> filho[indice] = criarNo();
        cursor = cursor -> filho[indice];
    }

    // Chegou ao final da palavra, marcar tipo palavra 'P'
    cursor -> tipo = 'P';
}

int buscaPalavra(char *palavra, no *raiz) {
    // IMPLEMENTAR !!!
    // Dica 1: Funcao similar ao adicionarPalavra
    // Dica 2: Se o ultimo noh que representa o ultimo caractere for do tipo 'I', a palavra nao existe
    // IMPORTANTE:
    //   retorne 0 se a palavra nao exite
    //   retorne 1 se a palavra existir
    return 0;
}

int numeroDeNos(no *r) {
    // IMPLEMENTAR !!!
    // Dica: A funcao pode ser muito simples se utilizar recursao
    return 0;
}

int numeroDePalavras(no *r) {
    // IMPLEMENTAR !!!
    // Dica: Similar a funcao numeroDeNos, mas contabilize apenas os tipos 'P', que representa as palavras
    return 0;
}

int altura(no *r) {
    // IMPLEMENTAR !!!
    // Dica: A funcao pode ser muito simples se utilizar recursao
    return 0;
}

void removerPalavra(char *palavra, no *raiz) {
    // IMPLEMENTAR !!!
    // Nota: Esta funcao eh a mais elaborada. Recomendo criar funcoes auxiliares e utilizar recursao
}
