/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:25:21 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/28 12:08:35 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

void	ft_send_bit(char *str, gid_t pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((1 << bit) & *str)
		{
			kill(pid, SIGUSR1);
			usleep(500);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(500);
		}
		bit--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("\033[31m" "Error, correct usage: <pid> <message>\n");
		exit(1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][++i])
			ft_send_bit(&argv[2][i], pid);
		ft_printf("\033[32m" "Message received: %s", argv[2]);
	}
}
