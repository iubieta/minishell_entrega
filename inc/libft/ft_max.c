/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p@student.42urduliz.com <marvi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:44:51 by acampo-p@         #+#    #+#             */
/*   Updated: 2024/10/07 13:45:19 by acampo-p@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *array, int len)
{
	int	n;
	int	i;

	n = INT_MIN;
	i = 0;
	while (i < len)
	{
		if (array[i] > n)
			n = array[i];
		i++;
	}
	return (n);
}
