/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:17:48 by oslutsky          #+#    #+#             */
/*   Updated: 2017/02/08 13:17:50 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;
	char		*res;

	res = NULL;
	if (big == NULL || little[0] == '\0')
		return (char*)(big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		res = (char*)(big + i);
		while (little[j] != '\0')
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
