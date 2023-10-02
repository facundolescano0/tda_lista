# TDA lista

## Repositorio de Facundo Lescano - 110784 - flescano@fi.uba.ar

- Para compilar:

```bash
make pruebas_chanutron
```

- Para ejecutar:

```bash

```

- Para ejecutar con valgrind:
```bash
valgrind ./pruebas_chanutron
```
---
##  Funcionamiento
En este programa se implemento un TDA lista, usando nodos simplemente enlazadas. La lista refiere a una cantidad, un nodo simplemente enlazado al nodo inicio y otro al nodo final. Este TDA fue reutilizado en la implementacion de Cola y Pila a traves de unos casteos. 
En esta implementacion se crea una lista reservando memoria para ocupar la estructura lista y antes de insertar cada nodo a la lista se reseravaba memoria previamente. Para los casos de insertar en ultima posicion se usaba la referencia directa gracias al facil acceso y se modificaba los punteros del inicio de la lista. En otros casos como insertar en posicion, buscar elemento en posicion o quitar de posicion se debe iterar hasta encontrar el elemento, guardando en una variable auxiliar para luego tener acceso al elemento encontrado. Se creo un iterador interno y otro externo. El primero con opcion de que el user ponga una condicion de corte y el segundo totalmente externo, con unas opareciones que le permitan iterar, como iterador_tiene_siguiente, avanzar y elemento corriente, y una estructura especifica para poder guardar la lista a iterar y el elemento que se esta iterando.

Abstraccion de la memoria usada por lista:
![](https://github.com/facundolescano0/tda_lista/blob/entrega/diagramas_tda/Lista_memoria.jpeg)

Tanto pila como cola fueron implementados con la reutilizacion de operaciones de lista. Usando casteos para modificar el tipo de dato.
Abstraccion de la memoria usada por cola:
![](https://github.com/facundolescano0/tda_lista/blob/entrega/diagramas_tda/Cola_memoria.jpeg)
Abstraccion de la memoria usada por pila:
![](https://github.com/facundolescano0/tda_lista/blob/entrega/diagramas_tda/Pila_memoria.jpeg)


## Respuestas a las preguntas teóricas
Tanto lista, como pila y cola son TDAs. Los TDAs son tipos de datos abstractos que estan definidos por el conjunto de todos los valores posibles que pueden contener y las operaciones que pueden utilizar.
La lista agrupa elementos los cuales cada uno de ellos tienen predecesor y sucesor (excepto en casos bases). En este caso se utilizo una lista simplemente enlazada en la cual esta conectada por "nodos simples"(tipo de dato el cual contiene un elemento y un puntero al siguiente elemento). Donde cada nodo apunta al siguiente y la lista se refiere al primer nodo, al final y una cantidad de elementos.
![](https://github.com/facundolescano0/tda_lista/blob/entrega/diagramas_tda/Lista_teorico.jpeg)
La pila agrupa elementos de forma LIFO, basada en que lo ultimo que entra es lo primero en salir.
![](https://github.com/facundolescano0/tda_lista/blob/entrega/diagramas_tda/Pila_teorico.jpeg)
La cola, al igual que los anteriores TDAs agrupa elementos de forma FIFO. Es decir, lo primero que entra es lo primero que sale.
![](https://github.com/facundolescano0/tda_lista/blob/entrega/diagramas_tda/Cola_teorico.jpeg)
Cabe aclarar que lo llamado agrupar elementos en esta implementacion son nodos simplemente enlazados los cuales contienen un elemento y un puntero al siguiente nodo(o a NULL).

lista simplemente enlazada, doblemente enlazada y vector dinámico para las operaciones:
   - Insertar/obtener/eliminar al inicio
la complejidad para estos casos seran las siguientes : al insertar al inicio en los casos de lista enlazada y doblemente enlazada sera o(1) debido a que para realizar esta operacion deberar el unico movimiento que se debera realizar es un cambio de direccion en punteros. En cambio, en vector dinamico, se debera mover todos los elementos un lugar y agregar al nuevo, es decir su cumplejidad sera O(n). La mayor diferencia entre ellas es esta ultima. 
Para el caso de obtener, todas seran O(1) ya que tienen facil acceso a la primer posicion.
Para el caso de eliminar, tendremos una situacion similar a insertar. Para las listas enlazadas se debera crear un auxiliar para guardar el elemento a borrar y un reajuste de punteros. En cambio, para vector dinamico se debera reajustar todos los elementos una posicion anterior luego de borrar inicio. sera O(N).

lista simplemente enlazada, doblemente enlazada y vector dinámico para las operaciones:
   - Insertar/obtener/eliminar al final
Para insertar al final en una lista simplemente enlazada y doblemente enlazada, al tener una referencia al ultimo nodo, la complejidad sera O(1). Solo se debera hacer un cambio de punteros. Para un vector dinamico se debera insertar el elemento y modificar el tope. Tambien sera O(1).
Obtener al final tambien sera O(1) en los tres casos ya que tienen acesso directo al ulitmo elemento.
eliminar al final, nuevamente, se debera acomodar los punteros en las listas y en el VD se debera eliminar elemento y modificar tope. La complejidad sera O(1)

lista simplemente enlazada, doblemente enlazada y vector dinámico para las operaciones:
   - Insertar/obtener/eliminar al medio
En estos casos sera mas laboroso para las listas debido a que solo tienen acesso directo al principio y al final. 
Insertar en el medio, para el vector dinamico, su complejidad estara dada por el acomodamiento de elementos por el espacio dejado aunque eliminar no le sera de gran complejidad. sera O(n).
Para las listas, se debera recorrer los nodos guardando nodo por nodo en un auxliar hasta encontrar la mitad y con un reajuste de punteros se realiza la inserccion. Para las listas tambien sera O(n).
Para obtener elemento, en el caso de VD sera O(1) ya que tiene facil acceso a cualquier posicion. En cambio, para las listas, sera igual de trabajo que insertar y eliminar. Debera recorrer nodo por nodo e ir guardando los datos en una variable auxilar. Para las listas la complejidad sera O(n).
Por ultimo, elminar en el medio. Sera similiar a insertar. La labor del VD sera reajustar los elementos y la de las listas sera recorrer nodos hasta encontrar la mitad. Para los tres TDAs sera o(n).
Cabe destacar que la principal diferencia entre la complejidad de lista simplemente enlazada y doblemente enlazada sera unicamente en el reacomodamiento de punteros. Aunque a la larga esto no hara mucha diferencia (si se van a infito las iteraciones), la complejidad de esta ultima sera el doble ya que al estar doblemente enlazada tiene que reacomodar lo mismo que la simple duplicado dos veces.


Complejidad de las operaciones implementadas para la pila y la cola.
Las complejidades de las operaciones tanto de pila como de cola seran todas O(1).
Para encolar y desencolar se realiza un reajuste de punteros. Para cola_tamanio y cola_vacia se chequea la cantidad de elementos que hay y para devolver el frente se utiliza la refencia al inicio de la cola.
Para la pila, apilar y desapilar se realiza un ajuste de punteros de nodos tambien. Para el tamaño y chequear si esta vacia se mira la cantidad de elementos y para conocer el tope se hace accede al puntero final de la pila.
Para la DESTRUCCION, tanto de pila de cola, se recorreran todos los nodos de cada TDA actual y se usaran auxiliares para no poder los punteros siguientes a cada nodo destruido. La complejidad paa destruir sera de O(n).  
