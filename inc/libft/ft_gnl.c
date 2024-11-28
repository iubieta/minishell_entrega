/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:31:53 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/12 10:06:04 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_nextnlpos(const void *start)
{
	unsigned char	*cs;
	ssize_t			indx;

	cs = (unsigned char *) start;
	indx = 0;
	while (cs[indx] != '\0')
	{
		if (cs[indx] == '\n')
			return (indx);
		indx++;
	}
	return (-1);
}

static char	*ft_readfd(int fd, char *bufr, char scope)
{
	size_t	indx;
	ssize_t	szrd;

	if (bufr)
		free(bufr);
	bufr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bufr)
		return (NULL);
	indx = 0;
	while (indx < BUFFER_SIZE + 1)
	{
		bufr[indx] = '\0';
		indx++;
	}
	szrd = read(fd, bufr, BUFFER_SIZE);
	if (!scope && (szrd < 0 || !*bufr))
	{
		free(bufr);
		return (NULL);
	}
	return (bufr);
}

static char	*ft_nlgen(char *s1, char *s2)
{
	char	*nl;
	size_t	indx;

	nl = ft_strjoin(s1, s2);
	free(s1);
	indx = 0;
	while (nl[indx] && nl[indx] != '\n')
		indx++;
	if (nl[indx] == '\n')
		indx++;
	while (nl[indx])
	{
		nl[indx] = '\0';
		indx++;
	}
	return (nl);
}

static char	*ft_lastfree(char *bufr, char *aux)
{
	free(bufr);
	bufr = NULL;
	if (*aux)
		bufr = aux;
	else
		free(aux);
	return (bufr);
}

char	*ft_gnl(int fd)
{
	static char	*bufr = NULL;
	char		*aux;
	char		*nl;
	ssize_t		nl_indx;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!bufr)
		bufr = ft_readfd(fd, bufr, 0);
	if (!bufr)
		return (NULL);
	aux = ft_strdup("");
	nl_indx = ft_nextnlpos(bufr);
	while (nl_indx == -1 && *bufr)
	{
		aux = ft_nlgen(aux, bufr);
		bufr = ft_readfd(fd, bufr, 1);
		if (!bufr)
			return (NULL);
		nl_indx = ft_nextnlpos(bufr);
	}
	nl = ft_nlgen(aux, bufr);
	aux = ft_strdup(bufr + nl_indx + 1);
	bufr = ft_lastfree(bufr, aux);
	return (nl);
}
