/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _index.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:21:04 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/14 00:34:32 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_index(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current != NULL)
	{
		current->index = -1;
		current = current->next;
	}
}

t_node	*least_value(t_stack *stack)
{
	t_node	*node;
	t_node	*least;

	node = stack->head;
	least = node;
	while (least->index != -1 && least->next != NULL)
	{
		least = node;
		node = node->next;
	}
	while (node != NULL)
	{
		if (node->index == -1 && (node->value < least->value))
			least = node;
		node = node->next;
	}
	return (least);
}

void	sort_index(t_stack *stack)
{
	t_node	*least;
	int		index;

	index = 0;
	init_index(stack);
	while (index != (stack->size))
	{
		least = least_value(stack);
		least->index = index;
		index++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->head;
	i = 0;
	while (node != NULL)
	{
		if (i != node->index)
			return (FAILURE);
		i++;
		node = node->next;
	}
	return (SUCCESS);
}

