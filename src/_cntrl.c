/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cntrl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:26:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 02:44:19 by bda-silv         ###   ########.fr       */
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
	int	node1;
	int	node2;
	int	node3;
	int	tmp;
	int	min;

	node1 = stack->head->index;
	node2 = stack->head->next->index;
	node3 = stack->tail->index;
	if (node1 < node2)
		tmp = node1;
	else
		tmp = node2;
	if (tmp < node3)
		min = tmp;
	else
		min = node3;
	return (min);

}

int	top_id(t_stack *stack)
{
	int	node1;
	int	node2;
	int	node3;
	int	tmp;
	int	max;

	node1 = stack->head->index;
	node2 = stack->head->next->index;
	node3 = stack->tail->index;
	if (node1 < node2)
		tmp = node2;
	else
		tmp = node1;
	if (tmp < node3)
		max = node3;
	else
		max = tmp;
	return (max);
}

int	mid_id(t_stack *stack)
{
	t_node	*node;
	int		mid;

	node = stack->head;
	while (node != NULL)
	{
		if ((node->index != low_id(stack))
			&& (node->index != top_id(stack)))
			mid = node->index;
		node = node->next;
	}
	return (mid);
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
	while (node != NULL && node->index != 0)
	{
		if (guess(a) > 1)
			r(a);
		else
			rr(a);
		node = node->next;
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
