/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:22:02 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/25 17:53:43 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

// len, length, is the return value of ft_printf - 
//the lenght of the string printed
// msg, the message string, is the first argument of ft_printf

void	ft_putchar(char c, int fd)
{
	write(1, &c, fd);
}

int	ft_printf(const char *msg, ...)
{
	va_list	args;
	int		len;

	len = 0;
	while (*msg != '\0')
	{
		if (*msg == '%')
			len = len + ft_conversions(msg++, len);
		else
		{
			ft_putchar(*msg, 1);
			len++;
		}
		msg++;
	}
	va_end(args);
	return (len);
}

//finds suitable conversion and prints the target, 
// returns nr of printed characters
// f_spec - the format specifier

int	ft_conversions(char *f_spec, int len)
{
	if (*f_spec == 'c' || *f_spec == '%')
		len = ft_printf_char();
	else if (*f_spec == 's')
		len = ft_printf_str();
	else if (*f_spec == 'i' || *f_spec == 'd')
		len = ft_printf_num(*, );
	else if (*f_spec == 'u')
		len = ;
	else if (*f_spec == 'x' || *f_spec == 'X')
		len = ft_printf_hex(*, );
	else if (*f_spec == 'p')
		len = ;
	return (len);
}

int	ft_printf_char(char *f_spec)
{
	ft_putchar(f_spec++, 1);
	return (1);
}

int	ft_printf_str(char *ptr)
{
	int	len;

	len = 0;
	while (*(ptr + len) != 0)
		write(1, (ptr + len++), 1);
	return (len);
}
