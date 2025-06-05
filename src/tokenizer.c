/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:28:39 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/05 22:59:34 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <ctype.h>

void	unclosed_quotes_error(void)
{
	perror(ERR_QUOTE);
	exit(1);
}

char	**split_quotation_blobs(char *s, char c)
{
	int		i;
	char	*p;
	char	*tmp;
	char	**arr;

	arr = ft_calloc(4, sizeof(char *));
	p = s;
	i = 0;
	if (c == '\0')
		return (arr[0] = s, arr);
	arr[i] = p;
	p = ft_strchr(p, c);
	while (p != NULL && i < 2)
	{
		if (p == s)
			arr[++i] = p;
		else if (*(p - 1) != '\\')
			arr[++i] = p;
		p++;
		p = ft_strchr(p, c);
	}
	if (i % 2 != 0)
		unclosed_quotes_error();
	while (i > 0)
	{
		tmp = arr[i];
		arr[i] = strdup(arr[i] + 1);
		ft_bzero(tmp, ft_strlen(tmp));
		i--;
	}
	return (arr);
}

// Falta comprobar que no tenga un "\"
char	find_first_quote_char(char *s)
{
	char	*p[2];

	p[0] = ft_strchr(s, '"');
	p[1] = ft_strchr(s, '\'');
	if (p[0] != NULL && p[1] != NULL)
	{
		if (p[0] < p[1])
			return ('"');
		else
			return ('\'');
	}
	else if (p[0] != NULL)
		return ('"');
	else if (p[1] != NULL)
		return ('\'');
	else
		return ('\0');
}

t_token	*tokenize(char *s)
{
	t_token	*tokens;
	char	c;
	char	**arr;
	char	*blob;

	tokens = NULL;
	while (s)
	{
		c = find_first_quote_char(s);
		arr = split_quotation_blobs(s, c);
		if (arr == NULL)
			return (NULL);
		s = arr[2];
		blob = arr[1];
		append_tokens(&tokens, arr, blob, c);
	}
	classify_tokens(&tokens);
	return (tokens);
}
