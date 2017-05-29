/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic_equation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:48:29 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/05 13:53:30 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	solve_linear_equation(t_quadratic_equation *eq)
{
	if (eq->b == 0)
		eq->has_solutions = 0;
	else
	{
		eq->x1 = (-eq->b / eq->c);
		eq->x2 = eq->x1;
	}
}

void	solve_quadratic_equation(t_quadratic_equation *eq)
{
	double	d;
	double	root_d;

	if (eq == NULL)
		return ;
	d = eq->b * eq->b - 4 * eq->a * eq->c;
	if (d < 0)
		eq->has_solutions = 0;
	else
	{
		eq->has_solutions = 1;
		if (eq->a == 0)
			return (solve_linear_equation(eq));
		root_d = sqrt(d);
		eq->x1 = (-eq->b - root_d) / (2 * eq->a);
		eq->x2 = (-eq->b + root_d) / (2 * eq->a);
	}
}
