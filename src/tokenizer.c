// Estructura del parseo de la entrada del usuario

#include "minishell.h"

// Estructura para almacenar tokens como un nodo de un árbol binario
typedef struct s_token {
    char *value;           // El valor del token
    int type;              // Tipo de token (comando, argumento, operador, etc.)
    struct s_token *left;  // Nodo izquierdo (anterior)
    struct s_token *right; // Nodo derecho (siguiente)
} t_token;

// Funciones auxiliares
int is_special_char(char c) {
    return (c == '|' || c == '<' || c == '>' || c == '$');
}

// Crea un nuevo token
t_token *new_token(char *value, int type) {
    t_token *token = malloc(sizeof(t_token));
    if (!token)
        return NULL;
    token->value = ft_strdup(value);
    token->type = type;
    token->left = NULL;
    token->right = NULL;
    return token;
}

// Agrega un token al árbol binario
t_token *add_token(t_token **root, char *value, int type) {
    t_token *current;

    if (!(*root)) {
        *root = new_token(value, type);
    } else {
        current = *root;
        while (current->right) {
            current = current->right;
        }
		t_token *new = new_token(value, type);
		current->right = new;
		new->left = current;
    }
    return *root;
}

// Divide la entrada en tokens:
//
// Saltar espacios
// Si el caracter es un operador -> agregarlo como token
// Sino -> marcar el inicio y avanzar hasta encontrar un espacio
// 		Si despues del espacio viene un operador -> marcar el final
// 		Sino -> seguir avanzando hasta encontrar un operador o acabar el string
//		Duplicar de inicio a final
//		Agregar token como Word con la copia
//
t_token *tokenize(char *input) {
    t_token *tokens = NULL;
    int i = 0;
	char	start;
	char	*word;

    while (input[i]) {
        // Salta espacios
        while (input[i] == ' ')
            i++;

        if (input[i] == '|') {
            add_token(&tokens, "|", TOKEN_PIPE);
            i++;
        } else if (input[i] == '<') {
            if (input[i + 1] == '<') {
                add_token(&tokens, "<<", TOKEN_REDIR_HEREDOC);
                i += 2;
            } else {
                add_token(&tokens, "<", TOKEN_REDIR_IN);
                i++;
            }
        } else if (input[i] == '>') {
            if (input[i + 1] == '>') {
                add_token(&tokens, ">>", TOKEN_REDIR_APPEND);
                i += 2;
            } else {
                add_token(&tokens, ">", TOKEN_REDIR_OUT);
                i++;
            }
        } else if (input[i] == '$') {
            // Tokenización de variables de entorno
            start = i++;
            if (input[i] && (isalnum(input[i]) || input[i] == '_')) {
                while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
                    i++;
                word = ft_substr(input, start, i - start);
                add_token(&tokens, word, TOKEN_ENV_VAR);
                free(word);
            } else {
                // Maneja un '$' aislado como TOKEN_WORD
                add_token(&tokens, "$", TOKEN_WORD);
            }
        } else if (input[i]) {
            // Tokenización de palabras
            start = i;
            while (input[i] && !is_special_char(input[i]))
				i++;
            word = ft_substr(input, start, i - start);
            add_token(&tokens, word, TOKEN_WORD);
            free(word);
        }
    }
    return tokens;
}

// Imprime los tokens en orden hacia adelante (right)
void print_tokens_forward(t_token *tokens) {
    while (tokens) {
        printf("Token: %-10s Type: %d\n", tokens->value, tokens->type);
        tokens = tokens->right;
    }
}

// Imprime los tokens en orden hacia atrás (left)
void print_tokens_backward(t_token *tokens) {
    while (tokens && tokens->right) {
        tokens = tokens->right; // Ir al final del árbol
    }
    while (tokens) {
        printf("Token: %-10s Type: %d\n", tokens->value, tokens->type);
        tokens = tokens->left;
    }
}

// Libera el árbol de tokens
void free_tokens(t_token *tokens) {
    t_token *tmp;
    while (tokens) {
        tmp = tokens;
        tokens = tokens->right;
        free(tmp->value);
        free(tmp);
    }
}

int main() {
    char input[1024];
    printf("minishell> ");
    if (fgets(input, 1024, stdin)) {
        input[strcspn(input, "\n")] = '\0'; // Elimina el salto de línea
        t_token *tokens = tokenize(input);
        printf("\nTokens hacia adelante:\n");
        print_tokens_forward(tokens);
        printf("\nTokens hacia atrás:\n");
        print_tokens_backward(tokens);
        free_tokens(tokens);
    }
    return 0;
}

