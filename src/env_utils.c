/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:33:21 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/05 18:07:54 by iubieta-         ###   ########.fr       */
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

