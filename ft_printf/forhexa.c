/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forhexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:27:31 by imendonc          #+#    #+#             */
/*   Updated: 2023/03/22 15:34:30 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
para todas as funcoes que imprimem numeros
hexadecimais em base 16 %x e %X
%x - printa um numero hex de base 16 em minusculas
%X - printa um numero hex de base 16 em maiuscula
*/

/*
base 10 -- decimal
base 16 -- hexadecimal
base 2  -- binario
base 10 -- octal
*/

/*
dizer base 16 ou hexadecimal e a mesma coisa
este e um dos 4 sistemas de numeracao ascii
os valores para representarem caracteres numa base hexa
variam entre o 0-9 e de a-f
*/

void	hexa_check(unsigned int nbr, char hex, int *len)
{
	char	*base;

	if (hex == 'x')
		base = "0123456789abcdef";
	else
	base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar((base[nbr % 16]), len);
	else
	{
		hexa_check((nbr / 16), hex, len);
		hexa_check((nbr % 16), hex, len);
	}
}

/*
exemplo de conversao hexadecimal para ascii
50(16) = 5*16+0*16(0) = 80+0 = 80 => P
6C(16) = 6*16+12*16(0) = 96+12 = 108 => l
61(16) = 6*16+1*16(0) = 96+1 = 97 => a
*/