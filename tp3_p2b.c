#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILA 5
#define COLUMNA 12

void CargarProduccion(int *simulacionProduccion);
void MostrarProduccion(int *simulacionProduccion);
void GananciasAnuales(int *simulacionProduccion);
void ValorMaximo(int *simulacionProduccion);
void ValorMinimo(int *simulacionProduccion);

int main()
{
    srand(time(NULL));
    int *simulacionProduccion = (int *)malloc(sizeof(int) * COLUMNA * FILA);

    CargarProduccion(simulacionProduccion);

    MostrarProduccion(simulacionProduccion);

    GananciasAnuales(simulacionProduccion);

    ValorMaximo(simulacionProduccion);
    
    ValorMinimo(simulacionProduccion);

    free(simulacionProduccion);
}

void CargarProduccion(int *simulacionProduccion)
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            *(simulacionProduccion + i * COLUMNA + j) = rand() % (5000 - 1000 + 1) + 1000;
        }
    }
}

void MostrarProduccion(int *simulacionProduccion)
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            printf("%d \t", *(simulacionProduccion + i * COLUMNA + j));
        }
        printf("\n");
    }
}

void GananciasAnuales(int *simulacionProduccion)
{
    int promedioAnual[FILA];
    for (int i = 0; i < FILA; i++)
    {
        int suma = 0;
        for (int j = 0; j < COLUMNA; j++)
        {
            suma += *(simulacionProduccion + i * COLUMNA + j);
        }
        promedioAnual[i] = suma / COLUMNA;
    }

    printf("promedio ganancias por anio:\n");
    for (int i = 0; i < FILA; i++)
    {
        printf("anio [%d]: %d\n", i + 1, promedioAnual[i]);
    }
}

void ValorMaximo(int *simulacionProduccion)
{
    int maximo = INT_MIN, anio = 0, mes = 0;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            if (*(simulacionProduccion + i * COLUMNA + j) > maximo)
            {
                maximo = *(simulacionProduccion + i * COLUMNA + j);
                anio = i + 1;
                mes = j + 1;
            }
        }
    }
    printf("maximo recaudacion: %d   //   mes: %d   //   anio: %d\n", maximo, mes, anio);
}

void ValorMinimo(int *simulacionProduccion)
{
    int minimo = INT_MAX, anio = 0, mes = 0;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            if (*(simulacionProduccion + i * COLUMNA + j) < minimo)
            {
                minimo = *(simulacionProduccion + i * COLUMNA + j);
                mes = j + 1;
                anio = i + 1;
            }
        }
    }
    printf("minimo recaudacion: %d   //   mes: %d   //   anio: %d\n",minimo , mes , anio);
}