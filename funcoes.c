#include <stdio.h>
#include <stdlib.h>
void swap(double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

int partitionLomuto(double arr[], int low, int high) {
  int middle = (low + high) / 2;
  double pivot = arr[middle];
  int i = low - 1;
  int j = high + 1;
  while (1) {
    do {
      i++;
    } while (arr[i] < pivot);
    do {
      j--;
    } while (arr[j] > pivot);
    if (i >= j) {
      return j;
    }
    swap(&arr[i], &arr[j]);
  }
}

void quickSortLomuto(double arr[], double low, double high) {
  if (low < high) {
    double pi = partitionLomuto(arr, low, high);
    quickSortLomuto(arr, low, pi);
    quickSortLomuto(arr, pi + 1, high);
  }
}
// cria ordenado
void gerarCrescente(int tam) {
  FILE *fp;
  char nomeArquibo[255];
  sprintf(nomeArquibo, "arquivos/crescente%d.txt", tam);
  fp = fopen(nomeArquibo, "w");
  if (fp == NULL) {
    printf("Erro na abertura do arquivo.");
    exit(0);
  }

  for (int cont = 1; cont <= tam; cont++) {
    fprintf(fp, "%d\n", cont);
  }
  fclose(fp);
}
// cria decresente
void gerarDecrescente(int tam) {
  FILE *fp;
  char nomeArquivo[255];
  sprintf(nomeArquivo, "arquivos/decrescente%d.txt", tam);
  fp = fopen(nomeArquivo, "w");
  if (fp == NULL) {
    printf("Erro na abertura do arquivo.");
    exit(0);
  }
  for (int cont = tam; cont >= 1; cont--) {
    fprintf(fp, "%d\n", cont);
  }
  fclose(fp);
}

int lerArquivo(char *nome_arquivo, double *numeros, int TAMANHO_MAXIMO) {
  int i = 0;
  char linha[100];
  FILE *arquivo;

  arquivo = fopen(nome_arquivo, "r");

  if (arquivo == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    return 1;
  }

  while (i < TAMANHO_MAXIMO && fgets(linha, 100, arquivo) != NULL) {
    numeros[i] =
        atof(linha); // converte a string lida para um número em ponto flutuante
    i++;
  }

  fclose(arquivo);

  return 0;
}

void insert(int tamanho, double *vetor) {
  int i, j;
  double temp;
  for (i = 1; i < tamanho; i++) {
    temp = vetor[i];
    j = i - 1;
    while (j >= 0 && vetor[j] > temp) {
      vetor[j + 1] = vetor[j];
      j--;
    }
    vetor[j + 1] = temp;
  }
}

void bubbleSort(int tamanho, double *vetor) {
  int i, j;
  double temp;
  for (i = 0; i < tamanho - 1; i++) {
    for (j = 0; j < tamanho - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}

void printaMenu() {
  printf("Escolha uma opcao:\n");
  printf("1 - Gerar arquivo em ordem crescente\n");
  printf("2 - Gerar arquivo em ordem decrescente\n");
  printf("3 - Gerar arquivo em ordem aleatoria\n");
}
void printaMenu2() {
  printf("Qual algoritimo voce dezeja usar?\n");
  printf("1: Bubble Sort\n");
  printf("2: Insert Sort\n");
  printf("3: Selection Sort\n");
  printf("4: Shell Sort\n");
  printf("6: Quick Sort Hoare\n");
  printf("5: Quick Sort Lomuto\n");
  printf("7: Merge Sort\n");
  printf("8: Radix Sort\n");
  printf("9: Hepfy Sort\n");
}

void gerarAleatorio(int tam, int max) {
  FILE *arquivo;
  char nomeArquivo[80];
  int numero;

  // Cria o nome do arquivo
  sprintf(nomeArquivo, "arquivos/randomico%d.txt", tam);

  // Abre o arquivo para escrita
  arquivo = fopen(nomeArquivo, "w");

  // Semente para gerar números aleatórios
  srand(time(NULL));

  // Escreve os números aleatórios no arquivo
  for (int i = 0; i < tam; i++) {
    numero = rand() % max + 1;
    fprintf(arquivo, "%d\n", numero);
  }

  // Fecha o arquivo
  fclose(arquivo);
}
void selectionSort(int tamanho, double *vetor) {
  int i, j, pos_menor;
  double temp;

  for (i = 0; i < tamanho - 1; i++) {
    pos_menor = i;
    for (j = i + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[pos_menor]) {
        pos_menor = j;
      }
    }
    if (pos_menor != i) {
      temp = vetor[i];
      vetor[i] = vetor[pos_menor];
      vetor[pos_menor] = temp;
    }
  }
}
void shellSort(int tamanho, double *vetor) {
  int gap, j, flag;
  for (gap = 1; gap < tamanho; gap = 3 * gap + 1)
    ;

  while (gap > 0) {
    gap = (gap - 1) / 3;
    for (int i = gap; i < tamanho; i++) {
      double temp = vetor[i];
      j = i;
      flag = 0; // redefinir a flag para zero antes de iniciar o loop interno
      while (vetor[j - gap] > temp && flag == 0) {
        vetor[j] = vetor[j - gap];
        j -= gap;
        if (j < gap) {
          flag = 1;
        }
      }
      vetor[j] = temp;
    }
  }
}
int partitionHoare(double *vetor, int tam) {
  int x = vetor[tam / 2];
  int esq, dir;
  for (esq = 0, dir = tam - 1;; esq++, dir--) {
    while (vetor[esq] < x) {
      esq++;
    }
    while (vetor[dir] > x) {
      dir--;
    }
    if (esq >= dir) {
      return esq;
    }
    int aux2 = vetor[esq];
    vetor[esq] = vetor[dir];
    vetor[dir] = aux2;
  }
}

void hoare(double *vetor, int tam) {
  if (tam < 2) {
    return;
  }
  int esq = partitionHoare(vetor, tam);
  if (tam > esq) {
    hoare(vetor, esq);
    hoare(vetor + esq, tam - esq);
  }
}

void quickSortHoare(double *vetor, int tam) { hoare(vetor, tam); }

void merge(double *v, double *c, int i, int m, int f) {
  int z, iv = i, ic = m + 1;
  for (z = i; z <= f; z++) {
    c[z] = v[z];
  }
  z = i;
  while (iv <= m && ic <= f) {
    if (c[iv] <= c[ic]) {
      v[z++] = c[iv++];
    } else {
      v[z++] = c[ic++];
    }
  }
  while (iv <= m) {
    v[z++] = c[iv++];
  }
  while (ic <= f) {
    v[z++] = c[ic++];
  }
}

void sort(double *v, double *c, int i, int f) {
  if (i >= f) {
    return;
  }
  int m = (i + f) / 2;
  sort(v, c, i, m);
  sort(v, c, m + 1, f);
  if (v[m] <= v[m + 1]) {
    return;
  }
  merge(v, c, i, m, f);
}

void mergesort(double *vetor, int esq, int dir) {
  double *c = malloc(sizeof(double) * (dir - esq + 1));
  sort(vetor, c, esq, dir);
  free(c);
}

int encontrarMaior(double *vetor, int TAM) {
  double maior = vetor[0];
  for (int i = 1; i < TAM; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
  }
  return (int)maior;
}

void countingSort(double *vetor, int TAM, int exp) {
  const int BASE = 10;
  double output[TAM];
  int count[BASE];

  for (int i = 0; i < BASE; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < TAM; i++) {
    count[(int)(vetor[i] / exp) % BASE]++;
  }

  for (int i = 1; i < BASE; i++) {
    count[i] += count[i - 1];
  }

  for (int i = TAM - 1; i >= 0; i--) {
    output[count[(int)(vetor[i] / exp) % BASE] - 1] = vetor[i];
    count[(int)(vetor[i] / exp) % BASE]--;
  }

  for (int i = 0; i < TAM; i++) {
    vetor[i] = output[i];
  }
}

void radixSort(double *numeros, int TAM) {
  int maior = encontrarMaior(numeros, TAM);

  for (int exp = 1; maior / exp > 0; exp *= 10) {
    countingSort(numeros, TAM, exp);
  }
}

void heapify_down(double *vetor, int i, int tamanho) {
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;

  if (esquerda < tamanho && vetor[esquerda] > vetor[maior]) {
    maior = esquerda;
  }

  if (direita < tamanho && vetor[direita] > vetor[maior]) {
    maior = direita;
  }

  if (maior != i) {
    swap(&vetor[i], &vetor[maior]);
    heapify_down(vetor, maior, tamanho);
  }
}

void heap_sort(double *vetor, int tamanho) {
  for (int i = tamanho / 2 - 1; i >= 0; i--) {
    heapify_down(vetor, i, tamanho);
  }

  for (int i = tamanho - 1; i >= 0; i--) {
    double temp = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = temp;
    heapify_down(vetor, 0, i);
  }
}

int buscaBinaria(double *vetor, int ini, int fim, double key, int *operacoes) {
  *operacoes += 1;
  int meio = (ini + fim) / 2;
  if ((ini == fim) && !(key == vetor[meio])) {
    return -1;
  } else {
    if (vetor[meio] == key) {
      return meio;
    } else {
      if (vetor[meio] < key) {
        return buscaBinaria(vetor, meio + 1, fim, key, operacoes);
      } else {
        return buscaBinaria(vetor, ini, meio - 1, key, operacoes);
      }
    }
  }
}
int buscaSequencial(double vetor[], int tamanho, int valor, int *operacoes) {
    int i;
    for (i = 0; i < tamanho; i++) {
        (*operacoes)++; 
        if (vetor[i] == valor) {
            return i; 
        }
    }
    return -1; 
}
