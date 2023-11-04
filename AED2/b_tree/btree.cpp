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

int buscarChave(int n, const int *a, int chave){
    int lo = -1, hi = n, mid;
    while(lo + 1 < hi){
        mid = (lo + hi)/2;
        if(a[mid] == chave) 
            return mid;
        else if(a[mid] < chave) 
            lo = mid;
        else   
            hi = mid;        
    }
    return hi;
}

int btBuscar(btNo *b, int chave){
    // Retornar true se a chave nao existe false se a chave nao existe

    if(b -> numChaves == 0)
        return 0;

    // search recursively to find index
    int posicao = buscarChave(b -> numChaves, b -> chaves, chave);

    // key found
    if(posicao < b ->numChaves && b ->chaves[posicao] == chave)
        return 1;
    // key not found
    else
        return(!b -> ehFolha && btBuscar(b -> filhos[posicao], chave)); // key not found, try children if exist
}
int btBuscar(bTree b, int chave) {
    return btBuscar(b.raiz, chave);
}

btNo *inserirInterno(btNo *b, int chave, int *mediana, const unsigned char ordem);
void btInserir(bTree b, int chave) {
    btNo *b1; // new left node
    btNo *b2; // new right node
    int mediana; // middle node (going up)

    b2 = inserirInterno(b.raiz, chave, &mediana, b.ordem);

    if(b2) { // root needs to divide: create new root
        b1 = btCriarNo(b.ordem);
        for(unsigned char i = 0; i < b.ordem; i++){
            b1 -> chaves[i] = b.raiz -> chaves[i];
            b1 -> filhos[i] = b.raiz -> filhos[i];           
        }

        b1 -> filhos[b.ordem] = b.raiz -> filhos[b.ordem];

        b1 -> ehFolha = b.raiz -> filhos[b.ordem];
        b1 -> ehFolha = 0;

        b1 -> numChaves = b.raiz -> numChaves;
        b.raiz -> numChaves = 1;

        b.raiz -> chaves[0] = mediana;
        b.raiz -> filhos[0] = b1;
        b.raiz -> filhos[1] = b2;
    }
}

btNo *inserirInterno(btNo *b, int chave, int *mediana, const unsigned char ordem){
    int pos;
    int mid;
    btNo *b2;

    pos = buscarChave(b -> numChaves, b -> chaves, chave); // get position on the current node
    if(pos < b -> numChaves && b -> chaves[pos] == chave) // key already exist
        return 0;

    if(b -> ehFolha){  // found a leaf to insert. Put it on the right position
        for(int i = b -> numChaves; i > pos; i--)
            b -> chaves[i] = b -> chaves[i-1]; // All keys above 'pos' move a step up
        b -> chaves[pos] = chave;
        b -> numChaves++;
    } else {
        b2 = inserirInterno(b -> filhos[pos], chave, &mid, ordem);
        if(b2){
            for(int i = b -> numChaves; i > pos; i--){
                b -> chaves[i] = b -> chaves[i-1]; // All keys above 'pos' move a step up
                b -> filhos[i+1] = b -> filhos[i]; // All children above 'pos' move a step up
            }
            b -> chaves[pos] = mid;
            b -> filhos[pos + 1] = b2;
            b -> numChaves++;
        }
    }

    if(b->numChaves >= ordem){ // verify if it needs to divide b
        mid = b -> numChaves/2; // mediana index
        *mediana = b -> chaves[mid]; // copy mediana value to be used on the father function
        b2 = btCriarNo(ordem); // new leaf
        b2 -> numChaves = b -> numChaves - mid - 1;
        b2 -> ehFolha = b -> ehFolha;

        for(int i = mid+1; i < b -> numChaves; i++) // copy half from b to b2
            b2 -> chaves[i-(mid+1)] = b -> chaves[i]; // copy half from b to b2
        
        if(!b -> ehFolha) // if not leaf, copy children too
            for(int i = mid+1; i < b -> numChaves+1; i++) // every children above 'pos' move a step up
                b2 -> filhos[i-(mid+1)] = b -> filhos[i];
        
        b -> numChaves = mid; // now b have half the elements
        return b2;
    } 
    else
        return 0;
}


int btAltura(bTree b) {
    int count = 1;
    btNo *cursor = b.raiz;
    
    while(cursor -> numChaves){
        count++;
        cursor = cursor -> filhos[0];
    }

    return count;
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
