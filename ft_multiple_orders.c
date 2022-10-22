/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_orders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:27:26 by jperez            #+#    #+#             */
/*   Updated: 2022/10/16 18:28:13 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap_ab(t_Stack *stack_a, t_Stack *stack_b)
{
	ft_swap(stack_a, 'a');
	ft_swap(stack_b, 'b');
	write(1, "ss\n", 3);
}

void	ft_rotate_ab(t_Stack *stack_a, t_Stack *stack_b)
{
	ft_rotate(stack_a, 'a');
	ft_rotate(stack_b, 'b');
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate_ab(t_Stack *stack_a, t_Stack *stack_b)
{
	ft_rotate(stack_a, 'a');
	ft_rotate(stack_b, 'b');
	write(1, "rrr\n", 4);
}
