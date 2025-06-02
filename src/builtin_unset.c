/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:55:07 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/23 19:32:56 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(t_md *md, char **args)
{
	size_t	i;
	t_var	*var;
	t_var	*next;

	if (!args || !md)
		return (printf("unset: not enough arguments\n"), 1);
	i = 1;
	while (args[i])
	{
		var = varfind(*md->env, args[i]);
		next = var->next;
		var->key = next->key;
		var->value = next->value;
		var->exported = next->exported;
		var->next = next->next;
		free(next);
		next = NULL;
		i++;
	}
	free(md->exported);
	md->exported = envtoarray(*md->env);
	arprint(md->exported);
	return (0);
}
