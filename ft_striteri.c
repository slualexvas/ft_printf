/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:23:25 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 15:09:48 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (*s != '\0')
			f(i++, s++);
	}
}
