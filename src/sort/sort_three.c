/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:36:14 by chpark            #+#    #+#             */
/*   Updated: 2022/03/31 00:19:27 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <stdlib.h>

static int	*temp_init(t_list *a)
{
	int	i;
	int	*temp;

	i = 0;
	temp = (int *)malloc(sizeof(int) * 3);
	if (!temp)
		return (NULL);
	while (i < 2)
	{
		temp[i] = ft_diff(a->arr[i], a->arr[i + 1]);
		i++;
	}
	temp[i] = ft_diff(a->arr[0], a->arr[i]);
	return (temp);
}

static void	temp_sort(t_stacks *stack, int *temp)
{
	if (temp[0] == 0)
	{
		if (temp[1] == 1)
		{
			if (temp[2] == 0)
				ra(stack);
			else
				sa(stack);
		}
		else
		{
			sa(stack);
			rra(stack);
		}
	}
	else if (temp[0] == 1)
	{
		if (temp[2] == 1)
		{
			sa(stack);
			ra(stack);
		}
		else
			rra(stack);
	}
}

int	three_sort(t_stacks *stack)
{
	int	*temp;

	temp = temp_init(stack->stack_a);
	if (!temp)
		return (-1);
	temp_sort(stack, temp);
	free(temp);
	return (1);
}
