/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:58:33 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/26 22:32:01 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_u_intlen(unsigned int u)
{
	int				length;
	long long int	div;

	length = 0;
	div = u;
	if (div == 0)
		length++;
	while (div != 0)
	{
		length++;
		div = div / 10;
	}
	return (length);
}		

char	*ft_itoa_u(unsigned int u)
{	
	char			*n_char;
	int				length;
	long long int	div;

	div = u;
	length = ft_u_intlen(u);
	n_char = malloc (length + 1);
	if (!n_char)
		return (NULL);
	n_char[length] = 0;
	length -= 1;
	while (length >= 0)
	{
		n_char[length] = div % 10 + '0';
		length--;
		div = div / 10;
	}
	return (n_char);
}	

static int	ft_x_len(unsigned int dec)
{
	int				length;
	unsigned int	div;

	length = 0;
	div = dec;
	while (div != 0)
	{
		length++;
		div = div / 16;
	}
	return (length);
}		

char	*ft_itoa_hex(unsigned int dec)
{
	char			*x_char;
	int				length;
	unsigned int	div;
	int				reminder;

	div = dec;
	length = ft_x_len(dec);
	x_char = malloc (length + 1);
	if (!x_char)
		return (NULL);
	x_char[length] = 0;
	length -= 1;
	while (length >= 0)
	{
		reminder = div % 16;
		if (reminder < 10)
			x_char[length] = reminder + '0';
		else if (reminder >= 10)
			x_char[length] = (reminder - 10) + 'a';
		length--;
		div = div / 16;
	} 
	return (x_char);
}

int	ft_printf_str(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

// int	ft_printf_char(void *arg, int len)
// {
// 	ft_putchar(*((char *)arg), 1);
// 	len++;
// 	return (len);
// }

int	ft_printf_num(int num)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(num);
	len = ft_printf_str(str);
	free(str);
	return (len);
}

int	ft_printf_u(unsigned int u_num)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa_u(u_num);
	len = ft_printf_str(str);
	free(str);
	return (len);
}

int	ft_printf_hex(unsigned int x_num)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa_hex(x_num);
	len = ft_printf_str(str);
	free(str);
	return (len);
}