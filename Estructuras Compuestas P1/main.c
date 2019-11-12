#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "ArreglosDListas.c"
MostrarDatos (celda roro[],int validos)
{
    for (int i=0;i<validos;i++)
    {
         printf("\n\nID.Materia: %i\n%Materia: %s",roro[i].idMateria,roro[i].materia);
        mostrarRegistro(roro[i].listaDeNotas);
    }
}
void mostrarRegistro (nodo * listadAlumnos)
{
    if (listadAlumnos!= NULL)
    {
        printf("---------------------------------------------------------------------------\n");
        printf("\nNombre: %s,\nlegajo %i,\nnota: %i \n",listadAlumnos->dato.nombreApe,listadAlumnos->dato.legajo,listadAlumnos->dato.nota);
        printf("---------------------------------------------------------------------------\n");
        listadAlumnos = listadAlumnos->siguiente;
    }
}
int pasarDeArchivoToADL(char nombre[],celda roro[], int validos)
{
    FILE *archiv = fopen(nombre,"rb");
    registroArchivo dato;
    int i = 0;
    if (archiv != NULL)
    {
        while (!feof(archiv))
        {
            printf("\n%i",validos);
            i++;
            fread(&dato,sizeof (registroArchivo),1, archiv);
            validos = ingresarNotas(roro,validos,dato);
        }
    }
    return validos;
}

pasarDeADLToArchivoDeAprobados ()
{

}
int main()
{
    celda arregloDeListas [999];
    int validos;
    validos = pasarDeArchivoToADL("registroArchivo.dat",arregloDeListas,0);
    MostrarDatos (arregloDeListas,validos);

    return 0;
}
