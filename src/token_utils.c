/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:47:39 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/07 21:05:17 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_redir_type(t_token *token)
{
  if (!token)
    return(0);
  return (token->type == TOKEN_REDIR_APPEND || \
          token->type == TOKEN_REDIR_OUT || \
          token->type == TOKEN_REDIR_IN || \
          token->type == TOKEN_REDIR_HEREDOC || \
          token->type == TOKEN_PIPE );
}

t_token *new_token(char *value, int type)
{
  t_token *token;

  token = malloc(sizeof(t_token));
  if (!token)
    return (NULL);
  token->value = ft_strdup(value);
  token->type = type;
  token->left = NULL;
  token->right = NULL;
  return (token);
}

t_token *add_token(t_token **root, char *value, int type)
{
  t_token *current;
  t_token *new;

  if (!(*root))
    *root = new_token(value, type);
  else {
    current = *root;
    while (current->right)
      current = current->right;
    new = new_token(value, type);
    current->right = new;
    new->left = current;
  }
  return (*root);
}


void free_tokens(t_token *tokens)
{
  t_token *tmp;

  while (tokens) {
    tmp = tokens;
    tokens = tokens->right;
    free(tmp->value);
    free(tmp);
  }
}

void print_tokens_forward(t_token *tokens)
{
  while (tokens) {
    printf("Token: %-10s Type: %d\n", tokens->value, tokens->type);
    tokens = tokens->right;
  }
}

