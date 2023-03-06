/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:22:39 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/06 18:06:50 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_stack *stack, char c)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->name = c;
}

void	show_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	ft_printf ("-%i-\n", stack->size);
	while (current != NULL)
	{
		ft_printf("%i", current->value);
		ft_printf("[%i]\n", current->index);
		current = current->next;
	}
	ft_printf("-----\n  %c   ", ft_toupper(stack->name));
	ft_printf("\n\n");
}

void	kill_stack(t_stack *stack)
{
	while (stack->head != NULL)
		del_node_on_top(stack);
	free(stack);
}
