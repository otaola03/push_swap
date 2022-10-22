/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:34:25 by jperez            #+#    #+#             */
/*   Updated: 2022/10/22 13:27:36 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_three(t_Stack *stack_a)
{
	if (stack_a->peek->num > stack_a->peek->next->num)
	{
		ft_swap(stack_a, 'a');
		if (check_order(stack_a) == 1)
			ft_reverse_rotate(stack_a, 'a');
		if (check_order(stack_a) == 1)
			ft_swap(stack_a, 'a');
	}
	else if (stack_a->peek->num < stack_a->peek->next->num)
	{
		ft_reverse_rotate(stack_a, 'a');
		if (check_order(stack_a) == 1)
			ft_swap(stack_a, 'a');
	}
}

void	ft_recolocate_max_min(t_Stack *stack_a, int pos)
{
	if (pos <= 3)
		while (pos-- > 1)
			ft_rotate(stack_a, 'a');
	else if (pos > 3 && stack_a->len == 5)
		while (pos++ < 6)
			ft_reverse_rotate(stack_a, 'a');
	else if (pos == 4)
		while (pos++ < 5)
			ft_reverse_rotate(stack_a, 'a');
}

void	sort_five(t_Stack *stack_a, t_Stack *stack_b)
{
	int	max;
	int	min;

	max = return_max_min(stack_a, stack_a->peek->num, 1);
	ft_recolocate_max_min(stack_a, max);
	ft_push_ab(stack_a, stack_b, 'b');
	if (stack_a->len == 4)
	{
		min = return_max_min(stack_a, stack_a->peek->num, 0);
		ft_recolocate_max_min(stack_a, min);
		ft_push_ab(stack_a, stack_b, 'b');
	}
	if (check_order(stack_a))
		sort_three(stack_a);
	if (stack_a->len == 3)
	{
		ft_push_ab(stack_b, stack_a, 'a');
		if (stack_b->peek)
			ft_push_ab(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else
		ft_push_ab(stack_b, stack_a, 'a');
}

void	push_swap(t_Stack *stack_a, t_Stack *stack_b)
{
	if (check_order(stack_a) == 0)
	{
		destroy_stack(stack_a);
		destroy_stack(stack_b);
		exit(-1);
	}
	if (stack_a->len <= 3)
		sort_three(stack_a);
	else if (stack_a->len <= 5)
		sort_five(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b, ft_get_max_len(stack_a));
}
