/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:23:43 by sifreita          #+#    #+#             */
/*   Updated: 2021/11/25 17:03:43 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_return(char **final)
{
	char	*temp2;
	char	*temp;
	int		i;

	if (!*final || **final == '\0')
		return (0);
	i = ft_strchr(*final, '\n');
	if (i >= 0)
	{
		temp = ft_substr(*final, 0, i + 1);
		temp2 = ft_substr(*final, i + 1, ft_strlen(*final));
		free (*final);
		*final = temp2;
		if (**final != '\0')
			return (temp);
	}
	else
		temp = ft_strdup(*final);
	free (*final);
	*final = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*final[100000];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 100000)
		return (0);
	count = read(fd, buff, BUFFER_SIZE);
	while (count > 0)
	{
		buff[count] = '\0';
		if (!final[fd])
			final[fd] = ft_strdup("");
		temp = ft_strjoin(final[fd], buff);
		free (final[fd]);
		final[fd] = temp;
		if (ft_strchr(final[fd], '\n') != -1)
			break ;
		count = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_return(&final[fd]));
}
