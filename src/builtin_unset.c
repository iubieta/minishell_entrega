/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:55:07 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 11:13:28 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_remove(t_var **env, char *key)
{
	t_var	*cur;
	t_var	*prev;

	cur = *env;
	prev = NULL;
	while (cur)
	{
		if (key_cmp(cur->key, key) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				*env = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			cur = NULL;
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

int	unset(t_md *md, char **args)
{
	size_t	i;

	if (!args || !md)
		return (printf("unset: not enough arguments\n"), 1);
	i = 1;
	while (args[i])
	{
		var_remove(md->env, args[i]);
		i++;
	}
	update_env_export(md);
	return (0);
}
