#include "heap.h"
// #include "internal.h"

// ATENCAO!!! ATENCAO!!! ATENCAO!!!
// ATENCAO!!! ATENCAO!!! ATENCAO!!!
// ATENCAO!!! ATENCAO!!! ATENCAO!!!
// --- CONSIDERE O INDICE ZERO (A[0]) A QUANTIDADE DE ELEMENTOS
// --- CONSIDERE QUE O VETOR VAI DE 1 ATE N (E NAO DE 0 ATE N-1)
// --- CONSIDERE QUE O VETOOR JA TEM UM TAMANHO SUFICIENTEMENTE GRANDE PARA A INSERCAO

void MaxHeapify(tipoChave A[], int i) {
    // Função que ordena o vetor heap para que tenha ordenação de árvores binárias
    // OBS.: O indice i vai de 1 ate A[0]

    int e = 2 * i;      // filho esquerdo
    int d = 2 * i + 1;  // filho direito

    int maior;

    if (e <= A[0] && A[e] > A[i])
        maior = e;
    else
        maior = i;

    if (d <= A[0] && A[d] > A[maior])
        maior = d;

    if (maior != i) {
        int temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        MaxHeapify(A, maior);
    }
}

void BuildMaxHeap(tipoChave A[]) {
    // IMPLEMENTAR
    // OBS.: Chamar a funcao MaxHeapify
}

void HeapSort(tipoChave A[]) {
    // IMPLEMENTAR
    // DICA: Como a funcao MaxHeapify nao tem o argumento tamanho (como nos slides),
    //       armazene o tamanho atual (t = A[0]), decremente A[0] antes de chamar
    //       MaxHeapify, entao restaure o valor A[0] = t no final.
}

tipoChave HeapMaximum(tipoChave A[]) {
    // IMPLEMENTAR
    // OBS.: Nao esqueca que o primeiro elemento eh o A[1]
    return 0;
}

tipoChave HeapExtractMax(tipoChave A[]) {
    // IMPLEMENTAR
    // OBS.: Nao precisa tratar o caso do vetor vazio!
    return 0;
}

void HeapIncreaseKey(tipoChave A[], int i, tipoChave key) {
    // IMPLEMENTAR
    // OBS.: Nao precisa tratar o caso da chave alterada for menor que a chave atual!
}

void MaxHeapInsert(tipoChave A[], tipoChave key) {
    // IMPLEMENTAR
    // OBS.: Nao esquecer de aumentar a quantidade de elementos, ou seja, A[0]++
}
