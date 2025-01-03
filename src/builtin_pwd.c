/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:16:20 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/02 13:25:00 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **args)
{
	char *current_dir;

	if (args && args[1])
	{
		printf("pwd: too many arguments\n");
		return ;
	}

	current_dir = getcwd(NULL, 0);
	printf("%s\n", current_dir);
}

// TEST
// int main()
// {
// 	char *args[3];
// 
// 	printf("--TEST 1--\n");
// 	ft_pwd(NULL);
// 
// 	printf("--TEST 2--\n");
// 	args[0] = NULL;
// 	ft_pwd(args);
// 
// 	printf("--TEST 3--\n");
// 	args[0] = "pwd";
// 	args[1] = NULL;
// 	ft_pwd(args);
// 
// 	printf("--TEST 4--\n");
// 	args[0] = "pwd";
// 	args[1] = ".";
// 	args[2] = NULL;
// 	ft_pwd(args);
// 
// }
