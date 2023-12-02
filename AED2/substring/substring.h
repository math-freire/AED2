#ifndef SUBSTRING_H
// NAO ALTERAR ESTE ARQUIVO!!!
// NAO ALTERAR ESTE ARQUIVO!!!
// NAO ALTERAR ESTE ARQUIVO!!!

#define SUBSTRING_H

#include "main.h"
#include <stdlib.h>
#include <string.h>

extern int inicia_em;

bool verifica_ocorrencia(char *a, int m, char *b, int n, int pos_ult_carac);

int ocorrencias(char *a, int m, char *b, int n);

int primeira_ocorrencia(char *a, int m, char *b, int n);

int ultima_ocorrencia(char *a, int m, char *b, int n);

void caractere_errado(char *a, int m, int *ultimo, int tamanho_alfabeto);

void sufixo_correto(char *a, int m, int *jump);

int salto_caractere_errado(char *a, int m, char *b, int n, int *ultimo, int tamanho_alfabeto, int posicao_atual);

int salto_sufixo_correto(char *a, int m, char *b, int n, int* jump, int posicao_atual);

int melhor_salto_na_posicao(char *a, int m, char *b, int n, int *ultimo, int tamanho_alfabeto, int* jump, int posicao_atual);

int boyer_moore(char *a, int m, char *b, int n, int *ultimo, int tamanho_alfabeto, int* jump);

#endif // #ifndef SUBSTRING_H
