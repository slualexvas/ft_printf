/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_linear_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:04:21 by oslutsky          #+#    #+#             */
/*   Updated: 2017/04/30 14:19:27 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec			vec_plus(t_vec a, t_vec b)
{
	t_vec		res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vec			vec_minus(t_vec a, t_vec b)
{
	t_vec		res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vec			vec_mult_num(t_vec a, double num)
{
	t_vec		res;

	res.x = a.x * num;
	res.y = a.y * num;
	res.z = a.z * num;
	return (res);
}
