#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo   = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo       = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf("Erro: lista vazia ou posicao invalida\n");
        return;
    }
    q        = p->Prox;
    *Item    = q->Item;
    p->Prox  = q->Prox;
    if (p->Prox == NULL) Lista->Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista) {
    TipoApontador Aux = Lista.Primeiro->Prox;
    while (Aux != NULL) {
        printf("%d\n", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void RetiraUltimo(TipoLista *Lista, TipoItem *Item) {
    if (Vazia(*Lista)){
        return;
    }
    TipoApontador Aux = Lista->Primeiro->Prox;
    
    if(Aux->Prox == NULL){
        *Item = Aux->Item; 
        free(Aux);
        Lista->Primeiro->Prox = NULL;
        Lista->Ultimo = Lista->Primeiro;
    }else {
        while (Aux->Prox->Prox != NULL) { //enquanto nao eh o penultimo
            Aux = Aux->Prox;
        }
        *Item = Aux->Prox->Item;
        free(Aux->Prox);
        Aux->Prox = NULL;
        Lista->Ultimo = Aux;
        
    }
}

void InsereInicio(TipoItem x, TipoLista *Lista) {
    if(Vazia(*Lista)){
        Insere(x, Lista);
    }else {
        TipoApontador Aux = (TipoApontador) malloc(sizeof(TipoCelula));
        Aux->Prox = Lista->Primeiro->Prox;
        Lista->Primeiro->Prox = Aux;
        Aux->Item = x;
    }
}

void Inverte(TipoLista *Lista) {
    if (Vazia(*Lista) || Lista->Primeiro->Prox->Prox == NULL) {
        return; //
    }
    TipoApontador ant = NULL;
    TipoApontador atual = Lista->Primeiro->Prox;
    TipoApontador proxi = NULL;
    TipoApontador novoUltimo = Lista->Primeiro->Prox;
    while (atual != NULL) {
        proxi = atual->Prox;
        atual->Prox = ant;
        ant = atual;
        atual = proxi;
    }
    Lista->Primeiro->Prox = ant;
    Lista->Ultimo = novoUltimo;
}

int Tamanho(TipoLista *Lista) {
    int tam = 0;
    TipoApontador Aux = Lista->Primeiro->Prox;
    while (Aux != NULL) {
        tam++;
        Aux = Aux->Prox;
    }
    return tam;
}
