/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:19:30 by imendonc          #+#    #+#             */
/*   Updated: 2023/01/24 13:19:30 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

/*
return 1 e o  valor do EXIT_FAILURE segundo a stdlib. ~
quando e bem sucedido, o return seria 0
sendo que e para tratar de erros, sera sempre 1 nestes casos
*/

/*
a diferenca do strerror para o perror e que o str tem de receber 
como argumento o numero pre definido
de um erro especifico enquanto o perror vai busca-lo automaticamente
*/

int	erros(void)
{
	ft_printf("\033[1;31mFailed: \033[0;97m");
	ft_printf("Number of arguments invalid.\n");
	ft_printf("      ----   Needed 4   ----\n");
	return (1);
}

/*
na funcao perror, printa o "Error" e em seguida dispoe o erro 
sucedido automaticamente
*/

void	perros(void)
{
	perror("\033[1;31mError\033[0;97m");
	exit(EXIT_FAILURE);
}
