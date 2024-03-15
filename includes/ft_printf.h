/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:27:09 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/15 01:43:13 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_putaddress(void *n);
int	ft_putstr(const char *str);
int	ft_putexa(unsigned long long n);
int	ft_putexa_upper(unsigned long long n);
int	ft_putunbr(unsigned int n);
int	ft_strcmp(const char *s1, const char *s2);

#endif