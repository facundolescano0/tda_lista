#include "cola.h"
#include "lista.h"
#include <stdbool.h>


cola_t *cola_crear()
{
	lista_t *cola = lista_crear();
	if(!cola)
		return NULL;
	return (cola_t *)cola;
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	if(!cola || !elemento)
		return NULL;
	lista_insertar((lista_t *)cola, elemento);
	return (cola_t *)cola;
}

void *cola_desencolar(cola_t *cola)
{
	if(!cola)
		return NULL;
	void *elemento;
	lista_t *lcola = (lista_t *)cola;
	elemento = lista_quitar_de_posicion(lcola,0);
	return elemento;
}

void *cola_frente(cola_t *cola)
{
	if(!cola)
		return NULL;
	lista_t *lcola = (lista_t *)cola;

	return lista_primero(lcola);
}

size_t cola_tamanio(cola_t *cola)
{
	if(!cola)
		return 0;

	return lista_tamanio( (lista_t *)cola );
}

bool cola_vacia(cola_t *cola)
{	
	lista_t *lcola = (lista_t *)cola;
	if(lista_vacia(lcola))
		return true;
	return false;
}

void cola_destruir(cola_t *cola)
{
	if(!cola){
		return;
	}
	lista_t *lcola = (lista_t *)cola;
	lista_destruir(lcola);
}
