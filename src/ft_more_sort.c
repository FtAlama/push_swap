/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:17:37 by alama             #+#    #+#             */
/*   Updated: 2024/08/14 13:10:15 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (1)
	{
		if (tmp->data < tmp->next->data)
			return (1);
		tmp = tmp->next;
		if (tmp == (*stack)->prev)
			break ;
	}
	return (0);
}

int	ft_is_r_sort(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next != *stack)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_add_price(t_node **stack)
{
	t_node	*tmp;
	int		median;
	int		nb_stack;

	nb_stack = ft_nb_stack(stack);
	median = nb_stack / 2;
	ft_add_place(stack);
	tmp = *stack;
	while (1)
	{
		if (tmp->place == nb_stack - 1)
			tmp->price = 0;
		else if (tmp->place >= median)
		{
			if (nb_stack % 2 == 0)
				tmp->price = nb_stack - tmp->place;
			else
				tmp->price = nb_stack - tmp->place - 1;
		}
		else
			tmp->price = tmp->place + 1;
		tmp = tmp->next;
		if (tmp == *stack)
			break ;
	}
}
