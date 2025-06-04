/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:33:22 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/20 22:09:33 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	freetreenode(t_tree *n)
{
	if (n->args != NULL)
		ft_free2parray(n->args);
	n->args = NULL;
	return ;
}

void	freetree(t_tree **head)
{
	t_tree	*cur;
	t_tree	*tmp;

	cur = *head;
	while (cur->right)
	{
		tmp = cur;
		cur = cur->right;
		freetreenode(tmp);
	}
	head = NULL;
	return ;
}

void	deletetreenode(t_tree *n, t_tree **head)
{
	t_tree	*cur;
	t_tree	*tmp;

	cur = *head;
	while (cur->right != n)
		cur = cur->right;
	tmp = n->right;
	freetreenode(n);
	cur->right = tmp;
	return ;
}

char	**tokensto2parray(t_token *tok, t_md *md)
{
	t_token	*cur;
	int		i;
	char	**arr;
	char	*key;

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
		exitwithmallocerror(md);
	cur = tok;
	i = 0;
	while (cur != NULL)
	{
		if (cur->type != TOKEN_ENV_VAR)
			if (cur->value[1] == '?')
				arr[i] = ft_itoa(md->exit_code);
			else
				arr[i] = cur->value;
		else
		{
			key = &(cur->value[1]);
			fprintf(stderr, "flag key: %s\n", key); 
			arr[i] = expand_var(*md->env, key);
		}
		cur = cur->right;
		i++;
	}
	return (arr);
}

void	printtree(t_tree *tree, char *c)
{
	t_tree	*t;
	char	**args;

	t = tree;
	while (t != NULL)
	{
		printf("%sTREE NODE: p=%p, right=%p, left=%p\n", c, t, t->right, t->left);
		printf("%stype: %d\n", c, t->type);
		print_tokens_forward(t->tok);
		args = t->args;
		printf("%sargs:", c);
		while (args)
		{
			if (*args)
				printf(" %s", *args);
			else
				break ;
			args++;
		}
		printf("\n");
		if (t->down)
		{
			printf("START: printing down node\n");
			printtree(t->down, "\t");
			printf("FINISH: printing down node\n");
		}
		t = t->right;
	}
}

void	printtreeinerror(t_tree *tree)
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
