/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:05:25 by jperez            #+#    #+#             */
/*   Updated: 2022/10/22 13:50:41 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_Node	*go_end(t_Stack *stack)
{
	t_Node	*ptr;

	if (stack->peek)
	{
		if (stack->peek->next)
		{
			ptr = stack->peek;
			while (ptr->next->next)
				ptr = ptr->next;
			return (ptr->next);
		}
		else
			return (stack->peek);
	}
	return (NULL);
}

void	ft_push(t_Stack *stack, int num)
{
	t_Node	*node;

	node = ft_create_node(num);
	if (stack->peek)
		go_end(stack)->next = node;
	else
		stack->peek = node;
	stack->len++;
}

void	ft_pop(t_Stack *stack)
{
	t_Node	*to_delete;

	if (stack->peek != NULL)
	{
		to_delete = stack->peek;
		stack->peek = stack->peek->next;
		stack->len--;
		delete_node(to_delete);
	}
}
