/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:15 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 09:08:07 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

// no funciona bien cuando se hace:
// HOLA=hola
// export HOLA
// solo coge el HOLA, y no guarda HOLA=hola
// version modificada para pasar la normi

int	ft_export(t_md *md, char **args)
{
	t_var	*def;
	t_var	*var;
	size_t	i;

	if (!args || !args[1])
		return (ft_putstr_fd("export: not enough arguments\n", 2), 1);
	i = 0;
	while (args[++i])
	{
		def = strtovar(args[i], 1);
		var = varfind(*md->env, def->key);
		if (var)
		{
			if (ft_strncmp(def->value, "", 1) != 0)
				var->value = def->value;
			var->exported = 1;
		}
		else
			add_var(*md->env, def);
	}
	update_env_export(md);
	return (0);
}

/* // Resolver problema con las comillas (linea 32) */
/* int	ft_export(t_md *md, char **args) */
/* { */
/* 	t_var	def; */
/* 	t_var	*var; */
/* 	size_t	i; */

/* 	if (!args || !args[1]) */
/* 	{ */
/* 		printf("export: not enough arguments\n"); */
/* 		return (1); */
/* 	} */
/* 	arprint(md->exported); */
/* 	i = 1; */
/* 	while (args[i]) */
/* 	{ */
/* 		printf("%s\n", args[i]); */
/* 		def = strtovar(args[i], 1); */
/* 		var = varfind(*md->env, def.key); */
/* 		if (var) */
/* 		{ */
/* 			printf("var found\n"); */
/* 			if (def.value) */
/* 				var->value = def.value; */
/* 			var->exported = 1; */
/* 		} */
/* 		else */
/* 		{ */
/* 			printf("var NOT found\n"); */
/* 			var = new_var(def.key, def.value, 1); */
/* 			add_var(*md->env, *var); */
/* 		} */
/* 		i++; */
/* 	} */
/* 	free(md->exported); */
/* 	md->exported = envtoarray(*md->env); */
/* 	arprint(md->exported); */
/* 	return (0); */
/* } */
