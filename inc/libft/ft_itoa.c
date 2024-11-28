/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:42:25 by acampo-p          #+#    #+#             */
/*   Updated: 2024/10/07 13:21:16 by acampo-p@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	tmp;
	char			*s;
	char			*base;

	len = 0;
	if (n <= 0)
		len++;
	tmp = ft_abs(n);
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	s = (char *)ft_calloc(len + 1, sizeof(char));
	base = ft_strdup("0123456789");
	tmp = ft_abs(n);
	while (len-- > 0)
	{
		s[len] = base[tmp % 10];
		tmp /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (free(base), s);
}
