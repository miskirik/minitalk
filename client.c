/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:36:59 by miskirik          #+#    #+#             */
/*   Updated: 2022/06/29 01:41:21 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
# include "ft_printf.h"
#include <unistd.h>

int main(int argc,char **argv)
{
	if(argc != 3)
	{
		ft_printf("You failed.");
		return(0);
	}
	ft_printf("%d",getpid());
}
