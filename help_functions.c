/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:55:24 by mamali            #+#    #+#             */
/*   Updated: 2021/07/01 20:17:35 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_node *stack)
{
	t_node	*tmp;
	int		max;
	int		i;

	tmp = stack;
	i = 1;
	max = -2147483648;
	while (tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == max)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	find_min_pos(t_node *stack)
{
	t_node	*tmp;
	int		min;
	int		i;

	tmp = stack;
	min = 2147483647;
	i = 1;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	exec_inst(char *str, t_data *data)
{
	if (!(strcmp(str, "sa")))
		sa(data);
	else if (!(strcmp(str, "sb")))
		sb(data);
	else if (!(strcmp(str, "ss")))
		ss(data);
	else if (!(strcmp(str, "pa")))
		pa(data);
	else if (!(strcmp(str, "pb")))
		pb(data);
	else if (!(strcmp(str, "ra")))
		ra(data);
	else if (!(strcmp(str, "rb")))
		rb(data);
	else if (!(strcmp(str, "rra")))
		rra(data);
	else if (!(strcmp(str, "rrb")))
		rrb(data);
	else if (!(strcmp(str, "rrr")))
		rrr(data);
	else if (!(strcmp(str, "rr")))
		rr(data);
}

void	exec_save_inst(char *str, t_data *data)
{
	exec_inst(str, data);
	add_back(&(data->cmd_list), create_new_node2(str));
}

int	find_oper(t_data *data, int *i, int pos, int j)
{
	int	len;

	if (j == 0)
		len = lent_stack(data->stack_a);
	else
		len = lent_stack(data->stack_b);
	*i = 0;
	if (pos <= len / 2)
	{
		*i = pos - 1;
		return (1);
	}
	else
	{
		*i = len - pos + 1;
		return (0);
	}
}
