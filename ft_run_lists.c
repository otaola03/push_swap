/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:02:22 by jperez            #+#    #+#             */
/*   Updated: 2022/10/23 12:58:37 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_run_list(t_Stack *stack)
{
	t_Node	*ptr;

	ptr = stack->peek;
	while (ptr->next)
	{
		printf("%d\n", ptr->num);
		ptr = ptr->next;
	}
	if (ptr->num)
	{
	 	printf("%d\n", ptr->num);
		printf("---------\n\n");

	}
}

void	ft_run_index(t_Stack *stack)
{
	t_Node	*ptr;

	ptr = stack->peek;
	while (ptr->next)
	{
		printf("%d\n", ptr->index);
		ptr = ptr->next;
	}
	if (ptr->num)
	{
	 	printf("%d\n", ptr->index);
		printf("---------\n\n");

	}
}

void	ft_run_binary(t_Stack *stack)
{
	t_Node	*ptr;

	ptr = stack->peek;
	while (ptr->next)
	{
		printf("%zu\n", ptr->bin);
		ptr = ptr->next;
	}
	if (ptr->num)
	{
	 	printf("%zu\n", ptr->bin);
		printf("---------\n\n");

	}
}
