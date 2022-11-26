/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:23:03 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/26 19:57:38 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
// # include "libft.h"

int		ft_printf(const char *msg, ...);

//from utilis
int		ft_printf_str(char *str);
int		ft_printf_num(int num);
int		ft_putchar(int c);
int		ft_printf_u(unsigned int u_num);
char	*ft_itoa_u(unsigned int u);
int		ft_printf_hex(unsigned int dec);
char	*ft_itoa_hex(unsigned int dec);

//using from libft
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif