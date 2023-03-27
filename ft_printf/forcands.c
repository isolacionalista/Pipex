/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forcands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:11:32 by imendonc          #+#    #+#             */
/*   Updated: 2022/12/05 13:27:17 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*  FUNCOES PARA %C E %S
putchar para %c e putstr para %s
  ------- PUTCHAR -------
%c - printa um unico caracter
  -------- PUTSTR -------
%s - printa uma string (conjunto de caracteres)
*/

/*
em todas as funcoes auxiliar para o printf,
e preciso ter um pointer len (indica para o tamanho)
para ser possivel a funcao dar a contagem correcta de
caracteres no output
*/

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

/*
------
ascii 6 =  ACK - acknowledge
------
*/

void	ft_putstr(char *str, int *len)
{
	size_t	i;

	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		i = 0;
		while (str[i])
			ft_putchar(str[i++], len);
	}
}
