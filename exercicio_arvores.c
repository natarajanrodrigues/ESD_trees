#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
} Node;

Node * novoNode(int data){
    Node * aux = malloc(sizeof(Node));
    aux->data = data;
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}


Node * insertTree(Node * a, int data);
Node * insertTree(Node * a, int data){
    if (a == NULL){
        a = malloc(sizeof(Node));
        a->data = data;
        a->left = NULL;
        a->right = NULL;
        
    } else {
        if (data < a->data){
            a->left = insertTree(a->left, data);
        } else {
            a->right = insertTree(a->right, data);
        }
    }
    return a;
}


void imprimeArv(Node * a){
    if (a != NULL){
        imprimeArv(a->left);
        printf("%d ", a->data);
        imprimeArv(a->right);
    }
}

Node * removeNode(Node * a, int data){
    if (a != NULL){
        //se está na direita
        if (data > a->data){
            a->right = removeNode(a->right, data);
        } else if (data < a->data){ //o noh a ser excluido deve estar à esquerda
            a->left = removeNode(a->left, data);
        } else {//caso contrario o noh a é aquele que devemos excluir
            if (a->left == NULL && a->right == NULL){   //se o nó é folha
                free(a);
                a = NULL;
            } else { //caso não seja folha
                if (a->left == NULL) {  //se ele só tem filhos na direita
                    a = a->right;
                } else if (a->right == NULL) { //se ele só tem filhos na esquerda
                    a = a->left;
                } else {    //se tem filhos nos 2 lados
                    Node * aux = malloc(sizeof(Node));
                    aux = a->left;
                    while (aux->right != NULL){
                        aux = aux->right;
                    }
                    a->data = aux->data;
                    aux->data = data;
                    a->left = removeNode(a->left, data);
                }
            }
        }
        
    }
    return a;
    
}


Node * procura (Node * raiz, int num){
    if (raiz != NULL){
        if (raiz->data == num) {
            return raiz;
        } else if (num > raiz->data){
            return procura(raiz->right, num);
        } else {
            return procura(raiz->left, num);
        }
    }
    return NULL;
}



//QUESTÃO 1
int elementosMaioresQue(Node * raiz, int num){
    if (raiz != NULL){
        if (raiz->data <= num){
            return elementosMaioresQue(raiz->right, num);
        } else {
            return 1 + elementosMaioresQue(raiz->left,num) + elementosMaioresQue(raiz->right, num);
        }
    } else {
        return 0;
    }
}


//QUESTÃO 2

int max(int n, int m){
    if (n >= m) return n;
    else return m;
}

int alturaDeArvore (Node * raiz){
    if (raiz != NULL){
        if (raiz->left == NULL && raiz->right == NULL){
            return 0;
        }
        return 1 + max(alturaDeArvore(raiz->left), alturaDeArvore(raiz->right));
    } else {
        return 0;
    }
}


//QUESTAO 3

Node * maxElemento(Node * a){
    if (a != NULL){
        if (a->right != NULL)
            return maxElemento(a->right);
        else
            return a;
    }
    return a;
}


//QUESTAO 4

int estah(Node * raiz, int num){
    if (raiz != NULL){
        if (raiz->data == num){
            return 1;
        } else {
            if (num > raiz->data){
                return estah(raiz->right, num);
            } else {
                return estah(raiz->left, num);
            }
        }
    }
    return 0;
}

Node * removeOcorrencias (Node * raiz, int num){
    
    if (raiz != NULL){
        while (estah(raiz, num)){
            raiz = removeNode(raiz, num);
        }
        return raiz;
    }
    return NULL;
}



//QUESTAO 5

Node * removeMenoresQue(Node * raiz, int num){
    if (raiz != NULL){
        if (raiz->data == num) {
            free(raiz->left);
            raiz->left = NULL;
            return raiz;
        } else {
            if (raiz->data < num){
                raiz = raiz->right;
                return removeMenoresQue(raiz, num);
            }
        }
    }
    return NULL;
}




int main(){
    
    Node * raiz = novoNode(1);
    raiz = insertTree(raiz, 2);
    raiz = insertTree(raiz, 3);
    
    /*
     
     Node * raiz = novoNode(4);
     raiz = insertTree(raiz, 2);
     raiz = insertTree(raiz, 6);
     raiz = insertTree(raiz, 1);
     raiz = insertTree(raiz, 3);
     raiz = insertTree(raiz, 5);
     raiz = insertTree(raiz, 7);
     raiz = insertTree(raiz, 8);
     raiz = insertTree(raiz, 10);
     raiz = insertTree(raiz, 9);
     */
    
    
    /*
     Node * raiz = novoNode(2);
     
     raiz = insertTree(raiz, 1);
     raiz = insertTree(raiz, 3);
     */
    imprimeArv(raiz);
    printf("\n");
    
    
    //raiz = removeOcorrencias(raiz, 2);
    //imprimeArv(raiz);
    //printf("\n");
    
    
    //Node * predes = predecessor(raiz, 2);
    //    printf("Predecessor: %d\n", predecessor2(raiz, 9)->data);
    
    //printf("Sucessor: %d\n", sucessor(raiz, 7)->data);
    
    //printf("Pai: %d\n", paiDe(raiz, 10)->data);
    
    //printf("Maiores: %d\n", elementosMaioresQue(raiz, 1));
    printf("Altura: %d\n", alturaDeArvore(raiz));
    
    
    return 0;
}

