#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>

// Token type enumeration
typedef enum e_token_type
{
    TOKEN_WORD,      // For commands and arguments
    TOKEN_PIPE,      // For '|'
    TOKEN_REDIR_IN,  // For '<'
    TOKEN_REDIR_OUT, // For '>'
    TOKEN_REDIR_APPEND, // For '>>'
    TOKEN_REDIR_HEREDOC, // For '<<'
    TOKEN_ENV_VAR, // For environment variables
}   t_token_type;

// Token structure
typedef struct s_token
{
    t_token_type type;
    char        *value;
    struct s_token *next;
}   t_token;
