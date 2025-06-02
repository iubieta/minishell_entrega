/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:13:33 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/12 19:36:45 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Prints a char** array
void	arprint(char **array)
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

// Frees a char** array
void	arfree(char **array)
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

// Duplicates a char** array
char	**ardup(char **array)
{
	int		i;
	char	**p;

	if (!array)
		return (NULL);
	p = ft_calloc(arlen(array) + 1, sizeof(char *));
	i = 0;
	while (array[i])
	{
		p[i] = ft_strdup(array[i]);
		i++;
	}
	return (p);
}
