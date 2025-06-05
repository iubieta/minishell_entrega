/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:19:09 by iubieta           #+#    #+#             */
/*   Updated: 2025/05/24 14:07:03 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Initializes new tree node to defaults
void	inittreenode(t_tree *node, t_md *md)
{
	node->args = tokensto2parray(node->tok, md);
	node->left = NULL;
	node->down = NULL;
	node->right = NULL;
}

t_tree	*buildtreenode(t_token *token, t_md *md)
{
	t_tree	*node;

	if (!token)
		return (NULL);
	node = (t_tree *)malloc(sizeof(t_tree));
	if (node == NULL)
		exitwithmallocerror(md);
	node->tok = token;
	if (is_redir(token))
		node->type = TREE_REDIR;
	else
	{
		node->type = TREE_CMD;
		token = traverse_tokens(token);
	}
	*(md->tok) = token->right;
	token->right = NULL;
	inittreenode(node, md);
	return (node);
}

// Appends a pair of redir node and its argument to the down position of
// previous node. Used to build redir_command linked list
void	next_pair_to_down(t_tree *node)
{
	t_tree	*next;
	t_tree	*p;

	if (!(node->right))
		return ;
	next = node->right;
	p = node->down;
	if (p)
	{
		while (p->right)
			p = p->right;
		p->right = next;
	}
	else
		p = next;
	if (next->right)
		next = next->right;
	if (next->right)
		node->right = next->right;
	else
		node->right = NULL;
	next->right = NULL;
	if (!node->down)
		node->down = p;
}

/*
 * This function aims to reorganize the tree to accomodate
 * left redirs into an orthogonal direction
 */
void	recompose_tree(t_md *md)
{
	t_tree	*node;
	t_token	*tok;

	node = *(md->tree);
	while (node)
	{
		tok = NULL;
		if (node->right)
			tok = node->right->tok;
		while (is_redir(tok) && !is_pipe(tok))
		{
			next_pair_to_down(node);
			tok = NULL;
			if (node->right)
				tok = node->right->tok;
		}
		node = node->right;
	}
}

void	buildtreestruct(t_md *md)
{
	t_tree	*node;
	t_tree	*tmp;

	tmp = NULL;
	while (*(md->tok) != NULL)
	{
		node = buildtreenode(*(md->tok), md);
		if (!tmp)
			*(md->tree) = node;
		else
		{
			tmp->right = node;
			node->left = tmp;
		}
		tmp = node;
	}
}
