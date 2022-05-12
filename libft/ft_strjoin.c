/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:58:14 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 13:40:15 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Allocates a new string which is the result of concatenation of s1 and s2.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
	{
		*(str + j) = *(s1 + i);
		j++;
		i++;
	}
	i = 0;
	while (*(s2 + i) != '\0')
	{
		*(str + j) = *(s2 + i);
		j++;
		i++;
	}
	return (str);
}
