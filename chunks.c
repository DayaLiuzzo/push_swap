/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:41:58 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/03/11 14:32:11 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_in_chunk(t_stack *sa, int i, int chunksize, t_utils utils)
{
	utils.tmp = ft_findlast(sa);
	utils.stacksize = ft_stacksize(sa);
	utils.chunkleft = utils.stacksize - (chunksize - i);
	utils.tmpleft = utils.chunkleft;
	while (utils.tmp && utils.stacksize != 0)
	{
		utils.prev = ft_find_prev(sa, utils.tmp);
		utils.tmpstack = utils.stacksize - utils.index;
		while (utils.tmp && utils.prev && utils.tmpstack > 1)
		{
			if (utils.tmp->data < utils.prev->data)
				utils.tmpleft--;
			if (utils.tmpleft <= 0 || (utils.tmpleft == 1 && chunksize == 1))
				return (utils.tmp);
			utils.prev = ft_find_prev(sa, utils.prev);
			utils.tmpstack--;
		}
		utils.tmp = ft_find_prev(sa, utils.tmp);
		utils.index++;
		utils.tmpleft = utils.chunkleft - utils.index;
	}
	return (sa);
}

t_stack	*ft_first_in_chunk(t_stack *sa, int i, int chunksize, int index)
{
	t_stack	*tmp;
	t_stack	*current;
	int		chunkleft;
	int		tmpleft;

	tmp = sa;
	chunkleft = ft_stacksize(sa) - (chunksize - i);
	tmpleft = chunkleft;
	while (tmp)
	{
		current = tmp->next;
		while (current)
		{
			if (tmp->data < current->data)
				tmpleft--;
			if (tmpleft <= 0)
				return (tmp);
			current = current->next;
		}
		tmp = tmp->next;
		index++;
		tmpleft = chunkleft - index;
	}
	return (sa);
}

int	ft_chunk_size(t_stack *sa)
{
	int	values;
	int	chunksize;

	values = ft_stacksize(sa);
	if (values <= 100)
		chunksize = values / 6;
	else
		chunksize = values / 12;
	return (chunksize);
}

void	ft_chunk_through(t_stack **sa, t_stack **sb, t_utils utils)
{
	t_stack	*cheapest;
	int		chunksize;
	int		i;

	chunksize = ft_chunk_size(*sa);
	i = 0;
	while (*sa)
	{
		ft_init_utils(&utils);
		utils.tmpfirst = ft_first_in_chunk(*sa, i, chunksize, 0);
		utils.tmpsnd = ft_last_in_chunk(*sa, i, chunksize, utils);
		cheapest = find_cheapest(utils.tmpfirst, utils.tmpsnd, *sa);
		ft_top_cheapest(sa, cheapest, 0);
		check_b(sb);
		push_b(sa, sb, 0);
	}
	while (*sb)
	{
		ft_top_max(sb, 0);
		push_a(sa, sb);
	}
}
