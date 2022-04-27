/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:53:41 by abziouzi          #+#    #+#             */
/*   Updated: 2021/12/19 04:25:31 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int				ft_putchar(char c);
int				ft_putstr(char *s);
unsigned int	ft_put_ptr(unsigned long long p);
void			ft_put_hexa_ptr(unsigned long long i);

int				ft_nbr_len(int i);
int				ft_putnbr(int n);
unsigned int	ft_put_uns_nbr(unsigned int i);

int				ft_hexa_len(unsigned long long i);
unsigned int	ft_put_hexa_l(unsigned int i);
unsigned int	ft_put_hexa_u(unsigned int i);

int				ft_printf(const char *format, ...);

#endif
