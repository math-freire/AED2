#include <stdlib.h>
#include "btree.h"

btNo* btCriarNo(const unsigned char ordem);
bTree btCriar(const unsigned char ordem) {
    bTree b;
    b.ordem = ordem;
    b.raiz = btCriarNo(ordem);
    return b;
}

btNo* btCriarNo(const unsigned char ordem){
    btNo *no = (btNo*) malloc(sizeof(btNo));
    no -> ehFolha = 1; // is leaf at the start
    no -> numChaves = 0;
    no -> chaves = (int*) malloc(sizeof(*no->chaves) * ordem);
    no -> filhos = (btNo**) malloc(sizeof(*no->filhos) * (ordem+1));
    return no;
}

void btDestruir(btNo *no);
void btDestruir(bTree b) {
    int i;
    if(b.raiz)
        btDestruir(b.raiz);
}
void btDestruir(btNo *no){
    if(!no)
        return;

    if(!no -> ehFolha){ // children first, therefore will access the leafs
        for(int i = 0; i < no -> numChaves; i++)
            btDestruir(no -> filhos[i]);  
    }

    // free leafs
    free(no -> chaves);
    free(no -> filhos);
    free(no);
}



void btInserir(bTree b, int chave) {
    // IMPLEMENTAR!
    // DICA 1: Crie funcoes auxiliares
    // DICA 2: Seguir o material de aula
}


int buscarChave(int n, const int *a, int chave){

}

int btBuscar(bTree b, int chave) {
    // Retornar true se a chave nao existe false se a chave nao existe

    if(b.raiz -> numChaves == 0)
        return 0;

    // search recursively to find index
    int posicao = buscarChave(b.raiz -> numChaves, b.raiz -> chaves, chave);

    // key found
    if(posicao < b.raiz ->numChaves && b.raiz ->chaves[posicao] == chave)
        return 1;
    // key not found
    else
        return(!b.raiz -> ehFolha && btBuscar(b -> filhos[posicao], chave));
}



int btAltura(bTree b) {
    // IMPLEMENTAR!
    // DICA: Como todos os nos folhas estao no mesmo nivel em uma arvore B, busque qualquer noh folha contando a sua profundidade
    return 0;
}




int btContaNos(bTree b) {
    // IMPLEMENTAR!
    // DICA: Implemente de modo recursivo
    return 0;
}



int btContaChaves(bTree t) {
    // IMPLEMENTAR!
    // DICA: Muito similar a funcao btContaNos
    return 0;
}
