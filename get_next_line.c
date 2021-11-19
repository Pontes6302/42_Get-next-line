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

	return(ft_substr(final, 0, l - s));
}

char	*get_next_line(int fd)
{
	static char	*final[100000]; //<-------------------------------------
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	//final = (char **)malloc(fd * sizeof(char *));
	while ((count = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[count] = '\0';
		if (!final[fd])
			final[fd] = ft_strdup("");
		temp = final[fd];
		final[fd] = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(final[fd], '\n'))
			break ;
	}
	while(f)
	return(ft_return(final[fd]));
}

int main()
{
	char *string;
	int fd = open("shit.txt", O_RDONLY);
	string = get_next_line(fd);

	printf("%s", string);
}