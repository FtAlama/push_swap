/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:58:17 by alama             #+#    #+#             */
/*   Updated: 2024/08/20 18:07:26 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_out_int(char *str, int i)
{
	if (i >= 10)
	{
		if (i > 11 || (i == 10 && ft_strncmp(str, "2147483647", 10) > 0)
			|| (i == 11 && ft_strncmp(str, "-2147483648", 11) > 0))
		{
			write(2, "Error\n", 6);
			exit(2);
		}
	}
}
