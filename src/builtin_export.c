/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:15 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/24 22:13:22 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	ft_export(t_md *md, char **args)
{
	t_var	def;
	t_var	*var;
	size_t	i;

	if (!args || !args[1])
	{
		printf("export: not enough arguments\n");
		return (1);
	}
	arprint(md->exported);
	i = 1;
	while (args[i])
	{
		// Resolver problema con las comillas
		printf("%s\n", args[i]);
		def = strtovar(args[i], 1);
		var = varfind(*md->env, def.key);
		if (var)
		{
			printf("var found\n");
			if (def.value)
				var->value = def.value;
			var->exported = 1;
		}
		else
		{
			printf("var NOT found\n");
			var = new_var(def.key, def.value, 1);
			add_var(*md->env, *var);
		}
		i++;
	}
	free(md->exported);
	md->exported = envtoarray(*md->env);
	arprint(md->exported);
	return (0);
}
