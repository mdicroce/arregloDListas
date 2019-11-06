#include <stdio.h>
#include <stdlib.h>
#include "ArreglosDListas.h"
#include <windows.h>
#include <string.h>

int pasarDeArchivoToADL(char nombre[],celda roro[], int validos)
{
    FILE *archiv = fopen(nombre,"rb");
    registroArchivo dato;
    if (archiv != NULL)
    {
        while (!feof(archiv))
        {
            fread(&dato,sizeof (registroArchivo),1, archiv);
            validos = ingresarNotas(roro,validos, dato);
        }
    }
    return validos;
}

pasarDeADLToArchivoDeAprobados ()
{

}
int main()
{

    return 0;
}
