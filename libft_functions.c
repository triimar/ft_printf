/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:57:25 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/26 17:08:50 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_intlen(int n)
{
	int				length;
	long long int	div;

	length = 0;
	div = n;
	if (n <= 0)
		length++;
	while (div != 0)
	{
		length++;
		div = div / 10;
	}
	return (length);
}		

static int	ft_is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{	
	char			*n_char;
	int				length;
	long long int	div;

	div = n;
	length = ft_intlen(n);
	n_char = malloc (length + 1);
	if (!n_char)
		return (NULL);
	n_char[length] = 0;
	length = length - 1;
	if (ft_is_neg(n))
	{
		n_char[0] = '-';
		div = -div;
	}
	while (length >= ft_is_neg(n))
	{
		n_char[length] = div % 10 + '0';
		length--;
		div = div / 10;
	}
	return (n_char);
}

