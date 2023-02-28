/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/28 20:24:17 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 2. Struct e Listas linkadas
 * 3. Criação dos Movimentos
 * 4. Algoritimo
 * */

int	main(int argc, char **argv)
{
	char	*args;
	char	**params;
	int		i;

	i = 0;
	if (argc > 1)
	{
		args = serialize(argv);
		params = ft_split(args, ' ');
		if (validate(params))
			ft_printf("Ready!\n");
		else
			ft_printf("Error!\n");
		free1d(args);
		free2d(params);
	}
	else
		ft_printf("\n");
	return (0);
}
