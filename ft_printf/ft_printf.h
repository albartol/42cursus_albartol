/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:27 by albartol          #+#    #+#             */
/*   Updated: 2023/11/16 16:38:33 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);

int	ft_strlen(const char *str);

int	ft_putstr_n(const char *s);
int	ft_putchar_n(char c);
int	ft_putnbr_n(long nbr);
int	ft_putnbr_base_n(unsigned long nbr, char *base);
int	ft_putptr_n(unsigned long ptr);

#endif