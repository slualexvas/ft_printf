/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult_scal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:20:08 by oslutsky          #+#    #+#             */
/*   Updated: 2017/04/30 14:23:10 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	vec_mult_scal(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
