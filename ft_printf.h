/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:23:03 by tmarts            #+#    #+#             */
/*   Updated: 2022/11/29 16:09:47 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *msg, ...);
int		ft_conversions(const char *f_spec, va_list args);

//from utilis_1
int		ft_putchar(int c);
int		ft_u_intlen(unsigned int u);
int		ft_hex_len(size_t dec);

char	*ft_itoa_u(unsigned int u);
char	*ft_itoa_hex(size_t dec, char x_case);

//from utilis_2
int		ft_printf_str(char *str);
int		ft_printf_num(int num);
int		ft_printf_u(unsigned int u_num);
int		ft_printf_hex(unsigned int dec, char x_case);
int		ft_printf_p(size_t p_dec);

#endif