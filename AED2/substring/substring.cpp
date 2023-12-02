#include "substring.h"  // typedef unsigned char *bytes;

#include "main.h"

// Use 0 se o vetor a e b (palavra e texto) inicia em 0 (a[0..m-1] e b[0..n-1])
//  ou 1 se o vetor a e b (palavra e texto) inicia em 1 (a[1..m]   e b[1..n])
int inicia_em = 0;

// Funcao que verifica se existe a ocorrencia da palavra 'a' no texto 'b', alinhado pelo último caractere da palavra.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// pos_ult_carac    Posição do texto b[pos_ult_carac+inicia_em-1] alinhado com a última letra da palavra (a[m+inicia_em-1])
// RETORNO  Verdadeiro se exisitr a ocorrêncai da palavra 'a' no texto 'b' na posição 'pos_ult_carac'. Falso caso contrário.
bool verifica_ocorrencia(char *a, int m, char *b, int n, int pos_ult_carac) {
    // criar um laço para o texto e se acertar a primeira letra criar um laço para a palavra
    // verificar se o texto não acabou***

    if (n) {  // se o texto existe
        // percorre o texto
        for (b[inicia_em]; b[n - 1]; b[inicia_em++]) {
            // achou a primeira letra da palavra
            if (b[inicia_em] == a[0]) {
                // vai percorrendo a palavra para testar se é igual, mas se não for, o looping do texto vai testar de novo a letra seguinte
                // pode acontecer da palavra ser "BAB" e no texto ter "BBBAB"
                for (int i = 0; m - 1; i++) {
                    // Se a letra não estiver certa
                    if (b[inicia_em] != '\0') {  // checar se a palavra não acabou
                        if (b[inicia_em] != a[i]) {
                            // letra está certa, ver se terminou
                        } else if (i == m - 1)
                            return true;
                    }
                    inicia_em++;
                }
            }
        }

        // terminou o texto e não achou
        return false;
    }

    return false;
}

// Funcao que calcula a quantidade de ocorrencias de 'a' em 'b'.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// RETORNO  Quantidade de ocorrências de a em b.
int ocorrencias(char *a, int m, char *b, int n) {
    // IMPLEMENTAR !!!
    return 0;
}

// Funcao que retorna a posicao do primeiro caractere de 'a' em 'b' durante a primeira ocorrecnai de 'a'.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// RETORNO  A posicao do primeiro caractere da palavra 'a' em 'b' iniciado em 'inicia_em'. Caso nao houver ocorrencias, retornar -1.
int primeira_ocorrencia(char *a, int m, char *b, int n) {
    // IMPLEMENTAR !!!
    return -1;
}

// Funcao que retorna a posicao do primeiro caractere de 'a' em 'b' durante a ultima ocorrecnai de 'a'.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// RETORNO  A posicao do primeiro caractere da palavra 'a' em 'b' iniciado em 'inicia_em'. Caso nao houver ocorrencias, retornar -1.
int ultima_ocorrencia(char *a, int m, char *b, int n) {
    // IMPLEMENTAR !!!
    return -1;
}

// Funcao que constroi o vetor 'ultimo', ja alocado com o tamanho 'tamanho_alfabeto', contendo a posicao da ultima ocorrencia do respectivo caractere na palavra 'a'.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// ultimo           Vetor tipo inteiro dos indice de cada caractere contendo a ultimoa ocorrencia em 'a'.
//                    Obs.1: O vetor ja esta alocado com o tamanho 'tamanho_alfabeto'.
//                    Obs.2: Eh preciso zerar todo o vetor. Caracteres inexistentes devem conter o valor 0.
//                    Obs.3: O primeiro caractere tem a posicao 1, iniciado da esquerda para a direita.
// tamanho_alfabeto Tamanho do alfabeto e, consequentemente, o tamanho do vetor 'ultimo'.
void caractere_errado(char *a, int m, int *ultimo, int tamanho_alfabeto) {
    // IMPLEMENTAR !!!
    // Zerar 'ultimo' (jah alocado)
    // Preencher 'ultimo' com a ocorrencia do ultimo caractere em 'a'
}

// Funcao que constroi o vetor 'jump', ja alocado com o tamanho 'm' da palavra 'a', contendo o ultimo sufixo da palavra 'a'.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// jump           Vetor tipo inteiro que contem a ocorrencia do sufixo na propria palavra 'a'.
void sufixo_correto(char *a, int m, int *jump) {
    // IMPLEMENTAR !!!
    // Preencher 'jump' (jah alocado) com as ocorrencias de sufixos
}

// Funcao que retorna o salto calculado atraves da tecnica caractere errado.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// ultimo           Vetor tipo inteiro dos indice de cada caractere contendo a ultimoa ocorrencia em 'a'.
// tamanho_alfabeto Tamanho do alfabeto e, consequentemente, o tamanho do vetor 'ultimo'.
// posicao_atual    Posicao atual do texto 'b' que inicia em 'inicia_em'.
// RETORNO  Valor do salto.
int salto_caractere_errado(char *a, int m, char *b, int n, int *ultimo, int tamanho_alfabeto, int posicao_atual) {
    // IMPLEMENTAR !!!
    return 1;
}

// Funcao que retorna o salto calculado atraves da tecnica sufixo correto.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// jump             Vetor tipo inteiro que contem a ocorrencia do sufixo na propria palavra 'a'.
// posicao_atual    Posicao atual do texto 'b' que inicia em 'inicia_em'.
// RETORNO  Valor do salto.
int salto_sufixo_correto(char *a, int m, char *b, int n, int *jump, int posicao_atual) {
    // IMPLEMENTAR !!!
    return 1;
}

// Funcao que retorna o salto calculado atraves das tecnicas caractere errado e sufixo correto.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// ultimo           Vetor tipo inteiro dos indice de cada caractere contendo a ultimoa ocorrencia em 'a'.
// tamanho_alfabeto Tamanho do alfabeto e, consequentemente, o tamanho do vetor 'ultimo'.
// jump             Vetor tipo inteiro que contem a ocorrencia do sufixo na propria palavra 'a'.
// posicao_atual    Posicao atual do texto 'b' que inicia em 'inicia_em'.
// RETORNO  Valor do melhor salto entre as duas tecnicas caractere errado e sufixo correto.
int melhor_salto_na_posicao(char *a, int m, char *b, int n, int *ultimo, int tamanho_alfabeto, int *jump, int posicao_atual) {
    // IMPLEMENTAR !!!
    // Eh preciso utilizar as funcoes salto_caractere_errado e salto_sufixo_correto
    // Retornar o maior salto
    return 1;
}

// Funcao que conta ocorrencias da palavra 'a' no texto 'b' utilizando o algoritmo de Boyer-Moore.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// ultimo           Vetor tipo inteiro dos indice de cada caractere contendo a ultima ocorrencia em 'a' ja preenchido!
// tamanho_alfabeto Tamanho do alfabeto e, consequentemente, o tamanho do vetor 'ultimo'.
// jump             Vetor tipo inteiro que contem a ocorrencia do sufixo na propria palavra 'a' ja prenchido!
// RETORNO  Quantidade de ocorrências de a em b.
int boyer_moore(char *a, int m, char *b, int n, int *ultimo, int tamanho_alfabeto, int *jump) {
    // IMPLEMENTAR !!!
    // Eh preciso utilizar a funcao melhor_salto_na_posicao
    return 0;
}
