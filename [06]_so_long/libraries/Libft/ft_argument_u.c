/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:08:09 by msimic            #+#    #+#             */
/*   Updated: 2024/01/03 21:08:09 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unsigned_nbr(unsigned int nbr)
{
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', 1);
	else
	{
		ft_put_unsigned_nbr(nbr / 10);
		ft_put_unsigned_nbr(nbr % 10);
	}
}

int	ft_argument_u(unsigned int nbr)
{
	ft_put_unsigned_nbr(nbr);
	return (ft_decimal_length(nbr));
}
