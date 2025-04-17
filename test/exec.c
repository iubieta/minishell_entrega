#include "../inc/libft/libft.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_cmd
{
    char *s;
    char **a;
    char **e;
} t_cmd;

int main (int argc, char **argv, char **env)
{
    int fdsi;
    int fd1;
    int fd2;

    t_cmd *c1;
    t_cmd *c2;
    t_cmd *c3;

    pid_t pid;

    c1->s = strdup("ls");
    c2->s = strdup("cat");
    c3->s = strdup("wc");

    c1->a = ft_split("ls", ' ');
    c2->a = ft_split("cat", ' ');
    c3->a = ft_split("wc -l", ' ');

    c1->e = env;
    c2->e = env;
    c3->e = env;

    fdsi = dup(STDIN_FILENO);

    pid = fork();
    if (pid == -1)
        return(1);
    if (pid == 0)
        ft_child()
    fd1 = open("Makefile", O_RDONLY);
    dup2(fd1, STDIN_FILENO);



}
