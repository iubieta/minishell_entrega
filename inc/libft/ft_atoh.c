/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:42:25 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/14 13:56:50 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoh(unsigned long n)
{
	unsigned int	len;
	unsigned long	tmp;
	char			*hex;
	char			*base;

	len = 0;
	tmp = n;
	if (n == 0)
		len++;
	while (tmp > 0)
	{
		tmp /= 16;
		len++;
	}
	hex = (char *)ft_calloc(len + 1, sizeof(char));
	base = ft_strdup("0123456789abcdefg");
	tmp = n;
	while (len > 0)
	{
		hex[len - 1] = base[tmp % 16];
		tmp /= 16;
		len--;
	}
	free(base);
	return (hex);
}
