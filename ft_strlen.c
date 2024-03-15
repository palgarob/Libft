/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:27:33 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/23 17:27:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		s++;
		n++;
	}
	return (n);
}

/*
int	main(void)
{
	char *s = "hola";
	printf("%zu", ft_strlen(s));
	return (0);
}
*/
