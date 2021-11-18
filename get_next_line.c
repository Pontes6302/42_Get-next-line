/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:23:43 by sifreita          #+#    #+#             */
/*   Updated: 2021/10/28 17:23:44 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*ft_return(char *final)
{
	int	l;
	int s;

	l = ft_strlen(final);
	if (final[l] == '\0')

	while (l > 0)
	{
		if (final[l] == '\n' || final[l] == '\0')
			break ;
		l--;
	}
	s = l;
	while (l > 0)
	{
		if (final[l] == '\n')
			break ;
		l--;
	}
	return(ft_substr(final, l, s - l));
}

char	*get_next_line(int fd)
{
	static char	*final[100000]; <-------------------------------------
	char		buff[BUFFER_SIZE + 1];
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	final = (char **)malloc(fd * sizeof(char *));
	while ((count = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		final[fd] = ft_strjoin(final[fd], buff);
		return (0);
		if (ft_strchr(final[fd], '\n'))
			break ;
	}
	return(ft_return(final[fd]));
}

int main()
{
	char *string;
	int fd = open("shit.txt", O_RDONLY);
	string = get_next_line(fd);

	printf("%s", string);
}