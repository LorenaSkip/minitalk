/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:46:32 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/28 12:01:56 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

void	bit_handler(int sign)
{
	static unsigned int	x;
	static unsigned int	y;

	if (sign == SIGUSR1)
	{
		y *= 2;
		y += 1;
		x++;
	}
	else
	{
		x++;
		y *= 2;
	}
	if (x == 8)
	{
		ft_printf("%c", y);
		x = 0;
		y = 0;
	}
}

int	main(void)
{
	ft_printf("\033[0;31m" "This is just a Lorena's server... enjoy!\n" "\033[1m");
	ft_printf("\033[0;36m" "	Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, bit_handler);
		signal(SIGUSR2, bit_handler);
		pause();
	}
	return (0);
}
