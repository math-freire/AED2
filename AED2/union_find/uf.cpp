#include "uf.h"

grafo* criarGrafo(int V, int E) {
    grafo* g = (grafo*) malloc( sizeof(grafo) );
    g->V = V;
    g->E = E;
    g->VetorDeArestas = (aresta*) malloc(g->E * sizeof(aresta) );
    return g;
}

void destruirGrafo(grafo *g) {
    free(g->VetorDeArestas);
    free(g);
}

subset *Make_Subset(int tamanho) {
    subset *subconjuntos = (subset*) malloc(tamanho * sizeof(subset));
    for (int i=0; i<tamanho; i++) {
        Make_Set(subconjuntos, i);
    }
    return subconjuntos;
}

void Destroy_Subset(subset *s) {
    free(s);
}

void Make_Set(subset subconjuntos[], int i) {
    subconjuntos[i].pai = i;
    subconjuntos[i].rank = 0;
}

// Funcao que procura o representante (pai) do elemento i com compressao de caminho.
int Find_Set(subset subconjuntos[], int i) {
    if (i != subconjuntos[i].pai) {
        subconjuntos[i].pai = Find_Set(subconjuntos, subconjuntos[i].pai);
    }
    return subconjuntos[i].pai;
}

// Funcao que junta os conjuntos de x e y com uniao ponderada.
void Union(subset subconjuntos[], int x, int y) {
    x = Find_Set(subconjuntos, x);
    y = Find_Set(subconjuntos, y);


    if (subconjuntos[x].rank > subconjuntos[y].rank)
        subconjuntos[y].pai = x;
    else{
        subconjuntos[x].pai = y;
        if(subconjuntos[x].rank == subconjuntos[y].rank)
            subconjuntos[x].rank++;
    }
}

// Funcao utilizada para verificar se o grafo tem ou nao ciclo
bool TemCiclo( grafo* g ) {
    subset *s = Make_Subset(g->V);

  for (int i = 0; i < g->E; i++) {
    int origem = g->VetorDeArestas[i].origem;
    int destino = g->VetorDeArestas[i].destino;

    int root_origem = Find_Set(s, origem);
    int root_destino = Find_Set(s, destino);

    if (root_origem == root_destino){
        Destroy_Subset(s);
        return true;  // Os vértices já estão no mesmo componente, há um ciclo
    }

    Union(s, root_origem, root_destino);
  }
  
    Destroy_Subset(s);
    return false; // não tem ciclo
}

int QuantidadeComponentesConexas( grafo* g ) {
    subset *s = Make_Subset(g->V);
    for(int i=0; i<g->E; i++) {
        int rx = Find_Set(s, g->VetorDeArestas[i].origem);
        int ry = Find_Set(s, g->VetorDeArestas[i].destino);
        if (rx!=ry)
          Union(s, rx, ry);
    }

    int nc=0;
    for(int i = 0; i < g -> V; i++){
        if(Find_Set(s, i) == i)
        nc++;
    }
    
    Destroy_Subset(s);
    return nc;
}


int MaiorComponenteConexa( grafo* g ) {
// Realiza as uniões
    subset *s = Make_Subset(g->V);
    for(int i=0; i<g->E; i++) {
        int rx = Find_Set(s, g->VetorDeArestas[i].origem);
        int ry = Find_Set(s, g->VetorDeArestas[i].destino);
        if (rx!=ry)
          Union(s, rx, ry);
    }

// Inicializa vetor de contagem de vértices para cada componente conexa
    int qtd_vertices[g->V];
    for (int i = 0; i < g->V; i++) {
        qtd_vertices[i] = 0;
    }
    
// Conta a quantidade de vértices em cada componente conexa
    for (int i = 0; i < g->V; i++) {
        int representante = Find_Set(s, i);
        qtd_vertices[representante]++;
    }

// Encontra o tamanho da maior componente conexa
    int maior = 0;
    for (int i = 0; i < g->V; i++) {
        if (qtd_vertices[i] > maior) {
            maior = qtd_vertices[i];
        }
    }   

// Libera a memória alocada para a estrutura subset
    Destroy_Subset(s);

    return maior;
}

// Função de comparação utilizada para ordenar as arestas por peso
int compararArestas(const void* a, const void* b) {
    return ((aresta*)a)->peso - ((aresta*)b)->peso;
}

int SomaPesoArestasDaArvoreGeradoraMinima(grafo* g) {
    // Ordena as arestas por peso
    qsort(g->VetorDeArestas, g->E, sizeof(aresta), compararArestas);

    // Inicializa a estrutura Union-Find
    subset* subsets = Make_Subset(g->V);

    int i = 0; // Índice para percorrer as arestas ordenadas
    int somaPesos = 0; // Variável para armazenar a soma dos pesos

    while (i < g->E) {
        int rx = Find_Set(subsets, g->VetorDeArestas[i].origem);
        int ry = Find_Set(subsets, g->VetorDeArestas[i].destino);

        if (rx != ry) {
            // Se a inclusão da aresta não criar um ciclo, adicione o peso à soma
            somaPesos += g->VetorDeArestas[i].peso;
            Union(subsets, rx, ry);
        }
        i++;
    }

    // Libera a memória alocada
    free(subsets);

    return somaPesos;
}