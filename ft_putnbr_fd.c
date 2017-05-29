/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:16:46 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/03 20:58:12 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;
	unsigned int	pow_10;

	if (n < 0)
	{
		n++;
		n1 = -n;
		n1++;
		write(fd, "-", 1);
	}
	else
		n1 = n;
	pow_10 = 1;
	while (n1 / pow_10 >= 10)
		pow_10 = pow_10 * 10;
	while (pow_10 > 0)
	{
		ft_putchar_fd(n1 / pow_10 + '0', fd);
		n1 = n1 % pow_10;
		pow_10 = pow_10 / 10;
	}
}
