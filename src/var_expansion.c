/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:58:32 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/05 23:01:37 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>
#include <stdio.h>

// Returns the value of var in env array
char	*expand_var(t_var *env, char *key)
{
	t_var	*var;

	var = varfind(env, key);
	//fprintf(stderr, "flag expand_var: var=%s, value=%s\n", var->key, var->value);
	if (var)
		return (var->value);
	return (NULL);
}

void	concat_var_def_dq(t_token **tokens);

void	rebuild_dq_tokens(t_token *tokens, t_md md)
{
	t_token	*p;
	t_token	*tmp;

	tmp = tokens;
	p = tokens;
	while (p)
	{
		if (p->type == TOKEN_BLOB_DQ)
			p->value = expand_vars_in_dq(p->value, md);
		p = p->right;
	}
	p = tmp;
	concat_var_def_dq(&tokens);
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
