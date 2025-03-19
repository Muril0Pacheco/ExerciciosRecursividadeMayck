#include <stdio.h>
#include <stdlib.h>

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

int main() {
     printf("Fatorial de 5: %d\n", fatorial(5));
    printf("Soma dos primeiros 4 números naturais: %d\n", somaEntreNumerosNaturais(4));
    printf("Fibonacci de 6: %d\n", fibonacci(6));
    printf("2 elevado a 5: %d\n", potenciacao(2, 5));
    printf("Contagem regressiva de 3:\n");
    contagemRegressiva(3);
    printf("Soma dos dígitos de 1234: %d\n", soma_digitos(1234));

    char str[] = "recursao";
    inverter_string(str, 0, 7);
    printf("String invertida: %s\n", str);

    return 0;
}
