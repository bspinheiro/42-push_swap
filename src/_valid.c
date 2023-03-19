/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _valid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:55:11 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/18 23:27:18 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	empty_check(char **params, int i, int j)
{
	(void) j;
	while (i != array_size(params))
	{
		if (ft_strlen(params[i]) == 0)
			return (-1);
		i++;
	}
	return (SUCCESS);
}

int	alpha_check(char **params, int i, int j)
{
	(void) j;
	while (i != array_size(params))
	{
		if (ft_isalpha(params[i][0]) != 0)
			return (-2);
		i++;
	}
	return (SUCCESS);
}

int	digit_check(char **params, int i, int j)
{
	while (i != array_size(params))
	{
		j = 0;
		while (j != (int) ft_strlen(params[i]))
		{
			if ((params[i][0] == '+' || params[i][0] == '-')
					&& ft_isdigit(params[i][1]))
				j++;
			while (ft_isdigit(params[i][j]))
				j++;
			if (j != (int) ft_strlen(params[i]))
				return (-3);
		}
		if (atol(params[i]) > INT_MAX || atol(params[i]) < INT_MIN)
			return (-4);
		i++;
	}
	return (SUCCESS);
}

int	equal_check(char **params, int i, int j)
{
	while (i != array_size(params))
	{
		j = i + 1;
		while (j != array_size(params))
		{
			if (atol(params[i]) == atol(params[j]))
				return (-5);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
