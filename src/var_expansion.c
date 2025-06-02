/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:58:32 by iubieta-          #+#    #+#             */
/*   Updated: 2025/05/30 18:46:46 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

// Returns the value of var in env array
char	*expand_var(t_var *env, char *key)
{
	t_var	*var;
	
	var = varfind(env, key);
	if (var)
		return (var->value);
	return (NULL);
}

char	*build_expanded_str(char *str, t_md md)
{
	char *splited_var[3];
	int	separator;
	int	i;
	int tmp;

	separator = indexof(str, '\0');
	i = 0;
	while (VAR_SEP_CHARS[i])
	{
		tmp = indexof(str, VAR_SEP_CHARS[i++]);
		if (tmp < separator)
			separator = tmp;
	}
	splited_var[0] = ft_substr(str, 0, separator);
	splited_var[1] = ft_strdup(str + separator);
	splited_var[2] = expand_var(*md.env, splited_var[0]);
	free(str);
	str = ft_strjoin(splited_var[2], splited_var[1]);
	free(splited_var[0]);
	free(splited_var[1]);
	free(splited_var[2]);
	return (str);
}

char	*expand_vars_in_dq(char *ogs, t_md md)
{
	char	*mods;
	char	**array;
	char	*tmp;
	int		i;
	
	array = ft_split(ogs, '$');
	i = 1;
	if (*ogs == '$')
		i = 0;
	while (array[i])
	{
		array[i] = build_expanded_str(array[i], md);
		i++;
	}
	i = 0;
	mods = ft_strdup("");
	while (array[i])
	{
		tmp = ft_strjoin(mods, array[i++]);
		mods = tmp;
		free(tmp);
	}
	return (mods);
}

void	rebuild_dq_tokens(t_token *tokens, t_md md)
{
	t_token	*p;

	p = tokens;
	while (p)
	{
		if (p->type == TOKEN_BLOB_DQ)
			expand_vars_in_dq(p->value, md);
		p = p->right;
	}
}

// char	*expand_vars_in_dq(char *ogs, t_md md)
// {
// 	char	*mods;
// 	char	**array;
// 	char	*tmp;
// 	int		i;
// 	
// 	array = ft_split(ogs, '$');
// 	mods = array[0];
// 	// arprint(array);
// 	i = 1;
// 	if (*ogs == '$')
// 		i = 0;
// 	while (array[i])
// 	{
// 		array[i] = build_expanded_str(array[i], md);
// 		i++;
// 		if (i != 0)
// 			tmp = ft_strjoin(mods, array[i]);
// 		mods = tmp;
// 		free(tmp);
// 	}
// 	return ();
// }

