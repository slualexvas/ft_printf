/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_pow_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 09:19:24 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/20 09:21:57 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_i_pow_n(intmax_t i, unsigned char n)
{
	unsigned char	n1;
	intmax_t		res;

	n1 = 0;
	res = 1;
	while (n1++ < n)
		res *= i;
	return (res);
}
