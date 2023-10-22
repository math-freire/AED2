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

    no *cursor = raiz;

    for(int i = 0; i < TAMANHO_ALFABETO; i++){
        if(cursor -> filho[i] != NULL)
            apagarArvore(cursor -> filho[i]);
        else if ((i == TAMANHO_ALFABETO - 1)) {
            free(cursor);
            cursor = NULL;
        }
    }
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
    int indice;
    no *cursor = raiz;
    for(int nivel = 0; nivel < strlen(palavra); nivel++){
        indice = CHAR_TO_INDEX(palavra[nivel]);
        if(cursor -> filho[indice] != NULL){
            if(cursor -> filho[indice] -> tipo == 'P')
                return 1;
            cursor = cursor -> filho[indice];
        }
    }
    return 0;
}

int numeroDeNos(no *r) {
    int count = 0;

    for(int i = 0; i < TAMANHO_ALFABETO; i++)
        if(r -> filho[i] != NULL)
            count =+ numeroDeNos(r -> filho[i]);
    
    return count += 1;
}

int numeroDePalavras(no *r) {

    int count = 0;

    for(int i = 0; i < TAMANHO_ALFABETO; i++)
        if(r -> filho[i] != NULL)
            count =+ numeroDeNos(r -> filho[i]);
    
    if(r -> tipo == 'P')
        return count += 1;
    else
        return count += 0;
}

int altura(no *r) {
    // IMPLEMENTAR !!!
    // Dica: A funcao pode ser muito simples se utilizar recursao
    
    if(r == NULL) 
        return -1;

    if(!r) 
        return 0;

    int alt = 0;
    int alturaM = 0;
    
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        alt = altura(r->filho[i])+1;
        if(alt > alturaM){
            alturaM = alt;
        }
    }
    return alturaM;
}

void remover_recursiva(char *palavra, no *cursor, int n, int p){

    if(cursor == NULL)
        return;
    
    // profundidade = tamanho da palavra entao achou a palavra
    if(p == n)
        cursor -> tipo = 'I';
    else remover_recursiva(palavra, cursor -> filho[palavra[p]], n, p+1);

    // verificar se esta numa palavra enquanto volta na recursao
    if(cursor -> tipo == 'P')
        return;

    // caso seja um no intermediario, verificar se tem algum filho antes de remover
    for(int i = 0; i < TAMANHO_ALFABETO; i++){
        if(cursor->filho[i] != NULL)
            return;
    }
        free(cursor);
        cursor = NULL;
}

void removerPalavra(char *palavra, no *raiz) {
    remover_recursiva(palavra, raiz, strlen(palavra), 0);
}
