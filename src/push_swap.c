/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:05:16 by bda-silv          #+#    #+#             */
/*   Updated: 2023/03/05 12:46:32 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* TODO
 * 2. Struct e Listas linkadas
 *  - funcao pegar o menor valor e setar como indice 1++; se indice <> 0
 * 3. Criação dos Movimentos
 * 4. Algoritimo
 * 
 * * REFACTOR:
 *  - main, validate
 *  - unica free;
 * */
char **free_double_ptr(char **pp) {
   	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (pp == NULL)
		return (0);
	if (*pp == NULL)
	{
		free(pp);
		pp = NULL;
		return (0);
	}
	while (pp[++n])
		;
	while (i != n)
	{
		free(pp[i]);
		pp[i] = (void *) 0;
		i++;
	}
	free (pp);
	pp = (void *) 0;
	return (0);
}
/* 
if (pptr == NULL) {
        return;
    }
    if (*pptr == NULL) {
        free(pptr);
        pptr = NULL;
        return;
    }
    free(*pptr);
    *pptr = NULL;
    free(pptr);
    pptr = NULL;
}
*/

int	main(int argc, char **argv)
{
	char		*args;
	char		**params;
	int			i;
	t_stack		*a;

	a = (t_stack *) malloc(sizeof(t_stack));
	if (a == NULL)
		return (FAILURE);
	i = 0;
	if (argc > 1)
	{
		args = serialize(argv);
		params = ft_split(args, ' ');
		if (validate(params))
		{
			init_stack(a);
			while (i != array_size(params))
				add_node_on_bottom(a, atol(params[i++]));
			show_stack(a);
			kill_stack(a);
		}
		else
			ft_printf("Error!\n");
		free_double_ptr((char **)args);
		free_double_ptr(params);
	}
	else
		ft_printf("\n");
	return (0);
}
