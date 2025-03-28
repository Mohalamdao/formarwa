/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:39:59 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 15:44:06 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_count(int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		count += 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		count += 1;
		nb /= 10;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = ft_count(nb);
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		count += 10;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (count);
}

int	ft_putnbr2(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr2(nb / 10);
		count += ft_putnbr2(nb % 10);
	}
	else
		count += ft_putchar(nb + 48);
	return (count);
}
