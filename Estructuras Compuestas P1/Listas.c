#include "Listas.h"

nodo * inicLista()
{
    return NULL;
}
nodo * crearNodo (persona dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo ->dato = dato;
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
nodo * buscarNodo(char nombre[20], nodo * lista)
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
}
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
nodo * borrarNodo(nodo * lista, char nombre[20])
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
}
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
int sumarEdadesLista(nodo * lista)
{
    int sumatoria=0;
    nodo *seg;
    while (seg != NULL)
    {
        sumatoria += seg->dato.edad;
        seg = seg->siguiente;
    }
    return sumatoria;
}
void mostrarUnNodo(nodo * aux)
{
    printf("\n Nombre:%s\nEdad%i",aux->dato.nombre,aux->dato.edad);
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
persona cargarPersona (void)
{
    persona dato;
    system("cls");
    printf("\nIngrese nombre y edad\nNombre: ");
    fflush(stdin);
    gets(dato.nombre);
    printf("\nEdad: ");
    scanf("%i",&dato.edad);
    return dato;
}
nodo * subprogramaIngresarDatosAlFinal(nodo * lista)
{
    persona dato=cargarPersona();
    nodo *nuevo = crearNodo(dato);
    agregarFinal(lista,nuevo);
    return lista;
}
nodo * subprogramaingresarDatosAlPpio(nodo * lista)
{
    persona dato = cargarPersona();
    nodo *nuevo = crearNodo(dato);
    agregarPpio(lista,nuevo);
    return lista;
}
nodo * subprogramaAgregarUnNodoEnOrden(nodo * lista)
{
    persona dato= cargarPersona();
    nodo * nuevo = crearNodo(dato);
    agregarEnOrden(lista,nuevo);
    printf("puto");
    return lista;
}
nodo * subprogramaCrearListaOrdenada(nodo * lista)
{
    char opc;
    nodo *nuevo;
    while (opc != 27)
    {
        persona dato=cargarPersona();
        nuevo = crearNodo(dato);
        lista = agregarEnOrden(lista,nuevo);
        printf("\nSi desea terminar de agregar datos, presione ESC");
        fflush(stdin);
        opc = getch();
    }
    return lista;
}
nodo * subprogramaBusquedaDeUnNodo (nodo * lista)
{
    persona dato=cargarPersona();
    nodo *seg = buscarNodo(dato.nombre,lista);
    if (seg != NULL)
    {
        printf("\nDato encontrado,\nNombre: %s\n Edad: %i",seg->dato.nombre,seg->dato.edad);
    }
    return seg;
}
nodo * subprogramaBorrarNodo(nodo * lista)
{
    persona dato = cargarPersona();
    borrarNodo(lista,dato.nombre);
    return lista;
}
nodo * menu(nodo * lista)
{
    char opc;
    nodo * seg;
    system("cls");
    printf("Presione:\n1 Para ingresar datos al final\n2 Para ingresar datos al principio\n3 Para ingresar datos en orden alfabetico\n4 Para crear una lista ordenada\n 5 Para buscar un nodo\n6 Para eliminar un nodo");
    fflush(stdin);
    opc = getch();
    switch(opc)
    {
    case 49:
        lista = subprogramaIngresarDatosAlFinal(lista);
        break;
    case 50:
        lista = subprogramaingresarDatosAlPpio(lista);
        break;
    case 51:
        lista = subprogramaAgregarUnNodoEnOrden(lista);
        break;
    case 52:
        lista = subprogramaCrearListaOrdenada(lista);
        break;
    case 53:
         seg = subprogramaBusquedaDeUnNodo(lista);
        break;
    case 56:
        lista = subprogramaBorrarNodo(lista);
        break;
    default:
        break;
    }
    return lista;
}
