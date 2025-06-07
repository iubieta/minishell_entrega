/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:33:21 by iubieta-          #+#    #+#             */
/*   Updated: 2025/05/30 18:04:29 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_export(t_md *md)
{
	int	i;

	i = 0;
	while (md->exported[i])
		free(md->exported[i++]);
	free(md->exported);
	md->exported = envtoarray(*md->env);
}

// Returns the index to the first element of env array whose name matches str
size_t	envfind(char **env, char *str)
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
		name_len = indexof(env[i], '=');
		if (str_len == name_len && ft_strncmp(str, env[i], name_len) == 0)
			return (i);
		i++;
	}
	return (i);
}

// TEST
// int	main()
// {
// 	
// 	char	**env;
// 	char	*var = "$Var1";
//
// 	printf("\n--Test 1--\n");
// 	printf("%p\n", expand_var(NULL, var));
//
// 	printf("\n--Test 2--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	printf("%p\n", expand_var(env, NULL));
// 	arfree(env);
//
// 	printf("\n--Test 3--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = NULL;
// 	var = "";
// 	printf("%p\n", expand_var(env, var));
// 	arfree(env);
//
// 	printf("\n--Test 4--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = NULL;
// 	var = "$";
// 	printf("%p\n", expand_var(env, var));
// 	arfree(env);
//
// 	printf("\n--Test 5--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2=Value2");
// 	env[2] = ft_strdup("Var3=Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	var = "$Var3";
// 	printf("%s\n", expand_var(env, var));
// 	arfree(env);
// 	
// 	printf("\n--Test 6--\n");
// 	env = ft_calloc(10, sizeof(char *));
// 	env[0] = ft_strdup("Var1=Value1");
// 	env[1] = ft_strdup("Var2Value2");
// 	env[2] = ft_strdup("Var3Value3");
// 	env[3] = ft_strdup("Var4=Value4");
// 	env[4] = NULL;
// 	var = "Var3";
// 	printf("%p\n", expand_var(env, var));
// 	arfree(env);
// }
//
