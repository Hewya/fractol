/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaelle <gaelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:52:34 by gaelle            #+#    #+#             */
/*   Updated: 2023/11/06 10:57:26 by gaelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

size_t	ft_putadress(void *adress);
size_t	ft_putchar(const char c);
size_t	ft_puthexa_lower(const unsigned int n);
size_t	ft_puthexa_upper(const unsigned int n);
size_t	ft_putnbr(const int n);
size_t	ft_putstr(const char *str);
size_t	ft_putunbr(const unsigned int n);
size_t	ft_strlen(const char *s);

#endif