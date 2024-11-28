/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p@student.42urduliz.com <marvi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:25:49 by acampo-p@         #+#    #+#             */
/*   Updated: 2024/10/07 13:31:37 by acampo-p@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_xtoi(char *hex)
{
	int		i;
	int		j;
	int		x;
	char	*base;

	if (!hex)
		return (0);
	if (ft_tolower(hex[0]) != '0' && ft_tolower(hex[1]) != 'x')
		return (perror("Not a valid hexadecimal string"), 0);
	base = ft_strdup("0123456789abcdef");
	i = 1;
	x = 0;
	while (hex[++i] != '\0')
	{
		x *= 16;
		j = 0;
		while (ft_tolower(hex[i]) != base[j])
		{
			if (base[j] == '\0')
				return (free(base), 0);
			j++;
		}
		x += j;
	}
	return (free(base), x);
}
