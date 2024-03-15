/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:19:39 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/27 14:19:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux2;

	aux = *lst;
	while (aux)
	{
		del((*aux).content);
		aux2 = (*aux).next;
		free(aux);
		aux = aux2;
	}
	*lst = NULL;
}
