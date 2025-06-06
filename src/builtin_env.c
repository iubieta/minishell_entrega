/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:23:04 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 11:11:34 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_exported_env(char **env)
{
	while (*env)
	{
		if (ft_strchr(*env, '='))
			printf("%s\n", *env);
		else
		{
			printf("%s\n", *env);
			printf("env: string with invalid format on env array\n");
		}
		env++;
	}
}

int	env(char **args, char **env)
{
	char	*error_str;

	if (!env)
	{
		ft_putstr_fd("env: env array doesnt exist\n", 2);
		return (1);
	}
	if (args && args[1])
	{
		error_str = ft_strjoin("env: ", args[1]);
		perror(error_str);
		free(error_str);
		return (1);
	}
	else
	{
		print_exported_env(env);
		return (0);
	}
	return (1);
}
