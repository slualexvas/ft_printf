/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:30:15 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/07 14:30:17 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*res;

	res = NULL;
	if (big == NULL || little[0] == '\0')
		return (char*)(big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		res = (char*)(big + i);
		while (little[j] != '\0' && (i + j) < len)
			if (big[i + j] != little[j])
				break ;
			else
				j++;
		if (little[j] == '\0')
			break ;
		else
			res = NULL;
		i++;
	}
	return (res);
}
