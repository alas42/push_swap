/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:22:09 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 17:47:33 by avogt            ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = stack->first;
	while (tmp != NULL)
	{
		printf("%d - ", tmp->number);
		tmp = tmp->next;
		len++;
	}
	printf("(null)\n");
}

void	print_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
}
