/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:08:36 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/13 20:05:08 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int	**initfdarray(void)
{
	int	**p;
	int	*a;

	p = malloc(2 * sizeof(int *));
	a = malloc(4 * sizeof(int));
	a[0] = -1;
	a[1] = -1;
	a[2] = -1;
	a[3] = -1;
	p[0] = a;
	p[1] = a + 2;
	return (p);
}

// Queda pendiente de adaptar, pero va a ser necesario para despues
void	cleanup(t_md *md, int mode)
{
	freetree(md->tree);
	free(md->fd[0]);
	free(md->fd);
	md->fd = initfdarray();
	if (mode == 1)
	{
		free(md);
		md = NULL;
	}
}

void	exitwithmallocerror(t_md *md)
{
	cleanup(md, 1);
	md->exit_code = 1;
	exit(EXIT_FAILURE);
}

t_md	*initmetadata(char **environ)
{
	t_md		*md;

	md = (t_md *)malloc(sizeof(t_md));
	if (md == NULL)
		exitwithmallocerror(md);
	md->env = (t_var **)malloc(sizeof(t_var *));
	*md->env = initenv();
	md->exported = ardup(environ);
	md->tok = (t_token **)malloc(sizeof(t_token *));
	if (md->tok == NULL)
		exitwithmallocerror(md);
	md->tree = (t_tree **)malloc(sizeof(t_tree *));
	if (md->tree == NULL)
		exitwithmallocerror(md);
	md->fd = initfdarray();
	md->prompt = NULL;
	return (md);
}
