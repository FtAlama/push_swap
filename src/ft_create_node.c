/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:30:56 by alama             #+#    #+#             */
/*   Updated: 2024/08/14 12:47:47 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_add_next(t_node *last, t_node **stack, t_node *new_node)
{
	while (last->next != *stack)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	(*stack)->prev = new_node;
}

static void	ft_if_not_last(t_node **stack, t_node **new_node)
{
	(*stack)->next = *new_node;
	(*stack)->prev = *new_node;
	(*new_node)->prev = *stack;
}

void	ft_create_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		ft_free_stack(stack);
		return ;
	}
	new_node->data = value;
	if (!stack || !(*stack))
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		return ;
	}
	last = (*stack)->next;
	new_node->next = *stack;
	if (!last)
		ft_if_not_last(stack, &new_node);
	else
		ft_add_next(last, stack, new_node);
}
