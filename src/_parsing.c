/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:49:36 by                   #+#    #+#             */
/*   Updated: 2023/03/07 11:23:45 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	array_size(char **pp)
{
	int	i;

	i = 0;
	while (pp[i])
		i++;
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
	args = array_size(argv);
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

int	validate(char **params, int i, int j)
{
	if (ft_strlen(params[i]) == 0)
		return (-1);
	while (i != array_size(params))
	{
		if (ft_isalpha(params[i][0]) != 0)
			return (-2);
		j = 0;
		while (j != (int) ft_strlen(params[i]))
		{
			if (params[i][0] == '+' || params[i][0] == '-')
				j++;
			if (!ft_isdigit(params[i][j++]))
				return (-3);
		}
		if (atol(params[i]) > INT_MAX || atol(params[i]) < INT_MIN)
			return (-4);
		j = i + 1;
		while (j != array_size(params))
		{
			if (atol(params[i]) == atol(params[j++]))
				return (-5);
		}
		i++;
	}
	return (SUCCESS);
}
