/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:01:49 by chpark            #+#    #+#             */
/*   Updated: 2022/03/31 17:01:52 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <stdlib.h>

t_stacks	*setup_stack(char **str)
{
	t_stacks	*stacks;
	int			*int_arr;
	int			size;
	int			i;

	size = count_stack_size(str);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	int_arr = (int *)malloc(sizeof(int) * size);
	if (int_arr == NULL)
		exit(ft_put_err(NULL, "Error", str, 1));
	i = -1;
	while (str[++i])
		int_arr[i] = ft_atoi_push_swap(str[i]);
	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	int_arr = make_index_sort(int_arr, size);
	init_stack_a(stacks, int_arr, size);
	init_stack_b(stacks, size);
	stacks->command = ft_strdup("");
	return (stacks);
}

int	count_stack_size(char **str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size])
		size++;
	return (size);
}

int	*make_index_sort(int *arr, int size)
{
	int	*copy_arr;
	int	i;

	copy_arr = (int *)malloc(sizeof(int) * size);
	if (copy_arr == NULL || !check_dup_arr(arr, size))
	{
		free(arr);
		ft_putendl_fd("Malloc Error1", 1);
		exit(1);
	}
	copy_arr = make_copy_arr(copy_arr, arr, size);
	i = ft_sort_int_arr(copy_arr, size);
	if (!i)
	{	
		free(arr);
		free(copy_arr);
		ft_putendl_fd("Already sorted", 1);
		exit(1);
	}
	arr = index_preprocess(copy_arr, arr, size);
	free(copy_arr);
	return (arr);
}

char	**av_to_string(char	**av, int ac)
{
	int		i;
	char	*str;
	char	**result;

	i = 1;
	str = ft_strdup("");
	while (i < ac)
	{
		str = ft_strjoin_push_swap(str, av[i++]);
		if (str == NULL)
		{
			free(str);
			break ;
		}
		str = ft_strjoin_push_swap(str, " ");
	}
	result = ft_split(str, " ");
	return (result);
}

int	ft_put_err(t_stacks *stacks, char *message, char **str, int ret)
{
	int	i;

	i = 0;
	if (stacks)
	{
		if (stacks->stack_a)
			free(stacks->stack_a);
		if (stacks->stack_b)
			free(stacks->stack_b);
	}
	else
	{
		while (str[i] != NULL)
			free(str[i++]);
		free(str);
	}
	if (message != NULL)
		ft_putendl_fd(message, 1);
	return (ret);
}
