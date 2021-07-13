/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:00:25 by mamali            #+#    #+#             */
/*   Updated: 2021/06/30 19:52:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_num(t_data *data)
{
	int		pos;
	int		i;
	int		d;

	pos = find_min_pos(data->stack_a);
	i = 0;
	d = find_oper(data, &i, pos, 0);
	if (d == 1)
	{
		while (i--)
			exec_save_inst("ra", data);
	}
	else
	{
		while (i-- > 0)
			exec_save_inst("rra", data);
	}
	exec_save_inst("pb", data);
	sort_four_num(data);
	exec_save_inst("pa", data);
}

void	sort_four_num(t_data *data)
{
	int		pos;
	int		i;
	int		d;

	pos = find_min_pos(data->stack_a);
	i = 0;
	d = find_oper(data, &i, pos, 0);
	if (d == 1)
	{
		while (i-- > 0)
			exec_save_inst("ra", data);
	}
	else
	{
		while (i-- > 0)
			exec_save_inst("rra", data);
	}
	exec_save_inst("pb", data);
	sort_three_numbers(data);
	exec_save_inst("pa", data);
}

void	sort_three_numbers(t_data *data)
{
	t_node		*tmp;
	int			i;

	tmp = data->stack_a;
	i = find_max_pos(data->stack_a);
	if (i == 1)
	{
		exec_save_inst("ra", data);
		if (is_sorted(data->stack_a) == 0)
			exec_save_inst("sa", data);
	}
	if (i == 2)
	{
		exec_save_inst("rra", data);
		if (is_sorted(data->stack_a) == 0)
			exec_save_inst("sa", data);
	}
	if (i == 3)
	{
		if (is_sorted(data->stack_a) == 0)
			exec_save_inst("sa", data);
	}
}
