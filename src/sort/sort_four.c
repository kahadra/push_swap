/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:20:16 by chpark            #+#    #+#             */
/*   Updated: 2022/03/31 00:06:14 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	find_min(t_list *a)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (i + count < a->used_size)
	{
		if (a->arr[i] > a->arr[i + count])
		{
			i += count;
			count = 1;
		}
		else
		count++;
	}
	return (i);
}

static int	four_sort_sub(t_stacks *stack, int n)
{
	if (n < 2)
	{
		while (n-- > 0)
			ra(stack);
		if (is_sorted(stack->stack_a) == 0)
		{	
			pb(stack);
			three_sort(stack);
			pa(stack);
		}
		return (1);
	}
	else
	{
		while (n++ < 4)
			rra(stack);
		if (is_sorted(stack->stack_a) == 0)
		{
			pb(stack);
			three_sort(stack);
			pa(stack);
		}
		return (1);
	}
}

int	four_sort(t_stacks *stack)
{
	int	n;

	n = find_min(stack->stack_a);
	if (is_sorted(stack->stack_a) == 0)
		return (four_sort_sub(stack, n));
	else
		return (1);
}
