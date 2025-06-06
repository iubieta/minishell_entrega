/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:33:22 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 09:12:23 by iubieta-         ###   ########.fr       */
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

void	fill_array_from_tokens(char **arr, t_token *cur, t_md *md)
{
	int		i;
	char	*key;

	i = 0;
	while (cur != NULL)
	{
		if (cur->type != TOKEN_ENV_VAR)
		{
			if (cur->value[1] == '?')
				arr[i] = ft_itoa(md->exit_code);
			else
				arr[i] = cur->value;
		}
		else
		{
			key = &(cur->value[1]);
			arr[i] = expand_var(*md->env, key);
		}
		cur = cur->right;
		i++;
	}
}

char	**tokensto2parray(t_token *tok, t_md *md)
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
		exitwithmallocerror(md);
	cur = tok;
	fill_array_from_tokens(arr, cur, md);
	return (arr);
}

//void	printtree(t_tree *tree, char *c)
//{
//	t_tree	*t;
//	char	**args;
//
//	t = tree;
//	while (t != NULL)
//	{
//		fprintf(stdout, "TREE NODE: p=%p, right=%p, ", t, t->right);
//		fprintf(stdout, "left=%p type: %d\n", t->left, t->type);
//		print_tokens_forward(t->tok);
//		args = t->args;
//		printf("%sargs:", c);
//		while (args)
//		{
//			if (*args)
//				printf(" %s", *args);
//			else
//				break ;
//			args++;
//		}
//		printf("\n");
//		if (t->down)
//		{
//			printf("START: printing down node\n");
//			printtree(t->down, "\t");
//			printf("FINISH: printing down node\n");
//		}
//		t = t->right;
//	}
//}
//
// void	printtreeinerror(t_tree *tree)
// {
// 	t_tree	*t;
// 	char	**args;
//
// 	t = tree;
// 	while (t != NULL)
// 	{
// 		fprintf(stderr, "TREE NODE: p=%p, right=%p, ", t, t->right);
// 		fprintf(stderr, "left=%p type: %d\n", t->left, t->type);
// 		print_tokens_forward(t->tok);
// 		args = t->args;
// 		fprintf(stderr, "args:");
// 		while (args)
// 		{
// 			if (*args)
// 				fprintf(stderr, " %s", *args);
// 			else
// 				break ;
// 			args++;
// 		}
// 		fprintf(stderr, "\n");
// 		t = t->right;
// 	}
// }
