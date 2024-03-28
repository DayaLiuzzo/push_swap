/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:20:30 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 18:37:32 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo100(t_stack **sa, t_stack **sb)
{
	t_utils	utils;

	ft_init_utils(&utils);
	ft_chunk_through(sa, sb, utils);
}

void	ft_algo5(t_stack **sa, t_stack **sb, int index)
{
	if (1 == ft_is_sort(*sa))
	{
		ft_top_min(sa, index);
		push_b(sa, sb, 0);
		if (1 == ft_is_sort(*sa))
			ft_algo4(sa, sb, index);
		push_a(sa, sb);
	}
}

void	ft_algo4(t_stack **sa, t_stack **sb, int index)
{
	ft_top_min(sa, index);
	push_b(sa, sb, 0);
	if (1 == ft_is_sort(*sa))
		ft_algo3(sa, index);
	push_a(sa, sb);
}

void	ft_algo3(t_stack **sa, int first)
{
	t_stack	*tmp;

	tmp = (*sa)->next;
	first = (*sa)->data;
	if ((first > tmp->data) && (first > tmp->next->data)
		&& (tmp->data > tmp->next->data))
	{
		rotate_a(sa, 0);
		swap_a(sa, 0);
	}
	else if ((first > tmp->data) && (first > tmp->next->data)
		&& (tmp->data < tmp->next->data))
		rotate_a(sa, 0);
	else if ((first < tmp->data) && (first > tmp->next->data))
		reverse_rotate_a(sa, 0);
	else if ((first < tmp->data) && (first < tmp->next->data))
	{
		reverse_rotate_a(sa, 0);
		swap_a(sa, 0);
	}
	else if ((first > tmp->data) && (first < tmp->next->data))
		swap_a(sa, 0);
}

void	ft_which_algo(t_stack **sa, t_stack **sb, int values)
{
	if (values == 2)
		rotate_a(sa, 0);
	else if (values == 3)
		ft_algo3(sa, 0);
	else if (values == 4)
		ft_algo4(sa, sb, 0);
	else if (values == 5)
		ft_algo5(sa, sb, 0);
	else
	{
		ft_algo100(sa, sb);
	}
}
