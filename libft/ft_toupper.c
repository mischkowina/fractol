/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:09:43 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 14:02:44 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Converts a lower-case letter to the corresponding upper-case letter.
*/
int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		c = c - 32;
	}
	return (c);
}
