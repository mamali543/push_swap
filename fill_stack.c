/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:05:48 by mamali            #+#    #+#             */
/*   Updated: 2021/07/01 17:37:18 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int value)
{
	t_node	*result;

	result = (t_node *)malloc(sizeof(t_node));
	result->value = value;
	result->cmd = NULL;
	result->next = NULL;
	return (result);
}

t_node	*create_new_node2(char *str)
{
	t_node	*result;

	result = (t_node *)malloc(sizeof(t_node));
	result->cmd = strdup(str);
	result->next = NULL;
	return (result);
}

t_node	*conv_tab_tolinkedlist(char **argv, int argc, t_data **data)
{
	int		d;
	t_node	*tmp;

	d = 1;
	tmp = NULL;
	while (argv[d])
	{
		if (ft_atoi(argv[d]) > 2147483647 || ft_atoi(argv[d]) < -2147483648)
			ft_puterror("ERROR\n", data);
		d++;
	}
	d = 1;
	while (d < argc)
	{
		add_back(&(tmp), create_new_node(atoi(argv[d])));
		d++;
	}
	return (tmp);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back(t_node **head, t_node *node_to_insert)
{
	node_to_insert->next = NULL;
	if (!*head)
		*head = node_to_insert;
	else
		ft_lstlast(*head)->next = node_to_insert;
}
