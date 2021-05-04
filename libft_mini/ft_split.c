/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:48:34 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 13:18:20 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mini.h"
#include <stdio.h>

static void	ft_strfill(char **tab, char *s, char c)
{
	unsigned int	len;
	unsigned int	n_word;
	int				i;

	i = 0;
	n_word = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			tab[n_word][len++] = s[i];
			i++;
		}
		if (tab[n_word] != NULL)
			tab[n_word++][len] = '\0';
	}
}

static int	ft_strmall(char **tab, char *s, char c)
{
	int				i;
	unsigned int	len;
	unsigned int	n_word;

	i = 0;
	n_word = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		while (s[i] == c)
			i++;
		if (!(tab[n_word++] = (char *)malloc(sizeof(char) * (len + 1))))
			while (tab[--n_word])
				free(tab[n_word]);
		if (!tab[0])
			return (-1);
	}
	return (1);
}

char		**ft_split(char *s, char c)
{
	char			**tab;
	unsigned int	n_word;
	int				i;

	i = 0;
	n_word = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		n_word = (s[i] != '\0' && s[i] != c) ? n_word + 1 : n_word;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (n_word + 1))))
		return (NULL);
	if (ft_strmall(tab, s, c) == -1)
		return (NULL);
	tab[n_word] = NULL;
	ft_strfill(tab, s, c);
	return (tab);
}
