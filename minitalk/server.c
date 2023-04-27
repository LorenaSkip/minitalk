/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:46:32 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/27 10:56:53 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

void	bit_handler(int bit)
{
	static int	x;
	static int	y;

	if (bit == SIGUSR1)
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

int		main(void)
{
	ft_printf("This is just a Lorena's server... enjoy!\n");
	ft_printf("Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, bit_handler);
		signal(SIGUSR2, bit_handler);
		pause();
	}
	return (0);
}
