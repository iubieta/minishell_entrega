/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:21:23 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/20 20:08:05 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	clean_exit(char **args, t_md *md)
{
	int	i;

	printf("exit\n");
	if (arlen(args) < 2)
		exit(0);
	if (arlen(args) > 2)
	{
		md->exit_code = 1;
		return (ft_putstr_fd("minishell: exit: too many arguments\n", 2), 1);
	}
	i = 0;
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
		{
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
			md->exit_code = 2;
			exit(2);
		}
		i++;
	}
	cleanup(md, 1);
	md->exit_code = ft_atoi(args[1]);
	exit(ft_atoi(args[1]));
}
