/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:11:20 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/20 19:11:53 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void handle_redir_in(t_tree *tree, int **fd_pipe)
{
    int fd;

    if (fd_pipe[IPIPE][RDEND] != -1)
        close(fd_pipe[IPIPE][RDEND]);
    fd = open(*(tree->args), O_RDONLY);
    fd_pipe[IPIPE][WREND] = fd;
}

void handle_redir_out(t_tree *tree, int **fd_pipe)
{
    int fd;

    if (fd_pipe[OPIPE][WREND] != -1)
        close(fd_pipe[OPIPE][WREND]);
    fd = open(*(tree->args), O_TRUNC | O_CREAT | O_WRONLY, 0777);
    fd_pipe[OPIPE][RDEND] = fd;
	fprintf(stderr, "out redirected\n");
}

void handle_redir_hdoc(t_tree *tree, int **fd_pipe)
{

    char *end;
    char *line;



    if (fd_pipe[IPIPE][RDEND] != -1)
        close(fd_pipe[IPIPE][RDEND]);
    end = *(tree->args);
    while (1)
    {
        printf("end:%s\n", end);
        line = ft_gnl(STDIN_FILENO);
        if (ft_strncmp(end, line, ft_strlen(line)) != 0)
            return ;
        ft_putstr_fd(line, fd_pipe[IPIPE][RDEND]);
    }
}

void handle_redir_append(t_tree *tree, int **fd_pipe)
{
    int fd;

    fd = open(*(tree->args), O_APPEND | O_CREAT | O_WRONLY, 0777);
    if (fd == -1)
        perror("open error");
    fprintf(stderr, "stdout: %d, fd: %d\n", STDOUT_FILENO, fd);
    fd_pipe[OPIPE][WREND] = fd;
    fprintf(stderr, "stdout: %d, fd: %d\n", STDOUT_FILENO, fd);
}

void handle_redirs(t_tree *tree, t_md *md)
{
    t_tree *node;

    md->has_output_redir = 0;
    node = tree;
    while (node)
    {
        if (is_redir_in(node->tok))
            handle_redir_in(node->right, md->fd);
        if (is_redir_out(node->tok))
        {
            handle_redir_out(node->right, md->fd);
            md->has_output_redir = 1;
        }
        if (is_redir_hdoc(node->tok))
            handle_redir_hdoc(node->right, md->fd);
        if (is_redir_append(node->tok))
        {
            handle_redir_append(node->right, md->fd);
            md->has_output_redir = 1;
        }
        node = node->right;
    }
}
