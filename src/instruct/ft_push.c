/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mojojojo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:35:27 by Mojojojo          #+#    #+#             */
/*   Updated: 2024/08/12 17:43:43 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **stack_a, t_node **stack_b, int print)
{
	t_node	*last;
	t_node	*tmp;

	if ((*stack_a)->next == NULL)
	{
		ft_create_node(stack_b, (*stack_a)->data);
		free(*stack_a);
		ft_print_instruct(print);
		return ;
	}
	last = (*stack_a)->prev;
	tmp = (*stack_a)->prev->prev;
	(*stack_a)->prev = tmp;
	tmp->next = *stack_a;
	ft_create_node(stack_b, last->data);
	last->next = NULL;
	last->prev = NULL;
	free(last);
	ft_print_instruct(print);
}
