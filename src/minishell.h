/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:30:00 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 10:35:59 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../inc/libft/libft.h"

# define RDEND 0
# define WREND 1
# define IPIPE 0
# define OPIPE 1

# define VAR_SEP_CHARS "@!#$%&'()*+,-./:;<=>?[]^_`{|} \\"

// ERRORS
# define ERR_QUOTE "error detected during parsing: incorrect use of quotes"
// Token type enumeration
typedef enum e_toktype
{
	TOKEN_WORD,	
	TOKEN_BLOB_SQ,
	TOKEN_BLOB_DQ,
	TOKEN_EXPORT,
	TOKEN_VAR_DEF,
	TOKEN_ENV_VAR,
	TOKEN_REDIR_APPEND,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_HEREDOC,
	TOKEN_PIPE,
	TOKEN_UNKNOWN,
}	t_toktype;

typedef enum e_treetype
{
	TREE_CMD,
	TREE_REDIR,
	TREE_OTHER,
}	t_treetype;

// AST structure
typedef struct s_tree
{
	t_treetype		type;
	struct s_token	*tok;
	char			**args;
	char			**paths;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*down;
}	t_tree;

// Token binary tree struct
typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

typedef struct s_var
{
	char			*key;
	char			*value;
	int				exported;
	struct s_var	*next;
}	t_var;

// Structure pointing to key variables
typedef struct s_md
{
	struct s_token	**tok;
	struct s_tree	**tree;
	struct s_tree	*nodeact;
	int				**fd;
	struct s_var	**env;
	char			**exported;
	int				status;
	int				exit_code;
	char			*prompt;
	int				has_output_redir;
}	t_md;

// Tokenizer
t_token	*tokenize(char *s);
t_token	*new_token(char *value, int type);
t_token	*add_token(t_token **root, char *value, int type);
void	free_tokens(t_token *tokens);
void	free_token(t_token *token);
void	print_tokens_forward(t_token *tokens);
void	append_tokens(t_token **tokens, char **arr, char *blob, char blob_type);
void	classify_tokens(t_token **head);

// Parser
void	buildtreestruct(t_md *md);
void	recompose_tree(t_md *md);
t_tree	*buildtreenode(t_token *token, t_md *md);
char	**buildcommand(t_token *t, int words);

// Enviroment
t_var	*initenv(void);
void	printenv(t_var	*env);
t_var	strtovar(char *def, int exported);
char	*vartostr(t_var var);
char	**envtoarray(t_var *env);
void	update_env_export(t_md *md);
int		var_exists(t_var *env, t_var var);
t_var	*new_var(char *key, char *value, int exported);
t_var	*add_var(t_var *env, t_var var);
t_var	*update_var(t_var *env, t_var var);
int		key_cmp(char *k1, char *k2);
t_var	*varfind(t_var	*env, char *key);
char	*expand_var(t_var *env, char *key);

int		is_var_definition(char *str);
void	set_var(t_md *md, char **args);
char	*expand_vars_in_dq(char *ogs, t_md md);
void	rebuild_dq_tokens(t_token *tokens, t_md md);

// Init
t_md	*initmetadata(char **env);
int		**initfdarray(void);
void	cleanup(t_md *md, int mode);
void	exitwithmallocerror(t_md *md);

// Exec
void	childproc(t_tree *tree, t_md *md);
void	parentproc(t_tree *tree, t_md *md);
void	execcmd(t_md *md);
void	rightredir(t_tree *t, int fd[2][2], char **env);
void	leftredir(t_tree *t, t_md *md);

// Signals
void	sig_init(void);
void	sig_ignore(void);
void	sig_default(void);
void	sig_reset(void);

// Builtins
int		echo(char **args);
int		pwd(void);
int		cd(char **args);
// int		env(char **env);
// int		ft_export(char ***env_ptr, char **args);
// int		unset(char ***env_ptr, char **args);
int		env(char **args, char **env);
int		ft_export(t_md *md, char **args);
int		unset(t_md *md, char **args);

int		clean_exit(char **args, t_md *md);

// Utils
size_t	indexof(char *str, char c);
int		is_special_char(char c);
int		count_quoted_chars(char *input);
int		ft_strcmp(const char *s1, const char *s2);
char	*artostr(char **ar);
int		isblankline(char *line);

char	**arremove(char **array, size_t del);
char	**arcat(char **array, char *ptr);
size_t	arlen(char **array);
void	arprint(char **array);
void	arfree(char **array);

char	**ardup(char **array);

char	*findbin(t_md md, char *bin);

char	*get_prompt(t_md md);

t_token	*traverse_tokens(t_token *token, t_toktype type);
// t_token	*traverse_tokens(t_token *token);

// Tree linked list utils
void	freetreenode(t_tree *n);
void	freetree(t_tree **head);
void	deletetreenode(t_tree *n, t_tree **head);
char	**tokensto2parray(t_token *tok, t_md *md);
void	printtree(t_tree *tree, char *c);
void	printtreeinerror(t_tree *tree);

// Redir types helpers
int		is_redir(t_token *token);
int		is_lredir(t_token *token);
int		is_rredir(t_token *token);
int		is_pipe(t_token *token);

int		is_redir_in(t_token *token);
int		is_redir_hdoc(t_token *token);
int		is_redir_out(t_token *token);
int		is_redir_append(t_token *token);

// handle redirs
void	handle_redirs(t_tree *tree, t_md *md);
#endif
