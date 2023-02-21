/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/21 17:35:44 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 1. Validação
 * 		- Parametros na String
 * 		- Parametros fora da String
 * 		- Parametros Mistos
 * 		- Trabalhar negativo solto
 * 		- Error: ""; " "; "-"; "+"; "a"; "int max", "int min", zero, -0, +0,
 * 		no double number;
 * 2. Struct e Listas linkadas
 * 3. Criação dos Movimentos
 * 4. Algoritimo
 *
 *
 * */
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

static char	*ft_wordcopy(char const *s, char c, char **strs)
{
	char	*next;

	next = ft_strchr(s, c);
	if (!next || !c)
	{
		next = (char *)s;
		while (*next)
			next++;
	}
	*strs = ft_substr(s, 0, next - s);
	return (next);
}

char	**ft_splitt(char const *s, char c)
{
	char	**strs;
	char	**buf;

	if (!s)
		return (NULL);
	strs = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(*strs));
	if (!strs)
		return (NULL);
	buf = strs;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			s = ft_wordcopy(s, c, strs++);
	}
	*strs = 0;
	return (buf);
}
int	main(int argc, char **argv)
{
	char	*args;
	char	**params;
	int		i
		;

	i = 0;
	if (argc > 1)
	{
		args = serialize(argv);
		ft_printf("%s\n", args);
		ft_printf("%i\n", ft_wordcount(args, ' '));
		params = ft_split(args, ' ');
		while (i < ft_wordcount(args, ' '))
		{			
			ft_printf("%s\n", params[i]);
			i++;
		}
		memfree(args);
		free(params);
	}
	else
		ft_printf("\n");
	return (0);
}
