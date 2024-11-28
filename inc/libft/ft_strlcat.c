/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:11:03 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/14 13:06:33 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len[2];
	size_t	index;

	len[0] = ft_strlen(dst);
	dst += len[0];
	len[1] = ft_strlen(src);
	index = 0;
	while (src[index] != '\0' && index + len[0] + 1 < size)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	if (size < len[0])
		return (len[1] + size);
	return (len[0] + len[1]);
}
