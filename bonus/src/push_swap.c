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

t_stacks	*push_swap(int ac, char **av)
{
	int			len;
	t_stacks	*stacks;
	char		**str;

	if (ac == 1)
		exit(ft_put_err(NULL, "Error", NULL, 1));
	str = av_to_string(av, ac);
	if (!str)
		exit(0);
	if (count_stack_size(str) <= 1)
		exit(ft_put_err(NULL, "Error", NULL, 1));
	stacks = setup_stack(str);
	if (ft_sort(stacks, count_stack_size(str)) != 1)
		exit(ft_put_err(stacks, "Error", str, 0));
	ft_put_err(NULL, NULL, str, 0);
	len = (int)ft_strlen(stacks->command);
	write(1, stacks->command, len);
	return (stacks);
}

void	init_stack_a(t_stacks *stacks, int *src_arr, int size, char **str)
{
	int	i;

	stacks->stack_a = (t_list *)malloc(sizeof(t_list));
	if (!stacks->stack_a)
	{
		free(src_arr);
		exit(ft_put_err(stacks, "Error", str, 1));
	}
	stacks->stack_a->arr = (int *)malloc(sizeof(int) * size);
	if (!stacks->stack_a->arr)
	{
		free(src_arr);
		exit(ft_put_err(stacks, "Error", str, 1));
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

void	init_stack_b(t_stacks *stacks, int size, char **str)
{
	int	i;

	stacks->stack_b = (t_list *)malloc(sizeof(t_list));
	if (!stacks->stack_b)
		exit(ft_put_err(stacks, "Error", str, 1));
	stacks->stack_b->arr = (int *)malloc(sizeof(int) * size);
	if (!stacks->stack_b->arr)
		exit(ft_put_err(stacks, "Error", str, 1));
	i = -1;
	while (++i < size)
		stacks->stack_b->arr[i] = -1;
	stacks->stack_a->used_size = size;
	stacks->stack_b->used_size = 0;
	return ;
}
