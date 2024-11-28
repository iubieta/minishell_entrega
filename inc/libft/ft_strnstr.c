/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:38:33 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/14 13:07:53 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ltl_len;
	size_t	big_len;

	big_len = ft_strlen(big);
	ltl_len = ft_strlen(little);
	if (!big_len && !ltl_len)
		return ((char *)big);
	if (!ltl_len)
		return ((char *)big);
	if (!big_len)
		return (NULL);
	while (len >= ltl_len)
	{
		if (!ft_memcmp(big, little, ltl_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
