/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_definition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:08:20 by iubieta-          #+#    #+#             */
/*   Updated: 2025/05/06 20:38:36 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_var_definition(char *str)
{
	char	*equal;

	if (!str)
		return (0);
	if (!ft_isalpha(str[0]))
		return (0);
	if(!ft_strchr(str, '='))
		return (0);
	equal = ft_strchr(str, '=');
	// if (!equal || !equal[1])
	if (!equal) 
		return (0);
	return (1);
}

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

void set_var(t_md *md, char **args)
{
	t_var	var;

	var = strtovar(args[0], 0);
	fprintf(stderr, "flag100: %s, %s, %d\n", var.key, var.value, var.exported);
	if (ft_strncmp(var.value, "", 1) == 0)
	{
		var.value = "";
		update_var(*md->env, var);
		return ;
	}
	if (var_exists(*md->env, var) == 1)
		update_var(*md->env, var);
	else
		add_var(*md->env, var);
	printenv(*md->env); //flag
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

t_var	*update_var(t_var *env, t_var var)
{
	t_var	*cur;

	if (!env || !env->key)
	{
		env = new_var(var.key, var.value, var.exported);
		return (env);
	}
	cur = env;
	while (cur->next != NULL && ft_strcmp(cur->key, var.key) != 0)
		cur = cur->next;
	free(cur->value);
	cur->value = var.value;
	return (env);
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
