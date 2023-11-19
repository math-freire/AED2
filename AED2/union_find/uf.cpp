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

    if(i != subconjuntos[i].pai)
        subconjuntos[i].pai = Find_Set(subconjuntos, subconjuntos[i].pai);
    return subconjuntos[i].pai;
}

// Funcao que junta os conjuntos de x e y com uniao ponderada.
void Union(subset subconjuntos[], int x, int y) {
    x = Find_Set(subconjuntos, x);
    y = Find_Set(subconjuntos, y);

    if (subconjuntos[x].rank < subconjuntos[y].rank)
        subconjuntos[y].pai = subconjuntos[x].pai;
    else
        subconjuntos[x].pai = subconjuntos[y].pai;

    if (subconjuntos[x].rank == subconjuntos[y].rank)
        subconjuntos[y].rank++;
}

// Funcao utilizada para verificar se o grafo tem ou nao ciclo
bool TemCiclo( grafo* g ) {
    subset *s = Make_Subset(g->V);

  for (int i = 0; i < g->E; i++) {
    int origem = g->VetorDeArestas[i].origem;
    int destino = g->VetorDeArestas[i].destino;

    int root_origem = Find_Set(s, origem);
    int root_destino = Find_Set(s, destino);

    if (root_origem == root_destino)
        return true;  // Os vértices já estão no mesmo componente, há um ciclo
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
    // DICA: Quando o elemento i for o mesmo que o pai[i] (se representante), significa que representa um componente conexo.
    //       Basta contar a quantidade de vertices nesta situacao...
    for(int i = 0; i < g -> V; i++){
      if(Find_Set(s, i) == i)
        nc++;
    }
    
    Destroy_Subset(s);
    return nc;
}


int MaiorComponenteConexa( grafo* g ) {
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // DICA: Inicio similar a funcao anterior, mas eh preciso contar quantos vertices tem cada
    //       componente conexo para descobrir qual eh de maior quantidade.
    //       Tente criar um vetor auxiliar (tamanho g->V), percorrer todos os vertices e
    //       incrementar o no representante (pai) para cada vertice. Assim, basta buscar a maior contagem.
    return 0;
}

int SomaPesoArestasDaArvoreGeradoraMinima( grafo* g ) {
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // DICA: Use o algoritmo de Kruskal (disponivel no slide):
    //       Ordene as arestas por peso e crie um contador que soma todos os pesos
    //       utilizados na formacao da Arvore Geradora Minima.
    return 0;
}
