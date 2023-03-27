/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:31:15 by imendonc          #+#    #+#             */
/*   Updated: 2023/03/27 13:40:23 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char sep)
{
	size_t	word_nr;
	size_t	is_word;

	word_nr = 0;
	is_word = 0;
	while (*str)
	{
		if (*str != sep && is_word == 0)
		{
			is_word = 1;
			word_nr++;
		}
		else if (*str == sep)
			is_word = 0;
		str++;
	}
	return (word_nr);
}

static char	*n_substr(const char *str, unsigned int start, size_t lenght)
{
	size_t	index;
	char	*new_str;

	new_str = (char *)malloc(sizeof(*str) * (lenght - start + 1));
	if (new_str == 0 || !str)
		return (NULL);
	index = 0;
	while (start < lenght)
	{
		new_str[index] = str[start];
		index++;
		start++;
	}
	new_str[index] = '\0';
	return (new_str);
}

char	**ft_split(const char *str, char sep)
{
	int		start;
	size_t	new_str_i;
	size_t	str_i;
	char	**new_str;

	new_str = malloc(sizeof(char *) * (word_count(str, sep) + 1));
	if (new_str == NULL)
		return (NULL);
	str_i = 0;
	new_str_i = 0;
	start = -1;
	while (str_i <= ft_strlen(str))
	{
		if (str[str_i] != sep && start < 0)
			start = str_i;
		else if ((str[str_i] == sep || str_i == ft_strlen(str)) && start >= 0)
		{
			new_str[new_str_i++] = n_substr(str, start, str_i);
			start = -1;
		}
		str_i++;
	}
	new_str[new_str_i] = 0;
	return (new_str);
}
