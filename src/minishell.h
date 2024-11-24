#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>

// Token type enumeration
typedef enum e_toktype
{
    TOKEN_WORD,      // For commands and arguments
    TOKEN_PIPE,      // For '|'
    TOKEN_REDIR_IN,  // For '<'
    TOKEN_REDIR_OUT, // For '>'
    TOKEN_REDIR_APPEND, // For '>>'
    TOKEN_REDIR_HEREDOC, // For '<<'
    TOKEN_ENV_VAR, // For environment variables
}   t_toktype;

// AST structure
typedef struct s_ast_node
{
    e_toktype type;
    char **args;
    struct s_ast_node *left;
    struct s_ast_node *right;
}   t_ast_node;
