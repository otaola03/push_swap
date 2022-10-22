/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:38:00 by jperez            #+#    #+#             */
/*   Updated: 2022/10/22 13:50:45 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<limits.h>

typedef struct node{
	int			num;
	int			index;
	size_t		bin;
	struct node	*next;
}	t_Node;

typedef struct stack
{
	t_Node	*peek;
	int		len;
}	t_Stack;

typedef struct stacks
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
}	t_Stacks;

/* ----- AUXILIAR FUNCTIONS ----- */

int		ft_atoi(const char *str, t_Stack *stack);
int		return_max_min(t_Stack *stack, int peek, int max_or_min);
void	ft_run_list(t_Stack *stack);
int		check_order(t_Stack *stack);
void	ft_run_index(t_Stack *stack);
void	ft_run_binary(t_Stack *stack);

/* ----- GET ENTRY ----- */

void	ft_get_multiple_entry(char **argv, t_Stack *stack);
int		ft_get_single_entry(char *argv, t_Stack *stack);
int		ft_check_repetitions(t_Stack *stack);

/* ----- CHECK ENTRY ----- */

int		ft_check_multiple(char **argv);
int		ft_check_one(char *argv);
int		ft_checkout(int argc, char **argv);

/* ----- MANEGE LISTS ----- */

t_Stack	*ft_create_stack(void);
void	destroy_stack(t_Stack *stack);
t_Node	*ft_create_node(int num);
void	delete_node(t_Node *node);
void	destroy_stacks(t_Stack *stack_a, t_Stack *stack_b, int option);

/* ----- MANEGE NODES ----- */

void	ft_push(t_Stack *stack, int num);
void	ft_pop(t_Stack *stack);
t_Node	*go_end(t_Stack *stack);

/* ----- ORDERS ----- */

void	ft_swap(t_Stack *stack, char c);
void	ft_push_ab(t_Stack *stack_1, t_Stack *stack_2, char c);
void	ft_rotate(t_Stack *stack, char c);
void	ft_reverse_rotate(t_Stack *stack, char c);

/* ----- MULTIPLE ORDERS ----- */

void	ft_swap_ab(t_Stack *stack_a, t_Stack *stack_b);
void	ft_rotate_ab(t_Stack *stack_a, t_Stack *stack_b);
void	ft_reverse_rotate_ab(t_Stack *stack_a, t_Stack *stack_b);

/* ----- ASSIGN INDEX ----- */

void	ft_assing_index(t_Stack *stack);

/* ----- TO BINARY ----- */

void	ft_list_to_binary(t_Stack *stack);
void	ft_to_binary(int num, size_t *bin);
int		ft_get_max_len(t_Stack *stack);

/* ----- RADIX ----- */

void	ft_radix(t_Stack *stack_a, t_Stack *stack_b, int len);

/* ----- PUSH SWAP ----- */

void	push_swap(t_Stack *stack_a, t_Stack *stack_b);

#endif
