/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:47:11 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 14:34:36 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"

int		rgb_to_int(const t_rgb *rgb)
{
	return (rgb->r * 0x10000 + rgb->g * 0x100 + rgb->b);
}

void	int_to_rgb(int color, t_rgb *rgb)
{
	rgb->b = color % 0x100;
	color /= 0x100;
	rgb->g = color % 0x100;
	color /= 0x100;
	rgb->r = color % 0x100;
}

int		rgb_components_mult(int color, float num)
{
	t_rgb	rgb;

	int_to_rgb(color, &rgb);
	rgb.r *= num;
	rgb.g *= num;
	rgb.b *= num;
	return (rgb_to_int(&rgb));
}

int		weighted_color(int color1, int color2, float w1, float w2)
{
	t_rgb	rgb1;
	t_rgb	rgb2;
	t_rgb	rgb3;

	if (w1 <= 0)
		return (color2);
	if (w2 <= 0)
		return (color1);
	w1 = w1 / (w1 + w2);
	w2 = 1 - w1;
	int_to_rgb(color1, &rgb1);
	int_to_rgb(color2, &rgb2);
	rgb3.r = rgb1.r * w1 + rgb2.r * w2;
	rgb3.g = rgb1.g * w1 + rgb2.g * w2;
	rgb3.b = rgb1.b * w1 + rgb2.b * w2;
	return (rgb_to_int(&rgb3));
}
