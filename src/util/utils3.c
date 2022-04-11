/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:55:53 by chpark            #+#    #+#             */
/*   Updated: 2022/04/04 15:56:17 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s1;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i <= start)
		return (ft_strdup(""));
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	ft_strlcpy(s1, (char *)s + start, len + 1);
	return (s1);
}

void	ft_editstr(char *s, size_t n)
{
	size_t	i;

	i = ft_strlen(s);
	while (n > 0)
	{
		s[i - n] = '\0';
		n--;
	}
	return ;
}
