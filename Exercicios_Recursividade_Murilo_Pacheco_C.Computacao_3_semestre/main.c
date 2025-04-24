#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <math.h>

int fatorial(int n)
{
    if(n <= 1) return 1;

    return n * fatorial(n - 1);
}

int somaEntreNumerosNaturais(int num)
{
    if (num < 1)return 0;
    return num + somaEntreNumerosNaturais(num - 1);
}

int fibonacci(int n) {
  int x;

  if (n == 1) {
    return(1);
  }

  if (n == 2) {
    return(1);
  }

  x = fibonacci(n-1) + fibonacci(n-2);
  return(x);
}

int potenciacao(int x, int y)
{
    if (y <= 0)return 1;
    return x * potenciacao(x, y - 1);
}

void contagemRegressiva(int y) {
    printf("%d\n", y);
    if (y > 0) {
        contagemRegressiva(y - 1);
    }
}

int soma_digitos(int n) {
    if (n == 0) {
        return 0;
    }

    return (n % 10) + soma_digitos(n / 10);
}

void inverter_string(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    inverter_string(str, inicio + 1, fim - 1);
}

int ehPalindromo(char str[], int inicio, int fim) {
    if (inicio >= fim) return 1;
    if (str[inicio] != str[fim]) return 0;
    return ehPalindromo(str, inicio + 1, fim - 1);
}

int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int multiplicar(int a, int b) {
    if (b == 0) return 0;
    return a + multiplicar(a, b - 1);
}

int contarCaracteres(char str[], char c, int index) {
    if (str[index] == '\0') return 0;
    return (str[index] == c) + contarCaracteres(str, c, index + 1);
}

int somaArray(int arr[], int tamanho) {
    if (tamanho == 0) return 0;
    return arr[tamanho - 1] + somaArray(arr, tamanho - 1);
}

int ehPrimo(int n, int divisor) {
    if (divisor < 2) return 1;
    if (n % divisor == 0) return 0;
    return ehPrimo(n, divisor - 1);
}

int verificaPrimo(int n) {
    if (n <= 1) return 0;
    return ehPrimo(n, (int)sqrt(n));
}

void decimalParaBinario(int n) {
    if (n == 0) return;
    decimalParaBinario(n / 2);
    printf("%d", n % 2);
}

void imprimirPares(int n) {
    if (n < 0) return;
    imprimirPares(n - 2);
    printf("%d ", n);
}

void imprimirImpares(int n) {
    if (n < 1) return;
    imprimirImpares(n - 2);
    printf("%d ", n);
}

int buscaArray(int arr[], int tamanho, int elemento) {
    if (tamanho == 0) return 0;
    if (arr[tamanho - 1] == elemento) return 1;
    return buscaArray(arr, tamanho - 1, elemento);
}

int comprimentoString(char str[]) {
    if (str[0] == '\0') return 0;
    return 1 + comprimentoString(str + 1);
}

void torreHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco %d de %c para %c\n", n, origem, destino);
        return;
    }
    torreHanoi(n - 1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    torreHanoi(n - 1, auxiliar, destino, origem);
}

void permutacoes(char str[], int inicio, int fim) {
    if (inicio == fim) {
        printf("%s\n", str);
        return;
    }
    for (int i = inicio; i <= fim; i++) {
        char temp = str[inicio];
        str[inicio] = str[i];
        str[i] = temp;
        permutacoes(str, inicio + 1, fim);
        temp = str[inicio];
        str[inicio] = str[i];
        str[i] = temp;
    }
}

void imprimirCombinacao(int arr[], int dados[], int inicio, int fim, int index, int k) {
    if (index == k) {
        printf("{");
        for (int i = 0; i < k; i++) {
            printf("%d", dados[i]);
            if (i < k - 1) printf(", ");
        }
        printf("}\n");
        return;
    }
    for (int i = inicio; i <= fim && fim - i + 1 >= k - index; i++) {
        dados[index] = arr[i];
        imprimirCombinacao(arr, dados, i + 1, fim, index + 1, k);
    }
}

