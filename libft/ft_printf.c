/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:25:58 by smischni          #+#    #+#             */
/*   Updated: 2022/04/03 16:03:45 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(char c, va_list a);

int	ft_printf(const char *str, ...)
{
	va_list	a;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(a, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(str[i], a);
		}
		else
		{
			ft_putchar_len(str[i]);
			len++;
		}
		i++;
	}
	va_end(a);
	return (len);
}

static int	ft_format(char c, va_list a)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_len(va_arg(a, int));
	else if (c == 's')
		len += ft_putstr_len(va_arg(a, char *));
	else if (c == 'p')
	{
		len += ft_putstr_len("0x");
		len += ft_putptr_len(va_arg(a, unsigned long long));
	}
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_len(va_arg(a, int));
	else if (c == 'u')
		len += ft_putnbr_uns_len(va_arg(a, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_puthex_len(va_arg(a, unsigned int), c);
	else
		len += ft_putchar_len(c);
	return (len);
}
