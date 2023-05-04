/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:25:49 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/01/27 00:25:51 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_3(t_list **stack_x)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_x)->arg;
	b = (*stack_x)->next->arg;
	c = (*stack_x)->next->next->arg;
	if (a < b && b > c && a < c)
	{
		swap_x(*stack_x, "sa\n");
		retate_x(stack_x, "ra\n");
	}
	else if (a > b && b < c && a < c)
		swap_x(*stack_x, "sa\n");
	else if (a < b && b > c && a > c)
		rretate_x(stack_x, "rra\n");
	else if (a > b && b < c && a > c)
		retate_x(stack_x, "ra\n");
	else if (a > b && b > c && a > b)
	{
		swap_x(*stack_x, "sa\n");
		rretate_x(stack_x, "rra\n");
	}
}

int	ft_find_arg(t_list *stack_x, int arg)
{
	int	i;

	i = 0;
	while (stack_x && stack_x->arg != arg)
	{
		stack_x = stack_x->next;
		i++;
	}
	if (!stack_x)
		return (-1);
	return (i);
}

void	sort_5(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	while (data->n_arg > 3)
	{
		n = ft_find_arg(data->stack_a, data->arr[i]);
		while (data->arr[i] != data->stack_a->arg)
		{
			if (n <= data->n_arg / 2)
				retate_x(&data->stack_a, "ra\n");
			else
				rretate_x(&data->stack_a, "rra\n");
		}
		push_x(&data->stack_a, &data->stack_b, "pb\n");
		data->n_arg--;
		i++;
	}
	sort_3(&data->stack_a);
	while (data->stack_b)
		push_x(&data->stack_b, &data->stack_a, "pa\n");
}

void	ft_re_a_push(t_data *data, int arg, int start, int end)
{
	int	n;
	int	n_s;
	int	n_e;

	n_s = data->arr[start];
	n_e = data->arr[end];
	n = ft_find_arg(data->stack_a, arg);
	while (arg != data->stack_a->arg)
	{
		if (n <= data->n_arg / 2)
			retate_x(&data->stack_a, "ra\n");
		else
			rretate_x(&data->stack_a, "rra\n");
	}
	push_x(&data->stack_a, &data->stack_b, "pb\n");
	if (arg < data->arr[data->n_arg / 2])
	{
		if (data->stack_a && (data->stack_a->arg < n_s
				|| data->stack_a->arg > n_e))
			retate_rr(&data->stack_a, &data->stack_b);
		else
			retate_x(&data->stack_b, "rb\n");
	}
}

void	ft_re_b_push(t_data *data, int arg)
{
	int	n;
	int	size;

	size = data->n_arg;
	n = ft_find_arg(data->stack_b, arg);
	while (arg != data->stack_b->arg)
	{
		if ((size - 2 > 0) && data->stack_b->arg == data->arr[size - 1])
		{
			ft_re_b_push(data, data->arr[data->n_arg - 1]);
			ft_re_b_push(data, data->arr[data->n_arg]);
			swap_x(data->stack_a, "sa\n");
			data->n_arg--;
			return ;
		}
		if (n <= size / 2)
			retate_x(&data->stack_b, "rb\n");
		else
			rretate_x(&data->stack_b, "rrb\n");
	}
	push_x(&data->stack_b, &data->stack_a, "pa\n");
}
