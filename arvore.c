#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore // Estrutura de dados em que se baseia a arvore
{
  int elemento;  // Elemento a ser inserido
  struct arvore *esquerda; // Ponteiro que irá apontar para o elemento a ser inserido na "esquerda"
  struct arvore *direita; // Ponteiro que irá apontar para o elemento a ser inserido na "direita"
}arvore;

struct arvore *arv;

void criarArvore(arvore **pRaiz){
    *pRaiz = NULL;
}

int main(void) //FUN??O PRINCIPAL
{
  arvore **pRaiz;
  criarArvore(pRaiz);
  menu_modulo1();
  system("pause");
  return 0;
}
//INDICE DE FUNÇÕES
void criarArvore();
int menu_modulo1(void);
void insere(arv, num);


int menu_modulo1(void)
{
  int op;
  int num;

  do
  {
    system("cls");
    puts("\tArvore Teste");
    puts("");
    puts("\t1 - Adicionar elemento");
    puts("\t2 - Mostrar todos os elementos");
    puts("\t3 - Sair");
    printf("\nDigite a op%c%co: ",135,198);
    scanf("%i",&op);
    switch(op)
    {
      case 1:
        {
          printf("Informe o elemento a ser inserido: ");
          scanf("%d", &num);
          insere(arv, num);
          system("pause");
          break;
        }
      case 2:
        {
            system("pause");
          break;
        }
      case 3:
        {
          return (0);
          break;
        }
      default:
        {
          printf("\tOp%c%co inv%clida\n",135, 198, 160);
          system("pause");
        }
    }
  }while(1);
}

void insere(arvore **pRaiz, int numero){
    if(*pRaiz == NULL){
        *pRaiz = (arvore *) malloc(sizeof(arvore));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->elemento = numero;
    }else{
        if(numero < (*pRaiz)->elemento)
            insere(&(*pRaiz)->esquerda, numero);
        if(numero > (*pRaiz)->elemento)
            insere(&(*pRaiz)->direita, numero);
    }
    printf("Elemento inserido!");
}
