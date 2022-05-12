/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:55:57 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 12:30:46 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_create_string(char *str, long i, int len);

/*
Allocates an returns a string representing the int received as argument
*/
char	*ft_itoa(int n)
{
	int		len;
	long	i;
	char	*str;

	i = n;
	len = 0;
	if (n < 0 || n == 0)
		len++;
	while (i != 0)
	{
		i = i / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	i = n;
	if (i < 0)
		i = i * -1;
	ft_create_string(str, i, len);
	if (n < 0)
		str[0] = '-';
	return (str);
}

static void	ft_create_string(char *str, long i, int len)
{
	if (i >= 0 && i < 10)
	{
		str[len] = ('0' + i);
		len--;
	}
	if (i >= 10)
	{
		str[len] = ('0' + (i % 10));
		len--;
		ft_create_string(str, (i / 10), len);
	}
}
