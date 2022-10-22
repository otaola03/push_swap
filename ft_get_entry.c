/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:55:49 by jperez            #+#    #+#             */
/*   Updated: 2022/10/21 18:10:05 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_get_multiple_entry(char **argv, t_Stack *stack)
{
	while (*argv)
		ft_push(stack, ft_atoi(*(argv++), stack));
}

int	ft_get_single_entry(char *argv, t_Stack *stack)
{
	int	cont;

	while (*argv)
	{
		while ((('\t' <= *argv && *argv <= '\r') || *argv == ' ') && *argv)
			argv++;
		if ((*argv == '-' || *argv == '+') && !('0' <= *(argv + 1) \
			&& *(argv + 1) <= '9'))
			return (1);
		cont = 0;
		while (*argv && (('0' <= *argv && *argv <= '9') || *argv == '+'\
			|| *argv == '-'))
		{
			argv++;
			cont++;
		}
		if (cont > 0)
			ft_push(stack, ft_atoi((argv - cont), stack));
	}
	return (0);
}
