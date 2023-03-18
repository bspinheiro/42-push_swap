/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:49:36 by                   #+#    #+#             */
/*   Updated: 2023/03/18 20:05:07 by bda-silv         ###   ########.fr       */
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

int	validation(char **params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (empty_check(params, i, j) != SUCCESS)
		return (empty_check(params, i, j));
	if (alpha_check(params, i, j) != SUCCESS)
		return (alpha_check(params, i, j));
	if (digit_check(params, i, j) != SUCCESS)
		return (digit_check(params, i, j));
	if (equal_check(params, i, j) != SUCCESS)
		return (equal_check(params, i, j));
	return (SUCCESS);
}

/*
 ** VALIDATION ERRORS
 **
 ** (-1) Empty String
 ** (-2) Alphanumeric
 ** (-3) Signal and Numbers
 ** (-4) INT MAX and INT MIN
 ** (-5) Duplicated
 **
*/
