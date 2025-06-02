/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   handle_redir.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: iubieta- <iubieta@student.42.fr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/20 19:11:20 by iubieta-		  #+#	#+#			 */
/*   Updated: 2025/04/20 19:11:53 by iubieta-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void	read_hdoc_lines(t_tree *tree, int **fd_pipe);

void	handle_redir_in(t_tree *tree, int **fd_pipe)
{
	int	fd;

	if (fd_pipe[IPIPE][RDEND] != -1)
		close(fd_pipe[IPIPE][RDEND]);
	fd = open(*(tree->args), O_RDONLY);
	if (fd == -1)
	{
		perror("minishell");
		exit(1);
	}
	fd_pipe[IPIPE][RDEND] = fd;
}

void	handle_redir_out(t_tree *tree, int **fd_pipe)
{
	int	fd;

	if (fd_pipe[OPIPE][WREND] != -1)
		close(fd_pipe[OPIPE][WREND]);
	fd = open(*(tree->args), O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
	{
		perror("minishell");
		exit(1);
	}
	fd_pipe[OPIPE][WREND] = fd;
}

void	handle_redir_hdoc(t_tree *tree, int **fd_pipe)
{
	int		fd;

	if (fd_pipe[IPIPE][RDEND] != -1)
		close(fd_pipe[IPIPE][RDEND]);
	fd = open("/tmp/hdoc.tmp", O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
	{
		perror("minishell");
		exit(1);
	}
	fd_pipe[IPIPE][RDEND] = fd;
	read_hdoc_lines(tree, fd_pipe);
	close(fd);
	fd = open("/tmp/hdoc.tmp", O_RDONLY);
	if (fd == -1)
	{
		perror("minishell");
		exit(1);
	}
	fd_pipe[IPIPE][RDEND] = fd;
}

void	handle_redir_append(t_tree *tree, int **fd_pipe)
{
	int	fd;

	fd = open(*(tree->args), O_APPEND | O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
		fd_pipe[OPIPE][WREND] = fd;
}

void	handle_redirs(t_tree *tree, t_md *md)
{
	t_tree	*node;

	md->has_output_redir = 0;
	node = tree;
	while (node)
	{
		if (is_redir_in(node->tok))
			handle_redir_in(node->right, md->fd);
		else if (is_redir_out(node->tok))
		{
			handle_redir_out(node->right, md->fd);
			md->has_output_redir = 1;
		}
		else if (is_redir_hdoc(node->tok))
			handle_redir_hdoc(node->right, md->fd);
		else if (is_redir_append(node->tok))
		{
			handle_redir_append(node->right, md->fd);
			md->has_output_redir = 1;
		}
		node = node->right;
	}
}
