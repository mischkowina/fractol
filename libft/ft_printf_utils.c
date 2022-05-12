/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:45:47 by smischni          #+#    #+#             */
/*   Updated: 2022/05/12 18:30:04 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_len(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr_len(char *s)
{
	int	len;

	len = 0;
	if (!s)
		len += ft_putstr_len("(null)");
	else
	{
		while (*(s + len) != '\0')
		{
			ft_putchar_len(*(s + len));
			len++;
		}
	}
	return (len);
}

int	ft_putnbr_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putchar_len('-');
		len += ft_putchar_len('2');
		n = 147483648;
	}
	if (n < 0)
	{
		len += ft_putchar_len('-');
		n = n * -1;
	}
	if (n >= 0 && n < 10)
		len += ft_putchar_len(('0' + n));
	else if (n >= 10)
	{
		len += ft_putnbr_len((n / 10));
		len += ft_putchar_len(('0' + (n % 10)));
	}
	return (len);
}

int	ft_putnbr_uns_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += ft_putchar_len(('0' + n));
	else if (n >= 10)
	{
		len += ft_putnbr_len((n / 10));
		len += ft_putchar_len(('0' + (n % 10)));
	}
	return (len);
}

int	ft_puthex_len(unsigned int n, char c)
{
	int	len;
	int	i;

	len = 0;
	if (c == 'x')
		i = 97;
	else if (c == 'X')
		i = 65;
	if (n < 10)
		len += ft_putchar_len('0' + n);
	if (n >= 10 && n < 16)
		len += ft_putchar_len(i + ((n % 16) - 10));
	else if (n >= 16)
	{
		len += ft_puthex_len((n / 16), c);
		if ((n % 16) < 10)
			len += ft_putchar_len('0' + (n % 16));
		else if ((n % 16) >= 10)
			len += ft_putchar_len(i + ((n % 16) - 10));
	}
	return (len);
}
