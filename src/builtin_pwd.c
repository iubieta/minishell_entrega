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

void	ft_pwd()
{
	char *current_dir;
	
	current_dir = getcwd(NULL, 0);
	printf("%s\n", current_dir);
}

// TEST
int main()
{
	ft_pwd();
}
