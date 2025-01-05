/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:13:33 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/04 14:17:53 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_arcat(char **array, char *str)
{
	char	**new_array;
	size_t	len;
	size_t	i;

	len = ft_arlen(array);
	new_array = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i++] = ft_strdup(str);
	new_array[i] = NULL;
	free(array);
	array = NULL;
	return (new_array);
}

size_t	ft_arlen(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (i);
	while (array[i])
		i++;
	return (i);
}

void	ft_arprint(char **array)
{
	size_t	i;

	if (!array)
	{
		printf("%p\n", array);
		return ;
	}
	i = 0;
	printf("ptr: %p\n{ ", array);
	while (array[i])
		printf("\"%s\" ", array[i++]);
	printf("}\n");
}

void	ft_arfree(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
	return ;
}

