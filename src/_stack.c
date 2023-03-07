/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:22:39 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/07 13:02:32 by bda-silv         ###   ########.fr       */
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
	ft_printf("-----\n  %c \n\n", ft_toupper(stack->name));
}

void	kill_stack(t_stack *stack)
{
	while (stack->head != NULL)
		del_node_on_top(stack);
	free(stack);
}

int	collapse_stacks(t_stack *a, t_stack *b)
{
	kill_stack(a);
	kill_stack(b);
	return (SUCCESS);
}

int	mount_stack(t_stack *a, char **params)
{
	int	i;

	i = 0;
	while (i != array_size(params))
		add_node_on_bottom(a, atol(params[i++]));
	return (SUCCESS);
}
