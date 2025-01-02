# Objetivos
- [ ] Andoitz, tener unos pipes funcionales con redirecciones.
- [ ] Iker, tenere un AST funcional.

# Tareas

## Andoitz
 - [ ] POSPUESTO, HASTA DECIDIR AST vs LList. hacer un algoritmo que navege el tree y vaya ejecutando cada comando. No hace falta que compruebe errores de momento, unicamente que navegue bien. 
 - [ ] Implementar built-ins.
   - [x] echo y echo -n
   - [x] cd
   - [x] pwd
   - [ ] export
   - [ ] unset
   - [ ] env
   - [ ] exit

 - [ ] ...

## Iker
- [x] Tokenizar la entrada
- [x] crear un algoritmo que te cree nodos del AST
- [ ] Navegar el AST para reordenarlo / ejecutarlo en el orden adecuado

# Dudas
- [ ] Preguntar si el prompt de la minishell tiene que esperar a que un comando
  termine de ejecutar y mostrar el output. Si se ha introducido un comando
  mientras estaba esperando se debe ejecutar este a continuacion.
