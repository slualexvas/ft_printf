/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:28:44 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/07 14:34:21 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;

	if (alst == NULL)
		return ;
	while ((*alst) != NULL)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		(*alst) = next;
	}
}
