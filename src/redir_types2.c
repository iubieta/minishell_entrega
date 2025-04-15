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

// returns a non-zero number if a token is a '<' or a '<<'
int	is_redir_in(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TOKEN_REDIR_IN);
}

int	is_redir_hdoc(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TOKEN_REDIR_HEREDOC);
}

// returns a non-zero number if a token is a '>' or a '>>'
int	is_redir_out(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TOKEN_REDIR_OUT);
}

int	is_redir_append(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TOKEN_REDIR_APPEND);
}
