/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:19:25 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 18:53:28 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_helper(t_helper *helper, int len_stack)
{
	helper->end_stack1 = len_stack - 1;
	helper->end_stack2 = len_stack - 1;
	helper->len_stack = len_stack;
	helper->blocks = 0;
	helper->tab = (int *)malloc(sizeof(int) * (len_stack + 1));
	if (!helper->tab)
	{
		helper->len_stack = -1;
		return ;
	}
	helper->tab[len_stack] = -1;
}
