/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:19:09 by iubieta           #+#    #+#             */
/*   Updated: 2024/12/24 18:48:41y iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void ft_redirleft(t_token *t)
//{
    //t_token *tmp;
//
    //tmp = t->left;
    //t->left = t->right;
    //t->right = tmp;
//}
//
//// Que esta funcion sea recuersiva para el caso en el que haya 2 redirecciones
//// seguidas
//// echo hola < mundo.c << HERE
//void parserread(t_token *t)
//{
    //while (t)
    //{
        //if (t->type == 3 || t->type == 4)
            //ft_redirleft(t);
        //if (t->type == 1 || t->type == 2)
            //ft_redirright(t);
        //else
            //ft_pipeexec(t);
//
    //}
//}

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

t_token *buildtreenode(t_tree *tree, t_token *t)
{
    int i;
    t_token *tmp;

    if (t == NULL)
        return (t);
    tree->args = NULL;
    tmp = t;
    i = 0;
    while (tmp == TOKEN_WORD && tmp != NULL)
    {
        tmp = tmp->right;
        i++;
    }
    if (t->type == TOKEN_WORD)
        tree->args = buildcommand(t, i);
    else
        tmp++;
    tree->type = t->type;
    return (tmp);
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
        current= current->right;
    }
    return (tree);

}

void test_printtree(t_tree *tree)
{
    char **args;

    while (tree)
    {
        printf("TREE NODE: p=%p, right=%p, left=%p\n", tree, tree->right, tree->left);
        printf("type: %d", tree->type);
        args = tree->args;
        printf("args:");
        while (args)
        {
            printf(" %s", *args);
            args++;
        }
        printf("\n");
        tree = tree->right;
    }

}

int main() {
    char input[1024];
    printf("minishell> ");
    if (fgets(input, 1024, stdin)) {
        input[strcspn(input, "\n")] = '\0'; // Elimina el salto de línea
        t_token *tokens = tokenize(input);
        t_tree *tree = buildtreestruct(tokens);
        test_printtree(tree);
        free_tokens(tokens);
    }
    return 0;
}
