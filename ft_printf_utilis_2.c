/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilis_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:21:16 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/27 20:35:28 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int	ft_printf_hex(unsigned int x_num, char x_case)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa_hex(x_num, x_case);
	len = ft_printf_str(str);
	free(str);
	return (len);
}

int	ft_printf_p(size_t p_dec)
{
	int		len;
	char	*str;

	str = ft_itoa_hex(p_dec, 'x');
	len = ft_printf_str("0x");
	len += ft_printf_str(str);
	free(str);
	return (len);
}