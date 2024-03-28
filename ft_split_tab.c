/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:21:25 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 18:51:12 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	ft_count_values(char **tmp, char c)
{
	char	**s;
	int		values;
	char	*current;

	s = tmp;
	values = 0;
	while (s && *s)
	{
		current = *s;
		while (*current)
		{
			while (*current && (*current == c))
				current++;
			if (*current && !(*current == c))
			{
				values++;
				while (*current && !(*current == c))
					current++;
			}
		}
		s++;
	}
	return (values);
}

static int	ft_strlen_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	return (i);
}

static char	*malloc_word(char *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_c(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[i] && !(s[i] == c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_fill_values(char **tab, char **s, char c, int values)
{
	int	i;

	i = 0;
	tab[values] = NULL;
	while (s && *s)
	{
		while (**s)
		{
			while (**s && (**s == c))
				(*s)++;
			if (**s && !(**s == c))
			{
				tab[i] = malloc_word(*s, c);
				if (!tab)
					return (NULL);
				while (**s && !(**s == c))
					(*s)++;
				i++;
			}
		}
		s++;
	}
	return (tab);
}

char	**ft_split_tab(char **s, char c)
{
	char	**tab;
	int		values;

	values = ft_count_values(s, c);
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (values + 1));
	if (!tab)
		return (NULL);
	tab = ft_fill_values(tab, s, c, values);
	return (tab);
}
