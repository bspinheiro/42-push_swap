/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/27 20:59:31 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 1. Validação
 * 		- Trabalhar negativo solt
 * 		- Error: ""; " "; "-"; "+"; "a"; "int max", "int min", zero, -0, +0,
 * 		no double number;
 * 2. Struct e Listas linkadas
 * 3. Criação dos Movimentos
 * 4. Algoritimo
 *
 * */

int	main(int argc, char **argv)
{
	char	*args;
	char	**params;
	int		n;
	int		i;

	i = 0;
	if (argc > 1)
	{
		args = serialize(argv);
		n = ft_wordcount(args, ' ');
		ft_printf("%s - %i allocations\n", args, n);
		params = ft_split(args, ' ');
		while (i < n)
		{
			ft_printf("%s\n", params[i]);
			i++;
		}
		free1d(args);
		free2d(params);
	}
	else
		ft_printf("\n");
	return (0);
}
