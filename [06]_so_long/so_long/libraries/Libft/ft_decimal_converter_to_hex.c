/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_converter_to_hex.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:19:16 by msimic            #+#    #+#             */
/*   Updated: 2024/01/03 21:19:16 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_decimal_converter_to_hex(char digit, char type)
{
	int	capitalize;

	capitalize = 0;
	if (type == 'X')
		capitalize = 32;
	if (digit > 9)
	{
		if (digit == 10)
			return ('a' - capitalize);
		if (digit == 11)
			return ('b' - capitalize);
		if (digit == 12)
			return ('c' - capitalize);
		if (digit == 13)
			return ('d' - capitalize);
		if (digit == 14)
			return ('e' - capitalize);
		if (digit == 15)
			return ('f' - capitalize);
	}
	else
		return (digit + '0');
	return (0);
}
