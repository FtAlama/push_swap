/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mojojojo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:49:29 by Mojojojo          #+#    #+#             */
/*   Updated: 2024/07/22 18:19:51 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_d_rotate(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a, -1);
	ft_rotate(stack_b, -1);
	ft_print_instruct(4);
}
