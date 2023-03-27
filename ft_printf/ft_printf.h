/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:53:29 by imendonc          #+#    #+#             */
/*   Updated: 2023/03/22 15:36:54 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*   O QUE E VA_LIST
as va_list's sao tipos de objectos completos que conseguem
conter toda a informacao necessaria dos macros va_start, va_copy
va_arg e va_end. se uma lista e criada, passada para outra funcao
e usada com o va_arg, qualquer subsequente da funcao tem de ser 
terminada com o va_end. e possivel passar um pointer para o objecto 
va_list e usar o objecto depois de a funcao retornar
------ap - uma instancia do va_list type
------tipo T - o tipo do proximo parametro na ap
*/

/* BIBLIOTECAS A INCLUIR
funcoes permitidas malloc, free, write e macros da va_list
para se conseguir usar os macros de va_list e preciso stdarg.c
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

//prototipos de funcoes

int			ft_printf(const char *str, ...);
void		check_conversion(va_list arg, const char str, int *len);
void		ft_putchar(char c, int *len);
void		ft_putstr(char *str, int *len);
void		ft_putnbr(int nbr, int *len);
void		ft_putun(unsigned int nbr, int *len);
void		hexa_check(unsigned int nbr, char hex, int *len);
void		ft_putp(const void *p, int *len);

/*   O QUE E VA_ARG
este macro expande para uma expressao tipo T. Para poder usar
va_arg, o ap tem de ser inicializado com start ou copy, sem ser interrompido
por end. cada evocacao do macro arg modifica o ap para apontar 
para a proxima variavel do argumento
se o proximo argumento do ap nao for cmpativel com T, vai ter um
comportamento indefinido a nao ser que:
-------- um tipo seja int e o outro unsigned int
-------- ou um tipo e um void pointer e o outro pointer e um caracter
*/

/*   O QUE E VA_START
este macro e usado para iniciar o ap de uma va_list.
apenas o primeiro argumento passado para start e avaliado,
qualquer argumento subsequente nao e expandido ou usado 
*/

/*   O QUE E VA_COPY
este macro copia o valor de source(origem) para o dest(destino)
o macro end deve ser usado em dest antes da funcao retornar
ou re-inicializacao do dest 
----------dest - uma instancia do va_list para inicializar
----------src - a origem para poder inicializar dest
*/

/*   O QUE E VA_END
este macro e usado para finalizar e modificar um objecto ap para nao ser mais
possivel de o usar ou alterar
tem de ser usado no final de uma inicializacao de um ap para ter um 
comportamento certo 
*/

#endif
