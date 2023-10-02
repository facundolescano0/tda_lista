#include "pa2m.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdlib.h>

void destruir_elemento(void *actual)
{
	if (!actual) {
		return;
	}
	free(actual);
}

bool son_iguales(void *elemento, void *contexto)
{
	if (elemento == contexto) {
		return false;
	}
	return true;
}

int elementos_comparados(void *actual, void *elemento)
{
	if (!actual || !elemento)
		return -1;
	if (actual == elemento) {
		return 0;
	}
	return -1;
}

void pruebas_con_lista()
{
	char elemento1 = 'g';
	char elemento2 = 'd';
	void *elemento3 = NULL;
	int elemento4 = 8;
	int elemento5 = 10;
	size_t posicion1 = 1;
	size_t posicion2 = 10;

	pa2m_nuevo_grupo("prueba crear lista");
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista != NULL, "Lista creada VALIDA");
	pa2m_afirmar(lista_tamanio(lista) == 0,
		     "Cantidad de lista creada es 0");
	pa2m_afirmar(lista_vacia(lista), "Lista creada esta vacia");

	pa2m_nuevo_grupo("prueba funciones lista");
	lista_insertar(lista, &elemento1);
	pa2m_afirmar(lista_primero(lista) == &elemento1,
		     "inserto elemento al final en posicion correcto");

	lista_insertar(lista, &elemento2);
	lista_insertar(lista, &elemento3);

	pa2m_afirmar(lista_ultimo(lista) == &elemento3,
		     "inserto elemento NULL al final");
	pa2m_afirmar(!lista_vacia(lista), "La lista no esta vacia");
	pa2m_afirmar(lista_primero(lista) == &elemento1,
		     "el primero de la lista es el correcto");
	lista_insertar_en_posicion(lista, &elemento4, posicion1);
	lista_insertar_en_posicion(lista, &elemento5, posicion2);

	pa2m_afirmar(lista_ultimo(lista) == &elemento5,
		     "elemento de posicion inexistente se inserta al final");

	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &elemento4,
		     "elemento insertado en posicion correspondiente");

	pa2m_afirmar(lista_quitar(lista) == &elemento5,
		     "quitar devuelve elemento eliminado");

	pa2m_afirmar(lista_ultimo(lista) == &elemento3,
		     "quitar elimina ultimo elemento");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 1) == &elemento4,
		     "quitar_posicion elimina posicion y devuelve elemento");

	pa2m_afirmar(lista_tamanio(lista) == 3, "el tamaño es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &elemento1,
		     "elemento en posicion buscada fue encontrado");

	pa2m_afirmar(lista_buscar_elemento(lista, elementos_comparados,
					   &elemento1) == &elemento1,
		     "elemento buscado en lista fue encontrado");

	pa2m_afirmar(lista_buscar_elemento(lista, elementos_comparados,
					   "elemento") == NULL,
		     "elemento inexistente buscado en lista devuelve NULL");
	pa2m_afirmar(lista_insertar(lista, &elemento1) != NULL,
		     "inserto elemento respetido ");

	lista_destruir(lista);
}

void pruebas_con_lista_nula()
{
	char elemento1 = 'g';
	void *elemento3 = NULL;
	int elemento4 = 8;
	size_t posicion1 = 1;

	pa2m_nuevo_grupo("pruebas lista nula");
	lista_t *lista_nula = NULL;
	pa2m_afirmar(lista_insertar(lista_nula, &elemento1) == NULL,
		     "insertar elemento en lista nula es nulo");
	pa2m_afirmar(!lista_insertar_en_posicion(lista_nula, &elemento4,
						 posicion1),
		     "inertar_en_posicion en lista nula es nulo");
	pa2m_afirmar(!lista_quitar(lista_nula),
		     "no se puede quitar de lista nula");
	pa2m_afirmar(!lista_quitar_de_posicion(lista_nula, 5),
		     "no se puede quitar de posicion de lista nula");
	pa2m_afirmar(!lista_elemento_en_posicion(lista_nula, 5),
		     "no se puede obtener elemento de lista nula");
	pa2m_afirmar(!lista_buscar_elemento(lista_nula, elementos_comparados,
					    elemento3),
		     "no se puede buscar en lista nula");
	pa2m_afirmar(!lista_tamanio(lista_nula),
		     "no se puede obtener tamaño de lista nula");
	pa2m_afirmar(!lista_primero(lista_nula),
		     "no se puede obtener primero de lista nula");
	pa2m_afirmar(!lista_ultimo(lista_nula),
		     "no se puede obtener ultimo de lista nula");
	pa2m_afirmar(!lista_iterador_crear(lista_nula),
		     "no se puede crear it interno con lista nula");
	pa2m_afirmar(lista_con_cada_elemento(lista_nula, son_iguales,
					     lista_primero(lista_nula)) == 0,
		     "it interno no itera lista nula");
}

