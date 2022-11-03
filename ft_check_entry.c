/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkouts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:11:31 by jperez            #+#    #+#             */
/*   Updated: 2022/11/03 18:26:59 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_check_multiple(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (1);
		while (argv[i][j])
		{
			if (!(('\t' <= argv[i][j] && argv[i][j] <= '\r') || \
			argv[i][j] == ' ' || ('0' <= argv[i][j] && argv[i][j] <= '9') \
			|| ((argv[i][j] == '+' || argv[i][j] == '-') \
			&& ('0' <= argv[i][j + 1] && argv[i][j + 1]) && argv[i][j - 1] == '\0')))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_one(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '\0')
		return (-1);
	while (argv[i])
	{
		if (!(('\t' <= argv[i] && argv[i] <= '\r') || \
		argv[i] == ' ' || ('0' <= argv[i] && argv[i] <= '9') \
		|| ((argv[i] == '+' || argv[i] == '-') \
		&& ('0' <= argv[i + 1] && argv[i + 1]) && \
		(('\t' <= argv[i - 1] && argv[i - 1] <= '\r') \
		|| argv[i - 1] == ' '))))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkout(int argc, char **argv)
{
	if (argc > 2)
		return (ft_check_multiple(argv));
	else
		return (ft_check_one(*argv));
}

int	ft_check_repetitions(t_Stack *stack)
{
	t_Node	*i;
	t_Node	*j;

	i = stack->peek;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->num == j->num)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
