/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:33:06 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/25 21:39:03 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

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

// int	ft_printf_str(char *ptr)
// {
// 	int	len;

// 	len = 0;
// 	while (*(ptr + len) != 0)
// 		write(1, (ptr + len++), 1);
// 	return (len);
// }

// int	main(void)
// {
// 	char *c = "A";
// 	int mine;
// 	int or;

// 	mine = ft_printf_str(c);
// 	or = printf("%s", c);
// 	printf("%i, %i", mine, or);
// }

// void va_start(va_list ap, last);
// type va_arg(va_list ap, type);
// void va_end(va_list ap);
// void va_copy(va_list dest, va_list src);

// int	ft_printf(const char *msg, ...)
// {
// 	va_list	args;

// 	va_start(args, msg)

// 	va_copy()
// }
// va_end()

/* '...' is C syntax for a variadic function */

// int max(int num_args, ...)
// {
// 	va_list	args;
// 	int		i;
// 	char	*x;

// 	i = 0;
// 	va_start(args, num_args);
// 	while (i++ < num_args)
// 	{
// 		x = va_arg(args, char *);
// 		printf("x=%s\n", x);
// 	}
// 	va_end(args);
// 	return (0);
// }

// void	print (char *placeholders, ...)
// {
// 	va_list	args;
// 	int		x;
// 	char	y;
// 	char	*z;

// 	va_start(args, placeholders);
// 	while (*placeholders != 0)
// 	{
// 		if (*placeholders == 'd')
// 		{
// 			x = va_arg(args, int);
// 			printf("%d\n", x);
// 		}
// 		else if (*placeholders == 'c')
// 		{
// 			y = va_arg(args, int);
// 			printf("%c\n", y);
// 		}
// 		else if (*placeholders == 's')
// 		{
// 			z = va_arg(args, char *);
// 			printf("%s\n", z);
// 		}
// 		else
// 			printf("%c\n", *placeholders);
// 		placeholders++;
// 	}
// 	va_end(args);
// }

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_str(char *str)
{
	write(1, str, ft_strlen(str));
	return(ft_strlen(str));
}

// int	ft_printf_char(void *arg, int len)
// {
// 	ft_putchar(*((char *)arg), 1);
// 	len++;
// 	return (len);
// }

int	ft_conversions(const char *f_spec, va_list args)
{
	int		len;
	char	*str;

	len = 0;
	if (*f_spec == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (*f_spec == '%')
		len = ft_putchar('%');
	else if (*f_spec == 's')
		len = ft_printf_str(va_arg(args, char *));
	else if (*f_spec == 'i' || *f_spec == 'd')
	{
		str = ft_itoa(va_arg(args, int));
		len = ft_printf_str(str);
		free(str);
	}		
	// 	len = ft_printf_num(*, );
	// else if (*f_spec == 'u')
	// 	len = ;
	// else if (*f_spec == 'x' || *f_spec == 'X')
	// 	len = ft_printf_hex(*, );
	// else if (*f_spec == 'p')
	// 	len = ;
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

int	main(void)
{
	printf("len: %d\n", ft_printf("%d4444d%ctll%%__%s\n", 1235, 'O', "PUTPUT"));
	printf("len original: %d", printf("%d4444d%ctll%%__%s\n", 1235, 'O', "PUTPUT"));
}
