/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   handle_redir.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: iubieta- <iubieta@student.42.fr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/20 19:11:20 by iubieta-		  #+#	#+#			 */
/*   Updated: 2025/04/20 19:11:53 by iubieta-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void	read_hdoc_lines(t_tree *tree, int **fd_pipe)
{
	char	*end;
	char	*line;

	end = *(tree->args);
	while (1)
	{
		line = ft_gnl(STDIN_FILENO);
		if (ft_strncmp(end, line, ft_strlen(line) - 1) == 0)
			break ;
		ft_putstr_fd(line, fd_pipe[IPIPE][RDEND]);
	}
}
