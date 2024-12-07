/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:33:30 by iubieta           #+#    #+#             */
/*   Updated: 2024/12/07 20:12:16 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void	*new_ast(char *str)
{
	char		**tokens;
	t_ast_node	root;
	
	tokens = token_spliter(str);
	root = new_ast_node(tokens, NULL);
	// CONTINUA...	
}

char **token_splitter(char *str)
{
	char **tokens;

	tokens = (char **)malloc(sizeof(char *) * (token_counter(str) + 1));
	// CONTINUA...
}
*/

int	token_counter(char *str)
{
	// SPLITEAR por delimitadores
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 1;
	while (str[i])
	{
		while (str[i] != ' ')
			i++;
		i++;
		if (str[i] == '|'
			|| str[i] == '<' || (str[i] == '<' && str[i + 1] == '<' && ++i)
			|| str[i] == '>' || (str[i] == '>' && str[i + 1] == '>' && ++i)
			|| str[i] == '$')
			count += 2;
		i++;
	}
	return (count);
}

/*
t_ast_node	new_ast_node(char **token, t_ast_node prev_node)
{
	t_ast_node node;
	
	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node.type = token_type(*token);
	node.args = ft_split(*token, ' ');
	node.left = prev_node;
	if (node.type != TOKEN_WORD)
		node.right = new_ast_node(++token, node);
}
*/

t_toktype	token_type(char *token)
{
	
	if (*token == '|')
		return (TOKEN_PIPE);
	if (*token == '<')
	{
		if (token[1] == '<')
			return (TOKEN_REDIR_HEREDOC);
		return (TOKEN_REDIR_IN);
	}
	if (*token == '>')
	{
		if (token[1] == '>')
			return (TOKEN_REDIR_APPEND);
		return (TOKEN_REDIR_OUT);
	}
	if (*token == '$')	
		return (TOKEN_ENV_VAR);
	return (TOKEN_WORD);
}

int main()
{
	printf("%i", token_counter("Hola mundo|adads<adad<<asd>add>>asdad$asdad| sbdfosbf | asjdoa > sdnao"));
}
