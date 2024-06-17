#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TipoProductos[] = {"galletas", "snack", "cigarrillos", "Caramelos", "bebidas"};

struct Producto
{
    int ProductoId;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} typedef Producto;

struct Cliente
{
    int ClienteId;
    char *NombreCliente;
    int productosAPedir;
    Producto *Productos;
} typedef Cliente;

int numeroAleatorio(int min, int max);
void CargarCliente(Cliente *clientes, int cantidadClientes);
void MostrarCliente(Cliente *clientes, int cantidadClientes);

int main()
{
    srand(time(NULL));  //semilla para numeros aleatorios

    int cantidadClientes;
    do
    {
    printf("ingrese cantidad de clientes:");
    scanf("%d", &cantidadClientes);
    } while (cantidadClientes > 5 || cantidadClientes < 1);

    Cliente *clientes = (Cliente *)malloc(sizeof(Cliente) * cantidadClientes);  // reservo memoria para arrelgo de clientes

    CargarCliente(clientes, cantidadClientes);
    MostrarCliente(clientes, cantidadClientes);

    for (int i = 0; i < cantidadClientes; i++)
    {
        free(clientes[i].NombreCliente);    //libero memoria del nombre cliente
        free(clientes[i].Productos);        //libero memoria del arreglo productos
    }

    free(clientes);// libero memoria de arreglo clientes

    return 0;
}

int numeroAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void CargarCliente(Cliente *clientes, int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        clientes[i].ClienteId = i + 1;
        clientes[i].NombreCliente = (char *)malloc(sizeof(char) * 20); // reservo memoria para el nombre cliente
        printf("ingrese nombre cliente %d\n", i) + 1;
        scanf("%s", clientes[i].NombreCliente);

        clientes[i].productosAPedir = numeroAleatorio(1, 5);

        clientes[i].Productos = (Producto *)malloc(sizeof(Producto) * clientes[i].productosAPedir); //reservo memoria para el arreglo producto de cada cliente de acuerdo a la cantidad de productos

        for (int j = 0; j < clientes[i].productosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoId = j + 1;
            clientes[i].Productos[j].Cantidad = numeroAleatorio(1, 5);
            clientes[i].Productos[j].TipoProducto = TipoProductos[numeroAleatorio(0, 4)];
            clientes[i].Productos[j].PrecioUnitario = numeroAleatorio(100, 500);
        }
    }
}

void MostrarCliente(Cliente *clientes, int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("cliente id numero [%d]\n", clientes[i].ClienteId);
        printf("Nombre Cliente: %s \t", clientes[i].NombreCliente);
        printf("cantidad de productos a pedir: %d\n", clientes[i].productosAPedir);
        printf("-----productos------\n");
        for (int j = 0; j < clientes[i].productosAPedir; j++)
        {
            printf("---producto [%d]---\n", i + 1);
            printf("id del producto: %d\n", clientes[i].Productos[j].ProductoId);
            printf("cantidad del producto: %d\n", clientes[i].Productos[j].Cantidad);
            printf("id del producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("id del producto: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("\n");
        }
    }
}