/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_to_str_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:33:20 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 14:39:19 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_digits(uintmax_t a, unsigned char base)
{
	int		i;

	i = 0;
	while (a > 0)
	{
		a = a / base;
		i++;
	}
	if (i == 0)
		i++;
	return (i);
}

char	ft_to_digit(unsigned char d, int is_uppercase)
{
	if (d < 10)
		return (d + '0');
	else if (is_uppercase == 0)
		return ('a' + d - 10);
	else if (is_uppercase == 1)
		return ('A' + d - 10);
	else
		return ('\0');
}

void	fill_digits(uintmax_t a, char *res,
			unsigned char base, int is_uppercase)
{
	int		i;
	int		n;

	n = (int)count_digits(a, base);
	i = 0;
	while (a > 0)
	{
		res[n - i - 1] = ft_to_digit(a % base, is_uppercase);
		a = a / base;
		i++;
	}
	if (i == 0)
		res[0] = '0';
}

char	*ft_uintmax_to_str_base(uintmax_t a, unsigned char base,
			int is_uppercase, size_t min_width)
{
	char	*res;
	int		zeros_len;
	char	*res1;
	char	*res2;

	if (base < 2)
		return (NULL);
	res = ft_strnew(count_digits(a, base));
	fill_digits(a, res, base, is_uppercase);
	zeros_len = min_width - ft_strlen(res);
	if (zeros_len <= 0)
		return (res);
	res1 = ft_strnew(zeros_len);
	ft_memset(res1, '0', zeros_len);
	res2 = ft_strjoin(res1, res);
	ft_strdel(&res);
	ft_strdel(&res1);
	return (res2);
}

char	*ft_intmax_to_str_base(intmax_t a, unsigned char base,
			int is_uppercase, size_t min_width)
{
	uintmax_t	b;
	char		*res;
	char		*ures;

	if (base < 2)
		return (NULL);
	if (a < 0)
		b = -(a + 1) + 1;
	else
		b = a;
	ures = ft_uintmax_to_str_base(b, base, is_uppercase, min_width);
	if (a < 0)
		res = ft_strjoin("-", ures);
	else
		res = ft_strdup(ures);
	ft_strdel(&ures);
	return (res);
}
