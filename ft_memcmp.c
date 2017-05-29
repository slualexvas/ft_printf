/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:32:01 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 13:51:48 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ss1;
	char	*ss2;

	if (n == 0)
		return (0);
	ss1 = (char*)s1;
	ss2 = (char*)s2;
	i = 0;
	while (i < n - 1)
	{
		if (ss1[i] != ss2[i])
			break ;
		i++;
	}
	return (int)((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}
