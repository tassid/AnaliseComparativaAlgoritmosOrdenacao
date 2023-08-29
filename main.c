#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  clock_t inicio, fim;
  double tempo;
  int tam = 6;
  int opcaoAlgoritmo, op, tipoArquivo;
  char nomeArquivo[80], nomeAlgoritimo[80];

  int quantidade_numeros = 0;

  double *numeros = malloc(tam * sizeof(double));

  if (numeros != NULL) {
    numeros[0] = 14;
    numeros[1] = 11;
    numeros[2] = 85;
    numeros[3] = 54;
    numeros[4] = 50;
    numeros[5] = 10;
  }

  printaMenu2();
  scanf("%d", &opcaoAlgoritmo);

  switch (opcaoAlgoritmo) {
  case 1:
    inicio = clock();
    bubbleSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "Bubllesort");
    break;
  case 2:
    inicio = clock();
    insert(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "Insert");
    break;
  case 3:
    inicio = clock();
    selectionSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "SelectionSort");
    break;
  case 4:
    inicio = clock();
    shellSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "ShellSort");
    break;
  case 5:
    inicio = clock();
    quickSortHoare(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "Quick Sort Hoare");
    break;
  case 6:
    inicio = clock();
    quickSortLomuto(numeros, 0, tam - 1);
    fim = clock();
    sprintf(nomeAlgoritimo, "Quick Sort Lomuto");
    break;
  case 7:
    inicio = clock();
    mergesort(numeros, 0, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "Merge Sort");
    break;
  case 8:
    inicio = clock();
    radixSort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "Radix Sort");
    break;
  case 9:
    inicio = clock();
    heap_sort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "heap_sort");
    break;

  default:
    printf("Opcao invalida.\n");
    break;
  }
  system("clear");
  printf("\n\nNumeros ordenados \n");
  for (int i = 0; i < tam; i++) {
    printf("%.0f \n", numeros[i]);
  }
  tempo = (double)(fim - inicio) / CLOCKS_PER_SEC; // Calcula o tempo em
  printf("Tempo de execucao: %f segundos\n", tempo);

  FILE *arquivo_resultados = fopen("resultados.txt", "a");
  if (arquivo_resultados == NULL) {
    printf("Erro ao abrir o arquivo resultados.txt\n");
    // return 1;
  }
  fprintf(arquivo_resultados,
          "Tempo de execucao do arquivo %s usando o algoritimo %s: %f segundos "
          "topo arquiv:%d\n",
          nomeArquivo, nomeAlgoritimo, tempo, tipoArquivo);
  fclose(arquivo_resultados);
  int valor;
  printf("qual valor deseja procurar?");
  scanf("%d", &valor);
  int operacoes = 0;
  inicio = clock();
  buscaSequencial(numeros, tam - 1, valor, &operacoes);
  printf("\n\nforam usadas %d operaçoes para achar pelo sequencial", operacoes);
  tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC; // Calcula o tempo em
  printf("\nTempo de pesquisa: %f segundos\n\n\n\n\n", tempo);
  operacoes = 0;
  inicio = clock();
  buscaBinaria(numeros, 0, tam - 1, valor, &operacoes);

  printf("\n\nforam usadas %d operaçoes para achar", operacoes);
  tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC; // Calcula o tempo em
  printf("\nTempo de pesquisa: %f segundos\n", tempo);
}