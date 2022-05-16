/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:25:17 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 14:02:12 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Converts an upper-case letter to the corresponding lower-case letter.
*/
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c = c + 32;
	}
	return (c);
}
