/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:26:41 by imendonc          #+#    #+#             */
/*   Updated: 2023/01/26 12:26:41 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*triple(char *s1, char *s2, char *s3)
{
	char	*str;
	size_t	a;
	size_t	b;

	str = malloc(sizeof(*s1) * ft_strlen(s1) + ft_strlen(s2)
			+ ft_strlen(s3) + 1);
	a = 0;
	b = 0;
	if (!s1 || !s2 || !s3 || !str)
		return (NULL);
	while (s1[a])
		str[b++] = s1[a++];
	a = 0;
	while (s2[a])
		str[b++] = s2[a++];
	a = 0;
	while (s3[a])
		str[b++] = s3[a++];
	str[b] = '\0';
	return (str);
}

char	**withoutflag(char *command)
{
	char	**without;

	without = ft_split(command, 32);
	if (!without)
	{
		free (without);
		perros();
	}
	return (without);
}

char	**pathfinder_first(char **envp)
{
	char	**path_search;
	int		p;

	p = 0;
	while (!(ft_strnstr(envp[p], "PATH", 4)))
		p++;
	path_search = ft_split(envp[p] + 5, ':');
	if (!path_search)
	{
		free (path_search);
		perros();
	}
	while (path_search)
		return (path_search);
	free (path_search);
	return (0);
}

/* funcao que encontra o PATH do comando*/
char	*pathfinder_second(char *command, char **envp)
{
	char	*path;
	int		p;

	p = 0;
	while (pathfinder_first(envp)[p])
	{
		path = triple(pathfinder_first(envp)[p], "/", withoutflag(command)[0]);
		if (access(path, 0) == 0)
			return (path);
		if (!access(path, 0))
		{
			free (path);
			perros();
		}
		free(path);
		p++;
	}
	return (0);
}

void	command_executer(char *argv, char **envp)
{
	char	*path;
	char	**way;

	way = ft_split(argv, 32);
	if (!way)
	{
		perros();
	}
	path = pathfinder_second(way[0], envp);
	if (!path)
	{
		free(way);
		perros();
	}
	if (execve(path, way, envp) == -1)
	{
		free(way);
		free(path);
		perros();
	}
	free (way);
	free (path);
}
