/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:39:20 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/07 14:51:46 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

typedef struct	s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

int				rgb_to_int(const t_rgb *rgb);
void			int_to_rgb(int color, t_rgb *rgb);
int				rgb_components_mult(int color, float num);
int				weighted_color(int color1, int color2, float w1, float w2);
#endif
