/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:09:07 by alama             #+#    #+#             */
/*   Updated: 2024/07/30 18:01:08 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **stack, int print)
{
	int		tmp;
	t_node	*last;

	if (!stack || !*stack)
		return ;
	last = (*stack)->next;
	if (!last)
		return ;
	if (last->next == *stack)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
	else
	{
		last = (*stack);
		tmp = last->prev->data;
		last->prev->data = last->prev->prev->data;
		last->prev->prev->data = tmp;
	}
	ft_print_instruct(print);
}
