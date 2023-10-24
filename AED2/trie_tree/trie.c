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
    int i, indice;
    no *cursor = raiz;

    for(i = 0; i < strlen(palavra); i++){
        indice = CHAR_TO_INDEX(palavra[i]);

        if(cursor -> filho[indice] != NULL)
            cursor = cursor -> filho[indice];
        else 
            break;
    }

    if(palavra[i] == '\0' && cursor -> tipo == 'P')
        return 1;
    else
        return 0;
}

int numeroDeNos(no *r) {
    int count = 1;

    for(int i = 0; i < TAMANHO_ALFABETO; i++)
        if(r -> filho[i] != NULL)
            count += numeroDeNos(r -> filho[i]);
    
    return count;
}

int numeroDePalavras(no *r) {

    int count = 0;

    if(r -> tipo == 'P')
        count++;

    for(int i = 0; i < TAMANHO_ALFABETO; i++)
        if(r -> filho[i] != NULL)
            count += numeroDePalavras(r -> filho[i]);
    
        return count;
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

// Retorna 0 se o no nao tem filhos ou retorna 1 se tiver algum filho
int temFilhos(no* raiz)
{
    for (int i = 0; i < TAMANHO_ALFABETO; i++)
        if (raiz -> filho[i])
            return 1;
    return 0;
}

no* remover_recursiva(no *raiz, char *palavra, int tamanho, int profundidade){
    // Arvore vazia
    if (!raiz)
        return NULL;
    
    // Se chegamos no ultimo caracter
    if (profundidade == tamanho){
        // Se o no for removido, o atual nao vai mais ser final de palavra
        if(raiz -> tipo == 'P')
            raiz -> tipo = 'I';
        
        // Se o no atual nao for prefixo de nenhuma palavra
        if(temFilhos(raiz) == 0){
            free (raiz);
            raiz = NULL;
        }
    return raiz;
    }

    // Se nao for o ultimo, faz recursao para o filho
    int indice = CHAR_TO_INDEX(palavra[profundidade]);
    raiz -> filho[indice] = remover_recursiva(raiz->filho[indice], palavra, strlen(palavra), profundidade + 1);

    // Se a raiz nao tem filho (o unico foi deletado) e nao e fim de palavra
    if(temFilhos(raiz) == 0 && raiz -> tipo == 'I'){
        free(raiz);
        raiz = NULL;
    }

    return raiz;
}

void removerPalavra(char *palavra, no *raiz) {
    remover_recursiva(raiz, palavra, strlen(palavra), 0);
}
