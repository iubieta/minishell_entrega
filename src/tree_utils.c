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

char **ft_tokensto2parray(t_token *tok, t_md *md)
{
    t_token *cur;
    int i;
    char **arr;

    if (is_redir_type(tok))
        return (NULL);
    cur = tok;
    i = 1;
    while ((cur = cur->right) != NULL)
        i++;
    if ((arr = (char **)ft_calloc(i + 1, sizeof(char *))) == NULL)
        ft_exitwithmallocerror(md);
    cur = tok;
    i = 0;
    while (cur)
    {
        arr[i] = cur->value;
        cur = cur->right;
        i++;
    }
    return (arr);
}

void ft_printtree(t_tree *tree)
{
    char **args;

    while (tree != NULL)
    {
        printf("TREE NODE: p=%p, right=%p, left=%p\n", tree, tree->right, tree->left);
        printf("type: %d\n", tree->type);
        print_tokens_forward(tree->tok);
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
