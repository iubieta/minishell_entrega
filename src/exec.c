#include "minishell.h"

void ft_childproc(t_tree *tree, t_md *md)
{
    char **cmd;
    int **fd;
    t_tree *next;

    fd = md->fd;
    cmd = tree->args;
    next = tree->right;
    if (fd[IPIPE][RDEND] != -1)
    {
        printf("flag10\n");
        dup2(fd[IPIPE][RDEND], STDIN_FILENO);
        close(fd[IPIPE][RDEND]);
    }
    if (is_lredir(next->tok))
    {
        printf("flag11\n");
        return ;
        /* ft_leftredir(md); //esto catearia el archivo y borraria el node de la llist */
    }
    else if (is_pipe(next->tok))
    {
        printf("flag12, %s\n", *cmd);
        dup2(fd[OPIPE][WREND], STDOUT_FILENO);
    }
    else if (is_rredir(next->tok))
    {
        printf("flag13\n");
        return ;
        /* ft_rightredir(md); */
    }
    printf("flag14\n");
    close(fd[OPIPE][RDEND]);
    execve(cmd[0], cmd, *(md->env));
    close(fd[OPIPE][WREND]);
}

void ft_parentproc(t_tree *tree, t_md *md)
{
    pid_t pid;

    tree = *(md->tree);
    printf("flag00, %s, %s\n", (tree->args)[0], (tree->args[1]));
    execve(*(tree->args), tree->args, NULL);
    if (tree ->right)
    {
        printf("flag01\n");
        if (pipe(md->fd[OPIPE]) == -1)
            ft_cleanup(md);
    }
    if ((pid = fork()) == -1)
        ft_cleanup(md);
    if (pid == 0)
        ft_childproc(tree, md);
    printf("flag02\n");
    md->fd[IPIPE][RDEND] = md->fd[OPIPE][RDEND];
    md->fd[IPIPE][WREND] = md->fd[OPIPE][WREND];
    close(md->fd[IPIPE][WREND]);
    waitpid(pid, NULL, 0);
}

void ft_execcmd(t_md *md)
{
    t_tree *tree;
    tree = *(md->tree);
    while (tree)
    {
        if (tree->type == TREE_CMD)
            ft_parentproc(tree, md);
        tree = tree->right;
    }
}
