/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:33:21 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/22 16:49:11 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_envfind(char **env, char *str)
{
	size_t	str_len;
	size_t	name_len;
	size_t	i;

	if (!env)
		return (0);
	i = 0;
	while (env[i])
	{
		str_len = ft_strlen(str);
		name_len = ft_indexof(env[i], '=');
		if (str_len == name_len && ft_strncmp(str, env[i], name_len) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_expand_var(char **env, char *var)
{
	size_t	i;
	char	*value;

	if (!env || !var || !*var || !var[1])
		return (NULL);
	var++;
	i = ft_envfind(env, var);
	if (!env[i])
		return (NULL);
	value = ft_strchr(env[i], '=');
	return (++value);
}

char	**ft_dup2parray(char **array)
{
	int		i;
	char	**p;

	if (!array)
		return (NULL);
	p = ft_calloc(ft_arlen(array) + 1, sizeof(char *));
	i = 0;
	while (array[i])
	{
		p[i] = array[i];
		i++;
	}
	return (p);
}

// TEST
// int	main()
// {
// 	
// 	char	**env;
// 	char	*var = "$Var1";
//
// 	printf("\n--Test 1--\n");
// 	printf("%p\n", ft_expand_var(NULL, var));
//
// 	printf("\n--Test 2--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	printf("%p\n", ft_expand_var(env, NULL));
// 	ft_arfree(env);
//
// 	printf("\n--Test 3--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	var = "";
// 	printf("%p\n", ft_expand_var(env, var));
// 	ft_arfree(env);
//
// 	printf("\n--Test 4--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = NULL;
// 	var = "$";
// 	printf("%p\n", ft_expand_var(env, var));
// 	ft_arfree(env);
//
// 	printf("\n--Test 5--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	var = "$Var3";
// 	printf("%s\n", ft_expand_var(env, var));
// 	ft_arfree(env);
// 	
// 	printf("\n--Test 6--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2Value2");
// 	env[2] = ft_strdup("Var3Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	var = "Var3";
// 	printf("%p\n", ft_expand_var(env, var));
// 	ft_arfree(env);
// }
//
