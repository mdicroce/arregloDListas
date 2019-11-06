#ifndef ARREGLOSDLISTAS_H_INCLUDED
#define ARREGLOSDLISTAS_H_INCLUDED



#endif // ARREGLOSDLISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
   int nota;
   int legajo;
   char nombreApe[30];
   char materia[30];
   int idMateria;
} registroArchivo;

typedef struct {
   int nota;
   int legajo;
   char nombreApe[30];
} notaAlumno;

typedef struct _nodo {
   notaAlumno dato;
   struct _nodo *siguiente;
}nodo;


typedef struct {
    int idMateria;
    char materia[30];
    nodo * listaDeNotas;
} celda;

nodo * inicLista();
nodo * crearNodo (registroArchivo dato);
nodo * agregarPpio (nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * buscarNodo(char nombre[20], nodo * lista);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * borrarNodo(nodo * lista, char nombre[20]);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
nodo * borrarTodaLaLista(nodo * lista);
int sumarEdadesLista(nodo * lista);
void mostrarUnNodo(nodo * aux);
void recorrerYmostrar(nodo * lista);
int alta(celda roro[],registroArchivo dato, int dimension);
int ingresarNotas (celda roro[], int dimension, registroArchivo dato);
int buscaPosMateria (celda adl[],char materia[], int validos);
int agregarMateria (celda adl[],int materia, char nombre[], int idMateria);
