/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:33:22 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/22 17:40:05 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freetreenode(t_tree *n)
{
	if (n->args != NULL)
		ft_free2parray(n->args);
	n->args = NULL;
	return ;
}

void	ft_freetree(t_tree **head)
{
	t_tree	*cur;
	t_tree	*tmp;

	cur = *head;
	while (cur->right)
	{
		tmp = cur;
		cur = cur->right;
		ft_freetreenode(tmp);
	}
	head = NULL;
	return ;
}

void	ft_deletetreenode(t_tree *n, t_tree **head)
{
	t_tree	*cur;
	t_tree	*tmp;

	cur = *head;
	while (cur->right != n)
		cur = cur->right;
	tmp = n->right;
	ft_freetreenode(n);
	cur->right = tmp;
	return ;
}

char	**ft_tokensto2parray(t_token *tok, t_md *md)
{
	t_token	*cur;
	int		i;
	char	**arr;

	if (is_redir(tok))
		return (NULL);
	cur = tok;
	i = 1;
	while (cur != NULL)
	{
		i++;
		cur = cur->right;
	}
	arr = (char **)ft_calloc(i + 1, sizeof(char *));
	if (arr == NULL)
		ft_exitwithmallocerror(md);
	cur = tok;
	i = 0;
	while (cur)
	{
		arr[i] = cur->value;
		cur = cur->right;
		i++;
	}
	return (arr);
}

void	ft_printtree(t_tree *tree)
{
	t_tree	*t;
	char	**args;

	t = tree;
	while (t != NULL)
	{
		printf("TREE NODE: p=%p, right=%p, left=%p\n", t, t->right, t->left);
		printf("type: %d\n", t->type);
		print_tokens_forward(t->tok);
		args = t->args;
		printf("args:");
		while (args)
		{
			if (*args)
				printf(" %s", *args);
			else
				break ;
			args++;
		}
		printf("\n");
		t = t->right;
	}
}

void	ft_printtreeinerror(t_tree *tree)
{
	t_tree	*t;
	char	**args;

	t = tree;
	while (t != NULL)
	{
		fprintf(stderr, "TREE NODE: p=%p, right=%p, left=%p\n", t, t->right, t->left);
		fprintf(stderr, "type: %d\n", t->type);
		print_tokens_forward(t->tok);
		args = t->args;
		fprintf(stderr, "args:");
		while (args)
		{
			if (*args)
				fprintf(stderr, " %s", *args);
			else
				break ;
			args++;
		}
		fprintf(stderr, "\n");
		t = t->right;
	}
}
