/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 16:27:40 by oslutsky          #+#    #+#             */
/*   Updated: 2017/03/04 14:11:24 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	join_without_mem_leak(char **line, char *to_line)
{
	char	*joined_line;

	joined_line = ft_strjoin(*line, to_line);
	ft_memdel((void**)line);
	ft_memdel((void**)&to_line);
	*line = joined_line;
}

size_t	copy_text_from_buf_to_line(t_buf *buf_x, char **line)
{
	char	*first_newline;
	char	*to_line;
	size_t	buf_len;

	buf_len = ft_strlen(buf_x->buf);
	if (buf_x->cursor >= buf_len)
		buf_x->cursor = 0;
	to_line = ft_strsub(buf_x->buf, buf_x->cursor,
			buf_len - buf_x->cursor);
	first_newline = ft_strchr(to_line, (int)'\n');
	if (first_newline == NULL)
	{
		join_without_mem_leak(line, to_line);
		buf_x->cursor = buf_len;
		return (0);
	}
	else
	{
		first_newline[0] = '\0';
		buf_x->cursor += ft_strlen(to_line) + 1;
		join_without_mem_leak(line, to_line);
		return (1);
	}
}

int		gnl_trivial_actions(const int fd, char **line, size_t *newline_found)
{
	if (fd < 0 || BUFF_SIZE < 0)
		return (-1);
	if (line == 0)
		return (-1);
	*line = 0;
	*newline_found = 0;
	return (1);
}

int		gnl_res_from_bytes_read_and_line(int bytes_read, char **line)
{
	if (bytes_read < 0)
		return (-1);
	else if (bytes_read == 0 && *line == 0)
		return (0);
	else
		return (1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_buf	buf_x = {"", 0};
	size_t			newline_found;
	int				bytes_read;

	if (gnl_trivial_actions(fd, line, &newline_found) == -1)
		return (-1);
	if (buf_x.cursor < ft_strlen(buf_x.buf))
		newline_found = copy_text_from_buf_to_line(&buf_x, line);
	bytes_read = 1;
	while (newline_found != 1 && bytes_read > 0)
	{
		ft_bzero(buf_x.buf, BUFF_SIZE + 1);
		bytes_read = read(fd, buf_x.buf, BUFF_SIZE);
		buf_x.cursor = 0;
		if (bytes_read > 0)
			newline_found = copy_text_from_buf_to_line(&buf_x, line);
	}
	return (gnl_res_from_bytes_read_and_line(bytes_read, line));
}
