/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:32:57 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/01 23:33:02 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int add_redir_token(char *input, t_token **tokens);
int add_env_var_token(char *input, t_token **tokens);
int add_word_token(char *input, t_token **tokens);

t_token *tokenize(char *input)
{
  t_token *tokens;
  int i;
  int j;

  tokens = NULL;
  i = 0;
  while (input[i]) {
    j = 0;
    while (input[i] == ' ')
      i++;
    if (input[i] == '|') {
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

int add_redir_token(char *input, t_token **tokens)
{
  int i;

  i = 0;
  if (input[i] == '<') {
    if (input[i + 1] == '<') {
      add_token(tokens, "<<", TOKEN_REDIR_HEREDOC);
      return (2);
    }
    add_token(tokens, "<", TOKEN_REDIR_IN);
    i++;
  } else if (input[i] == '>') {
    if (input[i + 1] == '>') {
      add_token(tokens, ">>", TOKEN_REDIR_APPEND);
      return (2);
    }
    add_token(tokens, ">", TOKEN_REDIR_OUT);
    i++;
  }
  return (i);
}

int add_env_var_token(char *input, t_token **tokens)
{
  int i;
  char start;
  char *word;

  i = 0;
  if (input[i] == '$') {
    start = i++;
    if (input[i] && (ft_isalnum(input[i]) || input[i] == '_')) {
      while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
        i++;
      word = ft_substr(input, start, i - start);
      add_token(tokens, word, TOKEN_ENV_VAR);
      free(word);
    } else {
      add_token(tokens, "$", TOKEN_WORD);
      i++;
    }
  }
  return (i);
}

int add_word_token(char *input, t_token **tokens)
{
  int i;
  int start;

  i = 0;
  if (input[i]) {
    start = i;
    if (input[i] == '"' || input[i] == '\'') {
      i += count_quoted_chars(&input[i]);
      start++;
    } else {
      while (input[i] && input[i] != ' ' && !is_special_char(input[i])) {
        if (input[i] == '\\')
          i++;
        i++;
      }
    }
    add_token(tokens, ft_substr(input, start, i - start), TOKEN_WORD);
  }
  return (i);
}

// TEST
// int main()
// {
//   char input[1024];
//   printf("minishell> ");
//   if (fgets(input, 1024, stdin)) {
//     input[strcspn(input, "\n")] = '\0'; // Elimina el salto de línea
//     t_token *tokens = tokenize(input);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//   }
//   return 0;
// }
