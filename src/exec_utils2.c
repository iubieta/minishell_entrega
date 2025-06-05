/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 21:05:14 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/05 21:05:28 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin(char **args, t_md *md)
{
	if (!ft_strcmp(args[0], "cd"))
		md->exit_code = cd(args);
	else if (!ft_strcmp(args[0], "export"))
		md->exit_code = ft_export(md, args);
	else if (!ft_strcmp(args[0], "unset"))
		md->exit_code = unset(md, args);
	else if (!ft_strcmp(args[0], "env"))
		md->exit_code = env(md->exported);
	else if (!ft_strcmp(args[0], "exit"))
		clean_exit(args, md);
	else if (!ft_strcmp(args[0], "echo"))
		md->exit_code = echo(args);
	else if (!ft_strcmp(args[0], "pwd"))
		md->exit_code = pwd(args);
}

void	execcmd(t_md *md)
{
	t_tree	*tree;

	tree = *(md->tree);
	while (tree)
	{
		if (tree->type == TREE_CMD)
			parentproc(tree, md);
		tree = tree->right;
	}
}
