/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:07:58 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 14:34:34 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	while (i < n)
	{
		res = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
		if (res != 0)
			break ;
		if (s1[i] == '\0')
			break ;
		++i;
	}
	return (res);
}
