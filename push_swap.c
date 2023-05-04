/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:19:39 by mben-zeh          #+#    #+#             */
/*   Updated: 2022/12/30 04:19:42 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rretate_rr(t_list **stack_a, t_list **stack_b)
{
	rretate_x(stack_a, NULL);
	rretate_x(stack_b, NULL);
	ft_putstr("rrr\n", 1);
}

void	re_initialization(int *pos, t_data *data, int offset)
{
	pos[0] -= offset;
	pos[1] += offset;
	if (pos[1] >= data->n_arg || pos[0] < 0)
	{
		pos[0] = 0;
		pos[1] = data->n_arg - 1;
	}
}

void	sort_all(t_data *data, int offset, int middle)
{
	int		pos[2];
	t_list	*temp;

	pos[0] = middle;
	pos[1] = middle;
	temp = NULL;
	while (data->stack_a)
	{
		if (!temp)
		{
			temp = data->stack_a;
			re_initialization(pos, data, offset);
		}
		if (temp->arg >= data->arr[pos[0]] && temp->arg <= data->arr[pos[1]])
		{
			ft_re_a_push(data, temp->arg, pos[0], pos[1]);
			temp = data->stack_a;
		}
		else
			temp = temp->next;
	}
	while (data->stack_b)
		ft_re_b_push(data, data->arr[--data->n_arg]);
}

void	push_swap(t_data *data)
{
	if (data->n_arg == 2)
		swap_x(data->stack_a, "sa\n");
	else if (data->n_arg == 3)
		sort_3(&data->stack_a);
	else if (data->n_arg < 15)
		sort_5(data);
	else if (data->n_arg < 250)
		sort_all(data, data->n_arg / 8, data->n_arg / 2);
	else
		sort_all(data, data->n_arg / 18, data->n_arg / 2);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	i = 1;
	if (ac >= 2)
	{
		data.is_sorted = 1;
		while (i < ac)
		{
			data.sp = ft_split(av[i], ' ');
			ft_check(&data);
			ft_free(data.sp);
			i++;
		}
		ft_sort_arr(&data);
		if (!data.is_sorted)
			push_swap(&data);
	}
	return (0);
}
