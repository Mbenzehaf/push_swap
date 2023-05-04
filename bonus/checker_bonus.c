/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:48:19 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/02/05 20:48:32 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rretate_rr(t_list **stack_a, t_list **stack_b)
{
	rretate_x(stack_a, NULL);
	rretate_x(stack_b, NULL);
	ft_putstr("rrr\n", 1);
}

void	ft_cmp_exec(char *str, t_data *data)
{
	if (!ft_strncmp(str, "sa\n", 4))
		swap_x(data->stack_a, NULL);
	else if (!ft_strncmp(str, "sb\n", 4))
		swap_x(data->stack_b, NULL);
	else if (!ft_strncmp(str, "ss\n", 4))
		(swap_x(data->stack_a, NULL), swap_x(data->stack_b, NULL));
	else if (!ft_strncmp(str, "pa\n", 4))
		push_x(&data->stack_b, &data->stack_a, NULL);
	else if (!ft_strncmp(str, "pb\n", 4))
		push_x(&data->stack_a, &data->stack_b, NULL);
	else if (!ft_strncmp(str, "ra\n", 4))
		retate_x(&data->stack_a, NULL);
	else if (!ft_strncmp(str, "rb\n", 4))
		retate_x(&data->stack_b, NULL);
	else if (!ft_strncmp(str, "rr\n", 4))
		(retate_x(&data->stack_a, NULL), retate_x(&data->stack_b, NULL));
	else if (!ft_strncmp(str, "rra\n", 4))
		rretate_x(&data->stack_a, NULL);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rretate_x(&data->stack_b, NULL);
	else if (!ft_strncmp(str, "rrr\n", 4))
		(rretate_x(&data->stack_a, NULL), rretate_x(&data->stack_b, NULL));
	else
		(ft_putstr("Error\n", 2), free(str), exit(1));
	free(str);
}

void	checker(t_data *data)
{
	char	*str;

	str = get_next_line(0);
	if (!str)
		return ;
	ft_cmp_exec(str, data);
	checker(data);
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
		checker(&data);
		data.is_sorted = 1;
		ft_check_dup(&data, 0, 1);
		if (data.is_sorted && !data.stack_b)
			ft_putstr("\x1B[32mOK\n", 1);
		else
			ft_putstr("\x1B[33mKO\n", 1);
	}
	return (0);
}
