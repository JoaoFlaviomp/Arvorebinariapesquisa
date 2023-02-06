#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct sNo{
    char info;
    struct sNo *esq;
    struct sNo *dir;
}NO;

typedef struct sABP{
    NO *ptRaiz;
}ABP;

void inicializar(NO **raiz){
    *raiz = NULL;
}

NO* alocarNo(){
    return (NO*)malloc(sizeof(NO));
}

void desalocarNo(NO*q){
    free(q);
}

void enserir(NO**raiz, char elem){
    if(*raiz==NULL){
        *raiz=malloc(sizeof(NO));
        (*raiz)->info=elem;
        (*raiz)->esq=NULL;
        (*raiz)->dir=NULL;
    }
    else
        if(elem<(*raiz)->info)
        enserir(&((*raiz)->esq), elem);
    else
        enserir(&((*raiz)->dir), elem);
    }

NO *remover(NO*raiz, char elem){
    if(raiz==NULL)
        return NULL;
    else if(raiz->info>elem)
        raiz->esq=remover(raiz->esq, elem);
    else if(raiz->info<elem)
        raiz->dir=remover(raiz->dir, elem);
    else if(raiz->esq==NULL && raiz->dir==NULL){
            desalocarNo(raiz);
            raiz=NULL;
    }

    else if(raiz->esq==NULL){
        NO *temp=raiz;
        raiz=raiz->dir;
        desalocarNo(temp);
    }
    else if(raiz->dir==NULL){
       NO *temp=raiz;
        raiz=raiz->esq;
        desalocarNo(temp);
    }
    else{
        NO *Pai=raiz;
        NO *F=raiz->esq;
        while(F->dir!=NULL){
            Pai=F;
            F=F->dir;
        }
        raiz->info=F->info;
        F->info=elem;
        raiz->esq=remover(raiz->esq, elem);
        }
            return raiz;
    }

void exibir_preordem(NO *r){
    if(r){
        printf("%c ", r->info);
        exibir_preordem(r->esq);
        exibir_preordem(r->dir);
    }
}

int quantidade_elem(NO *raiz){
    if(raiz==NULL)
        return 0;
    else
        return 1 + quantidade_elem(raiz->esq) + quantidade_elem(raiz->dir);
}

