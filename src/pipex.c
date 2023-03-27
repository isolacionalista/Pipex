/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:16:42 by imendonc          #+#    #+#             */
/*   Updated: 2023/01/18 21:16:42 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

/*
protecoes: tem de receber 4 argumentos (5 portanto), 
tem de ter um ficheiro para output, um fichero para input e 
tem de receber o pipe
o main e obtido por causa da funcao execve
*/

/*
se o programa receber os 5 argumentos, nao necessita ~
de protecoes para output wtc...
*/

/*
        if (pid == -1)
            perros();
            se o fork for mal sucedido ( fork return -1) ele  vai buscar o erro 
        id (pid == 0)
            se o fork for bem sucedido (fork return 0) avança para o processo de 
            calling entre child e parent
*/

/*
fd vao ser os file descriptors. ./pipex -> 0, 
infile -> 1, cmd 1 -> 2, cmd2 -> 3, outfile -> 4.
fd[2] significa cmd1
*/

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		return (erros());
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			perros();
		pid = fork();
		if (pid < 0)
			perros();
		if (pid == 0)
			embriao(fd, argv, envp);
		waitpid(pid, NULL, 0);
		progenitor(fd, argv, envp);
	}
	return (EXIT_SUCCESS);
}
