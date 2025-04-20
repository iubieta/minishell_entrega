/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:36:04 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/20 19:48:37 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

char	*findbin(char *bin)
{
	char	*path;
	char	**paths;
	int		i;

	if (access(bin, X_OK) == 0)
		return (bin);
	bin = ft_strjoin("/", bin);
	path = getenv("PATH");
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], bin);
		if (access(path, X_OK) == 0)
			return (ft_free2parray(paths), paths = NULL, path);
		free(path);
		i++;
	}
	return (ft_free2parray(paths), paths = NULL, NULL);
}
