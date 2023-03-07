/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/07 11:25:50 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 3. Criação dos Movimentos
 * 4. Algoritimo
 * 
 * * REFACTOR:
 *  - main mais concisa
 *  - unica free?
 *  - makefile (dsym, etc);
 * */

int	main(int argc, char **argv)
{
	char		*args;
	char		**params;
	int			i;
	t_stack		*a;
	t_stack		*b;

	a = (t_stack *) malloc(sizeof(t_stack));
	if (a == NULL)
		return (FAILURE);
	b = (t_stack *) malloc(sizeof(t_stack));
	if (b == NULL)
		return (FAILURE);
	i = 0;
	if (argc > 1)
	{
		args = serialize(argv);
		params = ft_split(args, ' ');
		if (validate(params, 0, 0) == SUCCESS)
		{
			init_stack(a, 'a');
			init_stack(b, 'b');
			while (i != array_size(params))
				add_node_on_bottom(a, atol(params[i++]));
			sort_index(a);
			show_stack(a);
			show_stack(b);
			p(a, b);
			p(a, b);
			show_stack(a);
			show_stack(b);
			kill_stack(a);
			kill_stack(b);
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
