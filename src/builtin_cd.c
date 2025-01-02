/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:27:13 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/02 13:59:52 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **args)
{
	char	*path;

	if (!args)
	{
		path = getenv("HOME");
		chdir(path);
		return ;
	}
	if (args[1])
	{
		printf("cd: too many arguments\n");
		return ;
	}
	path = args[0];
	chdir (path);
}

// TEST
int main()
{
	char *input;
	char *args[1024];
	int i;

	ft_pwd();
	i = 0;
	input = readline("path>");
	while (input != NULL)
	{
		args[i++] = input;
		input = readline("path>");
	}
	ft_cd(args);
	ft_pwd();
}
