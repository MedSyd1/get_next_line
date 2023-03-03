/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:07 by mmoufid           #+#    #+#             */
/*   Updated: 2022/10/30 18:04:29 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_buffer_stock(char *stock, char *buffer, int fd, int count)
{	
	while (count != 0 && !verify(stock, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	return (stock);
}

static char	*ft_get_line(char *stock)
{
	int	i;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	return (ft_substr(stock, 0, i + 1));
}

static char	*ft_update_stock(char *stock)
{
	int		i;
	char	*t;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	t = ft_substr(stock, i + 1, ft_strlen(stock + i + 1));
	free(stock);
	return (t);
}

char	*get_next_line(int fd)
{
	static char	*stock[10240];
	char		*buffer;
	char		*line;
	int			count;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stock[fd] = ft_buffer_stock(stock[fd], buffer, fd, count);
	if (!stock[fd])
		return (NULL);
	if (!*stock[fd])
	{
		free(buffer);
		free(stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(stock[fd]);
	stock[fd] = ft_update_stock(stock[fd]);
	free(buffer);
	return (line);
}
