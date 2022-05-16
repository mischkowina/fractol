/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:42:06 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 13:45:22 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
Copies up to dstsize - 1 characters src to dst, NUL-terminating if dstsize != 0.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			count;

	count = 0;
	while (*(src + count) != '\0')
	{
		count++;
	}
	if (dstsize != 0)
	{
		i = 0;
		while ((*(src + i) != '\0') && i < (dstsize - 1))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (count);
}
