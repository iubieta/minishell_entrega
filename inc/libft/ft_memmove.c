/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:19:12 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/09 17:27:29 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;

	cdst = dst;
	csrc = (char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		cdst += n - 1;
		csrc += n - 1;
		while (n-- > 0)
			*cdst-- = *csrc--;
	}
	else
		while (n-- > 0)
			*cdst++ = *csrc++;
	return (dst);
}
