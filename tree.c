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

/*
Node * removeNode(Node * a, int data){

	if (a != NULL){
		Node * aux = NULL;
		if (a->data == data){
			

			aux = a;
			if (a->left != NULL){
				a = a->left;
			} else if (a->right != NULL){
				a = a->right;
			} 
			free(aux);
			aux = NULL;
		} else {
			if (data < a->data){
				a->left = removeNode(a->left, data);
			} else {
				a->right = removeNode(a->right, data);
			}
		}
		
	}

	return a;
}
*/

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

/*

Node * removeNode(Node * a, int data){
	if (a != NULL){
		Node * aux = NULL;
		if (a->data == data){		
			if (a->left != NULL){
				Node * aux = maxAt(a->left);
				a->data = aux->data;
				a->left = aux->left;
				free(aux);
				aux = NULL;
			} else if (a->right != NULL) {
				Node * aux = minAt(a->right);
				a->data = aux->data;
				a->right = aux->right;
				free(aux);
				aux = NULL;
			} else {
				free(a);
				a = NULL;
			}
		} else {
			if (data < a->data){
				a->left = removeNode(a->left, data);
			} else {
				a->right = removeNode(a->right, data);
			}
		} 
	} 
	return a;
}


*/

/*

Node * removeNode(Node * a, int data){
	if (a != NULL){
		Node * aux = NULL;
		//excluir a raiz
		if (a->data == data){
			if (a->left != NULL){
				Node * aux = maxAt(a->left);
				a->data = aux->data;
				a->left = aux->left;
				free(aux);
				aux = NULL;
			} else if (a->right != NULL) {
				Node * aux = minAt(a->right);
				a->data = aux->data;
				a->right = aux->right;
				free(aux);
				aux = NULL;
			}
		} else {
			if (data <= a->data && a->left != NULL){
				if (a->left->data == data){
					//excluir aqui
					Node * aux = maxAt(a->left);

				} else {
					a->left = removeNode(a->left, data);
				}
			} else if (a->right != NULL) {
				if (a->right->data == data){
					//excluir aqui
				} else {
					a->right = removeNode(a->right, data);
				}
			}
		}
	}
	return a;
}

*/


/*

No *MaiorDireita(No **no){
    if((*no)->direita != NULL) 
       return MaiorDireita(&(*no)->direita);
    else{
       No *aux = *no;
       if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esquerda;
       else
          *no = NULL;
       return aux;
       }
}
 
No *MenorEsquerda(No **no){
    if((*no)->esquerda != NULL) 
       return MenorEsquerda(&(*no)->esquerda);
    else{
       No *aux = *no; 
       if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *no = (*no)->direita;
       else
          *no = NULL;
       return aux;
       }
}


void remover(No **pRaiz, int numero){
    if(*pRaiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(numero < (*pRaiz)->numero)
       remover(&(*pRaiz)->esquerda, numero);
    else 
       if(numero > (*pRaiz)->numero)
          remover(&(*pRaiz)->direita, numero);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          No *pAux = *pRaiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){         // se nao houver filhos...
                free(pAux);
                (*pRaiz) = NULL; 
               }
          else{     // so tem o filho da direita
             if ((*pRaiz)->esquerda == NULL){
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux); pAux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*pRaiz)->direita == NULL){
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL
                    free(pAux); pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
                   pAux = MaiorDireita(&(*pRaiz)->esquerda); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                   pAux->esquerda = (*pRaiz)->esquerda;          //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                   pAux->direita = (*pRaiz)->direita;
                   (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                   free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;   
                   }
                }
             }
          }
}




Node *searchInOrder(Node * tree, int data){
	Node * aux = NULL;

	if (tree == NULL){
		return NULL;
	} else if (tree->left != NULL){
		aux = searchInOrder(tree->left, data);
	} else if (tree->data == data){
		aux = tree;
	} else if (tree->right != NULL){
		aux = searchInOrder(tree->right, data);
	}
	return aux;
}

*/

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

