/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:12:42 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/22 17:16:01 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TOKEN_REDIR_APPEND || \
			token->type == TOKEN_REDIR_OUT || \
			token->type == TOKEN_REDIR_IN || \
			token->type == TOKEN_REDIR_HEREDOC || \
			token->type == TOKEN_PIPE);
}

// returns a non-zero number if a token is a '<' or a '<<'
int	is_lredir(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TOKEN_REDIR_IN || \
			token->type == TOKEN_REDIR_HEREDOC);
}

// returns a non-zero number if a token is a '>' or a '>>'
int	is_rredir(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TOKEN_REDIR_APPEND || \
			token->type == TOKEN_REDIR_OUT);
}

// returns a non-zero number if a token is a '|'
int	is_pipe(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TOKEN_PIPE);
}