lista_t *llenar_lista(lista_t *lista)
{
	char elemento1 = 'g';
	char elemento2 = 'd';
	int elemento3 = 13;
	int elemento4 = 8;
	lista_insertar(lista, &elemento1);
	lista_insertar(lista, &elemento2);
	lista_insertar(lista, &elemento3);
	lista_insertar(lista, &elemento4);
	return lista;
}

size_t buscando_elemento(lista_iterador_t *iterador, void *elemento)
{
	size_t contador = 0;

	for (lista_iterador_elemento_actual(iterador);
	     lista_iterador_tiene_siguiente(iterador);
	     lista_iterador_avanzar(iterador)) {
		void *actual = lista_iterador_elemento_actual(iterador);
		contador++;
		if (actual == elemento)
			return contador;
	}
	return contador;
}

void pruebas_con_iterador()
{
	pa2m_nuevo_grupo("iterador externo invalido");
	lista_iterador_t *iterador_null = lista_iterador_crear(NULL);
	pa2m_afirmar(iterador_null == NULL,
		     "iterador creado con lista invalida es NULL");
	pa2m_afirmar(lista_iterador_elemento_actual(iterador_null) == NULL,
		     "elemento corriente es NULL");
	pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador_null),
		     "Iterador no tiene siguiente");
	pa2m_afirmar(!lista_iterador_avanzar(iterador_null),
		     "Iterador no puede avanzar");
	lista_iterador_destruir(iterador_null);

	pa2m_nuevo_grupo("iterador externo valido");

	lista_t *lista = lista_crear();
	llenar_lista(lista);
	lista_iterador_t *iterador = lista_iterador_crear(lista);
	pa2m_afirmar(iterador != NULL, "iterador creado con lista valida");
	pa2m_afirmar(lista_iterador_elemento_actual(iterador) ==
			     lista_primero(lista),
		     "elemento corriente iterador es el 1º de la lista");
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador),
		     "iterador corriente tiene siguiente");
	pa2m_afirmar(lista_iterador_avanzar(iterador),
		     "iterador corriente avanzo");
	pa2m_afirmar(lista_iterador_elemento_actual(iterador) ==
			     lista_elemento_en_posicion(lista, 1),
		     "nuevo elemento corriente es el correcto");

	lista_iterador_destruir(iterador);
	lista_iterador_t *iterador2 = lista_iterador_crear(lista);

	pa2m_afirmar(buscando_elemento(iterador2, lista_primero(lista)) == 1,
		     "se itero un elemento");
	pa2m_afirmar(buscando_elemento(iterador2, lista_elemento_en_posicion(
							  lista, 1)) == 2,
		     "se iteraron dos elementos");
	pa2m_afirmar(buscando_elemento(iterador2, lista_ultimo(lista)) == 3,
		     "se iteraron tres elementos");

	lista_iterador_destruir(iterador2);
	lista_iterador_t *iterador3 = lista_iterador_crear(lista);

	pa2m_afirmar(buscando_elemento(iterador3, lista_ultimo(lista)) == 4,
		     "se iteraron todos los elementos");

	lista_iterador_destruir(iterador3);
	lista_destruir(lista);
}

void pruebas_iterador_interno()
{
	lista_t *lista = lista_crear();
	size_t iterados = lista_con_cada_elemento(lista, son_iguales,
						  lista_primero(lista));
	pa2m_afirmar(iterados == 0, "no se itera una lista vacia");
	llenar_lista(lista);
	iterados = lista_con_cada_elemento(lista, son_iguales,
					   lista_primero(lista));
	pa2m_afirmar(iterados == 1, "se itero un elemento");
	iterados = lista_con_cada_elemento(
		lista, son_iguales, lista_elemento_en_posicion(lista, 1));
	pa2m_afirmar(iterados == 2, "se iteraron dos elementos");
	iterados = lista_con_cada_elemento(
		lista, son_iguales, lista_elemento_en_posicion(lista, 2));
	pa2m_afirmar(iterados == 3, "se iteraron tres elementos");
	iterados = lista_con_cada_elemento(lista, son_iguales, NULL);
	pa2m_afirmar(iterados == 4, "se iteraron todos los elementos");
	iterados = lista_con_cada_elemento(NULL, son_iguales,
					   lista_primero(lista));
	pa2m_afirmar(iterados == 0, "si la lista es NULL no itera");
	iterados = lista_con_cada_elemento(lista, NULL, lista_primero(lista));
	pa2m_afirmar(iterados == 0, "funcion NULL no itera");
	lista_destruir(lista);
}

