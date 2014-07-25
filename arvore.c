#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore // Estrutura de dados em que se baseia a arvore
{
  int elemento;  // Elemento a ser inserido
  struct arvore *acima; // Ponteiro que irá apontar para o elemento acima, sendo que na raiz, apontara para nulo
  struct arvore *esquerda; // Ponteiro que irá apontar para o elemento a ser inserido na "esquerda"
  struct arvore *direita; // Ponteiro que irá apontar para o elemento a ser inserido na "direita"
};

struct arvore *arv;

void ini_arvore() // Função responsável por inicializar a arvore
{
  struct arvore *aux; //Ponteiro local do tipo arvore
  aux = (struct arvore*) malloc(sizeof(struct arvore)); //Aloca um espa?o na memoria para a variavel aux
  aux->esquerda = NULL; //Inicia o primeiro elemento á esquerda da arvore como valor nulo
  aux->elemento = 0;
  aux->direita = NULL; //Inicia o primeiro elemento á direita da fila como valor nulo
  aux->acima = NULL; // Aponta o ponteiro acima para nulo, virando defitivamente a raiz da arvore
  arv = aux; // aux ? igual a primeiro elemnto da pilha
}

int main(void) //FUN??O PRINCIPAL
{
  ini_arvore();
  menu();
  system("pause");
  return 0;
}

int menu(void);
void insere();
void most_todas(struct arvore *posicao);



int menu(void)
{
  int op;

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
          insere();
          break;
        }
      case 2:
        {
            most_todas(arv);
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

void insere()
{
  struct arvore *novo = (struct arvore*) malloc(sizeof(struct arvore));
  int n;

  system("cls");
  printf("Digite o novo elemento");
  scanf("%d", &novo->elemento);

  novo->direita = NULL;
  novo->esquerda = NULL;
  novo->acima = arv;
  printf("\t1-Inserir pela esquerda\n\t2-Inserir pela direita\n\n");
  scanf("%d", &n);
  if (n == 1)
  {
      arv->esquerda = novo;
  }
  if (n == 2)
  {
      arv->direita = novo;
  }

  system("cls");
  printf("\nElemento Inserido!\n");

  system("pause");
}

void most_todas(struct arvore *posicao) 
{
  system("cls");
  while(posicao->acima!= NULL){
  struct arvore *tmp = posicao->acima;
  printf("Elemento: %d\n",posicao->elemento);
  posicao = tmp;
  }
}
