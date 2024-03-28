/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:17:09 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 18:06:28 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **sa, int i)
{
	t_stack	*first;
	t_stack	*current;

	if (sa == NULL)
		return ;
	first = (*sa)->next;
	current = *sa;
	while (current->next != NULL)
	{
		current = current->next;
	}
	(*sa)->next = NULL;
	current->next = *sa;
	*sa = first;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **sb)
{
	rotate_a(sb, 1);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **sa, t_stack **sb)
{
	rotate_a(sa, 1);
	rotate_b(sb);
	write(1, "rr\n", 3);
}
