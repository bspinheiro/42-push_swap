/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _router.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:49:36 by                   #+#    #+#             */
/*   Updated: 2023/02/21 16:15:55 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*serialize( char **argv)
{
	int		i;
	int		args;
	char	*trimmed;
	char	*joined;

	joined =  NULL;
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
			memfree(trimmed);
		}
		i++;
	}
	return(joined);
}