void combinacoes(int arr[], int tamanho, int k) {
    int dados[k];
    imprimirCombinacao(arr, dados, 0, tamanho - 1, 0, k);
}

void subconjuntos(int arr[], int tamanho, int index, int subconjunto[], int subTamanho) {
    if (index == tamanho) {
        printf("{");
        for (int i = 0; i < subTamanho; i++) {
            printf("%d", subconjunto[i]);
            if (i < subTamanho - 1) printf(", ");
        }
        printf("}\n");
        return;
    }
    subconjuntos(arr, tamanho, index + 1, subconjunto, subTamanho);
    subconjunto[subTamanho] = arr[index];
    subconjuntos(arr, tamanho, index + 1, subconjunto, subTamanho + 1);
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int buscaBinaria(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return buscaBinaria(arr, l, mid - 1, x);
        return buscaBinaria(arr, mid + 1, r, x);
    }
    return -1;
}

int exponenciacaoRapida(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int temp = exponenciacaoRapida(x, n / 2);
        return temp * temp;
    }
    return x * exponenciacaoRapida(x, n - 1);
}

int contarCaminhos(int m, int n) {
    if (m == 1 || n == 1) return 1;
    return contarCaminhos(m - 1, n) + contarCaminhos(m, n - 1);
}

#define N 4
int tabuleiro[N][N];

int ehSeguro(int tabuleiro[N][N], int linha, int coluna) {
    for (int i = 0; i < coluna; i++)
        if (tabuleiro[linha][i]) return 0;
    for (int i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j]) return 0;
    for (int i = linha, j = coluna; j >= 0 && i < N; i++, j--)
        if (tabuleiro[i][j]) return 0;
    return 1;
}

int resolverNRainhas(int tabuleiro[N][N], int coluna) {
    if (coluna >= N) return 1;
    for (int i = 0; i < N; i++) {
        if (ehSeguro(tabuleiro, i, coluna)) {
            tabuleiro[i][coluna] = 1;
            if (resolverNRainhas(tabuleiro, coluna + 1)) return 1;
            tabuleiro[i][coluna] = 0;
        }
    }
    return 0;
}

#define LAB_SIZE 3
int labirinto[LAB_SIZE][LAB_SIZE] = {{0, 1, 0}, {0, 0, 0}, {1, 0, 1}};
int solucao[LAB_SIZE][LAB_SIZE];

int ehValido(int x, int y) {
    return (x >= 0 && x < LAB_SIZE && y >= 0 && y < LAB_SIZE && labirinto[x][y] == 0 && solucao[x][y] == 0);
}

int resolverLabirinto(int x, int y) {
    if (x == LAB_SIZE - 1 && y == LAB_SIZE - 1) {
        solucao[x][y] = 1;
        return 1;
    }
    if (ehValido(x, y)) {
        solucao[x][y] = 1;
        if (resolverLabirinto(x + 1, y)) return 1;
        if (resolverLabirinto(x, y + 1)) return 1;
        solucao[x][y] = 0;
    }
    return 0;
}

