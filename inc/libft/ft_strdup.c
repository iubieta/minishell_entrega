/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:02:06 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/10 10:28:23 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*scpy;
	size_t	len;

	len = ft_strlen(s) + 1;
	scpy = (char *)malloc(len);
	if (!scpy)
		return (NULL);
	scpy = ft_memcpy(scpy, s, len);
	return (scpy);
}
