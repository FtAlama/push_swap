/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:48:53 by alama             #+#    #+#             */
/*   Updated: 2024/08/20 18:06:17 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_num_zero(char *str)
{
	int	zero;
	int	sign;

	sign = 0;
	zero = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		zero++;
		sign = 1;
	}
	while (str[zero] == '0')
		zero++;
	zero -= sign;
	return (zero);
}

int	ft_isanum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		exit(write(2, "Error\n", 6));
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	i = i - ft_check_num_zero(str);
	ft_check_out_int(str, i);
	return (0);
}

static void	if_argc_bigger(int argc, char **argv, t_node **stack)
{
	int	k;

	ft_check_double_nb(argv, 0);
	argc--;
	while (argc > 0)
	{
		if (ft_isanum(argv[argc]) == 1)
		{
			ft_free_stack(stack);
			return ;
		}
		k = ft_atoi(argv[argc]);
		ft_create_node(stack, k);
		argc--;
	}
}

static void	parsing(int argc, char **argv, t_node **stack)
{
	int	i;
	int	k;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ft_check_double_nb(argv, 1);
		i = ft_d_strlen(argv);
		while (i >= 0)
		{
			if (ft_isanum(argv[i]) == 1)
			{
				ft_free_str(argv);
				ft_free_stack(stack);
				return ;
			}
			k = ft_atoi(argv[i]);
			ft_create_node(stack, k);
			i--;
		}
		ft_free_str(argv);
	}
	else if (argc > 2)
		if_argc_bigger(argc, argv, stack);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (2);
	}
	parsing(argc, argv, &stack_a);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	start(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
}
