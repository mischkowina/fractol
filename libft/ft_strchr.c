/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:58:34 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 13:36:37 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Locates the first occurrence of c (converted to a char) in the string s. 
The terminating null is part of the string; if c is `\0', the function locate it.
*/
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*n;

	i = 0;
	while ((*(s + i) != (unsigned char)c) && (*(s + i) != '\0'))
	{
		i++;
	}
	if ((unsigned char)c != '\0' && *(s + i) == '\0')
	{
		return (0);
	}
	else
	{
		n = (char *)(s + i);
		return (n);
	}
}
