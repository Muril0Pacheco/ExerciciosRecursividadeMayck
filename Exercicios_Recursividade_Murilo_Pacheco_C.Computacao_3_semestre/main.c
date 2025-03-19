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
    return num + somaEntreNumeros(num - 1);
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

int contagemRegressiva(int n, int y){

        printf("%d\n", y);
        if (n>y){
            return imprimenumeros(n, y+1);
        }
        else {
            return 0 ;
        }
    }

int soma_digitos(int n) {
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

    if (n == 0) {
        return 0;
    }

    return (n % 10) + soma_digitos(n / 10);
}

int main() {
  //Chame as funções aqui
}