void gerarParenteses(char *str, int n, int aberto, int fechado, int pos) {
    if (fechado == n) {
        printf("%s\n", str);
        return;
    }
    if (aberto > fechado) {
        str[pos] = ')';
        gerarParenteses(str, n, aberto, fechado + 1, pos + 1);
    }
    if (aberto < n) {
        str[pos] = '(';
        gerarParenteses(str, n, aberto + 1, fechado, pos + 1);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    printf("Fatorial de 5: %d\n\n", fatorial(5));


    printf("Soma dos primeiros 4 números naturais: %d\n\n", somaEntreNumerosNaturais(4));


    printf("Fibonacci de 6: %d\n\n", fibonacci(6));


    printf("2 elevado a 5: %d\n\n", potenciacao(2, 5));


    printf("Contagem regressiva de 3:\n");
    contagemRegressiva(3);
    printf("\n\n");


    printf("Soma dos dígitos de 1234: %d\n\n", soma_digitos(1234));


    char str[] = "recursao";
    inverter_string(str, 0, 7);
    printf("String invertida: %s\n\n", str);


    char palindromo1[] = "arara";
    char palindromo2[] = "casa";
    printf("'arara' é palíndromo? %d\n", ehPalindromo(palindromo1, 0, strlen(palindromo1) - 1));
    printf("'casa' é palíndromo? %d\n\n", ehPalindromo(palindromo2, 0, strlen(palindromo2) - 1));


    printf("MDC de 48 e 18: %d\n\n", mdc(48, 18));


    printf("4 * 5 = %d\n\n", multiplicar(4, 5));


    printf("'a' em 'abracadabra': %d\n\n", contarCaracteres("abracadabra", 'a', 0));


    int arr[] = {1, 2, 3, 4};
    printf("Soma do array: %d\n\n", somaArray(arr, 4));


    printf("7 é primo? %d\n", verificaPrimo(7));
    printf("9 é primo? %d\n\n", verificaPrimo(9));


    printf("10 em binário: ");
    decimalParaBinario(10);
    printf("\n\n");


    printf("Pares até 6: ");
    imprimirPares(6);
    printf("\n\n");


    printf("Ímpares até 7: ");
    imprimirImpares(7);
    printf("\n\n");


    int arrBusca[] = {2, 4, 6, 8};
    printf("6 está no array? %d\n", buscaArray(arrBusca, 4, 6));
    printf("5 está no array? %d\n\n", buscaArray(arrBusca, 4, 5));


    printf("Comprimento de 'recursivo': %d\n\n", comprimentoString("recursivo"));


    printf("Torre de Hanói para 2 discos:\n");
    torreHanoi(2, 'A', 'C', 'B');
    printf("\n\n");


    char perm[] = "abc";
    printf("Permutações de 'abc':\n");
    permutacoes(perm, 0, strlen(perm) - 1);
    printf("\n\n");


    int comb[] = {1, 2, 3};
    printf("Combinações de tamanho 2:\n");
    combinacoes(comb, 3, 2);
    printf("\n\n");


    int sub[] = {1, 2};
    printf("Subconjuntos de {1, 2}:\n");
    int subconjunto[2];
    subconjuntos(sub, 2, 0, subconjunto, 0);
    printf("\n\n");


    int mergeArr[] = {5, 3, 8, 1};
    printf("Merge Sort de {5, 3, 8, 1}: ");
    mergeSort(mergeArr, 0, 3);
    for (int i = 0; i < 4; i++) printf("%d ", mergeArr[i]);
    printf("\n\n");


    int quickArr[] = {9, 2, 5, 1, 7};
    printf("Quick Sort de {9, 2, 5, 1, 7}: ");
    quickSort(quickArr, 0, 4);
    for (int i = 0; i < 5; i++) printf("%d ", quickArr[i]);
    printf("\n\n");


    int binArr[] = {1, 3, 5, 7, 9};
    printf("Busca binária por 5: índice %d\n\n", buscaBinaria(binArr, 0, 4, 5));


    printf("3^4 = %d\n\n", exponenciacaoRapida(3, 4));


    printf("Caminhos em matriz 3x3: %d\n\n", contarCaminhos(3, 3));


    memset(tabuleiro, 0, sizeof(tabuleiro));
    if (resolverNRainhas(tabuleiro, 0)) {
        printf("Solução para 4 rainhas:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) printf("%d ", tabuleiro[i][j]);
            printf("\n");
        }
    }
    printf("\n\n");


    memset(solucao, 0, sizeof(solucao));
    if (resolverLabirinto(0, 0)) {
        printf("Solução do labirinto:\n");
        for (int i = 0; i < LAB_SIZE; i++) {
            for (int j = 0; j < LAB_SIZE; j++) printf("%d ", solucao[i][j]);
            printf("\n");
        }
    }
    printf("\n\n");


    char parenteses[7] = {0};
    printf("Parênteses válidos para n=3:\n");
    gerarParenteses(parenteses, 3, 0, 0, 0);
    printf("\n\n");

    return 0;
}
