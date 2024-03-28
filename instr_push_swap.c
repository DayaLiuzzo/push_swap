/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:32:44 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 18:06:01 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **sa, int i)
{
	t_stack	*tmp;
	t_stack	*head;

	if (sa == NULL || (*sa)->next == NULL)
		return ;
	head = *sa;
	tmp = (*sa)->next;
	(*sa)->next = tmp->next;
	*sa = tmp;
	(*sa)->next = head;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **sb)
{
	swap_a(sb, 1);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack **sa, t_stack **sb)
{
	swap_a(sa, 1);
	swap_b(sb);
	write(1, "ss\n", 3);
}

void	push_a(t_stack **sa, t_stack **sb)
{
	push_b(sb, sa, 1);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **sa, t_stack **sb, int i)
{
	t_stack	*firsta;

	if (sa == NULL)
		return ;
	firsta = *sa;
	*sa = (*sa)->next;
	firsta->next = *sb;
	*sb = firsta;
	if (i == 0)
		write(1, "pb\n", 3);
}
