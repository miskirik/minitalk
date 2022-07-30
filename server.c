/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:36:56 by miskirik          #+#    #+#             */
/*   Updated: 2022/07/30 18:46:26 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
# include "./ft_printf/ft_printf.h"
#include <unistd.h>

void	ft_catch(int x,siginfo_t *info,void *unused)
{
	int sig;
	static int	bit=7;
	static int	set=0;

	(void)unused;
	sig=0;
	if (x == SIGUSR1)
		sig=1;
	else if (x == SIGUSR2)
		sig=0;
	set += sig << bit;
	if (bit == 0)
	{
		if(set==0)
			kill(info->si_pid,SIGUSR1);
		ft_printf("%c",set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

int main(void)
{
	struct sigaction client;

	client.sa_flags=SA_SIGINFO;
	client.sa_sigaction=ft_catch;

	ft_printf("Server pid=%d\n",getpid());
	sigaction(SIGUSR1,&client,0);
	sigaction(SIGUSR2,&client,0);
	while (1)
		pause();
	return(0);

}
