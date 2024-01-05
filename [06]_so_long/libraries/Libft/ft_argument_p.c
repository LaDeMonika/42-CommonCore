/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:07:47 by msimic            #+#    #+#             */
/*   Updated: 2024/01/03 21:07:47 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_argument_p(unsigned long address)
{
	char	*num;
	int		bytes;
	int		i;

	i = 0;
	if (!address)
		return (write(1, "(nil)", sizeof(char) * 5));
	bytes = write(1, "0x", sizeof(char) * 2);
	num = (char *)malloc(((ft_hex_length(address)) + 1) * sizeof(char));
	while (address)
	{
		num[i] = ft_decimal_converter_to_hex(address % 16, 'x');
		address /= 16;
		i++;
	}
	num[i] = '\0';
	bytes += ft_print_reversed_str(num);
	ft_free_ptr(&num);
	return (bytes);
}
