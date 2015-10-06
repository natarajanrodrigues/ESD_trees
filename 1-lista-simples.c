//
//  main.c
//  listas-aula1
//
//  Created by Natarajan Ferreira on 13/05/15.
//  Copyright (c) 2015 Natarajan Ferreira. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int dado;
    struct noh * proximo;
    struct noh * anterior;
} Node;

Node * novo(int dado);
Node * novo(int dado){
    Node * n = (Node *) malloc (sizeof(Node));
    n->dado = dado;
    n->proximo = NULL;
    n->anterior = NULL;
    return n;
}

typedef struct lista{
    int tamanho;
    Node *first;
    Node *last;
} Lista;

Node* find (Node* head, int dado);
Node* find (Node* head, int dado){
    Node * current = head;
    
    while (current != NULL){
        if (current->dado == dado){
            return current;
        }
        current = current->proximo;
    }
    return NULL;
    
}


int removeNode (Node * node, int dado){
    if (node->dado == dado){
        Node * aux = node;
        node = node->proximo;
        node->anterior = NULL;
        free(aux);
        return 1;
    } else {
        Node * aux = node;
        while (aux != NULL && aux->dado != dado)
            aux = aux->proximo;
 
        if (aux->dado == dado){
            Node * temp = aux->proximo;
            aux->proximo = temp->proximo;
            free (temp);

            return 0;
        } else {
            return 1;
        }
    }
    
}



//addAt de LIsta duplamente encadeada
int addAt(Node * l, int data, int position);
int addAt(Node * l, int data, int position){
    if (position < 0)
        return 0;
    
    Node * aux = l;
    int cont = 0;
    while (cont < position && aux != NULL){
        if (aux->proximo != NULL)
            aux = aux->proximo;
        cont++;
    }
    
    Node * newNode = novo(data);
    
    if (aux->anterior == NULL){
        newNode->proximo = l;
        l = newNode;
        return 1;
    } else {
        Node * temp1 = aux->anterior;
        temp1->proximo = newNode;
        newNode->anterior = temp1;
        newNode->proximo = aux;
        aux->anterior = newNode;
        return 1;
        
    }
    
}

void imprime(Node *first);
void imprime(Node *first){
    Node *aux = first;
    while (aux) {
        printf("%d -> ", aux->dado);
        aux = aux->proximo;
    }
    printf(" //");
    
}


Node * adiciona (Node *l, int novoDado);
Node * adiciona (Node *l, int novoDado){
    Node *novoNode = novo(novoDado);
    novoNode->proximo = l;
    l->anterior = novoNode;
    return novoNode;
}

int main(int argc, const char * argv[]) {
    
    //Lista * minhaLista = (Lista *) malloc(sizeof(Lista));
    Node *p = novo(1);
    //addAt(p, 2, 0);
    //addAt(p, 3, 3);
    p = adiciona(p, 2);
    p = adiciona(p, 3);
    
    imprime(p);
  
    return 0;
}
