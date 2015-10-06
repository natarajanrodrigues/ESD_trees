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


Node * insertTree(Node * tree, int data);
Node * insertTree(Node * tree, int data){
    if (tree == NULL){
        tree = malloc(sizeof(Node));
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
        
    } else {
        if (data < tree->data){
            tree->left = insertTree(tree->left, data);
        } else {
            tree->right = insertTree(tree->right, data);
        }
    }
    return tree;
}


void print_tree(Node * tree){
    if (tree != NULL){
        print_tree(tree->left);
        printf("%d ", tree->data);
        print_tree(tree->right);
    }
}


Node * removeNode(Node * tree, int data){
    if (tree != NULL){
        //se está na direita
        if (data > tree->data){
            tree->right = removeNode(tree->right, data);
        } else if (data < tree->data){ //o noh a ser excluido deve estar à esquerda
            tree->left = removeNode(tree->left, data);
        } else {//caso contrario o noh a é aquele que devemos excluir
            if (tree->left == NULL && tree->right == NULL){   //se o nó é folha, apenas deleta
                free(tree);
                tree = NULL;
            } else { //caso não seja folha
                if (tree->left == NULL) {  //se ele só tem filhos na direita
                    tree = tree->right;
                } else if (tree->right == NULL) { //se ele só tem filhos na esquerda
                    tree = tree->left;
                } else {    //se tem filhos nos 2 lados
                    Node * aux = malloc(sizeof(Node));
                    aux = tree->left;
                    while (aux->right != NULL){
                        aux = aux->right;
                    }
                    tree->data = aux->data;
                    aux->data = data;
                    tree->left = removeNode(tree->left, data);
                }
            }
        }
        
    }
    return tree;    
}


int sumNodes(Node * tree){
	if (tree != NULL){
		return tree->data + sumNodes(tree->left) + sumNodes(tree->right);
	} else {
		return 0;
	}
}

int somaFolhas(Node * tree){

	if (tree != NULL){

		if (tree->left == NULL && tree->right == NULL){
			return tree->data;
		} else {
			return somaFolhas(tree->left) + somaFolhas(tree->right);
		}
	} else {
		return 0;
	}
}


int main(){
    
	Node * raiz = novoNode(4);
	raiz = insertTree(raiz, 2);
	raiz = insertTree(raiz, 6);
	raiz = insertTree(raiz, 1);
	raiz = insertTree(raiz, 3);
	raiz = insertTree(raiz, 5);
	raiz = insertTree(raiz, 7);
	/*
	raiz = insertTree(raiz, 8);
	raiz = insertTree(raiz, 10);
	raiz = insertTree(raiz, 9);
    */
     
    /*
    Node * raiz = novoNode(2);
    raiz = insertTree(raiz, 1);
    raiz = insertTree(raiz, 3);
    */

    print_tree(raiz);
    printf("\n");
    
    
    
    raiz = removeNode(raiz, 0);
    
    print_tree(raiz);
    printf("\n");

    int soma = sumNodes(raiz);

    printf("Soma dos nodos: %d\n", soma);
    
    return 0;
}

