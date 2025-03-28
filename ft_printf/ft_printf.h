/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:39:45 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 15:44:22 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putnbr2(unsigned int nb);
int	ft_putnbr_base2(unsigned long long nbr);
int	ft_putnbr_base(unsigned int nbr, char type);
int	ft_putstr(char *str);
int	ft_fonction(va_list list, char type);
int	ft_printf(const char *str, ...);

#endif