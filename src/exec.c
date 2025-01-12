#include "minishell.h"

void addcat(t_tree *t)
{
    int i;
    char **ptr;
    char **tmp;

    tmp = t->args;
    i = 0;
    while (ptr[i] != NULL)
        i++;
    ptr = ft_calloc(i + 2, sizeof(char *));
    *ptr = ft_strdup("cat");
    i = 0;
    while (tmp[i])
    {
        ptr[i + 1] = tmp[i];
        i++;
    }
    ft_free2parray(tmp);
    t->args = ptr;
    return ;
}

void ft_leftredir(t_tree *t, t_md *md)
{
    t_tree *node;
    char *cmd;

    addcat(t);
    cmd = t->args[0];
    if (t->right->type == TOKEN_REDIR_IN)
    {
        close(md->fd[OPIPE][RDEND]);
        execve(cmd, t->args, md->env[0]);
        close(md->fd[OPIPE][WREND]);
    }
    if (t->right->type == TOKEN_REDIR_HEREDOC)
        return ;
}

void ft_rightredir(t_tree *t, int fd[2][2], char **env)
{
    return ;
}

void ft_childproc(t_md *md)
{
    int fd_fileout;
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
        ft_leftredir(md); //esto catearia el archivo y borraria el node de la llist
    }
    if (cmd->right->type == TOKEN_PIPE)
        dup2(fd[OPIPE][WREND], STDOUT_FILENO);
    if (cmd->right->type == TOKEN_REDIR_OUT)
    {
        ft_rightredir(md);
    }
    close(fd[OPIPE][RDEND]);
    execve(cmd->args[0], cmd->args, md->env[0]);
    close(fd[OPIPE][WREND]);
}

void ft_execcmd(t_md *md)
{
    t_tree *cmd;
    int fd[2][2];
    pid_t pid;

    cmd = md->tree[0];
    fd = (int[2][2])md->fd;
    if (cmd->right)
    {
        if (pipe(fd[OPIPE]) == -1)
            ft_cleanup(md);
    }
    if ((pid = fork()) == -1)
        ft_cleanup(md);
    if (pid == 0)
        ft_childproc(md);
    fd[IPIPE][RDEND] = fd[OPIPE][RDEND];
    fd[IPIPE][WREND] = fd[OPIPE][WREND];
    close(fd[IPIPE][WREND]);
    waitpid(pid, NULL, 0);
}


// int main(int argc, char **argv)
// {
//     t_tree *t;
//
//     t = malloc(sizeof(t_tree *));
//     while (t)
//     {
//         if (t->right)
//
//     }
//
// }
