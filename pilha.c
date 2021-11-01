#include "pilha.h"
#include <stdlib.h>
#define MAX 15

struct pilha{
int vetor[MAX];
int topo;
};

Pilha cria_pilha(){
Pilha p;
p = (Pilha) malloc (sizeof(struct pilha));
if(p != NULL)
    p->topo = -1; //Começa -1 pq topo sempre "apontara" pra ultima posição e com a lista vazia, ele não pode apontar pra nada
return p;
/*if(p == NULL)
    return 0;
p->topo = -1;*/
}

int pilha_vazia(Pilha p){
if(p->topo == -1)// Como a inicialização da pilha começamos com p->topo = -1, faremos a verificação para saber se ela é vazia, ou seja, se p->top tem o valor de -1
    return 1;
else
    return 0;
}

int pilha_cheia(Pilha p){
if(p->topo == MAX-1)// Analisamos que ao inicializar a pilha com p->topo = -1, vamos verificar se a pilha está cheia de modo que o valor que colocamos como MAX seja subtraído também 1, pois, caso nao tenha essa subtração estaremos excedendo o próprio limite que impusemos.
    return 1;// Quando MAX-1 (14 posições) acessar regiao de memoria que não existe
else
    return 0;
}

// Push (Insere) | Pop (remove)

int push(Pilha p, int elem){ //Como estamos trabalhando com a inserção de um elemento, não passamos os valores por referência, portanto, não utilizamos ponteiro(*).
if(p == NULL || pilha_cheia(p) == 1) //Ponteiro nulo ou pilha cheia
    return 0;

//Insere o elemento no topo
p->topo++; //Como começamos o topo com -1, devemos incrementar antes de inserir
p->vetor[p->topo] = elem;
return 1;
}

int pop(Pilha p, int *elem){ //Como estamos trabalhando com remoção de um elemento, vamos modificar o valor atribuído a ele, ou seja, estamos passando esse valor por referência.
if(p == NULL || pilha_vazia(p) == 1) //Ponteiro nulo ou pilha vazia
    return 0;
*elem = p->vetor[p->topo]; //Retorna o elemento
p->topo--; //Decrementa o topo (remove o elemento do topo)
return 1;
}

int le_topo(Pilha p, int *elem){
if(p == NULL || pilha_vazia(p) == 1) //Ponteiro nulo ou pilha vazia
    return 0;
*elem = p->vetor[p->topo]; //Retorna o elemento
return 1;
}

//Função não básicas
int get_topo(Pilha p, int *topo){
if(p == NULL || pilha_vazia(p) == 1) //Ponteiro nulo ou pilha vazia
    return 0;
*topo = p->topo; // Retorna qual "posição" estaria o topo
return 1;
}

int esvazia_pilha(Pilha p){
    if(p == NULL || pilha_vazia(p) == 1){
        return 0;
    }
    while( p->topo != -1){
        p->topo--; //Decrementa o topo (removendo o elemento do topo)
    }

    // Chegando aqui, temos o topo = -1
    return 1;
}

int apaga_pilha(Pilha p){
    if(pilha_vazia(p) == 1){
        free(p);
        return 1;
    }
    if(p != NULL){ //Temos que esvaziar a pilha primeiro antes de apagá-la, pelo fato de que, ao esvaziarmos primeiro, a gente está liberando o espaço que foi alocado os elementos e seus respectivos endereços e conteúdos, e estamos apagando tudo, sem o desperdício de memória
        while( p->topo != -1){
            p->topo--; //Decrementa o topo (removendo o elemento do topo)
    }
     // Chegando aqui, temos o topo = -1
    }
    free(p);// O free libera o espaço que está sendo alocado
    return 1;
}
