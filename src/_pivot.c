/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pivot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:06:28 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/14 00:55:43 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate_direction(t_stack *stack)
{
	int	size;
	int	mid;
	int	id;

	size = stack->size;
	mid = (size / 2) + (size % 2);
	id = find_id(min_id(stack), stack);
	if (id < mid)
		return (1);
	else
		return (-1);
}

int	rotate_min_to_top(t_stack *a)
{
	int	i;
	int n;

	if (rotate_direction(a) > 0)
		n = find_id(min_id(a), a);
	else
		n = a->size - find_id(min_id(a), a);
	i = 0;
	while (i != n){
		if (rotate_direction(a) > 0)
			r(a);
		else
			rr(a);
		i++;
	}
	return (SUCCESS);
}

