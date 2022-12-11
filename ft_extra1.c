/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoptas <ctoptas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:47:44 by ctoptas           #+#    #+#             */
/*   Updated: 2022/12/10 15:47:46 by ctoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb >= 0 && nb <= 9)
		i += ft_putchar(nb + '0');
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(nb * (-1));
	}
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}
