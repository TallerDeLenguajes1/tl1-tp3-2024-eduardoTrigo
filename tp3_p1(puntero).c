#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILA 5
#define COLUMNA 12

int cargarTabla(int arreglo[FILA][COLUMNA]);
void mostrarTabla(int arreglo[FILA][COLUMNA]);
void promedioAnios(int arreglo[FILA][COLUMNA]);
void mostrarMayor(int arreglo[FILA][COLUMNA]);
void mostrarMenor(int arreglo[FILA][COLUMNA]);

int main()
{
    srand(time(NULL));
    int simularProduccion[FILA][COLUMNA];
    int *simuProd;
    simuProd = simularProduccion;

    cargarTabla(simularProduccion);
    mostrarTabla(simularProduccion);
    promedioAnios(simularProduccion);
    mostrarMayor(simularProduccion);
    mostrarMenor(simularProduccion);
}

int cargarTabla(int arreglo[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            arreglo[i][j] = rand() % (5000 - 1000 + 1) + 1000;
        }
    }
}

void mostrarTabla(int arreglo[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            printf("%d\t", arreglo[i][j]);
        }
        printf("\n");
    }
}

void promedioAnios(int arreglo[FILA][COLUMNA])
{
    int promAnual[FILA];
    for (int i = 0; i < FILA; i++)
    {
        int suma = 0, promedio = 0;
        for (int j = 0; j < COLUMNA; j++)
        {
            suma += arreglo[i][j];
        }
        promedio = suma / COLUMNA;
        promAnual[i] = promedio;
    }
    printf("----promedio anual----\n");
    for (int i = 0; i < FILA; i++)
    {
        printf("año %d: %d\n", i + 1, promAnual[i]);
    }
}

void mostrarMayor(int arreglo[FILA][COLUMNA])
{
    int arregloMayor[FILA];
    for (int i = 0; i < FILA; i++)
    {
        int mayor = 0;
        for (int j = 0; j < COLUMNA; j++)
        {
            if (arreglo[i][j] > mayor)
            {
                mayor = arreglo[i][j];
            }
        }
        arregloMayor[i] = mayor;
    }
    printf("el mayor de cada año es :\n");
    for (int i = 0; i < FILA; i++)
    {
        printf("anio %d : %d\t", i + 1, arregloMayor[i]);
    }
}

void mostrarMenor(int arreglo[FILA][COLUMNA]){
    int arregloMenor[FILA];
    for (int i = 0; i < FILA; i++)
    {
        int menor=5000;
        for (int j = 0; j < COLUMNA; j++)
        {
            if (arreglo[i][j] < menor)
            {
                menor = arreglo[i][j];
            }
        }
        arregloMenor[i]= menor;
    }
    printf("\nel menor de cada año es:\n");
    for (int i = 0; i < FILA; i++)
    {
        printf("año %d: %d\t", i+1, arregloMenor[i]);
    }
}