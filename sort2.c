/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:15:06 by mamali            #+#    #+#             */
/*   Updated: 2021/07/01 20:28:48 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_less_orequal_to_e(t_data *data, int a, int c)
{
	if (a == 0)
	{
		while (c--)
			exec_save_inst("rra", data);
	}
	else
	{
		while (c--)
			exec_save_inst("ra", data);
	}
}

void	e_greaterthan_c(t_data *data, int b, int e)
{
	if (b == 0)
	{
		while (e--)
			exec_save_inst("rra", data);
	}
	else
	{
		while (e--)
			exec_save_inst("ra", data);
	}
}

int	get_mid(t_node *a, int size)
{
	t_node	*tmp;
	t_node	*head;
	int		true_index;

	head = a;
	while (head)
	{
		tmp = a;
		true_index = 1;
		while (tmp)
		{
			if (head->value > tmp->value)
				true_index++;
			tmp = tmp->next;
		}
		if (true_index == size)
			return (head->value);
		head = head->next;
	}
	return (0);
}

void	move_to_b(t_data *data)
{
	int		a;
	int		b;
	int		c;
	int		e;
	int		mid;

	mid = get_mid(data->stack_a, get_size(data->stack_a));
	while ((get_r_closestnum(data, mid) != 0 || \
	get_l_closestnum(data, mid) != 0) && lent_stack(data->stack_a) >= 2)
	{
		a = find_oper(data, &c, get_r_closestnum(data, mid), 0);
		b = find_oper(data, &e, get_l_closestnum(data, mid), 0);
		if (c <= e)
			c_less_orequal_to_e(data, a, c);
		else
			e_greaterthan_c(data, b, e);
		exec_save_inst("pb", data);
	}
}

void	sortmorethanfive(t_data *data)
{
	while (lent_stack(data->stack_a) >= 2)
		move_to_b(data);
	if (is_sorted(data->stack_a) == 0)
		exec_save_inst("sa", data);
	move_to_a(data);
}
