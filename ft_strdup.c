/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:59:38 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 13:58:20 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		n;
	int		i;

	n = ft_strlen(s1);
	s2 = (char*)malloc((n + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
