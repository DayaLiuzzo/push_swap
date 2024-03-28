/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:50:17 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 18:32:09 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_data(t_stack *sa)
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
	return (min->data);
}

t_stack	*ft_find_prev(t_stack *sa, t_stack *current)
{
	t_stack	*tmp;

	tmp = sa;
	if (sa && sa->next && sa != current)
	{
		while (tmp && tmp->next && tmp->next->data != current->data)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

t_stack	*ft_findlast(t_stack *sa)
{
	t_stack	*tmp;

	tmp = sa;
	if (sa)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	return (tmp);
}

t_stack	*find_cheapest(t_stack *first, t_stack *last, t_stack *sa)
{
	t_stack	*tmp;
	int		i;
	int		firstcost;
	int		lastcost;

	tmp = sa;
	firstcost = 0;
	lastcost = ft_stacksize(last) + 1;
	i = 0;
	while (tmp->data != first->data)
	{
		tmp = tmp->next;
		i++;
	}
	firstcost = i + 1;
	if (firstcost < lastcost)
		return (first);
	else
		return (last);
}

void	check_b(t_stack **sb)
{
	t_stack	*tmp;
	int		i;

	tmp = *sb;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > 1 && ft_is_sort_decr(*sb) == 1)
	{
		ft_top_max(sb, 0);
	}
}
