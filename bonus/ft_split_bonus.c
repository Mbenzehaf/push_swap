/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:39:37 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/02/03 22:39:44 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_count(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
		i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

int	ft_worldlen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_world(const char *s, char c)
{
	char	*str;
	int		i;
	int		worldlen;

	i = 0;
	worldlen = ft_worldlen(s, c);
	str = malloc(worldlen + 1);
	if (!str)
		return (0);
	while (s[i] && s[i] != c && i < worldlen)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	i = 0;
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < count)
	{
		while (*s == c && *s)
			s++;
		if (*s && *s != c)
		str[i] = ft_world(s, c);
		if (!str[i])
			return (ft_free(str), NULL);
		while (*s != c && *s)
			s++;
		i++;
	}
	str[i] = 0;
	return (str);
}
