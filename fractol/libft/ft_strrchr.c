/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:54:58 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 13:54:21 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the last occurrence of c (converted to a char) in the string s. 
The terminating null is part of the string; if c is `\0', the function locate it.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*n;
	int		i;

	i = ft_strlen(s);
	while ((*(s + i) != (unsigned char)c) && i >= 0)
	{
		i--;
	}
	if (i < 0)
	{
		return (NULL);
	}
	else
	{
		n = (char *)(s + i);
		return (n);
	}	
}
