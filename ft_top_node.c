/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:54 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/03/08 16:05:30 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_top_cheapest(t_stack **sa, t_stack *cheapest,
		int index)
{
	t_stack	*tmp;

	tmp = *sa;
	while (tmp->data != cheapest->data)
	{
		tmp = tmp->next;
		index++;
	}
	if (index <= (ft_stacksize(*sa) / 2))
	{
		while ((*sa)->data != cheapest->data)
			rotate_a(sa, 0);
	}
	else if (index > (ft_stacksize(*sa) / 2))
	{
		while ((*sa)->data != cheapest->data)
			reverse_rotate_a(sa, 0);
	}
}

void	ft_top_max(t_stack **sb, int index)
{
	t_stack	*max;
	t_stack	*tmp;

	max = ft_find_max(*sb);
	tmp = *sb;
	while (tmp->data != max->data)
	{
		tmp = tmp->next;
		index++;
	}
	if (index <= (ft_stacksize(*sb) / 2))
	{
		while ((*sb)->data != max->data)
			rotate_b(sb);
	}
	else if (index > (ft_stacksize(*sb) / 2))
	{
		while ((*sb)->data != max->data)
			reverse_rotate_b(sb);
	}
}

void	ft_top_min_b(t_stack **sb, int index)
{
	t_stack	*min;
	t_stack	*tmp;

	min = ft_find_min(*sb);
	tmp = *sb;
	while (tmp->data != min->data)
	{
		tmp = tmp->next;
		index++;
	}
	if (index <= (ft_stacksize(*sb) / 2))
	{
		while ((*sb)->data != min->data)
			rotate_b(sb);
	}
	else if (index > (ft_stacksize(*sb) / 2))
	{
		while ((*sb)->data != min->data)
			reverse_rotate_b(sb);
	}
}

void	ft_top_min(t_stack **sa, int index)
{
	t_stack	*min;
	t_stack	*tmp;

	min = ft_find_min(*sa);
	tmp = *sa;
	while (tmp->data != min->data)
	{
		tmp = tmp->next;
		index++;
	}
	if (index <= (ft_stacksize(*sa) / 2))
	{
		while ((*sa)->data != min->data)
			rotate_a(sa, 0);
	}
	else if (index > (ft_stacksize(*sa) / 2))
	{
		while ((*sa)->data != min->data)
			reverse_rotate_a(sa, 0);
	}
}