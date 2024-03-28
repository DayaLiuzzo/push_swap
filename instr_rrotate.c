/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:14:22 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 18:07:00 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **sa, int i)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = *sa;
	while (tail && tail->next != NULL)
		tail = tail->next;
	before_tail = *sa;
	while (before_tail && before_tail->next && before_tail->next->next != NULL)
		before_tail = before_tail->next;
	tmp = *sa;
	*sa = tail;
	(*sa)->next = tmp;
	before_tail->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **sb)
{
	reverse_rotate_a(sb, 1);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack **sa, t_stack **sb)
{
	reverse_rotate_a(sa, 1);
	reverse_rotate_b(sb);
	write(1, "rrr\n", 4);
}
