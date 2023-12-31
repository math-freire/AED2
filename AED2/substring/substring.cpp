// #include "substring.h"  // typedef unsigned char *bytes;
// #include "main.h"

// Use 0 se o vetor a e b (palavra e texto) inicia em 0 (a[0..m-1] e b[0..n-1])
//  ou 1 se o vetor a e b (palavra e texto) inicia em 1 (a[1..m]   e b[1..n])
int inicia_em = 0;

// Funcao que verifica se existe a ocorrencia da palavra 'a' no texto 'b', alinhado pelo último caractere da palavra.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// b                Vetor com o texto que inicia em 'inicia_em' (b[inicia_em..m+inicia_em-1])
// n                Tamanho de 'b' (texto)
// pos_ult_carac    Posição do texto b[pos_ult_carac+inicia_em-1] alinhado com a última letra da palavra (a[m+inicia_em-1])
// RETORNO  Verdadeiro se existir a ocorrência da palavra 'a' no texto 'b' na posição 'pos_ult_carac'. Falso caso contrário.

bool verifica_ocorrencia(char *a, int m, char *b, int n, int pos_ult_carac) {
    // Confere se a palavra e o texto existem
    if (n > 0 && m > 0) {
        // Calcula a posição inicial do texto alinhado pelo último caractere da palavra
        int inicio_alinhado = pos_ult_carac - m + 1;  // pos_ult_carac - (m-1)

        // Confere se a posição atual e valida: Se está dentro do vetor, nem negativo e nem maior que a palavra n
        if (inicio_alinhado < 0 || inicio_alinhado + m > n) {
            return false;  // Posição inicial inválida
        }

        // Confere se e uma ocorrência da palavra
        for (int i = 0; i < m; i++) {
            // A partir da referencia inicio_alinhado anda a palavra com auxilio de i
            if (a[i] != b[inicio_alinhado + i]) {
                return false;  // Letras não correspondem, a palavra não ocorre no texto
            }
        }
        return true;  // Palavra correspondeu
    } else
        return false;  // Texto ou palavra não existe
}

// Funcao que calcula a quantidade de ocorrencias de 'a' em 'b'.
// RETORNO  Quantidade de ocorrências de a em b.
int ocorrencias(char *a, int m, char *b, int n) {
    // para cada vez que achar o ultimo caracter da palavra, chamar a função de verificar como se fosse último caracter
    int contagem_de_ocorrencias = 0;

    for (int i = 0; i < n; i++) {
        if (verifica_ocorrencia(a, m, b, n, i))  // se tiver uma palavra ali, somar 1 no contador
            contagem_de_ocorrencias++;
    }
    return contagem_de_ocorrencias;
}

// Funcao que retorna a posição do primeiro caracter de 'a' em 'b' durante a primeira ocorrência de 'a'.
// RETORNO  A posicao do primeiro caractere da palavra 'a' em 'b' iniciado em 'inicia_em'. Caso nao houver ocorrencias, retornar -1.
int primeira_ocorrencia(char *a, int m, char *b, int n) {
    for (int posicao_atual = inicia_em; posicao_atual < n; posicao_atual++) {
        if (verifica_ocorrencia(a, m, b, n, posicao_atual)) {  // se for uma ocorrência, então está no último caracter
            return posicao_atual - m + 1;
        }
    }
    return -1;
}

// Funcao que retorna a posicao do primeiro caractere de 'a' em 'b' durante a ultima ocorrecnai de 'a'.
// RETORNO  A posicao do primeiro caractere da palavra 'a' em 'b' iniciado em 'inicia_em'. Caso nao houver ocorrencias, retornar -1.
int ultima_ocorrencia(char *a, int m, char *b, int n) {
    int qtd_ocorrencias = ocorrencias(a, m, b, n);
    int contador_de_ocorrencias = 0;

    for (int posicao_atual = inicia_em; posicao_atual < n; posicao_atual++) {
        if (verifica_ocorrencia(a, m, b, n, posicao_atual)) {  // se for uma ocorrência, então está no último caracter
            contador_de_ocorrencias++;
            if (contador_de_ocorrencias == qtd_ocorrencias && qtd_ocorrencias != 0)
                return posicao_atual - m + 1;
        }
    }
    return -1;
}

