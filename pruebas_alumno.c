#include "pa2m.h"
#include "src/lista.h"
#include <stdlib.h>


void crear_lista_no_es_nula()
{
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista != NULL, "Lista creada distinta de NULL");
	lista_destruir(lista);
}
void crear_lista_cantidad_elementos_0()
{
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista_tamanio(lista)==0, "Cantidad de lista creada es 0");
	lista_destruir(lista);
}

void destruir_elemento(void *actual){
	if(!actual){
		return ;
	}
	free(actual);
}

int elementos_comparados(void *actual, void *elemento){
	
	if(!actual || !elemento)
		return -1;
	if (actual == elemento){
		return 0;
	}
	return -1;
}

void insertar_agrega_elemento_al_final()
{
	lista_t *lista = lista_crear();
	
	char elemento1 = 'g';
	char elemento2 = 'd';
	int elemento3 = 13;
	int elemento4 = 8;
	int elemento5 = 10;
	size_t posicion1 = 1;
	size_t posicion2 = 10;
	
	lista_insertar(lista, &elemento1);
	lista_insertar(lista, &elemento2);
	lista_insertar(lista, &elemento3);
	pa2m_afirmar(lista_ultimo(lista) == &elemento3, "elemento final es el insertado");
	pa2m_afirmar(lista_primero(lista) == &elemento1, "inserta elementos al final no rompe inicio");
	lista_insertar_en_posicion(lista, &elemento4, posicion1);
	lista_insertar_en_posicion(lista, &elemento5, posicion2);
	pa2m_afirmar(lista_ultimo(lista) == &elemento5, "elemento final es el insertado en una posicion inexistente");
	pa2m_afirmar(lista_quitar(lista) == &elemento5, "quitar devuelve elemento eliminado");
	pa2m_afirmar(lista_ultimo(lista) == &elemento3, "quitar elimina ultimo elemento");
	pa2m_afirmar(lista_quitar_de_posicion(lista,1) == &elemento4, "quitar_posicion elimina posicion y devuelve elemento (insertar_posicion OK)");
	pa2m_afirmar(lista_elemento_en_posicion(lista,0)== &elemento1, "elemento en posicion buscada fue encontrado");
	pa2m_afirmar(lista_buscar_elemento(lista,elementos_comparados,&elemento1)==&elemento1, "elemento buscado en lista fue encontrado");
	pa2m_afirmar(lista_buscar_elemento(lista,elementos_comparados,"elemento")==NULL, "elemento inexistente buscado en lista devuelve NULL");
	lista_destruir(lista);
}

int main()
{
	pa2m_nuevo_grupo("pruebas_crear_lista");
	crear_lista_no_es_nula();
	crear_lista_cantidad_elementos_0();
	insertar_agrega_elemento_al_final();

	return pa2m_mostrar_reporte();
}
