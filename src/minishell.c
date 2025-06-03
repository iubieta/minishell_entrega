/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:04:07 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/20 22:09:01 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

void interactive_mode(t_md *md)
{
	char	*input;

	fprintf(stderr, "Hello from minishell!\n");
	while (1)
	{
		sig_init();
		md->prompt = get_prompt(*md);
		input = readline(md->prompt);
		
		// printf("input: %s\n", input);
		if (!input)
		{ 
			printf("exit\n");
			break;
		}
		if (input[0] && !isblankline(input))
		{
			add_history(input);
			*(md->tok) = tokenize(input);
			// print_tokens_forward(*(md->tok)); 
			rebuild_dq_tokens(*(md->tok), *md);
			// print_tokens_forward(*(md->tok)); 
			buildtreestruct(md);
			recompose_tree(md);
			// printtreeinerror(*(md->tree)); 
			execcmd(md);
			cleanup(md, 0);
			// md = ft_initmetadata();
		}
	} 
	free(md);
	md = NULL;
}

void command_mode(t_md *md, char *input)
{
	fprintf(stderr, "Hello and goodbye from minishell!\n");
	// printf("%s\n", input);
	*(md->tok) = tokenize(input);
	// print_tokens_forward(*(md->tok)); 
	buildtreestruct(md);
	recompose_tree(md);
	printtreeinerror(*(md->tree));
	execcmd(md);
	// cleanup(md, 1);
	// md = ft_initmetadata();
}

int	main(int argc, char **argv, char **env)
{ 
	t_md	*md;

	md = initmetadata(env);
	//printenv(*md->env);
	// arprint(envtoarray(*md->env));
	if (argc == 1)
		interactive_mode(md);
	else
		command_mode(md, artostr(++argv));
} 

