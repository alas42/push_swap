/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:36:40 by avogt             #+#    #+#             */
/*   Updated: 2021/04/29 15:37:38 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static char	*search_operation2(t_operation **operation, char *line)
{
	if (!ft_strncmp(line, "rra", 3))
		return (add_to_operation(operation, 8));
	if (!ft_strncmp(line, "rrb", 3))
		return (add_to_operation(operation, 9));
	if (!ft_strncmp(line, "rrr", 3))
		return (add_to_operation(operation, 10));
	return ("Operation not existing");
}

static char	*search_operation(t_operation **operation, char *line)
{
	if (ft_strlen(line) == 2)
	{
		if (!ft_strncmp(line, "sa", 2))
			return (add_to_operation(operation, 0));
		if (!ft_strncmp(line, "sb", 2))
			return (add_to_operation(operation, 1));
		if (!ft_strncmp(line, "ss", 2))
			return (add_to_operation(operation, 2));
		if (!ft_strncmp(line, "pa", 2))
			return (add_to_operation(operation, 3));
		if (!ft_strncmp(line, "pb", 2))
			return (add_to_operation(operation, 4));
		if (!ft_strncmp(line, "ra", 2))
			return (add_to_operation(operation, 5));
		if (!ft_strncmp(line, "rb", 2))
			return (add_to_operation(operation, 6));
		if (!ft_strncmp(line, "rr", 2))
			return (add_to_operation(operation, 7));
		return ("Operation not existing");
	}
	if (ft_strlen(line) == 3)
		return (search_operation2(operation, line));
	return ("Operation not existing");
}

char		*parse_stdin(t_operation **operation)
{
	char	*line;
	char	*s;

	s = NULL;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line == NULL)
			continue ;
		if (ft_strlen(line) <= 3 && ft_strlen(line) >= 2)
			s = search_operation(operation, line);
		else
			s = "Operation not correctly formatted";
		if (line)
			free(line);
		if (s)
			break ;
	}
	return (s);
}
