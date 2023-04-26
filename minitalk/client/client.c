/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:25:21 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/26 14:46:25 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

void	send_bit(char *str, gid_t pid)
{
	int	pid;
	
	bit = 7;
	while (bit >= 0)
	{
		if ((1 << bit) & *str)
		{
			kill(pid, SIGUSR1);
			usleep(300);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(300);
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
		ft_printf("error");
		return (0);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][++i])
			send_bit(argv[2][i], pid);
		ft_printf("Message received: %s", argv[2]);
	}
}
