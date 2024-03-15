/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:40:13 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/06 15:40:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strs(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (*s != c && *s != 0)
	{
		count++;
		s++;
	}
	while (*s)
	{
		if ((*s != c && *s != 0) && *(s - 1) == c)
			count++;
		s++;
	}
	return (count);
}

static int	write_str(const char *s, char c, char **split_string, int i)
{
	int	char_i;

	char_i = 0;
	while (*s != c && *s)
	{
		char_i++;
		s++;
	}
	split_string[i] = ft_substr(s - char_i, 0, char_i);
	if (!split_string[i])
	{
		while (i-- > 0)
			free(split_string[i]);
		split_string = NULL;
		return (0);
	}
	return (char_i);
}

int	emptystring(char **split_string)
{
	*split_string = (char *)malloc(1);
	if (!*split_string)
		return (0);
	**split_string = 0;
	free(*split_string);
	return (1);
}

static int	create_array(const char *s, char c, char **split_string)
{
	size_t	char_i;
	int		i;

	char_i = 1;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			char_i = write_str(s, c, split_string, i);
			i++;
		}
		if (!char_i)
			return (0);
		else
			s += char_i;
		if (!*s)
			return (1);
		char_i = 1;
	}
	return (emptystring(split_string));
}

char	**ft_split(char const *s, char c)
{
	char	**split_string;
	int		str_i;
	int		array_len;

	str_i = count_strs(s, c);
	array_len = sizeof(char **) * (str_i + 1);
	split_string = (char **)malloc(array_len);
	if (!split_string)
		return (NULL);
	if (!create_array(s, c, split_string))
		return (NULL);
	split_string[str_i] = NULL;
	return (split_string);
}

/*int	main(void)
{
	const char	*s = "  ";
	char	**ss;

	ss = ft_split(s, ' ');
	if (ss == NULL)
		printf("fallo en la memoria");
	else
	{
		while (*ss != NULL)
		{
			printf("%s\n", *ss);
			ss++;
		}
	}
	return (0);
}*/
