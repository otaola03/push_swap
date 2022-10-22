/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:16:51 by jperez            #+#    #+#             */
/*   Updated: 2022/10/21 19:43:49 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_Node	*return_max_min_node(t_Stack *stack, int max_or_min)
{
	t_Node	*output;
	t_Node	*ptr;

	ptr = stack->peek;
	output = ptr;
	while (ptr)
	{
		if (ptr->num > output->num && max_or_min == 1)
			output = ptr;
		else if (ptr->num < output->num && max_or_min == 0)
			output = ptr;
		ptr = ptr->next;
	}
	return (output);
}

void	ft_assign_max_index(t_Stack *stack)
{
	int		i;
	t_Node	*ptr;
	t_Node	*stack_max;
	t_Node	*max;

	i = stack->len - 1;
	stack_max = return_max_min_node(stack, 1);
	stack_max->index = i--;
	max = stack->peek;
	ptr = stack->peek;
	while (ptr->num < stack_max->num)
	{
		while (ptr)
		{
			if (ptr->num > max->num && ptr->num < stack_max->num)
				max = ptr;
			ptr = ptr->next;
		}
		max->index = i--;
		stack_max = max;
		ptr = stack->peek;
		max = ptr;
	}
}

void	ft_assign_min_index(t_Stack *stack)
{
	int		i;
	t_Node	*ptr;
	t_Node	*stack_min;
	t_Node	*min;

	i = 0;
	stack_min = return_max_min_node(stack, 0);
	stack_min->index = i++;
	min = stack->peek;
	ptr = stack->peek;
	while (ptr->num > stack_min->num)
	{
		while (ptr)
		{
			if (ptr->num < min->num && ptr->num > stack_min->num)
				min = ptr;
			ptr = ptr->next;
		}
		min->index = i++;
		stack_min = min;
		ptr = stack->peek;
		min = ptr;
	}
}

void	ft_assing_index(t_Stack *stack)
{
	ft_assign_min_index(stack);
	ft_assign_max_index(stack);
}
