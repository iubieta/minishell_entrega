/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:49:50 by iubieta-          #+#    #+#             */
/*   Updated: 2025/05/06 20:45:51 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	execute_builtin(char **args, t_md *md);
int		is_main_builtin(char *cmd);
int		is_print_builtin(char *cmd);
void	create_pipe(t_md *md, int pipeint);
pid_t	create_fork(t_md *md);
void	handle_signals(t_md *md, pid_t pid);

void	handle_pipes(t_tree *tree, t_md *md)
{
	int		**fd;

	fd = md->fd;
	if (fd[IPIPE][RDEND] != -1)
	{
		dup2(fd[IPIPE][RDEND], STDIN_FILENO);
		close(fd[IPIPE][RDEND]);
	}
	close(fd[IPIPE][WREND]);
	if (tree->right || md->has_output_redir == 1)
	{
		dup2(fd[OPIPE][WREND], STDOUT_FILENO);
		close(fd[OPIPE][WREND]);
	}
	close(fd[OPIPE][RDEND]);
}

void	childproc(t_tree *tree, t_md *md)
{
	char	**cmd;
	char	*program;

	sig_reset();
	cmd = tree->args;
	program = *cmd;
	fprintf(stderr, "flag000: %s\n", program);
	if (**cmd != '/' && **cmd != '.')
		program = findbin(*md, *cmd);
	fprintf(stderr, "flag001: %s\n", program);
	fprintf(stderr, "flag001: %d\n", access(program, X_OK));
	if (tree->down)
		handle_redirs(tree->down, md);
	handle_pipes(tree, md);
	if (is_print_builtin(*cmd))
	{
		execute_builtin(cmd, md);
		exit(0);
	}
	else if (program && access(program, X_OK) != -1)
		execve(program, cmd, md->exported);
	else
	{
		ft_putstr_fd(ft_strjoin(*cmd, ": command not found\n"), 2);
		close(md->fd[OPIPE][WREND]);
		close(md->fd[IPIPE][RDEND]);
		exit(127);
	}
	close(md->fd[OPIPE][WREND]);
	close(md->fd[IPIPE][RDEND]);
}

void	parentproc(t_tree *tree, t_md *md)
{
	pid_t	pid;

	if (md->fd[IPIPE][RDEND] == -1 && md->fd[IPIPE][WREND] == -1)
		create_pipe(md, IPIPE);
	if (tree && tree->right && is_pipe(tree->right->tok))
		create_pipe(md, OPIPE);
	if (is_main_builtin(tree->args[0]))
		execute_builtin(tree->args, md);
	else if (is_var_definition(tree->args[0]) == 1)
		set_var(md, tree->args);
	else
	{
		pid = create_fork(md);
		if (pid == 0)
		{
			sig_default();
			childproc(tree, md);
		}
	}
	if (access("/tmp/hdoc.tmp", F_OK) == 0)
		unlink("/tmp/hdoc.tmp");
	md->fd[IPIPE][RDEND] = md->fd[OPIPE][RDEND];
	md->fd[IPIPE][WREND] = md->fd[OPIPE][WREND];
	close(md->fd[IPIPE][WREND]);
	handle_signals(md, pid);
}

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
