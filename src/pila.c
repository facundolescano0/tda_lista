#include "pila.h"
#include "lista.h"
#include <stdbool.h>

pila_t *pila_crear()
{
	return (pila_t *)lista_crear();
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	if (!pila)
		return NULL;
	lista_t *lpila = (lista_t *)pila;
	lista_insertar_en_posicion(lpila, elemento, 0);
	return pila;
}

void *pila_desapilar(pila_t *pila)
{
	if (!pila)
		return NULL;
	lista_t *lpila = (lista_t *)pila;
	return lista_quitar_de_posicion(lpila, 0);
}

void *pila_tope(pila_t *pila)
{
	if (!pila)
		return NULL;
	lista_t *lpila = (lista_t *)pila;
	return lista_primero(lpila);
}

size_t pila_tamanio(pila_t *pila)
{
	if (!pila)
		return 0;
	lista_t *lpila = (lista_t *)pila;
	return lista_tamanio(lpila);
}

bool pila_vacia(pila_t *pila)
{
	if (!pila)
		return false;
	lista_t *lpila = (lista_t *)pila;
	return lista_vacia(lpila);
}

void pila_destruir(pila_t *pila)
{
	if (!pila)
		return;
	lista_t *lpila = (lista_t *)pila;
	lista_destruir(lpila);
}
