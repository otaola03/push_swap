/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:26:44 by jperez            #+#    #+#             */
/*   Updated: 2022/10/22 12:42:16 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_Stack	*ft_create_stack(void)
{
	t_Stack	*stack;

	stack = (t_Stack *)malloc(sizeof(t_Stack));
	stack->len = 0;
	stack->peek = NULL;
	return (stack);
}

void	destroy_stack(t_Stack *stack)
{
	while (stack->peek != NULL)
		ft_pop(stack);
	free(stack);
}

t_Node	*ft_create_node(int num)
{
	t_Node	*node;

	node = (t_Node *)malloc(sizeof(t_Node));
	node->num = num;
	node->next = NULL;
	return (node);
}

void	delete_node(t_Node *node)
{
	free(node);
}

void	destroy_stacks(t_Stack *stack_a, t_Stack *stack_b, int option)
{
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	if (option == 1)
		write(2, "Error\n", 6);
	else if (option == 2)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}
