/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:36:56 by miskirik          #+#    #+#             */
/*   Updated: 2022/06/29 03:16:03 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf.h"

void ft_server()
{

}

int main(void)
{
	struct sigaction	server;
	int pid;

	server.sa_flags= SA_SIGINFO;
	server.sa_sigaction= ft_server;
	if (sigaction(SIGUSR1,&server,0)== -1)
		ft_printf("Signal Error\n");
	if (sigaction(SIGUSR2,&server,0)== -1)
		ft_printf("Signal Error\n");
	pid=getpid();
	ft_printf("Server pid=%d\n",pid);

	while (1)
		pause();
	return(0);

}
