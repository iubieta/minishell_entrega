# Parseo:

## Fuentes:
 - [Explicacion minishell](https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218)
 - [Algoritmo de agrupacion - Precedence climbing](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing)
 - [Formatos de ordenacion de arboles binarios](https://www.geeksforgeeks.org/introduction-to-binary-tree/)

## Prioridad de las operaciones:

1. Parentesis (?? Hay que contemplarlos)
2. Pipes
3. Here-doc (<<)
4. Redir IN (<)
5. Redir OUT (>) y Redir APPEND (>>)

## Algoritmo : Precedence Climbing
Busca agrupar operaciones en funcion de su orden de prioridad, determinando asi los niveles de cada operacion y el orden en el que deben ejecutarse.

a + b * c - d / e -> a + (b * c) - (d / e)

Debe tener en cuenta las propiedades asociativas.

### Funcionamiento
Los nodos son operaciones o argumentos. Cualquier operacion consta de al menos dos argumentos. 

El algoritmo se basa en una funcion recursiva que profundiza a medida que encuentra operaciones de mayor prioridad que el nivel en el que se encuentra. Si estamos intentando resolver una suma (operacion de nivel 1) y nos encontramos una multiplicacion (operacion de nivel 2) profundizara un nivel mas llamandose a si misma con los argumentos que acompañan a la multiplicacion. De esta forma se van resolviendo las operaciones mas prioritarias antes de seguir con las de menor nivel.

## Opciones de resultado de parseo:

1. Resolver las operaciones a medida que se navega el arbol.
2. Navegar el arbol y reordenarlo en forma de linked list.

# Variables de entorno

export:
- Si getenv() NO es NULL: hacer free al *p devueldo, luego strdup con el nuevo valor y *p = valor_nuevo
- Si getenv() es NULL: ir al final de **environ, y appenderar el nuevo *p con valor_nuevo. Acordarse de poner un puntero null al final
  - se necesita extender el tamano de el **environ

se detecta la necesidad de crear una varialbe nueva que contenga las varibles definidas en la minishell.
- Esta variable "localenv" se inicializara al principio de la minishell con el contenido de exter char **environ.
- Cada vez que se introduzca un comando de tipo definir variable, se appendeara un nuevo valor a esta variable "localenv"
- cuando se llame a export cojeremos la variable definida en "localenv" y la appendearemos al extern char *environ
- SIEMPRE vamos a trabajar sobre "localenv".

# Cosas que no funcionan

- Comillas: hace cosas raras con las primeras y ultimas letras
- Exit:
	- Falta el builtin
	- A veces cuando ejecutas varios comandos hay que hacer varios exits (ctrl+D) para cerrar la shell
- Leaks:
	- 
- Historial: no se si deberia funcionar con teclas o con ctrl+r. De momento creo que existe el historial pero no es funcional.
- Redirecciones
- Ejecucion con ruta absoluta : /bin/ls
- Valores de retorno: $?
- Ctrl-C
- Ctrl-\
- Comandos sin sentido