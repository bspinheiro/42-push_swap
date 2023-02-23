/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 02:06:17 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 1. Validação
 * 		- Trabalhar negativo solto
 * 		- Error: ""; " "; "-"; "+"; "a"; "int max", "int min", zero, -0, +0,
 * 		no double number;
 * 2. Struct e Listas linkadas
 * 3. Criação dos Movimentos
 * 4. Algoritimo
 *
 *
 * */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static size_t	cnt_word(char *s, char c);
static char		*make_p(char *s, char c);
static char		**free_all(char **pp, size_t i);

char	**ft_splitt(char const *str, char c)
{
	char	**pp;
	char	*s;
	size_t	i;

	s = (char *)str;
	pp = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!pp)
		return (0);
	i = 0;
	while (i < cnt_word((char *)str, c))
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
		{
			pp[i] = make_p(s, c);
			if (!pp[i])
				return (free_all(pp, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	printf("cnt_word : %zu\n",cnt_word(s, c));
	if (cnt_word(s, c))      /// 여기요 여기!!!!
		pp[0] = ft_strdup("");
	pp[i] = 0;
	return (pp);
}

static size_t	cnt_word(char *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (s[i - 1] && s[i - 1] == c)
		return (cnt - 1);
	return (cnt);
}

static char	*make_p(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static char	**free_all(char **pp, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(pp[j]);
		pp[j++] = 0;
	}
	free (pp);
	pp = 0;
	return (0);
}


int	main()
{
	char	s1 = 'a';
	char	s2[] = "";
	char	**pp = ft_splitt(s2, s1);

	printf("\n");
	for(int i = 0; i < (int)cnt_word(s2, s1);i++)
	{
		printf("ft   : %s\n", pp[i]);
		free(pp[i]);
	}
	free(pp);
	char s3[] = "sdfsadfasdf";
	pp = ft_splitt(s3, s1);
	for(int i = 0; i < (int)cnt_word(s3, s1);i++)
	{
		printf("ft   : %s\n", pp[i]);
		free(pp[i]);
	}
	free(pp);
	return (0);
}

/*static int	ft_wordcount(char const *s, char c)
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
	int		i;

	i = 0;
	if (argc > 1)
	{
		args = serialize(argv);
		ft_printf("%s\n", args);
		ft_printf("%i\n", ft_wordcount(args, ' '));
		params = ft_splitt(args, ' ');
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
}*/

/*static int	ft_wordcount(char const *s, char c)
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
}*/


