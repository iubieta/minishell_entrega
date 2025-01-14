#include "minishell.h"
#include <readline/readline.h>
// #include <string.h>

int main()
{
	t_md	md;
    char	*line;

	ft_initmetadata();
    while (1)
    {
        line = readline("$prompt>");
        add_history(line);
        parse(line, md);
		test_printtree(*md.tree);
		ft_cleanup(&md);
        free(line);
    }
    return (0);
}
