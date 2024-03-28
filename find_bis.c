/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:46:37 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 17:52:18 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_max(t_stack *sa)
{
	t_stack	*max;
	t_stack	*current;

	max = sa;
	current = sa->next;
	while (current)
	{
		if (max->data < current->data)
		{
			max = current;
		}
		current = current->next;
	}
	return (max);
}

t_stack	*ft_find_min(t_stack *sa)
{
	t_stack	*min;
	t_stack	*current;

	min = sa;
	current = sa->next;
	while (current)
	{
		if (min->data > current->data)
		{
			min = current;
		}
		current = current->next;
	}
	return (min);
}

void	ft_init_utils(t_utils *utils)
{
	utils->index = 0;
	utils->chunkleft = 0;
	utils->stacksize = 0;
	utils->tmpleft = 0;
	utils->tmpstack = 0;
	utils->tmp = 0;
	utils->prev = 0;
	utils->tmpfirst = 0;
	utils->tmpsnd = 0;
}
