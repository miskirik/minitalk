/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:36:59 by miskirik          #+#    #+#             */
/*   Updated: 2022/07/01 04:49:21 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
# include "ft_printf.h"
#include <unistd.h>

void ft_ok(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Process Successful");
}
int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
		i = (i * 10) + (*str++ - '0');
	return (i);
}

void ft_procces(int pid,char *str)
{
	int i;
	char c;

	i=0;
	c=0;
	while (str[c])
	{
		i=7;
		while (i>=0)
		{
			if(str[c] >> i & 1)
				kill(pid,SIGUSR1);
			else
				kill(pid,SIGUSR2);
			i--;
			usleep(50);
		}
		c++;
	}
}
int main(int argc,char **argv)
{
	int pid;

	pid=ft_atoi(argv[1]);
	//ft_printf("%d",pid);
	if(argc != 3)
	{
		ft_printf("You failed.\n");
		return(0);
	}
	signal (SIGUSR1, ft_ok);
	ft_procces(pid, argv[2]);
}
