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
	char	**env;
	size_t	i;
	size_t	j;
	char	*del;

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
		{
			del = env[j];
			env[j] = ft_strdup(args[i]);
			free(del);
			del = NULL;
		}
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
		if (ft_strncmp(var, env[i], name_len + 1) == 0)
			return (i);
		i++;
	}
	return (i);
}

// TEST
// int	main()
// {
// 	char	**env;
// 	char	**args;
// 
// 	printf("\n--Test 1--\n");
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1=Value1");
// 	args[1] = NULL;
// 	ft_arprint(NULL);
// 	ft_export(NULL, args);
// 	ft_arprint(NULL);
// 	ft_arfree(args);
// 
// 	printf("\n--Test 2--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	ft_arprint(env);
// 	ft_export(&env, NULL);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 
// 	printf("\n--Test 3--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1=Value1");
// 	args[1] = NULL;
// 	ft_export(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
// 
// 	printf("\n--Test 4--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1=Value2");
// 	args[1] = NULL;
// 	ft_export(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
// 
// 	printf("\n--Test 5--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("VarN=ValueN");
// 	args[1] = ft_strdup("VarN+1=ValueN+1");
// 	args[2] = ft_strdup("VarN+2=ValueN+2");
// 	args[3] = ft_strdup("VarN+3=ValueN+3");
// 	args[4] = NULL;
// 	ft_export(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
// 	
// 	printf("\n--Test 6--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var=ValueN");
// 	args[1] = ft_strdup("Var1=ValueN+1");
// 	args[2] = ft_strdup("Var2=ValueN+2");
// 	args[3] = ft_strdup("Var3=ValueN+3");
// 	args[4] = NULL;
// 	ft_export(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
// 
// }

