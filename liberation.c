/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:31:33 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/17 17:35:13 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *sa)
{
	t_stack	*tmp;

	if (sa)
	{
		tmp = sa;
		while (sa)
		{
			tmp = sa;
			sa = sa->next;
			free(tmp);
		}
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

char	ft_free_stack_tab(char **tab, t_stack *sa)
{
	ft_free_stack(sa);
	ft_free_tab(tab);
	write(2, "Error", 5);
	return ('f');
}

int	ft_free_head(t_head *head)
{
	free(head);
	return (1);
}

int	ft_free_head_stack(t_head *head, t_stack *sa)
{
	ft_free_stack(sa);
	ft_free_head(head);
	return (1);
}
