/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:16:43 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 18:38:26 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_head	*head;
	int		values;

	head = ft_give_head();
	head->sb = NULL;
	if (ac >= 2)
	{
		head->sa = ft_build_stack(av, ' ');
		if (!head->sa)
			return (ft_free_head(head));
		if (0 == ft_is_sort(head->sa))
			return (ft_free_head_stack(head, head->sa));
		values = ft_stacksize(head->sa);
		ft_which_algo(&head->sa, &head->sb, values);
		ft_free_stack(head->sa);
	}
	return (ft_free_head(head));
}
