/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:00:53 by oslutsky          #+#    #+#             */
/*   Updated: 2017/04/30 14:12:41 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec			vec(double x, double y, double z)
{
	t_vec		res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}
