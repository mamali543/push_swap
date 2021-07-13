/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:53:58 by mamali            #+#    #+#             */
/*   Updated: 2021/07/02 17:00:42 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	is_oper(char *line)
{
	char	**tokens;
	int		i;

	i = 0;
	tokens = ft_split("pa pb sa sb ss ra rb rr rra rrb rrr", ' ');
	while (tokens[i])
	{
		if (!strcmp(tokens[i], line))
		{
			free_tokens(tokens);
			return (1);
		}
		i++;
	}
	free_tokens(tokens);
	return (0);
}

int	log_error(char *err, char **line, t_data **data)
{
	clear_all(data);
	ft_putstr_fd(err, 1);
	free(*line);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_data	*data;

	if (argc <= 2)
		return (0);
	data = malloc(sizeof(t_data));
	init(data);
	check_isdigit(argv, &data);
	data->stack_a = conv_tab_tolinkedlist(argv, argc, &data);
	is_duplicate(data->stack_a, &data);
	while (get_next_line(0, &line))
	{
		if (!is_oper(line))
			return (log_error("Error\n", &line, &data));
		exec_inst(line, data);
		free(line);
	}
	if (is_sorted(data->stack_a) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
