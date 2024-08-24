/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:04:06 by alama             #+#    #+#             */
/*   Updated: 2024/08/20 17:01:00 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int				price;
	struct s_node	*best_friend;
	int				place;
	int				total_cost;
}	t_node;

void	ft_create_node(t_node **stack, int value);
void	ft_swap(t_node **stack, int print);
void	ft_rotate(t_node **stack, int print);
void	ft_reverse_rotate(t_node **stack, int print);
void	ft_free_stack(t_node **stack);
void	ft_push(t_node **stack_a, t_node **stack_b, int print);
void	ft_d_rotate(t_node **stack_a, t_node **stack_b);
void	ft_d_r_rotate(t_node **stack_a, t_node **stack_b);
void	ft_d_swap(t_node **stack_a, t_node **stack_b);
void	start(t_node **a, t_node **b);
void	ft_print_instruct(int print);
int		ft_bigger_nb_stack(t_node **stack);
int		ft_mini_nb_stack(t_node **stack);
void	ft_check_double_nb(char **argv, int alloced);
void	ft_free_str(char **str);
float	ft_average_nb(t_node **stack);
int		ft_nb_stack(t_node **stack);
void	ft_cost(t_node **tmp, t_node **a, int print);
void	ft_sort(t_node **stack, t_node **s_b);
int		ft_is_sort(t_node **stack);
int		ft_is_r_sort(t_node **stack);
void	ft_find_friend(t_node **stack_a, t_node **stack_b);
void	ft_friendship(t_node **stack_a, t_node **stack_b);
void	ft_add_place(t_node **stack);
int		ft_d_strlen(char **str);
void	ft_add_first_friend(t_node **stack_a, t_node **stack_b);
void	ft_add_price(t_node **stack);
int		ft_isanum(char *str);
void	ft_check_out_int(char *str, int i);

#endif
