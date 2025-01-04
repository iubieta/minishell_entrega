/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:15 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/04 14:17:59 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_envfind(char **env, char *var);

void	ft_export(char ***env_ptr, char **args)
{
	char **env;
	size_t i;
	size_t j;

	if (!args || !env_ptr)
	{
		printf("ft_export: invalid arguments or enviroment\n");
		return ;
	}
	i = 0;
	env = *env_ptr;
	while (args[i])
	{

		j = ft_envfind(env, args[i]);
		if (env[j])
			env[j] = args[i];
		else
			env = ft_arcat(env, args[i]);
		i++;
	}
	*env_ptr = env;
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

// TEST
int	main()
{
	char	**env;
	char	**args;

	printf("\n--Test 1--\n");
	args = malloc(5);
	args[0] = "Var1=Value1";
	args[1] = NULL;
	ft_arprint(NULL);
	ft_export(NULL, args);
	ft_arprint(NULL);

	printf("\n--Test 2--\n");
	env = malloc(10);
	ft_arprint(env);
	ft_export(&env, NULL);
	ft_arprint(env);

	printf("\n--Test 3--\n");
	env = malloc(10);
	ft_arprint(env);
	args = malloc(5);
	args[0] = "Var1=Value1";
	args[1] = NULL;
	ft_export(&env, args);
	ft_arprint(env);

	printf("\n--Test 4--\n");
	env = malloc(10);
	env[0] = "Var1=Value1";
	env[1] = NULL;
	ft_arprint(env);
	args = malloc(5);
	args[0] = "Var1=Value2";
	args[1] = NULL;
	ft_export(&env, args);
	ft_arprint(env);
}
