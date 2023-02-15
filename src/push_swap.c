/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/14 21:05:20 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 1. Validação
 * 		- Parametros na String
 * 		- Parametros fora da String
 * 		- Parametros Mistos
 * 		- Trabalhar negativo solto
 * 		- Error: ""; " "; "-"; "+"; "a"; "int max", "int min"
 * 2. Struct e Listas linkadas
 * 3. Criação dos Movimentos
 * 4. Algoritimo 
 *
 *
 * */

int	main(int argc, char **argv)
{
	int n;
	char *joined, *a, *b;

	n = 1;
	a = argv[1];
	if (argc > 2)
	{
		while (n != argc - 1)
		{
			b = argv[n + 1];
			if (!joined)
				joined = ft_strjoin(ft_strjoin(a, " "), b);
			else
				joined = ft_strjoin(ft_strjoin(joined, " "), b);
			ft_printf("%s\n", joined);
			n++;
		}
	}
	return (0);
}
