/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/07 18:22:16 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 3. Criação dos Movimentos
 * - Movimentos duplos(ss, rr, rrr) 
 * 4. Algoritimo
 * - 3
 * - 5
 *
 * 
 * * REFACTOR:
 *  -  
 *  - unica free?
 *  - makefile (dsym, etc);
 * */

void	show(t_stack *a, t_stack *b)
{
	show_stack(a);
	show_stack(b);
}

int	push_swap(char **params)
{
	t_stack	*a;
	t_stack	*b;

	a = (t_stack *) malloc(sizeof(t_stack));
	if (a == NULL)
		return (FAILURE);
	b = (t_stack *) malloc(sizeof(t_stack));
	if (b == NULL)
		return (FAILURE);
	init_stack(a, 'a');
	init_stack(b, 'b');
	mount_stack(a, params);
	sort_index(a);
	show(a, b);
	show(a, b);
	collapse_stacks(a, b);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	char		*args;
	char		**params;

	if (argc > 1)
	{
		args = serialize(argv);
		params = ft_split(args, ' ');
		if (validate(params, 0, 0) == SUCCESS)
			push_swap(params);
		else
			ft_putstr_fd("Error!", 2);
		free1d(args);
		free2d(params);
	}
	else
		ft_printf("\n");
	return (0);
}
