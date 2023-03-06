/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:22:39 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/06 03:03:15 by bda-silv         ###   ########.fr       */
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
	while (node->next != NULL)
	{
		if (node->value < node->next->value )
			least = node;
		else
			least = node->next;
		node = node->next;
	}
	return (least);
}

void	sort_index(t_stack *stack)
{
	//lsn(stack);
	//ft_printf("least: %i\n", least_value(stack)->value);
	t_node	*least;
	int		index;
	int		i;

	index = 0;
	i = 0;
	while (i != (stack->size))
	{

		least = least_value(stack);
		ft_printf("least: %i ", least->value);
		least->index = index;
		ft_printf("index: %i \n", least->index);
		show_stack(stack);
		index++;
		i++;
	}
}
