/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:44:32 by haslan            #+#    #+#             */
/*   Updated: 2024/03/13 14:55:04 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define W_ERROR	1
# define DW_ERROR	0
# define SPLITR		1
# define NSPLITR	0

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}	t_list;

typedef struct s_ps
{
	t_list	*list_a;
	t_list	*list_b;
	int		len_a;
	int		len_b;
	int		len_arr;
	int		*array;
	int		min_step;
	int		step_a;
	int		step_b;
}	t_ps;

t_ps	*determinate_ps(void);
void	my_exit(t_ps *ps, int code);
void	create_number(int argc, char **argv, t_ps *ps);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
int		all_is_number(char **str);
void	numbers_add_stack(t_ps *ps);
int		ft_peek_list(t_list	*list);
int		ft_pop_list(t_list	*list);
int		ft_add_list(t_list	*list, int value);
int		ft_move_up_list(t_list	*list);
int		ft_push_list(t_list	*dest, t_list	*target);
int		ft_move_down_list(t_list	*list);
int		ft_swap_list(t_list	*list);
void	ft_sa(t_ps	*ps);
void	ft_sb(t_ps	*ps);
void	ft_pa(t_ps	*ps);
void	ft_pb(t_ps	*ps);
void	ft_ra(t_ps	*ps);
void	ft_rb(t_ps	*ps);
void	ft_rra(t_ps	*ps);
void	ft_rrb(t_ps	*ps);
void	sort_array(int	*array, int length, t_ps *ps);
void	ps_sort(t_ps	*ps);
void	free_split_result(char **r_split);
void	free_splitr_and_exit(char **str, t_ps *ps, int flag);
void	olnly_3_number(t_ps *ps);
int		ft_putstr(char *str);
long	ft_abs(long num);
int		ft_min_way_len(int len, int index);
void	set_and_push(t_ps *ps);
int		get_index(t_list *stack, int index);
int		find_min_num_index(t_list *stack);
void	sort_low_numbers(t_ps *ps);
#endif
