#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
     char nombre[20];
     int edad;
} persona;
typedef struct {
     persona dato;
     struct nodo * siguiente;
} nodo;

nodo * inicLista();
nodo * crearNodo (persona dato);
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
nodo * subprogramaIngresarDatosAlFinal(nodo * lista);
nodo * subprogramaingresarDatosAlPpio(nodo * lista);
nodo * subprogramaAgregarUnNodoEnOrden(nodo * lista);
nodo * subprogramaCrearListaOrdenada(nodo * lista);
nodo * subprogramaBusquedaDeUnNodo(nodo * lista);
nodo * subprogramaBorrarNodo(nodo * lista);
nodo * menu(nodo * lista);
