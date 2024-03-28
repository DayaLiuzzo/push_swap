/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:47:37 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 15:33:17 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_bigger(t_stack *sa, t_stack *sb)
{
	t_stack	*tmp;

	tmp = sb;
	while (tmp)
	{
		if (sa->data < tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_is_smaller(t_stack *sa, t_stack *sb)
{
	t_stack	*tmp;

	tmp = sb;
	while (tmp)
	{
		if (sa->data > tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