// Funcao que constroi o vetor 'ultimo', ja alocado com o tamanho 'tamanho_alfabeto', contendo a posicao da ultima
// ocorrencia do respectivo caractere na palavra 'a'.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// ultimo           Vetor tipo inteiro dos indice de cada caractere contendo a ultimoa ocorrencia em 'a'.
//                    Obs.1: O vetor ja esta alocado com o tamanho 'tamanho_alfabeto'.
//                    Obs.2: Eh preciso zerar todo o vetor. Caracteres inexistentes devem conter o valor 0.
//                    Obs.3: O primeiro caractere tem a posicao 1, iniciado da esquerda para a direita.
// tamanho_alfabeto Tamanho do alfabeto e, consequentemente, o tamanho do vetor 'ultimo'.
void caractere_errado(char *a, int m, int *ultimo, int tamanho_alfabeto) {
    // Zerar 'ultimo' (já alocado)
    for (int i = 0; i < tamanho_alfabeto; i++)
        ultimo[i] = 0;

    for (int i = 0; i < m; i++) {
        ultimo[a[i]] = i + 1;  // O primeiro caractere tem a posição 1
    }
}

// Funcao que constroi o vetor 'jump', ja alocado com o tamanho 'm' da palavra 'a', contendo o ultimo sufixo da palavra 'a'.
// a                Vetor com a palavra que inicia em 'inicia_em' (a[inicia_em..m+inicia_em-1])
// m                Tamanho de 'a' (palavra)
// jump           Vetor tipo inteiro que contem a ocorrencia do sufixo na propria palavra 'a'.
void sufixo_correto(char *a, int m, int *jump) {
    int h = m + inicia_em - 1, k = m + inicia_em - 2;

    while (h >= 0 && k >= 0) {
        int i = m + inicia_em - 1, j = k;

        while (i >= h && j >= 0)
            if (a[i] == a[j])  // Ajuste nos índices para inicia_em = 0
                --i, --j;
            else
                i = m + inicia_em - 1, j = --k;
        jump[h--] = k + 1;
    }

    while (h >= 0)
        jump[h--] = k + 1;
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
    if (posicao_atual == n - 1) {
        return 1;
    }
    return m - ultimo[b[posicao_atual + 1]] + 1;
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
    int i = 0;
    while (a[m + inicia_em - 1 - i] == b[posicao_atual - i] && i < m)
        i++;

    if (i == 0)
        return 1;

    return salto_caractere_errado(a, m, b, n, jump, m, posicao_atual) - 1;
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
    int i = 0;
    while (a[m + inicia_em - 1 - i] == b[posicao_atual - i] && i < m)
        i++;

    if (i == 0) {
        int s1 = salto_caractere_errado(a, m, b, n, jump, m, posicao_atual);
        int s2 = salto_sufixo_correto(a, m, b, n, jump, posicao_atual);

        return (s1 > s2) ? s1 : s2;
    }

    int s1 = salto_caractere_errado(a, m, b, n, jump, m, posicao_atual) - 1;
    int s2 = salto_sufixo_correto(a, m, b, n, jump, posicao_atual);

    return (s1 > s2) ? s1 : s2;
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

#include <iostream>

int main() {
    char a[] = "xabcabcabc";
    char b[] = "abcabcxabcabcxabcabcdefghijabcabcxabcabcabcabcxabcx";

    int m = 9;
    int n = 55;  // Tamanho de b
    int tamanho_alfabeto = 256;  // Supondo um alfabeto ASCII

    int ultimo[tamanho_alfabeto];
    for (int i = 0; i < tamanho_alfabeto; ++i) {
        ultimo[i] = -1;  // Inicializando com -1 para indicar que ainda não ocorreu
    }

    // Calcula o vetor 'ultimo' para a função salto_caractere_errado
    for (int i = m - 1; i >= 0; --i) {
        ultimo[a[i]] = i;
    }

    // Aloca e calcula o vetor 'jump' para a função salto_sufixo_correto
    int jump[m + 1];
    sufixo_correto(a, m, jump);

    // Teste de exemplo
    int posicao_teste = 50;

    int salto_caractere_errado_resultado = salto_caractere_errado(a, m, b, n, ultimo, tamanho_alfabeto, posicao_teste - 1);
    int salto_sufixo_correto_resultado = salto_sufixo_correto(a, m, b, n, jump, posicao_teste - 1);
    int melhor_salto_resultado = melhor_salto_na_posicao(a, m, b, n, ultimo, tamanho_alfabeto, jump, posicao_teste - 1);

    std::cout << "Salto usando CaractereErrado em b[" << posicao_teste << "]: " << salto_caractere_errado_resultado << std::endl;
    std::cout << "Salto usando SufixoCorreto em b[" << posicao_teste << "]: " << salto_sufixo_correto_resultado << std::endl;
    std::cout << "Melhor salto em b[" << posicao_teste << "]: " << melhor_salto_resultado << std::endl;

    return 0;
}
