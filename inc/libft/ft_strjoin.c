/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:17:08 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/10 13:28:55 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len[2];

	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	str = (char *)malloc(len[0] + len[1] + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, len[0]);
	str += len[0];
	str = ft_memcpy(str, s2, len[1] + 1);
	str -= len[0];
	return (str);
}
