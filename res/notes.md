# Parseo:

## Fuentes:
 - https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218
 - https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing

## Algoritmo : Precedence Climbing
Busca agrupar operaciones en funcion de su orden de prioridad, determinando asi los niveles de cada operacion y el orden en el que deben ejecutarse.

a + b * c - d / e -> a + (b * c) - (d / e)

Debe tener en cuenta las propiedades asociativas.

### Funcionamiento
Los nodos son operaciones o argumentos. Cualquier operacion consta de al menos dos argumentos. 

El algoritmo se basa en una funcion recursiva que profundiza a medida que encuentra operaciones de mayor prioridad que el nivel en el que se encuentra. Si estamos intentando resolver una suma (operacion de nivel 1) y nos encontramos una multiplicacion (operacion de nivel 2) profundizara un nivel mas llamandose a si misma con los argumentos que acompañan a la multiplicacion. De esta forma se van resolviendo las operaciones mas prioritarias antes de seguir con las de menor nivel.
