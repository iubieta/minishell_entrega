#include "minishell.h"

void ft_childproc(t_tree *tree, t_md *md)
{
    char **cmd;
    int **fd;
    t_tree *next;
    char program[256];

    fd = md->fd;
    cmd = tree->args;
    next = tree->right;
    ft_memset(program, '\0', 256);
    ft_strlcat(program, "/bin/", ft_strlen("/bin/") + 1);
    ft_strlcat(program, *cmd, 50);
    if (fd[IPIPE][RDEND] != -1)
    {
        fprintf(stderr, "flag10\n");
        dup2(fd[IPIPE][RDEND], STDIN_FILENO);
        close(fd[IPIPE][RDEND]);
    }
    if (is_lredir(next->tok))
    {
        fprintf(stderr, "flag11\n");
        return ;
        /* ft_leftredir(md); //esto catearia el archivo y borraria el node de la llist */
    }
    else if (is_pipe(next->tok))
    {
        fprintf(stderr, "flag12\n");
        dup2(fd[OPIPE][WREND], STDOUT_FILENO);
    }
    else if (is_rredir(next->tok))
    {
        fprintf(stderr, "flag13\n");
        return ;
        /* ft_rightredir(md); */
    }
    fprintf(stderr, "flag14\n");
    close(fd[OPIPE][RDEND]);
    execve(program, cmd, NULL);
    close(fd[OPIPE][WREND]);
}

void ft_parentproc(t_tree *tree, t_md *md)
{
    pid_t pid;

    if (tree->right)
    {
        printf("flag03\n");
        if (pipe(md->fd[OPIPE]) == -1)
            ft_cleanup(md);
    }
    if ((pid = fork()) == -1)
        ft_cleanup(md);
    if (pid == 0)
    {
        fprintf(stderr, "flag04\n");
        ft_printtreeinerror(tree);
        ft_childproc(tree, md);
    }
    printf("flag05\n");
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
        {
            fprintf(stderr, "this is stderror\n");
            printf("flag000\n");
            /* ft_printtree(tree); */
            ft_parentproc(tree, md);
        }
        tree = tree->right;
    }
}
