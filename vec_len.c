/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:23:17 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/05 12:34:02 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	vec_len(t_vec a)
{
	return (sqrt(vec_mult_scal(a, a)));
}

t_vec	vec_normed(t_vec a)
{
	double	a_len;

	a_len = vec_len(a);
	if (a_len == 0)
		return (a);
	else
		return (vec_mult_num(a, 1 / a_len));
}
