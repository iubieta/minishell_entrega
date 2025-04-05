echo -- TEST 1 : Comandos simple --

echo 
echo bash: /bin/ls
bash /bin/ls
echo mini: /bin/ls
./minishell /bin/ls

echo 
echo -- TEST 2 : Comandos con argumentos --

echo 
echo bash: /bin/ls -l
bash /bin/ls -l
echo mini: /bin/ls -l ./minishell /bin/ls -l

echo
echo bash: /bin/ls -a
bash /bin/ls -a
echo mini: /bin/ls -a
./minishell /bin/ls -a

echo 
echo -- TEST 3 : echo --

echo
echo bash: echo
bash echo
echo mini: echo
./minishell echo

echo
echo bash: echo Hola mundo
bash echo Hola mundo
echo mini: echo Hola mundo
./minishell echo Hola mundo

echo
echo bash: echo -n
bash echo -n
echo mini: echo -n
./minishell echo -n

echo
echo bash: echo -n Hola mundo
bash echo -n Hola mundo
echo mini: echo -n Hola mundo
./minishell echo -n Hola mundo

echo "\n"
echo '-- TEST 4 : $? (Comprobar en modo interactivo tambien) --'

echo 
echo 'bash: /bin/ls; echo $?'
/bin/ls
bash echo $?
echo 'mini: /bin/ls; echo $?'
/bin/ls
./minishell echo $?

echo 
echo 'bash: /bin/ls archivo_inexistente; echo $?'
/bin/ls archivo_inexistente
bash echo $?
echo 'mini: /bin/ls; echo $?'
/bin/ls archivo_inexistente
./minishell echo $?

echo 
echo 'bash: /bin/ls; expr $? + $?'
/bin/ls
bash expr $? + $?
echo 'mini: /bin/ls; expr $? + $?'
/bin/ls
./minishell expr $? + $?

echo 
echo 'bash: /bin/ls archivo_inexistente; expr $? + $?'
/bin/ls archivo_inexistente
bash expr $? + $?
echo 'mini: /bin/ls; expr $? + $?'
/bin/ls archivo_inexistente
./minishell expr $? + $?

echo 
echo -- TEST 5 : echo "" --

echo "REVISAR: EL PIPE CORTA LA CADENA ENTRECOMILLADA"
# echo
# echo bash: echo "Hola mundo"
# bash echo "Hola mundo"
# echo mini: echo "Hola mundo"
# ./minishell echo "Hola mundo"
#
# echo
# echo bash: echo -n "Hola mundo"
# bash echo -n "Hola mundo"
# echo mini: echo -n "Hola mundo"
# ./minishell echo -n "Hola mundo"
#
# echo
# echo bash: echo "cat Makefile | wc -l"
# bash echo "cat Makefile | wc -l"
# echo mini: echo "cat Makefile | wc -l"
# ./minishell echo "cat Makefile | wc -l"
#
# echo
# echo bash: echo -n "cat Makefile | wc -l"
# bash echo -n "cat Makefile | wc -l"
# echo mini: echo -n "cat Makefile | wc -l"
# ./minishell echo -n "cat Makefile | wc -l"

echo 
echo -- TEST 6 : echo '' --

echo
echo 'bash: echo $USER'
bash echo $USER
echo 'mini: echo $USER'
./minishell echo $USER

# REVISAR : expandiendo variable
echo
echo 'bash: echo `$USER`'
bash echo '$USER'
echo 'mini: echo `$USER`'
./minishell echo '$USER'

echo
echo 'bash: echo "$USER"'
bash echo "$USER"
echo 'mini: echo "$USER"'
./minishell echo "$USER"

