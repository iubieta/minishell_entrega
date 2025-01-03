/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:15 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/03 22:49:16 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_envmod(char **env, char *var);
size_t	ft_envfind(char **env, char *var);
size_t	ft_indexof(char *str, char c);
char	**ft_arjoin(char **array, void *ptr);
size_t	ft_arlen(char **array);

void	ft_export(char **args, char **env)
{
	int i;

	if (!args || !env)
	{
		printf("ft_export: invalid arguments or enviroment\n");
		return ;
	}
	i = 0;
	while (args[i])
	{
		if (!ft_envmod(env, args[i]))
			ft_arjoin(env, args[i]);
		i++;
	}
}

char	**ft_envmod(char **env, char *var)
{
	size_t	i;
	
	if (!env || !var)
		return (NULL);
	i = ft_envfind(env, var);
	if (!env[i])
		return (NULL);
	env[i] = var;
	return (env);
}

size_t	ft_envfind(char **env, char *var)
{
	size_t	name_len;
	size_t	i;

	if (!env)
		return (0);
	name_len = ft_indexof(var, '=');
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(var, env[i], name_len) == 0)
			return (i);
		i++;
	}
	return (i);
}

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

char	**ft_arjoin(char **array, void *ptr)
{
	char	**new_array;
	size_t	len;
	size_t	i;

	len = ft_arlen(array);
	new_array = malloc(len + 2);
	i = 0;
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i++] = ptr;
	new_array[i] = NULL;
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
