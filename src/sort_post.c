/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_post.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:34:44 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/16 21:38:47 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		remove_push(t_list **all_ops, t_list **op)
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

static int		remove_rotandrev(t_list **all_ops, t_list **op)
{
	t_op	*current;
	t_op	*next;

	current = (t_op *)(*op)->content;
	next = (t_op *)((*op)->next)->content;
	if ((!ft_strcmp(current->name, "ra") && !ft_strcmp(next->name, "rra"))
		|| (!ft_strcmp(current->name, "rra") && !ft_strcmp(next->name, "ra"))
		|| (!ft_strcmp(current->name, "rb") && !ft_strcmp(next->name, "rrb"))
		|| (!ft_strcmp(current->name, "rrb") && !ft_strcmp(next->name, "rb")))
	{
		ft_lstremove(all_ops, (*op)->next, &ft_memerase);
		ft_lstremove(all_ops, *op, &ft_memerase);
		return (1);
	}
	return (0);
}

static t_list	*merge_ops(t_list **op, char *merged_name)
{
	ft_strncpy(((t_op *)((*op)->content))->name, merged_name, 4);
	ft_lstremove(op, (*op)->next, &ft_memerase);
	return ((*op)->next);
}

static t_list	*merge_rotandrev(t_list **op)
{
	t_op	*current;
	t_op	*next;

	current = (t_op *)(*op)->content;
	next = (t_op *)(*op)->next->content;
	if ((!ft_strcmp(current->name, "sa") && !ft_strcmp(next->name, "sb"))
		|| (!ft_strcmp(current->name, "sb") && !ft_strcmp(next->name, "sa")))
		return (merge_ops(op, "ss"));
	if ((!ft_strcmp(current->name, "ra") && !ft_strcmp(next->name, "rb"))
		|| (!ft_strcmp(current->name, "rb") && !ft_strcmp(next->name, "ra")))
		return (merge_ops(op, "rr"));
	if ((!ft_strcmp(current->name, "rra") && !ft_strcmp(next->name, "rrb"))
		|| (!ft_strcmp(current->name, "rrb") && !ft_strcmp(next->name, "rra")))
		return (merge_ops(op, "rrr"));
	return ((*op)->next);
}

void			sort_post(t_list **ops)
{
	t_list	*current;

	current = *ops;
	while (current && current->next)
		current = merge_rotandrev(&current);
	current = *ops;
	while (current && current->next)
	{
		if (remove_push(ops, &current))
			current = *ops;
		else if (remove_rotandrev(ops, &current))
			current = *ops;
		else
			current = current->next;
	}
}
