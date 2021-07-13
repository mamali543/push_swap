/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:17:19 by mamali            #+#    #+#             */
/*   Updated: 2021/07/01 20:25:11 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_node	*tmp;

	if (!data->stack_b)
		return ;
	tmp = data->stack_b;
	data->stack_b = (data->stack_b)->next;
	tmp->next = data->stack_a;
	data->stack_a = tmp;
}

void	pb(t_data *data)
{
	t_node	*tmp;

	if (!data->stack_a)
		return ;
	tmp = data->stack_a;
	data->stack_a = (data->stack_a)->next;
	tmp->next = data->stack_b;
	data->stack_b = tmp;
}

int	ret(char **str)
{
	free(*str);
	return (1);
}
