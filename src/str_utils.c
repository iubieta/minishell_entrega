/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:14:26 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/04 14:18:04 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_indexof(char *str, char c)
{
	size_t i;

	i = 0;
	if (!str)
		return (i);
	while(str[i] && str[i] != c)
		i++;
	return (i);
}

