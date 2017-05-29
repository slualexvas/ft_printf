/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:28:44 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 14:01:37 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstprint(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("\n(null list)\n");
	else
	{
		ft_putstr("\nlist:\n");
		while (lst != NULL)
		{
			write(1, "\"", 1);
			write(1, (char*)(lst->content), lst->content_size);
			write(1, "\"", 1);
			lst = lst->next;
			if (lst != NULL)
				write(1, "-", 1);
		}
	}
}
