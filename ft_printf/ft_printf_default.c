/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:58:03 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/27 11:11:12 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_default(t_pav *pav)
{
	if (pav->pcv.conv_printed != 0)
		return ;
	ft_printf_add_str_using_width(pav, &(pav->pcv.conv_char), 1);
}
