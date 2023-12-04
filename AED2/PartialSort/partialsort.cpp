// #include "partialsort.h"

void MinHeapify(int A[], int m, int i) {
    int e = 2 * i;      // filho esquerdo
    int d = 2 * i + 1;  // filho direito

    int menor;

    // se existe elemento esquerdo e se o elemento esquerdo for menor que o elemento do meio
    if (e <= m && A[e] < A[i])
        menor = e;
    else
        menor = i;

    // se existe elemento direito e se o elemento direito for menor que o atual menor (que pode ser o do meio ou da esquerda)
    if (d <= m && A[d] < A[menor])
        menor = d;

    // Caso o menor tenha sido alterado, reordenar o vetor (consequentemente a árvore)
    if (menor != i) {
        int temp = A[i];
        A[i] = A[menor];
        A[menor] = temp;
        MinHeapify(A, m, menor);  // recursivamente até ficar corrigido
    }
}

void BuildMinHeap(int A[], int n) {
    for (int i = A[0] / 2; i >= 1; i--)
        MinHeapify(A, n, i);
}

void PartialHeapSortInverse(int A[], int n, int k) {
    // IMPORTANTE: Considere que o A[0] contem o tamanho da lista, e os elementos estao nas posicoes de 1 ate n (inclusive)
    // DICA: Construa o MinHeap e insira os menores elementos no fim da lista (muito similar ao HeapSort, mas com os menores elementos)
    //       Lembre-se de parar com k elementos!
    //       A LISTA FICARA INVERTIDA, ou seja, o menor elemento eh o ultimo, depois o penultimo... e assim por diante...

    BuildMinHeap(A, A[0]);

    for (int i = n; i > n - k; i--) {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;

        MinHeapify(A, i - 1, 1);  // Mantém as propriedades de MinHeap para os elementos restantes
    }
}

void PartialHeapSort(int A[], int n, int k) {
    // IMPLEMENTAR
    // IMPORTANTE: Diferente das funcoes anteriores, os elementos comecam na posicao 0, e a saida nao sera invertida
    // DICA: 1) Crie um novo array com tamanho n+1
    //       2) Copie todos os elementos deslocado em um para o novo array
    //       3) Chame o PartialHeapSortInverse
    //       4) Copie novamente os elementso para o array original, invertendo a ordem e iniciando na posicao 0
}
