/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:41:46 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/02/03 22:41:49 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_x(t_list *stack_x, char *str)
{
	int	temp;

	if (!stack_x || !stack_x->next)
		return ;
	temp = stack_x->arg;
	stack_x->arg = stack_x->next->arg;
	stack_x->next->arg = temp;
	if (str)
		ft_putstr(str, 1);
}

void	swap_ss(t_list *stack_a, t_list *stack_b)
{
	swap_x(stack_a, NULL);
	swap_x(stack_b, NULL);
	ft_putstr("ss\n", 1);
}

void	push_x(t_list **stack_x, t_list **stack_y, char *str)
{
	t_list	*temp;

	temp = *stack_x;
	if (!stack_x || !*stack_x)
		return ;
	*stack_x = (*stack_x)->next;
	if (*stack_x)
		(*stack_x)->prev = NULL;
	ft_lstadd_front(stack_y, temp);
	if (str)
		ft_putstr(str, 1);
}

void	retate_x(t_list **stack_x, char *str)
{
	t_list	*temp;

	temp = *stack_x;
	if (!stack_x || !*stack_x)
		return ;
	*stack_x = (*stack_x)->next;
	if (*stack_x)
		(*stack_x)->prev = NULL;
	temp->next = NULL;
	ft_lstadd_back(stack_x, temp);
	if (str)
		ft_putstr(str, 1);
}

void	retate_rr(t_list **stack_a, t_list **stack_b)
{
	retate_x(stack_a, NULL);
	retate_x(stack_b, NULL);
	ft_putstr("rr\n", 1);
}

//rra /rretate_x(stack_a, "rra\n")
//rrb /rretate_x(stack_b, "rrb\n")
