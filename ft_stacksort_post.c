/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_post.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:35:54 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/24 20:05:26 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		ft_remove_push(t_list **all_ops, t_list **op)
{
	t_op	*current;
	t_op	*next;

	current = (t_op *)(*op)->content;
	next = (t_op *)((*op)->next)->content;
	if ((!ft_strcmp(current->name, "pa") && !ft_strcmp(next->name, "pb"))
		|| (!ft_strcmp(current->name, "pb") && !ft_strcmp(next->name, "pa")))
	{
		ft_lstremove(all_ops, (*op)->next, &ft_memerase);
		ft_lstremove(all_ops, *op, &ft_memerase);
		return (1);
	}
	return (0);
}

static t_list	*ft_mergeops(t_list **op, char *merged_name)
{
	t_list	*to_removed;

	ft_strncpy(((t_op *)((*op)->content))->name, merged_name, 4);
	to_removed = (*op)->next;
	(*op)->next = (*op)->next->next;
	ft_lstdelone(&to_removed, &ft_memerase);
	return ((*op)->next);
}

static t_list	*ft_merge_rotandrev(t_list **op)
{
	t_op	*current;
	t_op	*next;

	current = (t_op *)(*op)->content;
	next = (t_op *)(*op)->next->content;
	if ((!ft_strcmp(current->name, "sa") && !ft_strcmp(next->name, "sb"))
		|| (!ft_strcmp(current->name, "sb") && !ft_strcmp(next->name, "sa")))
		return (ft_mergeops(op, "ss"));
	if ((!ft_strcmp(current->name, "ra") && !ft_strcmp(next->name, "rb"))
		|| (!ft_strcmp(current->name, "rb") && !ft_strcmp(next->name, "ra")))
		return (ft_mergeops(op, "rr"));
	if ((!ft_strcmp(current->name, "rra") && !ft_strcmp(next->name, "rrb"))
		|| (!ft_strcmp(current->name, "rrb") && !ft_strcmp(next->name, "rra")))
		return (ft_mergeops(op, "rrr"));
	return ((*op)->next);
}

void			ft_stacksort_post(t_list **ops)
{
	t_list	*current;

	current = *ops;
	while (current && current->next)
		current = ft_merge_rotandrev(&current);
	current = *ops;
	while (current && current->next)
	{
		if (ft_remove_push(ops, &current))
			current = *ops;
		else
			current = current->next;
	}
}
