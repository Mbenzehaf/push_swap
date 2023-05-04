/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:21:36 by mben-zeh          #+#    #+#             */
/*   Updated: 2022/12/30 04:21:39 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				arg;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_data
{
	char			**sp;
	int				*arr;
	int				n_arg;
	int				count_a;
	int				count_b;
	int				is_sorted;
	t_list			*stack_a;
	t_list			*stack_b;
}					t_data;

t_list				*ft_lstnew(int x);
void				ft_check(t_data *data);
char				**ft_split(char const *s, char c);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_putstr(char *s, int fd);
void				ft_free(char **str);
void				swap_x(t_list *stack_x, char *str);
void				swap_ss(t_list *stack_a, t_list *stack_b);
void				push_x(t_list **stack_x, t_list **stack_y, char *str);
void				retate_x(t_list **stack_x, char *str);
void				rretate_x(t_list **stack_x, char *str);
void				rretate_rr(t_list **stack_a, t_list **stack_b);
void				sort_3(t_list **stack_x);
void				sort_5(t_data *data);
int					ft_check_dup(t_data *data, int n, int check);
void				retate_rr(t_list **stack_a, t_list **stack_b);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
