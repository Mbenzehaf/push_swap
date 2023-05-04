/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:41:10 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/02/05 21:34:07 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
