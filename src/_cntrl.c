/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cntrl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:26:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 00:15:07 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	how_far(int index, t_stack *stack)
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

int	guess(t_stack *stack)
{
	int	size;
	int	mid;
	int	where;

	size = stack->size;
	mid = (size / 2) + (size % 2);
	where = how_far(0, stack);
	if (where < mid)
		return (1);
	else
		return (-1);
}

int	low_id(t_stack *stack)
{
	t_node	*node;
	int		min_index;

	node = stack->head;
	min_index = node->index;
	while (node->next != NULL)
	{
		if (node->index > node->next->index)
			min_index = node->next->index;
		node = node->next;
	}
	return (min_index);
}

int	top_id(t_stack *stack)
{
	t_node	*node;
	int		high;
	int		temp;

	node = stack->head;
	high = node->index;
	while (node->next != NULL)
	{
		ft_printf("h: %i\n", high);
		if (node->index < node->next->index)
			high = node->next->index;
		node = node->next;
	}
	ft_printf("h: %i\n", high);
	return (high);
}

int	mid_id(t_stack *stack)
{
	t_node	*node;
	int		middle_index;

	node = stack->head;
	while (node->next != NULL)
	{
		if ((node->index != low_id(stack))
			|| (node->index != top_id(stack)))
			middle_index = node->index;
		node = node->next;
	}
	return (middle_index);
}

int	sort_3(t_stack *stack)
{
	int	head;
	int	center;
	int	tail;
	int	top;
	int	mid;

	head = stack->head->index;
	tail = stack->tail->index;
	center = stack->head->next->index;
	top = top_id(stack);
	mid = mid_id(stack);
	show_stack(stack);
//	ft_printf("lower: %i\n", lower_index(stack));
//	ft_printf("higher: %i\n", higher_index(stack));
//	ft_printf("middle: %i\n", middle_index(stack));
	if (is_sorted(stack) == SUCCESS)
		return (SUCCESS);
	if (head == mid && center < tail)
		s(stack);
	else if (head == mid && center > tail)
		rr(stack);
	else if (head == top && center < tail)
		r(stack);
	else if (head == top && center > tail)
	{
		s(stack);
		rr(stack);
	}
	else if (head == low_id(stack) && !is_sorted(stack))
	{
		s(stack);
		r(stack);
	}
	return (SUCCESS);
}

int	sort_4(t_stack *a, t_stack *b)
{
	t_node	*node;

	//show_stack(a);
	node = a->head;
	while (a->head->index != 0)
	{
		if (guess(a) > 1)
			r(a);
		else
			rr(a);
	//	show_stack(a);
	}
	p(a, b);
	//show_stack(a);
	//show_stack(b);
	sort_3(a);
	//show_stack(a);
	p(b, a);
	//show_stack(a);
	//show_stack(b);
	return (SUCCESS);
}

int	sort(t_stack *a, t_stack *b)
{
	t_stack	*stack;

	stack = b;
	stack = a;
	if (is_sorted(stack))
		return (SUCCESS);
	else if (stack->size == 2)
		s(a);
	else if (stack->size == 3)
		sort_3(a);
	else if (stack->size == 4)
		sort_4(a, b);
	return (SUCCESS);
}
