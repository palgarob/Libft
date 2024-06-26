/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:22:50 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/30 17:22:52 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strfound(const char *haystack, const char *needle, size_t len)
{
	char	*stack;

	stack = (char *)haystack;
	while (*stack == *needle && len >= ft_strlen(needle))
	{
		if (*(needle + 1) == 0)
		{
			return (1);
		}
		stack++;
		needle++;
		len--;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (ft_strlen(haystack) >= ft_strlen(needle) && ft_strlen(needle) <= len)
	{
		if (*haystack == *needle)
			if (strfound(haystack, needle, len))
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*needle = "d";
	const char	*haystack = "cdefg";
	size_t	len = 0;

	printf("%s\n", strnstr(haystack, needle, len));
	printf("%s", ft_strnstr(haystack, needle, len));
	return (0);
}
*/
