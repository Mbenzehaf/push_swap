/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:56:25 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/01/26 16:56:29 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_atoi_check(char *str)
{
	int			i;
	int			sign;
	long long	n;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i] && str[i + 1])
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			(ft_putstr("Error \nsome arguments aren't integers\n", 2), exit(1));
		n = n * 10 + (str[i++] - '0');
		if ((n * sign) > INT32_MAX || (n * sign) < INT32_MIN)
			(ft_putstr("Error \n some arguments are bigger than an integer\n", 2),
				exit(1), 0);
	}
	return (n * sign);
}

int	ft_check_dup(t_data *data, int n, int fill_arr)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = data->stack_a;
	while (temp)
	{
		if (fill_arr == 1)
		{
			data->arr[i] = temp->arg;
			i++;
		}
		else if (temp->arg == n)
		{
			ft_putstr("Error \nsome arguments are duplicates\n", 2);
			exit(1);
		}
		if (temp->next && temp->arg > temp->next->arg)
			data->is_sorted = 0;
		temp = temp->next;
	}
	return (n);
}

void	ft_check(t_data *data)
{
	int	i;

	i = 0;
	if (!data->sp[0])
		(ft_putstr("Error \nsome arguments aren't integers\n", 2), exit(1));
	while (data->sp[i])
	{
		ft_lstadd_back(&data->stack_a, ft_lstnew(ft_check_dup(data,
					ft_atoi_check(data->sp[i]), 0)));
		i++;
		data->n_arg++;
	}
}

void	ft_sort_arr(t_data *data)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	data->arr = malloc(data->n_arg * sizeof(int));
	if (!data->arr)
		exit(1);
	ft_check_dup(data, 0, 1);
	while (i < data->n_arg)
	{
		j = i + 1;
		while (j < data->n_arg)
		{
			if (data->arr[j] < data->arr[i])
			{
				temp = data->arr[j];
				data->arr[j] = data->arr[i];
				data->arr[i] = temp;
			}
			j++;
		}
		i++;
	}
}

void	rretate_x(t_list **stack_x, char *str)
{
	t_list	*temp;

	temp = *stack_x;
	if (!stack_x || !*stack_x)
		return ;
	while (temp->next)
		temp = temp->next;
	if (!temp->prev)
		return ;
	temp->prev->next = NULL;
	(temp)->prev = NULL;
	ft_lstadd_front(stack_x, temp);
	if (str)
		ft_putstr(str, 1);
}
