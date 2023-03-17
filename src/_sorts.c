/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sorts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:26:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/17 03:13:15 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_3(t_stack *stack){
	int	head;
	int	tail;
	int center;

	head = stack->head->index;
	tail = stack->tail->index;
	center = stack->head->next->index;
	if ((head < center) && (center < tail))
		return (SUCCESS);
	if (head == mid_id(stack) && center < tail)
		s(stack);
	else if (head == mid_id(stack) && center > tail)
		rr(stack);
	else if (head == max_id(stack) && center < tail)
		r(stack);
	else if (head == max_id(stack) && center > tail){
		s(stack);
		rr(stack);
	}
	else if (head == min_id(stack) && center > tail){
		s(stack);
		r(stack);
	}
	return (SUCCESS);
}

int	sort_4(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == SUCCESS)
		return (SUCCESS);
	rotate_min_to_top(a);
	if (!is_sorted(a)){
		p(a, b);
		sort_3(a);
		p(b, a);
	}
	return (SUCCESS);
}

int	sort_5(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == SUCCESS)
		return (SUCCESS);
	rotate_min_to_top(a);
	if (!is_sorted(a))
	{
		p(a, b);
		rotate_min_to_top(a);
		p(a, b);
		sort_3(a);
		p(b, a);
		p(b, a);
	}
	return (SUCCESS);
}

int	get_max_bits(t_stack *stack)
{
	int	count;
	int	n;

	n = max_id(stack);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return ((count * 8));
}

void to_b(t_stack *a, t_stack *b, int bit)
{
	t_node *node;
	node = a->head;
	if (((node->index >> bit) & 1) == 1)
		r(a);
	else
		p(a, b);
}

int radix(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	count;

	i = 0;
	while (i < get_max_bits(a))
	{
		count = 0;
		size = a-> size;
		while (count < size && size != 0)
		{
			to_b(a, b, i);
			count++;
		}
		while (b->size != 0)
			p(b, a);
		i++;
		if (is_sorted(a) == SUCCESS && b->size == 0)
			break;
	}
	return (SUCCESS);
}

int	sort(t_stack *a, t_stack *b)
{
	t_stack	*stack;

	stack = a;
	if (is_sorted(stack))
		return (SUCCESS);
	else if (stack->size == 2)
		s(a);
	else if (stack->size == 3)
		sort_3(a);
	else if (stack->size == 4)
		sort_4(a, b);
	else if (stack->size == 5)
		sort_5(a, b);
	else if (stack->size > 5)
		radix(a, b);
	return (SUCCESS);
}
