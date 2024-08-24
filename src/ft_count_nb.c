/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:10:09 by alama             #+#    #+#             */
/*   Updated: 2024/08/14 13:25:38 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bigger_nb_stack(t_node **stack)
{
	t_node	*tmp;
	int		big;

	tmp = *stack;
	big = (*stack)->prev->data;
	while (tmp != (*stack)->prev)
	{
		if (big < tmp->data)
			big = tmp->data;
		tmp = tmp->next;
	}
	return (big);
}

int	ft_mini_nb_stack(t_node **stack)
{
	t_node	*tmp;
	int		min;

	tmp = *stack;
	min = (*stack)->prev->data;
	while (tmp != (*stack)->prev)
	{
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

float	ft_average_nb(t_node **stack)
{
	float	argv;
	t_node	*tmp;
	int		size;

	tmp = *stack;
	size = ft_nb_stack(stack);
	argv = 0;
	while (1)
	{
		argv += tmp->data;
		tmp = tmp->next;
		if (tmp == *stack)
			break ;
	}
	return (argv / size);
}

int	ft_nb_stack(t_node **stack)
{
	int		i;
	t_node	*s;

	s = (*stack);
	i = 1;
	while (s->next != *stack)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	ft_d_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	i--;
	return (i);
}
