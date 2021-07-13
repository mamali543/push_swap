/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:38:49 by mamali            #+#    #+#             */
/*   Updated: 2021/07/01 17:37:26 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_l_closestnum(t_data *data, int p)
{
	int		i;
	t_node	*tmp;

	i = 1;
	tmp = data->stack_a;
	while (tmp)
	{
		if (tmp->value < p)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	get_r_closestnum(t_data *data, int	num)
{
	t_node	*tmp;
	int		min;
	int		i;

	min = 0;
	tmp = data->stack_a;
	while (tmp)
	{
		if (tmp->value < num)
			min = tmp->value;
		tmp = tmp->next;
	}
	i = 1;
	tmp = data->stack_a;
	while (tmp)
	{
		if (min == tmp->value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}

void	init(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->cmd_list = NULL;
}

int	is_duplicate(t_node *stack, t_data **data)
{
	t_node	*tmp;
	t_node	*head;
	int		num;

	head = stack;
	while (stack)
	{
		tmp = head;
		num = 0;
		while (tmp)
		{
			if (tmp->value == stack->value)
			{
				num++;
				if (num > 1)
					ft_puterror("ERROR\n", data);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
