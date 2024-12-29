/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:19:09 by iubieta           #+#    #+#             */
/*   Updated: 2024/12/24 18:48:41y iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Utils 
int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '$');
}

t_token	*new_token(char *value, int type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	token->type = type;
	token->left = NULL;
	token->right = NULL;
	return (token);
}

t_token	*add_token(t_token **root, char *value, int type)
{
	t_token	*current;
	t_token	*new;

	if (!(*root))
		*root = new_token(value, type);
	else
	{
		current = *root;
		while (current->right)
			current = current->right;
		new = new_token(value, type);
		current->right = new;
		new->left = current;
	}
	return (*root);
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->right;
		free(tmp->value);
		free(tmp);
	}
}

// Tokenizer functions
int	add_redir_token(char *input, t_token **tokens)
{
	int	i;

	i = 0;
	if (input[i] == '<')
	{
		if (input[i + 1] == '<')
		{
			add_token(tokens, "<<", TOKEN_REDIR_HEREDOC);
			return (2);
		}
		add_token(tokens, "<", TOKEN_REDIR_IN);
		i++;
	}
	else if (input[i] == '>')
	{
		if (input[i + 1] == '>')
		{
			add_token(tokens, ">>", TOKEN_REDIR_APPEND);
			return (2);
		}
		add_token(tokens, ">", TOKEN_REDIR_OUT);
		i++;
	}
	return (i);
}

int	add_env_var_token(char *input, t_token **tokens)
{
	int	i;
	char	start;
	char	*word;

	i = 0;
	if (input[i] == '$')
	{
		start = i++;
		if (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
		{
			while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
				i++;
			word = ft_substr(input, start, i - start);
			add_token(tokens, word, TOKEN_ENV_VAR);
			free(word);
		}
		else
		{
			add_token(tokens, "$", TOKEN_WORD);
			i++;
		}
	}
	return (i);
}

int count_quoted_chars(char *input)
{
	int		i;
	char	c;

	i = 0;
	if (input[i] == '"' || input[i] == '\'')
	{
		c = input[i++];
		while (input[i] && input[i] != c)
			i++;
	}
	return (i);
}

int	add_word_token(char *input, t_token **tokens)
{
	int		i;
	int		start;

	i = 0;
	if (input[i])
	{
		start = i;
		if (input[i] == '"' || input[i] == '\'')
		{
			i += count_quoted_chars(&input[i]);
			start++;
		}
		else
		{
			while (input[i] && input[i] != ' ' && !is_special_char(input[i]))
			{
				if (input[i] == '\\')
					i++;
				i++;
			}
		}
		add_token(tokens, ft_substr(input, start, i - start), TOKEN_WORD);
	}
	return (++i);
}

// Tokenizer:
t_token	*tokenize(char *input)
{
	t_token	*tokens;
	int		i;
	int		j;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i] == ' ')
			i++;
		if (input[i] == '|')
		{
			add_token(&tokens, "|", TOKEN_PIPE);
			j = 1;
		}
		if (j == 0)
			j = add_redir_token(&input[i], &tokens);
		if (j == 0)
			j = add_env_var_token(&input[i], &tokens);
		if (j == 0)
			j = add_word_token(&input[i], &tokens);
		i += j;
	}
	return (tokens);
}

// COMPROBACION

// Imprime los tokens en orden hacia adelante (right)
void print_tokens_forward(t_token *tokens) {
    while (tokens) {
        printf("Token: %-10s Type: %d\n", tokens->value, tokens->type);
        tokens = tokens->right;
    }
}

//int main() {
    //char input[1024];
    //printf("minishell> ");
    //if (fgets(input, 1024, stdin)) {
        //input[strcspn(input, "\n")] = '\0'; // Elimina el salto de línea
        //t_token *tokens = tokenize(input);
        //printf("\nTokens hacia adelante:\n");
        //print_tokens_forward(tokens);
        //free_tokens(tokens);
    //}
    //return 0;
//}
