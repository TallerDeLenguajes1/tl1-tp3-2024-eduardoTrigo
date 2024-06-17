#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define FILA 3
#define COLUMNA 2

int main(){
    // int *punt;
    // punt = (int*)malloc(sizeof(int));
    // *punt = 20;

    // printf("\nel contenido del puntero %d en la direccion : %p-- ",*punt,punt);
    // free(punt);

    // printf("\nel contenido del puntero %d en la direccion : %p-- ",*punt,punt);

    // getchar();

    int *pvect;
    pvect = (int*)malloc(sizeof(int)* MAX);

    for (int i = 0; i < MAX; i++)
    {
        *(pvect + i) = i;
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("pvect(%d) = %d \n", i, *(pvect + i));
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("--pvect--(%d) = %d \n", i, pvect[i]);
    }
    free(pvect);

    
    //matriz (2 dimensiones);

    int * pMatriz = (int *)malloc(sizeof(int)*FILA*COLUMNA);

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            *(pMatriz +i * COLUMNA + j) = i+j;
        }
    }

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            printf("%d\t",*(pMatriz + i * COLUMNA + j));
        }
        printf("\n");
    }    

    // puntero doble

    int **pMatriz2 = (int**)malloc(sizeof(int)*FILA);

    for (int i = 0; i < FILA; i++)
    {
        pMatriz2[i] = (int*)malloc(sizeof(int)* COLUMNA);
        for (int j = 0; j < COLUMNA; j++)
        {
            pMatriz2[i][j] = i+j;
        }
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j <COLUMNA; j++)
        {
            printf("%d\t", **(pMatriz2 + i * COLUMNA + j));
        }
        printf("\n");
    }
    

    return 0;
}