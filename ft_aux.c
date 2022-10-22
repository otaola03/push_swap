/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:45:06 by jperez            #+#    #+#             */
/*   Updated: 2022/10/21 20:04:10 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_atoi(const char *str, t_Stack *stack)
{
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if (!(INT_MIN <= num && num <= INT_MAX))
	{
		write(2, "Error\n", 6);
		destroy_stack(stack);
		exit(-1);
	}
	return ((int)(num * sign));
}

int	return_max_min(t_Stack *stack, int peek, int max_or_min)
{
	int		i;
	int		j;
	t_Node	*ptr;

	ptr = stack->peek;
	i = 1;
	j = 1;
	while (ptr)
	{
		if (ptr->num > peek && max_or_min == 1)
		{
			peek = ptr->num;
			j = i;
		}
		else if (ptr->num < peek && max_or_min == 0)
		{
			peek = ptr->num;
			j = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (j);
}

int	check_order(t_Stack *stack)
{
	t_Node	*ptr;

	ptr = stack->peek;
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
