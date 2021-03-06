/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:22:09 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 14:02:15 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

int		stack_len(t_stack *stack)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = stack->first;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
