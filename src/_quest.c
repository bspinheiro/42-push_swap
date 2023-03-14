/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _quest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:06:28 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/14 00:56:15 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_id(int index, t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->head;
	i = 0;
	while (node->index != index)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	min_id(t_stack *stack)
{
	t_node	*node;
	int		min_index;

	node = stack->head;
	min_index = node->index;
	while (node != NULL)
	{
		if (min_index > node->index)
			min_index = node->index;
		node = node->next;
	}
	return (min_index);
}

int	max_id(t_stack *stack)
{
	t_node	*node;
	int		max_index;

	node = stack->head;
	max_index = node->index;
	while (node != NULL)
	{
		if (max_index < node->index)
			max_index = node->index;
		node = node->next;
	}
	return (max_index);
}

int	mid_id(t_stack *stack)
{
	t_node	*node;
	int		mid;

	node = stack->head;
	if (stack->size != 3)
		return(min_id(stack));
	while (node != NULL)
	{
		if ((node->index != min_id(stack))
			&& (node->index != max_id(stack)))
			mid = node->index;
		node = node->next;
	}
	return (mid);
}
