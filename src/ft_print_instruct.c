/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:04:52 by alama             #+#    #+#             */
/*   Updated: 2024/07/30 17:58:14 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_instruct(int print)
{
	if (print == 0)
		ft_printf("pa\n");
	if (print == 1)
		ft_printf("pb\n");
	if (print == 2)
		ft_printf("ra\n");
	if (print == 3)
		ft_printf("rb\n");
	if (print == 4)
		ft_printf("rr\n");
	if (print == 5)
		ft_printf("rra\n");
	if (print == 6)
		ft_printf("rrb\n");
	if (print == 7)
		ft_printf("rrr\n");
	if (print == 8)
		ft_printf("sa\n");
	if (print == 9)
		ft_printf("sb\n");
	if (print == 10)
		ft_printf("ss\n");
}
