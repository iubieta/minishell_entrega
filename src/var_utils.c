/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:37:47 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/05 22:39:14 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	var_exists(t_var *env, t_var var)
{
	t_var	*cur;

	if (!env || !env->key)
		return (-1);
	cur = env;
	while (cur != NULL)
	{
		if (ft_strcmp(cur->key, var.key) == 0)
			return (1);
		cur = cur->next;
	}
	return (0);
}

t_var	strtovar(char *def, int exported)
{
	size_t	i;
	size_t	len;
	t_var	var;

	i = indexof(def, '=');
	len = ft_strlen(def);
	var.key = ft_substr(def, 0, i);
	var.value = ft_substr(def, i + 1, len);
	var.exported = exported;
	var.next = NULL;
	return (var);
}

char	*vartostr(t_var var)
{
	char	*str;
	char	*del;

	str = ft_strjoin(var.key, "=");
	del = str;
	str = ft_strjoin(str, var.value);
	free(del);
	return (str);
}
