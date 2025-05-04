/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:59:03 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/24 22:37:39 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

t_var	*initenv()
{
	extern char	**environ;
	t_var	*env;
	t_var	var;
	size_t	i;
	
	env = (t_var *)malloc(sizeof(t_var));
	i = 0;
	while (environ && environ[i])
	{
		var = strtovar(environ[i], 1);
		env = add_var(env, var);
		i++;
	}
	// printenv(env);
	return (env);
}

void	printenv(t_var	*env)
{
	t_var	*cur;
	int	i;

	cur = env;
	i = 1;
	while (cur)
	{
		printf("Var %i: key = %s, value = %s, exported = %i\n", i, cur->key, cur->value, cur->exported);
		cur = cur->next;
		i++;
	}
}

t_var	strtovar(char *def, int exported)
{
	size_t	i;
	size_t	len;
	t_var	var;
	
	i = indexof(def, '=');
	len = ft_strlen(def);
	var.key = ft_substr(def, 0, i);
	var.value = ft_substr(def, i+1, len);
	var.exported = exported;
	var.next = NULL;
	return(var);
}

t_var	*new_var(char *key, char *value, int exported)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	var->key = key;
	var->value = value;
	var->exported = exported;
	var->next = NULL;
	return (var);
}

t_var	*add_var(t_var *env, t_var var)
{
	t_var	*cur;

	if (!env || !env->key)
	{
		env = new_var(var.key, var.value, var.exported);
		return (env);
	}
	cur = env;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_var(var.key, var.value,	var.exported);
	return (env);
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

char	**envtoarray(t_var *env)
{
	char **ar;
	t_var	*cur;
	size_t	len;
	size_t	i;

	len = 0;
	cur = env;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	ar = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	cur = env;
	while (cur)
	{
		ar[i] = vartostr(*cur);
		cur = cur->next;
		i++;
	}
	return (ar);
}

char	*expand_var(t_var *env, char *key)
{
	t_var	*var;
	
	var = varfind(env, key);
	if (var)
		return (var->value);
	return (NULL);
}


int	key_cmp(char *k1, char *k2)
{
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(k1);
	l2 = ft_strlen(k2);
	if (l1 == l2 && ft_strncmp(k1, k2, l1) == 0)
		return (0);
	return (1);
}

t_var	*varfind(t_var	*env, char *key)
{
	t_var	*cur;

	if (!env || !key)
		return (NULL);
	cur = env;
	while (cur)
	{
		if (key_cmp(cur->key, key) == 0)
			return(cur);
		cur = cur->next;
	}
	return (NULL);
}

