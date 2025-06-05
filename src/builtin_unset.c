/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:55:07 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/05 22:40:28 by iubieta-         ###   ########.fr       */
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
		if (next)
		{
			fprintf(stderr, "flag00\n");
			var->key = next->key;
			fprintf(stderr, "flag00 key:%s\n", var->key);
			var->value = next->value;
			fprintf(stderr, "flag00 value:%s\n", var->value);
			var->exported = next->exported;
			fprintf(stderr, "flag00 exported:%d\n", var->exported);
			var->next = next->next;
			fprintf(stderr, "flag00 exported:%p\n", var->next);
			free(next);
			fprintf(stderr, "flag00\n");
			next = NULL;
			fprintf(stderr, "flag00\n");
		}
		else
		{
			fprintf(stderr, "flag01");
			free(var);
			var = NULL;
		}
		i++;
	}
	//REVISAR: SEGMENTATION FAULT
	fprintf(stderr, "flag02\n");
	free(md->exported);
	fprintf(stderr, "flag03\n");
	md->exported = envtoarray(*md->env);
	fprintf(stderr, "flag04\n");
	return (0);
}
