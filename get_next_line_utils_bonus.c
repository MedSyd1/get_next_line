/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:00:11 by mmoufid           #+#    #+#             */
/*   Updated: 2022/10/30 18:04:46 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*t;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	t = (char *)malloc(len + 1);
	if (!t)
		return (NULL);
	while (*s1)
		t[i++] = *s1++;
	t[i] = '\0';
	return (t);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verify(const char *hay, int c)
{
	size_t	i;

	i = 0;
	if (!hay)
		return (0);
	while (hay[i])
	{
		if (hay[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*t;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	t = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[j])
		t[i++] = s2[j++];
	t[i] = '\0';
	free(s1);
	return (t);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substring = malloc(1);
		if (!substring)
			return (NULL);
		*substring = '\0';
		return (substring);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	while (i < len)
		substring[i++] = s[start++];
	substring[len] = '\0';
	return (substring);
}
