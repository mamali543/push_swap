/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:18:33 by mamali            #+#    #+#             */
/*   Updated: 2021/07/01 21:43:42 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

void	sb(t_data *data)
{
	int		tmp;

	if (!data->stack_b || !(data->stack_b)->next)
		return ;
	tmp = (data->stack_b)->value;
	(data->stack_b)->value = (data->stack_b)->next->value;
	(data->stack_b)->next->value = tmp;
}

void	sa(t_data *data)
{
	int	tmp;

	if (!data->stack_a || !(data->stack_a)->next)
		return ;
	tmp = (data->stack_a)->value;
	(data->stack_a)->value = (data->stack_a)->next->value;
	(data->stack_a)->next->value = tmp;
}

int	clear_all(t_data **data)
{
	free_node(&((*data)->stack_a));
	free_node(&((*data)->stack_b));
	free_node(&((*data)->cmd_list));
	free(*data);
	return (1);
}
