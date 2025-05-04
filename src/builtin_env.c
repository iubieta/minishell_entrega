/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:23:04 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/23 19:15:04 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(char **env)
{
	if (!env)
	{
		printf("env: env array doesnt exist\n");
		return (1);
	}
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
	return (0);
}

