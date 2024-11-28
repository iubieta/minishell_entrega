#include "minishell.h"

void ft_echo(t_ast_node *node)
{
    char flag;
    char **args;

    flag = 0;
    args = node->args + 1;
    if ((flag = ft_strncmp("-n", *args, 3)) == 0)
        args++;
    printf("%s", *args);
    args++;
    while (args)
    {
        printf(" %s", *args);
    }
    if (flag)
        printf("\n");
}
