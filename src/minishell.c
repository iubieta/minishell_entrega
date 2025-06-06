/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:04:07 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 09:35:52 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

int	isblankline(char *line)
{
	while (*line != '\0')
	{
		if (*line != ' ' && (*line < '\a' || *line > '\r'))
			return (0);
		line++;
	}
	return (1);
}

void	interactive_mode(t_md *md)
{
	char	*input;

	ft_putstr_fd("Hello from minishell!\n", 2);
	while (1)
	{
		sig_init();
		md->prompt = get_prompt(*md);
		input = readline(md->prompt);
		if (!input)
			clean_exit(NULL, md);
		if (input[0] && !isblankline(input))
		{
			add_history(input);
			*(md->tok) = tokenize(input);
			print_tokens_forward(*md->tok);
			rebuild_dq_tokens(*(md->tok), *md);
			buildtreestruct(md);
			printtreeinerror(*md->tree);
			recompose_tree(md);
			execcmd(md);
			cleanup(md, 0);
		}
	}
}

void	command_mode(t_md *md, char *input)
{
	fprintf(stderr, "Hello and goodbye from minishell!\n");
	*(md->tok) = tokenize(input);
	buildtreestruct(md);
	recompose_tree(md);
	execcmd(md);
}

int	main(int argc, char **argv, char **env)
{
	t_md	*md;

	md = initmetadata(env);
	if (argc == 1)
		interactive_mode(md);
	else
		command_mode(md, artostr(++argv));
}
