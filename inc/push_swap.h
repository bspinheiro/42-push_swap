/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:00:48 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 20:28:34 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../lib/libft/inc/libft.h"

# define SUCCESS	(1)
# define FAILURE	(0)
# define INT_MAX	(2147483647)
# define INT_MIN	(-2147483648)

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}	t_stack;

/* MODEL  */

/* STACK */
void	init_stack(t_stack *stack);
void	show_stack(t_stack *stack);
void	kill_stack(t_stack *stack);

	/* NODE */
int		add_node_on_top(t_stack *stack, int value);
int		add_node_on_bottom(t_stack *stack, int value);
int		del_node_on_top(t_stack *stack);

/* PARSING */
char	*serialize(char **argv);
int		validate(char **params);
int		array_size(char **pp);

	/* UTILS */
char	*ft_strjoinfree(char *s1, char *s2);
char	**free1d(char *ptr);
char	**free2d(char **pp);
int		ft_wordcount(char const *s, char c);
int		ft_atol(const char *str);

#endif
