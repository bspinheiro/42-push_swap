/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:49:36 by                   #+#    #+#             */
/*   Updated: 2023/03/02 20:29:52 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	array_size(char **pp)
{
	int	i;

	i = 0;
	while (pp[++i])
		;
	return (i);
}

char	*serialize(char **argv)
{
	int		i;
	int		args;
	char	*trimmed;
	char	*joined;

	joined = NULL;
	args = 0;
	i = 1;
	while (argv[++args])
		;
	while (i != args)
	{
		trimmed = ft_strtrim(argv[i], " ");
		if (!joined)
			joined = ft_strjoinfree(trimmed, "");
		else
		{
			joined = ft_strjoinfree(joined, " ");
			joined = ft_strjoinfree(joined, trimmed);
			free1d(trimmed);
		}
		i++;
	}
	return (joined);
}

int	validate(char **params)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(params[i]) == 0)
		return (FAILURE);
	while (i != array_size(params))
	{
		if (ft_isalpha(params[i][0]) != 0)
			return (FAILURE);
		j = 0;
		while (j != (int) ft_strlen(params[i]))
		{
			if (params[i][0] == '+' || params[i][0] == '-')
				j++;
			if (!ft_isdigit(params[i][j++]))
				return (FAILURE);
		}
		if (atol(params[i]) > INT_MAX || atol(params[i]) < INT_MIN)
			return (FAILURE);
		j = i + 1;
		while (j != array_size(params))
		{
			if (atol(params[i]) == atol(params[j++]))
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
