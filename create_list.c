/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:28:11 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/22 16:27:45 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*ft_give_head(void)
{
	t_head	*head;

	head = (t_head *)malloc(sizeof(t_head));
	if (!head)
		exit(1);
	ft_bzero(head, sizeof(t_head));
	return (head);
}

t_stack	*ft_stacknew(int n)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	new->data = n;
	new->next = NULL;
	return (new);
}

int	ft_stacksize(t_stack *sa)
{
	t_stack	*current;
	int		count;

	current = sa;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_stack	*ft_checkdoublon(t_stack *sa, char **tab, int count)
{
	t_stack	*tmp;
	t_stack	*current;

	tmp = sa;
	current = sa;
	count = ft_stacksize(sa);
	if (count > 1)
	{
		while (tmp != NULL)
		{
			current = tmp->next;
			while (current != NULL)
			{
				if (tmp->data == current->data)
				{
					ft_free_stack_tab(tab, sa);
					return (NULL);
				}
				current = current->next;
			}
			tmp = tmp->next;
		}
	}
	ft_free_tab(tab);
	return (sa);
}

t_stack	*ft_build_stack(char **av, char c)
{
	t_stack	*ea;
	t_stack	*sa;
	char	**tab;
	int		i;
	int		n;

	ea = NULL;
	sa = NULL;
	i = 0;
	tab = ft_split_tab(av, c);
	while (tab[i] != NULL)
		i++;
	i = i - 1;
	while (i >= 1)
	{
		if ('f' == ft_checkifint(tab[i], tab, sa))
			return (NULL);
		n = ft_atoi_swap(tab[i]);
		ea = ft_stacknew(n);
		ea->next = sa;
		sa = ea;
		i--;
	}
	return (ft_checkdoublon(sa, tab, 0));
}