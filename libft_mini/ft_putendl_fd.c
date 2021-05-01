/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:49:09 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 19:21:49 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mini.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL)
		while (*s != '\0')
			ft_putchar_fd(*(s++), fd);
}

void		ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
