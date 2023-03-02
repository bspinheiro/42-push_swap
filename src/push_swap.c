/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 20:43:13 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 2. Struct e Listas linkadas
 *  - funcao pegar o menor valor e setar como indice 1++; se indice <> 0
 * 3. Criação dos Movimentos
 * 4. Algoritimo
 * 
 * * REFACTOR:
 *  - main, validate
 *  - unica free;
 * */
int	main(int argc, char **argv)
{
	char		*args;
	char		**params;
	int			i;
	t_stack		*a;

	a = (t_stack *) malloc(sizeof(t_stack));
	if (a == NULL)
		return (FAILURE);
	i = 0;
	if (argc > 1)
	{
		args = serialize(argv);
		params = ft_split(args, ' ');
		if (validate(params))
		{
			init_stack(a);
			while (i != array_size(params))
				add_node_on_bottom(a, atol(params[i++]));
			show_stack(a);
			kill_stack(a);
		}
		else
			ft_printf("Error!\n");
		free1d(args);
		free2d(params);
	}
	else
		ft_printf("\n");
	return (0);
}
