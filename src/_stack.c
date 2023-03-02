/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:22:39 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 20:28:59 by bda-silv         ###   ########.fr       */
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
		ft_printf("%i | ", current->value);
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
