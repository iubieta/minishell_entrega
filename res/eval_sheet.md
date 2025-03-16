# Minishell Evaluation Tests

## 📌 Introducción

- Asegúrate de que no hay alias maliciosos para engañar la evaluación.
- Si el proyecto contiene errores graves o trampas, usa las banderas apropiadas.
- **No se permiten fallos de segmentación ni terminaciones inesperadas.**
- Verifica la ausencia de fugas de memoria con herramientas como `leaks`, `valgrind` o `e_fence`.

---

## ✅ Tests Obligatorios

### 🔹 Compilación

- Usa `make -n` para verificar el uso de `-Wall -Wextra -Werror`.
- Asegúrate de que `minishell` compila sin errores.
- El `Makefile` no debe relinkear.

### 🔹 Comandos Simples & Variables Globales

- Ejecuta un comando simple con una ruta absoluta (`/bin/ls`).
- Pregunta cuántas variables globales usa el estudiante y por qué.
- Prueba comandos vacíos y entradas solo con espacios o tabs.

> ⚠️ **Errores posibles:**  
> - ❌ `Crash`  
> - ❌ `Trabajo incompleto`

### 🔹 Argumentos

- Ejecuta un comando simple con argumentos sin comillas (`/bin/ls -l`).
- Repite con diferentes combinaciones.

> ⚠️ **Errores posibles:**  
> - ❌ `Crash`  
> - ❌ `Trabajo incompleto`

### 🔹 Comando `echo`

- Ejecuta `echo` con y sin argumentos.
- Prueba con `-n` y varias combinaciones.

### 🔹 Comando `exit`

- Ejecuta `exit` con y sin argumentos.
- Repite varias veces y reinicia `minishell`.

### 🔹 Valor de Retorno (`$?`)

- Ejecuta un comando (`/bin/ls`) y luego `echo $?` para verificar el valor de retorno.
- Prueba con comandos erróneos (`/bin/ls archivo_inexistente`).
- Experimenta con `expr $? + $?`.

### 🔹 Señales (`ctrl-C`, `ctrl-D`, `ctrl-\`)

- `ctrl-C` en un prompt vacío debe mostrar una nueva línea con el prompt.
- `ctrl-D` en un prompt vacío debe cerrar `minishell`.
- `ctrl-C` tras escribir debe limpiar el buffer.
- `ctrl-\` en un prompt vacío no debe hacer nada.
- Prueba señales mientras ejecutas comandos bloqueantes (`cat`, `grep`).

### 🔹 Comillas Dobles `"..."`

- Ejecuta comandos con argumentos en comillas dobles (ej. `echo "Hola mundo"`).
- Prueba `echo "cat lol.c | cat > lol.c"`.

### 🔹 Comillas Simples `'...'`

- Prueba comandos con comillas simples.
- `echo '$USER'` debe imprimir `"$USER"` sin expandirlo.

### 🔹 Comando `env`

- Verifica que `env` muestra las variables de entorno.

### 🔹 Comando `export`

- Crea y reemplaza variables de entorno con `export`.
- Verifica los cambios con `env`.

### 🔹 Comando `unset`

- Usa `unset` para eliminar variables de entorno.
- Verifica los cambios con `env`.

### 🔹 Comando `cd`

- Usa `cd` para cambiar de directorio y verifica con `/bin/ls`.
- Prueba con `.` y `..`.

### 🔹 Comando `pwd`

- Ejecuta `pwd` en distintos directorios.

### 🔹 Rutas Relativas

- Ejecuta comandos con rutas relativas.
- Prueba rutas complejas (`../../bin/ls`).

### 🔹 Variable `$PATH`

- Ejecuta comandos sin especificar la ruta (`ls`, `wc`, etc.).
- Elimina `$

