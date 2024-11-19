# minishell
42 project

## Requerimientos del subject

### En caso de duda utilizar **bash** como referencia!

- [ ] **1.** Mostrar una nueva entrada mientras espera el comando nuevo.
- [ ] **2.** Tener una historia funcional.
- [ ] **3.** Buscar y ejecutar el ejecutable correcto (basado en la variable PATH o mediante el uso de rutas relativas o absolutas).
- [ ] **4.** Evita utilizar más de una variable global para indicar la recepción de una señal. (Prohibido utilizar estructuras tipo norm en global).
- [ ] **5.** No interpretar comillas sin cerrar o caracteres especiales no especificados en el enunciado como `\` (barra invertida) o `;` (punto y coma).
- [ ] **6.** Gestionar que la `’` evite que el shell interprete los metacaracteres en la secuencia entrecomillada.
- [ ] **7.** Gestionar que la " evite que el shell interprete los metacaracteres en la secuencia entrecomillada exceptuando $ (signo de dólar).
- [ ] **8.** Implementar redirecciones:
- - `<` debe redirigir el input
- - `>` debe redirigir el output 
- - `<<` debe recibir un delimitador, después leer del input de la fuente actual hasta que una línea que contenga solo el delimitador aparezca. Sin embargo, no necesita actualizar el historial.
- - `>>` debe redirigir el output en modo append.
- [ ] **9.** Implementar pipes.
- [ ] **10.** Gestionar variables de entorno que deberan expandirse a sus valores.
- [ ] **11.** Gestionar `$?`, que deberá expandirse al estado de salida del comando más reciente ejecutado en la pipeline.
- [ ] **12.** Gestionar `ctrl-C` `ctrl-D` `ctrl-\`, que deberán funcionar como en bash
- [ ] **13.** Cuando sea interactivo:
    - `ctrl-C` imprime una nueva entrada en una línea nueva.
    - `ctrl-D` termina la shell.
    - `ctrl-\` no hace nada.
- [ ] **14.** Implementar los siguientes built-ins:
    - `echo` con la opcion `-n`.
    - `cd` solo con una ruta relativa o absoluta.
    - `pwd` sin opciones.
    - `export` sin opciones.
    - `unset` sin opciones.
    - `env` sin opciones ni argumentos.
    - `exit` sin opciones.
    

## Funciones autorizadas

|   |   |   |   |   |
|---|---|---|---|---|
| readline | rl_clear_history | rl_on_new_line | rl_replace_line | rl_redisplay | 
| add_history | printf | malloc | free | write | 
| access | open | read | close | fork | 
| wait | waitpid | wait3 | wait4 | signal | 
| sigaction | kill | exit | getcwd | chdir | 
| stat | lstat | fstat | unlink | execve | 
| dup | dup2 | pipe | opendir | readdir | 
| closedir | strerror | perror | isatty | ttyname | 
| ttyslot | ioctl | getenv | tcsetattr | tcgetattr | 
| tgetent | tgetflag | tgetnum | tgetstr | tgoto | 
| tputs | | | | |

## Recursos

### Documentacion
- [readline](https://web.mit.edu/gnu/doc/html/rlman_2.html)
