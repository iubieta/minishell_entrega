#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "../inc/libft/libft.h"

// EUREKA
//
// NO Olvidar truncar entre redireccones para cargarse cada archivovoid

int main (int argc, char **argv, char **env)
{
    int fda;
    int fdb;
    char **c;
    pid_t pid;

    c = ft_split(strdup("cat"), ' ');
    fda = open("a", O_APPEND | O_WRONLY | O_CREAT, 0777);
    if (fda == -1)
        perror("open");
    fdb = open("b", O_RDONLY);
    if (dup2(fdb, STDIN_FILENO) == -1)
        perror("dup2");
    if (dup2(fda, STDOUT_FILENO) == -1)
        perror("dup2");
    pid = fork();
    if (pid == -1)
        perror("fork");
    close(fdb);
    close(fda);
    if (pid == 0)
        execve("/bin/cat", c, env);
    wait(NULL);
}
