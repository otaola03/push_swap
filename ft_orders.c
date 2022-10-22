/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:13:56 by jperez            #+#    #+#             */
/*   Updated: 2022/10/21 19:42:08 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_Stack *stack, char c)
{
	t_Node	*first_node;

	if (stack->len > 1)
	{
		first_node = stack->peek;
		stack->peek = first_node->next;
		first_node->next = first_node->next->next;
		stack->peek->next = first_node;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_push_ab(t_Stack *stack_1, t_Stack *stack_2, char c)
{
	t_Node	*aux;

	if (stack_1->peek)
	{
		aux = stack_1->peek;
		stack_1->peek = aux->next;
		aux->next = stack_2->peek;
		stack_2->peek = aux;
	}
	else
	{
		stack_2->peek = stack_1->peek;
		stack_1->peek = stack_1->peek->next;
		stack_2->peek->next = NULL;
	}
	stack_1->len--;
	stack_2->len++;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_Stack *stack, char c)
{
	t_Node	*end_node;

	if (stack->len > 1)
	{
		end_node = stack->peek;
		go_end(stack)->next = end_node;
		stack->peek = end_node->next;
		end_node->next = NULL;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_Stack *stack, char c)
{
	t_Node	*ptr;

	ptr = stack->peek;
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next->next = stack->peek;
	stack->peek = ptr->next;
	ptr->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
