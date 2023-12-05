#include "huffman.h"

#include <stdlib.h>
#include <string.h>

void criarAlfabeto(char *texto, int tamanho_texto, char *alfabeto[], int *frequencia[], int *tamanho) {
    // IMPLEMENTAR
    //   - texto: texto original com tamanho_texto caracteres
    //   - tamanho_texto: tamanho do texto (quantidade de caracteres)
    //   - alfabeto: parametro de saida. Vetor tipo char com os carecteres existentes. Exemplo: para o texto "banana", o vetor seria "{'a', 'b', 'n'}.
    //               Importante: Deve estar ordenado, de acordo com a tabela ASCII.
    //               Importante: Deve ser alocado (malloc) de acordo com a variedade de caracteres encontradas no texto. Por exemplo, para o texto "ABCABCAB", o tamanho seria de 3.
    //               Importante: Considerar quebra de linha, pontuacao e espaco como caractere valido. Distinguir caractere maiuscula de minuscula.
    //   - frequenca: parametro de saida. Vetor de inteiros, complementar ao vetor alfabeto, contendo a quantidade de ocorrencias.
    //   - tamanho: tamanho do vetor alfabeto e frequencia, referente a variedade de caracteres.
    // EXEMPLO: texto:    "Bom dia, tudo bem?"
    //          alfabeto:  {' ', ',', '?', 'B', 'a', 'b', 'd', 'e', 'i', 'm', 'o', 't', 'u' }
    //          frequencia:{ 3 ,  1 ,  1 ,  1 ,  1 ,  1 ,  2 ,  1 ,  1 ,  2 ,  2 ,  1 ,  1  }
    //          tamanho:   13
    // DICA:

    //  - Crie uma variavel caracteres tipo vetor de inteiro com tamanho 255 (tipos maximos de caractere), com todos valores em zero
    char caracteres[255];
    int freq[255];
    for (int i = 0; i < 255; i++) {
        caracteres[i] = 0;
        freq[i] = 0;
    }

    //  - Faca um laco percorrendo todo o texto, incrementando este vetor em cada ocorrencia de caractere
    //  - Aproveite o mesmo laco para calcular a variavel de saida tamanho (tipos distintos de caracteres presente no texto)
    *tamanho = 0;
    for (int i = 0; i < tamanho_texto; i++) {
        if (caracteres[texto[i]] != texto[i]) {
            caracteres[texto[i]] = texto[i];
            (*tamanho)++;
        }
        freq[texto[i]]++;
    }

    //  - Alocar as variaveis de saida alfabeto e frequencia
    for (int i = 0; i < *tamanho; i++) {
        alfabeto[i] = (char *)malloc(2 * sizeof(char));
        frequencia[i] = (int *)malloc(sizeof(int));
    }

    //  - Percorra todos os caracteres em um novo laco e insira no alfabeto e frequencia o caractere e a quantidade de ocorrencias respectivamente
    int posicao = 0;
    for (int i = 0; i < 255; i++) {
        if (caracteres[texto[i]] != 0) {
            alfabeto[posicao][0] = caracteres[i];
            *frequencia[posicao] = freq[i];
            posicao++;
        }
    }
}

struct MinHeapNode *buildHuffmanTree(char alfabeto[], int frequencia[], int tamanho) {
    // Passo 1: Criar e construir MinHeap com capacidade igual ao tamanho passando alfabeto, frequencia e tamanho como argumento
    // Criar um laco, enquanto houver dois elementos na heap
    //     Passo 2: Extrair os dois caracteres/nos com menor frequencia da heap
    //       ATENCAO: o menor elemento deve ser insirido no noh esquerdo, e o segundo menor no noh direito
    //       DICA: Use a funcao extractMin, jah implementado
    //     Passo 3: Criar um novo noh interno com frequencia igual a soma dos nos extraidos da heap.
    //       ATENCAO: utilize '$' como um valor especial utilizado em nos intermediarios
    //       DICA: Utilize a funcao newNode (jah implementado), passe a soma das frquencias dos filhos esquerdo e direto como valor
    //       DICA: Nao esqeuca de atribuir os filhos esquerdo e direito, obtido no passo 2
    //       LEMBRE-SE: insira este noh novamente na heap, usando a funcao insertMinHeap, jah implementado
    // Passo 4: Extrair o no raiz, que representa a raiz da arvore de huffman! Retorno o noh raiz.
    //   LEMBRE-SE: Chame o destroyMinHeap para liberar a estrutura heap.
    return NULL;
}

void destroyHuffmanTree(struct MinHeapNode *root) {
    // IMPLEMENTAR: Libera da memoria toda a arvore de Huffman
}

void generateCodesArray(struct MinHeapNode *root, codes_t codes) {
    // IMPLEMENTAR: Gerar o vetor codes de acordo com a arvore de huffman
    // IMPORTANTE: Atribuir 0 para os filhos esquerdos, e 1 para os filhos direitos
    // DICA: A estrutura codes_t esta descrita no arquivo huffman.h
}

long sizeOfTextCompressed(char *texto, long tamanho, codes_t codes) {
    // IMPLEMENTAR: Utilizando o dicionario (codes), calcular o tamnho do texto apos a codificacao
    // IMPORTANTE: Considerar o tamnho em bits
    // DICA: Percorra o texto e obtenha a quantidade de bits de cada caractere (codes[texto[i]][0])
    return 0;
}
