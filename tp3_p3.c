#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRES 5
#define MAX 20

int main(){
    char **pNombre = (char**)malloc(sizeof(char*)* NOMBRES);
    char *buff = (char*)malloc(sizeof(char)*MAX) ;
 
    for (int i = 0; i < NOMBRES; i++)
    {
        printf("ingrese nombre {%d}",i + 1);
        fgets(buff,MAX,stdin);

        pNombre[i] = (char*)malloc(sizeof(char) * (strlen(buff)+1));
        strcpy(pNombre[i],buff);
    }
    

    // Encuentra la posición del salto de línea y reemplazarlo por '\0'
    buff[strcspn(buff, "\n")] = '\0';
    free(buff);
    printf("\n");
    printf("--------------------------");
    printf("\n");

    for (int i = 0; i < NOMBRES; i++)
    {
        printf("nombre{%d}: %s", i+1 , pNombre[i] );
        free(pNombre[i]);
    }
    free(pNombre);
    return 0;
}