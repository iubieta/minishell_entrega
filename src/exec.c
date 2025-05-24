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
int		is_builtin(char *cmd);

void	childproc(t_tree *tree, t_md *md)
{
	char	**cmd;
	int		**fd;
	t_tree	*next;
	//char	program[256];
	char	*program;

	sig_reset();
	fd = md->fd;
	cmd = tree->args;
	next = tree->right;
	program = *cmd;
	if (**cmd != '/' && **cmd != '.')
		program = findbin(*md, *cmd);
	if (tree->down)
		handle_redirs(tree->down, md);
	if (fd[IPIPE][WREND] != -1)
	{
		dup2(fd[IPIPE][WREND], STDIN_FILENO);
		close(fd[IPIPE][WREND]);
	}
	if (next || md->has_output_redir == 1)
		dup2(fd[OPIPE][RDEND], STDOUT_FILENO);
	close(fd[OPIPE][WREND]);
	// printf("bin=%s\n", program);
	if (program)
		execve(program, cmd, md->exported);
	else
	{
		ft_putstr_fd("Command not found\n", 2);
		exit(127);
	}
	close(fd[OPIPE][WREND]);
}

void	parentproc(t_tree *tree, t_md *md)
{
	pid_t	pid;
	int		status;

	if (tree && tree->right && is_pipe(tree->right->tok))
	{
		if (pipe(md->fd[OPIPE]) == -1)
			cleanup(md);
	}
	if (is_builtin(tree->args[0]))
		execute_builtin(tree->args, md);
	else if (is_var_definition(tree->args[0]) == 1)
	{
		// printf("Var definition\n");
		set_var(md, tree->args[0]);
	}
	else
	{
		pid = fork();
		sig_ignore();
		if (pid == -1)
			cleanup(md);
		if (pid == 0)
		{
			sig_default();
			childproc(tree, md);
		}
	}
	md->fd[IPIPE][RDEND] = md->fd[OPIPE][RDEND];
	md->fd[IPIPE][WREND] = md->fd[OPIPE][WREND];
	close(md->fd[IPIPE][WREND]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		md->exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		md->exit_code = 128 + WTERMSIG(status);
	else
		md->exit_code = 1; // valor por defecto si nada aplica
}

int is_builtin(char *cmd)
{
    return (!ft_strcmp(cmd, "cd") || 
			!ft_strcmp(cmd, "export") ||
			!ft_strcmp(cmd, "unset") ||
            !ft_strcmp(cmd, "env") || 
			!ft_strcmp(cmd, "exit") || 
			//!ft_strcmp(cmd, "echo") ||
            !ft_strcmp(cmd, "pwd"));
}

void execute_builtin(char **args, t_md *md)
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
		clean_exit(md);
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
		{
			//fprintf(stderr, "this is stderror\n");
			/* printtree(tree); */
			//if (is_builtin(tree->args[0]))
				//execute_builtin(tree->args, md);
			parentproc(tree, md);
			// Buscar como implementar builtins sin forkear
		}
		tree = tree->right;
	}

	/* t_tree *n; */

	/* md->nodeact = *(md->tree); */
	/* n = md->nodeact; */
	/* while (is_lredir(n->right->tok) || is_rredir(n->right->tok)) */
	/* { */


	/* } */


	/* while (md->nodeact) */
	/* 	parentproc(md->nodeact, md); */
}
