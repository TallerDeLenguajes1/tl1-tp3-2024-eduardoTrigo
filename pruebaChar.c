#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 13
#define NOMBRES 3

int main(){
    char *punt;
    punt = (char*)malloc(sizeof(char)*11);
    strcpy(punt , "hola mundo");

    printf("%s", punt);
    getchar;

    // puntero doble

    char **nombres = (char **)malloc(sizeof(char*)* NOMBRES);
    for (int i = 0; i < NOMBRES; i++)
    {
        nombres[i] = (char*)malloc(sizeof(char) * MAX);
        printf("\nAgregar nombre %d:", i);
        fgets(nombres[i], MAX, stdin);
    }
    
    for (int i = 0; i < NOMBRES; i++)
    {
        printf("%s", nombres[i]);
    }

    for (int i = 0; i < NOMBRES; i++)
    {
        free(nombres[i]);
    }
    
    
    return 0;
}