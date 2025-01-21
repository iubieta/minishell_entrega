#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../inc/libft/libft.h"

# define RDEND 0
# define WREND 1
# define IPIPE 0
# define OPIPE 1


// ERRORS
# define ERR_QUOTE "error detected during parsing: incorrect use of quotes"
// Token type enumeration
typedef enum e_toktype
{
	TOKEN_WORD,				// For commands and arguments
	TOKEN_BLOB_SQ,	    	// For quote blocks of type `'`
	TOKEN_BLOB_DQ,  		// For quote blocks of type `"`
	TOKEN_ENV_VAR,			// For environment variables '$'
	TOKEN_REDIR_APPEND,		// For '>>' redirection
	TOKEN_REDIR_OUT,		// For '>' redirection
	TOKEN_REDIR_IN,			// For '<' redirection
	TOKEN_REDIR_HEREDOC,	// For '<<' redirection
	TOKEN_PIPE,				// For '|' redirection
	TOKEN_UNKNOWN,
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
	struct s_token **tok;
	struct s_tree **tree;
	int **fd;
	char ***env;
} t_md;

// Tokenizer
t_token	*tokenize(char *input);
int is_redir_type(t_token *token);
t_token *new_token(char *value, int type);
t_token *add_token(t_token **root, char *value, int type);
void free_tokens(t_token *tokens);
void print_tokens_forward(t_token *tokens);

// Parser
t_tree *buildtreestruct(t_token *t);
t_token *buildtreenode(t_tree *tree, t_token *t);
char **buildcommand(t_token *t, int words);

// Exec
int **initfdarray(void);
void ft_execcmd(t_md *md);
void ft_childproc(t_md *md);
void ft_cleanup(t_md *metad);
void ft_rightredir(t_tree *t, int fd[2][2], char **env);
void ft_leftredir(t_tree *t, t_md *md);
void addcat(t_tree *t);

// Init
t_md *ft_initmetadata(void);

// Builtins
// void	ft_echo(t_ast_node *node);
void	ft_pwd(char **args);
void	ft_cd(char **args);
void	ft_env(char **env);
void	ft_export(char ***env_ptr, char **args);
void	ft_unset(char ***env_ptr, char **args);

// Utils
size_t	ft_indexof(char *str, char c);
int		is_special_char(char c);
int		count_quoted_chars(char *input);

char	**ft_arremove(char **array, size_t del);
char	**ft_arcat(char **array, char *ptr);
size_t	ft_arlen(char **array);
void	ft_arprint(char **array);
void	ft_arfree(char **array);

size_t	ft_envfind(char **env, char *var);
char	*ft_expand_var(char **env, char *var);

char **ft_dup2parray(char **array);


// Tree linked list utils
void ft_freetreenode(t_tree *n);
void ft_freetree(t_tree **head);
void ft_deletetreenode(t_tree *n, t_tree **head);
void ft_printtree(t_tree *tree);

#endif
