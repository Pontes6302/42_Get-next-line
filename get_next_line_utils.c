/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:23:54 by sifreita          #+#    #+#             */
/*   Updated: 2021/10/28 17:23:56 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	if (!s || !c)
		return (-1);
	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		a;

	i = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (res == NULL)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (s2[i])
	{
		res[i + a] = s2[i];
		i++;
	}
	res[i + a] = '\0';
	return (res);
}

char	*ft_strdup(char *s1)
{
	int		p;
	char	*str2;

	str2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str2)
		return (0);
	p = 0;
	while (s1[p])
	{
		str2[p] = s1[p];
		p++;
	}
	str2[p] = '\0';
	return (str2);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	l;

	if (!s)
		return (0);
	i = 0;
	l = ft_strlen(s);
	if (start >= l)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (0);
		*res = '\0';
		return (res);
	}
	if (l < len)
		return (ft_strdup((char *)s + start));
	res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (0);
	while (start < l && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
