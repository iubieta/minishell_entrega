/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 21:40:44 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/05 21:44:11 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_toktype	determine_token_type(char *s)
{
	if (ft_memcmp(s, "|", 2) == 0)
		return (TOKEN_PIPE);
	else if (ft_memcmp(s, ">", 2) == 0)
		return (TOKEN_REDIR_OUT);
	else if (ft_memcmp(s, "<", 2) == 0)
		return (TOKEN_REDIR_IN);
	else if (ft_memcmp(s, ">>", 3) == 0)
		return (TOKEN_REDIR_APPEND);
	else if (ft_memcmp(s, "<<", 3) == 0)
		return (TOKEN_REDIR_HEREDOC);
	else if (is_var_definition(s))
		return (TOKEN_VAR_DEF);
	else if (s[0] == '$' && ft_strlen(s) > 1)
	{
		if (isalpha(s[1]) || ft_strncmp(s,"$?", 3) == 0)
			return (TOKEN_ENV_VAR);
		else if (s[1] == '_' && ft_strlen(s))
			return (TOKEN_ENV_VAR);
		else
			return (TOKEN_WORD);
	}
	else
		return (TOKEN_WORD);
}

void	classify_tokens(t_token **head)
{
	t_token	*t;

	t = *head;
	while (t)
	{
		if (t->type == TOKEN_UNKNOWN)
			t->type = determine_token_type(t->value);
		t = t->right;
	}
	return ;
}

char	*get_correct_spaced_tokens(char *ogs)
{
	char	*mods;
	int		i;
	int		j;

	mods = ft_calloc(ft_strlen(ogs) * 2, sizeof(char));
	i = 0;
	j = 0;
	while (ogs[i] != '\0')
	{
		if (ft_strchr("<>|", ogs[i]) != NULL)
		{
			mods[j++] = ' ';
			mods[j++] = ogs[i++];
			if (ogs[i] == ogs[i - 1] && ogs[i] != '|')
				mods[j++] = ogs[i++];
			mods[j++] = ' ';
		}
		else
			mods[j++] = ogs[i++];
	}
	mods[j++] = ogs[i++];
	free(ogs);
	return (mods);
}

void	append_tokens(t_token **tokens, char **arr, char *blob, char blob_type)
{
	int		i;
	char	**tmp;

	tmp = arr;
	arr = ft_split(get_correct_spaced_tokens(arr[0]), ' ');
	i = 0;
	while (arr[i])
		add_token(tokens, arr[i++], TOKEN_UNKNOWN);
	free(tmp);
	if (blob != NULL && blob_type == '"')
		add_token(tokens, blob, TOKEN_BLOB_DQ);
	if (blob != NULL && blob_type == '\'')
		add_token(tokens, blob, TOKEN_BLOB_SQ);
}
