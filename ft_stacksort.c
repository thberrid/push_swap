/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:05 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/07 16:51:18 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list		*ft_stacksort(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	int				i;
	int				stack_len;
	static t_algo	algos[4] = {
		{ft_bubble, 3},
		{ft_selection, 15},
		{ft_quicksort, 1000},
	};

	if (ft_isshifted(*stack_a) == 1)
	{
		if (!ft_minimumontop(stack_a, ops))
			return (NULL);
	}
	else
	{
		i = 0;
		stack_len = ft_lstlen(*stack_a);
		while (stack_len > algos[i].limit && i + 1 < 4)
			i += 1;
		algos[i].fn(stack_a, stack_b, ops, ft_lstlen(*stack_a));
		ft_stacksort_post(ops);
	}
	return (*ops);
}
