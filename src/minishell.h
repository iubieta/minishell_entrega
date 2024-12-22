#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../inc/libft/libft.h"

// Token type enumeration
typedef enum e_toktype
{
	TOKEN_ENV_VAR, // For environment variables '$'
	TOKEN_PIPE,      // For '|'
	TOKEN_REDIR_HEREDOC, // For '<<'
	TOKEN_REDIR_IN,  // For '<'
	TOKEN_REDIR_OUT, // For '>'
	TOKEN_REDIR_APPEND, // For '>>'
	TOKEN_WORD,      // For commands and arguments
}	t_toktype;

// AST structure
typedef struct s_ast_node
{
	t_toktype			type;
	char				**args;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

// Token binary tree struct
typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

// Function prototype for reordering tokens
t_token	*reorder_tokens(t_token *tokens);

// Function prototypes for tokenizer functions
t_token	*tokenize(char *input);
void	free_tokens(t_token *tokens);
t_token	*create_token(char *value, int type);
void	print_tokens(t_token *tokens, int level);

#endif