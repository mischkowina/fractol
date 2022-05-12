/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:54:25 by smischni          #+#    #+#             */
/*   Updated: 2022/04/03 15:57:57 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
		*(str + j++) = *(s1 + i++);
	i = 0;
	while (*(s2 + i) != '\0')
		*(str + j++) = *(s2 + i++);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*n;

	i = 0;
	if (!s)
		return (NULL);
	while ((*(s + i) != (unsigned char)c) && (*(s + i) != '\0'))
	{
		i++;
	}
	if ((unsigned char)c != '\0' && *(s + i) == '\0')
	{
		return (NULL);
	}
	else
	{
		n = (char *)(s + i);
		return (n);
	}
}
