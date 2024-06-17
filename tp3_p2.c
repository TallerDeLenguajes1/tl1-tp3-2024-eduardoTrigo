#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILA 5
#define COLUMNA 12

void cargarArreglo(int arreglo[FILA][COLUMNA]);
void mostrarArreglo(int arreglo[FILA][COLUMNA]);
void gananciasAnuales(int arreglo[FILA][COLUMNA]);
void valorMaximo(int arreglo[FILA][COLUMNA]);
void valorMinimo(int arreglo[FILA][COLUMNA]);

int main(){

    int simularProduccion[FILA][COLUMNA];

    srand(time(NULL));
    cargarArreglo(simularProduccion);
    mostrarArreglo(simularProduccion);

    gananciasAnuales(simularProduccion);
    
    valorMaximo(simularProduccion);
    valorMinimo(simularProduccion);
}


void cargarArreglo(int arreglo[FILA][COLUMNA]){

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            arreglo[i][j] = rand() % (5000 - 1000 + 1) + 1000;
        }
    }
}

void mostrarArreglo( int arreglo[FILA][COLUMNA]){
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            printf("%d\t", arreglo[i][j] );
        }
        printf("\n");
    }   
}

void gananciasAnuales(int arreglo[FILA][COLUMNA]){
    int promedioAnual[FILA];
    for (int i = 0; i < FILA; i++)
    {
        int suma = 0;
        for (int j = 0; j < COLUMNA; j++)
        {
            suma += arreglo[i][j];
        }
        promedioAnual[i] = suma / 12;
    }

    for (int i = 0; i < FILA; i++)
    {
        printf("-Anio (%d): %d \t", i+1 , promedioAnual[i]);
    }
}

void valorMaximo(int arreglo[FILA][COLUMNA]){
    int maximo = INT_MIN , anio = 0, mes = 0;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            if (arreglo[i][j] > maximo)
            {
                maximo = arreglo[i][j];
                mes =  j + 1;
                anio = i + 1;
            }
        }
    }
    printf("\nValor Maximo: %d // Anio: 200%d  // Mes: %d", maximo, anio, mes);    
}

void valorMinimo(int arreglo[FILA][COLUMNA]){
    int minimo = INT_MAX , anio = 0, mes = 0;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            if ( arreglo[i][j] < minimo)
            {
                minimo = arreglo[i][j];
                mes = j + 1;
                anio = i + 1;
            }
        }
    }
    printf("\nValor Minimo: %d // Anio: 200%d // mes: %d", minimo, anio, mes);
}