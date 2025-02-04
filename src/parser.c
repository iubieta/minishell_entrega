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
#include <stdlib.h>

/* char **buildtreenodeargs(t_token *token, t_md *md) */
/* { */
/*     int i; */
/*     int len; */
/*     char **args; */
/*     t_token *current; */

/*     len = 0; */
/*     current = token; */
/*     while (!is_redir_type(current)) */
/*     { */
/*         len++; */
/*         current = current->right; */
/*     } */
/*     if ((args = ft_calloc(sizeof(char *), len + 1)) == NULL) */
/*         ft_exitwithmallocerror(md); */
/*     i = 0; */
/*     current = token; */
/*     while (i < len) */
/*     { */
/*         args[i] = ft_strdup(current->value); */
/*         current= current->right; */
/*         i++; */
/*     } */
/*     return (args); */
/* } */


t_tree *buildtreenode(t_token *token, t_md *md)
{
    t_tree *node;

    if((node = (t_tree *)malloc(sizeof(t_tree))) == NULL)
        ft_exitwithmallocerror(md);
    if (is_redir_type(token))
    {
        *md->tok = *md->tok
        node->type = TREE_REDIR;
        node->tok = token;
        node->tok->right = NULL;
        return (node);
    }
    node->type = TOKEN_WORD;
    while (!is_redir_type(token))
    {

    }
}

void buildtreestruct(t_md *md)
{
    t_token *tok;
    t_tree *node;

    tok = *md->tok;
    while((node = buildtreenode(tok)) != NULL)
    {

    }

}
