/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _moves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:54:00 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 02:24:44 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	show_move(char move, char s)
{
	if (move == 'R')
		ft_printf("rr");
	else
		ft_printf("%c", move);
	ft_printf("%c\n", s);
	return (SUCCESS);
}

int	s(t_stack *stack)
{
	t_node	*top;
	t_node	*mid;
	t_node	*btm;

	if (stack->size < 2)
		return (FAILURE);
	top = stack->head;
	mid = top->next;
	btm = mid->next;
	stack->head = mid;
	top->next = btm;
	mid->next = top;
	show_move('s', stack->name);
	return (SUCCESS);
}

int	r(t_stack *stack)
{
	t_node	*top;
	t_node	*btm;
	t_node	*new;

	if (stack->size < 2)
		return (FAILURE);
	top = stack->head;
	btm = stack->tail;
	new = top->next;
	stack->head = new;
	btm->next = top;
	top->next = NULL;
	stack->tail = top;
	show_move('r', stack->name);
	return (SUCCESS);
}

int	rr(t_stack *stack)
{
	t_node	*top;
	t_node	*btm;
	t_node	*pen;
	int		i;

	i = 0;
	if (stack->size < 2)
		return (FAILURE);
	top = stack->head;
	btm = stack->tail;
	pen = top;
	while (i++ != (stack->size - 2))
		pen = pen->next;
	stack->head = btm;
	btm->next = top;
	stack->tail = pen;
	pen->next = NULL;
	show_move('R', stack->name);
	return (SUCCESS);
}

int	p(t_stack *send, t_stack *recv)
{
	t_node	*node;
	int		value;
	int		index;

	if (send->size == 0)
		return (FAILURE);
	node = send->head;
	value = node->value;
	index = node->index;
	add_node_on_top(recv, value, index);
	del_node_on_top(send);
	show_move('p', recv->name);
	return (SUCCESS);
}
