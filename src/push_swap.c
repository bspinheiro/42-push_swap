/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 16:38:16 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/libft/inc/libft.h"
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
char	*ft_strjoinfree(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

void	memfree(void *ptr)
{
	ft_printf("ADR: %p (heap)\n", ptr);
	if (ptr == NULL)
		return ;
	free(ptr);
	ptr = NULL;
	ft_printf("ADR: %p (free)\n\n", ptr);
	return ;
}

char	*trim(char *str)
{
	ft_printf("%s\n", str);
	str = ft_strtrim(str, " ");
	return (str);
}

void	serialize(int argc, char **argv)
{
	int		i;
	char	*trimmed;
	char	*joined;

	joined =  NULL;
	i = 1;
	while (i != argc)
	{
		trimmed = trim(argv[i]);
		ft_printf("%s\n", trimmed);
		if (!joined)
			joined = ft_strjoin(trimmed, "");
		else
		{
			joined = ft_strjoin(joined, " ");
			joined = ft_strjoin(joined, trimmed);
			memfree(trimmed);
		}
		ft_printf("%s\n", joined);
		i++;
	}
	exit(SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		serialize(argc, argv);
	else
		ft_printf("\n");
	return (0);
}
