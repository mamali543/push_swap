/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:06:59 by mamali            #+#    #+#             */
/*   Updated: 2021/07/01 20:21:04 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help(char *str)
{
	int		i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_isdigit(char **tab, t_data **data)
{
	int		i;

	i = 1;
	while (tab[i])
	{
		if (help(tab[i]) == 0)
			ft_puterror("ERRROR!\n", data);
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	long	i;

	i = count * size;
	p = malloc(i);
	if (!p)
		return (0);
	while (i--)
		p[i] = 0;
	return (p);
}
