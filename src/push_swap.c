/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:01:26 by chpark            #+#    #+#             */
/*   Updated: 2022/03/31 17:01:29 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	int			len;
	t_stacks	*stacks;
	char		**str;

	if (ac < 2)
		return (0);
	str = av_to_string(av, ac);
	if (!str)
		return (0);
	stacks = setup_stack(str);
	ft_sort(stacks, count_stack_size(str));
	free(str);
	len = (int)ft_strlen(stacks->command);
	write(1, stacks->command, len);
	return (free_stack(stacks));
}

void	init_stack_a(t_stacks *stacks, int *src_arr, int size)
{
	int	i;

	stacks->stack_a = (t_list *)malloc(sizeof(t_list));
	if (!stacks->stack_a)
	{
		free(src_arr);
		ft_putendl_fd("Malloc Error2", 1);
		exit(1);
	}
	stacks->stack_a->arr = (int *)malloc(sizeof(int) * size);
	if (!stacks->stack_a->arr)
	{
		free(stacks->stack_a);
		free(src_arr);
		ft_putendl_fd("Malloc Error3", 1);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		stacks->stack_a->arr[i] = src_arr[i];
		i++;
	}
	free(src_arr);
	return ;
}

void	init_stack_b(t_stacks *stacks, int size)
{
	int	i;

	stacks->stack_b = (t_list *)malloc(sizeof(t_list));
	if (!stacks->stack_b)
	{
		free(stacks->stack_a->arr);
		free(stacks->stack_a);
		ft_putendl_fd("Malloc Error4", 1);
		exit(1);
	}
	stacks->stack_b->arr = (int *)malloc(sizeof(int) * size);
	if (!stacks->stack_b->arr)
	{
		free(stacks->stack_b);
		free(stacks->stack_a->arr);
		free(stacks->stack_a);
		ft_putendl_fd("Malloc Error5", 1);
		exit(1);
	}
	i = -1;
	while (++i < size)
		stacks->stack_b->arr[i] = -1;
	stacks->stack_a->used_size = size;
	stacks->stack_b->used_size = 0;
	return ;
}

int	free_stack(t_stacks *stacks)
{
	free(stacks->command);
	free(stacks->stack_a->arr);
	free(stacks->stack_a);
	free(stacks->stack_b->arr);
	free(stacks->stack_b);
	ft_putendl_fd("Done", 1);
	return (1);
}
