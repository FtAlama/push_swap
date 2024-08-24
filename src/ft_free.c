/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mojojojo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:59:42 by Mojojojo          #+#    #+#             */
/*   Updated: 2024/08/07 12:32:40 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_del(t_node *stack)
{
	stack->next = NULL;
	stack->prev = NULL;
	free(stack);
	stack = NULL;
}

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*s;

	if (!stack || !(*stack))
		return ;
	if ((*stack)->next != NULL)
	{
		s = (*stack)->next;
		while (s != (*stack))
		{
			tmp = s->next;
			ft_del(s);
			s = NULL;
			s = tmp;
		}
	}
	ft_del(*stack);
	*stack = NULL;
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
