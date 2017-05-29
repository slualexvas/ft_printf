/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longdouble_to_str_base.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 09:12:31 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 14:38:45 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_longdouble_to_str_base(long double a, unsigned char base,
			int is_uppercase, unsigned char precision)
{
	char		*res;
	char		*s;
	long double	a_abs;
	uintmax_t	n;

	a_abs = a;
	if (a < 0)
		a_abs = -a;
	n = (uintmax_t)a_abs;
	if (precision == 0)
		n = (uintmax_t)(a_abs + 0.5);
	res = ft_uintmax_to_str_base(n, base, is_uppercase, 0);
	if (precision > 0)
	{
		res = ft_strjoin(res, ".");
		a_abs -= n;
		a_abs *= ft_i_pow_n(base, precision);
		s = ft_uintmax_to_str_base((uintmax_t)(a_abs + 0.5),
				base, is_uppercase, precision);
		res = ft_strjoin(res, s);
	}
	if (a < 0)
		res = ft_strjoin("-", res);
	return (res);
}
