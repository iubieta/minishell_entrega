#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../inc/libft/libft.h"

// EUREKA
//
// NO Olvidar truncar entre redireccones para cargarse cada archivo

int main (int argc, char **argv, char **env)
{
    int fda;
    int fdb;
    char **c;

    c = ft_split(strdup("cat"), ' ');
    fda = open("a", O_RDONLY);
    fdb = open("b", O_RDONLY);
    dup2(fda, STDIN_FILENO);
    close(fda);
    execve("/bin/cat", c, env);
}
