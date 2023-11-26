#include "hash.h"

// Funcao hash. Retorna o indice de uma chave na tabela. Nao alterar!
int hash(char chave[STR_SIZE], int tamanho, int tentativa) {
    int h = chave[0];
    for (int i = 1; chave[i] != '\0'; i++)
        h = (h * 251 * chave[i]) % tamanho;
    return (h + tentativa) % tamanho;
}

tipoHash criar(modoHash m, int t) {
    tipoHash h;
    h.tamanho = t;
    switch (h.modo = m) {
    case semColisao:
        h.tabela.aberto = (hashAberto*) malloc(sizeof(hashAberto) * t);
        for (int i = 0; i < t; i++) 
            h.tabela.aberto[i].chave[0] = h.tabela.aberto[i].valor[0] = '\0';
        break;

    case encadeamento:
        h.tabela.encadeada = (hashEncadeada*) malloc(sizeof(hashEncadeada) * t);
        for (int i = 0; i < t; i++)
            h.tabela.encadeada[i].primeiro = NULL;
        break;

    case aberto:
        h.tabela.aberto = (hashAberto*) malloc(sizeof(hashAberto) * t);
        for (int i = 0; i < t; i++) {
            h.tabela.aberto[i].excluido = false;
            h.tabela.aberto[i].chave[0] = h.tabela.aberto[i].valor[0] = '\0';
        }
        break;
    }
    return h;
}

void delete_linked_list(listaEncadeada *head){
    if(head){
        listaEncadeada *next_node = head->proximo;
        delete head;
        delete_linked_list(next_node);
    }
}

void destruir(tipoHash h) {
    switch (h.modo) {
    case semColisao:
        free(h.tabela.aberto);
        h.tabela.aberto = NULL;
        break;

    case encadeamento:
        delete_linked_list(h.tabela.encadeada->primeiro);
        free(h.tabela.encadeada);
        break;

    case aberto:
        free(h.tabela.aberto);
        h.tabela.aberto = NULL;
        break;
    }
}

void inserir(tipoHash h, char c[STR_SIZE], char v[STR_SIZE]) {
    int idx = hash(c, h.tamanho);

    // Criar variavel fora da função de encadeamento para evitar erro de crosses initialization 
    listaEncadeada *novaLista = nullptr;
    
    switch (h.modo) {
    case semColisao:
        strcpy(h.tabela.aberto[idx].chave, c);
        strcpy(h.tabela.aberto[idx].valor, v);
        break;

    case encadeamento:        
        // Calcular a função HASH
        idx = hash(c, h.tamanho);

        // Alocar a lista encadeada
        novaLista = (listaEncadeada*) malloc(sizeof(listaEncadeada));
        strcpy(novaLista->chave, c);
        strcpy(novaLista->valor, v);
        novaLista->proximo = NULL;

        // Verificar se a lista no indice está vazia para inserir, senão percorrer até o final
        if(h.tabela.encadeada[idx].primeiro == NULL)
            h.tabela.encadeada[idx].primeiro = novaLista;
        else{

            // Não está vazia, percorrer até o final
            listaEncadeada *atual = h.tabela.encadeada[idx].primeiro;
            while(atual -> proximo != NULL){
                atual = atual -> proximo;
            }
            
            // Adicionar ao final da lista (após atual)
            atual->proximo = novaLista; 
        }

        break;

    case aberto:

        // Utilizando encadeamento aberto linear com auxilio das tentativas
        for (int tentativa = 0; tentativa < h.tamanho; tentativa++) {

            // Calcula o idx para a tentativa atual na tabela. Abstração: Cada calculo é um slot/caixa da tabela
            idx = hash(c, h.tamanho, tentativa);
            
            // Verifica se a celula está vazia e insere
            if(h.tabela.aberto[idx].chave[0] == '\0'){
                strcpy(h.tabela.aberto[idx].chave, c);
                strcpy(h.tabela.aberto[idx].valor, v);
                h.tabela.aberto[idx].excluido = false;
                break;
            }
        }
        break;
    }
}

char *buscar(tipoHash h, char c[STR_SIZE]) {
    int idx = hash(c, h.tamanho);
    listaEncadeada *atual;

    switch (h.modo) {
    case semColisao:
    // Função admite que o indices são unicos na tabela, por isso não é necessário nennum tipo de looping, somente o calculo hash
        return strcmp(h.tabela.aberto[idx].chave, c) == 0 ? h.tabela.aberto[idx].valor : NULL;

    case encadeamento:
        // Retornar nulo se a chave nao for encontrada!
        idx = hash(c, h.tamanho);
        atual = h.tabela.encadeada[idx].primeiro;
        
        while(atual != NULL){
            if(strcmp(atual->chave, c) == 0)
                return atual->valor;
            else
                atual = atual->proximo;
        }
        return NULL;

    case aberto:
        // IMPLEMENTAR!!!
        // Retornar nulo se a chave nao for encontrada!
        idx = hash(c, h.tamanho);
        return strcmp(h.tabela.aberto[idx].chave, c) == 0 ? h.tabela.aberto[idx].valor : NULL;
    }
    return NULL;
}

void apagar(tipoHash h, char c[STR_SIZE]) {
    int idx = hash(c, h.tamanho);
    listaEncadeada *atual = NULL;
    listaEncadeada *anterior = NULL;

    switch (h.modo) {
    case semColisao:
        if (strcmp(h.tabela.aberto[idx].chave, c) == 0)
            h.tabela.aberto[idx].chave[0] = h.tabela.aberto[idx].valor[0] = '\0';
        break;

    case encadeamento:
        idx = hash(c, h.tamanho);
        atual = h.tabela.encadeada[idx].primeiro;

        while (atual != NULL) {
            if (strcmp(atual->chave, c) == 0) {
                // Ajustar os ponteiros para excluir o nó atual
                if (anterior == NULL)
                    h.tabela.encadeada[idx].primeiro = atual->proximo;
                else 
                    anterior->proximo = atual->proximo;
                free(atual);

                break;  // O nó foi excluído, sair do loop
            } else {
                anterior = atual;
                atual = atual->proximo;
            }
        }
        break;

    case aberto:
        if (strcmp(h.tabela.aberto[idx].chave, c) == 0){
            h.tabela.aberto[idx].chave[0] = h.tabela.aberto[idx].valor[0] = '\0';
            h.tabela.aberto[idx].excluido = true;
        }
        break;
    }
}

int quantidade(tipoHash h) {
    int qtd = 0;
    listaEncadeada *atual = NULL;

    switch (h.modo) {
    case semColisao:
    case aberto: // Igual ao semColisao, portanto, jah implementado!!!
        for (int i = 0; i < h.tamanho; i++)
            if (h.tabela.aberto[i].chave[0] != '\0')
                qtd++;
        break;

    case encadeamento:
        

        for (int i = 0; i < h.tamanho; i++){
            atual = h.tabela.encadeada[i].primeiro;
            
            while(atual != NULL){
                qtd++;
                atual = atual->proximo;
            }
        }
        break;
    }
    return qtd;
}