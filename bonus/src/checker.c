/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:34:13 by chpark            #+#    #+#             */
/*   Updated: 2022/04/11 22:37:15 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stack;

	stack = push_swap(ac, av);
	checker(ac, av, stack);
	return (0);
}

static char	**ft_cut_command(char *command)
{
	char	**s;

	s = ft_split(command, '\n');
	return (s);
}

static t_stacks	*setup_check(char **str)
{
	t_stacks	*check;
	int			*int_arr;
	int			size;
	int			i;

	size = count_stack_size(str);
	int_arr = (int *)malloc(sizeof(int) * size);
	if (int_arr == NULL)
		exit(ft_put_err(NULL, "Error", str, 1));
	i = -1;
	while (str[++i])
		int_arr[i] = ft_atoi_push_swap(str[i], str);
	check = (t_stacks *)malloc(sizeof(t_stacks));
	if (check == NULL)
		exit(ft_put_err(NULL, "Error", str, 1));
	init_stack_a(check, int_arr, size, str);
	init_stack_b(check, size, str);
	check->command = ft_strdup("");
	if (check->command == NULL)
		exit(ft_put_err(check, "Error", str, 1));
	return (check);
}

int	checker(int ac, char **av, t_stacks *stack)
{
	t_stacks	*check;
	char		**str;
	char		**command;
	int			i;

	i = 0;
	str = av_to_string(av, ac);
	if (!str)
		return (0);
	check = setup_check(str);
	command = ft_cut_command(stack->command);
	ft_put_err(stack, NULL, NULL, 0);
	while (command[i] != NULL)
	{
		if (find_command(command[i], check) != 0)
			i++;
		else
			return (ft_put_err(check, "Error", command, 1));
	}
	if (is_sorted(check->stack_a) == 1)
		return (ft_put_err(check, "OK", command, 0));
	else
		return (ft_put_err(check, "KO", command, 0));
}
