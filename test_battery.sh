echo -- TEST 1 : Comandos simple --

echo 
echo bash: /bin/ls
bash -c "/bin/ls"
echo mini: /bin/ls
./minishell /bin/ls

echo 
echo -- TEST 2 : Comandos con argumentos --

echo 
echo bash: /bin/ls -l
bash -c "/bin/ls -l"
echo mini: /bin/ls -l 
./minishell /bin/ls -l

echo
echo bash: /bin/ls -a
bash -c "/bin/ls -a"
echo mini: /bin/ls -a
./minishell /bin/ls -a

echo 
echo -- TEST 3 : echo --

echo
echo bash: echo
bash -c "echo"
echo mini: echo
./minishell echo

echo
echo bash: echo Hola mundo
bash -c "echo Hola mundo"
echo mini: echo Hola mundo
./minishell echo Hola mundo

echo
echo bash: echo -n
bash -c "echo -n"
echo mini: echo -n
./minishell echo -n

echo
echo bash: echo -n Hola mundo
bash -c "echo -n Hola mundo"
echo mini: echo -n Hola mundo
./minishell echo -n Hola mundo

echo "\n"
echo '-- TEST 4 : $? (Comprobar en modo interactivo tambien) --'

echo 
echo 'bash: /bin/ls; echo $?'
/bin/ls
bash -c "echo $?"
echo 'mini: /bin/ls; echo $?'
/bin/ls
./minishell echo $?

echo 
echo 'bash: /bin/ls archivo_inexistente; echo $?'
/bin/ls archivo_inexistente
bash -c "echo $?"
echo 'mini: /bin/ls; echo $?'
/bin/ls archivo_inexistente
./minishell echo $?

echo 
echo 'bash: /bin/ls; expr $? + $?'
/bin/ls
bash -c "expr $? + $?"
echo 'mini: /bin/ls; expr $? + $?'
/bin/ls
./minishell expr $? + $?

echo 
echo 'bash: /bin/ls archivo_inexistente; expr $? + $?'
/bin/ls archivo_inexistente
bash -c "expr $? + $?"
echo 'mini: /bin/ls; expr $? + $?'
/bin/ls archivo_inexistente
./minishell expr $? + $?

echo 
echo -- TEST 5 : echo "" --

echo "REVISAR: EL PIPE CORTA LA CADENA ENTRECOMILLADA"
# echo
# echo bash: echo "Hola mundo"
# bash -c echo "Hola mundo"
# echo mini: echo "Hola mundo"
# ./minishell echo "Hola mundo"
#
# echo
# echo bash: echo -n "Hola mundo"
# bash -c echo -n "Hola mundo"
# echo mini: echo -n "Hola mundo"
# ./minishell echo -n "Hola mundo"
#
# echo
# echo bash: echo "cat Makefile | wc -l"
# bash -c echo "cat Makefile | wc -l"
# echo mini: echo "cat Makefile | wc -l"
# ./minishell echo "cat Makefile | wc -l"
#
# echo
# echo bash: echo -n "cat Makefile | wc -l"
# bash -c echo -n "cat Makefile | wc -l"
# echo mini: echo -n "cat Makefile | wc -l"
# ./minishell echo -n "cat Makefile | wc -l"

echo 
echo -- TEST 6 : echo '' --

echo
echo "bash: echo \$USER"
bash -c "echo \$USER"
echo "mini: echo \$USER"
./minishell "echo \$USER"

echo
echo "bash: echo '\$USER'"
bash -c "echo '\$USER'"
echo "mini: echo '\$USER'"
./minishell "echo '\$USER'"

echo
echo "bash: echo \"\$USER\""
bash -c "echo \"\$USER\""
echo "mini: echo \"\$USER\""
./minishell "echo \"\$USER\""

echo 
echo -- TEST 7 : env --

echo
echo 'bash: env'
bash -c "env"
echo 'mini: env'
./minishell env

echo 
echo -- TEST 8 : export (REVISAR) --
## Export deberia exportar la variable a la shell de origen?

echo
echo 'bash: export HOLA="hola bash"'
bash -c 'export HOLA="hola bash"'
bash -c "'echo $HOLA'"
echo 'mini: export HOLA="hola mini"'
./minishell export HOLA="hola mini"
./minishell 'echo $HOLA'

echo
echo 'bash: export HOLA="hola otra vez bash"'
bash -c 'export HOLA="hola otra vez bash"'
bash -c "'echo $HOLA'"
echo 'mini: export HOLA="hola otra vez mini"'
./minishell export HOLA="hola otra vez mini"
./minishell 'echo $HOLA'

echo 
echo "-- TEST 8 : unset (REVISAR) --"

echo
echo 'bash: unset HOLA'
bash -c 'HOLA="hola bash"'
bash -c "echo HOLA = $HOLA"
bash -c "unset HOLA"
bash -c "echo HOLA = $HOLA"
echo 'mini: unset HOLA'
./minishell HOLA="hola mini"
./minishell echo 'HOLA = $HOLA'
./minishell unset HOLA
./minishell echo 'HOLA = $HOLA'


echo 
echo "-- TEST 9 : cd, pwd --"

echo
echo 'bash: pwd, cd, pwd'
bash -c "pwd"
bash -c "cd .."
bash -c "pwd"
echo 'mini: pwd, cd, pwd '
./minishell pwd
./minishell cd ..
./minishell pwd
