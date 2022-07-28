/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:36:56 by miskirik          #+#    #+#             */
/*   Updated: 2022/07/28 05:26:50 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
# include "./ft_printf/ft_printf.h"
#include <unistd.h>

void	ft_server(int signal, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void)context;
	if(signal == SIGUSR1)
		c = c | 1;
	if (++i == 8)
	{
		i=0;
		if (!c)
		{
			kill(info->si_pid,SIGUSR1);
			ft_printf("\n");
		}
		ft_printf("%c",c);
		c=0;
	}
	else
		c <<=1;
}

int main(void)
{
	struct sigaction	server;
	int pid;

	pid=getpid();
	ft_printf("Server pid=%d\n",pid);
	server.sa_flags= SA_SIGINFO;
	server.sa_sigaction= ft_server;
	if (sigaction(SIGUSR1,&server,0)== -1)
		ft_printf("Signal Error\n");
	if (sigaction(SIGUSR2,&server,0)== -1)
		ft_printf("Signal Error\n");
	while (1)
		pause();
	return(0);

}
