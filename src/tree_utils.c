#include "minishell.h"

void ft_freetreenode(t_tree *n)
{
    if (n->args != NULL)
        ft_free2parray(n->args);
    n->args = NULL;
    return ;
}

void ft_freetree(t_tree **head)
{
    t_tree *cur;
    t_tree *tmp;

    cur = *head;
    while (cur->right)
    {
        tmp = cur;
        cur = cur->right;
        ft_freetreenode(tmp);
    }
    head = NULL;
    return ;
}

void ft_deletetreenode(t_tree *n, t_tree **head)
{
    t_tree *cur;
    t_tree *tmp;

    cur = *head;
    while (cur->right != n)
        cur = cur->right;
    tmp = n->right;
    ft_freetreenode(n);
    cur->right = tmp;
    return ;
}

void ft_printtree(t_tree *tree)
{
    char **args;

    while (tree != NULL)
    {
        printf("TREE NODE: p=%p, right=%p, left=%p\n", tree, tree->right, tree->left);
        printf("type: %d\n", tree->type);
        args = tree->args;
        printf("args:");
        while (args)
        {
            if (*args)
                printf(" %s", *args);
            else
                break;
            args++;
        }
        printf("\n");
        tree = tree->right;
    }
}
