/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:20:14 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/25 18:37:53 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/printf.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
}					t_stack;

typedef struct s_head
{
	t_stack			*sa;
	t_stack			*sb;
}					t_head;

typedef struct s_utils {
	int		index;
	int		stacksize;
	int		tmpstack;
	int		tmpleft;
	int		chunkleft;
	t_stack	*tmp;
	t_stack	*prev;
	t_stack	*tmpfirst;
	t_stack	*tmpsnd;
}				t_utils;

int					ft_is_bigger(t_stack *sa, t_stack *sb);
int					ft_is_smaller(t_stack *sa, t_stack *sb);
int					ft_is_sort(t_stack *sa);
int					ft_stacksize(t_stack *sa);
int					ft_atoi_swap(char *nptr);
int					ft_free_head(t_head *head);
int					ft_free_head_stack(t_head *head, t_stack *sa);
int					main(int ac, char **av);
int					ft_is_sort_decr(t_stack *sa);
char				**ft_split_tab(char **s, char c);
char				**ft_fill_values(char **tab, char **s, char c, int values);
char				ft_checkifint(char *nptr, char **tab, t_stack *sa);
char				ft_free_stack_tab(char **tab, t_stack *sa);
void				ft_top_max(t_stack **sb, int index);
void				ft_which_algo(t_stack **sa, t_stack **sb,
						int values);
void				ft_free_tab(char **tab);
void				ft_free_stack(t_stack *sa);
void				swap_a(t_stack **sa, int i);
void				swap_b(t_stack **sb);
void				swap_ab(t_stack **sa, t_stack **sb);
void				push_a(t_stack **sa, t_stack **sb);
void				push_b(t_stack **sa, t_stack **sb, int i);
void				rotate_a(t_stack **sa, int i);
void				rotate_b(t_stack **sb);
void				rotate_ab(t_stack **sa, t_stack **sb);
void				reverse_rotate_a(t_stack **sa, int i);
void				reverse_rotate_b(t_stack **sb);
void				reverse_rotate_ab(t_stack **sa, t_stack **sb);
void				ft_algo3(t_stack **sa, int first);
void				ft_algo4(t_stack **sa, t_stack **sb, int index);
void				ft_algo100(t_stack **sa, t_stack **sb);
void				ft_top_min(t_stack **sa, int index);
void				ft_chunk_through(t_stack **sa, t_stack **sb, t_utils utils);
void				ft_init_utils(t_utils *utils);
void				check_b(t_stack **sb);
void				ft_top_cheapest(t_stack **sa,
						t_stack *cheapest, int index);
void				ft_top_min_b(t_stack **sb, int index);
t_head				*ft_give_head(void);
t_stack				*ft_last_in_chunk(t_stack *sa, int i, int chunksize,
						t_utils utils);
t_stack				*ft_stacknew(int n);
t_stack				*ft_build_stack(char **av, char c);
t_stack				*ft_checkdoublon(t_stack *sa, char **tab, int count);
t_stack				*ft_find_min(t_stack *sa);
t_stack				*ft_first_in_chunk(t_stack *sa, int i, int chunksize,
						int index);
t_stack				*ft_findlast(t_stack *sa);
t_stack				*ft_find_prev(t_stack *sa, t_stack *current);
t_stack				*find_cheapest(t_stack *first, t_stack *last, t_stack *sa);

t_stack				*ft_find_max(t_stack *sa);
#endif
