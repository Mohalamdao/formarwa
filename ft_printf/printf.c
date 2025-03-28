/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:39:52 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 15:44:17 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base2(unsigned long long nbr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (nbr < 16)
		count += ft_putchar(base[nbr]);
	else
	{
		count += ft_putnbr_base2((nbr / 16));
		count += ft_putchar((base[nbr % 16]));
	}
	return (count);
}

int	ft_putnbr_base(unsigned int nbr, char type)
{
	char	*base;
	int		count;

	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (nbr < 16)
		count += ft_putchar(base[nbr]);
	else
	{
		count += ft_putnbr_base((nbr / 16), type);
		count += ft_putchar((base[nbr % 16]));
	}
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_fonction(va_list list, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (type == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (type == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base2(va_arg(list, unsigned long long));
	}
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (type == 'u')
		count += ft_putnbr2(va_arg(list, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_putnbr_base(va_arg(list, unsigned int), type);
	else if (type == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_fonction(list, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}

// int main()
// {
// 	ft_ft_printf("%p","");
// }