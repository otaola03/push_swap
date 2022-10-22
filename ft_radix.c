/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:04:10 by jperez            #+#    #+#             */
/*   Updated: 2022/10/22 13:29:41 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_get_max_len(t_Stack *stack)
{
	size_t	max;
	int		len;

	len = 1;
	max = 0;
	ft_to_binary(stack->len, &max);
	while (max / 10 > 0)
	{
		max /= 10;
		len++;
	}
	return (len);
}

void	ft_organize_stacks(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Node	*ptr;

	ptr = stack_b->peek;
	while (ptr)
	{
		ptr = ptr->next;
		ft_push_ab(stack_b, stack_a, 'a');
	}
}

void	ft_radix(t_Stack *stack_a, t_Stack *stack_b, int len)
{
	int		i;
	int		j;
	t_Node	*ptr;

	i = 0;
	while (i < len)
	{
		ptr = stack_a->peek;
		j = stack_a->len;
		while (ptr && j--)
		{
			if ((ptr->index >> i & 1) == 0)
			{
				ptr = ptr->next;
				ft_push_ab(stack_a, stack_b, 'b');
			}
			else
			{
				ptr = ptr->next;
				ft_rotate(stack_a, 'a');
			}
		}
		ft_organize_stacks(stack_a, stack_b);
		i++;
	}
}
