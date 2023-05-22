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

char	**pathfinder_first(char **envp)
{
	int		p;

	p = 0;
	while (!(ft_strnstr(envp[p], "PATH", 4)))
		p++;
	return (envp + 5);
}

/* funcao que encontra o PATH do comando*/
char	*pathfinder_second(char *command, char **envp)
{
	char	**paths;
	char	**without;
	char	*path;
	int		p;

	p = 0;
	while (!(ft_strnstr(envp[p], "PATH", 4)))
		p++;
	paths = ft_split(envp[p], ':');
	without = ft_split(command, 32);
	p = 0;
	while (paths[p])
	{
		path = triple(paths[p], "/", without[0]);
		if (access(path, 0) == 0)
			return (path);
		free(path);
		p++;
	}
	free_2(without, paths);
	return (0);
}

void	command_executer(char *argv, char **envp)
{
	char	*path;
	char	**flag;

	flag = ft_split(argv, 32);
	if (!flag)
	{
		perros();
	}
	path = pathfinder_second(flag[0], envp);
	if (!path)
	{
		free_1(flag, path);
		perros();
	}
	if (execve(path, flag, envp) == -1)
	{
		free_1(flag, path);
		perros();
	}
}
