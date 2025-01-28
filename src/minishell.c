#include "minishell.h"
#include <readline/readline.h>
// #include <string.h>

// TEST EXEC: BEGINING //
int main(void)
{
    t_md *md;
    char *s;

    printf("=== TEST PARSE===\n");
    s = strdup("cat Makefile | grep -i SRC | wc -l");
    printf("\nTest 1: input = <i>%s<\\i>\n", s);
    printf("flag00: HERE\n");
    md = ft_initmetadata();
    md->tok = tokenize(s);
    md->tree =
    /* printf("flag01: HERE\n"); */
    /* ft_execcmd(md); */
    /* free(s); */
    /* ft_freetree(&tree); */
    /* printf("Test 1: End\n"); */
}
// TEST EXEC: ENDING//


// TEST PARSE: BEGINING //
/* int main(void) */
/* { */
/*     t_token *tokens; */
/*     t_tree *tree; */
/*     char *s; */

/*     printf("=== TEST PARSE===\n"); */
/*     s = strdup("cat Makefile | grep -i SRC | wc -l"); */
/*     printf("\nTest 1: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     tree = buildtreestruct(tokens); */
/*     ft_printtree(tree); */
/*     free(s); */
/*     ft_freetree(&tree); */
/*     printf("Test 1: End\n"); */

/*     s = strdup("\'cat Makefile | grep -i SRC \' | wc -l"); */
/*     printf("\nTest 2: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     tree = buildtreestruct(tokens); */
/*     ft_printtree(tree); */
/*     free(s); */
/*     ft_freetree(&tree); */
/*     printf("Test 2: End\n"); */
/* } */
// TEST PARSE: ENDING//

// TEST TOKENIZE: BEGINING //
/* int main(void) */
/* { */
/*     t_token *tokens; */
/*     char *s; */

/*     printf("=== TEST TOKENIZE ===\n"); */
/*     printf("\nTest 1: input = \"\\\"cat Makefile | grep -i SRC \" | wc -l\\\"\n"); */
/*     tokens = tokenize(ft_strdup("\"cat Makefile | grep -i SRC \" | wc -l")); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     printf("Test 1: End\n"); */


/*     s = strdup("cat Makefile | grep -i SRC | wc -l | test"); */
/*     printf("\nTest 2: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     free(s); */
/*     printf("Test 2: End\n"); */

/*     s = strdup("\'cat Makefile | grep -i SRC \' | wc -l"); */
/*     printf("\nTest 3: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     free(s); */
/*     printf("Test 3: End\n"); */

/*     s = strdup("cat Makefile | grep -i SRC\\\" | wc -l | test"); */
/*     printf("\nTest 4: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     free(s); */
/*     printf("Test 4: End\n"); */

/*     s = strdup("\"cat Makefile | grep -i SRC\' \" | wc -l"); */
/*     printf("\nTest 5: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     free(s); */
/*     printf("Test 5: End\n"); */

/*     s = strdup("\"cat Makefile | grep -i SRC\\\" \" | wc -l"); */
/*     printf("\nTest 6: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     free(s); */
/*     printf("Test 6: End\n"); */

/*     s = strdup("ls < \"file1 file2\" < \'file3 file4\' < file5 < file6"); */
/*     printf("\nTest 7: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     free(s); */
/*     printf("Test 7: End\n"); */

/*     s = strdup("ls < \"file1 file2\" < \'file3 file4\' < \file5 < file6"); */
/*     printf("\nTest 7: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     free(s); */
/*     printf("Test 7: End\n"); */

/*     s = strdup("cat Makefile | grep -i SRC\" | wc -l | test"); */
/*     printf("\nTest 9: input = <i>%s<\\i>\n", s); */
/*     tokens = tokenize(s); */
/*     print_tokens_forward(tokens); */
/*     free_tokens(tokens); */
/*     free(s); */
/*     printf("Test 9: End\n"); */

/* } */
// TEST TOKENIZE: ENDING //

// TEST READLINE: BEGINING //
/* int main(void) */
/* { */
/*     char *line; */

/*     while (1) */
/*     { */
/*         line = readline("$prompt>"); */
/*         add_history(line); */
/*         printf("line: %s\n", line); */
/*         free(line); */
/*     } */
/*     return (0); */
/* } */
// TEST READLINE: ENDING //
