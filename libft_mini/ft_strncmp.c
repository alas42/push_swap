/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:56:44 by avogt             #+#    #+#             */
/*   Updated: 2021/03/19 14:22:31 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mini.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			counter;
	unsigned char	c1;
	unsigned char	c2;

	c1 = (unsigned char)*s1;
	c2 = (unsigned char)*s2;
	counter = 0;
	if (n == 0)
		return (0);
	while (counter < n - 1 && *s1 != '\0' && *s2 != '\0')
	{
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
		if (c1 != c2)
			return (c1 - c2);
		counter++;
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
