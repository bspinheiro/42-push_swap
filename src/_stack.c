/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:22:39 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/06 11:41:37 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	show_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	ft_printf ("Size: %i\n", stack->size);
	while (current != NULL)
	{
		ft_printf("%i ", current->value);
		ft_printf("[%i] | ", current->index);
		current = current->next;
	}
	ft_printf("\n");
}

void	kill_stack(t_stack *stack)
{
	while (stack->head != NULL)
		del_node_on_top(stack);
	free(stack);
}

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
		node  = node->next;
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
	while (index != (stack->size))
	{
		least = least_value(stack);
		ft_printf("least: %i ", least->value);
		least->index = index;
		ft_printf("index: %i \n", least->index);
		show_stack(stack);
		index++;
	}
}
