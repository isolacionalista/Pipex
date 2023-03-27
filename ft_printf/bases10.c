/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bases10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:05:52 by imendonc          #+#    #+#             */
/*   Updated: 2022/12/05 13:35:16 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
para funcoes de base 10
     -------- PUTNBR --------
%d - printa um numero decimal de base 10 
    --------- PUTUN ---------
%u - print um numero unsigned decimal se base 10
*/

/*
em todas as funcoes auxiliar para o printf,
e preciso ter um pointer len (indica para o tamanho)
para ser possivel a funcao dar a contagem correcta de
caracteres no output
*/

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648", len);
	else if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr *= -1;
		ft_putnbr(nbr, len);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	else
		ft_putchar(nbr + 48, len);
}

/*
-----
putun - putnbr mas em unsigned
-----
*/
void	ft_putun(unsigned int nbr, int *len)
{
	if (nbr > 9)
	{
		ft_putun(nbr / 10, len);
		ft_putun(nbr % 10, len);
	}
	else
		ft_putchar(nbr + 48, len);
}
