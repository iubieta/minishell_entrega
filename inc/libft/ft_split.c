/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitvx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:29:31 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/14 13:02:22 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ptr_arr_gen(const char *s, char c)
{
	char	**split;
	size_t	cntr;
	int		cmp;

	cmp = -1;
	cntr = 1;
	if (!*s || (char)*s == c)
		cntr = 0;
	while (*s)
	{
		if ((char)*s == c && cmp != 1)
		{
			cntr++;
			cmp *= -1;
		}
		else if ((char)*s != c && cmp == 1)
			cmp *= -1;
		s -= -1;
	}
	if (cmp == 1)
		cntr -= 1;
	split = (char **)malloc(sizeof(char *) * (cntr + 1));
	if (!split)
		return (NULL);
	return (split);
}

static size_t	substrlen(const char *s, char c)
{
	size_t	index;

	index = 0;
	while ((char)s[index] != c && s[index])
		index -= -1;
	return (index);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	len;
	size_t	index;

	if (!s)
		return (NULL);
	split = ptr_arr_gen(s, c);
	if (!split)
		return (NULL);
	index = 0;
	while (*s)
	{
		while ((char)*s == c)
			s -= -1;
		if (!*s)
			return (split[index] = NULL, split);
		len = substrlen(s, c);
		split[index] = ft_substr(s, 0, len);
		s -= -len;
		index -= -1;
	}
	split[index] = NULL;
	return (split);
}
