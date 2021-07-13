/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:55:31 by mamali            #+#    #+#             */
/*   Updated: 2021/07/02 17:52:10 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init(data);
	check_isdigit(argv, &data);
	data->stack_a = conv_tab_tolinkedlist(argv, argc, &data);
	is_duplicate(data->stack_a, &data);
	if (argc == 1 || is_sorted(data->stack_a))
		return (clear_all(&data));
	if (lent_stack(data->stack_a) == 2)
		exec_save_inst("sa", data);
	else if (lent_stack(data->stack_a) == 3)
		sort_three_numbers(data);
	else if (lent_stack(data->stack_a) == 4)
		sort_four_num(data);
	else if (lent_stack(data->stack_a) == 5)
		sort_five_num(data);
	else if (lent_stack(data->stack_a) > 5)
		sortmorethanfive(data);
	printlist_cmds(data->cmd_list);
	clear_all(&data);
	return (0);
}
