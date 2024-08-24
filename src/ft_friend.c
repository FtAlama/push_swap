/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_friend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:56:02 by alama             #+#    #+#             */
/*   Updated: 2024/08/14 13:10:50 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_close_friend(t_node **stack)
{
	t_node	*b_tmp;
	t_node	*close_bff;
	int		small;

	small = 2147483647;
	b_tmp = *stack;
	while (1)
	{
		b_tmp->total_cost = b_tmp->price + b_tmp->best_friend->price;
		if (small > b_tmp->total_cost)
		{
			small = b_tmp->total_cost;
			close_bff = b_tmp;
		}
		b_tmp = b_tmp->next;
		if (b_tmp == *stack)
			break ;
	}
	return (close_bff);
}

void	ft_add_first_friend(t_node **stack_a, t_node **stack_b)
{
	t_node	*b_tmp;
	int		min;
	int		b_max;
	t_node	*tmp;

	min = ft_mini_nb_stack(stack_a);
	b_tmp = *stack_b;
	b_max = ft_bigger_nb_stack(stack_b);
	if (b_max > ft_bigger_nb_stack(stack_a))
	{
		tmp = *stack_a;
		while (tmp->data != min)
			tmp = tmp->next;
		ft_cost(&tmp, stack_a, 1);
		b_tmp = *stack_b;
		while (b_tmp->data != b_max)
			b_tmp = b_tmp->next;
		ft_cost(&b_tmp, stack_b, 0);
		ft_push(stack_b, stack_a, 0);
	}
	return ;
}

void	ft_friendship(t_node **stack_a, t_node **stack_b)
{
	t_node	*b_tmp;
	t_node	*close_bff;
	int		nb_stack;
	int		min;

	nb_stack = ft_nb_stack(stack_b) - 1;
	min = ft_mini_nb_stack(stack_a);
	b_tmp = *stack_b;
	ft_add_first_friend(stack_a, stack_b);
	while (nb_stack > 0)
	{
		ft_find_friend(stack_a, stack_b);
		ft_add_price(stack_a);
		ft_add_price(stack_b);
		close_bff = ft_close_friend(stack_b);
		ft_cost(&close_bff->best_friend, stack_a, 1);
		ft_cost(&close_bff, stack_b, 0);
		ft_push(stack_b, stack_a, 0);
		b_tmp = *stack_a;
		nb_stack--;
	}
	b_tmp = *stack_a;
	while (b_tmp->data != min)
		b_tmp = b_tmp->next;
	ft_cost(&b_tmp, stack_a, 1);
}

void	ft_find_friend(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*b_tmp;
	int		max;

	b_tmp = *stack_b;
	while (1)
	{
		max = 2147483647;
		tmp = *stack_a;
		while (1)
		{
			if (max >= tmp->data && tmp->data >= b_tmp->data)
			{
				max = tmp->data;
				b_tmp->best_friend = tmp;
			}
			tmp = tmp->next;
			if (tmp == *stack_a)
				break ;
		}
		b_tmp = b_tmp->next;
		if (b_tmp == *stack_b)
			break ;
	}
}
