/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:08:36 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/12 20:03:50 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int **initfdarray(void)
{
    int **p;
    int *a;

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

t_md *ft_initmetadata()// Deberia iniciarse en vacio ?? Sin tokens ni comandos.
{

    t_md *md;
	extern char	**environ;
	char	**my_env;

    md = malloc(sizeof(t_md *));
    // md->tree[0] = buildtreestruct(token);
	md->tree = NULL;
    md->fd = initfdarray();
    my_env = ft_dup2parray(environ);
	md->env = &my_env;
	return (md);
}

// Queda pendiente de adaptar, pero va a ser necesario para despues
void ft_cleanup(t_md *metad)
{
    ft_freetree(metad->tree);
    free(metad->fd[0]);
    free(metad->fd);
    ft_free2parray(metad->env[0]);
    free(metad);
    metad = NULL;
}