void pruebas_pila()
{
	pila_t *pila = pila_crear();
	pa2m_afirmar(pila != NULL, "pila creada distinta de NULL");
	pa2m_afirmar(pila_vacia(pila), "pila vacia esta vacia");
	pa2m_afirmar(pila_tope(pila) == NULL, "pila vacia su tope es NULL");
	pa2m_afirmar(pila_tamanio(pila) == 0, "pila vacia su tamaño es 0");

	pa2m_afirmar(pila_apilar(pila, NULL) != NULL, "apilo elemento NULL");
	pa2m_afirmar(!pila_vacia(pila),
		     "con elemento nulo pila no vacia esta vacia");
	pa2m_afirmar(pila_tope(pila) == NULL, "tope de pila es correcto");
	pa2m_afirmar(pila_tamanio(pila) == 1, "el tamaño de la pila es 1");

	pa2m_afirmar(pila_apilar(pila, (void *)10) != NULL, "apilo elemento");
	pa2m_afirmar(!pila_vacia(pila), "la pila no esta vacia");
	pa2m_afirmar(pila_tope(pila) == (void *)10, "tope de pila es correcto");
	pa2m_afirmar(pila_tamanio(pila) == 2, "el tamaño de la pila es 2");

	pa2m_afirmar(pila_desapilar(pila) == (void *)10,
		     "desapila un elemento y lo devuelve");
	pa2m_afirmar(pila_desapilar(pila) == NULL,
		     "desapila otro elemento y lo devuelve");

	pa2m_afirmar(pila_vacia(pila), "pila desapilada esta vacia");
	pa2m_afirmar(pila_tope(pila) == NULL,
		     "pila desapilada su tope es NULL");
	pa2m_afirmar(pila_tamanio(pila) == 0, "pila desapilada su tamaño es 0");

	pila_destruir(pila);
}

void pruebas_cola()
{
	cola_t *cola = cola_crear();
	pa2m_afirmar(cola_vacia(cola), "cola creada esta vacia");
	pa2m_afirmar(cola_frente(cola) == NULL, "cola vacia tiene frente NULL");
	pa2m_afirmar(cola_frente(cola) == NULL, "cola vacia tiene frente NULL");
	pa2m_afirmar(cola_tamanio(cola) == 0, "cola vacia tiene tamaño 0");

	pa2m_afirmar(cola_encolar(cola, NULL) != NULL, "encolo elemento nulo");
	pa2m_afirmar(cola_frente(cola) == NULL,
		     "el frente de la cola es correcto");
	pa2m_afirmar(cola_tamanio(cola) == 1, "tamaño de cola es 1");
	pa2m_afirmar(!cola_vacia(cola), "la cola no esta vacia");

	pa2m_afirmar(cola_encolar(cola, (void *)"string") != NULL,
		     "encolo elemento");
	pa2m_afirmar(cola_frente(cola) == NULL,
		     "el frente de la cola es correcto");
	pa2m_afirmar(cola_tamanio(cola) == 2, "tamaño de cola es 2");

	pa2m_afirmar(cola_desencolar(cola) == NULL, "desencolo elemento");
	pa2m_afirmar(cola_desencolar(cola) == (void *)"string",
		     "desencolo otro elemento y lo devuelvo");

	pa2m_afirmar(cola_vacia(cola), "cola desencolada esta vacia");
	pa2m_afirmar(cola_tamanio(cola) == 0, "cola desencolada tamaño 0");
	pa2m_afirmar(cola_frente(cola) == NULL,
		     "el frente de cola es correcto");

	cola_destruir(cola);
}

int main()
{
	pa2m_nuevo_grupo("pruebas lista");
	pruebas_con_lista_nula();
	pruebas_con_lista();
	pa2m_nuevo_grupo("pruebas iterador externo");
	pruebas_con_iterador();
	pa2m_nuevo_grupo("pruebas iterador interno");
	pruebas_iterador_interno();
	pa2m_nuevo_grupo("pruebas pila");
	pruebas_pila();
	pa2m_nuevo_grupo("pruebas cola");
	pruebas_cola();
	return pa2m_mostrar_reporte();
}
