/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:00:48 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/27 09:25:13 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../lib/libft/inc/libft.h"

# define SUCCESS	(0)
# define FAILURE	(1)

/* MODEL  */

/* CONTROLLER */

/* VIEW */

/* ROUTER */
char	*serialize(char **argv);

/* UTILS */
char	*ft_strjoinfree(char *s1, char *s2);
char	**free1d(char *ptr);
char	**free2d(char **pp);
int		ft_wordcount(char const *s, char c);

#endif
