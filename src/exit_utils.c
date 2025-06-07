/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:49:23 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/07 02:51:56 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_exit_code_var(int codenum, t_md *md)
{
	t_var *var;
	char *varstr;

	varstr = ft_strjoin(ft_strdup("EXIT_CODE="), ft_itoa(codenum));
	var = strtovar(varstr, 0);
	if (var_exists(*md->env, var))
		update_var(*md->env, var);
	else
		add_var(*md->env, var);
}
