/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:37:33 by chpark            #+#    #+#             */
/*   Updated: 2022/04/12 00:36:07 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	check_p(char *command, t_stacks *check)
{
	if (command[1] == 'a')
	{
		pa(check);
		return (1);
	}
	else if (command[1] == 'b')
	{
		pb(check);
		return (1);
	}
	else
		return (0);
}

static int	check_s(char *command, t_stacks *check)
{
	if (command[1] == 'a')
	{
		sa(check);
		return (1);
	}
	else if (command[1] == 'b')
	{
		sb(check);
		return (1);
	}
	else if (command[1] == 's')
	{
		sa(check);
		sb(check);
		return (1);
	}
	else
		return (0);
}

static int	check_r(char *command, t_stacks *check)
{
	if (command[1] == 'a')
	{
		ra(check);
		return (1);
	}
	else if (command[1] == 'b')
	{
		rb(check);
		return (1);
	}
	else if (command[1] == 'r')
	{
		ra(check);
		rb(check);
		return (1);
	}
	else
		return (0);
}

static int	check_rr(char *command, t_stacks *check)
{
	if (command[2] == 'a')
	{
		rra(check);
		return (1);
	}
	else if (command[2] == 'b')
	{
		rrb(check);
		return (1);
	}
	else if (command[2] == 'r')
	{
		rra(check);
		rrb(check);
		return (1);
	}
	else
		return (0);
}

int	find_command(char *command, t_stacks *check)
{
	if (ft_strlen(command) == 2)
	{	
		if (command[0] == 'p')
			return (check_p(command, check));
		else if (command[0] == 's')
			return (check_s(command, check));
		else
			return (check_r(command, check));
	}
	else if (ft_strlen(command) == 3)
		return (check_rr(command, check));
	else
		return (0);
}
