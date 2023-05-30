#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 3 // n�mero m�ximo de n�meros decimais que podem ser lidos do arquivo
#define TAMANHO 32 // n�mero m�ximo de bits para representar um n�mero em bin�rio

typedef struct {
    int topo;
    int vetor[TAMANHO];
} pilhaEstatica;

void iniciaPilha(pilhaEstatica *p){
	p->topo = 0;
}

void empilha(pilhaEstatica *p, int x) {
    int aux = 0;

    // converte o n�mero decimal em bin�rio e armazena na pilha
    while (x > 0) {
        p->vetor[aux] = x % 2;
        x /= 2;
        aux++;
    }

    p->topo = aux - 1;
}

void imprimi(pilhaEstatica *p, FILE *saida) {
    // escreve o n�mero bin�rio na ordem correta no arquivo de sa�da
    int i = 0;
    for (i = p->topo; i >= 0; i--) {
        fprintf(saida, "%d", p->vetor[i]);
    }

    fprintf(saida, "\n");
}

int main(int argc, const char * argv[]) {
  
  // usando o argc 
  printf("Numero de parametros fornecidos: %d\n", argc);
  
  if(argc!= 3) {
    printf("Quantidade de parametros invalida\n");
    return 0;
  }  

  int i = 0;
  for(i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }

  FILE* entrada = fopen(argv[1], "r");
  FILE* saida   = fopen(argv[2], "w");

  // checar erros de abertura de arquivo
  if(entrada == NULL || saida == NULL) {
     printf("Erro: algum dos arquivos n�o pode ser criado corretamente\n");
     return 0;
  }
  
  pilhaEstatica pilha;
  iniciaPilha(&pilha);
  
  
    int num;
    while (fscanf(entrada, "%d", &num) == 1) {
        empilha(&pilha, num);
    }

  imprimi(&pilha, saida);

  fclose(entrada);
  fclose(saida);
  // chamar o destrutor da pilha dinamica
  return 0;
}
