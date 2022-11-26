/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:22:02 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/26 21:32:08 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

// len, length, is the return value of ft_printf - 
//the lenght of the string printed
// msg, the message string, is the first argument of ft_printf

// void	ft_putchar(char c, int fd)
// {
// 	write(1, &c, fd);
// }

//finds suitable conversion and prints the target
// returns nr of printed characters
// f_spec - the format specifier

int	ft_conversions(const char *f_spec, va_list args)
{
	int		len;

	len = 0;
	if (*f_spec == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (*f_spec == '%')
		len = ft_putchar('%');
	else if (*f_spec == 's')
		len = ft_printf_str(va_arg(args, char *));
	else if (*f_spec == 'i' || *f_spec == 'd')
		len = ft_printf_num(va_arg(args, int));
	else if (*f_spec == 'u')
		len = ft_printf_u(va_arg(args, unsigned int));
	else if (*f_spec == 'x' || *f_spec == 'X')
		len = ft_printf_hex(va_arg(args, unsigned int));
	// else if (*f_spec == 'p')
	// 	len = ft_printf_p(va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *msg, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, msg);
	while (*msg != '\0')
	{
		if (*msg == '%')
		{
			msg++;
			len += ft_conversions(msg, args);
		}
		else
			len += ft_putchar(*msg);
		msg++;
	}
	va_end(args);
	return (len);
}

// int	ft_printf_char(char *f_spec)
// {
// 	ft_putchar(f_spec++, 1);
// 	return (1);
// }

// int	ft_printf_str(char *ptr)
// {
// 	int	len;

// 	len = 0;
// 	while (*(ptr + len) != 0)
// 		write(1, (ptr + len++), 1);
// 	return (len);
// }
