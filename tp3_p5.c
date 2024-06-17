#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int main()
{
    int cantNombres;

    do
    {
        printf("ingrese la cantidad de nombres a ingresar: \n");
        scanf("%d", &cantNombres);
    } while (cantNombres <= 0);

    
    getchar(); //limpia caracter o salto de linea del buffer despues del scanf 

    char **pNombres = (char **)malloc(sizeof(char *) * cantNombres); //Reservo memoria para un arreglo del puntero, donde cada puntero apuntará a un nombre.
    char *buff = (char *)malloc(sizeof(char) * MAX);  // Reservo memoria para un buffer para el nombre antes de copiarlos.

    for (int i = 0; i < cantNombres; i++)
    {

        printf("ingrese el nombre [%d]\n", i + 1);
        fgets(buff, MAX, stdin);

        buff[strcspn(buff,"\n")] = '\0';      // Encuentra la posición del salto de línea y reemplazarlo por '\0'
        pNombres[i] = (char *)malloc(sizeof(char) * (strlen(buff) + 1)); // Reservo memoria exacta para almacenar el nombre y lo copiamos desde el buffer
        strcpy(pNombres[i], buff);    //copio lo almacenado en buff al pNombre[i]
    }

    free(buff); //libero memoria de buff
    printf("\n");
    printf("------------------");
    printf("\n");

    for (int i = 0; i < cantNombres; i++)
    {
        printf("Nombre[%d]: %s", i+1 , pNombres[i] );
        free(pNombres[i]);//libero memoria de cada nombre
    }
    free(pNombres);//libero memoria del arreglo de nombres

    return 0;
}