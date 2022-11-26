/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:33:06 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/26 22:13:11 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <limits.h>



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

// int	ft_conversions(const char *f_spec, va_list args)
// {
// 	int		len;

// 	len = 0;
// 	if (*f_spec == 'c')
// 		len = ft_putchar(va_arg(args, int));
// 	else if (*f_spec == '%')
// 		len = ft_putchar('%');
// 	else if (*f_spec == 's')
// 		len = ft_printf_str(va_arg(args, char *));
// 	else if (*f_spec == 'i' || *f_spec == 'd')
// 		len = ft_printf_num(va_arg(args, int));
// 	else if (*f_spec == 'u')
//  		len = ft_printf_u(va_arg(args, unsigned int));
// 	// else if (*f_spec == 'x' || *f_spec == 'X')
// 	// 	len = ft_printf_hex(*, );
// 	// else if (*f_spec == 'p')
// 	// 	len = ;
// 	return (len);
// }

// int	ft_printf(const char *msg, ...)
// {
// 	va_list	args;
// 	int		len;

// 	len = 0;
// 	va_start(args, msg);
// 	while (*msg != '\0')
// 	{
// 		if (*msg == '%')
// 		{
// 			msg++;
// 			len += ft_conversions(msg, args);
// 		}
// 		else
// 			len += ft_putchar(*msg);
// 		msg++;
// 	}
// 	va_end(args);
// 	return (len);
// }

int	main(void)
{
	
	// printf("len: %d\n", ft_printf("%d4444d%ctll%%__%s\n", -1235, 'O', "PUTPUT"));
	// printf("len orig: %d\n", printf("%d4444d%ctll%%__%s\n", -1235, 'O', "PUTPUT"));
	// printf("len: %d\n", ft_printf("%u4444u%ctll%%__%s\n", 429496, 'O', "PUTPUT"));
	// printf("len orig: %d\n", printf("%u4444d%ctll%%__%s\n", 429496, 'O', "PUTPUT"));
	// printf("len: %d\n", ft_printf("f %%x = [%x];[%x]\n", 429, 0xABCDEF));
	// printf("len: %d\n", ft_printf("f %%X = [%X]\n", 4294967295u));
	// printf("len orig: %d\n", printf("f %%x = [%x];[%x]\n", 429, 0xABCDEF));
	// printf("len orig: %d\n", printf("f %%X = [%X]\n", 4294967295u));
	// printf("%p\n", NULL);
	// printf("%% test");
	// printf("f %%%%, [%%]\n");
	// printf("f %%5%%, [%5%]\n");
	// printf("f %%-5%%, [%-5%]\n");
	// printf("f %%05%%, [%05%]\n");
	// printf("f %%-05%%, [%-05%]\n");
	// ft_printf("%% test");
	// ft_printf("f %%%%, [%%]\n");
	// ft_printf("f %%5%%, [%5%]\n");
	// ft_printf("f %%-5%%, [%-5%]\n");
	// ft_printf("f %%05%%, [%05%]\n");
	// ft_printf("f %%-05%%, [%-05%]\n");
	// printf("u - unsigned int test \n");
	// ft_printf("f %u\n", 4294967295u);
	// ft_printf("%u\n", 42);
	// ft_printf("Kashim a %u histoires à raconter\n", 1001);
	// ft_printf("Il fait au moins %u\n", -8000);
	// ft_printf("%u\n", -0);
	// ft_printf("%u\n", 0);
	// ft_printf("%u\n", INT_MAX);
	// ft_printf("%u\n", INT_MIN);
	// ft_printf("%%u 0000042 == |%u|\n", 0000042);
	// ft_printf("%%u \t == |%u|\n", '\t');
	// ft_printf("%%u Lydie == |%u|\n\n", 'L'+'y'+'d'+'i'+'e');
	// printf("len ft_printf: %i\n", ft_printf("%u\n", 0));
	// printf("len printf: %i\n", printf("%u\n", 0));
	// ft_printf("s - string test \n");
	// ft_printf("hello, %8s.\n", "gavin");
	// ft_printf("%-8s\n", "testing testing");
	// ft_printf("this %s is empty\n", "");
	// ft_printf("%s !", "Ceci n'est pas un \0 exercice !\n\n");
	char *null_str = NULL;
	printf("ft_printf len: %d\n", ft_printf("%s everywhere\n", null_str));
	printf("printf len: %d\n", printf("%s everywhere\n", null_str));
}
