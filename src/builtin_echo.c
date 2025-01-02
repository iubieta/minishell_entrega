#include "minishell.h"

void ft_echo(t_tree *node)
{
    int i;
    int flag;
    char **args;

    flag = 0;
    args = node->args;
    if (args[1] == NULL)
    {
        printf("\n");
        return;
    }
    i = 0;
    if (strncmp(args[++i], "-n", 2) == 0)
        flag = 1;
    i+= flag;
    if (args[i])
        printf("%s", args[i]);
    else
        return;
    while (args[++i])
        printf(" %s", args[i]);
    if (!flag)
        printf("\n");
}

/* int main (void) */
/* { */
/*     char *s; */
/*     t_tree node; */

/*     s = strdup("echo -n hola mundo"); */
/*     node.args = ft_split(s, ' '); */
/*     printf("===TEST 1===\n"); */
/*     printf("EXPECTED: hola mundo\n"); */
/*     printf("ACTUAL: "); */
/*     ft_echo(&node); */
/*     printf("\n"); */
/*     free(s); */

/*     s = strdup("echo hola mundo"); */
/*     node.args = ft_split(s, ' '); */
/*     printf("===TEST 2===\n"); */
/*     printf("EXPECTED: hola mundo\n\n"); */
/*     printf("ACTUAL: "); */
/*     ft_echo(&node); */
/*     printf("\n"); */
/*     free(s); */

/*     s = strdup("echo"); */
/*     node.args = ft_split(s, ' '); */
/*     printf("===TEST 3===\n"); */
/*     printf("EXPECTED:\n\n"); */
/*     printf("ACTUAL:"); */
/*     ft_echo(&node); */
/*     printf("\n"); */
/*     free(s); */

/*     s = strdup("echo -n"); */
/*     node.args = ft_split(s, ' '); */
/*     printf("===TEST 4===\n"); */
/*     printf("EXPECTED:\n"); */
/*     printf("ACTUAL:"); */
/*     ft_echo(&node); */
/*     printf("\n"); */
/*     free(s); */
/* } */
