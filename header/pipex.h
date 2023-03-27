/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:09:56 by imendonc          #+#    #+#             */
/*   Updated: 2023/01/18 20:09:56 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

//malloc, free, exit
# include <stdlib.h>

//open, unlink
# include <stdio.h>

//strerror
# include <string.h>
# include <errno.h>

//waitpid, wait
# include <sys/wait.h>

//write, read, close, access, pipe, dup, dup2, execve, fork
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

//open, unlink
# include <fcntl.h>

int		main(int argc, char *argv[], char *envp[]);
int		erros(void);
void	perros(void);
char	*pathfinder_second(char *command, char **envp);
char	*triple(char *s1, char *s2, char *s3);
void	command_executer(char *argv, char **envp);
void	progenitor(int *fd, char **argv, char **envp);
void	embriao(int *fd, char **argv, char **envp);
char	**withoutflag(char *command);
char	**pathfinder_first(char **envp);

#endif