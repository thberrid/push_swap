/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:08:31 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/14 16:09:57 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_addrswap(void **addra, void **addrb)
{
	void	*tmp;

	tmp = *addra;
	*addra = *addrb;
	*addrb = tmp;
}
