/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:45:27 by imendonc          #+#    #+#             */
/*   Updated: 2022/11/15 14:44:29 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//bibliotecas necessárias
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>

size_t		ft_strlen(const char *string);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		**ft_split(char const *s, char c);

#endif
