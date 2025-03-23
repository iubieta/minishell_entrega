<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                                      :::      ::::::::  -->
<!-- eval_sheet.md                                      :+:      :+:    :+:  -->
<!--                                                  +:+ +:+         +:+    -->
<!-- By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+       -->
<!--                                              +#+#+#+#+#+   +#+          -->
<!-- Created: 2025/03/23 17:46:38 by iubieta-          #+#    #+#            -->
<!-- Updated: 2025/03/23 19:53:34 by iubieta-         ###   ########.fr      -->
<!--                                                                         -->
<!-- *********************************************************************** -->

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

### 🔹 Comandos Simples & Variables Globales FUNCIONANDO

- Ejecuta un comando simple con una ruta absoluta (`/bin/ls`).
- Pregunta cuántas variables globales usa el estudiante y por qué.
- Prueba comandos vacíos y entradas solo con espacios o tabs.

> ⚠️ **Errores posibles:**  
> - ❌ `Crash`  
> - ❌ `Trabajo incompleto`

### 🔹 Argumentos FUNCIONANDO

- Ejecuta un comando simple con argumentos sin comillas (`/bin/ls -l`).
- Repite con diferentes combinaciones.

> ⚠️ **Errores posibles:**  
> - ❌ `Crash`  
> - ❌ `Trabajo incompleto`

### 🔹 Comando `echo` FUNCIONANDO

- Ejecuta `echo` con y sin argumentos.
- Prueba con `-n` y varias combinaciones.

### 🔹 Comando `exit` FUNCIONANDO

- Ejecuta `exit` con y sin argumentos.
- Repite varias veces y reinicia `minishell`.

### 🔹 Valor de Retorno (`$?`) FUNCIONANDO

- Ejecuta un comando (`/bin/ls`) y luego `echo $?` para verificar el valor de retorno.
- Prueba con comandos erróneos (`/bin/ls archivo_inexistente`).
- Experimenta con `expr $? + $?`.

### 🔹 Señales (`ctrl-C`, `ctrl-D`, `ctrl-\`) REVISAR

- `ctrl-C` en un prompt vacío debe mostrar una nueva línea con el prompt.
- `ctrl-D` en un prompt vacío debe cerrar `minishell`.
- `ctrl-C` tras escribir debe limpiar el buffer.
- `ctrl-\` en un prompt vacío no debe hacer nada.
- Prueba señales mientras ejecutas comandos bloqueantes (`cat`, `grep`).

### 🔹 Comillas Dobles `"..."` FUNCIONANDO

- Ejecuta comandos con argumentos en comillas dobles (ej. `echo "Hola mundo"`).
- Prueba `echo "cat lol.c | cat > lol.c"`.

### 🔹 Comillas Simples `'...'` FUNCIONANDO

- Prueba comandos con comillas simples.
- `echo '$USER'` debe imprimir `"$USER"` sin expandirlo.

### 🔹 Comando `env` FUNCIONANDO

- Verifica que `env` muestra las variables de entorno.

### 🔹 Comando `export` REVISAR : PARCHE para juntar comillas despues del igual

- Crea y reemplaza variables de entorno con `export`.
- Verifica los cambios con `env`.

### 🔹 Comando `unset` FUNCIONANDO

- Usa `unset` para eliminar variables de entorno.
- Verifica los cambios con `env`.

### 🔹 Comando `cd` FUNCIONANDO

- Usa `cd` para cambiar de directorio y verifica con `/bin/ls`.
- Prueba con `.` y `..`.

### 🔹 Comando `pwd` FUNCIONANDO

- Ejecuta `pwd` en distintos directorios.

### 🔹 Rutas Relativas REVISAR

- Ejecuta comandos con rutas relativas.
- Prueba rutas complejas (`../../bin/ls`). ` FUNCIONA SIEMPRE, no deberia`

### 🔹 Variable `$PATH`

- Ejecuta comandos sin especificar la ruta (`ls`, `wc`, etc.).
- Elimina `$PATH` y verifica que los comandos dejan de funcionar.
- Modifica `$PATH` y verifica el orden de búsqueda.

### 🔹 Redirecciones (`<`, `>`, `>>`, `<<`)

- Prueba redirecciones con diferentes comandos.
- Asegúrate de que `<<` no actualiza el historial.

### 🔹 Pipes (`|`) FUNCIONANDO

- Ejecuta comandos con pipes (`cat file | grep bla | more`).
- Prueba combinaciones incorrectas (`ls archivo_inexistente | grep bla`).
- Mezcla pipes con redirecciones.

### 🔹 Comportamiento General REVISAR

- Escribe un comando y usa `ctrl-C`. El buffer debe estar limpio.
- Usa las teclas `↑` y `↓` para navegar en el historial.
- Asegúrate de que `minishell` no crashea con comandos inválidos (`dsbksdgbksdghsd`).
- Prueba una línea de comandos muy larga.

### 🔹 Variables de Entorno REVISAR: las comillas dobles deberian expandir $

- Ejecuta `echo $VARIABLE`.
- Verifica que `$` es interpretado correctamente.
- Asegúrate de que `echo "$USER"` imprime el valor de la variable.

---

## ⭐ Tests Opcionales (Bonus)

### 🔹 `&&`, `||` y Paréntesis

- Prueba operadores lógicos (`ls && echo "ok"`, `false || echo "error"`).
- Asegura que el comportamiento sea como en Bash.

### 🔹 Wildcards (`*`)

- Usa `*` para listar archivos (`ls *.c`).

### 🔹 Expansión de Variables

- `echo "'$USER'"` debe imprimir el valor de `USER`.
- `echo '"$USER"'` debe imprimir `"$USER"`.

---

## 🔍 Evaluación Final

- Si el trabajo está completo, evalúa la sección de bonus.
- Si el proyecto tiene errores graves, marca las banderas correspondientes:

  | Código | Descripción |
  |--------|------------|
  | ✅ `Ok` | Proyecto aprobado |
  | 🌟 `Outstanding` | Proyecto excepcional |
  | ❌ `Empty work` | Repositorio vacío |
  | ⚠️ `Incomplete` | Trabajo incompleto |
  | 🛑 `Invalid compilation` | Error de compilación |
  | 🚫 `Norme` | No sigue la Norme |
  | 💀 `Crash` | Programa crashea |
  | ❓ `Incomplete group` | Grupo incompleto |
  | ⚠️ `Leaks` | Fugas de memoria |
  | ⛔ `Forbidden function` | Uso de funciones prohibidas |

---
