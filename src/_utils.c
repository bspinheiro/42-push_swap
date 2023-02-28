/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:53:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/28 17:44:38 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char	**free1d(char *ptr)
{
	if (ptr == NULL)
		return (0);
	free(ptr);
	ptr = NULL;
	return (0);
}

char	**free2d(char **pp)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (pp == NULL)
		return (0);
	while (pp[++n])
		;
	while (i != n)
	{
		free(pp[i]);
		pp[i] = (void *) 0;
		i++;
	}
	free (pp);
	pp = (void *) 0;
	return (0);
}

int	ft_wordcount(char const *s, char c)
{
	int	wc;

	wc = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		if (*s)
			wc++;
		s = ft_strchr(s, c);
	}
	return (wc);
}

int	ft_atol(const char *str)
{
	int		i;
	long	signal;
	long	number;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	signal = 1;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	number = 0;
	while (ft_isdigit((int)str[i]))
		number = (number * 10) + (str[i++] - '0');
	return ((long)(number * signal));
}
