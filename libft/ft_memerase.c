/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memerase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:23:00 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/12 14:25:15 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_memerase(void *ap, size_t size)
{
	ft_bzero(ap, size);
	ft_memdel(&ap);
}
