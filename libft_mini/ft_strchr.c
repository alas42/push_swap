/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:59:32 by avogt             #+#    #+#             */
/*   Updated: 2021/03/19 14:22:31 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mini.h"

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	char	*ptr;

	counter = 0;
	ptr = (char *)s;
	while (s[counter] != '\0')
	{
		if (s[counter] == c)
			return (ptr);
		counter++;
		ptr++;
	}
	if (s[counter] == c)
		return (ptr);
	return (NULL);
}
