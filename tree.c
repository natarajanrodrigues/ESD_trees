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


Node * maxAt(Node * a){
	if (a != NULL){
		if (a->right != NULL)
			return maxAt(a->right);
		else 
			return a;
	}
	return a;
}

Node * minAt(Node * a){
	if (a != NULL){
		if (a->left != NULL)
			return maxAt(a->left);
		else 
			return a;
	}
	return a;
}



Node *searchInOrder(Node * tree, int data){
	

	if (tree == NULL){
		return NULL;
	} else if (data < tree->data){
		return searchInOrder(tree->left, data);
	} else if (tree->data == data){
		return tree;
	} else {
		return searchInOrder(tree->right, data);
	}
}

Node * removeNode(Node * raiz, int data){
	

	if (raiz != NULL){
		//se está na direita
		if (data > (raiz)->data){
			(raiz->right) = removeNode((raiz)->right, data);
		} else if (data < (raiz)->data){
			(raiz->left) = removeNode((raiz)->left, data);
		} else {
			if (raiz->left == NULL && raiz->right == NULL){
				free(raiz);
				(raiz) = NULL;
				return NULL;
			} else {
				Node * aux;

				if (raiz->left == NULL) {  //se ele só tem filhos na direita
                    aux = raiz;
                    raiz = raiz->right;
                    free(aux);
                } else if (raiz->right == NULL) { //se ele só tem filhos na esquerda
                	aux = raiz;
                    raiz = raiz->left;
                    free(aux);
                } else {    //se tem filhos nos 2 lados
                	Node * aux = malloc(sizeof(Node));
                    aux = raiz->left;
                    while (aux->right != NULL){
                        aux = aux->right;
                    }
                    raiz->data = aux->data;
                    aux->data = data;
                    raiz->left = removeNode(raiz->left, data);
                }
			}
		}
	}

	return raiz;

}



int main(){
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

	Node * raiz = novoNode(2);

	raiz = insertTree(raiz, 1);
	raiz = insertTree(raiz, 3);
	raiz = insertTree(raiz, 8);
	raiz = insertTree(raiz, 10);
	raiz = insertTree(raiz, 9);

	imprimeArv(raiz);
	printf("\n");

	Node * achar = searchInOrder(raiz, 1);

	printf("%d\n", achar->data);
	
	raiz = removeNode(raiz, 1);
	
	imprimeArv(raiz);

	return 0;
}

