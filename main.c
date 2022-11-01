/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:56:35 by jperez            #+#    #+#             */
/*   Updated: 2022/11/01 16:48:37 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	int		end;

	end = 0;
	if (argc < 2 || ft_checkout(argc, ++argv) != 0)
	{	
		if (argc >= 2)
			write(2, "Error\n", 6);
		exit(-1);
	}
	stack_a = ft_create_stack();
	stack_b = ft_create_stack();
	if (argc > 2)
		ft_get_multiple_entry(argv, stack_a);
	else
		end = ft_get_single_entry(*argv, stack_a);
	if (ft_check_repetitions(stack_a) == 1 || end == 1)
		destroy_stacks(stack_a, stack_b, 2);
	if (stack_a->len > 5)
		ft_assing_index(stack_a);
	push_swap(stack_a, stack_b);
	destroy_stacks(stack_a, stack_b, 0);
	return (0);
}
