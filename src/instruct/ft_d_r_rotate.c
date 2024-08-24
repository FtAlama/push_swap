/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_r_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mojojojo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:51:03 by Mojojojo          #+#    #+#             */
/*   Updated: 2024/07/30 15:40:26 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_d_r_rotate(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate(stack_a, -1);
	ft_reverse_rotate(stack_b, 7);
}
