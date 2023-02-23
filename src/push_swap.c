/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 15:32:45 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 1. Validação
 * 		- Trabalhar negativo solt
 * 		- Error: ""; " "; "-"; "+"; "a"; "int max", "int min", zero, -0, +0,
 * 		no double number;
 * 2. Struct e Listas linkadas
 * 3. Criação dos Movimentos
 * 4. Algoritimo
 *
 *
 * */
static char **p_check(char **pp)
{
	int i = 0;
	int s1 = ft_printf("**pp[0][0] %p\n", &pp[0][0]);
	int s2 = ft_printf("**pp[0] %x\n", pp[0]);

	while(pp[++i])
		;
	ft_printf("**pp    %p\n", pp);
	ft_printf("**pp[0] %p\n", &pp[0]);
	ft_printf("**pp[0][0] %p\n", &pp[0][0]);
	ft_printf("**pp[0] %x\n", pp[0]);
	ft_printf("**s1 %i\n", s1);
	ft_printf("**s2 %i\n", s2);
	return (0);
}

static char	**free_all(char **pp)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (pp == NULL)
		return(0);
	p_check(pp);
	while (pp[++n])
		;
	while (i != n)
	{
		free(pp[i]);
		pp[i] = (void *) 0;
		i++;
	}
	if (pp != NULL)
	{
		free (pp);
		pp = (void *) 0;
	}
	return (0);
}

static int	ft_wordcount(char const *s, char c)
{
	int	wc;

	wc = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		if (*s)
			wc++;
		s = ft_strchr(s, c);
	}
	return (wc);
}

int	main(int argc, char **argv)
{
	char	*args;
	char	**params;
	int		wc;
	int		i;

	i = 0;
	if (argc > 1)
	{
		args = serialize(argv);
		wc = ft_wordcount(args, ' ');
		ft_printf("%s\n", args);
		ft_printf("%i allocations\n", wc);
		params = ft_split(args, ' ');
		while (i < wc)
		{
			ft_printf("%s\n", params[i]);
			i++;
		}
		free_all((void *)args);
		free_all(params);
	}
	else
		ft_printf("\n");
	return (0);
}
