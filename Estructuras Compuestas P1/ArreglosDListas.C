#include "ArreglosDListas.h"

nodo * inicLista()
{
    return NULL;
}
nodo * crearNodo (registroArchivo dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo ->dato.legajo = dato.legajo;
    nuevo ->dato.nota = dato.nota;
    strcpy(nuevo->dato.nombreApe,dato.nombreApe);
    nuevo ->siguiente = NULL;
    return nuevo;
}
nodo * agregarPpio (nodo * lista, nodo * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo ->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}
nodo * buscarUltimo(nodo * lista)
{
    nodo*seg = lista;
    if (lista == NULL)
    {

    }
    else
    {
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}
/*nodo * buscarNodo(char nombre[20], nodo * lista)
{
    nodo *seg = lista;
    nodo *anterior;
    if (lista != NULL)
    {
        while ((strcmp(nombre,seg->dato.nombre)!=0)&&(seg!= NULL))
        {
            seg= seg->siguiente;
        }
    }
    return seg;
}*/
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    nodo * seg;
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else if (lista ->siguiente == NULL)
    {
        lista->siguiente = nuevoNodo;
    }
    else
    {
        seg = buscarUltimo(lista);
        seg ->siguiente = nuevoNodo;
    }
    return lista;
}
/*nodo * borrarNodo(nodo * lista, char nombre[20])
{
    nodo *seg;
    nodo *ante;

    if ((lista != NULL) && (strcmp (lista->dato.nombre,nombre)==0))
    {
        nodo * aux = lista;
        lista = lista -> siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while ((strcmp(seg->dato.nombre,nombre)!=0)&&(seg != NULL))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if (seg != NULL)
        {
            ante ->siguiente = seg ->siguiente;
            free(seg);
        }
    }
    return lista;
}
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
{

    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if (strcmp(lista->dato.nombre,nuevoNodo->dato.nombre)>0)
        {
            lista = agregarPpio(lista,nuevoNodo);
        }
        else
        {
            nodo *seg=lista->siguiente;
            nodo *ante=lista;
            while ((strcmp(ante->dato.nombre,nuevoNodo->dato.nombre)<0)&&(seg != NULL))
            {
                ante = seg;
                seg = ante->siguiente;
            }
            nuevoNodo->siguiente = seg;
            ante ->siguiente = nuevoNodo;
        }
    }

    return lista;
}*/
nodo * borrarTodaLaLista(nodo * lista)
{
    nodo*seg = lista;
    nodo * next;
    while (seg != NULL)
    {
        next = seg ->siguiente;
        free(seg);
        seg = next;
    }
    return seg;
}
/*int sumarEdadesLista(nodo * lista)
{
    int sumatoria=0;
    nodo *seg;
    while (seg != NULL)
    {
        sumatoria += seg->dato.edad;
        seg = seg->siguiente;
    }
    return sumatoria;
}*/
void mostrarUnNodo(nodo * aux)
{

}
void recorrerYmostrar(nodo * lista)
{
    nodo *seg = lista;
    while (seg != NULL)
    {
        system("pause");
        mostrarUnNodo(seg);
        seg = seg->siguiente;
    }
}
notaAlumno cargarPersona (void)
{
    notaAlumno dato;
    system("cls");
    printf("\nIngrese nombre y edad\nNombre: ");
    fflush(stdin);
    printf("\nEdad: ");
    return dato;
}
int ingresarNotas (celda roro[], int dimension, registroArchivo dato)
{
    dimension = alta(roro,dato,dimension);
    return dimension;
}
int alta(celda roro[],registroArchivo dato,int dimension)
{
    nodo *aux = crearNodo(dato);
    int pos = buscaPosMateria(roro,dato.materia,dimension);
    if (pos = -1)
    {
        dimension = agregarMateria(roro,dimension,dato.materia,dato.idMateria);
        pos = dimension -1;
    }
    roro [pos].listaDeNotas = agregarPpio(roro[pos].listaDeNotas,aux);
    return dimension;
}
int buscaPosMateria (celda adl[],char materia[], int validos)
{
    int pos = -1;
    for (int i = 0;i<validos;i++)
    {
        if (0==strcmp(materia,adl[i].materia))
        {
            pos = i;
        }
    }
    return pos;
}
int agregarMateria (celda adl[],int materia, char nombre[],int idMateria)
{
    adl[materia].idMateria=idMateria;
    strcpy(adl[materia].materia,nombre);
    adl[materia].listaDeNotas = inicLista();
    materia++;
    return materia;
}
