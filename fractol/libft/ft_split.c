/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:03:54 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 13:24:21 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_create(char **split, char const *s, char c, size_t count);
static size_t	ft_strlen_del(char const *str, char c);
static int		ft_check_alloc(char **split, size_t count);

/*
Allocates an array of strings obtained by splitting s using char c as delimiter.
Array must end with a NULL pointer.
*/
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**split;

	if (!s)
		return (NULL);
	count = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c && s[i + 1]))
			count++;
		i++;
	}
	split = ft_calloc((count + 1), sizeof(char *));
	if (!split)
		return (NULL);
	ft_create(split, s, c, count);
	if (ft_check_alloc(split, count) == 0)
		return (NULL);
	return (split);
}

/*
Creates count separate substrings of s in the array split.
*/
static void	ft_create(char **split, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < count && *(s + i) != '\0')
	{
		if (i == 0 && *(s + i) != c)
		{
			split[j] = ft_substr(s, 0, ft_strlen_del((s + i), c));
			j++;
		}
		if (*(s + i) == c && *(s + i + 1) != c)
		{
			split[j] = ft_substr(s, (i + 1), ft_strlen_del((s + i + 1), c));
			j++;
		}
		i++;
	}
}

/*
Determines the size of the next substring to create from s.
*/
static size_t	ft_strlen_del(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str != '\0' && *str != c)
	{
		count++;
		str++;
	}
	return (count);
}

/*
Checks if allocation was succesful for all strings and the array.
Else frees everything and returns 0.
*/
static int	ft_check_alloc(char **split, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (!split[i])
		{
			i = 0;
			while (i < count)
			{
				free(split[i]);
				i++;
			}
			free(split);
			return (0);
		}
		i++;
	}
	return (1);
}
