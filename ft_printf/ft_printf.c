/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:33 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 15:58:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_put_bonus(const char *str, va_list argc, int *i)
// {
// 	int	n=0;
// 	int	j=0;
// 	int nb=0;

// 	if (str[*i] ==   && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
// 	{
// 		nb = va_arg(argc, int);
// 		if (nb > 0)
// 		{
// 			n = write(1, "+", 1);
// 			++(*i);	
// 		}
// 		j = ft_putnbr_n(nb);
// 	}
// 	else if (str[*i] == ' ' && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
// 	{
// 		nb = va_arg(argc, int);
// 		if (nb > 0)
// 		{
// 			n = write(1, " ", 1);
// 			++(*i);	
// 		}
// 		j = ft_putnbr_n(nb);
// 	}
// 	// else if (str[*i] == '#')
// 	// 	n = ft_putptr_n(va_arg(argc, unsigned long));
// 	else
// 		return (0);
// 	if (n == -1 || j == -1)
// 		return (-1);
// 	return (n + j);
// }

static int	ft_put_all(const char *str, va_list argc, int i)
{
	int	n;

	if (str[i] == 'c')
		n = ft_putchar_n(va_arg(argc, int));
	else if (str[i] == 's')
		n = ft_putstr_n(va_arg(argc, char *));
	else if (str[i] == 'p')
		n = ft_putptr_n(va_arg(argc, unsigned long));
	else if (str[i] == 'd' || str[i] == 'i')
		n = ft_putnbr_n(va_arg(argc, int));
	else if (str[i] == 'u')
		n = ft_putnbr_n(va_arg(argc, unsigned int));
	else if (str[i] == 'x')
		n = ft_putnbr_base_n(va_arg(argc, unsigned int), "0123456789abcdef");
	else if (str[i] == 'X')
		n = ft_putnbr_base_n(va_arg(argc, unsigned int), "0123456789ABCDEF");
	else if (str[i] == '%')
		n = ft_putchar_n(str[i]);
	// else if (str[i] == '#' || str[i] == ' ' || str[i] == '+')
	// 	n = ft_put_bonus(str, argc, &i);
	else
		return (0);
	return (n);
}

static int	ft_print(const char *str, va_list argc)
{
	int	i;
	int	res;
	int	n;

	res = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			n = ft_putchar_n(str[i++]);
			if (n == -1)
				return (-1);
			res += n;
		}
		if (str[i])
			i++;
		n = ft_put_all(str, argc, i);
		if (n == -1)
			return (-1);
		res += n;
		if (str[i])
			i++;
	}
	return (res);
}

int	ft_printf(char const *str, ...)
{
	va_list	argc;
	int		res;

	if (!str)
		return (0);
	va_start(argc, str);
	res = ft_print(str, argc);
	va_end(argc);
	return (res);
}
