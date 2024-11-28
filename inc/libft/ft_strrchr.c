/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:09:27 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/13 19:10:58 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		cache;

	cache = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			cache = index;
		index++;
	}
	if ((char)c == 0)
		return ((char *)&s[index]);
	else if (cache != 0)
		return ((char *)&s[cache]);
	else if (s[0] == (char)c)
		return ((char *)&s[0]);
	return (NULL);
}
