/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:15 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/20 20:12:28 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

// Replace a char** element with a new char*
void	armod(char	**ar_pos, char	*str)
{
	char	*del;

	del = *ar_pos;
	*ar_pos = ft_strdup(str);
	free(del);
	del = NULL;
}

int	ft_export(char ***env_ptr, char **args)
{
	char	**env;
	char	*var;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!args || !env_ptr)
	{
		printf("export: not enough arguments\n");
		return (1);
	}
	i = 1;
	env = *env_ptr;
	while (args[i])
	{
		len = ft_strlen(args[i]);
		//REVISAR: ñapa?? revisar leaks de memoria
		if (len == (indexof(args[i], '=') + 1))
		{
			var = ft_substr(args[i], 0, indexof(args[i], '=' + 1));
			i++;
			args[i] = ft_strjoin(var, args[i]);
		}
		var = ft_substr(args[i], 0, indexof(args[i], '='));
		j = envfind(env, var);
		if (env[j])
			armod(&env[j], args[i]);
		else
			env = arcat(env, args[i]);
		i++;
	}
	*env_ptr = env;
	return (0);
}
