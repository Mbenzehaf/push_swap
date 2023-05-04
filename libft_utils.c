/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 04:38:29 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/02/05 21:33:27 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

t_list	*ft_lstnew(int x)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->arg = x;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		(*lst)->prev = new;
	}
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *(lst);
	if (!new)
		return ;
	if (*(lst))
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = new;
		new->prev = node;
	}
	else
	{
		*(lst) = new;
	}
}
