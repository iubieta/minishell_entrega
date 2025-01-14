/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:19:09 by iubieta           #+#    #+#             */
/*   Updated: 2025/01/12 19:59:05 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *buildtreenode(t_tree *tree, t_token *t);
char **buildcommand(t_token *t, int words);

void	parse(char *input, t_md md)
{
	t_token	*tokens;

	tokens = tokenize(input);
	// crear variable tipo tree
	// asignad md.tree con &vartree
	md.tree[0] = buildtreestruct(tokens);
}

t_tree *buildtreestruct(t_token *t)
{
    t_tree *tree;
    t_tree *current;

    tree= (t_tree *)malloc(sizeof(t_tree));
    current = tree;
    while (t)
    {
        t = buildtreenode(current, t);
        current->left = NULL; // Provisional hasta que decidamos si se hace tipo binarytree o tipo linked list
        current->right = (t_tree *)malloc(sizeof(t_tree));
        current = current->right;
        current->right = NULL;
    }
    return (tree);

}

t_token *buildtreenode(t_tree *tree, t_token *t)
{
    int i;
    t_token *tmp;

    if (t == NULL)
        return (t);
    tree->args = NULL;
    tmp = t;
    i = 0;
    while (tmp)
    {
        if (tmp->type != TOKEN_WORD)
            break;
        tmp = tmp->right;
        i++;
    }
    if (t->type == TOKEN_WORD)
        tree->args = buildcommand(t, i);
    else
        tmp = tmp->right;
    tree->type = t->type;
    return (tmp);
}

char **buildcommand(t_token *t, int words)
{
    int i;
    char **args;

    args = ft_calloc(words, sizeof(char *) + 1);
    i = 0;
    while (i < words)
    {
        args[i] = t->value;
        t = t->right;
        i++;
    }
    return (args);
}


void test_printtree(t_tree *tree)
{
    char **args;

    while (tree)
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

// int main() {
//     char input[1024];
//     printf("minishell> ");
//     if (fgets(input, 1024, stdin)) {
//         input[strcspn(input, "\n")] = '\0'; // Elimina el salto de línea
//         t_token *tokens = tokenize(input);
//         t_tree *tree = buildtreestruct(tokens);
//         test_printtree(tree);
//         free_tokens(tokens);
//     }
//     return 0;
// }
