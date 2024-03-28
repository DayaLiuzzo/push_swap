/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:59:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 15:38:32 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_stack *sa)
{
	t_stack	*tmp;
	t_stack	*current;

	current = sa;
	tmp = sa;
	while (tmp != NULL)
	{
		current = tmp->next;
		while (current != NULL)
		{
			if (tmp->data > current->data)
			{
				return (1);
			}
			current = current->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_is_sort_decr(t_stack *sa)
{
	t_stack	*tmp;
	t_stack	*current;

	current = sa;
	tmp = sa;
	while (tmp != NULL)
	{
		current = tmp->next;
		while (current != NULL)
		{
			if (tmp->data < current->data)
			{
				return (1);
			}
			current = current->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
