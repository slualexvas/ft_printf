/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:16:46 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/12 14:37:37 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_atoi_before_digits(const char *s, int *i, int *sign)
{
	(*sign) = 1;
	(*i) = 0;
	while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\v'
			|| s[*i] == '\f' || s[*i] == '\r' || s[*i] == '\n')
		(*i)++;
	if (s[*i] == '-')
		(*sign) = -1;
	if (s[*i] == '-' || s[*i] == '+')
		(*i)++;
}

int			ft_atoi(const char *s)
{
	int		res;
	int		i;
	int		sign;
	int		res1;

	ft_atoi_before_digits(s, &i, &sign);
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res1 = res * 10 + s[i++] - '0';
		if (res1 / 10 != res)
		{
			if (sign == 1)
				return (-1);
			else if (res1 * (-1) != res1)
				return (0);
		}
		res = res1;
	}
	return (res * sign);
}
