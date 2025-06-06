/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion_dq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:53:34 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/06 09:18:04 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*build_expanded_str(char *str, t_md md)
{
	char	*splited_var[3];
	int		separator;
	int		i;
	int		tmp;

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
		free(mods);
		mods = tmp;
	}
	return (mods);
}

char	*build_var_def_dq_str(t_token *t1, t_token *t2)
{
	char	*r;
	int		rlen;

	rlen = ft_strlen(t1->value) + ft_strlen(t2->value) + 1;
	r = (char *)ft_calloc(rlen, sizeof(char));
	ft_strlcat(r, t1->value, rlen);
	ft_strlcat(r, t2->value, rlen);
	return (r);
}

void	update_var_with_dq_str(t_token	*p)
{
	t_token	*tmp;
	char	*catstr;

	catstr = build_var_def_dq_str(p, p->right);
	tmp = p->right;
	free(p->value);
	p->value = catstr;
	p->right = tmp->right;
	free_token(tmp);
}

void	concat_var_def_dq(t_token **tokens)
{
	t_token	*p;

	p = *tokens;
	while (p->right)
	{
		if (p->type != TOKEN_VAR_DEF || p->right == NULL)
		{
			p = p->right;
			continue ;
		}
		else if (p->right->type != TOKEN_BLOB_SQ
			&& p->right->type != TOKEN_BLOB_DQ)
		{
			p = p->right;
			continue ;
		}
		else
			update_var_with_dq_str(p);
		if (p->right)
			p = p->right;
	}
}
