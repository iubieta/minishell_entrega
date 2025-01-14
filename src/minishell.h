#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../inc/libft/libft.h"

#define RDEND 0
#define WREND 1
#define IPIPE 0
#define OPIPE 1


// Token type enumeration
typedef enum e_toktype
{
	TOKEN_WORD,				// For commands and arguments
	TOKEN_REDIR_APPEND,		// For '>>'
	TOKEN_REDIR_OUT,		// For '>'
	TOKEN_REDIR_IN,			// For '<'
	TOKEN_REDIR_HEREDOC,	// For '<<'
	TOKEN_PIPE,				// For '|'
	TOKEN_ENV_VAR,			// For environment variables '$'
}	t_toktype;

// AST structure
typedef struct s_tree
{
	t_toktype			type;
	char				**args;
	struct s_tree *left;
	struct s_tree *right;
}	t_tree;

// Token binary tree struct
typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

// Structure pointing to key variables
typedef struct s_md
{
	struct s_tree **tree;
	int **fd;
	char ***env;
}	t_md;

//	Init
t_md	*ft_initmetadata();  // Deberia iniciarse en vacio ?? Sin tokens ni comandos.
void	ft_cleanup(t_md *metad);

// Function prototypes for tokenizer functions
t_token	*tokenize(char *input);
void	free_tokens(t_token *tokens);
t_token	*create_token(char *value, int type);
void	print_tokens(t_token *tokens, int level);
t_token *add_token(t_token **root, char *value, int type);

//	Parsing
void	parse(char *input, t_md md);
t_tree *buildtreestruct(t_token *t);
char **ft_dup2parray(char **array);

// Builtins
//void	ft_echo(t_ast_node *node);
void	ft_pwd(char **args);
void	ft_cd(char **args);
void	ft_env(char **env);
void	ft_export(char ***env_ptr, char **args);
void	ft_unset(char ***env_ptr, char **args);

// Utils
//	String utils
size_t	ft_indexof(char *str, char c);
int		is_special_char(char c);
int		count_quoted_chars(char *input);

//	2 char array utils
char	**ft_arremove(char **array, size_t del);
char	**ft_arcat(char **array, char *ptr);
size_t	ft_arlen(char **array);
void	ft_arprint(char **array);
void	ft_arfree(char **array);

//	Enviroment utils
size_t	ft_envfind(char **env, char *var);
char	*ft_expand_var(char **env, char *var);

// Tree linked list utils
void ft_freetreenode(t_tree *n);
void ft_freetree(t_tree **head);
void ft_deletetreenode(t_tree *n, t_tree **head);
void test_printtree(t_tree *tree);

#endif
