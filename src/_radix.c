/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _radix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:54:51 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/17 14:16:30 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	count;
	int	n;

	n = max_id(stack);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return ((count * 8));
}

void	send_to_b(t_stack *a, t_stack *b, int bit)
{
	t_node	*node;

	node = a->head;
	if (((node->index >> bit) & 1) == 1)
		r(a);
	else
		p(a, b);
}

int	radix(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	count;

	i = 0;
	while (i < get_max_bits(a))
	{
		count = 0;
		size = a-> size;
		while (count < size && size != 0)
		{
			send_to_b(a, b, i);
			count++;
		}
		while (b->size != 0)
			p(b, a);
		i++;
		if (is_sorted(a) == SUCCESS && b->size == 0)
			break ;
	}
	return (SUCCESS);
}
