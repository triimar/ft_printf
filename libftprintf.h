/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:23:03 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/27 20:45:38 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//# include "libft.h"
# include <stdio.h> // REMOVE!!

int		ft_printf(const char *msg, ...);
int		ft_conversions(const char *f_spec, va_list args);

//from utilis
int		ft_printf_str(char *str);
int		ft_printf_num(int num);
int		ft_putchar(int c);
int		ft_printf_u(unsigned int u_num);
char	*ft_itoa_u(unsigned int u);
int		ft_printf_hex(unsigned int dec, char x_case);
char	*ft_itoa_hex(size_t dec, char x_case);
int		ft_printf_p(size_t p_dec);

//using from libft
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif