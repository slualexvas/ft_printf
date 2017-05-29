/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cos_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:18:44 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/03 12:27:13 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double			vec_cos_angle(t_vec a, t_vec b)
{
	double	ab;
	double	aa;
	double	bb;

	ab = vec_mult_scal(a, b);
	aa = vec_mult_scal(a, a);
	bb = vec_mult_scal(b, b);
	if (ab == 0)
		return (0);
	return (ab / sqrt(aa * bb));
}
