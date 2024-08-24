/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:47:54 by alama             #+#    #+#             */
/*   Updated: 2024/08/14 13:10:35 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_place(t_node **stack)
{
	t_node	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp->next != *stack)
	{
		tmp->place = i;
		i++;
		tmp = tmp->next;
	}
	tmp->place = i;
}

static void	ft_if_is_min(int min, t_node *tmp, t_node **stack, t_node **s_b)
{
	int		median;

	median = ft_nb_stack(stack) / 2;
	while (tmp != *stack)
	{
		min = ft_mini_nb_stack(stack);
		ft_add_place(stack);
		median = ft_nb_stack(stack) / 2;
		if (tmp->data == min)
		{
			if (median >= tmp->place)
				while (tmp->next != *stack)
					ft_reverse_rotate(stack, 5);
			else if (median <= tmp->place)
				while (tmp->next != *stack)
					ft_rotate(stack, 2);
			ft_push(stack, s_b, 1);
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_add_min(t_node **stack, t_node **s_b)
{
	t_node	*tmp;
	int		min;

	min = ft_mini_nb_stack(stack);
	if ((*stack)->data == min)
	{
		ft_reverse_rotate(stack, 5);
		ft_push(stack, s_b, 1);
		return ;
	}
	tmp = (*stack)->next;
	ft_if_is_min(min, tmp, stack, s_b);
}

void	ft_sort_three(t_node **stack)
{
	int		max;

	max = ft_bigger_nb_stack(stack);
	if (max == (*stack)->prev->data)
		ft_rotate(stack, 2);
	else if ((*stack)->next->data == max)
		ft_reverse_rotate(stack, 5);
	if ((*stack)->prev->data > (*stack)->next->data)
		ft_swap(stack, 8);
}

void	ft_sort(t_node **stack, t_node **s_b)
{
	if (ft_is_sort(stack) == 0)
		return ;
	if (ft_nb_stack(stack) > 3)
	{
		ft_add_min(stack, s_b);
		ft_add_min(stack, s_b);
		ft_sort_three(stack);
		if (ft_is_r_sort(s_b) == 0)
		{
			while ((*s_b)->next != *s_b)
				ft_push(s_b, stack, 0);
			ft_push(s_b, stack, 0);
		}
		else
		{
			ft_push(s_b, stack, 0);
			ft_push(s_b, stack, 0);
			ft_friendship(stack, s_b);
		}
	}
	else
		ft_sort_three(stack);
}
