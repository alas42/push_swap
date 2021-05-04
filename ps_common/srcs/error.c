/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:00:41 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 13:44:35 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

void	ft_quit(t_stack *stack_a, t_stack *stack_b)
{
	free_stacks(stack_a, stack_b);
	exit(EXIT_FAILURE);
}

void	ft_error(char *s, t_stack *stack_a, t_stack *stack_b, t_helper *helper)
{
	if (helper != NULL)
	{
		if (helper->tab != NULL)
			free(helper->tab);
		free(helper);
	}
	if (s != NULL)
	{
		if (ft_strncmp("NO", s, 2) != 0)
			ft_putendl_fd("Error", 2);
		ft_quit(stack_a, stack_b);
	}
}
