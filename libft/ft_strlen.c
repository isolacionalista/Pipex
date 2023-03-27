/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:03:04 by imendonc          #+#    #+#             */
/*   Updated: 2023/01/18 18:37:30 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	size_t	a;

	a = 0;
	while (string[a] != '\0')
		a++;
	return (a);
}

//int main()
//{
//    char *string;
//    int size;
//    int test_size;
//
//    //test 1
//    string = "ola";
//    size = strlen(string);
//    test_size = ft_strlen(string);
//    printf("First test:\n");
//    printf("Original function: %d\nMy function: %d\n\n", size, test_size);
//
//    //test 2
//    string = "";
//    size = strlen(string);
//    test_size = ft_strlen(string);
//    printf("Second test:\n");
//    printf("Original function: %d\nMy function: %d\n\n", size, test_size);
//
//    //test 3
//    string = "01234";
//    size = strlen(string);
//    test_size = ft_strlen(string);
//    printf("Third test:\n");
//    printf("Original function: %d\nMy function: %d\n", size, test_size);
//}
