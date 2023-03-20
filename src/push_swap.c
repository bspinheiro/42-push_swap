/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/20 12:25:17 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	sort(a, b);
	collapse_stacks(a, b);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	char		*args;
	char		**params;
	int			error;

	error = empty_check(argv, 0, argc);
	if (argc > 1)
	{
		args = serialize(argv);
		params = ft_split(args, ' ');
		if (validation(params) == SUCCESS && error == SUCCESS)
			push_swap(params);
		else
		{
			error = validation(params) * (-1);
			ft_putstr_fd("Error!\n", 2);
		}
		free1d(args);
		free2d(params);
	}
	else
		ft_printf("\n");
	return (error);
}
