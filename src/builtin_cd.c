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

	if (!args || !args[1])
	{
		path = getenv("HOME");
		chdir(path);
		return ;
	}
	if (args[2])
	{
		printf("cd: too many arguments\n");
		return ;
	}
	path = args[1];
	if (chdir (path) == -1)
		perror("cd");
}

// TEST
// int main() 
// {
// 	char *home[] = {"cd", "/home", NULL};
// 	char *args[1024];
// 
// 	// Comprobacion sin argumentos
// 	printf("--TEST 1--\n");
// 	ft_cd(home);
// 	ft_pwd(NULL);
// 	ft_cd(NULL);
// 	ft_pwd(NULL);
// 
// 	//Comprobacion con argumentos
// 	printf("--TEST 2--\n");
// 	ft_cd(home);
// 	ft_pwd(NULL);
// 	args[0] = "cd";
// 	ft_cd(args);
// 	ft_pwd(NULL);
// 
// 	printf("--TEST 3--\n");
// 	ft_cd(home);
// 	ft_pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = NULL;
// 	ft_cd(args);
// 	ft_pwd(NULL);
// 
// 	printf("--TEST 4--\n");
// 	ft_cd(home);
// 	ft_pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = ".";
// 	args[2] = NULL;
// 	ft_cd(args);
// 	ft_pwd(NULL);
// 
// 	printf("--TEST 5--\n");
// 	ft_cd(home);
// 	ft_pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = "..";
// 	args[2] = NULL;
// 	ft_cd(args);
// 	ft_pwd(NULL);
// 
// 	printf("--TEST 6--\n");
// 	ft_cd(home);
// 	ft_pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = "/etc";
// 	args[2] = NULL;
// 	ft_cd(args);
// 	ft_pwd(NULL);
// 
// 	printf("--TEST 7--\n");
// 	ft_cd(home);
// 	ft_pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = "sadjhla";
// 	args[2] = NULL;
// 	ft_cd(args);
// 	ft_pwd(NULL);
// 
// 	printf("--TEST 8--\n");
// 	ft_cd(home);
// 	ft_pwd(NULL);
// 	args[0] = "cd";
// 	args[1] = "/home";
// 	args[2] = "sadjhla";
// 	args[3] = NULL;
// 	ft_cd(args);
// 	ft_pwd(NULL);
// 
// }
