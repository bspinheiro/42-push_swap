/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _node.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:20:30 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/06 18:27:00 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	add_node_on_top(t_stack *stack, int value, int index)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(t_node));
	if (new == NULL)
		return (FAILURE);
	new->value = value;
	new->index = index;
	if (stack->head == NULL)
	{
		new->next = NULL;
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->next = stack->head;
		stack->head = new;
	}
	stack->size++;
	return (SUCCESS);
}

int	add_node_on_bottom(t_stack *stack, int value)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(t_node));
	if (new == NULL)
		return (FAILURE);
	new->value = value;
	new->next = NULL;
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		stack->tail->next = new;
		stack->tail = new;
	}
	stack->size++;
	return (SUCCESS);
}

int	del_node_on_top(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head != NULL)
	{
		tmp = stack->head;
		stack->head = tmp->next;
		stack->size--;
		if (stack->head == NULL)
			stack->tail = NULL;
		free (tmp);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}
