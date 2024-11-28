/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:50:37 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/14 13:57:57 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	unsigned int	dbase;
	char			c;

	dbase = 1;
	if (n < 0)
	{
		nbr = -1 * n;
		write (fd, "-", 1);
	}
	else
		nbr = n;
	while (nbr / dbase >= 10)
		dbase *= 10;
	while (dbase >= 1)
	{
		c = nbr / dbase + '0';
		nbr -= (c - '0') * dbase;
		dbase /= 10;
		write (fd, &c, 1);
	}
}
