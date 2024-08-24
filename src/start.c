/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:24:56 by alama             #+#    #+#             */
/*   Updated: 2024/08/19 17:11:39 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_if_argv_is_malloc(int alloced)
{
	int	i;

	if (alloced == 1)
		i = -1;
	else
		i = 0;
	return (i);
}

void	ft_check_double_nb(char **argv, int alloced)
{
	int	i;
	int	nb;
	int	j;

	i = ft_if_argv_is_malloc(alloced);
	nb = 0;
	while (argv[nb] != NULL)
		nb++;
	if (nb == 1)
		exit(ft_isanum(argv[0]));
	nb--;
	while (argv[++i] != NULL && argv[i + 1] != NULL)
	{
		j = i + 1;
		while (argv[j++] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j - 1]))
			{
				if (alloced == 1)
					ft_free_str(argv);
				exit(write(2, "Error\n", 6) - 4);
			}
			nb--;
		}
	}
}

static void	ft_up_or_down(int up, int down, t_node **a, int print)
{
	while (down > 0 && down < up)
	{
		if (print == 1)
			print = 2;
		else if (print == 0)
			print = 3;
		ft_rotate(a, print);
		down--;
	}
	while (up > 0 && up <= down)
	{
		if (print == 1)
			print = 5;
		else if (print == 0)
			print = 6;
		ft_reverse_rotate(a, print);
		up--;
	}
}

void	ft_cost(t_node **tmp, t_node **a, int print)
{
	int		up;
	t_node	*here;
	int		down;

	up = 0;
	down = 0;
	here = *tmp;
	while (here != (*a)->prev)
	{
		up++;
		here = here->prev;
	}
	here = *tmp;
	while (here != (*a)->prev)
	{
		down++;
		here = here->next;
	}
	ft_up_or_down(up, down, a, print);
}

void	start(t_node **a, t_node **b)
{
	t_node	*tmp;
	float	aver;

	if (ft_is_sort(a) == 0)
		return ;
	aver = ft_average_nb(a);
	tmp = (*a)->prev;
	while (ft_nb_stack(a) > 5)
	{
		if (tmp->data > aver)
		{
			ft_cost(&tmp, a, 1);
			ft_push(a, b, 1);
			tmp = (*a)->next;
			aver = ft_average_nb(a);
		}
		tmp = tmp->prev;
	}
	ft_sort(a, b);
}
