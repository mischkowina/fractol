/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:46:43 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 13:04:54 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Output character c to the given file descriptor fd.
*/
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
