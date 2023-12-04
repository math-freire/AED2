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

    // se existe elemento esquerdo e se o elemento esquerdo for maior que o elemento do meio
    if (e <= A[0] && A[e] > A[i])
        maior = e;
    else
        maior = i;

    // se existe elemento direito e se o elemento direito for maior que o atual maior (que pode ser o do meio ou da esquerda)
    if (d <= A[0] && A[d] > A[maior])
        maior = d;

    // Caso o maior tenha sido alterado, reordenar o vetor (consequentemente a árvore)
    if (maior != i) {
        int temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        MaxHeapify(A, maior);  // recursivamente até ficar corrigido
    }
}

void BuildMaxHeap(tipoChave A[]) {
    // Rearranjar uma árvore inteira para que seja um max-Heap

    for (int i = A[0] / 2; i >= 1; i--)
        MaxHeapify(A, i);
}

void HeapSort(tipoChave A[]) {
    // IMPLEMENTAR
    // DICA: Como a funcao MaxHeapify nao tem o argumento tamanho (como nos slides),
    //       armazene o tamanho atual (t = A[0]), decremente A[0] antes de chamar
    //       MaxHeapify, entao restaure o valor A[0] = t no final.

    BuildMaxHeap(A);
    int tamanho = A[0];

    for (int i = A[0]; i >= 2; i--) {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;

        A[0] -= 1;
        MaxHeapify(A, 1);  // as duas subárvores são maxheaps, então essa função ordena o maior valor
        // na primeira posição, desconsiderando o último que é o maior do vetor que estamos ordenando
    }
    A[0] = tamanho;
}

tipoChave HeapMaximum(tipoChave A[]) {
    return A[1];  // sempre chamado em cima de um heap de maximo (BuildMaxHeap)
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
