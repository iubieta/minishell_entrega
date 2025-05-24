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

int	main(int argc, char **argv, char **env)
{ 
	t_md	*md;
	char	*input;

	md = initmetadata(env);
	//printenv(*md->env);
	// arprint(envtoarray(*md->env));
	if (argc == 1)
	{
		printf("Hello from minishell!\n");
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
			if (input[0])
			{
				add_history(input);
				*(md->tok) = tokenize(input);
				// print_tokens_forward(*(md->tok)); 
				buildtreestruct(md);
				recompose_tree(md);
				printtree(*(md->tree));
				execcmd(md);
				// cleanup(md);
				// md = ft_initmetadata();
			}
			// printf("1\n");
			// print_tokens_forward(*(md->tok)); 
			// printf("2\n");
			// if (md->tree)
			// 	printtree(*(md->tree));
		} 
	}
	else
	{
		printf("Hello and goodbye from minishell!\n");
		input = artostr(++argv);
		// printf("%s\n", input);
		*(md->tok) = tokenize(input);
		// print_tokens_forward(*(md->tok)); 
		buildtreestruct(md);
		// printtree(*(md->tree));
		// execcmd(md);
		// cleanup(md);
		// md = ft_initmetadata();
	}
} 
