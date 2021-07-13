#include "push_swap.h"

int	rotate_max(t_data *data, int max_i, int max_op)
{
	if (max_i == 1)
	{
		while (max_op--)
			exec_save_inst("rb", data);
	}
	else
	{
		while (max_op--)
			exec_save_inst("rrb", data);
	}
	exec_save_inst("pa", data);
	return (0);
}

void	move_to_a(t_data *data)
{
	int		max_i;
	int		max_op;

	max_op = 0;
	while (data->stack_b)
	{
		max_i = find_max_pos(data->stack_b);
		if (max_i == 2)
		{
			exec_save_inst("sb", data);
			exec_save_inst("pa", data);
		}
		else
		{
			max_i = find_oper(data, &max_op, max_i, 1);
			rotate_max(data, max_i, max_op);
		}
	}
}

int	get_size(t_node *a)
{
	if (lent_stack(a) <= 50)
		return (lent_stack(a) / 2 + 1);
	else if (lent_stack(a) <= 100)
		return (20);
	else if (lent_stack(a) <= 170)
		return (40);
	else
		return (45);
}
