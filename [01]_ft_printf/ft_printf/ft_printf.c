/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:58:35 by msimic            #+#    #+#             */
/*   Updated: 2023/10/03 15:44:57 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]) && str[i + 1])
			{
				count += ft_formats(args, str[i + 1]);
				i++;
			}
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int	main()
{
	char *s = "Monika";
	int a = 42;
	int x = ft_printf("My name is : %s, some number: %0100d", s, a);
	printf("\n");
	printf("Mine: %d\n", x);
	int y = printf("My name is : %s, some number: %0100d", s, a);
	printf("\n");
	printf("Printf: %d", y);
	//int a = ft_printf(NULL);
	printf("%d", a);
}*/
