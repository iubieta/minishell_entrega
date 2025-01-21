#include "minishell.h"

/* void addcat(t_tree *t) */
/* { */
/*     int i; */
/*     char **ptr; */
/*     char **tmp; */

/*     tmp = t->args; */
/*     i = 0; */
/*     while (ptr[i] != NULL) */
/*         i++; */
/*     ptr = ft_calloc(i + 2, sizeof(char *)); */
/*     *ptr = ft_strdup("cat"); */
/*     i = 0; */
/*     while (tmp[i]) */
/*     { */
/*         ptr[i + 1] = tmp[i]; */
/*         i++; */
/*     } */
/*     ft_free2parray(tmp); */
/*     t->args = ptr; */
/*     return ; */
/* } */

/* void ft_leftredir(t_tree *t, t_md *md) */
/* { */
/*     t_tree *node; */
/*     char *cmd; */

void ft_cleanup(t_md *metad)
{
    ft_freetree(metad->tree);
    free(metad->fd[0]);
    free(metad->fd);
    ft_free2parray(metad->env[0]);
    free(metad);
    metad = NULL;
}

>>>>>>> f57c047 (asdf)
void ft_childproc(t_md *md)
{
    int **fd;
    t_tree *cmd;

    fd = md->fd;
    cmd = md->tree[0];
    if (fd[IPIPE][RDEND] != -1)
    {
        dup2(fd[IPIPE][RDEND], STDIN_FILENO);
        close(fd[IPIPE][RDEND]);
    }
    while (cmd->right->type == TOKEN_REDIR_IN || cmd->right->type == TOKEN_REDIR_HEREDOC)
    {
        return ;
        /* ft_leftredir(md); //esto catearia el archivo y borraria el node de la llist */
    }
    if (cmd->right->type == TOKEN_PIPE)
        dup2(fd[OPIPE][WREND], STDOUT_FILENO);
    if (cmd->right->type == TOKEN_REDIR_OUT)
    {
        return ;
        /* ft_rightredir(md); */
    }
    close(fd[OPIPE][RDEND]);
    execve(cmd->args[0], cmd->args, md->env[0]);
    close(fd[OPIPE][WREND]);
}

void ft_execcmd(t_md *md)
{
    t_tree *cmd;
    pid_t pid;

    cmd = md->tree[0];
    if (cmd->right)
    {
        if (pipe(md->fd[OPIPE]) == -1)
            ft_cleanup(md);
    }
    if ((pid = fork()) == -1)
        ft_cleanup(md);
    if (pid == 0)
        ft_childproc(md);
    md->fd[IPIPE][RDEND] = md->fd[OPIPE][RDEND];
    md->fd[IPIPE][WREND] = md->fd[OPIPE][WREND];
    close(md->fd[IPIPE][WREND]);
    waitpid(pid, NULL, 0);
}

int **initfdarray(void)
{
    int **p;
    int *a;

    p = malloc(2 * sizeof(int *));
    a = malloc(4 * sizeof(int));
    a[0] = -1;
    a[1] = -1;
    a[2] = -1;
    a[3] = -1;
    p[0] = a;
    p[1] = a + 2;
    return (p);
}

void ft_initmetadata(t_token *token)
{

    t_md *md;
    extern char **environ;

    md = malloc(sizeof(t_md));
    md->tree = malloc(sizeof(t_tree));
    printf("flag10: HERE\n");
    *(md->tree) = buildtreestruct(token);
    printf("flag11: HERE\n");
    md->fd = initfdarray();
    printf("flag12: HERE\n");
    md->env = malloc(sizeof(char **));
    *(md->env) = ft_dup2parray(environ); //Queda pendiente crear un funcion que copie el environment
    printf("flag13: HERE\n");
}
>>>>>>> f57c047 (asdf)
