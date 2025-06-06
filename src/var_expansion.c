/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:58:32 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 09:18:56 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>
#include <stdio.h>

void	concat_var_def_dq(t_token **tokens);

// Returns the value of var in env array
char	*expand_var(t_var *env, char *key)
{
	t_var	*var;

	var = varfind(env, key);
	if (var)
		return (var->value);
	return (NULL);
}

char	*expand_token(char *ogs, t_md md)
{
	char	*mods;
	char	*tmp;
	
	tmp = &ogs[1];
	printf("flag ogs: %s\n", ogs);
	printf("flag tmp: %s\n", tmp);
	if (tmp[0] == '?')
		tmp = "EXIT_CODE";
	mods = expand_var(*md.env, tmp);
	printf("flag mods: %s\n", mods);
	return (mods);
}

void	rebuild_dq_tokens(t_token *tokens, t_md md)
// void	expand_tokens_vars(t_token *tokens, t_md md)
{
	t_token	*p;
	t_token	*tmp;

	tmp = tokens;
	p = tokens;
	while (p)
	{
		if (p->type == TOKEN_ENV_VAR)
			p->value = expand_token(p->value, md);
		printf("flag pvalue: %s\n", p->value);
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
