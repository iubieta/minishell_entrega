#include "minishell.h"

void addcat()


// Queda pendiente de adaptar, pero va a ser necesario para despues
//void ft_cleanup(t_tree *metad)
//{
    //t_tree *cmd;
    //t_tree *tmp;
//
    //cmd = *(metad->head);
    //while (cmd)
    //{
        //free(cmd->cmd);
        //ft_free2parray(cmd->argv);
        //tmp = cmd;
        //cmd = cmd->next;
        //free(tmp);
    //}
    //free(metad->head);
//}

    void ft_childproc(t_tree *cmd, int fd[2][2])
{
    int fd_fileout;

    if (fd[IPIPE][RDEND] != -1)
    {
        dup2(fd[IPIPE][RDEND], STDIN_FILENO);
        close(fd[IPIPE][RDEND]);
    }
    if (cmd->right->type == TOKEN_REDIR_IN)
    {
        ft_catfile(cmd); //esto catearia el archivo y borraria el node de la llist
    }
    if (cmd->right->type == TOKEN_PIPE)
        dup2(fd[OPIPE][WREND], STDOUT_FILENO);
    if (cmd->right->type == TOKEN_REDIR_OUT)
    {
        ft_writefile(cmd);
    }
    close(fd[OPIPE][RDEND]);
    execve(cmd->cmd, cmd->argv, cmd->env);
    close(fd[OPIPE][WREND]);
    if (!cmd->next)
        close(fd_fileout);
}

void ft_execcmd(t_tree *cmd)
{
    static int fd[2][2] = {{-1, -1}, {-1, -1}};
    pid_t pid;

    if (cmd->right)
    {
        if (pipe(fd[OPIPE]) == -1)
            ft_cleanup(metad);
    }
    if ((pid = fork()) == -1)
        ft_cleanup(metad);
    if (pid == 0)
        ft_childproc(cmd, fd, metad->ofile);
    fd[IPIPE][RDEND] = fd[OPIPE][RDEND];
    fd[IPIPE][WREND] = fd[OPIPE][WREND];
    close(fd[IPIPE][WREND]);
    waitpid(pid, NULL, 0);
}

int main(int argc, char **argv)
{
    t_tree *t;

    t = malloc(sizeof(t_tree *));
    while (t)
    {
        if (t->right)

    }

}
