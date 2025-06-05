/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:47:39 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/22 17:26:27 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(char *value, int type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	token->type = type;
	token->left = NULL;
	token->right = NULL;
	return (token);
}

t_token	*add_token(t_token **root, char *value, int type)
{
	t_token	*current;
	t_token	*new;

	if (!(*root))
		*root = new_token(value, type);
	else
	{
		current = *root;
		while (current->right)
			current = current->right;
		new = new_token(value, type);
		current->right = new;
		new->left = current;
	}
	return (*root);
}

void	free_token(t_token *token)
{
		free(token->value);
		free(token);
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->right;
		free_token(tmp);
	}
}

// traverses tokens until condition met, then returs token.
// used to build tree nodes from a linked list of tokens
t_token	*traverse_tokens(t_token *token)
{
	while (1)
	{
		if (is_redir(token->right))
			break ;
		if (token->right == NULL)
			break ;
		if (token->right->type == TOKEN_VAR_DEF)
			break ;
		token = token->right;
	}
	return (token);
}


void	print_tokens_forward(t_token *tokens)
{
	while (tokens)
	{
		fprintf(stderr, "Token: %-10s Type: %d\n", tokens->value, tokens->type);
		tokens = tokens->right;
	}
}
