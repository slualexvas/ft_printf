/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:52:13 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 13:45:54 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_fill_digits(int n, char *res)
{
	int		i;
	int		pow_10;

	pow_10 = 1;
	while (n / pow_10 >= 10)
		pow_10 = pow_10 * 10;
	i = 0;
	while (pow_10 > 0)
	{
		res[i++] = n / pow_10 + '0';
		n = n % pow_10;
		pow_10 = pow_10 / 10;
	}
}

static int	ft_itoa_count_digits(int n)
{
	int		count_digits;

	count_digits = 1;
	if (n < 0)
		count_digits++;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		count_digits++;
	}
	return (count_digits);
}

char		*ft_itoa(int n)
{
	char	*res;

	if (-n == n && n != 0)
		return (ft_strdup("-2147483648"));
	res = ft_strnew(ft_itoa_count_digits(n));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		ft_itoa_fill_digits(-n, res + 1);
	}
	else
		ft_itoa_fill_digits(n, res);
	return (res);
}
