/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:26:58 by smischni          #+#    #+#             */
/*   Updated: 2022/04/03 16:02:07 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += ft_putchar_len('0' + n);
	if (n >= 10 && n < 16)
		len += ft_putchar_len('a' + ((n % 16) - 10));
	else if (n >= 16)
	{
		len += ft_putptr_len((n / 16));
		if ((n % 16) < 10)
			len += ft_putchar_len('0' + (n % 16));
		else if ((n % 16) >= 10)
			len += ft_putchar_len('a' + ((n % 16) - 10));
	}
	return (len);
}
