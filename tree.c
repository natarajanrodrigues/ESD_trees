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
	Node * aux; 

	if (raiz != NULL){
		//se está na direita
		if (data > (raiz)->data){
			(raiz->right) = removeNode((raiz)->right, data);
		} else if (data < (raiz)->data){
			(raiz->left) = removeNode((raiz)->left, data);
		}

		aux = raiz;

		if ((raiz)->left == NULL && (raiz)->right == NULL){
			free(aux);
			(raiz) = NULL;
			return NULL;
		} else {
			if ((raiz)->left == NULL) {
				(raiz) = (raiz)->right;
				aux->right = NULL;
				free(aux);
				aux = NULL;
				return raiz;
			} else if ((raiz->right) == NULL) {
				(raiz) = (raiz)->left;
				aux->left = NULL;
				free(aux);
				aux = NULL;
				return raiz;
			} else {
				Node * aux2 = raiz->left;
				while (aux2->right != NULL){
					aux2 = aux2->right;
				}

				raiz->data = aux2->data;
				aux2->data = data;

				return removeNode(raiz->left, data);

			}
		}

	}

	return aux;

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

	imprimeArv(raiz);
	printf("\n");

	Node * achar = searchInOrder(raiz, 1);

	printf("%d\n", achar->data);
	
	raiz = removeNode(raiz, 2);
	
	imprimeArv(raiz);

	return 0;
}

