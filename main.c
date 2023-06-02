#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int elegirTamanio();
int generarAleatorio(int min, int max);
void cargarVectorAleatorio(int v[], int tam);
void mostarVector(int v[], int tam);
void mostrasPosicionesDivisibles3(int v[], int tam);
int encontrarMaximoImparesNeg(int v[],int tam);


int main(){
    srand(time(0));

    generarAleatorio(-99,99);

    int tam=elegirTamanio();
    int v[tam];
    cargarVectorAleatorio(v,tam);
    mostarVector(v,tam);

    mostrasPosicionesDivisibles3(v,tam);

    encontrarMaximoImparesNeg(v,tam);


    return 0;
}

int elegirTamanio(){
    int tamanio;
    do {
    printf("Ingrese un tamanio de 2 cifras que no puede terminar en 7: ");
    scanf("%d", &tamanio);
    } while(tamanio<9 || tamanio>100 || tamanio%10==7);
    return tamanio;
};

int generarAleatorio(int min, int max){
    int ale;
    do{
    ale= min+rand()%(max-min+1);
    } while (ale%2==1);
    return ale;
};

void cargarVectorAleatorio(int v[], int tam){
    int numero;
    for(int i=0; i<tam; i++){
        numero=generarAleatorio(-99, 99);
        while(numero>=-9 && numero<=9){
            numero=generarAleatorio(-99, 99);
        }
        v[i]=numero;
    }
};

void mostarVector(int v[], int tam){
    printf("||");
    for(int i=0; i<tam; i++){
        printf(" %d ", v[i]);
    }
    printf("||");
};

void mostrasPosicionesDivisibles3(int v[], int tam){
    printf("\n");
    printf("||");
    for(int i=0; i<tam; i++){
        if(i%3==0){
            printf(" %d ", v[i]);
        }
    }
    printf("||");
};

int encontrarMaximoImparesNeg(int v[],int tam){

    int maximo = -1;  // Inicializamos el máximo como -1 (un valor que no existe en el vector)

    for (int i = 0; i < tam; i++) {
        if (v[i] < 0 && v[i] % 2 != 0) {  // Verificar si el número es negativo e impar
            if (maximo == -1 || v[i] > maximo) {
                maximo = v[i];
            }
        }
    }
    printf("\nEl mayor de los neg es: %d", maximo);
    return maximo;
};
