/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:55:07 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/22 16:48:00 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char ***env_ptr, char **args)
{
	char	**env;
	size_t	i;
	size_t	j;

	if (!args || !env_ptr)
	{
		printf("unset: not enough arguments\n");
		return ;
	}
	i = 0;
	env = *env_ptr;
	while (args[i])
	{
		j = ft_envfind(env, args[i]);
		if (!env[j])
			printf("unset: %s: invalid parameter name\n", args[i]);
		env = ft_arremove(env, j);
		i++;
	}
	*env_ptr = env;
}

// TEST
// int	main()
// {
// 	char	**args;
// 	char	**env;
//
//
// 	printf("\n--Test 1--\n");
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1");
// 	args[1] = NULL;
// 	ft_arprint(NULL);
// 	ft_unset(NULL, args);
// 	ft_arprint(NULL);
// 	ft_arfree(args);
//
// 	printf("\n--Test 2--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	ft_arprint(env);
// 	ft_unset(&env, NULL);
// 	ft_arprint(env);
// 	ft_arfree(env);
//
// 	printf("\n--Test 3--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	ft_arprint(env);
// 	args = ft_calloc(10, sizeof(char *));
// 	args[0] = ft_strdup("Var1");
// 	args[1] = NULL;
// 	ft_unset(&env, args);
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
// 	args[0] = ft_strdup("Var1=Value1");
// 	args[1] = NULL;
// 	ft_unset(&env, args);
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
// 	args[0] = ft_strdup("Var2");
// 	args[1] = ft_strdup("Var3");
// 	args[2] = NULL;
// 	ft_unset(&env, args);
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
// 	args[0] = ft_strdup("Var2=Value2");
// 	args[1] = ft_strdup("Var3");
// 	args[2] = NULL;
// 	ft_unset(&env, args);
// 	ft_arprint(env);
// 	ft_arfree(env);
// 	ft_arfree(args);
// }
//
