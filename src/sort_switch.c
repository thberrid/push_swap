/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:43:31 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 17:06:33 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list		*sort_switch(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	int				i;
	int				minimum;
	int				stack_len;
	static t_algo	algos[3] = {
		{bubble, 3},
		{selection, 15},
		{quicksort, 1000},
	};

	if (is_shifted(*stack_a) == 1)
	{
		minimum = findn_min(*stack_a, 1);
		if (!pullup(stack_a, ops, minimum, 'a'))
			return (NULL);
	}
	else
	{
		i = 0;
		stack_len = ft_lstlen(*stack_a);
		while (stack_len > algos[i].limit && i + 1 < 3)
			i += 1;
		algos[i].fn(stack_a, stack_b, ops, ft_lstlen(*stack_a));
		sort_post(ops);
	}
	return (*ops);
}
